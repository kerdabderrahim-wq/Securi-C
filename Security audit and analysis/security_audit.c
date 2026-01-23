#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Encryption & Decryption/enc_dec.h"
struct User{
    char name[20]; 
    char password[20]; 
    int role;   // 0: user, 1: admin 
    int state;  // 0: active, 1: blocked 
};
//1
//description : a function that counts the number of uppercase letters in a given text
// input : a string (character array)
 //output : the number of uppercase letters in the string
int countUppercase(char text[]) {
    int i,count;
    count=0;
    for ( i = 0; text[i]!='\0'; i++)
    {
        if(text[i]>='A'&& text[i]<='Z'){
            count=count+1;
        }
    }
    return count;
    
}
//2
//description : a function that counts the number of lowercase letters in a given text  
// input : a string (character array)
    //output : the number of lowercase letters in the string
int countLowercase(char text[]){
    int i,count;
    count=0;
    for ( i = 0; text[i]!='\0'; i++)
    {
        if(text[i]>='a'&& text[i]<='z'){
            count=count+1;
        }
    }
    return count;

}
//3
//description : a function that counts the number of digits in a given text  
// input : a string (character array)
// output : the number of digits in the string
int countDigits(char text[]){
    int i,count;
    count=0;
    for ( i = 0; text[i]!='\0'; i++)
    {
        if(text[i]>='0'&& text[i]<='9'){
            count=count+1;
        }
    }
    return count;   
}
//4
//description : a function that calculates the percentage of uppercase letters in a given text
// input : a string (character array)
// output : the percentage of uppercase letters in the string
float percentUppercase(char text[]){
    int i;
    float total,uppercase;
    total=0;
    uppercase=0;
    for ( i = 0; text[i]!='\0'; i++)
    {
        total=total+1;
        if(text[i]>='A'&& text[i]<='Z'){
            uppercase=uppercase+1;
        }
    }
    return (uppercase/total )*100;

}
//5
//description : a function that calculates the length of a given text
// input : a string (character array)
// output : the length of the string
int textLength(char text[])
{
    int i,length;
    length=0;
    for ( i = 0; text[i]!='\0'; i++)
    //\0 is the null character that indicates the end of a string in C
    {
        length=length+1;
    }
    return length;
}
//6
//description : a procedure that displays various statistics about a given text
// input : a string (character array)
//output : none (the function prints the statistics to the console)
void displayTextStats(char text[]){
    int uppercase,lowercase,digits,length;
    float percent_uppercase;
    uppercase=countUppercase(text);
    lowercase=countLowercase(text);
    digits=countDigits(text);
    length=textLength(text);
    percent_uppercase=percentUppercase(text);
    printf("Text Statistics:\n");
    printf("Length: %d\n",length);
    printf("Uppercase Letters: %d\n",uppercase);
    printf("Lowercase Letters: %d\n",lowercase);
    printf("Digits: %d\n",digits);
    printf("Percentage of Uppercase Letters: %.2f%%\n",percent_uppercase);
}
//7
//description : a function that checks if a password is very strong based on specific criteria
// input : a string (character array) representing the password
// output : 1 if the password is very strong, 0 otherwise
int veryStrongPassword(char pass[]){
    /*Requirements:

The password length must be at least 12 characters.

It must contain at least one uppercase letter.

It must contain at least one lowercase letter.

It must contain at least one digit.

It must contain at least one special character (e.g., !@#$%^&*).

Return 1 if very strong, 0 otherwise.*/
    int length ,uppercase,lowercase , digits,specialChar;
    length=textLength(pass);
    uppercase=countUppercase(pass);
    lowercase=countLowercase(pass);
    digits=countDigits(pass);
    specialChar=length-(uppercase+lowercase+digits);
    return (length>=12 && uppercase>0 && lowercase>0 && digits>0 && specialChar>0);




}
void generateRandomPassword(int length, char pass[]);
//8
//description : a procedure that generates a random key of specified length
// input : an integer length and a character array key to store the generated key
// output : none (the function modifies the key array in place)
void generateKey(int length, char key[]){
    generateRandomPassword(length,key);
}
//9
//description : a function that checks if a given key is a valid hexadecimal key
// input : a string (character array) representing the key
// output : 1 if the key is valid hexadecimal, 0 otherwise
int isHexKey(char key[]){
    int i;
    for ( i = 0; key[i]!='\0'; i++){
        if (!((key[i]>='0' && key[i]<='9')||(key[i]>='A' && key[i]<='F')))
        //'0' the char of 0
        {
            return 0;
        }
        
    }
    return 1;
}
//10
//description : a procedure that generates a random password of specified length        
// input : an integer length and a character array pass to store the generated password
// output : none (the function modifies the pass array in place)
void generateRandomPassword(int length, char pass[]){

    int random ,i;
    srand(time(0)); 
    // to initialize the random number generator with the current time as seed
    
    for ( i = 0; i < length; i++)
    {
        random=rand()%94 +33;
         // to generate a random character between ASCII 33 and 126
        pass[i]=random;
    }
    pass[length]='\0';
    // to terminate the string with null character
    
}
//11
//description : a function that calculates the strength score of a given password
// input : a string (character array) representing the password
// output : an integer score representing the strength of the password
int passwordScore(char pass[]){
    int length,uppercase,lowercase,digits,specialChar,score;
    length=textLength(pass);                                    
    uppercase=countUppercase(pass);
    lowercase=countLowercase(pass);
    digits=countDigits(pass);
    specialChar=length-(uppercase+lowercase+digits);
    score=0;
    if (length>=8){
        score=score+1;
    }
    if (length>=12){
        score=score+1;
    }
    if (uppercase>0){
        score=score+1;
    }
    if (lowercase>0){
        score=score+1;
    }
    if (digits>0){
        score=score+1;
    }
    if (specialChar>0){
        score=score+1;
    }
    return score;
}
//12
//description : a function that calculates the average password strength score for an array of users
// input : an array of User structs and the number of users
// output : a float representing the average password strength score
float averageScore(struct User users[], int n){
    int i,total;
    total=0;
    for ( i = 0; i < n; i++)
    {
        total=total+passwordScore(users[i].password);
    }
    if(n!=0){
        return (float)total/n;
    }else{
        return 0.0;
    }
}
//13
//description : a procedure that displays a security report for an array of users
// input : an array of User structs and the number of users
// output : none (the function prints the report to the console)
void displaySecurityReport(struct User users[], int n){
    int i,score;
    for ( i = 0; i < n; i++)
    {
        score = passwordScore(users[i].password);
        if (score<=3)
        {
            printf("User: %s, Password Strength: Weak (Score: %d)\n", users[i].name, score);

        }else{
            printf("User: %s, Password Strength: Strong (Score: %d)\n", users[i].name, score);
        }
        
    }
    
}
//14
//description : a function that counts the number of users with strong passwords
// input : an array of User structs and the number of users
// output : the number of users with strong passwords
int countStrongUsers(struct User users[], int n){
    int i,count;
    count=0;
    for ( i = 0; i < n; i++)
    {
        if (passwordScore(users[i].password)>3)
        {
            count=count+1;
        }
        
    }
    return count;
}
//15
//description : a procedure that displays security tips to the user
// input : none
// output : none (the function prints the tips to the console)
void showSecurityTips(){
    printf("Security Tips:\n");
    printf("1. Use strong passwords with a mix of uppercase, lowercase, digits, and special characters.\n");
    printf("2. Change your passwords regularly.\n");
    printf("3. Avoid using the same password for multiple accounts.\n");
    printf("4. Enable two-factor authentication whenever possible.\n");
    printf("5. Be cautious of phishing attempts and suspicious links.\n");
}
//16
//description : a function that checks if an email address is in a valid format
// input : a string (character array) representing the email address
// output : 1 if the email format is valid, 0 otherwise
int checkEmailFormat(char email[]){
    int i,arobaz,dot;
    for ( i = 0; email[i]!='\0' ; i++)
    {
        if (email[i]=='@')
        {
            arobaz=i;
        }
        if (email[i]=='.')
        {
            dot=i;
        }
        if (email[i]==' ')
        {
            return 0;
        }

        
    }
    if(arobaz<dot-1 && (i-dot)>2){
        //this means that there is at least one character between @ and . and at least two characters after .
        return 1;
    }
    return 0;
    
}
//17
//description : a function that checks if a login name is in a valid format
// input : a string (character array) representing the login name
// output : 1 if the login format is valid, 0 otherwise
int checkLoginFormat(char name[]){
/*1. It is not Empty
2. It has No Spaces
3. It contains Only Letters and Numbers*/
    int i;
    for ( i = 0; name[i]!='\0' ; i++)
    {
        if (name[i]==' ')
        {
            return 0;
        }
        if (!((name[i]>='0' && name[i]<='9')||(name[i]>='A' && name[i]<='Z')||(name[i]>='a' && name[i]<='z')))
        {
            return 0;
        }    
    }
    if (i==0)
    {
        return 0;
    }
    return 1;

}

void generateHexKey(int length, char key[]){
    int i,random;
    srand(time(0));
    for ( i = 0; i < length; i++){
        random=rand()%16;
        if (random<10){
            key[i]='0'+random;
        }else{
            key[i]='A'+(random-10);
        }
    }
    
}
void sortScore(struct User users[], int n) {
    int i, j;
    struct User temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (passwordScore(users[j].password) < passwordScore(users[j + 1].password)) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}
//19
//description : a procedure that displays the top 3 strongest passwords from an array of users
// input : an array of User structs and the number of users
// output : none (the function prints the top 3 passwords to the console)
void top3Passwords(struct User users[], int n){
    int i;
    sortScore( users,n);
    for ( i = 0; i < n  && i<3; i++){
        printf("the top %d password is : %s score : %d\n ",i+1,users[i].password, passwordScore(users[i].password));
    }
    
}

int globalSecurityLevel(struct User users[], int n){
    // Implementation
    float avg = averageScore(users, n);
    if(avg >= 5) return 1; // High
    if(avg >= 3) return 2; // Medium
    return 3; // Low
}


//==============================================================================================================================================
// extra functions of the encryption and decryption cli
//========================================================================================================================================================
void _countUppercase(){
    char text[400];
    printf("Enter the text:\n");
    //%[^\n] means read until newline
    scanf(" %[^\n]",text);
    printf("The number of uppercase letters is : %d\n",countUppercase(text));
}
void _countLowercase(){
    char text[400];
    printf("Enter the text:\n");
    scanf(" %[^\n]",text);
    printf("The number of lowercase letters is : %d\n",countLowercase(text));
}
void _countDigits(){
    char text[400];
    printf("Enter the text:\n");

    scanf(" %[^\n]",text);
    printf("The number of digits is : %d\n",countDigits(text));
}
void _percentUppercase(){
    char text[400];
    printf("Enter the text:\n");
    scanf(" %[^\n]",text);
    printf("The percentage of uppercase letters is : %.2f%%\n",percentUppercase(text));
}
void _textLength(){
    char text[400];
    printf("Enter the text:\n");
    scanf(" %[^\n]",text);
    printf("The length of the text is : %d\n",textLength(text));
}
void _displayTextStats(){
    char text[400];
    printf("Enter the text:\n");
    scanf(" %[^\n]",text);
    displayTextStats(text);
}
void _veryStrongPassword(){
    char pass[100];
    printf("Enter the password:\n");
    scanf(" %[^\n]",pass);
    if (veryStrongPassword(pass))
    {
        printf("The password is very strong\n");
    }else{
        printf("The password is not very strong\n");
    }
    
}

void _generateKey(){
    int length;
    char key[100];
    printf("Enter the length of the key:\n");
    while (scanf("%d",&length) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    generateKey(length,key);
    printf("The generated key is : %s\n",key);
}

void _isHexKey(){
    char key[100];
    printf("Enter the key:\n");
    scanf(" %[^\n]",key);
    if (isHexKey(key))
    {
        printf("The key is a valid hexadecimal key\n");
    }else{
        printf("The key is not a valid hexadecimal key\n");
    }
    
}

void _generateRandomPassword(){
    int length;
    char pass[100];
    printf("Enter the length of the password:\n");
    while (scanf("%d",&length) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    generateRandomPassword(length,pass);
    printf("The generated password is : %s\n",pass);
}
void _passwordScore(){
    char pass[100];
    printf("Enter the password:\n");
    scanf(" %[^\n]",pass);
    printf("The password strength score is : %d\n",passwordScore(pass));
}
void _averageScore(){
    struct User users[100];
    int n,i;
    printf("Enter the number of users:\n");
    while (scanf("%d",&n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < n; i++)
    {
        printf("Enter the name of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].name);
        printf("Enter the password of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].password);
    }
    printf("The average password strength score is : %.2f\n",averageScore(users,n));
}
void _countStrongUsers(){
    struct User users[100];
    int n,i;
    printf("Enter the number of users:\n");
    while (scanf("%d",&n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < n; i++)
    {
        printf("Enter the name of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].name);
        printf("Enter the password of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].password);
    }
    printf("The number of users with strong passwords is : %d\n",countStrongUsers(users,n));
}
void _showSecurityTips(){
    showSecurityTips();
}
void _checkEmailFormat(){
    char email[100];
    printf("Enter the email address:\n");
    scanf(" %[^\n]",email);
    if (checkEmailFormat(email))
    {
        printf("The email format is valid\n");
    }else{
        printf("The email format is not valid\n");
    }
    
}
void _checkLoginFormat(){
    char name[100];
    printf("Enter the login name:\n");
    scanf(" %[^\n]",name);
    if (checkLoginFormat(name))
    {
        printf("The login format is valid\n");
    }else{
        printf("The login format is not valid\n");
    }
    
}
void _generateHexKey(){
    int length;
    char key[100];
    printf("Enter the length of the hexadecimal key:\n");
    while (scanf("%d",&length) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    generateHexKey(length,key);
    printf("The generated hexadecimal key is : %s\n",key);


}
void _sortScore(){
    struct User users[100];
    int n,i;
    printf("Enter the number of users:\n");
    while (scanf("%d",&n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < n; i++)
    {
        printf("Enter the name of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].name);
        printf("Enter the password of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].password);
    }
    sortScore(users,n);
    printf("Users sorted by password strength score successfully\n");
}
void _top3Passwords(){
    struct User users[100];
    int n,i;
    printf("Enter the number of users:\n");
    while (scanf("%d",&n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < n; i++)
    {
        printf("Enter the name of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].name);
        printf("Enter the password of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].password);
    }
    top3Passwords(users,n);
}
void _displaySecurityReport(){
    struct User users[100];
    int n,i;
    printf("Enter the number of users:\n");
    while (scanf("%d",&n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < n; i++)
    {
        printf("Enter the name of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].name);
        printf("Enter the password of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].password);
    }
    displaySecurityReport(users,n);
}

void _globalSecurityLevel(){
    struct User users[100];
    int n,i;
    printf("Enter the number of users:\n");
    while (scanf("%d",&n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < n; i++)
    {
        printf("Enter the name of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].name);
        printf("Enter the password of user %d:\n",i+1);
        scanf(" %[^\n]",users[i].password);
    }
    int level = globalSecurityLevel(users, n);
    printf("Global Security Level: %s\n", level == 1 ? "High" : (level == 2 ? "Medium" : "Low"));
}