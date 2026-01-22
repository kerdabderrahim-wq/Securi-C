#include <stdio.h>
struct Message{ 
  char text[200]; 
  int length; 
 };
//1
// description: function to input a message from the user
// input : pointer to a Message struct
// output : none (the function modifies the struct in place)
void inputMessage(struct Message *m){
    int i;
    printf("enter your message: ");
    scanf(" %[^\n]",(*m).text);
    m->length=0;
    for (i = 0; m->text[i]!='\0'; i++){
        m->length++;
    }

}

//2
// description: function to display a message
// input : a Message struct
// output : none (the function prints the message to the console)

void displayMessage(struct Message m){
        printf(m.text);
}

//3
// description: function to check if a character is uppercase
// input : a character c
// output : 1 if c is uppercase, 0 otherwise
int isUppercase(char c) {
    return (c >= 'A' && c <= 'Z'); //&& automaticly return 0 or 1 if the conditions satisfied

}

//4
// description: function to check if a character is lowercase
// input : a character c
// output : 1 if c is lowercase, 0 otherwise
int isLowercase(char c) {
    return (c >= 'a' && c <= 'z');
}
//5
//description: function to check if a character is alphabetic
//input : a character c
//output : 1 if c is alphabetic, 0 otherwise
int isAlphabetic(char c){
    return (isUppercase(c) || isLowercase(c));
}
//6
// description: function to convert all lowercase letters in a message to uppercase
// input : a Message struct
// output : none (the function modifies the struct in place)
void toUppercase(struct Message *m){
    int i;
    for (i = 0; i < m->length; i++) {
        if (isLowercase(m->text[i])) {
            m->text[i] = m->text[i] - ('a' - 'A'); // we need to understande it //
        }
    }
}

//7
// description: function to convert all uppercase letters in a message to lowercase
// input : a Message struct
// output : none (the function modifies the struct in place)
void toLowercase(struct Message *m){
    int i;
    for (i = 0; i < m->length; i++) {
        if (isUppercase(m->text[i])) {
            m->text[i] = m->text[i] + ('a' - 'A');
        // this ('a' - 'A') means the difference between the ASCII values of 'a' and 'A' and it is 32 and we add it to convert to lowercase    
        }
    }
}
//8
// description: function to encrypt a message using a Caesar cipher
// input : a Message struct and an integer key
// output : none (the function modifies the struct in place)
void reverseMessage(struct Message *m){ 
    int i;
    struct Message s=*m;
    for ( i = 0; i < m->length; i++){
        s.text[i]=m->text[m->length-1-i];
        //-1 because the index starts from 0
    }
    *m=s;
    
}
//9
// description: function to remove spaces from a message    
// input : a Message struct
// output : none (the function modifies the struct in place)
void removeSpaces(struct Message *m){
    int i,c;
    c=0;
    struct Message s=*m;
    for ( i = 0; i < m->length; i++){
        if((m->text[i])!=' '){
            s.text[c]=m->text[i];
            c++;
        }else{
            s.length--;
        }
    }
    s.text[c]='\0';
    *m=s;

}
//10
// description: function to encrypt a message using a Caesar cipher
// input : a Message struct and an integer key
// output : none (the function modifies the struct in place)

void encryptCesar(struct Message *m, int key){
    int i;
    for ( i = 0; i < m->length; i++){
        //there is a different between uppercase and lowr case in ASCII
        if (isUppercase(m->text[i])){
            //there is 26 letter so we use MOD 26
            m->text[i]=((m->text[i]-'A'+key)%26)+'A';
            // to understande it //
            // m->text[i]-'A' : to get the index of the letter in the alphabet (0-25)
            //  +key : to shift the letter by the key
            // %26 : to wrap around if the index goes beyond 25
            // +'A' : to convert the index back to a character
            
        }else if (isLowercase(m->text[i])){
            m->text[i]=((m->text[i]-'a'+key)%26)+'a';
        }
    }
}

//11
// description: function to decrypt a message using a Caesar cipher
// input : a Message struct and an integer key
// output : none (the function modifies the struct in place)
void decryptCesar(struct Message *m, int key){
    int i;
    for ( i = 0; i < m->length; i++){
        //there is a different between uppercase and lowr case in ASCII
        if (isUppercase(m->text[i])){
            //there is 26 letter so we use MOD 26
            //the same with minus//
            m->text[i]=(((m->text[i]-'A'-key)%26+26)%26)+'A';
        }else if (isLowercase(m->text[i])){
            m->text[i]=(((m->text[i]-'a'-key)%26+26)%26)+'a';
        }
    }

}
//12
// description: function to encrypt a message using XOR cipher
 // input : a Message struct and an integer key
// output : none (the function modifies the struct in place)
void encryptXOR(struct Message *m, int key){
    int i;// we can use the length attribute of the struct Message
    for ( i = 0; i < m->length; i++){ 
        //^ is the XOR operator in C 
        //the same function can be used for encryption and decryption
        m->text[i]=m->text[i]^key;
    }
}


//13 
//description: function to decrypt a message using XOR cipher
 // input : a Message struct and an integer
// output : none (the function modifies the struct in place)
void decryptXOR(struct Message *m, int key) {
    int i;
    for ( i = 0; i < m->length; i++)
    {
        m->text[i]=m->text[i]^key;
        // to get back the original character we use the same operation
        //then XORing again with the same key returns the original value
    }
    
}

//14
//description: function to encrypt a message using substitution cipher
// input : a Message struct and a key (an array of 26 characters)
// output : none (the function modifies the struct in place)
void encryptSubstitution(struct Message *m, char key[26]){
    int i;
    for ( i = 0; i < m->length ; i++){
        if (isUppercase(m->text[i])){
            m->text[i]=key[m->text[i]-'A']; 
        }
        //to get the index of the letter in the alphabet we subtract 'A' or 'a'
        else if (isLowercase(m->text[i])){
            m->text[i]=key[m->text[i]-'a'];
        }
        
        
        
    }
    
}
//15
//description: function to decrypt a message using substitution cipher
// input : a Message struct and a key (an array of 26 characters)
// output : none (the function modifies the struct in place)
void decryptSubstitution(struct Message *m, char key[26]){
    int i,j;
    for(i=0;i<m->length;i++){
        for(j=0;j<26;j++){
            if(key[j]==m->text[i]){
                m->text[i]='a'+j;
                break;
            }
        }
    }

}
//16
//description: function to check if a substitution key is valid
// input : a key (an array of 26 characters)
// output : 1 if the key is valid, 0 otherwise
// the criteria for a valid key are:
// - it must contain exactly 26 characters, and we know that every string in C ends with '\0'
// - all characters must be alphabetic
// - no character should be repeated
int isValidKey(char key[26]){
    int isValid,i,j,length;
    isValid=1;
    length=0;
    for (int i = 0; key[i]!='\0'; i++){
        length++;
    }
    if (length!=26){
        isValid=0;
    }

    for ( i = 0; isValid && i<26; i++){
        if (!isAlphabetic(key[i])){
            isValid=0;
            break;
        }
        for (j = 0; j < i; j++){
            if(key[i]==key[j]){
                isValid=0;
                break;
            }
        }
        
        
    }
    return isValid;
    
    
}

//17
//description: function to compare two messages
// two messages are considered equal if they have the same length and the same characters in the same order
// input : two Message structs
// output : 1 if the messages are equal, 0 otherwise

int compareMessages(struct Message m1, struct Message m2){
    int isequal,i;
    isequal=1;
    if (m1.length!=m2.length){
        isequal=0;
        // to exit early if lengths are different
    }
    
    for ( i = 0; i < m1.length && isequal==1; i++){
        if (m1.text[i]!=m2.text[i]){
            isequal=0;
            break;
            // to exit the loop early if we find a mismatch
        }
        
    }
    return (isequal);
}

//18
//description: function to count the occurrences of a character in a message
// input : a Message struct and a character c
// output : the number of times c appears in the message

int countCharacter(struct Message m, char c){
    int i,count_char;
    count_char=0;
    for(i=0;i<m.length;i++){
        if (m.text[i]==c){
            //if the current letter is the same as the input char
            count_char++;
            //add one to the counter
        }
    }
    return count_char;
}
//19
//description : a procedure that calculate the frequency of each letter in a message  
// input : a Message struct
// output : none (the function prints the frequency of each letter to the console) 
void frequencyAnalysis(struct Message m){
    int i,c1,c2;
    for(i=0;i<26;i++){
        // this means that for each letter in the alphabet
        c1=countCharacter(m,i+'a');
        c2=countCharacter(m,i+'A');
        // print only if the count is not zero
            if (c1!=0)
            {
                printf("%c",i+'a');
                printf(":");
                printf("%d\n",c1);
            }
            if (c2!=0)
            {
                printf("%c",i+'A');
                printf(":");
                printf("%d\n",c2);
            }
            
    }
}
//20
//description : a function that calculate the coincidence index of a message
// input : a Message struct
// output : the coincidence index as a float value
float coincidenceIndex(struct Message m){
    float f,i,result, n;
    result=0;
    n=0;

    for ( i = 0; i < 26; i++){
        f=countCharacter(m,i+'a')+countCharacter(m,i+'A');
        // this to count both lowercase and uppercase letters if there exist
        result=result+f*(f-1);
        n=n+f;
    
        // to calculate the total number of letters in the message
        // we ignore non-alphabetic characters
        //the coincidence index formula is :
        // IC = sum(f_i * (f_i - 1)) / (n * (n - 1))
        // where f_i is the frequency of letter i and n is the total number of letters

    }
    return ((result)/(n*(n-1)));
}


//============================================================================================================================
// extra function of the cli
//============================================================================================================================
void _inputMessage(){
    struct Message m;
    inputMessage(&m);
    printf("The message you entered is : ");
    displayMessage(m);
}
void _displayMessage(){
    struct Message m;
    inputMessage(&m);
    printf("The message is : ");
    displayMessage(m);
}
void _isUppercase(){
    char c;
    printf("Enter a character : ");
    scanf(" %c",&c);
    if(isUppercase(c)){
        printf("yes is uppercase");
    }
    else{
        printf("no it is not uppercase");
    }
}
void _isLowercase(){
    char c;
    printf("Enter a character : ");
    scanf(" %c",&c);
    if(isLowercase(c)){
        printf("yes is lowercase");
    }
    else{
        printf("no it is not lowercase");
    }
}
void _isAlphabetic(){
    char c;
    printf("Enter a character : ");
    scanf(" %c",&c);
    if(isAlphabetic(c)){
        printf("yes is alphabetic");
    }
    else{
        printf("no it is not alphabetic");
    }
}
void _toUppercase(){
    struct Message m;
    inputMessage(&m);
    toUppercase(&m);
    printf("The message in uppercase is : ");
    displayMessage(m);
}

void _toLowercase(){
    struct Message m;
    inputMessage(&m);
    toLowercase(&m);
    printf("The message in lowercase is : ");
    displayMessage(m);
}
void _reverseMessage(){
    struct Message m;
    inputMessage(&m);
    reverseMessage(&m);
    printf("The reversed message is : ");
    displayMessage(m);
}
void _removeSpaces(){
    struct Message m;
    inputMessage(&m);
    removeSpaces(&m);
    printf("The message without spaces is : ");
    displayMessage(m);
}
void _encryptCesar(){
    struct Message m;
    int key;
    inputMessage(&m);
    printf("Enter the key (an integer): ");
    scanf("%d",&key);
    encryptCesar(&m,key);
    printf("The encrypted message is : ");
    displayMessage(m);
}
void _decryptCesar(){
    struct Message m;
    int key;
    inputMessage(&m);
    printf("Enter the key (an integer): ");
    scanf("%d",&key);
    decryptCesar(&m,key);
    printf("The decrypted message is : ");
    displayMessage(m);
}
void _encryptXOR(){
    struct Message m;
    int key;
    inputMessage(&m);
    printf("Enter the key (an integer): ");
    scanf("%d",&key);
    encryptXOR(&m,key);
    printf("The encrypted message is : ");
    displayMessage(m);
}
void _decryptXOR(){
    struct Message m;
    int key;
    inputMessage(&m);
    printf("Enter the key (an integer): ");
    scanf("%d",&key);
    decryptXOR(&m,key);
    printf("The decrypted message is : ");
    displayMessage(m);
}
void _encryptSubstitution(){
    struct Message m;
    char key[27];
    inputMessage(&m);
    printf("Enter the substitution key (26 alphabetic characters): ");
    scanf(" %26s",key);
    if (isValidKey(key)){
        encryptSubstitution(&m,key);
        printf("The encrypted message is : ");
        displayMessage(m);
    }else{
        printf("Invalid key!!!!!!!!!!!!!!! Please ensure it contains 26 unique alphabetic characters \n");
    }
}
void _decryptSubstitution(){
    struct Message m;
    char key[260];
    inputMessage(&m);
    printf("Enter the substitution key (26 alphabetic characters): ");
    scanf(" %26s",key);
    if (isValidKey(key)){
        decryptSubstitution(&m,key);
        printf("The decrypted message is : ");
        displayMessage(m);
    }else{
        printf("Invalid key! Please ensure it contains 26 unique alphabetic characters \n");
    }
}
void _isValidKey(){
    char key[270];
    printf("Enter the substitution key (26 alphabetic characters): ");
    scanf(" %26s",key);
    if (isValidKey(key)){
        printf("The key is valid.\n");
    }else{
        printf("The key is invalid.\n");
    }
}
void _compareMessages(){
    struct Message m1,m2;
    printf("Enter the first message:\n");
    inputMessage(&m1);
    printf("Enter the second message:\n");
    inputMessage(&m2);
    if (compareMessages(m1,m2)){
        printf("The messages are equal.\n");
    }else{
        printf("The messages are not equal.\n");
    }
}
void _countCharacter(){
    struct Message m;
    char c;
    int count;
    inputMessage(&m);
    printf("Enter the character to count: ");
    scanf(" %c",&c);
    count=countCharacter(m,c);
    printf("The character '%c' appears %d times in the message.\n",c,count);
}
void _frequencyAnalysis(){
    struct Message m;
    inputMessage(&m);
    printf("Frequency analysis of the message:\n");
    frequencyAnalysis(m);
}
void _coincidenceIndex(){
    struct Message m;
    float index;
    inputMessage(&m);
    index=coincidenceIndex(m);
    printf("The coincidence index of the message is : %.6f\n",index);
}
//============================================================================================================================
// end of extra function of the cli
//============================================================================================================================
