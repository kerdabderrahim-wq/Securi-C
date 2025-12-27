#ifndef MATHS_H
#define MATHS_H
struct Matrix{
    int rows;
    int cols;
    int data[10][10];
};

int isEven(int a);
int isPrime(int a);
int gcd(int a,int b);
int lcm(int a,int b);
int power(int base,int exp);
int modExp(int base, int exp, int mod); 
int factorial(int n);
int sumDigits(int n);
int reverseNumber(int n);
int isPalindromeNumber(int n);
int sumDivisors(int n);
int isPerfectNumber(int n);
int isArmstrong(int n);
float randomNumber(int max , int min);    
int sumArray(int T[],int n);
float averageArray(int T[], int n);
int maxArray(int T[], int n);
int minArray(int T[], int n);
void sortAscending(int T[], int n); 
void displayMatrix(struct Matrix M);
void addMatrices(struct Matrix A, struct Matrix B, struct Matrix *C);
void  multiplyMatrices(struct Matrix A, struct Matrix B, struct Matrix *C);
void transposeMatrix(struct Matrix A, struct Matrix *T);
int determinant2x2(int A[2][2]) ;
int isSymmetric(struct Matrix M);
int isIdentity(struct Matrix M);
void inputNumber(int *n,char *msg);
void outputNumber(int n, char *msg);
void _isEven();
void _isPrime();
void _gcd();
void _lcm();
void _modExp();
void _factorial();
void _sumDigits();
void _reverseNumber();
void _isPalindromeNumber();
void _sumDivisors();
void _isPerfectNumber();
void _isArmstrong();
void _randomNumber();
void inputArray(int T[],int *n);
void outputArray(int T[],int n,char msg[]);
void _sumArray();
void _averageArray();
void _maxArray();
void _minArray();
void _sortAscending();
void inputMatrix(struct Matrix *M);
void _displayMatrix();
void _addMatrices();
void _multiplyMatrices();
void _transposeMatrix();
void _determinant2x2();
void _isSymmetric();
void _isIdentity();




#endif/* MATHS_H */