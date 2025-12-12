#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Log{ 
  char user[20]; 
  char action[50]; 
  char date[20]; 
  char time[10]; 
  int code;  // 0 info, 1 warning, 2 error 
 };
//1
//Description : Initialize log entries
// inputs: logs array, number of logs
// outputs: none

void initLogs(struct Log logs[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {   
        printf("Log Entry %d:\n", i + 1);
        printf("Enter the username : ");
        scanf("%s",logs[i].user);
        printf("Enter the action : ");
        scanf("%s",logs[i].action);
        printf("Enter the date : ");
        scanf("%s",logs[i].date);
        printf("Enter the time : ");
        scanf(" %s",logs[i].time);
        printf("Enter the code : ");
        scanf(" %d",&logs[i].code);
        
    }
    
}

//extra function for get current date and time

char* currentDateTime(){
    time_t now;
    time(&now);
    char* dt = ctime(&now);
    return dt;
}
//extra function for get current date
char* currentDate(){
    time_t now;
    time(&now);
    char* dt=ctime(&now);
    //extract date part
    static char date[11];
    strncpy(date,dt,10);
    date[10]='\0';
    return date;

}
//2
//Description : Add a new log entry
// inputs: logs array, number of logs, user, action, code
// outputs: none
void addLog(struct Log logs[], int n, char user[], char action[], int code){
    
    int i;
    for ( i = n-1; i >0 ; i--)
    {
        logs[i]=logs[i-1];
    }
    
    struct Log newLog;
    strcpy(newLog.user,user);
    strcpy(newLog.action,action);
    strcpy(newLog.date,currentDate());
    newLog.code=code;
    logs[0]=newLog;
}
//3
//Description : Display all log entries
// inputs: logs array, number of logs
// outputs: none
 void displayLogs(struct Log logs[], int n){
    int i;
    for ( i = 0; i<n; i++)
    {
        printf("Log Entry %d:\n", i + 1);
        printf("User: %s\n",logs[i].user);
        printf("Action: %s\n",logs[i].action);
        printf("Date: %s\n",logs[i].date);
        printf("Time: %s\n",logs[i].time);
        printf("Code: %d\n",logs[i].code);
        printf("===========================\n");
    }
    
 }
 //4
//Description : Search logs by user
// inputs: logs array, number of logs, user
// outputs: none
void searchLogsByUser(struct Log logs[], int n, char user[]){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(user,logs[i].user)==0)
        //0 mean equal
        {
            printf("Log Entry %d:\n", i + 1);
            printf("User: %s\n",logs[i].user);
            printf("Action: %s\n",logs[i].action);
            printf("Date: %s\n",logs[i].date);
            printf("Time: %s\n",logs[i].time);
            printf("Code: %d\n",logs[i].code);
            printf("===========================\n");
        }
        
    }
    
}
//5
//Description : Search logs by date
// inputs: logs array, number of logs, date
// outputs: none
void searchLogsByDate(struct Log logs[], int n, char date[]){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(date,logs[i].date)==0)
        //0 mean equal
        {
            printf("Log Entry %d:\n", i + 1);
            printf("User: %s\n",logs[i].user);
            printf("Action: %s\n",logs[i].action);
            printf("Date: %s\n",logs[i].date);
            printf("Time: %s\n",logs[i].time);
            printf("Code: %d\n",logs[i].code);
            printf("===========================\n");
        }
        
    }
    
}
//6
//Description : Count error logs
// inputs: logs array, number of logs
// outputs: number of error logs
int countErrorLogs(struct Log logs[], int n){
    int i,count;
    count=0;
    for ( i = 0; i < n; i++)
    {
        if (logs[i].code==2)
        //2 mean error
        {
            count=count+1;
        }
        
    }
    return count;
}
//7
//Description : Count login logs
// inputs: logs array, number of logs
// outputs: number of login logs
int countLoginLogs(struct Log logs[], int n){
    int i,count;
    count=0;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(logs[i].action,"login")==0)
        //compare strings
        {
            count++;
        }
        
    }
    return count;
}
//8
//Description : Count blocked logs
// inputs: logs array, number of logs
// outputs: number of blocked logs
int countBlockedLogs(struct Log logs[], int n){
    int i,count;
    count=0;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(logs[i].action,"blocked")==0)
        //compare strings 0 means equal
        {
            count++;
        }
        
    }
    return count;
}
//9
//Description : Display log statistics
//inputs: logs array, number of logs
//outputs: none
void displayLogStats(struct Log logs[], int n){
    int errorCount,loginCount,blockedCount;
    errorCount=countErrorLogs(logs,n);
    loginCount=countLoginLogs(logs,n);
    blockedCount=countBlockedLogs(logs,n);
    printf("Total Logs: %d\n",n);
    printf("Error Logs: %d\n",errorCount);
    printf("Login Logs: %d\n",loginCount);
    printf("Blocked Logs: %d\n",blockedCount);
}
//10
//Description : Sort logs by date
//inputs: logs array, number of logs
//outputs: none
void sortLogsByDate(struct Log logs[], int n){
    int i;
    struct Log  temp;
    // declaration of a flag to check if the array is sorted
    int isSorted;
    isSorted=1;
    for ( i = 0; i < n; i++)
    {
    if (logs[i].date>logs[i+1].date)
    {
        temp=logs[i];
        logs[i]=logs[i+1];
        logs[i+1]=temp;
        isSorted=0;
    }
    
}
 if (isSorted=0)
    {
        sortLogsByDate(logs,n);
    }
}
//11
//Description : Sort logs by user
//inputs: logs array, number of logs
//outputs: none
void sortLogsByUser(struct Log logs[], int n){
    int i;
    struct Log  temp;
    int isSorted;
    isSorted=1;
    for ( i = 0; i < n; i++)
    {
    if (strcmp(logs[i].user,logs[i+1].user)>0)
    {
        temp=logs[i];
        logs[i]=logs[i+1];
        logs[i+1]=temp;
        isSorted=0;
    }
    
}
if (isSorted=0){
        sortLogsByUser(logs,n);
}
}
int detectSuspiciousActivity(struct Log logs[], int n, char user[]){

}

float errorRate(struct Log logs[], int n){
    return (float)countErrorLogs(logs,n)/n;

}
// i do *100 in the second vertion of the function to get percentage
// extra function to clear logs
void clearLogs(struct Log logs[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        strcpy(logs[i].user,"");
        strcpy(logs[i].action,"");
        strcpy(logs[i].date,"");
        strcpy(logs[i].time,"");
        logs[i].code=0;
    }
}

int main(){
    //test after log management
    struct Log logs[100];
    int n=0;
    //test error rate with predefined logs
    for (int i = 0; i < 5; i++)
    {
        strcpy(logs[i].user,"user1");
        strcpy(logs[i].action,"action1");
        strcpy(logs[i].date,"2024-01-01");
        strcpy(logs[i].time,"12:00:00");
        if (i%2==0)
        {
            logs[i].code=2; //error
        }else{
            logs[i].code=0; //info
        }
    }
    n=5;
    displayLogs(logs,n);
    float rate=errorRate(logs,n);
    printf("Error Rate: %.2f%%\n",rate*100);
    return 0;
}

//============================================================================================================================
// extra functions for the cli
//========================================================================================================================================

void _initLogs(){
    struct Log logs[100];
    int n;
    printf("Enter number of logs to initialize: ");
    scanf("%d",&n);
    initLogs(logs,n);
    printf("Logs initialized successfully.\n");
}
void _addLog(){
    struct Log logs[100];
    int n;
    char user[20],action[50];
    int code;
    printf("Enter current number of logs: ");
    scanf("%d",&n);
    printf("Enter username: ");
    scanf("%s",user);
    printf("Enter action: ");
    scanf("%s",action);
    printf("Enter code (0: info, 1: warning, 2: error): ");
    scanf("%d",&code);
    addLog(logs,n,user,action,code);
    printf("Log added successfully.\n");
}
void _displayLogs(){
    struct Log logs[100];
    int n;
    printf("Enter number of logs to display: ");
    scanf("%d",&n);
    displayLogs(logs,n);
}
void _searchLogsByUser(){
    struct Log logs[100];
    int n;
    char user[20];
    printf("Enter number of logs: ");
    scanf("%d",&n);
    printf("Enter username to search: ");
    scanf("%s",user);
    searchLogsByUser(logs,n,user);
}
void _searchLogsByDate(){
    struct Log logs[100];
    int n;
    char date[11];
    printf("Enter number of logs: ");
    scanf("%d",&n);
    printf("Enter date to search In the form of (YYYY-MM-DD): ");
    scanf("%s",date);
    searchLogsByDate(logs,n,date);
}
void _countErrorLogs(){
    struct Log logs[100];
    int n,count;
    printf("Enter number of logs: ");
    scanf("%d",&n);
    count=countErrorLogs(logs,n);
    printf("Number of error logs: %d\n",count);
}
void _countLoginLogs(){
    struct Log logs[100];
    int n,count;
    printf("Enter number of logs: ");
    scanf("%d",&n);
    count=countLoginLogs(logs,n);
    printf("Number of login logs: %d\n",count);
}
void _countBlockedLogs(){
    struct Log logs[100];
    int n,count;
    printf("Enter number of logs: ");
    scanf("%d",&n);
    count=countBlockedLogs(logs,n);
    printf("Number of blocked logs: %d\n",count);
}
void _displayLogStats(){
    struct Log logs[100];
    int n;
    printf("Enter number of logs: ");
    scanf("%d",&n);
    displayLogStats(logs,n);
}
void _sortLogsByDate(){
    struct Log logs[100];
    int n;
    printf("Enter number of logs: ");
    scanf("%d",&n);
    sortLogsByDate(logs,n);
    printf("Logs sorted by date successfully\n");
}   
void _sortLogsByUser(){
    struct Log logs[100];
    int n;
    printf("Enter number of logs: ");
    scanf("%d",&n);
    sortLogsByUser(logs,n);
    printf("Logs sorted by user successfully\n");
}
/*=============================================================================================================================*/



























































void _errorRate(){
    struct Log logs[100];
    int n;
    float rate;
    printf("Enter number of logs: ");
    scanf("%d",&n);
    rate=errorRate(logs,n);
    printf("Error Rate: %.2f \n",rate*100);
}
void _clearLogs(){
    struct Log logs[100];
    int n;
    printf("Enter number of logs to clear: ");
    scanf("%d",&n);
    clearLogs(logs,n);
    printf("Logs cleared successfully\n");
}
