#include <iostream>
#include <fstream> 
#include <string>
#include <ctype.h>
#include <regex>
#include "vigenere.h"

int preprocessar(char* texto) {
    int i = 0;
    while(texto[i] != '\0') {
        texto[i] = toupper(texto[i]);
        /*
        switch(string[i]) {
            // caracteres especiais À Á Â Ã
            case 'À': case 'Á':
            case 'Â': case 'Ã':
                string[i] = 65;
                break;
            // caracteres especiais Ç
            case 199:
                string[i] = 67;
                break;
            // caracteres especiais É Ê
            case 201: case 202:
                string[i] = 69;
                break;
            // caracteres especiais Í
            case 205: 
                string[i] = 73;
                break;
            // caracteres especiais Ó Ô Õ
            case 211: case 212:
            case 213:
                string[i] = 79;
                break;
            // caracteres especiais Ú
            case 218:
                string[i] = 85;
                break;
        }
        */
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
    length = preprocessar(key);
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
        length = preprocessar(plaintext);
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
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            encrypted[i] = plaintext[i] + key->getOffset(j);
            if (encrypted[i] > 'Z') {
                encrypted[i] = encrypted[i] - 26;
            }
            j++;  
        } else {
            encrypted[i] = plaintext[i];
        }
        i++;
    }
    encrypted[i+1] = '\0';
    std::cout << encrypted << std::endl;
    return 0;
}

int Text::decrypt(Key *key) {
    int i = 0;
    int j = 0;
    char* decrypted = new char[length];
    while(decrypted[i] = '\0')

}