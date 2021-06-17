#include <bitset>
#include "./globals.hpp"

namespace font {
    Vector2 bitmapDimensions = {112, 160};
    std::bitset<17920> fontBitmap;

    void initFont(){
        unsigned long data[560] = {
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x60e0000,
            (unsigned long)0x1070e1c3,
            (unsigned long)0x4087060c,
            (unsigned long)0x183070e1,
            (unsigned long)0x60c1830a,
            (unsigned long)0xe1c3830,
            (unsigned long)0x10614082,
            (unsigned long)0x8000810,
            (unsigned long)0x2870e1ce,
            (unsigned long)0x81880e1c,
            (unsigned long)0xc187020,
            (unsigned long)0x7041428,
            (unsigned long)0x3070c1c1,
            (unsigned long)0xc387001c,
            (unsigned long)0x8287041,
            (unsigned long)0x41428204,
            (unsigned long)0x3941030,
            (unsigned long)0x20a04182,
            (unsigned long)0x142813a,
            (unsigned long)0x1874e871,
            (unsigned long)0x40820183,
            (unsigned long)0x7027040,
            (unsigned long)0x1870e081,
            (unsigned long)0x870004,
            (unsigned long)0x0,
            (unsigned long)0x41428506,
            (unsigned long)0xc2840,
            (unsigned long)0x7,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x83060000,
            (unsigned long)0x307060c1,
            (unsigned long)0xc307061c,
            (unsigned long)0x143870e1,
            (unsigned long)0xa142850a,
            (unsigned long)0x20c1850,
            (unsigned long)0x7060c183,
            (unsigned long)0x9b161408,
            (unsigned long)0xa08366cd,
            (unsigned long)0xca07161c,
            (unsigned long)0x1c086021,
            (unsigned long)0x2040810,
            (unsigned long)0x387041c1,
            (unsigned long)0x83060a1c,
            (unsigned long)0x183060c1,
            (unsigned long)0x4143060c,
            (unsigned long)0xe1c2820,
            (unsigned long)0x20408103,
            (unsigned long)0xa1c1830e,
            (unsigned long)0xe2c3850,
            (unsigned long)0xc181c194,
            (unsigned long)0x2063060,
            (unsigned long)0x2830e181,
            (unsigned long)0x43800a1c,
            (unsigned long)0x0,
            (unsigned long)0x81c3070e,
            (unsigned long)0xa1c2850,
            (unsigned long)0x1c380,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x6000000,
            (unsigned long)0x8005,
            (unsigned long)0x10,
            (unsigned long)0x40000000,
            (unsigned long)0xc0050600,
            (unsigned long)0x8100073,
            (unsigned long)0x504,
            (unsigned long)0x6002000,
            (unsigned long)0x6150a280,
            (unsigned long)0x2080400,
            (unsigned long)0x20000000,
            (unsigned long)0xc7c00600,
            (unsigned long)0x40050b1,
            (unsigned long)0x10508,
            (unsigned long)0x6001000,
            (unsigned long)0x30428280,
            (unsigned long)0x80080400,
            (unsigned long)0x1000e003,
            (unsigned long)0x87c00000,
            (unsigned long)0x40049a2,
            (unsigned long)0x10008,
            (unsigned long)0x6000800,
            (unsigned long)0x4951e280,
            (unsigned long)0x40800,
            (unsigned long)0x8000080,
            (unsigned long)0x80000600,
            (unsigned long)0xb1c0,
            (unsigned long)0x800000,
            (unsigned long)0x420,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x21c3040c,
            (unsigned long)0xc3c30f1,
            (unsigned long)0x6,
            (unsigned long)0x86121800,
            (unsigned long)0x8112204,
            (unsigned long)0x2091220,
            (unsigned long)0x24100101,
            (unsigned long)0x22040412,
            (unsigned long)0x12200811,
            (unsigned long)0xe0800009,
            (unsigned long)0x41a2020,
            (unsigned long)0x3861e182,
            (unsigned long)0xe0c10,
            (unsigned long)0x18400040,
            (unsigned long)0x2010416,
            (unsigned long)0x12104881,
            (unsigned long)0xe0810208,
            (unsigned long)0x84120020,
            (unsigned long)0x48810200,
            (unsigned long)0x81208,
            (unsigned long)0x8100101,
            (unsigned long)0x1c78e0c,
            (unsigned long)0xc083071,
            (unsigned long)0x6,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0xe383861c,
            (unsigned long)0x121878f0,
            (unsigned long)0x5022478e,
            (unsigned long)0x892a1848,
            (unsigned long)0x8112044,
            (unsigned long)0x42041224,
            (unsigned long)0x24587022,
            (unsigned long)0x20448936,
            (unsigned long)0x12040811,
            (unsigned long)0x70214204,
            (unsigned long)0x8f3a2468,
            (unsigned long)0x38712043,
            (unsigned long)0xc2041e04,
            (unsigned long)0x24485020,
            (unsigned long)0x20448902,
            (unsigned long)0x12340811,
            (unsigned long)0x50214204,
            (unsigned long)0x891c2448,
            (unsigned long)0x8112044,
            (unsigned long)0x42841224,
            (unsigned long)0x24485022,
            (unsigned long)0xe3838900,
            (unsigned long)0x121808f0,
            (unsigned long)0x51e2410e,
            (unsigned long)0x1848,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x20,
            (unsigned long)0xe383860e,
            (unsigned long)0x14284893,
            (unsigned long)0x6043078a,
            (unsigned long)0x89120020,
            (unsigned long)0x48908044,
            (unsigned long)0x40a1428,
            (unsigned long)0x504041,
            (unsigned long)0x80448912,
            (unsigned long)0x14284890,
            (unsigned long)0x4081020a,
            (unsigned long)0x890e0000,
            (unsigned long)0x48908183,
            (unsigned long)0x1040828,
            (unsigned long)0x4081,
            (unsigned long)0x82048902,
            (unsigned long)0x14384890,
            (unsigned long)0x41010104,
            (unsigned long)0x85020000,
            (unsigned long)0x28908204,
            (unsigned long)0x841438,
            (unsigned long)0x6103,
            (unsigned long)0x81c48a02,
            (unsigned long)0x14281060,
            (unsigned long)0x2000784,
            (unsigned long)0x7c00,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x40000,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x8008,
            (unsigned long)0x2183001,
            (unsigned long)0x808000,
            (unsigned long)0x86000000,
            (unsigned long)0x48010000,
            (unsigned long)0x84040224,
            (unsigned long)0x80,
            (unsigned long)0x8800,
            (unsigned long)0x2240861,
            (unsigned long)0x808000,
            (unsigned long)0x8e000000,
            (unsigned long)0x3891c303,
            (unsigned long)0x84040e38,
            (unsigned long)0x18301082,
            (unsigned long)0x20848900,
            (unsigned long)0x12200871,
            (unsigned long)0xb0818404,
            (unsigned long)0x89002448,
            (unsigned long)0x8112084,
            (unsigned long)0x85041224,
            (unsigned long)0x24495082,
            (unsigned long)0xc3039600,
            (unsigned long)0x12180861,
            (unsigned long)0x10828204,
            (unsigned long)0x1849,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0xc000000,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x20820000,
            (unsigned long)0x1400,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0xc004081,
            (unsigned long)0x83010c0c,
            (unsigned long)0x0,
            (unsigned long)0xc0818000,
            (unsigned long)0xa147050,
            (unsigned long)0x50a1c083,
            (unsigned long)0x78a1444,
            (unsigned long)0x30284081,
            (unsigned long)0x81050c0c,
            (unsigned long)0x84450a0,
            (unsigned long)0x4081020a,
            (unsigned long)0x8047400,
            (unsigned long)0x50a08201,
            (unsigned long)0x1041454,
            (unsigned long)0x4002082,
            (unsigned long)0x81810804,
            (unsigned long)0x142820e0,
            (unsigned long)0x784,
            (unsigned long)0xc00,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x20004104,
            (unsigned long)0x1000800,
            (unsigned long)0x10000000,
            (unsigned long)0x8282001c,
            (unsigned long)0x140050a0,
            (unsigned long)0x2080020a,
            (unsigned long)0x9022800,
            (unsigned long)0x20000000,
            (unsigned long)0x80000030,
            (unsigned long)0x10504142,
            (unsigned long)0xc1830002,
            (unsigned long)0xc083060,
            (unsigned long)0x306,
            (unsigned long)0x89020000,
            (unsigned long)0x40810204,
            (unsigned long)0x4891208,
            (unsigned long)0x10204081,
            (unsigned long)0xc383891c,
            (unsigned long)0xe3070e1,
            (unsigned long)0x40810387,
            (unsigned long)0x89082850,
            (unsigned long)0x48912240,
            (unsigned long)0x810220,
            (unsigned long)0x38704081,
            (unsigned long)0xc5830604,
            (unsigned long)0xc10b162,
            (unsigned long)0x40810306,
            (unsigned long)0x2850,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x80000,
            (unsigned long)0x0,
            (unsigned long)0x50a1400,
            (unsigned long)0x20200000,
            (unsigned long)0x1000004,
            (unsigned long)0x82020,
            (unsigned long)0x10000000,
            (unsigned long)0x5051,
            (unsigned long)0x50414280,
            (unsigned long)0x4861410,
            (unsigned long)0x10a8a181,
            (unsigned long)0xf0b0e,
            (unsigned long)0x14000000,
            (unsigned long)0x40438489,
            (unsigned long)0x940238b8,
            (unsigned long)0x4860c182,
            (unsigned long)0x84891424,
            (unsigned long)0x10d8e0e0,
            (unsigned long)0x22478e06,
            (unsigned long)0x8244891,
            (unsigned long)0x40408489,
            (unsigned long)0x850210f8,
            (unsigned long)0x48912242,
            (unsigned long)0x84890824,
            (unsigned long)0x1450e1e3,
            (unsigned long)0xc18e9a0e,
            (unsigned long)0x8183060,
            (unsigned long)0x40010306,
            (unsigned long)0x820,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x80000,
            (unsigned long)0x30000000,
            (unsigned long)0xf0f0018,
            (unsigned long)0x4081,
            (unsigned long)0x41020004,
            (unsigned long)0x82440a1,
            (unsigned long)0x1428801,
            (unsigned long)0x8000000,
            (unsigned long)0x7050a081,
            (unsigned long)0x40000024,
            (unsigned long)0x42a5,
            (unsigned long)0x40c,
            (unsigned long)0x18184800,
            (unsigned long)0x42e5c000,
            (unsigned long)0x102490,
            (unsigned long)0xb091e243,
            (unsigned long)0xc0002000,
            (unsigned long)0x48484366,
            (unsigned long)0x2244841c,
            (unsigned long)0x240000b1,
            (unsigned long)0x43e7c000,
            (unsigned long)0x84122490,
            (unsigned long)0xf8d12244,
            (unsigned long)0x80001800,
            (unsigned long)0x4142,
            (unsigned long)0x2183042c,
            (unsigned long)0x91,
            (unsigned long)0x40810000,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x952a0000,
            (unsigned long)0x5040810f,
            (unsigned long)0x50a0000,
            (unsigned long)0x20a140,
            (unsigned long)0x810a8a00,
            (unsigned long)0x5040,
            (unsigned long)0xa140050a,
            (unsigned long)0x95140020,
            (unsigned long)0x5070810f,
            (unsigned long)0xc50b0e00,
            (unsigned long)0x38a163,
            (unsigned long)0xe1050a00,
            (unsigned long)0x83c5840,
            (unsigned long)0xf1020508,
            (unsigned long)0x952a1c20,
            (unsigned long)0x5070810f,
            (unsigned long)0xc50b0e28,
            (unsigned long)0x103801e2,
            (unsigned long)0x810a8a00,
            (unsigned long)0x8285040,
            (unsigned long)0x2850a,
            (unsigned long)0x95141000,
            (unsigned long)0x5040810f,
            (unsigned long)0x850a0828,
            (unsigned long)0x10000002,
            (unsigned long)0x81050a00,
            (unsigned long)0x8285040,
            (unsigned long)0x2850a,
            (unsigned long)0x1000,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x4080000,
            (unsigned long)0x20400100,
            (unsigned long)0x5001428,
            (unsigned long)0x10500140,
            (unsigned long)0x1000408,
            (unsigned long)0x14282040,
            (unsigned long)0x1400500,
            (unsigned long)0x4081050,
            (unsigned long)0xe0400100,
            (unsigned long)0xcd9e3428,
            (unsigned long)0x7cd9f347,
            (unsigned long)0xe70f9f38,
            (unsigned long)0x46821f3,
            (unsigned long)0x400002,
            (unsigned long)0x0,
            (unsigned long)0xe0400102,
            (unsigned long)0xcf9a3c28,
            (unsigned long)0x7cd9f346,
            (unsigned long)0x1020000,
            (unsigned long)0x282040,
            (unsigned long)0x142800a,
            (unsigned long)0x50,
            (unsigned long)0x20400102,
            (unsigned long)0x800a0028,
            (unsigned long)0x500142,
            (unsigned long)0x1020000,
            (unsigned long)0x282040,
            (unsigned long)0x142800a,
            (unsigned long)0x50,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x140000,
            (unsigned long)0x8280,
            (unsigned long)0xc0040828,
            (unsigned long)0x7cc07007,
            (unsigned long)0x82800014,
            (unsigned long)0x8280000,
            (unsigned long)0x7007c004,
            (unsigned long)0x1f147cc0,
            (unsigned long)0x1c38280,
            (unsigned long)0xc0043e28,
            (unsigned long)0x7cc07007,
            (unsigned long)0x878f803e,
            (unsigned long)0x6cf040,
            (unsigned long)0x7007ce07,
            (unsigned long)0x1f007cc0,
            (unsigned long)0x51c38005,
            (unsigned long)0xc2003e28,
            (unsigned long)0xc073e7,
            (unsigned long)0x50400,
            (unsigned long)0x8285040,
            (unsigned long)0x73e7c200,
            (unsigned long)0x40000c0,
            (unsigned long)0x50400005,
            (unsigned long)0xc2000828,
            (unsigned long)0xc073e7,
            (unsigned long)0x50400,
            (unsigned long)0x8285040,
            (unsigned long)0x73e7c200,
            (unsigned long)0xc0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x800e1c00,
            (unsigned long)0x4003,
            (unsigned long)0xe0000000,
            (unsigned long)0x8000003,
            (unsigned long)0x40028011,
            (unsigned long)0x8c000000,
            (unsigned long)0x2800200f,
            (unsigned long)0x87151c78,
            (unsigned long)0xe000,
            (unsigned long)0x40009410,
            (unsigned long)0x2a14a800,
            (unsigned long)0x51430895,
            (unsigned long)0x8c0c0079,
            (unsigned long)0x79e087c0,
            (unsigned long)0x48952a10,
            (unsigned long)0x4952a4,
            (unsigned long)0x4280940a,
            (unsigned long)0x1c100850,
            (unsigned long)0x51444895,
            (unsigned long)0x952a3831,
            (unsigned long)0x8902280,
            (unsigned long)0x45110850,
            (unsigned long)0x4488e004,
            (unsigned long)0xe2808e1c,
            (unsigned long)0x1c300863,
            (unsigned long)0x40038d8e,
            (unsigned long)0x4470,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x400000,
            (unsigned long)0xc00,
            (unsigned long)0x3000,
            (unsigned long)0x201003e,
            (unsigned long)0x12142043,
            (unsigned long)0x20060000,
            (unsigned long)0x4000000,
            (unsigned long)0x428102,
            (unsigned long)0x1228,
            (unsigned long)0x706002,
            (unsigned long)0x80840e3e,
            (unsigned long)0xc00f840,
            (unsigned long)0x20204,
            (unsigned long)0x4000070,
            (unsigned long)0x408102,
            (unsigned long)0xc0000014,
            (unsigned long)0x700002,
            (unsigned long)0x82010e3e,
            (unsigned long)0x282050,
            (unsigned long)0xe28000,
            (unsigned long)0x80000000,
            (unsigned long)0x3087cf,
            (unsigned long)0x0,
            (unsigned long)0x141,
            (unsigned long)0x80000000,
            (unsigned long)0x0,
            (unsigned long)0x1400000,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
            (unsigned long)0x0,
        };

        for (int i = 0; i < 560; i++){
            std::bitset<32> tmp(data[i]);
            for (int pos = 0; pos < 32; pos++){
                fontBitmap.set(i*32+pos, tmp[pos]);
            }
        }
    }
}
