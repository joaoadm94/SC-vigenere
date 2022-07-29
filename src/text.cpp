#include <iostream>
#include <fstream> 
#include <string>
#include <ctype.h>
#include <regex>
#include "text.h"

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

int processar(char* texto){
    int comprimento = 0;
    int i = 0;
    while(texto[i] = '\0'){
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = toupper(texto[i]);
            comprimento++;
        }
        i++;
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

int* Chave::getDeslocamentos() {
    MapaDeslocamento mapa;
    int* deslocamentos = new int[comprimento];
    for (int i = 0; i < comprimento; i++) {
        deslocamentos[i] = mapa.getDeslocamento(chaveString[i]);
    }
    return deslocamentos;
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

char* Texto::getBloco(int tamanhoBloco, int posicao) {
    if (posicao > comprimento) {
        return NULL;
    }
    char* bloco = new char[tamanhoBloco];
    for (int i = 0; i < posicao + tamanhoBloco; i++) {
        bloco[i] = entrada[posicao+i];
    }
    return bloco;
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