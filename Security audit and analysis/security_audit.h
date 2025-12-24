#ifndef SECURITY_AUDIT_H
#define SECURITY_AUDIT_H

#include "../User Management/user.h"

int countUppercase(char text[]);
int countLowercase(char text[]);
int countDigits(char text[]);
float percentUppercase(char text[]);
int textLength(char text[]);
void displayTextStats(char text[]);
int veryStrongPassword(char pass[]);
void generateKey(int length, char key[]);
int isHexKey(char key[]);
void generateRandomPassword(int length, char pass[]);
int passwordScore(char pass[]);
float averageScore(struct User users[], int n);
void displaySecurityReport(struct User users[], int n);
int countStrongUsers(struct User users[], int n);
void showSecurityTips();
int checkEmailFormat(char email[]);
int checkLoginFormat(char name[]);
void generateHexKey(int length, char key[]);
void top3Passwords(struct User users[], int n);
int globalSecurityLevel(struct User users[], int n);

// CLI functions
void _countUppercase();
void _countLowercase();
void _countDigits();
void _percentUppercase();
void _textLength();
void _displayTextStats();
void _veryStrongPassword();
void _generateKey();
void _isHexKey();
void _generateRandomPassword();
void _passwordScore();
void _averageScore();
void _displaySecurityReport();
void _countStrongUsers();
void _showSecurityTips();
void _checkEmailFormat();
void _checkLoginFormat();
void _generateHexKey();
void _top3Passwords();
void _globalSecurityLevel();

#endif
