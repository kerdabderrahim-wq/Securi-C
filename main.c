#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Encryption & Decryption/enc_dec.h"
#include "Math & Security Tools/math.h"
#include "User Management/user.h"
#include "Security audit and analysis/security_audit.h"
#include "Log Management & Analysis _/log.h"

#define START_R 60
#define START_G 160
#define START_B 255

#define END_R 255
#define END_G 150
#define END_B 100

#define SHADOW_R 20
#define SHADOW_G 20
#define SHADOW_B 30

#define C_NUM "\033[38;2;255;150;100m" 
#define C_RST "\033[0m"                

void draw_logo() {
    const char *bitmap[] = {
        "  #   ####  #####  ####   #  #  ####  #         #### ",
        " #    #     #      #      #  #  #  #  #         #    ",
        "#     ####  #####  #      #  #  ####  #  #####  #    ",
        " #       #  #      #      #  #  # #   #         #    ",
        "  #   ####  #####  ####   ####  #  #  #         #### "
    };

    int rows = sizeof(bitmap) / sizeof(bitmap[0]);
    int width = strlen(bitmap[0]);

    printf("\n"); 
    for (int y = 0; y < rows + 1; y++) {
        printf("  "); 
        for (int x = 0; x < width + 1; x++) {
            int is_pixel = (y < rows && x < width && bitmap[y][x] == '#');
            int is_shadow = (y - 1 >= 0 && x - 1 >= 0 && 
                             y - 1 < rows && x - 1 < width && 
                             bitmap[y - 1][x - 1] == '#');

            if (is_pixel) {
                float ratio = (float)x / (float)width;
                int r = (int)(START_R + (END_R - START_R) * ratio);
                int g = (int)(START_G + (END_G - START_G) * ratio);
                int b = (int)(START_B + (END_B - START_B) * ratio);
                printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b);
            } else if (is_shadow) {
                printf("\033[48;2;%d;%d;%dm  \033[0m", SHADOW_R, SHADOW_G, SHADOW_B);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n"); 
}

void drawNSCS() {
    const char *bitmap[] = {
        " #   #   ####    ####    #### ",
        " ##  #  #       #       #     ",
        " # # #   ###    #        ###  ",
        " #  ##      #   #           # ",
        " #   #  ####     ####   ####  "
    };

    int rows = sizeof(bitmap) / sizeof(bitmap[0]);
    int width = strlen(bitmap[0]);

    printf("\n"); 
    for (int y = 0; y < rows + 1; y++) {
        printf("  ");
        for (int x = 0; x < width + 1; x++) {
            int is_pixel = (y < rows && x < width && bitmap[y][x] == '#');
            int is_shadow = (y - 1 >= 0 && x - 1 >= 0 && 
                             y - 1 < rows && x - 1 < width && 
                             bitmap[y - 1][x - 1] == '#');

            if (is_pixel) {
                float ratio = (float)x / (float)width;
                int r = (int)(START_R + (END_R - START_R) * ratio);
                int g = (int)(START_G + (END_G - START_G) * ratio);
                int b = (int)(START_B + (END_B - START_B) * ratio);
                printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b);
            } else if (is_shadow) {
                printf("\033[48;2;%d;%d;%dm  \033[0m", SHADOW_R, SHADOW_G, SHADOW_B);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseConsole() {
    printf("\nPress Enter to continue...");
    getchar(); 
    getchar(); 
}

void menuEncryption();
void menuMath();
void menuUser();
void menuAudit();
void menuLog();
void showHelp();
void showAbout();

int main() {
    int choice;
    do {
        clearScreen();
        draw_logo();
        
        printf("--------------- Securi-C Main Menu ---------------\n");
        printf(C_NUM "1." C_RST " Encryption and Decryption Library\n");
        printf(C_NUM "2." C_RST " Mathematical and Security Tools\n");
        printf(C_NUM "3." C_RST " User Management System\n");
        printf(C_NUM "4." C_RST " Security Audit and Analysis\n");
        printf(C_NUM "5." C_RST " Log Management and Monitoring\n");
        printf(C_NUM "6." C_RST " Help\n");
        printf(C_NUM "7." C_RST " About\n");
        printf(C_NUM "0." C_RST " Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: menuEncryption(); break;
            case 2: menuMath(); break;
            case 3: menuUser(); break;
            case 4: menuAudit(); break;
            case 5: menuLog(); break;
            case 6: showHelp(); break;
            case 7: showAbout(); break;
            case 0: 
                printf("Exiting tool... SeeYA.\n"); 
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
                pauseConsole();
        }
    } while (choice != 0);
    
    return 0;
}


void menuEncryption() {
    int choice;
    do {
        clearScreen();
        
        printf("\033[38;2;%d;%d;%dm >> Encryption & Decryption Library\033[0m\n", START_R,START_G,START_B);
        printf("----------------------------------\n");
        
        printf(" " C_NUM "1." C_RST " Input Message           " C_NUM "2." C_RST " Display Message\n");
        printf(" " C_NUM "3." C_RST " Is Uppercase?           " C_NUM "4." C_RST " Is Lowercase?\n");
        printf(" " C_NUM "5." C_RST " Is Alphabetic?          " C_NUM "6." C_RST " To Uppercase\n");
        printf(" " C_NUM "7." C_RST " To Lowercase            " C_NUM "8." C_RST " Reverse Message\n");
        printf(" " C_NUM "9." C_RST " Remove Spaces          " C_NUM "10." C_RST " Encrypt Cesar\n");
        printf(C_NUM "11." C_RST " Decrypt Cesar          " C_NUM "12." C_RST " Encrypt XOR\n");
        printf(C_NUM "13." C_RST " Decrypt XOR            " C_NUM "14." C_RST " Encrypt Substitution\n");
        printf(C_NUM "15." C_RST " Decrypt Substitution   " C_NUM "16." C_RST " Is Valid Key\n");
        printf(C_NUM "17." C_RST " Compare Messages       " C_NUM "18." C_RST " Count Character\n");
        printf(C_NUM "19." C_RST " Frequency Analysis     " C_NUM "20." C_RST " Coincidence Index\n");
        printf(" " C_NUM "0." C_RST " Back to Main Menu\n");
        
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: _inputMessage(); break;
            case 2: _displayMessage(); break;
            case 3: _isUppercase(); break;
            case 4: _isLowercase(); break;
            case 5: _isAlphabetic(); break;
            case 6: _toUppercase(); break;
            case 7: _toLowercase(); break;
            case 8: _reverseMessage(); break;
            case 9: _removeSpaces(); break;
            case 10: _encryptCesar(); break;
            case 11: _decryptCesar(); break;
            case 12: _encryptXOR(); break;
            case 13: _decryptXOR(); break;
            case 14: _encryptSubstitution(); break;
            case 15: _decryptSubstitution(); break;
            case 16: _isValidKey(); break;
            case 17: _compareMessages(); break;
            case 18: _countCharacter(); break;
            case 19: _frequencyAnalysis(); break;
            case 20: _coincidenceIndex(); break;
            case 0: return;
            default: printf("Invalid choice.\n");
        }
        if(choice != 0) pauseConsole();
    } while (choice != 0);
}

void menuMath() {
    int choice;
    do {
        clearScreen();
        printf("\033[38;2;%d;%d;%dm >> Mathematical & Security Tools\033[0m\n", START_R,START_G,START_B);
        printf("--------------------------------\n");
        
        printf(" " C_NUM "1." C_RST " Is Even?                " C_NUM "2." C_RST " Is Prime?\n");
        printf(" " C_NUM "3." C_RST " GCD                     " C_NUM "4." C_RST " LCM\n");
        printf(" " C_NUM "5." C_RST " Modular Exp             " C_NUM "6." C_RST " Factorial\n");
        printf(" " C_NUM "7." C_RST " Sum Digits              " C_NUM "8." C_RST " Reverse Number\n");
        printf(" " C_NUM "9." C_RST " Is Palindrome          " C_NUM "10." C_RST " Sum Divisors\n");
        printf(C_NUM "11." C_RST " Is Perfect Number      " C_NUM "12." C_RST " Is Armstrong\n");
        printf(C_NUM "13." C_RST " Random Number          " C_NUM "14." C_RST " Sum Array\n");
        printf(C_NUM "15." C_RST " Average Array          " C_NUM "16." C_RST " Max Array\n");
        printf(C_NUM "17." C_RST " Min Array              " C_NUM "18." C_RST " Sort Ascending\n");
        printf(C_NUM "19." C_RST " Display Matrix         " C_NUM "20." C_RST " Add Matrices\n");
        printf(C_NUM "21." C_RST " Multiply Matrices      " C_NUM "22." C_RST " Transpose Matrix\n");
        printf(C_NUM "23." C_RST " Determinant 2x2        " C_NUM "24." C_RST " Is Symmetric Matrix\n");
        printf(C_NUM "25." C_RST " Is Identity Matrix      " C_NUM "0." C_RST " Back\n");
        
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: _isEven(); break;
            case 2: _isPrime(); break;
            case 3: _gcd(); break;
            case 4: _lcm(); break;
            case 5: _modExp(); break;
            case 6: _factorial(); break;
            case 7: _sumDigits(); break;
            case 8: _reverseNumber(); break;
            case 9: _isPalindromeNumber(); break;
            case 10: _sumDivisors(); break;
            case 11: _isPerfectNumber(); break;
            case 12: _isArmstrong(); break;
            case 13: _randomNumber(); break;
            case 14: _sumArray(); break;
            case 15: _averageArray(); break;
            case 16: _maxArray(); break;
            case 17: _minArray(); break;
            case 18: _sortAscending(); break;
            case 19: _displayMatrix(); break;
            case 20: _addMatrices(); break;
            case 21: _multiplyMatrices(); break;
            case 22: _transposeMatrix(); break;
            case 23: _determinant2x2(); break;
            case 24: _isSymmetric(); break;
            case 25: _isIdentity(); break;
            case 0: return;
            default: printf("Invalid choice.\n");
        }
        if(choice != 0) pauseConsole();
    } while (choice != 0);
}

void menuUser() {
    int choice;
    do {
        clearScreen();
        printf("\033[38;2;%d;%d;%dm >> User Management System\033[0m\n", START_R,START_G,START_B);
        printf("--------------------------\n");
        
        printf(" " C_NUM "1." C_RST " Init Users              " C_NUM "2." C_RST " Display Users\n");
        printf(" " C_NUM "3." C_RST " Add User                " C_NUM "4." C_RST " Delete User\n");
        printf(" " C_NUM "5." C_RST " Search User             " C_NUM "6." C_RST " Change Password\n");
        printf(" " C_NUM "7." C_RST " Check Login             " C_NUM "8." C_RST " Check Pass Strength\n");
        printf(" " C_NUM "9." C_RST " Block User             " C_NUM "10." C_RST " Unblock User\n");
        printf(C_NUM "11." C_RST " Change Role            " C_NUM "12." C_RST " List Admins\n");
        printf(C_NUM "13." C_RST " String Length          " C_NUM "14." C_RST " Contains Uppercase\n");
        printf(C_NUM "15." C_RST " Contains Lowercase     " C_NUM "16." C_RST " Contains Digit\n");
        printf(C_NUM "17." C_RST " Contains Symbol        " C_NUM "18." C_RST " User Statistics\n");
        printf(C_NUM "19." C_RST " Save Users             " C_NUM "20." C_RST " Load Users\n");
        printf(" " C_NUM "0." C_RST " Back\n");
        
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: _initUsers(); break;
            case 2: _displayUsers(); break;
            case 3: _addUser(); break;
            case 4: _deleteUser(); break;
            case 5: _searchUser(); break;
            case 6: _changePassword(); break;
            case 7: _checkLogin(); break;
            case 8: _strongPassword(); break;
            case 9: _blockUser(); break;
            case 10: _unblockUser(); break;
            case 11: _changeRole(); break;
            case 12: _listAdmins(); break;
            case 13: _stringLength(); break;
            case 14: _containsUppercase(); break;
            case 15: _containsLowercase(); break;
            case 16: _containsDigit(); break;
            case 17: _containsSymbol(); break;
            case 18: _userStatistics(); break;
            case 19: _saveUsers(); break;
            case 20: _loadUsers(); break;
            case 0: return;
            default: printf("Invalid choice.\n");
        }
        if(choice != 0) pauseConsole();
    } while (choice != 0);
}

void menuAudit() {
    int choice;
    do {
        clearScreen();
        printf("\033[38;2;%d;%d;%dm >> Security Audit & Analysis\033[0m\n", START_R,START_G,START_B);
        printf("----------------------------\n");
        
        printf(" " C_NUM "1." C_RST " Count Uppercase         " C_NUM "2." C_RST " Count Lowercase\n");
        printf(" " C_NUM "3." C_RST " Count Digits            " C_NUM "4." C_RST " Percent Uppercase\n");
        printf(" " C_NUM "5." C_RST " Text Length             " C_NUM "6." C_RST " Display Stats\n");
        printf(" " C_NUM "7." C_RST " Very Strong Pass?       " C_NUM "8." C_RST " Generate Key\n");
        printf(" " C_NUM "9." C_RST " Is Hex Key?            " C_NUM "10." C_RST " Gen Random Pass\n");
        printf(C_NUM "11." C_RST " Password Score         " C_NUM "12." C_RST " Average Score\n");
        printf(C_NUM "13." C_RST " Global Report          " C_NUM "14." C_RST " Count Strong Users\n");
        printf(C_NUM "15." C_RST " Security Tips           " C_NUM "0." C_RST " Back\n");
        
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: _countUppercase(); break;
            case 2: _countLowercase(); break;
            case 3: _countDigits(); break;
            case 4: _percentUppercase(); break;
            case 5: _textLength(); break;
            case 6: _displayTextStats(); break;
            case 7: _veryStrongPassword(); break;
            case 8: _generateKey(); break;
            case 9: _isHexKey(); break;
            case 10: _generateRandomPassword(); break;
            case 11: _passwordScore(); break;
            case 12: _averageScore(); break;
            case 13: _displaySecurityReport(); break;
            case 14: _countStrongUsers(); break;
            case 15: _showSecurityTips(); break;
            case 0: return;
            default: printf("Invalid choice.\n");
        }
        if(choice != 0) pauseConsole();
    } while (choice != 0);
}

void menuLog() {
    int choice;
    do {
        clearScreen();
        printf("\033[38;2;%d;%d;%dm >> Log Management & Analysis\033[0m\n", START_R, START_G, START_B);
        printf("----------------------------\n");
        
        printf(" " C_NUM "1." C_RST " Init Logs               " C_NUM "2." C_RST " Add Log\n");
        printf(" " C_NUM "3." C_RST " Display Logs            " C_NUM "4." C_RST " Search by User\n");
        printf(" " C_NUM "5." C_RST " Search by Date          " C_NUM "6." C_RST " Count Errors\n");
        printf(" " C_NUM "7." C_RST " Count Logins            " C_NUM "8." C_RST " Count Blocked\n");
        printf(" " C_NUM "9." C_RST " Log Stats              " C_NUM "10." C_RST " Sort by Date\n");
        printf(C_NUM "11." C_RST " Sort by User           " C_NUM "12." C_RST " Suspicious Activity\n");
        printf(C_NUM "13." C_RST " Daily Connections      " C_NUM "14." C_RST " Error Rate\n");
        printf(C_NUM "15." C_RST " Export CSV             " C_NUM "16." C_RST " Import CSV\n");
        printf(C_NUM "17." C_RST " Clear Logs             " C_NUM "18." C_RST " Recent Logs\n");
        printf(C_NUM "19." C_RST " Archive Logs           " C_NUM "20." C_RST " Top Errors\n");
        printf(" " C_NUM "0." C_RST " Back\n");
        
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: _initLogs(); break;
            case 2: _addLog(); break;
            case 3: _displayLogs(); break;
            case 4: _searchLogsByUser(); break;
            case 5: _searchLogsByDate(); break;
            case 6: _countErrorLogs(); break;
            case 7: _countLoginLogs(); break;
            case 8: _countBlockedLogs(); break;
            case 9: _displayLogStats(); break;
            case 10: _sortLogsByDate(); break;
            case 11: _sortLogsByUser(); break;
            case 12: _detectSuspiciousActivity(); break;
            case 13: _dailyConnections(); break;
            case 14: _errorRate(); break;
            case 15: _exportLogsCSV(); break;
            case 16: _importLogsCSV(); break;
            case 17: _clearLogs(); break;
            case 18: _recentLogs(); break;
            case 19: _archiveLogs(); break;
            case 20: _showTopErrors(); break;
            case 0: return;
            default: printf("Invalid choice.\n");
        }
        if(choice != 0) pauseConsole();
    } while (choice != 0);
}

void showHelp() {
    clearScreen();
    printf("\033[38;2;%d;%d;%dm >> HELP GUIDE\033[0m\n", START_R,START_G,START_B);
    printf("Use the number keys to navigate the menus.\n");
    printf("Each library contains modules for cybersecurity tasks.\n");
    printf("Follow the on-screen prompts within each module.\n");
    pauseConsole();
}

void showAbout() {
    clearScreen();
    drawNSCS();
    printf("\033[38;2;%d;%d;%dm >> ABOUT Securi-C\033[0m\n", START_R,START_G,START_B);
    printf("Securi-C is a comprehensive C library suite for cybersecurity.\n");
    printf("It includes modules for encryption, math tools, user management,\n");
    printf("security auditing, and log analysis.\n");
    printf("Developed to aid security professionals and enthusiasts.\n");
    printf("================================================\n");
    printf("Project: Security Utility Library Suite\n");
    printf("Academic Year: 2025/2026\n");
    printf("Developed by: Kerd Abderrahim & Akeb Abdelkarim\n");
    printf("Group: B03\n");
    printf("Supervised by: Dr. Berghout Yasser\n");
    pauseConsole();
}