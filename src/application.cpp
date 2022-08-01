#include <iostream>
#include <fstream> 
#include <string>
#include "vigenere.h"

int main (int argc, char* argv[]) {
    Texto* texto = new Texto();
    Chave* chave = new Chave();
    if (argc < 3) {
        std::cout << "Por favor, informe o nome do arquivo de texto que deseja abrir ";
        std::cout << "no formato do seguinte exemplo: ./bin/vigenere opcao teste.txt." << std::endl;
        std::cout << "Opcoes: 1 (cifrar); 2 (decifrar); 3 (analisar)" << std::endl;
        std::cout << std::endl << "Encerrando..." << std::endl;
        return 0;
    }
    if(texto->abrirArquivo(argv[2])) {
        return 0;
    }
    char op = argv[1][0];
    switch(op) {
        case '1':
            chave->obterChaveUsuario();
            Vigenere::cifrar(*chave, *texto);
            break;
        case '2':
            chave->obterChaveUsuario();
            Vigenere::decifrar(*chave, *texto);
            break;
        case '3':
            Vigenere::criarMapaTrigramas(*texto);
            texto->getMapaTrigramas()->gerarMapaEspacos(texto->getMapaEspacos());
            Vigenere::analisarTextoCifrado(*texto);
            break;
        default:
            std::cout << "Opção não encontrada. O programa será encerrado." << std::endl;
    }
    return 0;
}