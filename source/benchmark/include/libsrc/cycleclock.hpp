// ----------------------------------------------------------------------
// CycleClock
//    A CycleClock tells you the current time in Cycles.  The "time"
//    is actually time since power-on.  This is like time() but doesn't
//    involve a system call and is much more precise.
//
// NOTE: Not all cpu/platform/kernel combinations guarantee that this
// clock increments at a constant rate or is synchronized across all logical
// cpus in a system.
//
// If you need the above guarantees, please consider using a different
// API. There are efforts to provide an interface which provides a millisecond
// granularity and implemented as a memory read. A memory read is generally
// cheaper than the CycleClock for many architectures.
//
// Also, in some out of order CPU implementations, the CycleClock is not
// serializing. So if you're trying to count at cycles granularity, your
// data might be inaccurate due to out of order instruction execution.
// ----------------------------------------------------------------------

#ifndef BENCHMARK_CYCLECLOCK_H_
#define BENCHMARK_CYCLECLOCK_H_

#include <cstdint>

#include "../benchmark/macros.h"
#include "internal_macros.h"

#if defined(BENCHMARK_OS_MACOSX)
#include <mach/mach_time.h>
#endif
// For MSVC, we want to use '_asm rdtsc' when possible (since it works
// with even ancient MSVC compilers), and when not possible the
// __rdtsc intrinsic, declared in <intrin.h>.  Unfortunately, in some
// environments, <windows.h> and <intrin.h> have conflicting
// declarations of some other intrinsics, breaking compilation.
// Therefore, we simply declare __rdtsc ourselves. See also
// http://connect.microsoft.com/VisualStudio/feedback/details/262047
#if defined(COMPILER_MSVC) && !defined(_M_IX86)
extern "C" uint64_t __rdtsc();
#pragma intrinsic(__rdtsc)
#endif

#ifndef BENCHMARK_OS_WINDOWS
#include <sys/time.h>
#endif

namespace benchmark
{
    // NOTE: only i386 and x86_64 have been well tested.
    // PPC, sparc, alpha, and ia64 are based on
    //    http://peter.kuscsik.com/wordpress/?p=14
    // with modifications by m3b.  See also
    //    https://setisvn.ssl.berkeley.edu/svn/lib/fftw-3.0.1/kernel/cycle.h
    namespace cycleclock
    {
        // This should return the number of cycles since power-on.  Thread-safe.
        inline BENCHMARK_ALWAYS_INLINE int64_t Now()
        {
            uint32_t pmccntr;
            uint32_t pmuseren;
            uint32_t pmcntenset;
            // Read the user mode perf monitor counter access permissions.
            asm("mrc p15, 0, %0, c9, c14, 0" : "=r"(pmuseren));
            if (pmuseren & 1)
            { // Allows reading perfmon counters for user mode code.
                asm("mrc p15, 0, %0, c9, c12, 1" : "=r"(pmcntenset));
                if (pmcntenset & 0x80000000ul)
                { // Is it counting?
                    asm("mrc p15, 0, %0, c9, c13, 0" : "=r"(pmccntr));
                    // The counter is set up to count every 64th cycle
                    return static_cast<int64_t>(pmccntr) * 64; // Should optimize to << 6
                }
            }
            struct timeval tv;
            gettimeofday(&tv, nullptr);
            return static_cast<int64_t>(tv.tv_sec) * 1000000 + tv.tv_usec;
        }
    } // end namespace cycleclock
} // end namespace benchmark

#endif // BENCHMARK_CYCLECLOCK_H_
