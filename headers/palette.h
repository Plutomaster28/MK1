#ifndef PALETTE_H
#define PALETTE_H

// NES-like 8-bit color palette
typedef struct {
    unsigned char r, g, b;
} Color;

// Define the palette (limited color set for 8-bit games)
extern const Color PALETTE[16];

// Get a color from the palette by index
Color get_color_from_palette(int index);

#endif // PALETTE_H
