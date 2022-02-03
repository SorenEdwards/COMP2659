#define INVADER_HEIGHT 16

int invader_bitmap[INVADER_HEIGHT] =
{
	0x0000,
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
	0x0000
};

#UINT16 *FB = (UINT16 *) PhysBase();
plot_bitmap(FB, 0,0, *invader_bitmap, INVADER_HEIGHT)

void plot_bitmap_grid(U)

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap,
			unsigned int height) {
	offset = (40 * y) + (x >> 4);
	for (int i = 0; i < height; i++) {
		*(base + offset + 40 * i) = invader_bitmap[i];
}
	
