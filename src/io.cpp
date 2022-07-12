#include <iostream>
#include <fstream> 
#include <string>

int openFile(char *fileName, char* plaintext, int plaintextMaxLength) {

    std::ifstream myFile;
    myFile.open(fileName, std::ios::in); // read
    if (myFile.is_open()){
        std::cout << "Arquivo aberto corretamente." << std::endl;
        std::string line;
        plaintext = new char[plaintextMaxLength];
        myFile.get(plaintext, plaintextMaxLength, '\0');
        myFile.close();
    } else {
        std::cout << "Arquivo nao foi aberto." << std::endl;
        std::cout << "A execucao sera interrompida." << std::endl;
        return 1;
    }

    return 0;
}

// Funcao aceita qualquer chave. Falta filtrar para apenas letras
int getKey(char* key, int maxLength) {
    std::cout << "Digite a chave utilizada para cifrar a mensagem (max. 50 caracteres)" << std::endl;
    std::fgets(key, maxLength, stdin);
    return 0;
}