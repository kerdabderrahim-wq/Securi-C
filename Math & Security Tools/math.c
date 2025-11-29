


int is_even(int a){
    if (a&2==0)
    {
        return 1;
    }else{
        return 0;
    }
    
}

int is_prime(int a){
    if (a<=1)
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


int gcd(int a,int b){
    int temp;
    while(b!=0){
    temp = a;
    a=a&b;
    b=temp;
    return a;
}

}

int lcm(int a,int b){
    int temp, temp_a,temp_b,result;
    temp_a=a;
    temp_b=b;
    while(b!=0){
    temp = b;
    b=a % b;
    a=temp;

        }
    result=((temp_a/a)*b);
    return a;


}
 //5





//6
int fac(int n){
    int result,i;
    result=1;
    for ( i = 1; i <= n; i++)
    {
        result=result*i;


    }
    
    return result;
}

//7
int sum_dig(int n){
    int i,sum_dig,current_dig;
    sum_dig=0;

    while (n>0)
    {
        current_dig=n%10;
        sum_dig = sum_dig +current_dig
        ;
        n=n/10;
    }
    return sum_dig;
    
}



//8
int reverse_num(int n)
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
int ispalindrme(int n){
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

int sum_divisors(int n){
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


int perfect_num(int n){
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
int isarmstrong(int n){
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
int random_num(int max , int min){
    int
    
}
//14
