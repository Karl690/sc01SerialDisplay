/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MONO_REGUALR_16
#define MONO_REGUALR_16 1
#endif

#if MONO_REGUALR_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x55, 0x54, 0xf0,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x24, 0x4b, 0xf9, 0x66, 0xc9, 0x3f, 0xa4, 0x48,
    0x90,

    /* U+0024 "$" */
    0x23, 0xe1, 0xc, 0x30, 0xc1, 0x8, 0x7c, 0x42,
    0x0,

    /* U+0025 "%" */
    0x63, 0x2a, 0x74, 0xc7, 0x2, 0x8a, 0x95, 0x4b,
    0x88,

    /* U+0026 "&" */
    0x30, 0x91, 0x22, 0xc7, 0xe, 0xa7, 0x46, 0x8c,
    0xec,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x13, 0x64, 0xc8, 0x88, 0x88, 0xc4, 0x63, 0x10,

    /* U+0029 ")" */
    0x8c, 0x62, 0x31, 0x11, 0x11, 0x32, 0x6c, 0x80,

    /* U+002A "*" */
    0x25, 0x7e, 0xc5, 0x28,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0x6c, 0xa8,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0xc, 0x20, 0x86, 0x10, 0x43, 0xc, 0x20, 0x86,
    0x10, 0x43, 0x0,

    /* U+0030 "0" */
    0x79, 0x28, 0x6d, 0xb6, 0x18, 0x61, 0x49, 0xc0,

    /* U+0031 "1" */
    0x23, 0x28, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+0032 "2" */
    0xf2, 0x20, 0x82, 0x10, 0xc6, 0x10, 0xc3, 0xf0,

    /* U+0033 "3" */
    0xf2, 0x20, 0x82, 0x70, 0x30, 0x41, 0xf, 0xe0,

    /* U+0034 "4" */
    0xc, 0x38, 0x51, 0x24, 0x58, 0xbf, 0x82, 0x4,
    0x8,

    /* U+0035 "5" */
    0x7d, 0x4, 0x10, 0x78, 0x30, 0x41, 0xf, 0xe0,

    /* U+0036 "6" */
    0x1d, 0x84, 0x3e, 0x8e, 0x18, 0x61, 0x49, 0xe0,

    /* U+0037 "7" */
    0xfc, 0x30, 0x86, 0x10, 0xc2, 0x8, 0x21, 0x80,

    /* U+0038 "8" */
    0x7a, 0x38, 0x61, 0x79, 0x68, 0x61, 0x85, 0xe0,

    /* U+0039 "9" */
    0x7b, 0x28, 0x61, 0xc5, 0xf0, 0x42, 0x1b, 0x80,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0x6c, 0x0, 0xd9, 0x50,

    /* U+003C "<" */
    0x0, 0x1d, 0xc6, 0xe, 0x3, 0x81, 0x0,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0x1, 0xc0, 0x70, 0x30, 0xee, 0x10, 0x0,

    /* U+003F "?" */
    0xf0, 0x42, 0x33, 0x31, 0x0, 0x63, 0x0,

    /* U+0040 "@" */
    0x3c, 0xc9, 0xc, 0xfb, 0x34, 0x68, 0xd1, 0xb3,
    0x3d, 0x3, 0x1, 0xc0,

    /* U+0041 "A" */
    0x18, 0x18, 0x24, 0x24, 0x24, 0x66, 0x7e, 0x42,
    0x42, 0xc3,

    /* U+0042 "B" */
    0xfa, 0x38, 0x63, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0043 "C" */
    0x3d, 0xc, 0x20, 0x82, 0x8, 0x20, 0x40, 0xf0,

    /* U+0044 "D" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0x61, 0x8b, 0xc0,

    /* U+0045 "E" */
    0xfa, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x83, 0xf0,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x84, 0x0,

    /* U+0047 "G" */
    0x3d, 0x1c, 0x20, 0x82, 0x18, 0x71, 0x44, 0xf0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x86, 0x10,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+004A "J" */
    0x3c, 0x10, 0x41, 0x4, 0x10, 0x41, 0xd, 0xe0,

    /* U+004B "K" */
    0x8d, 0x12, 0x45, 0xe, 0x1c, 0x24, 0x4c, 0x8d,
    0x8,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0xc7, 0x8f, 0xbd, 0x5a, 0xb2, 0x60, 0xc1, 0x83,
    0x4,

    /* U+004E "N" */
    0x87, 0x1e, 0x69, 0xb6, 0x59, 0x63, 0x8e, 0x10,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0x70,

    /* U+0050 "P" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xc6,
    0xf8, 0xe0, 0xc0, 0xe0,

    /* U+0052 "R" */
    0xf9, 0x1a, 0x14, 0x28, 0xdf, 0x26, 0x44, 0x85,
    0x8,

    /* U+0053 "S" */
    0x7e, 0x8, 0x20, 0x70, 0x60, 0x41, 0x7, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0056 "V" */
    0xc3, 0x42, 0x42, 0x42, 0x66, 0x24, 0x24, 0x3c,
    0x18, 0x18,

    /* U+0057 "W" */
    0x83, 0x6, 0xc, 0x19, 0x35, 0x6a, 0xf7, 0xc7,
    0x8c,

    /* U+0058 "X" */
    0x42, 0x66, 0x24, 0x3c, 0x18, 0x18, 0x2c, 0x24,
    0x66, 0x42,

    /* U+0059 "Y" */
    0xc3, 0x8d, 0x13, 0x62, 0x82, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0xfc, 0x30, 0x84, 0x30, 0x86, 0x10, 0xc3, 0xf0,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8f,

    /* U+005C "\\" */
    0xc1, 0x4, 0x18, 0x20, 0x83, 0xc, 0x10, 0x41,
    0x82, 0x8, 0x30,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f,

    /* U+005E "^" */
    0x30, 0xc4, 0x92, 0x86, 0x10,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0xa4,

    /* U+0061 "a" */
    0x78, 0x30, 0x5f, 0xc6, 0x18, 0x5f,

    /* U+0062 "b" */
    0x82, 0x8, 0x20, 0xf2, 0x28, 0x61, 0x86, 0x18,
    0xbc,

    /* U+0063 "c" */
    0x3d, 0x8, 0x20, 0x82, 0x4, 0xf,

    /* U+0064 "d" */
    0x4, 0x10, 0x41, 0x3d, 0x18, 0x61, 0x86, 0x14,
    0x4f,

    /* U+0065 "e" */
    0x39, 0x38, 0x7f, 0x82, 0x4, 0xf,

    /* U+0066 "f" */
    0x1e, 0x40, 0x87, 0xe2, 0x4, 0x8, 0x10, 0x20,
    0x40, 0x80,

    /* U+0067 "g" */
    0x3d, 0x18, 0x61, 0x86, 0x14, 0x5f, 0x4, 0x3f,
    0x80,

    /* U+0068 "h" */
    0x82, 0x8, 0x20, 0xfa, 0x38, 0x61, 0x86, 0x18,
    0x61,

    /* U+0069 "i" */
    0x61, 0x80, 0x38, 0x20, 0x82, 0x8, 0x20, 0x81,
    0xc0,

    /* U+006A "j" */
    0x18, 0xc0, 0xf0, 0x84, 0x21, 0x8, 0x42, 0x10,
    0xf8,

    /* U+006B "k" */
    0x82, 0x8, 0x20, 0x8a, 0x6b, 0x30, 0xe2, 0x48,
    0xa3,

    /* U+006C "l" */
    0xe0, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x81,
    0xc0,

    /* U+006D "m" */
    0xed, 0x26, 0x4c, 0x99, 0x30, 0x60, 0xc1,

    /* U+006E "n" */
    0xfa, 0x38, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0070 "p" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0xbc, 0x82, 0x8,
    0x0,

    /* U+0071 "q" */
    0x3d, 0x18, 0x61, 0x86, 0x14, 0x4f, 0x4, 0x10,
    0x40,

    /* U+0072 "r" */
    0xfc, 0x21, 0x8, 0x42, 0x10,

    /* U+0073 "s" */
    0x7e, 0x8, 0x1c, 0x18, 0x10, 0x7e,

    /* U+0074 "t" */
    0x20, 0x8f, 0xc8, 0x20, 0x82, 0x8, 0x20, 0x70,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0x5f,

    /* U+0076 "v" */
    0x42, 0x42, 0x66, 0x24, 0x24, 0x3c, 0x18, 0x18,

    /* U+0077 "w" */
    0xc3, 0xc3, 0x5a, 0x5a, 0x5a, 0x66, 0x66, 0x66,

    /* U+0078 "x" */
    0x42, 0x24, 0x3c, 0x18, 0x18, 0x24, 0x66, 0x42,

    /* U+0079 "y" */
    0x87, 0x1c, 0xd2, 0x49, 0xa3, 0x8c, 0x10, 0x8c,
    0x0,

    /* U+007A "z" */
    0xfc, 0x31, 0x8c, 0x21, 0x8c, 0x3f,

    /* U+007B "{" */
    0x1c, 0x82, 0x8, 0x20, 0x8c, 0x8, 0x20, 0x82,
    0x8, 0x20, 0x70,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xe0, 0x41, 0x4, 0x10, 0x40, 0xc4, 0x10, 0x41,
    0x4, 0x13, 0x80,

    /* U+007E "~" */
    0xe6, 0x70,

    /* U+00A9 "©" */
    0x38, 0x8a, 0x6d, 0x1a, 0x33, 0x51, 0x1c,

    /* U+2013 "–" */
    0xfc,

    /* U+2014 "—" */
    0xff,

    /* U+2015 "―" */
    0xff,

    /* U+2018 "‘" */
    0x2a, 0x6c,

    /* U+2019 "’" */
    0x6c, 0xa8,

    /* U+201A "‚" */
    0x6c, 0xa8,

    /* U+201C "“" */
    0x67, 0x13, 0x36, 0x60,

    /* U+201D "”" */
    0x66, 0xcc, 0x8e, 0x60,

    /* U+201E "„" */
    0x66, 0xcc, 0x8e, 0x60,

    /* U+2020 "†" */
    0x20, 0x82, 0x3f, 0x20, 0x82, 0x8, 0x20, 0x82,
    0x8,

    /* U+2021 "‡" */
    0x20, 0x82, 0x3f, 0x20, 0x82, 0x3f, 0x20, 0x82,
    0x8,

    /* U+2022 "•" */
    0x6f, 0xff, 0x60,

    /* U+2026 "…" */
    0x93, 0x24,

    /* U+2030 "‰" */
    0xe0, 0xa1, 0xa6, 0xf8, 0x60, 0xb6, 0x35, 0x35,
    0x35, 0x37,

    /* U+2039 "‹" */
    0x25, 0xe4, 0xc8,

    /* U+203A "›" */
    0x93, 0x35, 0xa0,

    /* U+2044 "⁄" */
    0x2, 0x2, 0x4, 0x8, 0x8, 0x10, 0x10, 0x20,
    0x40, 0x40,

    /* U+2070 "⁰" */
    0x69, 0xf9, 0x60,

    /* U+2074 "⁴" */
    0x33, 0x95, 0xf1, 0x0,

    /* U+2075 "⁵" */
    0xf8, 0xf1, 0xe0,

    /* U+2076 "⁶" */
    0x7e, 0x99, 0x60,

    /* U+2077 "⁷" */
    0xf1, 0x24, 0x40,

    /* U+2078 "⁸" */
    0xf9, 0x69, 0xf0,

    /* U+2079 "⁹" */
    0xe9, 0xf3, 0xe0,

    /* U+2080 "₀" */
    0x69, 0x9f, 0x96,

    /* U+2081 "₁" */
    0x2e, 0x22, 0x2f,

    /* U+2082 "₂" */
    0x71, 0x12, 0x4f,

    /* U+2083 "₃" */
    0xe1, 0x61, 0x1e,

    /* U+2084 "₄" */
    0x11, 0x94, 0xaf, 0x88,

    /* U+2085 "₅" */
    0xf8, 0xc1, 0x1e,

    /* U+2086 "₆" */
    0x7c, 0xe9, 0x96,

    /* U+2087 "₇" */
    0xf1, 0x22, 0x44,

    /* U+2088 "₈" */
    0x79, 0xfb, 0x9f,

    /* U+2089 "₉" */
    0x69, 0x97, 0x3c,

    /* U+20AC "€" */
    0x1c, 0x41, 0x7, 0xc4, 0x1f, 0x10, 0x20, 0x20,
    0x3c,

    /* U+20AE "₮" */
    0xfe, 0x20, 0x40, 0xe7, 0xa, 0x87, 0x38, 0x10,
    0x20,

    /* U+20B4 "₴" */
    0x78, 0x8, 0x17, 0xf1, 0x1f, 0xd0, 0x20, 0x40,
    0x78,

    /* U+20B9 "₹" */
    0xfc, 0x30, 0x27, 0xe1, 0x9c, 0x30, 0x30, 0x30,
    0x30,

    /* U+2113 "ℓ" */
    0x32, 0x52, 0x95, 0xa9, 0x88, 0xc2, 0xe,

    /* U+2116 "№" */
    0x97, 0xaf, 0x5e, 0xbd, 0x76, 0x2c, 0x5b, 0xb1,
    0x20,

    /* U+2122 "™" */
    0xf2, 0xbd, 0x7a, 0x90,

    /* U+2126 "Ω" */
    0x38, 0x89, 0x16, 0x3c, 0x78, 0xf1, 0xa2, 0x45,
    0xdc,

    /* U+212E "℮" */
    0x39, 0x8a, 0xf, 0xf8, 0x10, 0x11, 0x1c,

    /* U+2153 "⅓" */
    0x47, 0x89, 0x22, 0x41, 0x4, 0xb, 0xa3, 0xc3,
    0x1c,

    /* U+2154 "⅔" */
    0xe2, 0x49, 0x17, 0x41, 0x82, 0xb, 0x93, 0x43,
    0x9c,

    /* U+2155 "⅕" */
    0x47, 0x89, 0x22, 0xc1, 0x4, 0xb, 0xa4, 0xc3,
    0x1c,

    /* U+2156 "⅖" */
    0xe2, 0x49, 0x17, 0x41, 0x82, 0xb, 0x94, 0x42,
    0x9c,

    /* U+2157 "⅗" */
    0xc3, 0x89, 0x36, 0x41, 0x2, 0xb, 0xa4, 0x43,
    0x1c,

    /* U+2158 "⅘" */
    0x63, 0x4b, 0xd1, 0x41, 0x82, 0x9, 0x94, 0x42,
    0x9c,

    /* U+2159 "⅙" */
    0x22, 0x62, 0x24, 0x28, 0x8, 0x16, 0x3c, 0x2e,
    0x4b, 0x46,

    /* U+215A "⅚" */
    0xe3, 0x88, 0xb7, 0x41, 0x3, 0x8e, 0x2e, 0x57,
    0x18,

    /* U+215B "⅛" */
    0x22, 0x62, 0x24, 0x28, 0x8, 0x17, 0x35, 0x26,
    0x49, 0x47,

    /* U+215C "⅜" */
    0xe2, 0x64, 0x24, 0xe8, 0x18, 0x1e, 0x2a, 0x26,
    0x4a, 0x8e,

    /* U+215D "⅝" */
    0xe7, 0x88, 0xa7, 0x41, 0x7, 0xca, 0xa6, 0x53,
    0x1c,

    /* U+215E "⅞" */
    0x62, 0x24, 0x44, 0x48, 0x18, 0x1e, 0x2a, 0x26,
    0x4a, 0xce,

    /* U+2202 "∂" */
    0x70, 0x20, 0x41, 0x7d, 0x18, 0x61, 0x8f, 0x27,
    0x0,

    /* U+2206 "∆" */
    0x18, 0x18, 0x3c, 0x24, 0x24, 0x66, 0x42, 0x42,
    0x42, 0xff,

    /* U+220F "∏" */
    0xfe, 0x18, 0x61, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x40,

    /* U+2211 "∑" */
    0xff, 0x6, 0x8, 0x30, 0x43, 0x18, 0x43, 0xf,
    0xc0,

    /* U+2212 "−" */
    0xfe,

    /* U+2215 "∕" */
    0x2, 0x2, 0x4, 0xc, 0x8, 0x10, 0x10, 0x20,
    0x40, 0x40,

    /* U+2219 "∙" */
    0xf0,

    /* U+221A "√" */
    0x3, 0x2, 0x2, 0x2, 0x4, 0x24, 0x64, 0x24,
    0x18, 0x18, 0x18,

    /* U+221E "∞" */
    0x6d, 0x26, 0x4b, 0x60,

    /* U+222B "∫" */
    0x19, 0x8, 0x42, 0x10, 0x84, 0x21, 0x8, 0x42,
    0x60,

    /* U+2248 "≈" */
    0xe6, 0x70, 0x39, 0x9c,

    /* U+2260 "≠" */
    0x4, 0x1b, 0xf8, 0x81, 0x1f, 0xd8, 0x20,

    /* U+2264 "≤" */
    0x6, 0x3b, 0x87, 0x3, 0x80, 0xc0, 0x7f,

    /* U+2265 "≥" */
    0xc0, 0xe0, 0x38, 0x73, 0x98, 0x0, 0x7f,

    /* U+2500 "─" */
    0xff,

    /* U+2502 "│" */
    0xff, 0xff,

    /* U+250C "┌" */
    0xf8, 0x88, 0x88, 0x88,

    /* U+2510 "┐" */
    0xf1, 0x11, 0x11, 0x11,

    /* U+2514 "└" */
    0x88, 0x88, 0x88, 0x8f,

    /* U+2518 "┘" */
    0x11, 0x11, 0x11, 0x1f,

    /* U+251C "├" */
    0x88, 0x88, 0x88, 0x8f, 0xf8, 0x88, 0x88, 0x88,

    /* U+2524 "┤" */
    0x11, 0x11, 0x11, 0x1f, 0xf1, 0x11, 0x11, 0x11,

    /* U+252C "┬" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+2534 "┴" */
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff,

    /* U+253C "┼" */
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff,
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+2550 "═" */
    0xff, 0xff, 0x0, 0xff,

    /* U+2551 "║" */
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99,

    /* U+2552 "╒" */
    0xff, 0xf, 0x88, 0x88, 0x88,

    /* U+2553 "╓" */
    0x9e, 0x49, 0x24, 0x92, 0x49, 0x24,

    /* U+2554 "╔" */
    0xff, 0xf8, 0x27, 0x92, 0x49, 0x24, 0x92, 0x40,

    /* U+2555 "╕" */
    0xff, 0xf, 0x11, 0x11, 0x11,

    /* U+2556 "╖" */
    0xe4, 0x92, 0x49, 0x24, 0x92, 0x49,

    /* U+2557 "╗" */
    0xff, 0xf0, 0x79, 0x24, 0x92, 0x49, 0x24, 0x90,

    /* U+2558 "╘" */
    0x88, 0x88, 0x88, 0xf0, 0xf0,

    /* U+2559 "╙" */
    0x92, 0x49, 0x24, 0x92, 0x49, 0x27,

    /* U+255A "╚" */
    0x92, 0x49, 0x24, 0x92, 0x49, 0xe0, 0xfc,

    /* U+255B "╛" */
    0x11, 0x11, 0x11, 0xf0, 0xf0,

    /* U+255C "╜" */
    0x24, 0x92, 0x49, 0x24, 0x92, 0x79,

    /* U+255D "╝" */
    0x24, 0x92, 0x49, 0x24, 0x9e, 0x41, 0xfc,

    /* U+255E "╞" */
    0x88, 0x88, 0x88, 0xf0, 0xf8, 0x88, 0x88, 0x80,

    /* U+255F "╟" */
    0x92, 0x49, 0x24, 0x92, 0x49, 0x27, 0x9e, 0x49,
    0x24, 0x92, 0x49, 0x24,

    /* U+2560 "╠" */
    0x92, 0x49, 0x24, 0x92, 0x49, 0xe0, 0x82, 0x79,
    0x24, 0x92, 0x49, 0x24,

    /* U+2561 "╡" */
    0x11, 0x11, 0x11, 0xf0, 0xf1, 0x11, 0x11, 0x10,

    /* U+2562 "╢" */
    0x24, 0x92, 0x49, 0x24, 0x92, 0x79, 0xe4, 0x92,
    0x49, 0x24, 0x92, 0x49,

    /* U+2563 "╣" */
    0x24, 0x92, 0x49, 0x24, 0x9e, 0x41, 0x7, 0x92,
    0x49, 0x24, 0x92, 0x49,

    /* U+2564 "╤" */
    0xff, 0xff, 0x0, 0xff, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+2565 "╥" */
    0xff, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,

    /* U+2566 "╦" */
    0xff, 0xff, 0x0, 0xe7, 0x24, 0x24, 0x24, 0x24,
    0x24, 0x24,

    /* U+2567 "╧" */
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff, 0x0,
    0xff,

    /* U+2568 "╨" */
    0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xff,

    /* U+2569 "╩" */
    0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xe7, 0x0,
    0xff,

    /* U+256A "╪" */
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff, 0x18,
    0x18, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+256B "╫" */
    0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xff,
    0xff, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,

    /* U+256C "╬" */
    0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xe7, 0x0,
    0xe7, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,

    /* U+2588 "█" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+2591 "░" */
    0x95, 0xa, 0x95, 0x0, 0x2, 0x95, 0xa, 0x95,
    0x0, 0x2, 0x95, 0xa, 0x95, 0x0, 0x2, 0x95,

    /* U+2592 "▒" */
    0xdd, 0xb7, 0x37, 0x60, 0x0, 0x26, 0xed, 0xb9,
    0xbb, 0x0, 0x1, 0x37, 0x6d, 0xcd, 0xd8, 0x0,
    0x9, 0xbb,

    /* U+2593 "▓" */
    0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff,
    0xdf, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff,

    /* U+25CA "◊" */
    0x20, 0xc7, 0x92, 0x86, 0x14, 0x92, 0x30, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 128, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 24, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 128, .box_w = 1, .box_h = 4, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 43, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 51, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 59, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 63, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 70, .adv_w = 128, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 72, .adv_w = 128, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 73, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 85, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 128, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 128, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 171, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 178, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 182, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 189, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 208, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 351, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 128, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 438, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 449, .adv_w = 128, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 456, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 461, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 462, .adv_w = 128, .box_w = 2, .box_h = 3, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 463, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 518, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 545, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 570, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 592, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 601, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 620, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 659, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 676, .adv_w = 128, .box_w = 1, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 678, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 689, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 691, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 698, .adv_w = 128, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 699, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 700, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 701, .adv_w = 128, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 703, .adv_w = 128, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 705, .adv_w = 128, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 707, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 711, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 715, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 719, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 728, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 737, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 740, .adv_w = 128, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 742, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 752, .adv_w = 128, .box_w = 3, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 755, .adv_w = 128, .box_w = 3, .box_h = 7, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 758, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 768, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 771, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 775, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 778, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 781, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 784, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 787, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 790, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 793, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 796, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 799, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 802, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 806, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 809, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 812, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 818, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 821, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 830, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 839, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 128, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 873, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 877, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 886, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 893, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 902, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 920, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 929, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 938, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 947, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 966, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 976, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 986, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 995, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1005, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1014, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1024, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1033, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1042, .adv_w = 128, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1043, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1053, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 1054, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1065, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1069, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1078, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1082, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1089, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1096, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1103, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1104, .adv_w = 128, .box_w = 1, .box_h = 16, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 1106, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 1110, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1114, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 1118, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1122, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 1130, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1138, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1146, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1154, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1170, .adv_w = 128, .box_w = 8, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1174, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1182, .adv_w = 128, .box_w = 4, .box_h = 10, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 1187, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1193, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1201, .adv_w = 128, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1206, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1212, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1220, .adv_w = 128, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 4},
    {.bitmap_index = 1225, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 1231, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 1238, .adv_w = 128, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 1243, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1249, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1256, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 1264, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1276, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1288, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1296, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1308, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1320, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1330, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1338, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1348, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1357, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1365, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1374, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1390, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1406, .adv_w = 128, .box_w = 8, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1421, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1437, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1453, .adv_w = 128, .box_w = 9, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1471, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1487, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x1f6a, 0x1f6b, 0x1f6c, 0x1f6f, 0x1f70, 0x1f71, 0x1f73,
    0x1f74, 0x1f75, 0x1f77, 0x1f78, 0x1f79, 0x1f7d, 0x1f87, 0x1f90,
    0x1f91, 0x1f9b, 0x1fc7, 0x1fcb, 0x1fcc, 0x1fcd, 0x1fce, 0x1fcf,
    0x1fd0, 0x1fd7, 0x1fd8, 0x1fd9, 0x1fda, 0x1fdb, 0x1fdc, 0x1fdd,
    0x1fde, 0x1fdf, 0x1fe0, 0x2003, 0x2005, 0x200b, 0x2010, 0x206a,
    0x206d, 0x2079, 0x207d, 0x2085, 0x20aa, 0x20ab, 0x20ac, 0x20ad,
    0x20ae, 0x20af, 0x20b0, 0x20b1, 0x20b2, 0x20b3, 0x20b4, 0x20b5,
    0x2159, 0x215d, 0x2166, 0x2168, 0x2169, 0x216c, 0x2170, 0x2171,
    0x2175, 0x2182, 0x219f, 0x21b7, 0x21bb, 0x21bc, 0x2457, 0x2459,
    0x2463, 0x2467, 0x246b, 0x246f, 0x2473, 0x247b, 0x2483, 0x248b,
    0x2493
};

static const uint16_t unicode_list_3[] = {
    0x0, 0x9, 0xa, 0xb, 0x42
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 169, .range_length = 9364, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 81, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 9552, .range_length = 29, .glyph_id_start = 177,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 9608, .range_length = 67, .glyph_id_start = 206,
        .unicode_list = unicode_list_3, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t mono_regualr_16 = {
#else
lv_font_t mono_regualr_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MONO_REGUALR_16*/

