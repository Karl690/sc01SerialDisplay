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

#ifndef MONO_BOLD_16
#define MONO_BOLD_16 1
#endif

#if MONO_BOLD_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xf0, 0xf0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x34, 0x4b, 0xff, 0xf6, 0xcd, 0xbf, 0xff, 0x48,
    0xb0,

    /* U+0024 "$" */
    0x30, 0xc7, 0xf0, 0xc3, 0xc7, 0x87, 0xe, 0x3f,
    0xcc, 0x30,

    /* U+0025 "%" */
    0x63, 0xf6, 0xfe, 0xfc, 0x78, 0x1e, 0x3f, 0x7f,
    0x6f, 0xc6,

    /* U+0026 "&" */
    0x38, 0xf9, 0xb3, 0x63, 0x8e, 0xf3, 0xe3, 0xfe,
    0xec,

    /* U+0027 "'" */
    0xff, 0xc0,

    /* U+0028 "(" */
    0x8, 0xcc, 0xc6, 0x63, 0x18, 0xc6, 0x38, 0xc3,
    0x1c, 0x20,

    /* U+0029 ")" */
    0x86, 0x18, 0x63, 0xc, 0x63, 0x18, 0xcc, 0x66,
    0x72, 0x0,

    /* U+002A "*" */
    0x32, 0xdf, 0xcc, 0x79, 0x20,

    /* U+002B "+" */
    0x30, 0x63, 0xff, 0xf3, 0x6, 0xc, 0x0,

    /* U+002C "," */
    0x77, 0x73, 0xe0,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0xc, 0x31, 0x86, 0x18, 0xe3, 0xc, 0x71, 0x86,
    0x18, 0xc3, 0x0,

    /* U+0030 "0" */
    0x79, 0xec, 0xff, 0xff, 0x3c, 0xf3, 0x79, 0xe0,

    /* U+0031 "1" */
    0x18, 0x71, 0xe0, 0xc1, 0x83, 0x6, 0xc, 0x7e,
    0xfc,

    /* U+0032 "2" */
    0x79, 0xfa, 0x30, 0x61, 0x86, 0x18, 0x60, 0xff,
    0xfc,

    /* U+0033 "3" */
    0x7b, 0xf0, 0xde, 0x78, 0x30, 0xc3, 0xff, 0xe0,

    /* U+0034 "4" */
    0xc, 0x38, 0xf1, 0x66, 0xd9, 0xbf, 0xff, 0xc,
    0x18,

    /* U+0035 "5" */
    0x7d, 0xf4, 0x10, 0x78, 0x70, 0xc3, 0xff, 0xe0,

    /* U+0036 "6" */
    0x1c, 0x79, 0x87, 0xef, 0xf8, 0xf1, 0xe3, 0x7c,
    0x70,

    /* U+0037 "7" */
    0xff, 0xf1, 0xc6, 0x30, 0xc3, 0x18, 0x61, 0x80,

    /* U+0038 "8" */
    0x7d, 0xff, 0x1e, 0x37, 0xcf, 0xb1, 0xe3, 0xfe,
    0xf8,

    /* U+0039 "9" */
    0x79, 0xfb, 0x1e, 0x3f, 0xef, 0xc3, 0x8e, 0x78,
    0xe0,

    /* U+003A ":" */
    0xff, 0x81, 0xff,

    /* U+003B ";" */
    0x77, 0x70, 0x7, 0x77, 0x3e,

    /* U+003C "<" */
    0x4, 0x3d, 0xe7, 0xf, 0x7, 0xc3, 0x0,

    /* U+003D "=" */
    0xff, 0xfc, 0x7, 0xff, 0xe0,

    /* U+003E ">" */
    0x41, 0xe0, 0xf0, 0x71, 0xff, 0x18, 0x0,

    /* U+003F "?" */
    0xfb, 0xf8, 0xc3, 0x18, 0xc7, 0x0, 0x71, 0xc0,

    /* U+0040 "@" */
    0x3c, 0xf9, 0x9e, 0x3d, 0xff, 0xfd, 0xfb, 0xf7,
    0xff, 0x7b, 0x7, 0xe7, 0xc0,

    /* U+0041 "A" */
    0x18, 0x3c, 0x3c, 0x3c, 0x24, 0x66, 0x7e, 0x7e,
    0xe6, 0xc3,

    /* U+0042 "B" */
    0xf9, 0xfb, 0x36, 0x6f, 0x9f, 0xb1, 0xe3, 0xff,
    0xf0,

    /* U+0043 "C" */
    0x3e, 0xff, 0x8e, 0xc, 0x18, 0x30, 0x70, 0x7e,
    0x7c,

    /* U+0044 "D" */
    0xf9, 0xfb, 0x3e, 0x3c, 0x78, 0xf1, 0xe7, 0xfd,
    0xf0,

    /* U+0045 "E" */
    0xfd, 0xfb, 0x6, 0xf, 0xdf, 0xb0, 0x60, 0xff,
    0xfc,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x3e, 0xff, 0x8e, 0xc, 0x18, 0xf1, 0xf3, 0x7e,
    0x7c,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3f, 0xff, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0049 "I" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0xff, 0xf0,

    /* U+004A "J" */
    0x7e, 0xfc, 0x18, 0x30, 0x60, 0xc1, 0xa3, 0x7e,
    0xf8,

    /* U+004B "K" */
    0xcf, 0x9b, 0x67, 0xcf, 0x1f, 0x36, 0x66, 0xcf,
    0x8c,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xff, 0xf0,

    /* U+004D "M" */
    0xcf, 0xdf, 0xbf, 0x7f, 0xfa, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+004E "N" */
    0xc7, 0xcf, 0x9f, 0xbd, 0x7b, 0xf3, 0xe7, 0xc7,
    0x8c,

    /* U+004F "O" */
    0x38, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x7c,
    0x70,

    /* U+0050 "P" */
    0xf9, 0xff, 0x1e, 0x3c, 0x7f, 0xfe, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x38, 0xfb, 0xbe, 0x3c, 0x78, 0xf1, 0xe3, 0xee,
    0xf8, 0xe0, 0xc0, 0xe0,

    /* U+0052 "R" */
    0xf9, 0xfb, 0x36, 0x6f, 0xdf, 0x36, 0x66, 0xcd,
    0x98,

    /* U+0053 "S" */
    0x7d, 0xfb, 0x6, 0x7, 0x3, 0x81, 0xc3, 0xfe,
    0xf8,

    /* U+0054 "T" */
    0xff, 0xfc, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18,
    0x30,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xfe,
    0xf8,

    /* U+0056 "V" */
    0xc3, 0x66, 0x66, 0x66, 0x66, 0x24, 0x3c, 0x3c,
    0x3c, 0x18,

    /* U+0057 "W" */
    0xc7, 0x8f, 0x1e, 0x3d, 0x7f, 0xfb, 0xf7, 0xef,
    0xcc,

    /* U+0058 "X" */
    0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66,
    0x66, 0xe7,

    /* U+0059 "Y" */
    0xc3, 0x66, 0x66, 0x34, 0x3c, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xff, 0xfc, 0x30, 0xe1, 0x86, 0x18, 0x30, 0xff,
    0xfc,

    /* U+005B "[" */
    0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8f,
    0xfc,

    /* U+005C "\\" */
    0xc3, 0x6, 0x18, 0x60, 0xc3, 0xc, 0x38, 0x61,
    0x86, 0xc, 0x30,

    /* U+005D "]" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x3f,
    0xfc,

    /* U+005E "^" */
    0x18, 0x3c, 0x3c, 0x66, 0x66, 0x42,

    /* U+005F "_" */
    0xff, 0xff,

    /* U+0060 "`" */
    0x67, 0x0,

    /* U+0061 "a" */
    0x79, 0xf0, 0xdf, 0xff, 0x3f, 0xdf,

    /* U+0062 "b" */
    0x1, 0x83, 0x6, 0xf, 0x9f, 0xb1, 0xe3, 0xc7,
    0x9f, 0xf7, 0xc0,

    /* U+0063 "c" */
    0x3e, 0xfb, 0x86, 0xc, 0x1c, 0x1f, 0x9f,

    /* U+0064 "d" */
    0x0, 0x30, 0xc3, 0x7f, 0xfc, 0xf3, 0xcf, 0x37,
    0xdf,

    /* U+0065 "e" */
    0x38, 0xfb, 0x1f, 0xff, 0xf8, 0x1f, 0x1f,

    /* U+0066 "f" */
    0x1e, 0x3e, 0x30, 0xfe, 0xfe, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30,

    /* U+0067 "g" */
    0x3d, 0xfc, 0xf3, 0xcf, 0x3f, 0xdf, 0xf, 0xff,
    0x80,

    /* U+0068 "h" */
    0x3, 0xc, 0x30, 0xfb, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3,

    /* U+0069 "i" */
    0x38, 0x38, 0x0, 0xf8, 0xf8, 0x18, 0x18, 0x18,
    0x18, 0x1f, 0xf,

    /* U+006A "j" */
    0x1c, 0x70, 0x3f, 0xfc, 0x30, 0xc3, 0xc, 0x30,
    0xe3, 0xff, 0xe0,

    /* U+006B "k" */
    0x41, 0x83, 0x6, 0xc, 0xdb, 0x34, 0x78, 0xf1,
    0xb3, 0x36, 0x70,

    /* U+006C "l" */
    0xf1, 0xe0, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x7c, 0x78,

    /* U+006D "m" */
    0xfe, 0xff, 0xdb, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3,

    /* U+006E "n" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3c, 0xf3,

    /* U+006F "o" */
    0x38, 0xfb, 0x1e, 0x3c, 0x78, 0xdf, 0x1c,

    /* U+0070 "p" */
    0xf3, 0xec, 0xf3, 0xcf, 0x3f, 0xfe, 0xc3, 0xc,
    0x0,

    /* U+0071 "q" */
    0x3e, 0xff, 0x9e, 0x3c, 0x78, 0xdf, 0xbf, 0x6,
    0xc, 0x18,

    /* U+0072 "r" */
    0xff, 0xfc, 0x30, 0xc3, 0xc, 0x30,

    /* U+0073 "s" */
    0x7f, 0xfc, 0x38, 0x38, 0x3f, 0xfe,

    /* U+0074 "t" */
    0x30, 0x63, 0xff, 0xf3, 0x6, 0xc, 0x18, 0x3e,
    0x3c,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3f, 0xdf,

    /* U+0076 "v" */
    0xc3, 0x66, 0x66, 0x66, 0x3c, 0x3c, 0x38, 0x18,

    /* U+0077 "w" */
    0xc3, 0xc3, 0xdb, 0x5a, 0x5a, 0x7e, 0x66, 0x66,

    /* U+0078 "x" */
    0x66, 0x66, 0x3c, 0x18, 0x1c, 0x3c, 0x66, 0x66,

    /* U+0079 "y" */
    0x66, 0x66, 0x66, 0x36, 0x34, 0x3c, 0x1c, 0x18,
    0x18, 0x70, 0xf0,

    /* U+007A "z" */
    0xff, 0xf1, 0x8c, 0x71, 0x8f, 0xff,

    /* U+007B "{" */
    0x1c, 0xf3, 0xc, 0x30, 0xce, 0x38, 0x30, 0xc3,
    0xc, 0x3c, 0x70,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xf1, 0xf0, 0x60, 0xc1, 0x83, 0x3, 0x87, 0x18,
    0x30, 0x60, 0xcf, 0x9e, 0x0,

    /* U+007E "~" */
    0x73, 0x7e, 0xce,

    /* U+00A9 "©" */
    0x38, 0x8a, 0x6d, 0x1a, 0x33, 0x51, 0x1c,

    /* U+2013 "–" */
    0xff, 0xf0,

    /* U+2014 "—" */
    0xff, 0xff,

    /* U+2015 "―" */
    0xff, 0xff,

    /* U+2018 "‘" */
    0x7c, 0xee, 0xe0,

    /* U+2019 "’" */
    0x77, 0x73, 0xe0,

    /* U+201A "‚" */
    0x77, 0x73, 0xe0,

    /* U+201C "“" */
    0x67, 0x93, 0x36, 0x60,

    /* U+201D "”" */
    0x66, 0xcc, 0x9e, 0x60,

    /* U+201E "„" */
    0x0, 0xcd, 0x9b, 0x3c, 0xc0,

    /* U+2020 "†" */
    0x30, 0xcf, 0xff, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc,

    /* U+2021 "‡" */
    0x30, 0xcf, 0xff, 0x30, 0xcf, 0xff, 0x30, 0xc3,
    0xc,

    /* U+2022 "•" */
    0x6f, 0xff, 0x60,

    /* U+2026 "…" */
    0xdb, 0xdb,

    /* U+2030 "‰" */
    0xe0, 0xa0, 0xa3, 0xec, 0x30, 0xc0, 0x77, 0x55,
    0x55, 0x77,

    /* U+2039 "‹" */
    0x23, 0x6e, 0x67, 0x30,

    /* U+203A "›" */
    0x6, 0x73, 0x36, 0x60,

    /* U+2044 "⁄" */
    0x2, 0x6, 0x4, 0xc, 0x18, 0x18, 0x30, 0x20,
    0x60, 0x40,

    /* U+2070 "⁰" */
    0x76, 0xf7, 0xbd, 0xb8,

    /* U+2074 "⁴" */
    0x33, 0x9d, 0x6f, 0x98,

    /* U+2075 "⁵" */
    0x7a, 0x1c, 0x71, 0xf8,

    /* U+2076 "⁶" */
    0x33, 0x3f, 0xbd, 0xb8,

    /* U+2077 "⁷" */
    0xf3, 0x26, 0x64,

    /* U+2078 "⁸" */
    0x76, 0xbd, 0xed, 0x38,

    /* U+2079 "⁹" */
    0x76, 0xf7, 0xf3, 0x30,

    /* U+2080 "₀" */
    0x76, 0xf7, 0xbd, 0xb8,

    /* U+2081 "₁" */
    0x67, 0x38, 0xc6, 0x7c,

    /* U+2082 "₂" */
    0xeb, 0x36, 0xcf,

    /* U+2083 "₃" */
    0xf3, 0x73, 0x3e,

    /* U+2084 "₄" */
    0x33, 0x9d, 0x6f, 0x98,

    /* U+2085 "₅" */
    0x7a, 0x1c, 0x71, 0xf8,

    /* U+2086 "₆" */
    0x33, 0x3f, 0xbd, 0xb8,

    /* U+2087 "₇" */
    0xf3, 0x26, 0x64,

    /* U+2088 "₈" */
    0x76, 0xbd, 0xed, 0x78,

    /* U+2089 "₉" */
    0x76, 0xf6, 0xf3, 0x30,

    /* U+20AC "€" */
    0x1e, 0xff, 0xf7, 0xe6, 0x1f, 0xbf, 0x38, 0x3e,
    0x3c,

    /* U+20AE "₮" */
    0xff, 0xfc, 0x60, 0xe1, 0xcf, 0x7, 0x1c, 0x78,
    0x30,

    /* U+20B4 "₴" */
    0x7c, 0xff, 0xff, 0xf7, 0x9f, 0xff, 0xe0, 0xfe,
    0xf8,

    /* U+20B9 "₹" */
    0xff, 0xfc, 0x67, 0xe1, 0x9e, 0x30, 0x30, 0x30,
    0x30,

    /* U+2113 "ℓ" */
    0x32, 0x52, 0x95, 0xa9, 0x88, 0xc2, 0xe,

    /* U+2116 "№" */
    0x96, 0x9f, 0xdf, 0xd6, 0xf6, 0xf0, 0xbf, 0xbf,
    0x90, 0x90,

    /* U+2122 "™" */
    0xf2, 0xbd, 0x7a, 0x90,

    /* U+2126 "Ω" */
    0x38, 0xcb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x6d,
    0xdc,

    /* U+212E "℮" */
    0x39, 0x8a, 0xf, 0xf8, 0x10, 0x11, 0x1c,

    /* U+2153 "⅓" */
    0x66, 0xe4, 0x6c, 0x68, 0x18, 0x30, 0x36, 0x66,
    0x62, 0xc6,

    /* U+2154 "⅔" */
    0xe2, 0x26, 0x4c, 0xec, 0x18, 0x18, 0x3f, 0x27,
    0x63, 0x4f,

    /* U+2155 "⅕" */
    0x66, 0xe6, 0x6c, 0x6c, 0x18, 0x18, 0x37, 0x36,
    0x61, 0xc7,

    /* U+2156 "⅖" */
    0xe2, 0x26, 0x44, 0xec, 0x8, 0x18, 0x17, 0x36,
    0x21, 0x4f,

    /* U+2157 "⅗" */
    0xe2, 0x66, 0x24, 0xec, 0x8, 0x18, 0x17, 0x36,
    0x21, 0x67,

    /* U+2158 "⅘" */
    0x72, 0xf6, 0xf6, 0x3c, 0xc, 0x18, 0x1f, 0x36,
    0x31, 0x67,

    /* U+2159 "⅙" */
    0x65, 0xc9, 0xb3, 0xc1, 0x86, 0xd, 0xb7, 0x6b,
    0x9c,

    /* U+215A "⅚" */
    0x73, 0x66, 0x16, 0xfc, 0xc, 0x18, 0x1b, 0x37,
    0x35, 0x67,

    /* U+215B "⅛" */
    0x64, 0xec, 0x68, 0x78, 0x18, 0x30, 0x3e, 0x6e,
    0x6a, 0xce,

    /* U+215C "⅜" */
    0xe6, 0x64, 0x2c, 0xe8, 0x18, 0x10, 0x3e, 0x2e,
    0x6a, 0x4e,

    /* U+215D "⅝" */
    0x72, 0x66, 0x14, 0xfc, 0x8, 0x18, 0x17, 0x35,
    0x27, 0x67,

    /* U+215E "⅞" */
    0xe4, 0x4c, 0x48, 0xd8, 0x10, 0x30, 0x2e, 0x6e,
    0x4a, 0xce,

    /* U+2202 "∂" */
    0x78, 0x18, 0x18, 0x33, 0xec, 0xf1, 0xe3, 0xc5,
    0x99, 0xe0,

    /* U+2206 "∆" */
    0x18, 0x3c, 0x3c, 0x2c, 0x66, 0x66, 0x66, 0x66,
    0xff,

    /* U+220F "∏" */
    0xff, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x18,

    /* U+2211 "∑" */
    0xff, 0xc1, 0x81, 0x83, 0x3, 0xc, 0x18, 0x61,
    0xc3, 0xf8,

    /* U+2212 "−" */
    0xfe,

    /* U+2215 "∕" */
    0x2, 0x6, 0x4, 0xc, 0x18, 0x18, 0x30, 0x20,
    0x60, 0x40,

    /* U+2219 "∙" */
    0xfc,

    /* U+221A "√" */
    0x3, 0x6, 0x6, 0x6, 0x6, 0x6c, 0xec, 0x3c,
    0x3c, 0x18, 0x18,

    /* U+221E "∞" */
    0x6d, 0x76, 0xeb, 0x60,

    /* U+222B "∫" */
    0x1c, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0xf3, 0x80,

    /* U+2248 "≈" */
    0x73, 0x7e, 0xce, 0x32, 0x7f, 0xce,

    /* U+2260 "≠" */
    0x4, 0x1b, 0xf8, 0xc1, 0x1f, 0xd8, 0x20,

    /* U+2264 "≤" */
    0xe, 0x7f, 0xc7, 0x83, 0xe1, 0xc0, 0x7f,

    /* U+2265 "≥" */
    0xe1, 0xf0, 0x78, 0xff, 0x9c, 0x0, 0x7f,

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
    0x10, 0x18, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x3c,
    0x18, 0x18
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 128, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 7, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 26, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 128, .box_w = 2, .box_h = 5, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 47, .adv_w = 128, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 57, .adv_w = 128, .box_w = 5, .box_h = 15, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 67, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 72, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 79, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 82, .adv_w = 128, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 83, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 96, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 128, .box_w = 3, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 128, .box_w = 4, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 190, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 197, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 202, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 209, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 230, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 336, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 384, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 477, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 488, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 497, .adv_w = 128, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 503, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 505, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 507, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 531, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 558, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 567, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 598, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 627, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 649, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 659, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 671, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 702, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 710, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 721, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 738, .adv_w = 128, .box_w = 2, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 742, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 755, .adv_w = 128, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 758, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 765, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 767, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 769, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 771, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 774, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 777, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 780, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 784, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 788, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 793, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 802, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 811, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 814, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 816, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 826, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 830, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 834, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 844, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 848, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 852, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 856, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 860, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 863, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 867, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 871, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 875, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 882, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 885, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 893, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 900, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 904, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 908, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 917, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 926, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 935, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 944, .adv_w = 128, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 951, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 961, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 965, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 974, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 981, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1001, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1011, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1031, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1041, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1050, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1060, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1070, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1080, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1090, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1100, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1110, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1119, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1129, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1139, .adv_w = 128, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1140, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1150, .adv_w = 128, .box_w = 3, .box_h = 2, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 1151, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1162, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1166, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1177, .adv_w = 128, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1183, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1190, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1197, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1204, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1205, .adv_w = 128, .box_w = 1, .box_h = 16, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 1207, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 1211, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1215, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 1219, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1223, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 1231, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1239, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1247, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1255, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1271, .adv_w = 128, .box_w = 8, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1275, .adv_w = 128, .box_w = 4, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1283, .adv_w = 128, .box_w = 4, .box_h = 10, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 1288, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1294, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1302, .adv_w = 128, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1307, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1313, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1321, .adv_w = 128, .box_w = 4, .box_h = 9, .ofs_x = 4, .ofs_y = 4},
    {.bitmap_index = 1326, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 1332, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 1339, .adv_w = 128, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 1344, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1350, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1357, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 1365, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1377, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1389, .adv_w = 128, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1397, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1409, .adv_w = 128, .box_w = 6, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1421, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1431, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1439, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1449, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1458, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1466, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1475, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1491, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1507, .adv_w = 128, .box_w = 8, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1522, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1538, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1554, .adv_w = 128, .box_w = 9, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1572, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1588, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0}
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
const lv_font_t mono_bold_16 = {
#else
lv_font_t mono_bold_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MONO_BOLD_16*/

