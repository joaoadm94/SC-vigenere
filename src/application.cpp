#include <iostream>
#include <fstream> 
#include <string>
#include "vigenere.h"

int main (int argc, char* argv[]) {
    Texto* original = new Texto();
    if (argc < 2) {
        std::cout << "Por favor, informe o nome do arquivo de texto que deseja abrir ";
        std::cout << "no formato do seguinte exemplo: ./bin/vigenere teste.txt.";
        std::cout << std::endl << "Encerrando..." << std::endl;
        return 0;
    }
    if(original->abrirArquivo(argv[1])) {
        return 0;
    }
    Chave* chave = new Chave();
    chave->obterChaveUsuario();
    Vigenere::cifrar(*chave, *original);
    Texto* cifrado = new Texto();
    cifrado->copiarSaida(*original);
    Vigenere::decifrar(*chave, *cifrado);
    Vigenere::criarMapaTrigramas(*cifrado);
    cifrado->getMapaTrigramas()->gerarMapaEspacos(cifrado->getMapaEspacos());
    return 0;
}