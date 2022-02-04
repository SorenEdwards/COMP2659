#include <stdio.h>      /* header needed for printfs and scanfs */
#include <osbind.h>     /* header needed for Bconstat and Bconin */

#define INVADER_HEIGHT 16

typedef unsigned int UINT16;

void plot_bitmap_16(UINT16*, int, int, UINT16*, UINT16);

const UINT16 invader_bitmap[INVADER_HEIGHT] = {0x0000,
										0x0810,
										0x0810,
										0x0420,
										0x0240,
										0x1FF8,
										0x2004,
										0x4662,
										0x4002,
										0x43C2,
										0x2424,
										0x1008,
										0x0FF0,
										0x0240,
										0x0E70,
										0x0000 };
int main() {

	
	UINT16 * FB = (UINT16 *) Physbase();
	UINT16 * FB_two = FB;
	int x_two;
	int x = 12;
	int y = 0;
	int f;
	int j;
	char ch;
	plot_bitmap_16(FB, x,y, invader_bitmap, (UINT16) INVADER_HEIGHT);
	getchar(ch);
	x_two = 22;
	plot_bitmap_16(FB_two, x_two, y, invader_bitmap, (UINT16) INVADER_HEIGHT);
	getchar(ch);

	return 0;
}

void plot_bitmap_16(UINT16 * base, int x, int y, const UINT16 * bitmap, UINT16 height) {
	UINT16 offset = (40 * y) + (x >> 4);
	int i;
	for (i = 0; i < height; i++) {
		*(base + offset + 40 * i) = invader_bitmap[i];
	}
}
