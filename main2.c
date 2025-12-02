
#include <stdio.h>

int main() {
    int choice;
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
    
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Launching Math & Security Tools...\n");
        printf("Choose one of these modules:\n");
        printf("1. isEven\n");
        printf("2. isPrime\n");
        printf("3. GCD\n");
        printf("4. lcm\n");
        printf("5. power\n");
        printf("6. modExp\n");
        printf("7. factorial\n");
        printf("8. sumDigits\n");
        printf("9. reverseNumber\n"); 
        printf("10. isPalindromeNumber\n");
        printf("11. sumDivisors\n");
        printf("12. isPerfectNumber\n");
        printf("13. isArmstrong\n");
        printf("14. randomNumber\n");
        printf("15. sumArray\n");
        printf("16. averageArray\n");
        printf("17. maxArray\n");
        printf("18. minArray\n");
        printf("19. sortAscending\n");

    } else if (choice == 2) {
        printf("Launching Encryption & Decryption...\n");
        printf("Choose one of these modules:\n");
        printf("1. toUppercase\n");   
        printf("2. toLowercase\n");
        printf("3. reverseMessage\n");
        printf("4. removeSpaces\n");
        printf("5. encryptCesar\n");
        printf("6. decryptCesar\n");
        printf("7. encryptXOR\n");
        printf("8. decryptXOR\n");
        printf("9. encryptSubstitution\n");
        printf("10. decryptSubstitution\n");
    } else {
        printf("Invalid choice. Please restart the program and select 1 or 2.\n");
    }
    return 0;



}

