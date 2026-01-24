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
struct Log logs[100];
int logCount = 0;
char* currentDateTime();
char* currentDate();
//1
//Description : Initialize log entries
// inputs: logs array, number of logs
// outputs: none

void initLogs(struct Log logs[], int n){
    int i,valid;
    //adding sanity check 
    for ( i = 0; i < n; i++)
    {   
        printf("Log Entry %d:\n", i + 1);
        valid = 0;
        do {
            printf("Enter username: ");
            scanf(" %[^\n]", logs[i].user);

            // Check if the string contains a comma
            if (strchr(logs[i].user, ',') != NULL) {
                printf("Error: Input cannot contain a comma (,). Try again.\n");
                valid = 0;
            } else {
                valid = 1;
         }
        } while (!valid);

        valid = 0;
        do {
            printf("Enter action: ");
            scanf(" %[^\n]", logs[i].action);

            // Check if the string contains a comma
            if (strchr(logs[i].action, ',') != NULL) {
                printf("Error: Input cannot contain a comma (,). Try again.\n");
                valid = 0;
            } else {
                valid = 1;
            }
        } while (!valid);

        strcpy(logs[i].date,currentDate());
        strcpy(logs[i].time,currentDateTime());
        printf("Enter the code : ");
        while (scanf(" %d",&logs[i].code) != 1) {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }
        
    }
    
}

//extra function for get current date and time

char* currentDateTime(){
    time_t now;
    struct tm *local_time;
    char *buffer = (char*)malloc(6 * sizeof(char)); // HH:MM plus null terminator

    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        return NULL;
    }

    time(&now);
    local_time = localtime(&now);

    strftime(buffer, 6, "%H:%M", local_time);

    return buffer;
    
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
    for ( i = n; i >0 ; i--)
    {
        logs[i]=logs[i-1];
    }
    //we add it to the begining
    struct Log newLog;
    strcpy(newLog.user,user);
    strcpy(newLog.action,action);
    strcpy(newLog.date,currentDate());
    strcpy(newLog.time,currentDateTime());
    newLog.code=code;
    logs[0]=newLog;
}
//3
//Description : Display all log entries
// inputs: logs array, number of logs
// outputs: none
 void displayLogs(struct Log logs[], int n){
    int i;
    for ( i = 0; i<n; i++){
        printf("log %d: %s %s %s %s %d\n",i+1,logs[i].date,logs[i].user,logs[i].action,logs[i].time,logs[i].code);
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
        if (strcmp(logs[i].action,"login")==0){
        //compare strings
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
    //date is of the form  Sat Jan 24 so we can compare it as string
    // declaration of a flag to check if the array is sorted
    int isSorted;
    isSorted=1;
    for ( i = 0; i < n-1; i++){
        if (strcmp(logs[i].date,logs[i+1].date)>0){
            temp=logs[i];
            logs[i]=logs[i+1];
            logs[i+1]=temp;
            isSorted=0;
        }
    }
    if (isSorted==0){
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
    for ( i = 0; i < n-1; i++)
    {
    if (strcmp(logs[i].user,logs[i+1].user)>0){
        temp=logs[i];
        logs[i]=logs[i+1];
        logs[i+1]=temp;
        isSorted=0;
    }
    
}
if (isSorted==0){
        sortLogsByUser(logs,n);
}
}

int detectSuspiciousActivity(struct Log logs[], int n, char user[]){
    // Implementation: e.g., multiple failed logins
    int count = 0;
    for(int i=0; i<n; i++){
        if(strcmp(logs[i].user, user) == 0 && logs[i].code == 2){ // Error
            count++;
        }
    }
    return count > 3; // Suspicious if more than 3 errors
}


float errorRate(struct Log logs[], int n){
    if (n == 0){
        return 0.0;
    }
    return (float)countErrorLogs(logs,n)/n;

}
// i do *100 in the second version of the function to get percentage
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

void dailyConnections(struct Log logs[], int n){
    // Count logins per day (simplified: just print dates of logins)
    printf("Daily Connections:\n");
    for(int i=0; i<n; i++){
        if(strcmp(logs[i].action, "login") == 0){
            printf("%s: %s\n", logs[i].date, logs[i].user);
        }
    }
}


void exportLogsCSV(struct Log logs[], int n){
    FILE *f = fopen("logs.csv", "w");
    if(f == NULL){
        printf("Error opening file.\n");
        return;
    }
    fprintf(f, "User,Action,Date,Time,Code\n");
    for(int i=0; i<n; i++){
        fprintf(f, "%s,%s,%s,%s,%d\n", logs[i].user, logs[i].action, logs[i].date, logs[i].time, logs[i].code);
    }
    fclose(f);
}

void importLogsCSV(struct Log logs[], int *n){
    FILE *f = fopen("logs.csv", "r");
    if(f == NULL){
        printf("Error opening file.\n");
        return;
    }
    char buffer[1024];
    fgets(buffer, 1024, f); // skip header
    *n = 0;
    while(fgets(buffer, 1024, f)){
        sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%d", logs[*n].user, logs[*n].action, logs[*n].date, logs[*n].time, &logs[*n].code);
        (*n)++;
    }
    fclose(f);
}

void recentLogs(struct Log logs[], int n){
    // Display last 5 logs
    int start; 
    start= n > 5 ? n - 5 : 0;
    for(int i=start; i<n; i++){
        printf("Log %d: %s %s %s\n", i+1, logs[i].date, logs[i].user, logs[i].action);
    }
}

void archiveLogs(struct Log logs[], int n){
    // Save to archive file
    FILE *f = fopen("logs_archive.txt", "a");
    if(f == NULL){
        printf("Error opening file.\n");
        return;
    }
    for(int i=0; i<n; i++){
        fprintf(f, "%s %s %s %s %d\n", logs[i].user, logs[i].action, logs[i].date, logs[i].time, logs[i].code);
    }
    fclose(f);
    printf("Logs archived.\n");
}


void showTopErrors(struct Log logs[], int n){
    // Simplified: show users with most errors
    printf("Top Errors:\n");
    for(int i=0; i<n; i++){
        if(logs[i].code == 2){
            printf("%s: %s\n", logs[i].user, logs[i].action);
        }
    }
}







//============================================================================================================================
// extra functions for the cli
//========================================================================================================================================

void _initLogs(){
    printf("Enter number of logs to initialize: ");
    while (scanf("%d",&logCount) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    initLogs(logs,logCount);
    printf("Logs initialized successfully.\n");
}
void _addLog(){
    char user[20],action[50];
    int code,valid;
    valid=0;
    do{
        printf("Enter username: ");
        scanf(" %[^\n]", user);

        // Check if the string contains a comma
        if (strchr(user, ',') != NULL) {
            printf("Error: Input cannot contain a comma (,). Try again.\n");
            valid = 0;
        } else {
            valid = 1;
        }
    } while (!valid);
    valid=0;
    do{
        printf("Enter action: ");
        scanf(" %[^\n]", action);

        // Check if the string contains a comma
        if (strchr(action, ',') != NULL) {
            printf("Error: Input cannot contain a comma (,). Try again.\n");
            valid = 0;
        } else {
            valid = 1;
        }
    } while (!valid);

    printf("Enter code (0: info, 1: warning, 2: error): ");
    while (scanf("%d",&code) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    addLog(logs,logCount,user,action,code);
    logCount++;
    printf("Log added successfully.\n");
}
void _displayLogs(){
    displayLogs(logs,logCount);
}
void _searchLogsByUser(){
    char user[20];
    printf("Enter number of logs: ");
    while (scanf("%d",&logCount) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    printf("Enter username to search: ");
    scanf("%s",user);
    searchLogsByUser(logs,logCount,user);
}
void _searchLogsByDate(){

    char date[11];
    printf("Enter date to search In the form of (YYYY-MM-DD): ");
    scanf("%s",date);
    searchLogsByDate(logs,logCount,date);
}
void _countErrorLogs(){
    int count;
    count=countErrorLogs(logs,logCount);
    printf("Number of error logs: %d\n",count);
}
void _countLoginLogs(){
    int count;
    count=countLoginLogs(logs,logCount);
    printf("Number of login logs: %d\n",count);
}
void _countBlockedLogs(){
    int count;
    count=countBlockedLogs(logs,logCount);
    printf("Number of blocked logs: %d\n",count);
}
void _displayLogStats(){
    displayLogStats(logs,logCount);
}
void _sortLogsByDate(){
    sortLogsByDate(logs,logCount);
    printf("Logs sorted by date successfully\n");
}   
void _sortLogsByUser(){
    sortLogsByUser(logs,logCount);
    printf("Logs sorted by user successfully\n");
}

void _detectSuspiciousActivity(){
    char user[20];
    printf("Enter username to check: ");
    scanf("%s", user);
    if(detectSuspiciousActivity(logs, logCount, user)){
        printf("Suspicious activity detected for user %s!\n", user);
    } else {
        printf("No suspicious activity detected for user %s.\n", user);
    }
}

void _dailyConnections(){
    dailyConnections(logs, logCount);
}


void _errorRate(){
    float rate;
    rate=errorRate(logs,logCount);
    printf("Error Rate: %.2f%%\n",rate*100);
}
void _exportLogsCSV(){
    exportLogsCSV(logs, logCount);
    printf("Logs exported to logs.csv\n");
}
void _importLogsCSV(){
    importLogsCSV(logs, &logCount);
    printf("%d Logs imported from logs.csv\n", logCount);
}
void _clearLogs(){
    clearLogs(logs,logCount);
    logCount = 0;
    printf("Logs cleared successfully\n");
}
void _recentLogs(){
    recentLogs(logs, logCount);
}
void _archiveLogs(){
    archiveLogs(logs, logCount);
}
void _showTopErrors(){
    showTopErrors(logs, logCount);
}

