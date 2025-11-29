#include <stdio.h>

void encode(const char *input, char *output) {
    // Simple encoding: shift each character by 1
    while (*input) {
        *output++ = *input++ + 1;
    }
    *output = '\0';
}