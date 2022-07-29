#include <iostream>
#include <fstream> 
#include <string>
#include <ctype.h>
#include <regex>
#include "text.h"

int processar(char* texto){
    int comprimento = 0;
    while(texto[comprimento] = '\0'){
        comprimento++;
        texto[comprimento] = toupper(texto[comprimento]);
    }
    return comprimento;
}

Chave::Chave() : maxComprimento(50) {
    chaveString = new char[maxComprimento];
}

int Chave::getComprimento() {
    return comprimento;
}

int Chave::getDeslocamento(int posicao) {
    return chaveString[posicao] - 'A';
}

// Funcao aceita qualquer chave. Falta filtrar para apenas letras
void Chave::setChave() {
    std::cout << "Digite a chave utilizada para cifrar a mensagem (max. 50 caracteres)" << std::endl;
    std::fgets(chaveString, maxComprimento, stdin);
    comprimento = processar(chaveString);
}

Texto::Texto() : maxComprimento(5000) {
    entrada = new char[maxComprimento];
}

int Texto::getComprimento() {
    return comprimento;
}

char* Texto::getEntrada() {
    return entrada;
}

int Texto::abrirArquivo(char *nomeArquivo) {
    std::ifstream meuArquivo;
    meuArquivo.open(nomeArquivo, std::ios::in); // read
    if (meuArquivo.is_open()){
        std::cout << "Texto em claro aberto corretamente." << std::endl;
        meuArquivo.get(entrada, maxComprimento, '\0');
        meuArquivo.close();
    } else {
        std::cout << "Texto em claro nao foi aberto." << std::endl;
        std::cout << "A execucao sera interrompida." << std::endl;
        return 1;
    }
    comprimento = processar(entrada);
    return 0;
}