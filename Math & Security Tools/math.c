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
//this function is needed for the modExp function it calculate base to the exp power
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

//Performs modular exponentiation
//input :the base and the exp and mod
//output : base^exp MOD mod
int modExp(int base, int exp, int mod){
    
    return (power(base%mod,exp))%mod;
    // try 1 10 1000//
}




//6
//factorial function
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
//sum of digits function
//input : an integer n
//output : sum of digits of n
int sumDigits(int n){
    int i,sum_dig,current_dig;
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
//reverse number function
//input : an integer n  
//output : the reverse of n
int reverseNumber(int n)
{
    int rev , c_dig;
    rev=0;
    while (n>0)
    {
        c_dig=n%10;
        rev=rev*10+c_dig;
        n=n/10;
    }
    return rev;
    

}

//9
//palindrome function
//input : an integer n  /
//output : 1 if n is palindrome 0 otherwise
int isPalindromeNumber(int n){
    int c_dig,temp_n,rev;
    temp_n=n;
    rev=0;
    if (n<0)
    {
        return 0;
    }
    
    while (n>0)
    {
        c_dig=n%10;
        rev=rev*10+c_dig;
        n=n/10;
    }

    if(rev-temp_n==0){
        return 1;
    }else{
        return 0;
    }
    
}



//10
//sum of divisors function
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
//perfect number function
//input : an integer n
//output : 1 if n is perfect number 0 otherwise
int isPerfectNumber(int n){
    int s_div,i;
    s_div=0;

for(i=1;i<=n/2;i++){
        if (n % i ==0)
        {
            s_div=s_div+i;
        }
            
    }
    
    if (s_div==n)
    {
        return 1;
    }
    else{
    return 0;
    }
    }

//12
//armstrong number function
//input : an integer n
//output : 1 if n is armstrong number 0 otherwise
int isArmstrong(int n){
    int i,temp_n_1,temp_n_2,num_dig,current_dig,power,res;
    num_dig=0;
    temp_n_1=n;
    temp_n_2=n;
    res=0;

    while (temp_n_2>0)
    {
        
        num_dig = num_dig +1
        ;
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
//random number function
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
//sum of array function
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
//average of array function
//input : an array T of n integers
//output : average of the integers in T
float averageArray(int T[], int n){
    return (float)sumArray(T,n)/n;

}
//16
//maximum of array function
//input : an array T of n integers
//output : maximum of the integers in T
int maxArray(int T[], int n) {
    int i,max;
    max=INT_MIN ;
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
    min=INT_MAX ;
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
//sorting array in ascending order function
//input : an array T of n integers
//output : the array T sorted in ascending order
void sortAscending(int T[], int n){
    int i,isSorted,tmp;
    isSorted=1;
    for(i = 0; i <n-1; i++){
        if(T[i]>T[i+1]){
            tmp=T[i];
            T[i]=T[i+1];
            T[i+1]=tmp;
            isSorted=0;
        }
    }
    
    if (isSorted!=1){
        sortAscending(T,n);
    }
    

}

int main(){

    int n,t,k;
    printf("hello");
    scanf("%d",&n);
    scanf("%d",&t);
    //scanf("%d",&k);
    //scanf("%d",&t);
    printf("%f8",randomNumber(n,t));
    //arr[]={9098,3,4,5,6,78,9,0,7,45,4};
    //sortAscending(arr,11);a
    
    //printf("%d",minArray(arr,11));
    return 0;
}