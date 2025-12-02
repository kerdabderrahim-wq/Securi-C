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
    for (int i = 0; m->text[i]!='\0'; i++){
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
    for (int i = 0; i < m->length; i++) {
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
    for (int i = 0; i < m->length; i++) {
        if (isUppercase(m->text[i])) {
            m->text[i] = m->text[i] + ('a' - 'A');
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
            m->text[i]=((m->text[i]-'A'-key)%26)+'A';
        }else if (isLowercase(m->text[i])){
            m->text[i]=((m->text[i]-'a'-key)%26)+'a';
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
            count_char++;
        }
    }
    return count_char;
}
void frequencyAnalysis(struct Message m){
    int i,c1,c2;
    for(i=0;i<26;i++){
        c1=countCharacter(m,i+'a');
        c2=countCharacter(m,i+'A');
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


int main(){
    struct Message m1;
    inputMessage(&m1);
    frequencyAnalysis(m1);
    //decryptSubstitution(&m,"qwertyuiopasdfghjklzxcvbnm");
    //displayMessage(m);
    return 0;
}
