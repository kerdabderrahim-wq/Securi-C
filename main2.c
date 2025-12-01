#include <stdio.h>

int main() {
    printf("\n");
    printf("   _____                     _        _____ \n");
    printf("  / ____|                   (_)      / ____|\n");
    printf(" | (___   ___  ___ _   _ _ __ _ ____| |     \n");
    printf("  \\___ \\ / _ \\/ __| | | | '__| |____| |     \n");
    printf("  ____) |  __/ (__| |_| | |  | |    | |____ \n");
    printf(" |_____/ \\___|\\___|\\__,_|_|  |_|     \\_____|\n");
    printf("\n");





    printf("Welcome to Securi-C! Your command-line security toolkit.\n");
    printf("Choose an option to get started:\n");
    printf("1. Math & Security Tools\n");   
    printf("2. Encryption & Decryption\n");
    printf("Enter your choice (1 or 2): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Launching Math & Security Tools...\n");
        // Here you would call the Math & Security Tools module
    } else if (choice == 2) {
        printf("Launching Encryption & Decryption...\n");
        // Here you would call the Encryption & Decryption module
    } else {
        printf("Invalid choice. Please restart the program and select 1 or 2.\n");
    }
    
    return 0;



}
