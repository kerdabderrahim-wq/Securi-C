#include <stdio.h>
#include <stdlib.h>

/* --- Windows Compatibility Setup --- */
#ifdef _WIN32
#include <windows.h>
void setup_console() {
    /* Set Output to UTF-8 to allow block characters */
    SetConsoleOutputCP(CP_UTF8);
    
    /* Enable ANSI Escape Codes for Colors */
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= 0x0004; /* ENABLE_VIRTUAL_TERMINAL_PROCESSING */
    SetConsoleMode(hOut, dwMode);
}
#else
void setup_console() { /* No setup needed for Linux/Mac */ }
#endif

/* --- Configuration --- */
#define FONT_H 5
#define CANVAS_H 7
#define CANVAS_W 80

typedef struct { int r, g, b; } Color;

/* 
 * Bitmap Font Data 
 * Each string represents one row of one character.
 * '1' = Pixel, '0' = Empty
 */
const char *font_data[] = {
    /* > (Width 3) */
    "100", "010", "001", "010", "100",
    /* S (Width 5) */
    "01111", "10000", "01110", "00001", "11110",
    /* e (Width 5) */
    "00000", "01110", "11111", "10000", "01111",
    /* c (Width 5) */
    "00000", "01110", "10000", "10000", "01111",
    /* u (Width 5) */
    "00000", "10010", "10010", "10010", "01110",
    /* r (Width 5) */
    "00000", "10110", "11000", "10000", "10000",
    /* i (Width 5) */
    "00100", "00000", "00100", "00100", "00100",
    /* - (Width 5) */
    "00000", "00000", "11100", "00000", "00000",
    /* C (Width 5) */
    "01111", "10000", "10000", "10000", "01111"
};

const int char_widths[] = {3, 5, 5, 5, 5, 5, 5, 5, 5};
const int text_seq[]    = {0, 1, 2, 3, 4, 5, 6, 7, 8}; /* Indices for "> Securi-C" */

int main() {
    setup_console();

    /* --- 1. Define Gradients --- */
    Color palette[] = {
        {0, 120, 255},   /* > Deep Blue */
        {0, 180, 255},   /* S Cyan */
        {100, 160, 255}, /* e Cornflower */
        {140, 140, 255}, /* c Periwinkle */
        {180, 120, 240}, /* u Lavender */
        {220, 100, 200}, /* r Orchid */
        {255, 80, 150},  /* i Hot Pink */
        {255, 80, 100},  /* - Salmon */
        {255, 60, 60}    /* C Red/Pink */
    };

    /* --- 2. Initialize Canvas --- */
    /* 0=Empty, 1=Shadow, 2=Text */
    int grid[CANVAS_H][CANVAS_W] = {0}; 
    int color_map[CANVAS_H][CANVAS_W] = {0};

    int cursor_x = 2; /* Start padding */
    int spacing = 2;  /* Space between letters */
    int i, r, c;

    /* --- 3. Render Loop --- */
    /* We iterate twice: First for Shadows (layer 1), then for Text (layer 2) 
       This ensures text is always "on top" of the shadow. */
    
    // Pass 1: Draw Shadows (Offset +1, +1)
    int temp_x = cursor_x;
    for (i = 0; i < 9; i++) {
        int char_idx = text_seq[i];
        int w = char_widths[char_idx];
        
        for (r = 0; r < FONT_H; r++) {
            for (c = 0; c < w; c++) {
                if (font_data[char_idx * 5 + r][c] == '1') {
                    // Draw shadow at y+1, x+1
                    grid[r + 1][temp_x + c + 1] = 1; 
                }
            }
        }
        temp_x += w + spacing;
    }

    // Pass 2: Draw Main Text
    temp_x = cursor_x;
    for (i = 0; i < 9; i++) {
        int char_idx = text_seq[i];
        int w = char_widths[char_idx];
        
        for (r = 0; r < FONT_H; r++) {
            for (c = 0; c < w; c++) {
                if (font_data[char_idx * 5 + r][c] == '1') {
                    // Draw text at y, x (Overwrites shadow if they overlap)
                    grid[r][temp_x + c] = 2;
                    color_map[r][temp_x + c] = i; // Save which color to use
                }
            }
        }
        temp_x += w + spacing;
    }

    /* --- 4. Print Canvas --- */
    printf("\n\n");
    for (r = 0; r < CANVAS_H; r++) {
        printf("  "); // Left Margin
        for (c = 0; c < temp_x + 2; c++) {
            int type = grid[r][c];
            
            if (type == 2) {
                // Foreground Pixel (Gradient)
                int col_idx = color_map[r][c];
                printf("\033[38;2;%d;%d;%dm██", 
                    palette[col_idx].r, palette[col_idx].g, palette[col_idx].b);
            } 
            else if (type == 1) {
                // Shadow Pixel (Dark Grey/Blue)
                printf("\033[38;2;40;40;60m██");
            } 
            else {
                // Background (Space)
                printf("\033[0m  "); 
            }
        }
        printf("\033[0m\n"); // End of line
    }
    printf("\n");

    #ifdef _WIN32
    system("pause");
    #endif

    return 0;
}