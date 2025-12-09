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

    for(i=0;i<n;i++)
    {
        printf("Enter the user %d name :",i+1);
        scanf("%s",users[i].name);
        //we use %s to read strings
        printf("Enter the user %d password :",i+1);
        scanf("%s",users[i].password);
        printf("Enter the user %d role (0 user , 1 admin) :",i+1);
        scanf("%d",&users[i].role);
        if (users[i].role!=0  && users[i].role!=1)
        {
            printf("error");
            break;
            
        }
        
        printf("Enter the user %d state (0: active, 1: blocked ) :",i+1);
        scanf("%d",&users[i].state);
        if (users[i].state!=0  && users[i].state!=1)
        {
            printf("error");
            break;
            
        }






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
    while(searchUser(users,new_user.name)!=-1){
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
    int index,reached;
    reached=0;
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
    int i,index;
    char passwd[10];
    //ask for the current password
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
        if (strcmp(users[index].password,pass))
        {
            return 1;
        }
        
    }
    return 0;
}

int main (){
    int n;
    struct User hello[199];
    initUsers(hello,3);
    printf("%d",checkLogin(hello,3,"karim","kariim"));
    return 0;
}