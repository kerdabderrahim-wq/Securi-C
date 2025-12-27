#ifndef LOG_H
#define LOG_H

struct Log{ 
  char user[20]; 
  char action[50]; 
  char date[20]; 
  char time[10]; 
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
void dailyConnections(struct Log logs[], int n);
float errorRate(struct Log logs[], int n);
void exportLogsCSV(struct Log logs[], int n);
void importLogsCSV(struct Log logs[], int *n);
void clearLogs(struct Log logs[], int n);
void recentLogs(struct Log logs[], int n);
void archiveLogs(struct Log logs[], int n);
void showTopErrors(struct Log logs[], int n);

// CLI wrapper functions
void _initLogs();
void _addLog();
void _displayLogs();
void _searchLogsByUser();
void _searchLogsByDate();
void _countErrorLogs();
void _countLoginLogs();
void _countBlockedLogs();
void _displayLogStats();
void _sortLogsByDate();
void _sortLogsByUser();
void _detectSuspiciousActivity();
void _dailyConnections();
void _errorRate();
void _exportLogsCSV();
void _importLogsCSV();
void _clearLogs();
void _recentLogs();
void _archiveLogs();
void _showTopErrors();

#endif
