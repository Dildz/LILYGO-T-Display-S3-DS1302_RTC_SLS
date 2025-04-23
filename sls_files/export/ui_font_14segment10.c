/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: --bpp 1 --size 10 --font C:/Users/Dildz/Documents/PlatformIO/LILYGO-T-Display-S3/LILYGO-T-Display-S3-DS1302_RTC_SLS/sls_files/project/assets/DSEG14Classic-Regular.ttf -o C:/Users/Dildz/Documents/PlatformIO/LILYGO-T-Display-S3/LILYGO-T-Display-S3-DS1302_RTC_SLS/sls_files/project/assets\ui_font_14segment10.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_14SEGMENT10
#define UI_FONT_14SEGMENT10 1
#endif

#if UI_FONT_14SEGMENT10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x0,

    /* U+0022 "\"" */
    0x89, 0x99, 0x90,

    /* U+0024 "$" */
    0x7d, 0x22, 0x44, 0x89, 0xd, 0xc4, 0x89, 0x12,
    0xf8,

    /* U+0025 "%" */
    0x83, 0x2c, 0xb4, 0x78, 0x14, 0xd3, 0x4,

    /* U+0026 "&" */
    0xf9, 0x24, 0x94, 0x0, 0x15, 0x53, 0x4f, 0xe0,

    /* U+0027 "'" */
    0xf0,

    /* U+0028 "(" */
    0x68, 0x29,

    /* U+0029 ")" */
    0xa4, 0x1a,

    /* U+002A "*" */
    0xad, 0x5c, 0xed, 0xb1, 0xd5, 0xa8,

    /* U+002B "+" */
    0x21, 0x8, 0x4d, 0x90, 0x84, 0x20,

    /* U+002C "," */
    0x68,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x11, 0x22, 0x4, 0x88,

    /* U+0030 "0" */
    0x7a, 0x38, 0xe5, 0x86, 0x1c, 0x71, 0xc5, 0xe0,

    /* U+0031 "1" */
    0xff,

    /* U+0032 "2" */
    0x78, 0x10, 0x41, 0x5, 0xf8, 0x20, 0x81, 0xe0,

    /* U+0033 "3" */
    0xf8, 0x10, 0x41, 0x7, 0xf0, 0x41, 0x7, 0xe0,

    /* U+0034 "4" */
    0x86, 0x18, 0x61, 0x78, 0x10, 0x41, 0x4,

    /* U+0035 "5" */
    0x7a, 0x8, 0x20, 0x81, 0xf0, 0x41, 0x5, 0xe0,

    /* U+0036 "6" */
    0x7a, 0x8, 0x20, 0x81, 0xf8, 0x61, 0x85, 0xe0,

    /* U+0037 "7" */
    0x7a, 0x18, 0x61, 0x84, 0x10, 0x41, 0x4,

    /* U+0038 "8" */
    0x7a, 0x18, 0x61, 0x85, 0xf8, 0x61, 0x85, 0xe0,

    /* U+0039 "9" */
    0x7a, 0x18, 0x61, 0x85, 0xf0, 0x41, 0x5, 0xe0,

    /* U+003A ":" */
    0xc0, 0xc0,

    /* U+003C "<" */
    0x8, 0x21, 0x4, 0x20, 0x84, 0x10, 0xfc,

    /* U+003D "=" */
    0xfc, 0x0, 0x0, 0x7c,

    /* U+003E ">" */
    0x41, 0x2, 0x8, 0x10, 0x40, 0x82, 0xfc,

    /* U+003F "?" */
    0x7d, 0x6, 0xc, 0x18, 0x21, 0x84, 0x8, 0x10,

    /* U+0040 "@" */
    0x7d, 0x6, 0xc, 0x18, 0x21, 0xe4, 0xc9, 0x92,
    0xf8,

    /* U+0041 "A" */
    0x7a, 0x18, 0x61, 0x85, 0xf8, 0x61, 0x86, 0x10,

    /* U+0042 "B" */
    0xf8, 0x92, 0x49, 0x24, 0x72, 0x49, 0x27, 0xe0,

    /* U+0043 "C" */
    0x7e, 0x8, 0x20, 0x82, 0x8, 0x20, 0x81, 0xf0,

    /* U+0044 "D" */
    0xf8, 0x92, 0x49, 0x24, 0x92, 0x49, 0x27, 0xe0,

    /* U+0045 "E" */
    0x7e, 0x8, 0x20, 0x81, 0xf8, 0x20, 0x81, 0xf0,

    /* U+0046 "F" */
    0x7e, 0x8, 0x20, 0x81, 0xf8, 0x20, 0x82, 0x0,

    /* U+0047 "G" */
    0x7a, 0x8, 0x20, 0x80, 0x78, 0x61, 0x85, 0xe0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0x7a, 0x18, 0x61, 0x84,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x86, 0x18, 0x61, 0x78,

    /* U+004B "K" */
    0x84, 0x23, 0x18, 0x32, 0x11, 0x84, 0x0,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x7c,

    /* U+004D "M" */
    0x87, 0x1c, 0xeb, 0xa6, 0x59, 0x65, 0x96, 0x10,

    /* U+004E "N" */
    0x87, 0x1c, 0x71, 0x86, 0x19, 0x63, 0x8e, 0x10,

    /* U+004F "O" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+0050 "P" */
    0x7a, 0x18, 0x61, 0x85, 0xf8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x7a, 0x18, 0x61, 0x86, 0x19, 0x63, 0x8d, 0xe0,

    /* U+0052 "R" */
    0x7a, 0x18, 0x61, 0x85, 0xe9, 0x22, 0x8a, 0x0,

    /* U+0053 "S" */
    0x7b, 0xc, 0x30, 0x81, 0xe1, 0x43, 0xd, 0xe0,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x20,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x78,

    /* U+0056 "V" */
    0x84, 0x23, 0x18, 0x42, 0x98, 0xc4, 0x0,

    /* U+0057 "W" */
    0x86, 0x59, 0x65, 0x96, 0x1a, 0xfb, 0xc6, 0x10,

    /* U+0058 "X" */
    0x99, 0xa0, 0xa, 0x99,

    /* U+0059 "Y" */
    0x99, 0xa2, 0x4, 0x44,

    /* U+005A "Z" */
    0xfc, 0x20, 0x84, 0x0, 0x2, 0x10, 0x43, 0xf0,

    /* U+005C "\\" */
    0x88, 0x44, 0x2, 0x11,

    /* U+005E "^" */
    0x9b, 0x5a,

    /* U+005F "_" */
    0x7c,

    /* U+0060 "`" */
    0xa4,

    /* U+0061 "a" */
    0x7a, 0x18, 0x61, 0x85, 0xf8, 0x61, 0x86, 0x10,

    /* U+0062 "b" */
    0xf8, 0x92, 0x49, 0x24, 0x72, 0x49, 0x27, 0xe0,

    /* U+0063 "c" */
    0x7e, 0x8, 0x20, 0x82, 0x8, 0x20, 0x81, 0xf0,

    /* U+0064 "d" */
    0xf8, 0x92, 0x49, 0x24, 0x92, 0x49, 0x27, 0xe0,

    /* U+0065 "e" */
    0x7e, 0x8, 0x20, 0x81, 0xf8, 0x20, 0x81, 0xf0,

    /* U+0066 "f" */
    0x7e, 0x8, 0x20, 0x81, 0xf8, 0x20, 0x82, 0x0,

    /* U+0067 "g" */
    0x7a, 0x8, 0x20, 0x80, 0x78, 0x61, 0x85, 0xe0,

    /* U+0068 "h" */
    0x86, 0x18, 0x61, 0x7a, 0x18, 0x61, 0x84,

    /* U+0069 "i" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+006A "j" */
    0x4, 0x10, 0x41, 0x86, 0x18, 0x61, 0x78,

    /* U+006B "k" */
    0x84, 0x23, 0x18, 0x32, 0x11, 0x84, 0x0,

    /* U+006C "l" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x7c,

    /* U+006D "m" */
    0x87, 0x1c, 0xeb, 0xa6, 0x59, 0x65, 0x96, 0x10,

    /* U+006E "n" */
    0x87, 0x1c, 0x71, 0x86, 0x19, 0x63, 0x8e, 0x10,

    /* U+006F "o" */
    0x7a, 0x18, 0x61, 0x86, 0x18, 0x61, 0x85, 0xe0,

    /* U+0070 "p" */
    0x7a, 0x18, 0x61, 0x85, 0xf8, 0x20, 0x82, 0x0,

    /* U+0071 "q" */
    0x7a, 0x18, 0x61, 0x86, 0x19, 0x63, 0x8d, 0xe0,

    /* U+0072 "r" */
    0x7a, 0x18, 0x61, 0x85, 0xe9, 0x22, 0x8a, 0x0,

    /* U+0073 "s" */
    0x7b, 0xc, 0x30, 0x81, 0xe1, 0x43, 0xd, 0xe0,

    /* U+0074 "t" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x20,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x78,

    /* U+0076 "v" */
    0x84, 0x23, 0x18, 0x42, 0x98, 0xc4, 0x0,

    /* U+0077 "w" */
    0x86, 0x59, 0x65, 0x96, 0x1a, 0xfb, 0xc6, 0x10,

    /* U+0078 "x" */
    0x99, 0xa0, 0xa, 0x99,

    /* U+0079 "y" */
    0x99, 0xa2, 0x4, 0x44,

    /* U+007A "z" */
    0xfc, 0x20, 0x84, 0x0, 0x2, 0x10, 0x43, 0xf0,

    /* U+007C "|" */
    0xff,

    /* U+007E "~" */
    0x7b, 0x5d, 0xef, 0xb5, 0xeb, 0xff, 0xd5, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 32, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 131, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 131, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 5, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 21, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 131, .box_w = 1, .box_h = 4, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 30, .adv_w = 131, .box_w = 2, .box_h = 8, .ofs_x = 5, .ofs_y = 1},
    {.bitmap_index = 32, .adv_w = 131, .box_w = 2, .box_h = 8, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 34, .adv_w = 131, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 40, .adv_w = 131, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 131, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 47, .adv_w = 131, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 48, .adv_w = 0, .box_w = 2, .box_h = 1, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 131, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 53, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 131, .box_w = 1, .box_h = 8, .ofs_x = 6, .ofs_y = 1},
    {.bitmap_index = 62, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 108, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 32, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 126, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 131, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 131, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 152, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 131, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 131, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 300, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 131, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 314, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 131, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 336, .adv_w = 131, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 340, .adv_w = 131, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 344, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 131, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 356, .adv_w = 131, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 358, .adv_w = 131, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 131, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 360, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 392, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 408, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 131, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 131, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 131, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 513, .adv_w = 131, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 131, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 131, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 539, .adv_w = 131, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 543, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 131, .box_w = 1, .box_h = 8, .ofs_x = 4, .ofs_y = 1},
    {.bitmap_index = 552, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_3[] = {
    0, 0, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 0,
    30, 0, 31
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 3, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 36, .range_length = 23, .glyph_id_start = 4,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 60, .range_length = 31, .glyph_id_start = 27,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 92, .range_length = 35, .glyph_id_start = 58,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_3, .list_length = 35, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
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
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_14segment10 = {
#else
lv_font_t ui_font_14segment10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_14SEGMENT10*/

