#include <stdio.h>
#include "../Encryption & Decryption/enc_dec.h"

int main(){
    struct Message m;
    inputMessage(&m);
    displayMessage(m);
    printf("\nFrequency Analysis:\n");
    frequencyAnalysis(m);
    float ci=coincidenceIndex(m);
    printf("Coincidence Index: %.6f\n",ci);
    return 0;
}


