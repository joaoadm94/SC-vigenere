#include <iostream>
#include <fstream> 
#include <string>
#include "vigenere.h"

int main (int argc, char* argv[]) {
    Text* text = new Text();
    if (argc < 2) {
        std::cout << "Por favor, informe o nome do arquivo de texto que deseja abrir ";
        std::cout << "no formato do seguinte exemplo: ./bin/vigenere teste.txt.";
        std::cout << std::endl << "Encerrando..." << std::endl;
        return 0;
    }
    if(text->openFile(argv[1])) {
        return 0;
    }
    Key* key = new Key();
    key->setKey();
    text->encrypt(key);
    return 0;
}