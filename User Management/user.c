#include <stdio.h>
#include <string.h>
struct User{ 
    char name[20]; 
    char password[20]; 
    int role;   // 0: user, 1: admin 
    int state;  // 0: active, 1: blocked 
};
struct User users[100];
int userCount = 0;
//the function is needed before
int searchUser(struct User users[], int n, char name[]);
//1
//function to initialize an array of users
//input : the number of users 
//output : an initialized list of users 
void initUsers(struct User users[], int n){
    int i;

    for(i=0;i<n;i++)
    {
        printf("Enter the user %d name :",i+1);
        scanf("%s",users[i].name);
        //we use %s to read strings
        printf("Enter the user %d password :",i+1);
        scanf("%s",users[i].password);
        do{
            printf("Enter the user %d role (0 user , 1 admin) :",i+1);
            scanf("%d",&users[i].role);
        }
        while(users[i].role!=0  && users[i].role!=1);
        
        do{
            printf("Enter the user %d state (0 active , 1 blocked) :",i+1);
            scanf("%d",&users[i].state);
        }
        while(users[i].state!=0  && users[i].state!=1);

    }

}

//2
//function to display the list of users 
//input : an array of users and the number of users
//output : display the list of users with their roles and states
void displayUsers(struct User users[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(users[i].name,"")!=0){ 
            //print them as table
            printf("User %d: Name: %s, Password: %s, Role: %s, State: %s\n", 
                i+1, 
                users[i].name, 
                users[i].password, 
                users[i].role == 0 ? "User" : "Admin", 
                users[i].state == 0 ? "Active" : "Blocked");
        }
    }
    
}
//3
//function to add a new user
//input : an array of users and the number of users
//output : add a new user to the list
void addUser(struct User users[], int n){
    struct User new_user;
    printf("Enter username: ");
    scanf("%s", new_user.name);
    while(searchUser(users,n,new_user.name)!=-1){
        printf("username is already exist please enter ANOTHER NAME");
    scanf("%s", new_user.name);
    //we check if the username already exists

    }
    printf("Enter password: ");
    scanf("%s", new_user.password);
    new_user.role = 0; 
    // default role is user
    new_user.state = 0;
     // default state is active
    users[n] = new_user; 
    // add the new user at the end of the list
}
//4
//function to delete a user by name
//input : an array of users, the number of users and the name of the user to delete
//output : delete the user from the list
void deleteUser(struct User users[], int n, char name[]){
    int index;
    index=searchUser(users,n,name);
    if (index==-1)
    {
        printf("user deasnot exist");
    }
    else
    {
        for (int i = index; i < n-1; i++)
        {
            users[i]=users[i+1];
            //shift the users to the left
        }
        //clear the last user
        strcpy(users[n-1].name,"");
        //empty the name
        strcpy(users[n-1].password,"");
        //empty the password
        users[n-1].role=0;
        //set role to default
        users[n-1].state=0;
        //set state to default
        printf("user deleted successfully");
    }
    
    

}
//5
//function to search for a user by name
//input : an array of users, the number of users and the name to search for
//output : the index of the user in the array or -1 if not found
int searchUser(struct User users[], int n, char name[]){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(name,users[i].name)==0)
        {
            return (i);
            //when the function return the rest of its code will not be executed 
        }
        
    }

    return -1;
}
//6
//function to change a user's password
//input : an array of users, the number of users and the name of the user
//output : change the password of the user if found
void changePassword(struct User users[], int n, char name[]){
    int index;
    char passwd[10];
    //ask for the current password
    index=searchUser(users,n,name);
    if (index!=-1)
    {
        printf("please enter your password");
        scanf("%s",passwd);
        if (strcmp(passwd,users[index].password)==0)
        {
            printf("please enter your new paaword");
            scanf("%s",users[index].password);
            printf("password changed seccusfully");
            //change the password
        }
        else{
            printf("wrong password please try again");
        }
    }else{
        printf("user not found");
    }
    
}
//7
//function to check login credentials
//input : an array of users, the number of users, a username and a password
//output : 1 if login is successful, 0 otherwise
int checkLogin(struct User users[], int n, char name[], char pass[]){
    int index;
    index=searchUser(users,n,name);
    if (index==-1)
    {
        return 0;
    }else{
        if (strcmp(users[index].password,pass)==0)
        {
            return 1;
        }
        
    }
    return 0;
}
//8
//function to check if a password is strong
//input : a password string
//output : 1 if the password is strong, 0 otherwise
int strongPassword(char pass[])
{
    int i,length,isuppercase,containDigit;
    i=0;
    length=0;
    containDigit=0;
    isuppercase=0;
    while (pass[i]!='\0')
    {
        length=length+1;
        
        if (pass[i]>='A' && pass[i]<='Z')
        {
            isuppercase=1;
        }
        //Contains at least one digit
        if (pass[i]>='0' && pass[i]<='9')
        {
            containDigit=1;
        }
        i=i+1;
    }
    return(length>8 && containDigit==1 && isuppercase==1);
    //if all the conditions are satisfied return 1 else return 0
    

}
//9
//function to block a user
//input : an array of users, the number of users and the name of the user to block
//output : block the user by setting the state to 1

void blockUser(struct User users[], int n, char name[]){
    int index;
    index=searchUser(users,n,name);
    //search for the user
    if (index!=-1)
    {
        users[index].state=1;
        //set the state to blocked
        printf("User %s blocked successfully\n", users[index].name);
    }else{
        printf("user not found");
    }
    
}
//10
//function to unblock a user
//input : an array of users,the size and the name of the user to
//output : unblock the user by setting the state to 0
void unblockUser(struct User users[], int n, char name[]){
    int index;
    index=searchUser(users,n,name);
    //search for the user
     if (index==-1)
    {
        printf("user not found");
    }
    
    if (index!=-1)
    {   printf("User %s unblocked successfully\n", users[index].name);
        users[index].state=0; // change the state 
    }
    
}
//11
//function to change a user role
//input : an array of users, the size, the name of the user and the new role
//output : change the role of the user if found
void changeRole(struct User users[], int n, char name[], int role){
    int index;
    index=searchUser(users,n,name);
    //search for the user
    if (index==-1)
    {
        printf("user not found");
    }
    // the case if the user is found
    if (index!=-1){   
        printf("User %s role changed successfully to %s\n", users[index].name, role == 0 ? "User" : "Admin");
        users[index].role=role;
    }
    
}
//12
//function to list all admins
//input : an array of users and the size
//output : print the names of all admins 
void listAdmins(struct User users[], int n){
    int i;
    printf("List of admins: \n");
    //print the list of admins
for ( i = 0; i < n; i++)
{
    //
    if (users[i].role==1)
    {
        printf("%s\n",users[i].name);

    }
    
    }
}
//13
//function to list all blocked users
//input : an array of users and the size
//output : print the names of all blocked users
int stringLength(char str[]){
    int i,length;
    length=0;
    i=0;
    while (str[i]!='\0')
    {
        length=length+1;
        i=i+1;
    }
    return length;
}
//14
//function to check if a string contains uppercase letters
//input : a string
//output : 1 if it contains uppercase letters, 0 otherwise
int containsUppercase(char str[]){
    int i;
    i=0;

    while (str[i]!='\0')
    {
        if (str[i]>='A' && str[i]<='Z')
        {
            return 1;
        }
        i=i+1;
    }
    return 0;
}
//15
//function to check if a string contains lowercase letters
//input : a string
//output : 1 if it contains lowercase letters, 0 otherwise
int containsLowercase(char str[]){
    int i;
    i=0;
    
    while (str[i]!='\0')
    {
        if (str[i]>='a' && str[i]<='z')
        {
            return 1;
        }
        i=i+1;
    }
    return 0;

}
//16
//function to check if a string contains digits 
//input : a string
//output : 1 if it contains digits, 0 otherwise
int containsDigit(char str[]){
    int i;
    i=0;
    
    while (str[i]!='\0')
    {
        
        //Contains at least one digit
        if (str[i]>='0' && str[i]<='9')
        {
            return 1;
        }
        i=i+1;
    }
    return 0;
}
//17
//function to check if a string contains symbols    
//input : a string
//output : 1 if it contains symbols, 0 otherwise
int containsSymbol(char str[]){
    
    int i;
 

    i=0;
    while (str[i]!='\0'){
        if(!(str[i]>='0' && str[i]<='9') && !(str[i]>='a' && str[i]<='z') && !(str[i]>='A' && str[i]<='Z')){
            return 1;
        }
        i++;
    }
    
    
    return 0;
    
}
//18
//function to display user statistics
//input : an array of users and the size
//output : print the total number of users, number of admins and number of blocked users

void userStatistics(struct User users[], int n){
    int countBlocked,countAdmins,i;
    countAdmins=0;
    i=0;
    countBlocked=0;
    for ( i = 0; i < n; i++)
    {
        if (users[i].role==1)
        {
            countAdmins=countAdmins+1;
        }
        
        if (users[i].state==1)
        {
            countBlocked++;
        }
        
        
    }
    printf("User statistics:\n");
    printf("Total number of users: %d\n",n);
    printf("Number of admins: %d\n",countAdmins);
    printf("Number of blocked users: %d\n",countBlocked);
    
}
//19
//function to save users to a file
//input : an array of users and the size
//output : save the users to a file named "users.txt"

void saveUsers(struct User users[], int n){
    int i;
    FILE *file;
    file = fopen("users.txt", "w");
    // 
    for ( i = 0; i < n; i++)
    {
        fprintf(file, "%s %s %d %d\n", users[i].name, users[i].password, users[i].role, users[i].state);
    }
    fclose(file);
    
}
//20
//function to load users from a file
//input : an array of users and the size
//output : load the users from a file named "users.txt"
void loadUsers(struct User users[], int n){
    int i;
    FILE *file;
    file = fopen("users.txt", "r");// open the file in read mode
    if (file == NULL) {
        // this for checking if the file invalid or non-existent address.
        // if the file is not found, it will return NULL
        // and we will print an error message
        printf("Error opening file!\n");
        return;
        // exit the function if the file cannot be opened directely
    }
    for ( i = 0; i < n; i++)
    {
        fscanf(file, "%s %s %d %d", users[i].name, users[i].password, &users[i].role, &users[i].state);
        //fscanf reads formatted input from a file
        //we read the name, password, role and state of the user
    }
    fclose(file);   
    //close the file after reading       
}
//===============================================================================================================================
//===========================CLI functions=========================================================================================
//===============================================================================================================================1
void _initUsers(){
    printf("Enter number of users to initialize: ");
    scanf("%d",&userCount);
    initUsers(users,userCount);
}
void _displayUsers(){
    displayUsers(users,userCount);
}
void _addUser(){
    addUser(users,userCount);
    userCount++;
}
void _deleteUser(){
    char name[20];
    printf("Enter the name of the user to delete: ");
    scanf("%s",name);
    deleteUser(users,userCount,name);
    userCount--;
}
void _changePassword(){
    char name[20];
    printf("Enter the name of the user to change password: ");
    scanf("%s",name);
    changePassword(users,userCount,name);
}
void _searchUser(){
    char name[20];
    printf("Enter the name to search:");
    scanf("%s",name);
    int index=searchUser(users,userCount,name);
    if (index!=-1)
    {
        printf("user found at index %d",index);
    }else{
        printf("user not found");
    }
    
}

void _checkLogin(){
    char name[20],pass[20];
    printf("Enter username:");
    scanf("%s",name);
    printf("Enter password:");
    scanf("%s",pass);
    if (checkLogin(users,userCount,name,pass))
    {
        printf("Login successful");
    }else{
        printf("Login failed");
    }       
    
}
void _strongPassword(){
    char pass[50];
    printf("Enter password to check:");
    scanf("%s",pass);
    if (strongPassword(pass))
    {
        printf("Password is strong");
    }else{
        printf("Password is weak");
    }       
    
}
void _blockUser(){
    char name[20];
    printf("Enter the name to block:");
    scanf("%s",name);
    blockUser(users,userCount,name);
}

void _unblockUser(){
    char name[20];
    printf("Enter the name to unblock:");
    scanf("%s",name);
    unblockUser(users,userCount,name);
}
void _changeRole(){
    int role;
    char name[20];
    printf("Enter the name to change role:");
    scanf("%s",name);
    printf("Enter the new role (0 user , 1 admin):");
    scanf("%d",&role);
    changeRole(users,userCount,name,role);
}
void _listAdmins(){
    listAdmins(users,userCount);
}
void _stringLength(){
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);
    printf("The length of the string is: %d",stringLength(str));
}
void _containsUppercase(){
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);
    if (containsUppercase(str))
    {
        printf("The string contains uppercase letters");
    }else{
        printf("The string does not contain uppercase letters");
    }       
    
}
void _containsLowercase(){
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);
    if (containsLowercase(str))
    {
        printf("The string contains lowercase letters");
    }else{
        printf("The string does not contain lowercase letters");
    }       
    
}
void _containsDigit(){
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);
    if (containsDigit(str))
    {
        printf("The string contains digits");
    }else{
        printf("The string does not contain digits");
    }       
    
}
void _containsSymbol(){
    char str[100];
    printf("Enter the string:");
    scanf("%s",str);
    if (containsSymbol(str))
    {
        printf("The string contains symbols");
    }else{
        printf("The string does not contain symbols");
    }       
    
}
void _userStatistics(){
    userStatistics(users,userCount);
}
void _saveUsers(){
    saveUsers(users,userCount);
    printf("Users saved successfully to users.txt");
}
void _loadUsers(){
    printf("Enter number of users to load:");
    scanf("%d",&userCount);
    loadUsers(users,userCount);
    printf("Users loaded successfully from users.txt\n");
    displayUsers(users,userCount);
}

