struct Log{ 
  char user[20]; 
  char action[50]; 
  char date[11]; // Format: YYYY-MM-DD
  char time[9];  // Format: HH:MM:SS
  int code; // 0: Login, 1: Error, 2: Blocked
};
void initLogs(struct Log logs[], int n); 
void addLog(struct Log logs[], int n, char user[], char action[], int code);
void displayLogs(struct Log logs[], int n);
void searchLogsByUser(struct Log logs[], int n, char user[]);
void searchLogsByDate(struct Log logs[], int n, char date[]);
int countErrorLogs(struct Log logs[], int n);
int countLoginLogs(struct Log logs[], int n);
int countBlockedLogs(struct Log logs[], int n);
void displayLogStats(struct Log logs[], int n);
void sortLogsByDate(struct Log logs[], int n);
void sortLogsByUser(struct Log logs[], int n);
int detectSuspiciousActivity(struct Log logs[], int n, char user[]);
