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

int main(){
    struct Message m;
    inputMessage(&m);
    removeSpaces(&m);
    displayMessage(m);
    return 0;
}