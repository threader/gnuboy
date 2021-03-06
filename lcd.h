

#ifndef __LCD_H__
#define __LCD_H__

#include "defs.h"

struct vissprite
{
	byte *buf;
	int x;
	byte pal, pri, pad[6];
};

struct scan
{
	int bg[64];
	int wnd[64];
	byte buf[256];
	byte pal1[128];
	un16 pal2[64];
	un32 pal4[64];
	byte pri[256];
	struct vissprite vs[16];
	int ns, l, x, y, s, t, u, v, wx, wy, wt, wv;
};

struct obj
{
	byte y;
	byte x;
	byte pat;
	byte flags;
};

struct lcd
{
	byte vbank[2][8192];
	union
	{
		byte mem[256];
		struct obj obj[40];
	} oam;
	byte pal[128];
};

extern struct lcd lcd;
extern struct scan scan;

void updatepatpix();
void tilebuf();
void bg_scan();
void wnd_scan();
void bg_scan_pri();
void wnd_scan_pri();
void bg_scan_color();
void wnd_scan_color();
void spr_count();
void spr_enum();
void spr_scan();
void lcd_begin();
void lcd_refreshline();
void pal_write(int i, byte b);
void pal_write_dmg(int i, int mapnum, byte d);
void vram_write(int a, byte b);
void vram_dirty();
void pal_dirty();
void lcd_reset();

#define LCDC_BIT_BG_EN    (1<<0) /* BG display off or on - CGB: always on */
#define LCDC_BIT_OBJ_EN   (1<<1) /* OBJs off or on */
#define LCDC_BIT_OBJ_SIZE (1<<2) /* OBJ size: 0:8x8 1:8x16 */
#define LCDC_BIT_BG_MAP   (1<<3) /* BG code area 0:9800-9bff, 1:9c00-9fff */
#define LCDC_BIT_TILE_SEL (1<<4) /* BG char data 0:8800-97ff, 1:8000-8fff */
#define LCDC_BIT_WIN_EN   (1<<5) /* WIN off or on */
#define LCDC_BIT_WIN_MAP  (1<<6) /* WIN code area 0:9800-9bff, 1:9c00-9fff */
#define LCDC_BIT_LCD_EN   (1<<7) /* LCD controller off or on */


#endif



