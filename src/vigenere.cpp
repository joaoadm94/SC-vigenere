#include <iostream>
#include <fstream> 
#include <string>
#include <ctype.h>
#include "vigenere.h"
#define MAX_LEN 50
#define MAX_LEN_PLAINTXT 5000

int findLengthAndUppercase(char* string) {
    int i = 0;
    while(string[i] != '\0') {
        string[i] = toupper(string[i]);
        i++;
    }
    return i-1;
}

Key::Key() : maxLength(50) {
    key = new char[maxLength];
}

int Key::getLength() {
    return length;
}

int Key::getOffset(int position) {
    std::cout << key[position] - 'A' << std::endl; 
    return key[position] - 'A';
}
// Funcao aceita qualquer chave. Falta filtrar para apenas letras
void Key::setKey() {
    std::cout << "Digite a chave utilizada para cifrar a mensagem (max. 50 caracteres)" << std::endl;
    std::fgets(key, maxLength, stdin);
    length = findLengthAndUppercase(key);
}

Text::Text() : maxLength(5000) {
    plaintext = new char[maxLength];
}

int Text::getLength() {
    return length;
}

int Text::openFile(char *fileName) {
    std::ifstream myFile;
    myFile.open(fileName, std::ios::in); // read
    if (myFile.is_open()){
        std::cout << "Texto em claro aberto corretamente." << std::endl;
        myFile.get(plaintext, maxLength, '\0');
        length = findLengthAndUppercase(plaintext);
        myFile.close();
    } else {
        std::cout << "Texto em claro nao foi aberto." << std::endl;
        std::cout << "A execucao sera interrompida." << std::endl;
        return 1;
    }
    return 0;
}


int Text::encrypt(Key* key) {
    int i = 0;
    int j = 0;
    encrypted = new char[length];
    while(plaintext[i] != '\0') {
        if (j == key->getLength()) {
            j = 0;
        }
        encrypted[i] = plaintext[i] + key->getOffset(j);
        i++;
        j++;  
    }
    encrypted[i+1] = '\0';
    std::cout << encrypted << std::endl;
    return 0;
}