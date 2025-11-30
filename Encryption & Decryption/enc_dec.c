// description : 
void inputMessage(struct Message m[]){
    printf("dear user, please enter the message you want to encript");
    scanf("%d",&m);


}
void displayMessage(struct Message m){
    printf(m);
    }
int main(){
    int m;
    struct Message m;
    inputMessage(m);
    displayMessage(m);
    return 0;
}