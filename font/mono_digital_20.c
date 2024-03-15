/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MONO_DIGITAL_20
#define MONO_DIGITAL_20 1
#endif

#if MONO_DIGITAL_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfd, 0xc8,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x24, 0x24, 0xdb, 0x24, 0x24, 0xdb, 0x24, 0x24,

    /* U+0024 "$" */
    0x10, 0x23, 0xfc, 0x9, 0x12, 0x24, 0x40, 0xfe,
    0x4, 0x48, 0x91, 0x20, 0x7f, 0x88, 0x10,

    /* U+0025 "%" */
    0xf1, 0x49, 0xa4, 0xde, 0xc0, 0x60, 0x20, 0x0,
    0x20, 0x30, 0x1b, 0xd9, 0x2c, 0x94, 0x78,

    /* U+0026 "&" */
    0x7e, 0x42, 0x42, 0x42, 0x2, 0x7e, 0x82, 0x82,
    0x82, 0x82, 0x80, 0xfe, 0x2, 0x0,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x78, 0x88, 0x88, 0x8, 0x88, 0x88, 0x70,

    /* U+0029 ")" */
    0xe1, 0x11, 0x11, 0x1, 0x11, 0x11, 0xe0,

    /* U+002A "*" */
    0x21, 0x3e, 0xef, 0x90, 0x80,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0xf0,

    /* U+002D "-" */
    0xfe,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x3, 0x3, 0x6, 0x6, 0xc, 0xc, 0x0, 0x10,
    0x30, 0x30, 0x60, 0x60, 0x40,

    /* U+0030 "0" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+0031 "1" */
    0xfd, 0xf8,

    /* U+0032 "2" */
    0xfe, 0x4, 0x8, 0x10, 0x20, 0x7f, 0xc0, 0x81,
    0x2, 0x4, 0xf, 0xc0,

    /* U+0033 "3" */
    0xfe, 0x4, 0x8, 0x10, 0x20, 0x5f, 0x81, 0x2,
    0x4, 0x8, 0x1f, 0xe0,

    /* U+0034 "4" */
    0x3, 0x6, 0xc, 0x18, 0x30, 0x7f, 0x81, 0x2,
    0x4, 0x8, 0x10, 0x20,

    /* U+0035 "5" */
    0xfd, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x81, 0x2,
    0x4, 0x8, 0x1f, 0xe0,

    /* U+0036 "6" */
    0xfd, 0x2, 0x4, 0x8, 0x10, 0x3f, 0xc1, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+0037 "7" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x40, 0x1, 0x2,
    0x4, 0x8, 0x10, 0x0,

    /* U+0038 "8" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+0039 "9" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0x81, 0x2,
    0x4, 0x8, 0x1f, 0xe0,

    /* U+003A ":" */
    0x82,

    /* U+003B ";" */
    0x80, 0xf0,

    /* U+003C "<" */
    0x19, 0x99, 0xe, 0x18, 0x60,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0xc3, 0xc, 0x3, 0x33, 0x0,

    /* U+003F "?" */
    0xfe, 0x4, 0x8, 0x10, 0x20, 0x7f, 0xc0, 0x81,
    0x0, 0x0, 0x8, 0x0,

    /* U+0040 "@" */
    0xff, 0x6, 0xc, 0xf9, 0x32, 0x40, 0x49, 0x93,
    0x3e, 0x4, 0xf, 0xc0,

    /* U+0041 "A" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0042 "B" */
    0xfd, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x1f, 0xc0,

    /* U+0043 "C" */
    0xfe, 0x8, 0x20, 0x82, 0x0, 0x20, 0x82, 0x8,
    0x20, 0xfc,

    /* U+0044 "D" */
    0xfd, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x1f, 0xc0,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0x82, 0xf, 0xe0, 0x82, 0x8,
    0x20, 0xfc,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x82, 0xf, 0xe0, 0x82, 0x8,
    0x20, 0x80,

    /* U+0047 "G" */
    0xfd, 0x2, 0x4, 0x8, 0x10, 0x7, 0xc1, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+0048 "H" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0049 "I" */
    0xfd, 0xf8,

    /* U+004A "J" */
    0x0, 0x4, 0x8, 0x10, 0x20, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+004B "K" */
    0x87, 0x1e, 0x75, 0xcf, 0x1c, 0x3f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+004C "L" */
    0x1, 0x2, 0x4, 0x8, 0x10, 0x0, 0x40, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+004D "M" */
    0xff, 0x26, 0x4c, 0x99, 0x32, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+004E "N" */
    0x83, 0xc6, 0xcc, 0xd8, 0xf0, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x10, 0x0,

    /* U+004F "O" */
    0x7d, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x17, 0xc0,

    /* U+0050 "P" */
    0xfd, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc0, 0x81,
    0x2, 0x4, 0x8, 0x0,

    /* U+0051 "Q" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0x83,
    0x6, 0x3c, 0x6f, 0xa0,

    /* U+0052 "R" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xf0, 0xf1,
    0x72, 0x74, 0x78, 0x60,

    /* U+0053 "S" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x81, 0x2,
    0x4, 0x8, 0x1f, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40, 0x81, 0x0,

    /* U+0055 "U" */
    0x1, 0x6, 0xc, 0x18, 0x30, 0x60, 0x41, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+0056 "V" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0xc6,
    0x88, 0xa1, 0x40, 0x0,

    /* U+0057 "W" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x44, 0x49, 0x93,
    0x26, 0x4c, 0x1f, 0xe0,

    /* U+0058 "X" */
    0x43, 0x63, 0x66, 0x36, 0x3c, 0x1c, 0x0, 0x1c,
    0x3c, 0x36, 0x66, 0x63, 0x43,

    /* U+0059 "Y" */
    0x3, 0x6, 0xc, 0x18, 0x30, 0x7f, 0x81, 0x2,
    0x4, 0x8, 0x1f, 0xe0,

    /* U+005A "Z" */
    0xfa, 0x2, 0x6, 0x4, 0xc, 0x8, 0x0, 0x10,
    0x30, 0x20, 0x60, 0x40, 0xfe,

    /* U+005B "[" */
    0xf2, 0x49, 0x4, 0x92, 0x4e,

    /* U+005C "\\" */
    0x40, 0x60, 0x60, 0x30, 0x30, 0x10, 0x0, 0xc,
    0xc, 0x6, 0x6, 0x3, 0x3,

    /* U+005D "]" */
    0xe4, 0x92, 0x41, 0x24, 0x9e,

    /* U+005E "^" */
    0x18, 0x3c, 0x66, 0xc3, 0x81,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x98, 0x80,

    /* U+0061 "a" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0062 "b" */
    0xfd, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x1f, 0xc0,

    /* U+0063 "c" */
    0xfe, 0x8, 0x20, 0x82, 0x0, 0x20, 0x82, 0x8,
    0x20, 0xfc,

    /* U+0064 "d" */
    0xfd, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x1f, 0xc0,

    /* U+0065 "e" */
    0xfe, 0x8, 0x20, 0x82, 0xf, 0xe0, 0x82, 0x8,
    0x20, 0xfc,

    /* U+0066 "f" */
    0xfe, 0x8, 0x20, 0x82, 0xf, 0xe0, 0x82, 0x8,
    0x20, 0x80,

    /* U+0067 "g" */
    0xfd, 0x2, 0x4, 0x8, 0x10, 0x7, 0xc1, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+0068 "h" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0069 "i" */
    0xfd, 0xf8,

    /* U+006A "j" */
    0x0, 0x4, 0x8, 0x10, 0x20, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+006B "k" */
    0x87, 0x1e, 0x75, 0xcf, 0x1c, 0x3f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+006C "l" */
    0x1, 0x2, 0x4, 0x8, 0x10, 0x0, 0x40, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+006D "m" */
    0xff, 0x26, 0x4c, 0x99, 0x32, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+006E "n" */
    0x83, 0xc6, 0xcc, 0xd8, 0xf0, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x10, 0x0,

    /* U+006F "o" */
    0x7d, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0x83,
    0x6, 0xc, 0x17, 0xc0,

    /* U+0070 "p" */
    0xfd, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc0, 0x81,
    0x2, 0x4, 0x8, 0x0,

    /* U+0071 "q" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0x83,
    0x6, 0x3c, 0x6f, 0xa0,

    /* U+0072 "r" */
    0xff, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xf0, 0xf1,
    0x72, 0x74, 0x78, 0x60,

    /* U+0073 "s" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x81, 0x2,
    0x4, 0x8, 0x1f, 0xe0,

    /* U+0074 "t" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40, 0x81, 0x0,

    /* U+0075 "u" */
    0x1, 0x6, 0xc, 0x18, 0x30, 0x60, 0x41, 0x83,
    0x6, 0xc, 0x1f, 0xe0,

    /* U+0076 "v" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x40, 0x41, 0xc6,
    0x88, 0xa1, 0x40, 0x0,

    /* U+0077 "w" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x44, 0x49, 0x93,
    0x26, 0x4c, 0x1f, 0xe0,

    /* U+0078 "x" */
    0x43, 0x63, 0x66, 0x36, 0x3c, 0x1c, 0x0, 0x1c,
    0x3c, 0x36, 0x66, 0x63, 0x43,

    /* U+0079 "y" */
    0x3, 0x6, 0xc, 0x18, 0x30, 0x7f, 0x81, 0x2,
    0x4, 0x8, 0x1f, 0xe0,

    /* U+007A "z" */
    0xfa, 0x2, 0x6, 0x4, 0xc, 0x8, 0x0, 0x10,
    0x30, 0x20, 0x60, 0x40, 0xfe,

    /* U+007B "{" */
    0x39, 0x8, 0x42, 0x13, 0x4, 0x21, 0x8, 0x43,
    0x80,

    /* U+007C "|" */
    0xff, 0xf8,

    /* U+007D "}" */
    0xe1, 0x8, 0x42, 0x10, 0x64, 0x21, 0x8, 0x4e,
    0x0,

    /* U+007E "~" */
    0x60, 0x0, 0x92, 0xc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 145, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 145, .box_w = 1, .box_h = 13, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 145, .box_w = 4, .box_h = 4, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 5, .adv_w = 145, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 13, .adv_w = 145, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 28, .adv_w = 145, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 145, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 57, .adv_w = 145, .box_w = 1, .box_h = 4, .ofs_x = 4, .ofs_y = 9},
    {.bitmap_index = 58, .adv_w = 145, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 145, .box_w = 4, .box_h = 13, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 145, .box_w = 5, .box_h = 7, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 77, .adv_w = 145, .box_w = 5, .box_h = 5, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 81, .adv_w = 145, .box_w = 1, .box_h = 4, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 82, .adv_w = 145, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 83, .adv_w = 145, .box_w = 1, .box_h = 1, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 145, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 145, .box_w = 1, .box_h = 13, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 145, .box_w = 1, .box_h = 7, .ofs_x = 4, .ofs_y = 3},
    {.bitmap_index = 208, .adv_w = 145, .box_w = 1, .box_h = 12, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 210, .adv_w = 145, .box_w = 5, .box_h = 7, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 215, .adv_w = 145, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 219, .adv_w = 145, .box_w = 5, .box_h = 7, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 224, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 236, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 145, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 145, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 304, .adv_w = 145, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 145, .box_w = 1, .box_h = 13, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 448, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 145, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 145, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 145, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 145, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 145, .box_w = 3, .box_h = 13, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 145, .box_w = 8, .box_h = 5, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 574, .adv_w = 145, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 145, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = 10},
    {.bitmap_index = 577, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 145, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 623, .adv_w = 145, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 145, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 655, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 145, .box_w = 1, .box_h = 13, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 705, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 729, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 741, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 753, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 765, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 789, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 837, .adv_w = 145, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 850, .adv_w = 145, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 862, .adv_w = 145, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 875, .adv_w = 145, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 884, .adv_w = 145, .box_w = 1, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 886, .adv_w = 145, .box_w = 5, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 895, .adv_w = 145, .box_w = 8, .box_h = 4, .ofs_x = 1, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
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
    .cmap_num = 1,
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
const lv_font_t mono_digital_20 = {
#else
lv_font_t mono_digital_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MONO_DIGITAL_20*/

