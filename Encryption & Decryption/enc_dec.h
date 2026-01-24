#ifndef ENC_DEC_H
#define ENC_DEC_H

struct Message {
    int length;
    char text[530];

};

void inputMessage(struct Message *m);
void displayMessage(struct Message m);
int isUppercase(char c);   
int isLowercase(char c);
int isAlphabetic(char c);
void toUppercase(struct Message *m);
void toLowercase(struct Message *m);
void reverseMessage(struct Message *m);
void removeSpaces(struct Message *m);
void encryptCesar(struct Message *m, int key);
void decryptCesar(struct Message *m, int key);
void encryptXOR(struct Message *m, int key);
void decryptXOR(struct Message *m, int key);
void encryptSubstitution(struct Message *m, char key[26]);
void decryptSubstitution(struct Message *m, char key[26]);
int isValidKey(char key[26]);
int compareMessages(struct Message m1, struct Message m2);
int countCharacter(struct Message m, char c);
void frequencyAnalysis(struct Message m);
float coincidenceIndex(struct Message m);

// CLI wrapper functions
void _inputMessage();
void _displayMessage();
void _isUppercase();
void _isLowercase();
void _isAlphabetic();
void _toUppercase();
void _toLowercase();
void _reverseMessage();
void _removeSpaces();
void _encryptCesar();
void _decryptCesar();
void _encryptXOR();
void _decryptXOR();
void _encryptSubstitution();
void _decryptSubstitution();
void _isValidKey();
void _compareMessages();
void _countCharacter();
void _frequencyAnalysis();
void _coincidenceIndex();

#endif
