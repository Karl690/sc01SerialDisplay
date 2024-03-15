/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MONO_REGUALR_12
#define MONO_REGUALR_12 1
#endif

#if MONO_REGUALR_12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf9,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x28, 0xaf, 0xd2, 0x53, 0xf5, 0x14,

    /* U+0024 "$" */
    0x21, 0x1d, 0x8, 0x30, 0x42, 0xf1, 0x8,

    /* U+0025 "%" */
    0xe6, 0xab, 0x3c, 0x3c, 0xd5, 0x67,

    /* U+0026 "&" */
    0x72, 0x94, 0xc6, 0xce, 0x4d,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x2d, 0x49, 0x24, 0x48, 0x80,

    /* U+0029 ")" */
    0x99, 0x12, 0x49, 0x4a, 0x0,

    /* U+002A "*" */
    0x25, 0x5c, 0xa5, 0x0,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0x6d, 0x80,

    /* U+002D "-" */
    0xc0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x11, 0x22, 0x26, 0x44, 0x48, 0x80,

    /* U+0030 "0" */
    0x76, 0xe3, 0x58, 0xc7, 0x6e,

    /* U+0031 "1" */
    0x2e, 0x22, 0x22, 0x2f,

    /* U+0032 "2" */
    0xe9, 0x11, 0x24, 0x8f,

    /* U+0033 "3" */
    0xe1, 0x16, 0x11, 0x1e,

    /* U+0034 "4" */
    0x11, 0x95, 0x29, 0x7c, 0x42,

    /* U+0035 "5" */
    0x7a, 0x10, 0xe0, 0x84, 0x3e,

    /* U+0036 "6" */
    0x3a, 0x21, 0xe8, 0xc6, 0x2e,

    /* U+0037 "7" */
    0xf8, 0x84, 0x42, 0x21, 0x8,

    /* U+0038 "8" */
    0x74, 0x62, 0xa7, 0xc6, 0x2e,

    /* U+0039 "9" */
    0x74, 0xe3, 0x17, 0x84, 0x5c,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0x6c, 0x6, 0xd8,

    /* U+003C "<" */
    0x9, 0xb0, 0xc1, 0x80,

    /* U+003D "=" */
    0xf0, 0xf0,

    /* U+003E ">" */
    0x83, 0x6, 0x6c, 0x0,

    /* U+003F "?" */
    0xe1, 0x12, 0x44, 0x4,

    /* U+0040 "@" */
    0x72, 0x63, 0x3a, 0xd6, 0xb3, 0x41, 0x80,

    /* U+0041 "A" */
    0x30, 0xc3, 0x12, 0x49, 0xe8, 0x61,

    /* U+0042 "B" */
    0xe4, 0xa5, 0xc9, 0xc6, 0x3e,

    /* U+0043 "C" */
    0x7a, 0x21, 0x8, 0x41, 0xf,

    /* U+0044 "D" */
    0xf4, 0xa3, 0x18, 0xc6, 0x5e,

    /* U+0045 "E" */
    0xf8, 0x8f, 0x88, 0x8f,

    /* U+0046 "F" */
    0xf8, 0x8f, 0x88, 0x88,

    /* U+0047 "G" */
    0x7a, 0x21, 0x8, 0xc5, 0x2f,

    /* U+0048 "H" */
    0x8c, 0x63, 0xf8, 0xc6, 0x31,

    /* U+0049 "I" */
    0xe9, 0x24, 0x97,

    /* U+004A "J" */
    0xf1, 0x11, 0x11, 0x1e,

    /* U+004B "K" */
    0x9c, 0xa9, 0x8e, 0x5a, 0x51,

    /* U+004C "L" */
    0x88, 0x88, 0x88, 0x8f,

    /* U+004D "M" */
    0xde, 0xf7, 0xda, 0xc6, 0x31,

    /* U+004E "N" */
    0x8e, 0x73, 0x5a, 0xce, 0x71,

    /* U+004F "O" */
    0x76, 0xe3, 0x18, 0xc6, 0x6e,

    /* U+0050 "P" */
    0xf4, 0x63, 0x1f, 0x42, 0x10,

    /* U+0051 "Q" */
    0x76, 0xe3, 0x18, 0xc6, 0x2e, 0x20, 0xc0,

    /* U+0052 "R" */
    0xf4, 0x63, 0x1f, 0x4a, 0x31,

    /* U+0053 "S" */
    0x7c, 0x20, 0x83, 0x4, 0x3e,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84,

    /* U+0055 "U" */
    0x8c, 0x63, 0x18, 0xc6, 0x2e,

    /* U+0056 "V" */
    0x85, 0x34, 0x92, 0x48, 0xc3, 0xc,

    /* U+0057 "W" */
    0x8c, 0x63, 0x5e, 0xef, 0x7b,

    /* U+0058 "X" */
    0x49, 0x23, 0xc, 0x31, 0x24, 0xb2,

    /* U+0059 "Y" */
    0x8c, 0x54, 0xa2, 0x10, 0x84,

    /* U+005A "Z" */
    0xf8, 0x8c, 0x44, 0x22, 0x1f,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x93, 0x80,

    /* U+005C "\\" */
    0x88, 0x44, 0x46, 0x22, 0x21, 0x10,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x27, 0x80,

    /* U+005E "^" */
    0x30, 0xc4, 0x92,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0x70, 0x5f, 0x18, 0xbc,

    /* U+0062 "b" */
    0x84, 0x21, 0xe8, 0xc6, 0x33, 0xf0,

    /* U+0063 "c" */
    0x7e, 0x21, 0xc, 0x3c,

    /* U+0064 "d" */
    0x8, 0x42, 0xfc, 0xc6, 0x39, 0x78,

    /* U+0065 "e" */
    0x74, 0x7f, 0xc, 0x3c,

    /* U+0066 "f" */
    0x3a, 0x11, 0xe4, 0x21, 0x8, 0x40,

    /* U+0067 "g" */
    0x7e, 0x63, 0x18, 0xbc, 0x3e,

    /* U+0068 "h" */
    0x88, 0x8e, 0x99, 0x99, 0x90,

    /* U+0069 "i" */
    0x60, 0x1, 0xc2, 0x10, 0x84, 0x38,

    /* U+006A "j" */
    0x30, 0xf, 0x11, 0x11, 0x11, 0xe0,

    /* U+006B "k" */
    0x84, 0x21, 0x2a, 0x63, 0x92, 0x98,

    /* U+006C "l" */
    0xe1, 0x8, 0x42, 0x10, 0x84, 0x18,

    /* U+006D "m" */
    0xdd, 0x6b, 0x58, 0xc4,

    /* U+006E "n" */
    0xe9, 0x99, 0x99,

    /* U+006F "o" */
    0x74, 0x63, 0x18, 0xb8,

    /* U+0070 "p" */
    0xf4, 0xe3, 0x18, 0xfa, 0x10,

    /* U+0071 "q" */
    0x7e, 0x63, 0x1c, 0xbc, 0x21,

    /* U+0072 "r" */
    0xf8, 0x88, 0x88,

    /* U+0073 "s" */
    0xf8, 0xc3, 0x1f,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x43,

    /* U+0075 "u" */
    0x99, 0x99, 0x97,

    /* U+0076 "v" */
    0xcd, 0x24, 0x94, 0x30, 0xc0,

    /* U+0077 "w" */
    0x86, 0x1b, 0x9e, 0x49, 0x20,

    /* U+0078 "x" */
    0x49, 0xe3, 0xc, 0x49, 0x20,

    /* U+0079 "y" */
    0x49, 0x24, 0x8a, 0x30, 0x42, 0x38,

    /* U+007A "z" */
    0xf3, 0x24, 0x8f,

    /* U+007B "{" */
    0x74, 0x44, 0x48, 0x44, 0x44, 0x70,

    /* U+007C "|" */
    0xff, 0xe0,

    /* U+007D "}" */
    0xe2, 0x22, 0x21, 0x22, 0x22, 0xe0,

    /* U+007E "~" */
    0x66, 0x60,

    /* U+00A9 "©" */
    0x77, 0x73, 0x9e, 0xb8,

    /* U+2013 "–" */
    0xf0,

    /* U+2014 "—" */
    0xfc,

    /* U+2015 "―" */
    0xfc,

    /* U+2018 "‘" */
    0x1b, 0x60,

    /* U+2019 "’" */
    0x6d, 0x80,

    /* U+201A "‚" */
    0x6d, 0x80,

    /* U+201C "“" */
    0xdc, 0xa4,

    /* U+201D "”" */
    0x4a, 0x44,

    /* U+201E "„" */
    0x4a, 0x76,

    /* U+2020 "†" */
    0x21, 0x3e, 0x42, 0x10, 0x84, 0x20,

    /* U+2021 "‡" */
    0x21, 0x3e, 0x42, 0x7c, 0x84, 0x20,

    /* U+2022 "•" */
    0xff, 0x80,

    /* U+2026 "…" */
    0xfc,

    /* U+2030 "‰" */
    0xc3, 0x1d, 0xb8, 0xed, 0xb6, 0xdb,

    /* U+2039 "‹" */
    0x5a, 0x40,

    /* U+203A "›" */
    0xa5, 0x80,

    /* U+2044 "⁄" */
    0x8, 0x21, 0x4, 0x20, 0x84, 0x20,

    /* U+2070 "⁰" */
    0x56, 0xd4,

    /* U+2074 "⁴" */
    0x26, 0xaf, 0x20,

    /* U+2075 "⁵" */
    0xd3, 0x1c,

    /* U+2076 "⁶" */
    0x7b, 0xd6,

    /* U+2077 "⁷" */
    0xe9, 0x48,

    /* U+2078 "⁸" */
    0xf7, 0x5e,

    /* U+2079 "⁹" */
    0xf6, 0xfc,

    /* U+2080 "₀" */
    0xf6, 0xf0,

    /* U+2081 "₁" */
    0xc9, 0x70,

    /* U+2082 "₂" */
    0xe5, 0x70,

    /* U+2083 "₃" */
    0xec, 0xf0,

    /* U+2084 "₄" */
    0x6a, 0xf2,

    /* U+2085 "₅" */
    0xd1, 0x60,

    /* U+2086 "₆" */
    0x7e, 0xf0,

    /* U+2087 "₇" */
    0xeb, 0x40,

    /* U+2088 "₈" */
    0xf7, 0xf0,

    /* U+2089 "₉" */
    0xf7, 0xe0,

    /* U+20AC "€" */
    0x3a, 0x3c, 0x8f, 0x21, 0x87,

    /* U+20AE "₮" */
    0xf9, 0xc, 0xc2, 0x19, 0x84,

    /* U+20B4 "₴" */
    0xf1, 0xf6, 0xf8, 0x87,

    /* U+20B9 "₹" */
    0xf7, 0x8d, 0xcc, 0x20, 0x80,

    /* U+2113 "ℓ" */
    0x75, 0x55, 0x64, 0xc7,

    /* U+2116 "№" */
    0xaa, 0xef, 0xba, 0xe2, 0xaa, 0x0,

    /* U+2122 "™" */
    0xf5, 0x75, 0x40,

    /* U+2126 "Ω" */
    0x72, 0xa3, 0x18, 0xc5, 0x5b,

    /* U+212E "℮" */
    0x74, 0x7f, 0x8, 0x38,

    /* U+2153 "⅓" */
    0xc9, 0x45, 0x8, 0x21, 0x64, 0xa6,

    /* U+2154 "⅔" */
    0xca, 0xb4, 0x42, 0x2d, 0x73,

    /* U+2155 "⅕" */
    0x4b, 0x25, 0x8, 0x21, 0x24, 0xa6,

    /* U+2156 "⅖" */
    0xca, 0xb4, 0x42, 0x2d, 0x53,

    /* U+2157 "⅗" */
    0xce, 0xb4, 0x42, 0x2e, 0x53,

    /* U+2158 "⅘" */
    0x66, 0xae, 0x8c, 0x10, 0xb4, 0x93,

    /* U+2159 "⅙" */
    0x4e, 0x94, 0x43, 0xaa, 0x73,

    /* U+215A "⅚" */
    0xcc, 0xb4, 0x45, 0x32, 0xd6,

    /* U+215B "⅛" */
    0xc9, 0x25, 0x8, 0x39, 0x55, 0xe6,

    /* U+215C "⅜" */
    0xc9, 0x2d, 0x4, 0x39, 0x65, 0x66,

    /* U+215D "⅝" */
    0xcc, 0xb4, 0x45, 0xb6, 0xf3,

    /* U+215E "⅞" */
    0x69, 0x25, 0x4, 0x39, 0x65, 0x66,

    /* U+2202 "∂" */
    0x70, 0xc2, 0xf8, 0xc6, 0x4e,

    /* U+2206 "∆" */
    0x30, 0xc3, 0x12, 0x49, 0x28, 0x7f,

    /* U+220F "∏" */
    0xfc, 0x63, 0x18, 0xc6, 0x31, 0x88,

    /* U+2211 "∑" */
    0xfe, 0x10, 0x42, 0x11, 0x10, 0xf8,

    /* U+2212 "−" */
    0xf8,

    /* U+2215 "∕" */
    0x8, 0x21, 0x8, 0x21, 0x8, 0x0,

    /* U+2219 "∙" */
    0xf0,

    /* U+221A "√" */
    0x4, 0x20, 0x82, 0xd0, 0xc3, 0xc,

    /* U+221E "∞" */
    0x7e, 0xdb, 0x5f,

    /* U+222B "∫" */
    0x19, 0x8, 0x42, 0x10, 0x84, 0x26, 0x0,

    /* U+2248 "≈" */
    0x66, 0x66, 0x26,

    /* U+2260 "≠" */
    0x10, 0xbe, 0x4f, 0xa0,

    /* U+2264 "≤" */
    0x1f, 0x30, 0x70, 0x7c,

    /* U+2265 "≥" */
    0xc1, 0xc7, 0xc0, 0x7c,

    /* U+2500 "─" */
    0xfc,

    /* U+2502 "│" */
    0xff, 0xf0,

    /* U+250C "┌" */
    0xf8, 0x88, 0x88, 0x80,

    /* U+2510 "┐" */
    0xf1, 0x11, 0x11, 0x10,

    /* U+2514 "└" */
    0x88, 0x88, 0x88, 0xf0,

    /* U+2518 "┘" */
    0x11, 0x11, 0x11, 0xf0,

    /* U+251C "├" */
    0x88, 0x88, 0x88, 0xe8, 0x88, 0x88,

    /* U+2524 "┤" */
    0x11, 0x11, 0x11, 0x71, 0x11, 0x11,

    /* U+252C "┬" */
    0xfc, 0x82, 0x8, 0x20, 0x80, 0x0,

    /* U+2534 "┴" */
    0x0, 0x82, 0x8, 0x20, 0x8f, 0xc0,

    /* U+253C "┼" */
    0x20, 0x82, 0x8, 0x20, 0x8f, 0xc8, 0x20, 0x82,
    0x8,

    /* U+2550 "═" */
    0xfc, 0xf, 0xc0,

    /* U+2551 "║" */
    0xb6, 0xdb, 0x6d, 0xb6, 0xd0,

    /* U+2552 "╒" */
    0xf0, 0xf8, 0x88, 0x88,

    /* U+2553 "╓" */
    0xba, 0xaa, 0xaa,

    /* U+2554 "╔" */
    0xf8, 0xba, 0xaa, 0xaa,

    /* U+2555 "╕" */
    0xf0, 0xf1, 0x11, 0x11,

    /* U+2556 "╖" */
    0xe9, 0x4a, 0x52, 0x94,

    /* U+2557 "╗" */
    0xf8, 0x7a, 0x52, 0x94, 0xa5,

    /* U+2558 "╘" */
    0x88, 0x88, 0xf0, 0xf0,

    /* U+2559 "╙" */
    0xaa, 0xaa, 0xaa, 0xb0,

    /* U+255A "╚" */
    0xaa, 0xaa, 0xb8, 0xf0,

    /* U+255B "╛" */
    0x11, 0x11, 0xf0, 0xf0,

    /* U+255C "╜" */
    0x29, 0x4a, 0x52, 0x97, 0xa0,

    /* U+255D "╝" */
    0x29, 0x4a, 0x5e, 0x87, 0xe0,

    /* U+255E "╞" */
    0x88, 0x88, 0xf0, 0xf8, 0x88, 0x88,

    /* U+255F "╟" */
    0xaa, 0xaa, 0xaa, 0xba, 0xaa, 0xaa,

    /* U+2560 "╠" */
    0xaa, 0xaa, 0xab, 0xba, 0xaa, 0xaa,

    /* U+2561 "╡" */
    0x11, 0x11, 0xf0, 0xf1, 0x11, 0x11,

    /* U+2562 "╢" */
    0x29, 0x4a, 0x52, 0x95, 0xa5, 0x29, 0x4a, 0x50,

    /* U+2563 "╣" */
    0x29, 0x4a, 0x52, 0xf7, 0xa5, 0x29, 0x4a, 0x50,

    /* U+2564 "╤" */
    0xfc, 0xf, 0xc8, 0x20, 0x82, 0x0,

    /* U+2565 "╥" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0x0,

    /* U+2566 "╦" */
    0xfc, 0xf, 0xcc, 0x30, 0xc3, 0xc,

    /* U+2567 "╧" */
    0x0, 0x82, 0x8, 0xfc, 0xf, 0xc0,

    /* U+2568 "╨" */
    0x30, 0xc3, 0xc, 0x30, 0xcf, 0xc0,

    /* U+2569 "╩" */
    0x30, 0xc3, 0xc, 0xfc, 0xf, 0xc0,

    /* U+256A "╪" */
    0x20, 0x82, 0x8, 0x23, 0xff, 0xc8, 0x20, 0x82,
    0x8,

    /* U+256B "╫" */
    0x30, 0xc3, 0xc, 0x30, 0xcf, 0xcc, 0x30, 0xc3,
    0xc,

    /* U+256C "╬" */
    0x28, 0xa2, 0x8a, 0xec, 0xe, 0xca, 0x28, 0xa2,
    0x8a,

    /* U+2588 "█" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff,

    /* U+2591 "░" */
    0xaa, 0xaa, 0xaa, 0xaa, 0xa0, 0x15, 0x55, 0x55,
    0x55, 0x55, 0x50,

    /* U+2592 "▒" */
    0xc1, 0xfc, 0x1f, 0xc0, 0x7, 0xf0, 0x7f, 0x7,
    0xf0,

    /* U+2593 "▓" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0,

    /* U+25CA "◊" */
    0x0, 0xc3, 0x12, 0x49, 0x23, 0x8
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 96, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 96, .box_w = 1, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 4, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 17, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 96, .box_w = 1, .box_h = 3, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 29, .adv_w = 96, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 34, .adv_w = 96, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 39, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 43, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 47, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 49, .adv_w = 96, .box_w = 2, .box_h = 1, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 50, .adv_w = 96, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 96, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 57, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 96, .box_w = 2, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 96, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 109, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 113, .adv_w = 96, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 115, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 119, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 130, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 96, .box_w = 3, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 212, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 96, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 264, .adv_w = 96, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 270, .adv_w = 96, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 275, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 278, .adv_w = 96, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 279, .adv_w = 96, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 280, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 300, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 304, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 315, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 96, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 332, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 360, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 365, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 399, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 96, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 408, .adv_w = 96, .box_w = 1, .box_h = 11, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 410, .adv_w = 96, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 416, .adv_w = 96, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 418, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 96, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 423, .adv_w = 96, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 424, .adv_w = 96, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 425, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 427, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 429, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 431, .adv_w = 96, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 433, .adv_w = 96, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 435, .adv_w = 96, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 437, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 443, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 449, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 451, .adv_w = 96, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 96, .box_w = 2, .box_h = 5, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 460, .adv_w = 96, .box_w = 2, .box_h = 5, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 462, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 96, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 470, .adv_w = 96, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 473, .adv_w = 96, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 475, .adv_w = 96, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 477, .adv_w = 96, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 479, .adv_w = 96, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 481, .adv_w = 96, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 483, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 96, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 495, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 96, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 526, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 96, .box_w = 6, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 535, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 544, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 587, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 599, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 627, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 633, .adv_w = 96, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 634, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 96, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 641, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 647, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 650, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 657, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 660, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 664, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 96, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 673, .adv_w = 96, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 675, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 679, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 683, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 687, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 691, .adv_w = 96, .box_w = 4, .box_h = 12, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 697, .adv_w = 96, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 703, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 709, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 715, .adv_w = 96, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 724, .adv_w = 96, .box_w = 6, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 727, .adv_w = 96, .box_w = 3, .box_h = 12, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 732, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 736, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 739, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 743, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 747, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 751, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 756, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 760, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 764, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 768, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 772, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 777, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 782, .adv_w = 96, .box_w = 4, .box_h = 12, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 788, .adv_w = 96, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 794, .adv_w = 96, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 800, .adv_w = 96, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 806, .adv_w = 96, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 814, .adv_w = 96, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 822, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 828, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 834, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 840, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 846, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 852, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 858, .adv_w = 96, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 867, .adv_w = 96, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 876, .adv_w = 96, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 885, .adv_w = 96, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 894, .adv_w = 96, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 905, .adv_w = 96, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 914, .adv_w = 96, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 926, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0}
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
const lv_font_t mono_regualr_12 = {
#else
lv_font_t mono_regualr_12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MONO_REGUALR_12*/

