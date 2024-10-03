#include "palette.h"
#include <stdio.h>

// Define the NES-like 8-bit color palette with 16 colors
const Color PALETTE[16] = {
    { 0x7C, 0x7C, 0x7C },  // Dark Gray
    { 0x00, 0x00, 0xFC },  // Blue
    { 0x00, 0x00, 0xBC },  // Dark Blue
    { 0x44, 0x28, 0xBC },  // Purple
    { 0x94, 0x00, 0x84 },  // Magenta
    { 0xA8, 0x00, 0x20 },  // Dark Red
    { 0xA8, 0x10, 0x00 },  // Red
    { 0x88, 0x14, 0x00 },  // Orange
    { 0x50, 0x30, 0x00 },  // Brown
    { 0x00, 0x78, 0x00 },  // Green
    { 0x00, 0x68, 0x00 },  // Dark Green
    { 0x00, 0x58, 0x00 },  // Olive Green
    { 0x00, 0x40, 0x58 },  // Cyan
    { 0x00, 0x00, 0x00 },  // Black
    { 0xA0, 0xA0, 0xA0 },  // Light Gray
    { 0xFC, 0xFC, 0xFC }   // White
};

// Function to get a color from the palette by index
Color get_color_from_palette(int index) {
    // Check if the index is within the valid range
    if (index < 0 || index >= 16) {
        printf("Error: Invalid color index %d. Returning black.\n", index);
        return (Color){ 0x00, 0x00, 0x00 };  // Return black for invalid index
    }
    
    return PALETTE[index];  // Return the color from the palette
}
