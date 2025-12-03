struct User{ 
    char name[20]; 
    char password[20]; 
    int role;   // 0: user, 1: admin 
    int state;  // 0: active, 1: blocked 
};
//function to initialize an array of users

void initUsers(struct User users[], int n){
    int i; 
    struct User admin={"admin","securi-c",1,0};
    users[0]=admin;
    //the first user always the admin
    for ( i = 1; i < n ;i++){
        
    }
        
    
    
}