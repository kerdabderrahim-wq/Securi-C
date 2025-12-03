#include <stdio.h>
#include <string.h>
struct User{ 
    char name[20]; 
    char password[20]; 
    int role;   // 0: user, 1: admin 
    int state;  // 0: active, 1: blocked 
};
//1
//function to initialize an array of users
//input : the number of users 
//output : an initialized list of users 
void initUsers(struct User users[], int n){
    int i;
     //the default admin credentials
    struct User admin={"admin","securi-c",1,0};
    //the first user is the admin
    users[0]=admin;  
    //default user credentials
    for ( i = 1; i < n ;i++){
            struct User user={"user","password",0,0};
            sprintf(user.name, "user%d", i);
            users[i]=user;
            //initialize other users with default credentials
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
        
            printf(users[i].name);
            //display the username
            printf("  admin : ");
            printf("%d",users[i].role);
            //display the role
            printf("   active : ");
            printf("%d",users[i].state);
            //display the state
            printf("\n");
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
    //%s means read a string until a whitespace is encountered
    printf("Enter password: ");
    scanf("%s", new_user.password);
    new_user.role = 0; 
    // default role is user
    new_user.state = 0;
     // default state is active
    users[n] = new_user; 
    // add the new user at the end of the list
}

void deleteUser(struct User users[], int n, char name[]){
    int i,reached;
    reached=0;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(users[i].name,name)==0){
            
            struct User empty_user={"","",0,0};
            users[i]=empty_user;
        }
    }
    

}
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
void changePassword(struct User users[], int n, char name[]){
    int i,index;
    char passwd[10];
    index=searchUser(users,n,name);
    if (index!=-1)
    {
        printf("please enter your password");
        scanf("%s",&passwd);
        if (strcmp(passwd,users[index].password)==0)
        {
            printf("please enter your new paaword");
            scanf("%d",&users[index].password);
            printf("password changed seccusfully");
        }
        else{
            printf("wrong password please try again");
        }
    }else{
        printf("user not found");
    }
    
}
int checkLogin(struct User users[], int n, char name[], char pass[]){
    int ;
}
int main (){
    int n;
    struct User users[50];
    //for testing purposes
    initUsers(users,3);
    //initialize 10 users
    //addUser(users,3);
    addUser(users,3);
    //deleteUser(users,3,"user1");*/
    //printf("%d \n",searchUser(users,4,"karim"));
    changePassword(users , 4,"karim");
    //add a new user
    //displayUsers(users,3);
    //display the initialized users

    return 0;
}