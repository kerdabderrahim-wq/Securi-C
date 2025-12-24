#ifndef USER_H
#define USER_H

#include <stdio.h>

struct User { 
    char name[20]; 
    char password[20]; 
    int role;   // 0: user, 1: admin 
    int state;  // 0: active, 1: blocked 
};

void initUsers(struct User users[], int n);
void displayUsers(struct User users[], int n);
void addUser(struct User users[], int n);
void deleteUser(struct User users[], int n, char name[]);
int searchUser(struct User users[], int n, char name[]);
void changePassword(struct User users[], int n, char name[]);
int checkLogin(struct User users[], int n, char name[], char pass[]);
int strongPassword(char pass[]);
void blockUser(struct User users[], int n, char name[]);
void unblockUser(struct User users[], int n, char name[]);
void changeRole(struct User users[], int n, char name[], int role);
void listAdmins(struct User users[], int n);
int stringLength(char str[]);
int containsUppercase(char str[]);
int containsLowercase(char str[]);
int containsDigit(char str[]);
int containsSymbol(char str[]);
void userStatistics(struct User users[], int n);
void saveUsers(struct User users[], int n);
void loadUsers(struct User users[], int n);

// CLI functions
void _initUsers();
void _displayUsers();
void _addUser();
void _deleteUser();
void _searchUser();
void _changePassword();
void _checkLogin();
void _strongPassword();
void _blockUser();
void _unblockUser();
void _changeRole();
void _listAdmins();
void _stringLength();
void _containsUppercase();
void _containsLowercase();
void _containsDigit();
void _containsSymbol();
void _userStatistics();
void _saveUsers();
void _loadUsers();

#endif
