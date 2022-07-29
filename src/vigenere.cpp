#include <iostream>
#include <fstream> 
#include <string>
#include <map>
#include <ctype.h>
#include "text.h"
#include "vigenere.h"

char* Vigenere::cifrar(Chave chave, Texto texto) {
    int i = 0;
    int posicao = 0;
    char* saida = new char[texto.getComprimento()];
    int* deslocamentos = chave.getDeslocamentos();
    char* bloco = texto.getBloco(chave.getComprimento(), posicao);
    while(bloco != NULL) {
        for(i = 0; i < chave.getComprimento(); i++) {
            if(bloco[i] >= 'A' && bloco[i] <= 'Z'){
                bloco[i] = 
            }
        }
        if (j == chave->getComprimento()) {
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