#include <iostream>
#include <fstream> 
#include <string>
#include "vigenere.h"

int main (int argc, char* argv[]) {
    Texto* texto = new Texto();
    if (argc < 2) {
        std::cout << "Por favor, informe o nome do arquivo de texto que deseja abrir ";
        std::cout << "no formato do seguinte exemplo: ./bin/vigenere teste.txt.";
        std::cout << std::endl << "Encerrando..." << std::endl;
        return 0;
    }
    if(texto->abrirArquivo(argv[1])) {
        return 0;
    }
    Chave* chave = new Chave();
    chave->setChave();
    texto->cifrar(chave);
    texto->decifrar(chave);
    return 0;
}