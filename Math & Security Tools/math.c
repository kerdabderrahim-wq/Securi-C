#include <stdio.h>
#include <time.h>
#include <limits.h>
struct Matrix{ 
    int data[10][10]; 
    int n, p; 
};

//1
/*
description: a function that return 1 or 0 if the number is even or odd respectively
input : an integer a
output : 0 if odd or 1 if even 
*/

int isEven(int a){
    if (a%2==0)
    {
        return 1; //is  even//
    }else{
        return 0;//is odd//
    }
    
}
//2
/*
description: a function that return 1 or 0 if the number is prime or not  respectively
input : an integer a
output : 1 if prime or 0 otherwise

*/
int isPrime(int a){
    if (a<=1)
    //there is no prime number less than or equal to 1
    //1 is not prime//
    {
        return 0;
    }
    for (int i = 2; i*i <= a; i++)
    {
        if (a%i==0)
        {
            return 0;
        }
        
    }
    
    return 1;
    
}
int abs(int n){
    if(n<0){
        return -n;
    }
    return n;
}
//3
/*
description: a function that return the gcd of two integer 
input : two integers a and b
output : the gcd

*/
int gcd(int a,int b){
    int temp;
    while(b!=0){
    temp = b;
    b=a % b;
    a=temp;
}
        return a;
}
//4
/*
description: a function that return the lcm of two integer 
input : two integers a and b
output : the lsm

*/
int lcm(int a,int b){
    return (a*b)/gcd(a,b);


}
 //5
//description this function is needed for the modExp function it calculate base to the exp power
//input :the base and the exp
//output : base^exp
int power(int base,int exp){
    int res,i;
    res=1;
    for ( i = 0; i < exp; i++){
        res=res*base;
    }
    return res;

}

//description Performs modular exponentiation
//input :the base and the exp and mod
//output : base^exp MOD mod
int modExp(int base, int exp, int mod){
    return (power(base%mod,exp))%mod;
    // try 1 10 1000//
}




//6
//description factorial function
//input : an integer n
//output : n!
int factorial(int n){
    int result,i;
    result=1;
    for ( i = 1; i <= n; i++)
    {
        result=result*i;


    }
    
    return result;
}

//7
//description sum of digits function
//input : an integer n
//output : sum of digits of n
int sumDigits(int n){
    int sum_dig,current_dig;
    sum_dig=0;

    while (n>0)
    {
        current_dig=n%10;
        sum_dig = sum_dig +current_dig;
        n=n/10;
    }
    return sum_dig;
    
}



//8
//description reverse number function
//input : an integer n  
//output : the reverse of n
int reverseNumber(int n){
    int rev , c_dig,sign;
    rev=0;
    sign=n/abs(n);
    n=abs(n);
    while (n>0)
    {
        c_dig=n%10;
        rev=rev*10+c_dig;
        n=n/10;
    }
    return sign*rev;
    

}

//9
//description palindrome function
//input : an integer n  
//output : 1 if n is palindrome 0 otherwise
int isPalindromeNumber(int n){
    return reverseNumber(n)==n;    
}



//10
//description sum of divisors function
//input : an integer n
//output : sum of divisors of n
int sumDivisors(int n){
    int s_div,i;
    s_div=0;


    if (n<0)
    {
        return 0;
    }
    
    for(i=1;i<=n/2;i++){
        if (n % i ==0)
        {
            s_div=s_div+i;
        }
            
    }
    
    return s_div;
}
//11
//description perfect number function
//input : an integer n
//output : 1 if n is perfect number 0 otherwise
int isPerfectNumber(int n){
    return (n==sumDivisors(n));
}

//12
//description armstrong number function
//input : an integer n
//output : 1 if n is armstrong number 0 otherwise
int isArmstrong(int n){
    int i,temp_n_1,temp_n_2,num_dig,current_dig,power,res;
    num_dig=0;
    temp_n_1=n;
    temp_n_2=n;
    res=0;
    //armstrong number : 𝑛=153 → 1³ + 5³ + 3³ = 153.
    while (temp_n_2>0)
    {
        num_dig = num_dig +1;
        temp_n_2=temp_n_2/10;
    }
    
    while (n>0)
    {
        power=1;
        current_dig=n%10;
    for ( i = 1; i <= num_dig; i++)
    {
        power=power*current_dig;
    }
    res=res+power;
    
    n=n/10;
    }

    if (temp_n_1==res)
    {
        return 1;
    }else{
        return 0;
    }
}



//13
//description random number function
//input : max and min values
//output : a random float number between min and max
float randomNumber(int max , int min){
    float now;
    //we can use the time function from the time library
    now=time(NULL)%60;  
    //we must add null as minimal argument 
    now=now/60;  
    //time between 0 60 because in seconds
    return (now*(max-min)+min);
}

//14
//description : sum of array function
//input : an array T of n integers
//output : sum of the integers in T
int sumArray(int T[],int n){
    int res,i;
    res=0;
    for(i=0;i<n;i++){
        res=res+T[i];  
        //we can use [] to access the i-th number of the T array,
        // then add it to the sum 
    }
    return res;

}

    


//15
//description average of array function
//input : an array T of n integers
//output : average of the integers in T
float averageArray(int T[], int n){
    return (float)sumArray(T,n)/n;
    //we cast the sum to float to avoid integer division so with float be division of float /float //

}
//16
//description maximum of array function
//input : an array T of n integers
//output : maximum of the integers in T
int maxArray(int T[], int n) {
    int i,max;
    max=T[0];
    for ( i = 0; i < n; i++)
    {
        if (T[i]>max)
        {
        max=T[i];
        }
    }
    return max;
    
    
}

//17
//minimum of array function
//input : an array T of n integers
//output : minimum of the integers in T
int minArray(int T[], int n) {
    int i,min;
    min=T[0] ;
    for ( i = 0; i < n; i++)
    {
        if (T[i]<min)
        {
        min=T[i];
        }
    }
    return min;
    
    
}
//18
//description sorting array in ascending order function
//input : an array T of n integers
//output : the array T sorted in ascending order
void sortAscending(int T[], int n){
    int i,isSorted,tmp;
    isSorted=0;
    while (!isSorted){
        isSorted=1;
        for(i = 0; i <n-1; i++){
            if(T[i]>T[i+1]){
                tmp=T[i];
                T[i]=T[i+1];
                T[i+1]=tmp;
                isSorted=0;
            }
        }
    }
}
//19
//display matrix function
void displayMatrix(struct Matrix M){
    int i,j;
    for ( i = 0; i < M.n; i++){
        //for each row//
        for (j = 0; j <M.p; j++){
            //for each element in the matrix//
            printf("%d",M.data[i][j]);
            //print the element//
                if (j<M.p-1)
                {
                    printf(",");
                }
                
            

        }
        

        printf("\n");
    }
    
}
//20
//matrix addition function
//input : two matrices A and B of same dimensions n x p
//output : matrix C which is the addition of A and B
void addMatrices(struct Matrix A, struct Matrix B, struct Matrix *C){
    int i,j;
    C->n=A.n;
    C->p=A.p;
    for ( i = 0; i < A.n; i++)
    {
        for ( j = 0; j < A.p; j++)
        {
            C->data[i][j]=A.data[i][j]+B.data[i][j];
            //we use -> to access the data of the matrix C because C is a pointer//
        }
    }
    

}
//21
//matrix multiplication function
//input : two matrices A and B of same dimensions n x p
//output : matrix C which is the multiplication of A and B
void multiplyMatrices(struct Matrix A, struct Matrix B, struct Matrix *C) {
    int i, j, k;
    C->n = A.n;
    C->p = B.p;

    
    // A is (n x m), B is (m x p), Result C is (n x p)
    for (i = 0; i < A.n; i++) {           // Loop through rows of A
        for (j = 0; j < B.p; j++) {       // Loop through columns of B
            
            C->data[i][j] = 0;            // 1. Initialize the cell to 0
            
            for (k = 0; k < A.p; k++) {   // 2. The "inner" dimension loop
                // 3. Add to the sum of products
                C->data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
}   
//22
//matrix transpose function 
//input : a matrix A of dimensions n x p
//output : matrix T which is the transpose of A

void transposeMatrix(struct Matrix A, struct Matrix *T){
    int i,j;
    T->n=A.p;
    T->p=A.n;
    for ( i = 0; i < A.n; i++)
    {
        for ( j = 0; j <A.p ; j++)
        {
            T->data[j][i]=A.data[i][j];
            // we use -> to access the data of the matrix T because T is a pointer//    
        }
    }
}
//23
//2x2 matrix determinant function
//input : a 2x2 matrix A
//output : determinant of A

int determinant2x2(int A[2][2]) {
    return A[0][0]*A[1][1]-A[1][0]*A[0][1];
    //ad-bc in the matrix//
}
//24
//symmetric matrix test function
//input : a matrix M of dimensions n x p
//output : 1 if M is symmetric 0 otherwise  
int isSymmetric(struct Matrix M){
    struct Matrix T;
    transposeMatrix(M,&T);
    for (int i = 0; i < M.n; i++){
        for (int j = 0; j < M.p; j++){
            
            if (M.data[i][j]!=T.data[i][j]){
                
                return 0;
            }
        }
    }
    return 1;
}
//25
//identity matrix test function
//input : a matrix M of dimensions n x p
//output : 1 if M is identity 0 otherwise
int isIdentity(struct Matrix M){
    int i,j;
    for (i = 0; i < M.n; i++){
        for (j = 0; j < M.p; j++){
            if ((j==i && M.data[i][j]!=1)||((j!=i && M.data[i][j]!=0))){
                //if diagonal element not 1 or non diagonal element not 0//
                return 0;
            }
        }
    }
    return 1;
}

//============================================================================================================
//Extra procedures needed for the command interface
//============================================================================================================
void inputNumber(int *n,char *msg){
    printf(msg);
    while (scanf("%d",n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    //* with & cancel out //
}
void outputNumber(int n, char *msg){
    printf("%s %d\n",msg,n);
}
void _isEven(){
    int n;
    inputNumber(&n, "Enter a number : ");
    if(isEven(n)){
        //one represent true and 0 represent false 
        printf("The number is even");
    }else{
        printf("The number is odd");
    }
}
void _isPrime(){
    int n;
    inputNumber(&n,"Enter a number : ");
    if(isPrime(n)){
        printf("The number is prime");
    }else{
        printf("The number is not prime");
    }
}
void _gcd(){
    int a,b;
    inputNumber(&a,"Enter the first number : ");
    inputNumber(&b,"Enter the second number : ");
    outputNumber(gcd(abs(a),abs(b)),"The gcd is :");
}

void _lcm(){
    int a,b;
    inputNumber(&a,"Enter the first number : ");
    inputNumber(&b,"Enter the second number : ");
    outputNumber(lcm(a,b),"The lcm is :");
}
void _modExp(){
    int base,exp,mod;
    inputNumber(&base,"Enter the base : ");
    inputNumber(&exp,"Enter the exp : ");
    inputNumber(&mod,"Enter the mod : ");
    outputNumber(modExp(base,exp,mod),"The modular exponentiation result is :");
}
void _factorial(){
    int n;
    do{
        inputNumber(&n,"Enter a non-negative integer : ");
    }while(n<0);
    outputNumber(factorial(n),"The factorial is :");

}
void _sumDigits(){
    int n;
    inputNumber(&n,"Enter a number : ");
    outputNumber(sumDigits(abs(n)),"The sum of digits is :");
}
void _reverseNumber(){
    int n;
    inputNumber(&n,"Enter a number : ");
    outputNumber(reverseNumber(n),"The reverse number is :");
}
void _isPalindromeNumber(){
    int n;
    inputNumber(&n,"Enter a number : ");
    if(isPalindromeNumber(n)){
        printf("The number is a palindrome");
    }else{
        printf("The number is not a palindrome");
    }
}
void _sumDivisors(){
    int n;
    inputNumber(&n,"Enter a number : ");
    outputNumber(sumDivisors(abs(n)),"The sum of divisors is :");
}
void _isPerfectNumber(){
    int n;
    inputNumber(&n,"Enter a number : ");
    if(isPerfectNumber(n)){
        printf("The number is a perfect number");
    }else{
        printf("The number is not a perfect number");
    }
}

void _isArmstrong(){
    int n;
    inputNumber(&n,"Enter the number :");
    if (isArmstrong(n))
    {
        printf("The number is armstrong");
    }
    else{
        printf("The number is not armstrong");
    }

}
void _randomNumber(){
    int min , max;
    inputNumber(&min,"Enter the min value : ");
    inputNumber(&max,"Enter the max value : ");
    printf("The random number is : %f\n",randomNumber(max,min));
}



void inputArray(int T[],int *n){
    int i,temp;
    printf("Enter the number of  elements of array : ");
    while (scanf("%d",n) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < *n; i++)
    {   
        printf("Enter the number %d element : ",i+1);
        while (scanf("%d",&temp) != 1) {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }
        T[i]=temp;
    }
    
}
void outputArray(int T[],int n,char msg[]){
    int i;
    printf(msg);
        for ( i = 0; i < n-1; i++)
    {   
        printf("%d,",T[i]);
        
    }
    printf("%d",T[n-1]);
}


void _sumArray(){
    int T[100],n;
    inputArray(T,&n);
    outputNumber(sumArray(T,n),"The sum is : ");

}

void _averageArray(){
    int T[100],n;
    inputArray(T,&n);
    if(n!=0){
        printf("The average is : %f\n",averageArray(T,n));
        //we dont use output number because it works only with integers so we use printf
    }else{
        printf("Empty!!");
    }
}
void _maxArray(){
    int T[100],n;
    inputArray(T,&n);
    outputNumber(maxArray(T,n),"The max of the array is : ");
}
void _minArray(){
    int T[100],n;
    inputArray(T,&n);
    outputNumber(minArray(T,n),"The min of the array is : ");
}
void _sortAscending(){
    int T[100],n;
    inputArray(T,&n);
    sortAscending(T,n);
    outputArray(T,n,"The sorted array in ascending order is : ");
    printf("\n");
}
void inputMatrix(struct Matrix *M){
    int i,j;
    printf("Enter the number of rows : ");
    while (scanf("%d",&(M->n)) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    printf("Enter the number of columns : ");
    while (scanf("%d",&(M->p)) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    for ( i = 0; i < M->n; i++)
    {
        for ( j = 0; j < M->p; j++)
        {
            printf("Enter element [%d][%d] : ",i,j);
            while (scanf("%d",&(M->data[i][j])) != 1) {
                printf("Invalid input. Please enter a number: ");
                while (getchar() != '\n');
            }
        }
        
    }
}
void _displayMatrix(){
    struct Matrix M;
    inputMatrix(&M);
    displayMatrix(M);
}
void _addMatrices(){
    struct Matrix A,B,C;
    printf("Input matrix A : \n");
    inputMatrix(&A);
    printf("Input matrix B : \n");
    inputMatrix(&B);
    if(A.n==B.n && A.p==B.p){
        addMatrices(A,B,&C);
        printf("The result of addition is : \n");
        displayMatrix(C);
    }else{
        printf("You cannot add them since they don't have same number of rows and columns : \n");
    }
}
void _multiplyMatrices(){
    struct Matrix A,B,C;
    printf("Input matrix A : \n");
    inputMatrix(&A);
    printf("Input matrix B : \n");
    inputMatrix(&B);
    if(A.p==B.n){
        multiplyMatrices(A,B,&C);
        printf("The result of multiplication is : \n");
        displayMatrix(C);
    }else{
        printf("You cannot multiply these two matrices in that order : \n");
    }
}
void _transposeMatrix(){
    struct Matrix A,T;
    printf("Input matrix A : \n");
    inputMatrix(&A);
    transposeMatrix(A,&T);
    printf("The transpose of matrix A is : \n");
    displayMatrix(T);
}
void _determinant2x2(){
    int A[2][2];
    printf("Enter element [0][0] : ");
    while (scanf("%d",&A[0][0]) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    printf("Enter element [0][1] : ");
    while (scanf("%d",&A[0][1]) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    printf("Enter element [1][0] : ");
    while (scanf("%d",&A[1][0]) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    printf("Enter element [1][1] : ");
    while (scanf("%d",&A[1][1]) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
    printf("The determinant is : %d\n",determinant2x2(A));
}

void _isSymmetric(){
    struct Matrix M;
    inputMatrix(&M);
    if (isSymmetric(M)){
        printf("The matrix is symmetric\n");
    }else{
        printf("The matrix is not symmetric\n");
    }
}
void _isIdentity(){
    struct Matrix M;
    inputMatrix(&M);
    if (isIdentity(M)){
        printf("The matrix is identity\n");
    }else{
        printf("The matrix is not identity\n");
    }
}


//==============================================================================================================================================