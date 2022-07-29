#include <iostream>
#include <fstream> 
#include <string>
#include <map>
#include <ctype.h>
#include "text.h"
#include "vigenere.h"

MapaDeslocamento::MapaDeslocamento() {
    mapaDeslocamento['A'] = 0;
    mapaDeslocamento['B'] = 1;
    mapaDeslocamento['C'] = 2;
    mapaDeslocamento['D'] = 3;
    mapaDeslocamento['E'] = 4;
    mapaDeslocamento['F'] = 5;
    mapaDeslocamento['G'] = 6;
    mapaDeslocamento['H'] = 7;
    mapaDeslocamento['I'] = 8;
    mapaDeslocamento['J'] = 9;
    mapaDeslocamento['K'] = 10;
    mapaDeslocamento['L'] = 11;
    mapaDeslocamento['M'] = 12;
    mapaDeslocamento['N'] = 13;
    mapaDeslocamento['O'] = 14;
    mapaDeslocamento['P'] = 15;
    mapaDeslocamento['Q'] = 16;
    mapaDeslocamento['R'] = 17;
    mapaDeslocamento['S'] = 18;
    mapaDeslocamento['T'] = 19;
    mapaDeslocamento['U'] = 20;
    mapaDeslocamento['V'] = 21;
    mapaDeslocamento['W'] = 22;
    mapaDeslocamento['X'] = 23;
    mapaDeslocamento['Y'] = 24;
    mapaDeslocamento['Z'] = 25;
}

char MapaDeslocamento::getDeslocamento(char c){
    return mapaDeslocamento[c];
}

char* Vigenere::cifrar(Chave chave, Texto texto) {
    int i = 0;
    int j = 0;
    char* saida = new char[texto.getComprimento()];
    while(plaintext[i] != '\0') {
        if (j == key->getComprimento()) {
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
    std::cin >> i;
    return 0;
}

int Text::decrypt(Key *key) {
    int i = 0;
    int j = 0;
    decrypted = new char[Comprimento];
    while(encrypted[i] != '\0'){
        if(j == key->getComprimento()){
            j = 0;
        }
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = encrypted[i] - key->getOffset(j);
            if (decrypted[i] < 'A') {
                decrypted[i] = decrypted[i] + 26;
            }
            j++;  
        } else {
            decrypted[i] = encrypted[i];
        }
        i++;
    }
    decrypted[i+1] = '\0';
    std::cout << decrypted << std::endl;
    return 0;
}