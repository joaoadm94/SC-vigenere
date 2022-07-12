#include <iostream>
#include <fstream> 
#include <string>
#include "io.h"
#define MAX_LEN 50
#define MAX_LEN_PLAINTXT 5000

class CharPointer {
    public:
        char* charPointer;
};

class Key : public CharPointer {
    public:
        Key();
};

class Plaintext : public CharPointer {
    public:
        Plaintext();
};

Key::Key() {
    charPointer = new char[MAX_LEN];
    getKey(charPointer, MAX_LEN);
}

Plaintext::Plaintext() {
    int status;
    charPointer = new char[MAX_LEN_PLAINTXT];
    status = openFile((char*)"teste.txt", charPointer, MAX_LEN_PLAINTXT);
}

int main () {

    int status;
    Plaintext plaintext;
    Key currentKey;
    return 0;
}