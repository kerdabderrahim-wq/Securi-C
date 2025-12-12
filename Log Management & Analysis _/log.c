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

char* currentDateTime(){
    time_t now;
    time(&now);
    char* dt = ctime(&now);
    return dt;
}
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
void addLog(struct Log logs[], int n, char user[], char action[], int code){
    //shift logs to make space for new log at the beginning
    int i;
    for ( i = n-1; i >0 ; i--)
    {
        logs[i]=logs[i-1];
    }
    //add new log at the beginning
    struct Log newLog;
    strcpy(newLog.user,user);
    strcpy(newLog.action,action);
    strcpy(newLog.date,currentDate());
    strcpy(newLog.time,currentDateTime()+11); //skip date part
    newLog.code=code;
    logs[0]=newLog;
}
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
int countErrorLogs(struct Log logs[], int n){
    int i,count;
    count=0;
    for ( i = 0; i < n; i++)
    {
        if (logs[i].code==2)
        {
            count++;
        }
        
    }
    return count;
}
int countLoginLogs(struct Log logs[], int n){
    int i,count;
    count=0;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(logs[i].action,"login")==0)
        {
            count++;
        }
        
    }
    return count;
}
int countBlockedLogs(struct Log logs[], int n){
    int i,count;
    count=0;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(logs[i].action,"blocked")==0)
        {
            count++;
        }
        
    }
    return count;
}
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
void sortLogsByDate(struct Log logs[], int n){
    int i;
    struct Log  temp;
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
