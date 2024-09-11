#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

extern uint64_t _kernel_start;
extern uint64_t _kernel_end;

static const uint8_t letters[256][8] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0000 (uni0000.dup1)
    {0x7e, 0x81, 0xa5, 0x81, 0xbd, 0x99, 0x81, 0x7e},  // 0001 (uni0001)
    {0x7e, 0xff, 0xdb, 0xff, 0xc3, 0xe7, 0xff, 0x7e},  // 0002 (uni0002)
    {0x6c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x00},  // 0003 (uni0003)
    {0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x10, 0x00},  // 0004 (uni0004)
    {0x38, 0x7c, 0x38, 0xfe, 0xfe, 0x7c, 0x38, 0x7c},  // 0005 (uni0005)
    {0x10, 0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x7c},  // 0006 (uni0006)
    {0x00, 0x00, 0x18, 0x3c, 0x3c, 0x18, 0x00, 0x00},  // 0007 (uni0007)
    {0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xe7, 0xff, 0xff},  // 0008 (uni0008)
    {0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x00},  // 0009 (uni0009)
    {0xff, 0xc3, 0x99, 0xbd, 0xbd, 0x99, 0xc3, 0xff},  // 000a (uni000A)
    {0x0f, 0x07, 0x0f, 0x7d, 0xcc, 0xcc, 0xcc, 0x78},  // 000b (uni000B)
    {0x3c, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x7e, 0x18},  // 000c (uni000C)
    {0x3f, 0x33, 0x3f, 0x30, 0x30, 0x70, 0xf0, 0xe0},  // 000d (uni000D)
    {0x7f, 0x63, 0x7f, 0x63, 0x63, 0x67, 0xe6, 0xc0},  // 000e (uni000E)
    {0x99, 0x5a, 0x3c, 0xe7, 0xe7, 0x3c, 0x5a, 0x99},  // 000f (uni000F)
    {0x80, 0xe0, 0xf8, 0xfe, 0xf8, 0xe0, 0x80, 0x00},  // 0010 (uni0010)
    {0x02, 0x0e, 0x3e, 0xfe, 0x3e, 0x0e, 0x02, 0x00},  // 0011 (uni0011)
    {0x18, 0x3c, 0x7e, 0x18, 0x18, 0x7e, 0x3c, 0x18},  // 0012 (uni0012)
    {0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00},  // 0013 (uni0013)
    {0x7f, 0xdb, 0xdb, 0x7b, 0x1b, 0x1b, 0x1b, 0x00},  // 0014 (uni0014)
    {0x3e, 0x63, 0x38, 0x6c, 0x6c, 0x38, 0xcc, 0x78},  // 0015 (uni0015)
    {0x00, 0x00, 0x00, 0x00, 0x7e, 0x7e, 0x7e, 0x00},  // 0016 (uni0016)
    {0x18, 0x3c, 0x7e, 0x18, 0x7e, 0x3c, 0x18, 0xff},  // 0017 (uni0017)
    {0x18, 0x3c, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x00},  // 0018 (uni0018)
    {0x18, 0x18, 0x18, 0x18, 0x7e, 0x3c, 0x18, 0x00},  // 0019 (uni0019)
    {0x00, 0x18, 0x0c, 0xfe, 0x0c, 0x18, 0x00, 0x00},  // 001a (uni001A)
    {0x00, 0x30, 0x60, 0xfe, 0x60, 0x30, 0x00, 0x00},  // 001b (uni001B)
    {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xfe, 0x00, 0x00},  // 001c (uni001C)
    {0x00, 0x24, 0x66, 0xff, 0x66, 0x24, 0x00, 0x00},  // 001d (uni001D)
    {0x00, 0x18, 0x3c, 0x7e, 0xff, 0xff, 0x00, 0x00},  // 001e (uni001E)
    {0x00, 0xff, 0xff, 0x7e, 0x3c, 0x18, 0x00, 0x00},  // 001f (uni001F)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0020 (space)
    {0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00},  // 0021 (exclam)
    {0x6c, 0x6c, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0022 (quotedbl)
    {0x6c, 0x6c, 0xfe, 0x6c, 0xfe, 0x6c, 0x6c, 0x00},  // 0023 (numbersign)
    {0x30, 0x7c, 0xc0, 0x78, 0x0c, 0xf8, 0x30, 0x00},  // 0024 (dollar)
    {0x00, 0xc6, 0xcc, 0x18, 0x30, 0x66, 0xc6, 0x00},  // 0025 (percent)
    {0x38, 0x6c, 0x38, 0x76, 0xdc, 0xcc, 0x76, 0x00},  // 0026 (ampersand)
    {0x60, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0027 (quotesingle)
    {0x18, 0x30, 0x60, 0x60, 0x60, 0x30, 0x18, 0x00},  // 0028 (parenleft)
    {0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00},  // 0029 (parenright)
    {0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00},  // 002a (asterisk)
    {0x00, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x00, 0x00},  // 002b (plus)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60},  // 002c (comma)
    {0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00},  // 002d (hyphen)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00},  // 002e (period)
    {0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00},  // 002f (slash)
    {0x7c, 0xc6, 0xce, 0xde, 0xf6, 0xe6, 0x7c, 0x00},  // 0030 (zero)
    {0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x00},  // 0031 (one)
    {0x78, 0xcc, 0x0c, 0x38, 0x60, 0xc4, 0xfc, 0x00},  // 0032 (two)
    {0x78, 0xcc, 0x0c, 0x38, 0x0c, 0xcc, 0x78, 0x00},  // 0033 (three)
    {0x1c, 0x3c, 0x6c, 0xcc, 0xfe, 0x0c, 0x1e, 0x00},  // 0034 (four)
    {0xfc, 0xc0, 0xf8, 0x0c, 0x0c, 0xcc, 0x78, 0x00},  // 0035 (five)
    {0x38, 0x60, 0xc0, 0xf8, 0xcc, 0xcc, 0x78, 0x00},  // 0036 (six)
    {0xfc, 0xcc, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x00},  // 0037 (seven)
    {0x78, 0xcc, 0xcc, 0x78, 0xcc, 0xcc, 0x78, 0x00},  // 0038 (eight)
    {0x78, 0xcc, 0xcc, 0x7c, 0x0c, 0x18, 0x70, 0x00},  // 0039 (nine)
    {0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00},  // 003a (colon)
    {0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x60, 0x00},  // 003b (semicolon)
    {0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x00},  // 003c (less)
    {0x00, 0x00, 0xfc, 0x00, 0x00, 0xfc, 0x00, 0x00},  // 003d (equal)
    {0x60, 0x30, 0x18, 0x0c, 0x18, 0x30, 0x60, 0x00},  // 003e (greater)
    {0x78, 0xcc, 0x0c, 0x18, 0x30, 0x00, 0x30, 0x00},  // 003f (question)
    {0x7c, 0xc6, 0xde, 0xde, 0xde, 0xc0, 0x78, 0x00},  // 0040 (at)
    {0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00},  // 0041 (A)
    {0xfc, 0x66, 0x66, 0x7c, 0x66, 0x66, 0xfc, 0x00},  // 0042 (B)
    {0x3c, 0x66, 0xc0, 0xc0, 0xc0, 0x66, 0x3c, 0x00},  // 0043 (C)
    {0xf8, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0xf8, 0x00},  // 0044 (D)
    {0xfe, 0x62, 0x68, 0x78, 0x68, 0x62, 0xfe, 0x00},  // 0045 (E)
    {0xfe, 0x62, 0x68, 0x78, 0x68, 0x60, 0xf0, 0x00},  // 0046 (F)
    {0x3c, 0x66, 0xc0, 0xc0, 0xce, 0x66, 0x3e, 0x00},  // 0047 (G)
    {0xcc, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0xcc, 0x00},  // 0048 (H)
    {0x78, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00},  // 0049 (I)
    {0x1e, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78, 0x00},  // 004a (J)
    {0xe6, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00},  // 004b (K)
    {0xf0, 0x60, 0x60, 0x60, 0x62, 0x66, 0xfe, 0x00},  // 004c (L)
    {0xc6, 0xee, 0xfe, 0xfe, 0xd6, 0xc6, 0xc6, 0x00},  // 004d (M)
    {0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6, 0x00},  // 004e (N)
    {0x38, 0x6c, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x00},  // 004f (O)
    {0xfc, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00},  // 0050 (P)
    {0x78, 0xcc, 0xcc, 0xcc, 0xdc, 0x78, 0x1c, 0x00},  // 0051 (Q)
    {0xfc, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0xe6, 0x00},  // 0052 (R)
    {0x78, 0xcc, 0xe0, 0x70, 0x1c, 0xcc, 0x78, 0x00},  // 0053 (S)
    {0xfc, 0xb4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00},  // 0054 (T)
    {0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xfc, 0x00},  // 0055 (U)
    {0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x00},  // 0056 (V)
    {0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00},  // 0057 (W)
    {0xc6, 0xc6, 0x6c, 0x38, 0x38, 0x6c, 0xc6, 0x00},  // 0058 (X)
    {0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x30, 0x78, 0x00},  // 0059 (Y)
    {0xfe, 0xc6, 0x8c, 0x18, 0x32, 0x66, 0xfe, 0x00},  // 005a (Z)
    {0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x78, 0x00},  // 005b (bracketleft)
    {0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x02, 0x00},  // 005c (backslash)
    {0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00},  // 005d (bracketright)
    {0x10, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0x00},  // 005e (asciicircum)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff},  // 005f (underscore)
    {0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},  // 0060 (grave)
    {0x00, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x76, 0x00},  // 0061 (a)
    {0xe0, 0x60, 0x60, 0x7c, 0x66, 0x66, 0xdc, 0x00},  // 0062 (b)
    {0x00, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x00},  // 0063 (c)
    {0x1c, 0x0c, 0x0c, 0x7c, 0xcc, 0xcc, 0x76, 0x00},  // 0064 (d)
    {0x00, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00},  // 0065 (e)
    {0x38, 0x6c, 0x60, 0xf0, 0x60, 0x60, 0xf0, 0x00},  // 0066 (f)
    {0x00, 0x00, 0x76, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8},  // 0067 (g)
    {0xe0, 0x60, 0x6c, 0x76, 0x66, 0x66, 0xe6, 0x00},  // 0068 (h)
    {0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00},  // 0069 (i)
    {0x0c, 0x00, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78},  // 006a (j)
    {0xe0, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0xe6, 0x00},  // 006b (k)
    {0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00},  // 006c (l)
    {0x00, 0x00, 0xcc, 0xfe, 0xfe, 0xd6, 0xc6, 0x00},  // 006d (m)
    {0x00, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0xcc, 0x00},  // 006e (n)
    {0x00, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0x78, 0x00},  // 006f (o)
    {0x00, 0x00, 0xdc, 0x66, 0x66, 0x7c, 0x60, 0xf0},  // 0070 (p)
    {0x00, 0x00, 0x76, 0xcc, 0xcc, 0x7c, 0x0c, 0x1e},  // 0071 (q)
    {0x00, 0x00, 0xdc, 0x76, 0x66, 0x60, 0xf0, 0x00},  // 0072 (r)
    {0x00, 0x00, 0x7c, 0xc0, 0x78, 0x0c, 0xf8, 0x00},  // 0073 (s)
    {0x10, 0x30, 0x7c, 0x30, 0x30, 0x34, 0x18, 0x00},  // 0074 (t)
    {0x00, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x76, 0x00},  // 0075 (u)
    {0x00, 0x00, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x00},  // 0076 (v)
    {0x00, 0x00, 0xc6, 0xd6, 0xfe, 0xfe, 0x6c, 0x00},  // 0077 (w)
    {0x00, 0x00, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00},  // 0078 (x)
    {0x00, 0x00, 0xcc, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8},  // 0079 (y)
    {0x00, 0x00, 0xfc, 0x98, 0x30, 0x64, 0xfc, 0x00},  // 007a (z)
    {0x1c, 0x30, 0x30, 0xe0, 0x30, 0x30, 0x1c, 0x00},  // 007b (braceleft)
    {0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},  // 007c (bar)
    {0xe0, 0x30, 0x30, 0x1c, 0x30, 0x30, 0xe0, 0x00},  // 007d (braceright)
    {0x76, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 007e (asciitilde)
    {0x00, 0x10, 0x38, 0x6c, 0xc6, 0xc6, 0xfe, 0x00},  // 007f (uni007F)
    // ---------------------------  160-255 ---------------------------
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 00a0 (uni00A0)
    {0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00},  // 00a1 (exclamdown)
    {0x18, 0x18, 0x7e, 0xc0, 0xc0, 0x7e, 0x18, 0x18},  // 00a2 (cent)
    {0x38, 0x6c, 0x64, 0xf0, 0x60, 0xe6, 0xfc, 0x00},  // 00a3 (sterling)
    {0x00, 0xc6, 0x7c, 0xc6, 0xc6, 0x7c, 0xc6, 0x00},  // 00a4 (currency)
    {0xcc, 0xcc, 0x78, 0xfc, 0x30, 0xfc, 0x30, 0x30},  // 00a5 (yen)
    {0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},  // 00a6 (brokenbar)
    {0x3e, 0x63, 0x38, 0x6c, 0x6c, 0x38, 0xcc, 0x78},  // 00a7 (section)
    {0xc6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 00a8 (dieresis)
    {0x7e, 0x81, 0x9d, 0xa1, 0xa1, 0x9d, 0x81, 0x7e},  // 00a9 (copyright)
    {0x3c, 0x6c, 0x6c, 0x3e, 0x00, 0x7e, 0x00, 0x00},  // 00aa (ordfeminine)
    {0x00, 0x33, 0x66, 0xcc, 0x66, 0x33, 0x00, 0x00},  // 00ab (guillemotleft)
    {0x00, 0x00, 0x00, 0xfc, 0x0c, 0x0c, 0x00, 0x00},  // 00ac (logicalnot)
    {0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00},  // 00ad (uni00AD)
    {0x7e, 0x81, 0xb9, 0xa5, 0xb9, 0xa5, 0x81, 0x7e},  // 00ae (registered)
    {0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  // 00af (macron)
    {0x38, 0x6c, 0x6c, 0x38, 0x00, 0x00, 0x00, 0x00},  // 00b0 (degree)
    {0x30, 0x30, 0xfc, 0x30, 0x30, 0x00, 0xfc, 0x00},  // 00b1 (plusminus)
    {0x70, 0x18, 0x30, 0x60, 0x78, 0x00, 0x00, 0x00},  // 00b2 (uni00B2)
    {0x70, 0x18, 0x30, 0x18, 0x70, 0x00, 0x00, 0x00},  // 00b3 (uni00B3)
    {0x0c, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00},  // 00b4 (acute)
    {0x00, 0x66, 0x66, 0x66, 0x66, 0x7c, 0x60, 0xc0},  // 00b5 (mu)
    {0x7f, 0xdb, 0xdb, 0x7b, 0x1b, 0x1b, 0x1b, 0x00},  // 00b6 (paragraph)
    {0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00},  // 00b7 (periodcentered)
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x0c, 0x38},  // 00b8 (cedilla)
    {0x30, 0x70, 0x30, 0x30, 0x78, 0x00, 0x00, 0x00},  // 00b9 (uni00B9)
    {0x38, 0x6c, 0x6c, 0x38, 0x00, 0x7c, 0x00, 0x00},  // 00ba (ordmasculine)
    {0x00, 0xcc, 0x66, 0x33, 0x66, 0xcc, 0x00, 0x00},  // 00bb (guillemotright)
    {0xc3, 0xc6, 0xcc, 0xdb, 0x37, 0x6f, 0xcf, 0x03},  // 00bc (onequarter)
    {0xc3, 0xc6, 0xcc, 0xde, 0x33, 0x66, 0xcc, 0x0f},  // 00bd (onehalf)
    {0xe0, 0x33, 0x66, 0x3c, 0xfb, 0x37, 0x6f, 0xc3},  // 00be (threequarters)
    {0x30, 0x00, 0x30, 0x60, 0xc0, 0xcc, 0x78, 0x00},  // 00bf (questiondown)
    {0xc0, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0xc6, 0x00},  // 00c0 (Agrave)
    {0x06, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0xc6, 0x00},  // 00c1 (Aacute)
    {0x7c, 0xc6, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0x00},  // 00c2 (Acircumflex)
    {0x76, 0xdc, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0x00},  // 00c3 (Atilde)
    {0xc6, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0xc6, 0x00},  // 00c4 (Adieresis)
    {0x30, 0x30, 0x00, 0x78, 0xcc, 0xfc, 0xcc, 0x00},  // 00c5 (Aring)
    {0x3e, 0x6c, 0xcc, 0xfe, 0xcc, 0xcc, 0xce, 0x00},  // 00c6 (AE)
    {0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x18, 0x0c, 0x78},  // 00c7 (Ccedilla)
    {0xe0, 0x00, 0xfc, 0x60, 0x78, 0x60, 0xfc, 0x00},  // 00c8 (Egrave)
    {0x1c, 0x00, 0xfc, 0x60, 0x78, 0x60, 0xfc, 0x00},  // 00c9 (Eacute)
    {0x78, 0xcc, 0xfc, 0x60, 0x78, 0x60, 0xfc, 0x00},  // 00ca (Ecircumflex)
    {0xcc, 0x00, 0xfc, 0x60, 0x78, 0x60, 0xfc, 0x00},  // 00cb (Edieresis)
    {0xe0, 0x00, 0x78, 0x30, 0x30, 0x30, 0x78, 0x00},  // 00cc (Igrave)
    {0x1c, 0x00, 0x78, 0x30, 0x30, 0x30, 0x78, 0x00},  // 00cd (Iacute)
    {0x7e, 0xc3, 0x3c, 0x18, 0x18, 0x18, 0x3c, 0x00},  // 00ce (Icircumflex)
    {0xcc, 0x00, 0x78, 0x30, 0x30, 0x30, 0x78, 0x00},  // 00cf (Idieresis)
    {0xf8, 0x6c, 0x66, 0xf6, 0x66, 0x6c, 0xf8, 0x00},  // 00d0 (Eth)
    {0xfc, 0x00, 0xcc, 0xec, 0xfc, 0xdc, 0xcc, 0x00},  // 00d1 (Ntilde)
    {0xc0, 0x38, 0x6c, 0xc6, 0xc6, 0x6c, 0x38, 0x00},  // 00d2 (Ograve)
    {0x06, 0x38, 0x6c, 0xc6, 0xc6, 0x6c, 0x38, 0x00},  // 00d3 (Oacute)
    {0x7c, 0xc6, 0x38, 0x6c, 0xc6, 0x6c, 0x38, 0x00},  // 00d4 (Ocircumflex)
    {0x76, 0xdc, 0x38, 0x6c, 0xc6, 0x6c, 0x38, 0x00},  // 00d5 (Otilde)
    {0xc3, 0x18, 0x3c, 0x66, 0x66, 0x3c, 0x18, 0x00},  // 00d6 (Odieresis)
    {0x00, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00, 0x00},  // 00d7 (multiply)
    {0x3a, 0x6c, 0xce, 0xd6, 0xe6, 0x6c, 0xb8, 0x00},  // 00d8 (Oslash)
    {0xe0, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x00},  // 00d9 (Ugrave)
    {0x1c, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x00},  // 00da (Uacute)
    {0x7c, 0xc6, 0x00, 0xc6, 0xc6, 0xc6, 0x7c, 0x00},  // 00db (Ucircumflex)
    {0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x00},  // 00dc (Udieresis)
    {0x1c, 0x00, 0xcc, 0xcc, 0x78, 0x30, 0x78, 0x00},  // 00dd (Yacute)
    {0xf0, 0x60, 0x7c, 0x66, 0x7c, 0x60, 0xf0, 0x00},  // 00de (Thorn)
    {0x78, 0xcc, 0xcc, 0xd8, 0xcc, 0xc6, 0xcc, 0x00},  // 00df (germandbls)
    {0xe0, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00},  // 00e0 (agrave)
    {0x1c, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00},  // 00e1 (aacute)
    {0x7e, 0xc3, 0x3c, 0x06, 0x3e, 0x66, 0x3f, 0x00},  // 00e2 (acircumflex)
    {0x76, 0xdc, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00},  // 00e3 (atilde)
    {0xcc, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00},  // 00e4 (adieresis)
    {0x30, 0x30, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00},  // 00e5 (aring)
    {0x00, 0x00, 0x7f, 0x0c, 0x7f, 0xcc, 0x7f, 0x00},  // 00e6 (ae)
    {0x00, 0x00, 0x78, 0xc0, 0xc0, 0x78, 0x0c, 0x38},  // 00e7 (ccedilla)
    {0xe0, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00},  // 00e8 (egrave)
    {0x1c, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00},  // 00e9 (eacute)
    {0x7e, 0xc3, 0x3c, 0x66, 0x7e, 0x60, 0x3c, 0x00},  // 00ea (ecircumflex)
    {0xcc, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00},  // 00eb (edieresis)
    {0xe0, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00},  // 00ec (igrave)
    {0x38, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00},  // 00ed (iacute)
    {0x7c, 0xc6, 0x38, 0x18, 0x18, 0x18, 0x3c, 0x00},  // 00ee (icircumflex)
    {0xcc, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00},  // 00ef (idieresis)
    {0x30, 0x7e, 0x0c, 0x7c, 0xcc, 0xcc, 0x78, 0x00},  // 00f0 (eth)
    {0x00, 0xf8, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0x00},  // 00f1 (ntilde)
    {0x00, 0xe0, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00},  // 00f2 (ograve)
    {0x00, 0x1c, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00},  // 00f3 (oacute)
    {0x78, 0xcc, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00},  // 00f4 (ocircumflex)
    {0x76, 0xdc, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00},  // 00f5 (otilde)
    {0x00, 0xcc, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00},  // 00f6 (odieresis)
    {0x30, 0x30, 0x00, 0xfc, 0x00, 0x30, 0x30, 0x00},  // 00f7 (divide)
    {0x00, 0x02, 0x7c, 0xce, 0xd6, 0xe6, 0x7c, 0x80},  // 00f8 (oslash)
    {0x00, 0xe0, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00},  // 00f9 (ugrave)
    {0x00, 0x1c, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00},  // 00fa (uacute)
    {0x78, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00},  // 00fb (ucircumflex)
    {0x00, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00},  // 00fc (udieresis)
    {0x00, 0x1c, 0x00, 0xcc, 0xcc, 0x7c, 0x0c, 0x78},  // 00fd (yacute)
    {0xe0, 0x60, 0x7c, 0x66, 0x66, 0x7c, 0x60, 0xf0},  // 00fe (thorn)
    {0x00, 0xcc, 0x00, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8},  // 00ff (ydieresis) 
};

static inline void outb(uint16_t port_num, uint8_t value) {
	asm("out %0, %1" : : "a"(value), "Nd"(port_num):);
}
static inline uint8_t inb(uint16_t port_num) {
	uint8_t res;

	asm("in %1, %0" : "=a"(res) : "Nd"(port_num):);
	return res;
}

#define SERIAL_PORT 0x3f8

static int init_serial(void) {
	outb(SERIAL_PORT + 1, 0x00);
	outb(SERIAL_PORT + 3, 0x80);
	outb(SERIAL_PORT + 0, 0x03);
	outb(SERIAL_PORT + 1, 0x00);
	outb(SERIAL_PORT + 3, 0x03);
	outb(SERIAL_PORT + 2, 0xC7);
	outb(SERIAL_PORT + 4, 0x0B);
	outb(SERIAL_PORT + 4, 0x1E);
	outb(SERIAL_PORT + 0, 0xAE);
	
	if (inb(SERIAL_PORT + 0) != 0xAE)
		return 1;
	
	outb(SERIAL_PORT+4, 0x0F);
	outb(0x3f8+1, 0x00);
	return 0;
}

static int serial_received(void) {
	return inb(SERIAL_PORT + 5) & 1;
}

static int is_transmit_empty(void) {
	return inb(SERIAL_PORT + 5) & 0x20;
}
static void write_serial(char c) {
	while(is_transmit_empty() == 0);
	outb(SERIAL_PORT, c);
}

static uint8_t read_serial(void) {
	while (serial_received() == 0);
	return inb(SERIAL_PORT);
}

static void print_serial(const char *s) {
	while(*s) {
		write_serial(*s);
		s++;
	}
}

#define PAGE_SIZE 4096
#define BOOTSTRAP_MEM_LIMIT (2ULL * 1024ULL * 1024ULL)

static int d = 'Y';
extern uint64_t boot_info;
extern uint64_t _stack_start;
extern uint64_t _pages_start;
extern uint64_t _pages_end;

static uint8_t vga_entry_color(uint8_t fg, uint8_t bg) {
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char ch, uint8_t color) {
	return (uint16_t) ch | (uint16_t) color << 8;
}

static void memset(uint8_t *addr, uint8_t chr, uint64_t count)
{
	uint64_t i;

	for (i = 0; i < count; i++) {
		*addr = chr;
		addr++;
	}
}

static int allocated_pages = 0;
static bool bootstrap = true;
static void *allocate_phy_pages(uint64_t count)
{
	void *addr = &_pages_start + allocated_pages * PAGE_SIZE;
	
	if ((uint64_t)addr >= BOOTSTRAP_MEM_LIMIT && bootstrap)
		return NULL;

	memset(addr, 0, count * PAGE_SIZE);
	allocated_pages += count;
	return addr;
}

static void *pml4t;
static void init_pml4t(void)
{
	pml4t = allocate_phy_pages(1);
}

static size_t row, column;
static uint16_t *vga_buffer = (uint16_t *) (0xB8000);

static void clear_s(void)
{
	row = 0;
	column = 0;
	for (int i = 0; i < 80 * 40; i++)
		*(vga_buffer + i) = vga_entry(' ', vga_entry_color(15, 0));
}

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
static void map_addr(void *virt_addr, void *phy_addr)
{
	int i;
	uint64_t va = (uint64_t) virt_addr;
	uint64_t pa = (uint64_t) phy_addr;

	va &= ~(0xFFFULL);
	pa &= ~(0xFFFULL);

	uint64_t pt_ind = (va & 0x1ff000ULL) >> 12;
	uint64_t pd_ind = (va & 0x3fe00000ULL) >> 21;
	uint64_t pdp_ind = (va & 0x7fc0000000ULL) >> 30;
	uint64_t pml4t_ind = (va & 0xff8000000000ULL) >> 39;

	uint64_t inds[] = { pml4t_ind, pdp_ind, pd_ind };

	uint64_t *cur = (uint64_t *)pml4t;

	for (i = 0; i < ARRAY_SIZE(inds); i++) {
		if (!cur[inds[i]]) {
			cur[inds[i]] = ((uint64_t)allocate_phy_pages(1)) | 0x3;
		}
		cur = (uint64_t *)(cur[inds[i]] & ~(0xFFFULL));
	}

	cur[pt_ind] = pa | 0x3;
}

static void map_range(uint64_t virt_start, uint64_t phy_start, size_t pages_count)
{
	size_t i;

	virt_start &= ~(0xFFFULL);
	phy_start &= ~(0xFFFULL);

	for (i = 0; i < pages_count; i++)
		map_addr((void *)(virt_start + i * PAGE_SIZE),
			 (void *)(phy_start + i * PAGE_SIZE));
}

static uint64_t buf_pos = 0;

void init_paging(void)
{
	uint64_t i;
	uint64_t end = (uint64_t)&_kernel_end;
	uint64_t begin = (uint64_t)&_pages_start;
	uint64_t count = (end - begin) / PAGE_SIZE;

	init_pml4t();
	map_range(0, 0, 512);
	
	map_range(begin, begin, count);

	asm("movq %0, %%cr3" : : "r"(pml4t):);
	bootstrap = false;
}

static void *info_struct;

struct __attribute__((packed)) info_header {
	uint32_t total_size;
	uint32_t reserved;
};

struct __attribute__((packed)) info_tag {
	uint32_t type;
	uint32_t size;
};

#define put_n(text, num) do {			\
	print_s(text);				\
	print_num(num);				\
	print_c('\n');				\
} while (0)

#define EARLY_PANIC(msg) do {			\
	print_serial(msg);			\
	while(1);				\
} while (0)

static void sleep(uint64_t t)
{
	for (uint64_t i = 0; i < 100000000ULL * t; i++)
		asm("nop");
}

struct __attribute__((packed)) frame_buffer {
	struct info_tag tag;
	uint64_t framebuffer_addr;
	uint32_t framebuffer_pitch;
	uint32_t framebuffer_width;
	uint32_t framebuffer_height;
	uint8_t framebuffer_bpp;
	uint8_t framebuffer_type;
	uint8_t reserved;
	uint8_t framebuffer_red_field_position;
	uint8_t framebuffer_red_mask_size;
	uint8_t framebuffer_green_field_position;
	uint8_t framebuffer_green_mask_size;
	uint8_t framebuffer_blue_field_position;
	uint8_t framebuffer_blue_mask_size;
};

static struct frame_buffer *fb = NULL;
static void put_pixel(uint64_t x, uint64_t y, uint32_t color)
{
	uint64_t where = y * fb->framebuffer_pitch + x * fb->framebuffer_bpp / 8;

	uint8_t *screen = (uint8_t *)fb->framebuffer_addr;
	screen[where] = color & 0xFF;
	screen[where + 1] = (color >> 8) & 0xFF;
	screen[where + 2] = (color >> 16) & 0xFF;
}

#define TEXT_COLOR 0xFFFFFF

static void draw_letter(const uint8_t *letter, uint64_t x, uint64_t y)
{
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			put_pixel(x + (7 - j), y + i, letter[i] & (1 << j) ? TEXT_COLOR : 0);
		}
	}
}

static char *logo = ".____    .__  __    __  .__           ________    _________\n"
		    "|    |   |__|/  |__/  |_|  |   ____   \\_____  \\  /   _____/\n"
		    "|    |   |  \\   __\\   __\\  | _/ __ \\   /   |   \\ \\_____  \\\n" 
		    "|    |___|  ||  |  |  | |  |_\\  ___/  /    |    \\/        \\\n"
		    "|_______ \\__||__|  |__| |____/\\___  > \\_______  /_______  /\n"
		     "        \\/                        \\/          \\/        \\/ \n\n";

#define CHAR_W 8
#define CHAR_H 8
#define H_SPACE 4
static uint64_t cx = 0;
static uint64_t cy = 0;
static void print_c(unsigned char c)
{
	if (c == '\n') {
		cy += CHAR_H + H_SPACE;
		cx = 0;
		return;
	}
	draw_letter(letters[c], cx, cy);
	cx += CHAR_W;
	if (column == fb->framebuffer_width) {
		cy += CHAR_H + H_SPACE;
		cx = 0;
	}
}
static void print_s(char *s)
{
	while (*s) {
		print_c(*s);
		s++;
	}
}
static const char *digits = "0123456789ABCDEF";

#define PRINT_NUMBER(x, pr_chr) do {		\
	char res[32] = {};			\
	int8_t len = 0;				\
	if (x == 0) {				\
		pr_chr('0');			\
		break;				\
	}					\
	while (x) {				\
		res[len++] = digits[x % 16];	\
		x >>= 4;			\
	}					\
	len--;					\
	while (len >= 0)			\
		pr_chr(res[len--]);		\
} while (0);

static void print_num(uint64_t x)
{
	PRINT_NUMBER(x, print_c);
}

static inline void print_c_serial(char x)
{
	write_serial(x);
}

static void print_num_serial(uint64_t x)
{
	PRINT_NUMBER(x, print_c_serial);
}

#define pr_n_s(msg, x) do {		\
	print_serial(msg);		\
	print_num_serial(x);		\
	print_c_serial('\n');		\
} while (0);

struct __attribute__((packed)) memory_entry_header {
	struct info_tag tag;
	uint32_t entry_size;
	uint32_t entry_version;
};

struct __attribute__((packed)) memory_entry_info {
	uint64_t base_addr;
	uint64_t length;
	uint32_t type;
	uint32_t reserved;
};

#define _packed __attribute__((packed))

static uint64_t phy_memory_map[80000];

static inline uint64_t floor_page(uint64_t x)
{
	return x & ~(0xFFF);
}

static inline uint64_t ceil_page(uint64_t x)
{
	return floor_page(x + PAGE_SIZE - 1);
}

static inline void bitmap_set(uint64_t *b, size_t x)
{
	b[x / sizeof(*b) / 8] |= 1 << (x % (sizeof(*b) * 8));
}

static inline bool bitmap_test(uint64_t *b, size_t x)
{
	return b[x / sizeof(*b) / 8] & (1 << (x % (sizeof(*b) * 8)));
}

static inline void bitmap_clear(uint64_t *b, size_t x)
{
	b[x / sizeof(*b) / 8] &= ~(1ULL << (x % (sizeof(*b) * 8)));
}

enum PAGE_TYPE {
	PAGE_FREE,
	PAGE_TAKEN,
};

static void mark_pages(uint64_t start, uint64_t end, enum PAGE_TYPE ptype)
{
	for (size_t i = floor_page(start); i <= end; i += PAGE_SIZE)
		if (ptype == PAGE_FREE)
			bitmap_clear(phy_memory_map, i / PAGE_SIZE);
		else
			bitmap_set(phy_memory_map, i / PAGE_SIZE);
}

static void init_phy_alloc(void)
{
	memset(phy_memory_map, 0xFF, 65536 * sizeof(uint64_t));
}

static void *alloc_physical_page(void)
{
	int x = -1;
	for (size_t i = 0; i < sizeof(phy_memory_map) / sizeof(phy_memory_map[0]); i++) {
		if (phy_memory_map[i] != 0xFFFFFFFFFFFFFFFFULL) {
			x = i;
			break;
		}
	}
	if (x == -1)
		return NULL;

	for (size_t i = 0; i < 8 * 8; i++) {
		if (!bitmap_test(phy_memory_map, x * 64 + i)) {
			bitmap_set(phy_memory_map, x * 64 + i);
			return (x * 64 + i) * PAGE_SIZE;
		}
	}

	return NULL;
}

static struct memory_entry_info *mem_info;
static struct memory_entry_header *mem_hdr;
static struct area_info *main_mem;

static void parse_info_struct(void)
{
	struct info_header *header = (struct info_header *)info_struct;
	struct memory_entry_info *temp;

	if (header->reserved != 0)
		EARLY_PANIC("AHTUNG! Header struct is not clean\n");

	uint64_t data = (uint64_t)info_struct + 8;

	char *bootloader_name = NULL;
	while ((uint64_t)data < (uint64_t)info_struct + header->total_size) {
		uint32_t cur_type = *((uint32_t *)data);
		uint32_t cur_size = *((uint32_t *)(data + 4));
		//pr_n_s("Type: ", cur_type);
		//pr_n_s("Size: ", cur_size);
		if (cur_type == 0 && cur_size == 8)
			break;
		if (cur_type == 8) {
			fb = (struct frame_buffer *)data;
		} else if (cur_type == 2) {
			bootloader_name = (char *)(data + 8);
		} else if (cur_type == 6) {
			mem_hdr = (struct memory_entry_header *)data;
			mem_info = (struct memory_entry_info *)(data + 16);
		}
		data += cur_size;
		data = (data + 7ULL) >> 3 << 3;
	}

	uint64_t pages_count = (fb->framebuffer_width * fb->framebuffer_height * fb->framebuffer_bpp + PAGE_SIZE) / PAGE_SIZE + 1;
	map_range(fb->framebuffer_addr, fb->framebuffer_addr, pages_count);

	print_s(logo);
	if (bootloader_name) {
		print_s(bootloader_name);
		print_c('\n');
	}

	temp = &mem_info[(mem_hdr->tag.size - 16) / mem_hdr->entry_size - 1];
	while (temp > mem_info) {
		put_n("Type:", temp->type);
		put_n("Base:", temp->base_addr);
		put_n("Len:", temp->length);
		if (temp->type == 1)
			mark_pages(temp->base_addr, temp->base_addr + temp->length, PAGE_FREE);	
		temp--;
	}
	mark_pages(&_kernel_start, &_kernel_end, PAGE_TAKEN);
}

static void alloc_virt_range(uint64_t va, uint64_t pc)
{
	size_t i;
	uint64_t pa;

	for (i = 0; i < pc; i++) {
		pa = alloc_physical_page();
		map_addr(va + i * PAGE_SIZE, pa);
	}
}

/* HEAP */
#define HEAP_PAGES 64
#define BIN_COUNT 12
static uint64_t bins[BIN_COUNT + 1] = {};
struct _packed block_hdr {
	uint64_t prev_size;
	// Last bit: taken / free
	// Size of the block excluding header
	uint64_t size;
	struct block_hdr *next_in_bin;
};

typedef struct block_hdr block_t;
static void *heap;

#define HEAP_ADDR 0x1337FFFF000ULL
#define HEAP_END (HEAP_ADDR + PAGE_SIZE * HEAP_PAGES)

static void init_heap(void)
{
	alloc_virt_range(HEAP_ADDR, HEAP_PAGES);
	heap = (void *) HEAP_ADDR;
	// bins[BINS_COUNT] = initial, large region
	bins[BIN_COUNT] = heap;
	struct block_hdr *main_block = (struct block_hdr *)heap;
	main_block->prev_size = 0;
	main_block->size = HEAP_PAGES * PAGE_SIZE - sizeof(block_t);
	main_block->next_in_bin = 0;
}

static inline uint64_t find_bin(uint64_t block_size)
{
	uint64_t pow = 0;

	while (pow < BIN_COUNT && (1ULL << (3 + pow)) < block_size)
		pow++;

	return pow;
}

static inline uint64_t ceil8(uint64_t x)
{
	return (x + 7) / 8 * 8;
}

static void put_block2bin(block_t *b)
{
	size_t bin = find_bin(b->size);
	block_t *tmp;
	block_t *f = (block_t *)bins[bin];

	if (bins[bin] == 0 || f->size > b->size) {
		tmp = (block_t *)bins[bin];
		bins[bin] = b;
		b->next_in_bin = tmp;
		return;
	}
	while (f->next_in_bin && f->size < b->size)
		f = f->next_in_bin;

	tmp = f->next_in_bin;
	f->next_in_bin = b;
	b->next_in_bin = tmp;
}

static void remove_from_bin(block_t *b)
{
	block_t *prev = NULL;
	size_t bin = find_bin(b->size);
	if (bins[bin] == (uint64_t)b) {
		bins[bin] = b->next_in_bin;
		return;
	}
	block_t *c = (block_t *)bins[bin];
	pr_n_s("Removing ", b->size);
	pr_n_s("From bin ", bin);
	while (c) {
		if (c == b) {
			prev->next_in_bin = c->next_in_bin;
			return;
		}
		prev = c;
		c = c->next_in_bin;
	}
	EARLY_PANIC("There is no bin!");
}

#define bs sizeof(block_t)
static void *kmalloc(uint64_t size)
{
	size_t bin;

	size = ceil8(size);
	pr_n_s("allocating ", size);
	bin = find_bin(size);
	while (bin <= BIN_COUNT && bins[bin] == 0)
		bin++;
	if (bin > BIN_COUNT)
		return NULL;

	// Take block out of the bin
	block_t *block = (block_t *)bins[bin];
	bins[bin] = block->next_in_bin;
	uint64_t diff = block->size - size;
	if (diff > sizeof(block_t)) {
		block_t *sec = (block_t *)((uint64_t)block + sizeof(block_t) + size);
		sec->size = diff - sizeof(block_t);
		sec->prev_size = size;
		block->size = size;
		pr_n_s("Sec size: ", sec->size);
		//put block back
		put_block2bin(sec);
	}
	block->size |= 1ULL;
	pr_n_s("Final bs:", block->size);
	return (void *)((uint64_t)block + sizeof(block_t));
}

static block_t *merge_back(block_t *b)
{
	while (b) {
		if (b->prev_size == 0)
			return b;
		block_t *prev = (block_t *)((uint64_t)b - b->prev_size - sizeof(block_t));
		if (prev->size & 1ULL) {
			/* Prev is taken */
			break;
		}
		remove_from_bin(prev);
		prev->size += sizeof(block_t) + b->size;
		b = prev;
	}
	return b;
}
static void merge_forward(block_t *b)
{
	block_t *cur = b;
	while ((uint64_t)(cur + bs + cur->size) < HEAP_END) {
		block_t *next = (block_t *) ((uint64_t)cur + bs + cur->size);
		pr_n_s("Next block is:", next->size);
		if (next->size & 1) {
			next->prev_size = b->size;
			break;
		}
		print_serial("Removing next");
		remove_from_bin(next);
		b->size += next->size + bs;
		cur = next;
	}
}

static void *kfree(void *addr, bool b)
{
	block_t *block = (block_t *)(addr - bs);
	block->size ^= 1ULL;
	pr_n_s("Before merge back size: ", block->size);
	block = merge_back(block);
	pr_n_s("After merge back size: ", block->size);
	merge_forward(block);
	put_block2bin(block);
}

static void print_bins(void)
{
	print_serial("Bins content:\n");
	for (size_t i = 0; i < BIN_COUNT + 1; i++) {
		print_num_serial(bins[i]);
		print_c_serial(' ');
	}
	print_c_serial('\n');
}

int kernel_main(void)
{
	init_serial();
	init_paging();
	map_addr((void *)0xDEADCAFE000ULL, (void *)boot_info);
	info_struct = (void *)(0xDEADCAFE000ULL + (boot_info & 0xFFFULL));
	init_phy_alloc();
	parse_info_struct();

	uint64_t *t = alloc_physical_page();
	map_addr(t, t);
	put_n("Page: ", t);
	t[0] = 0x123;
	put_n("Val: ", t[0]);
	print_s("Initializing heap...");
	init_heap();
	block_t *lb = (block_t *)bins[BIN_COUNT];
	print_s("Done!\n");
	print_s("Allocating test block (size: 0x26)...");
	pr_n_s("Last bin size:", lb->size);
	void *bl = kmalloc(0x20);
	void *bl2 = kmalloc(0x8);
	put_n("Done! Addr: ", bl);
	put_n("Done! Addr2: ", bl2);
	print_bins();
	kfree(bl, false);
	print_bins();
	kfree(bl2, true);
	print_bins();
	pr_n_s("Last bin size:", lb->size);


	while(1);
	return 0;
}
