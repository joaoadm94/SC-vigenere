#include "vigenere.h"

void Vigenere::cifrar(Chave chave, Texto texto) {
    int i = 0;
    int posicao = 0;
    int* deslocamentos = chave.getDeslocamentos();
    int comprimentoChave = chave.getComprimento();
    char* saida = texto.getSaida();
    char* bloco = texto.getBloco(comprimentoChave, posicao);
    while(bloco != NULL) {
        for(i = 0; i < comprimentoChave; i++) {
            saida[i+posicao] = bloco[i] + deslocamentos[i];
            if(saida[i+posicao] > 'Z') {
                saida[i+posicao] = saida[i+posicao] - 26; 
            }
        }
        posicao = posicao + comprimentoChave;
        bloco = texto.getBloco(comprimentoChave, posicao);
    }
    saida[texto.getComprimento()] = '\0';
    std::cout << saida << std::endl;
    char c;
    std::cin.get(c);
    return;
}

void Vigenere::decifrar(Chave chave, Texto texto) {
    int i = 0;
    int posicao = 0;
    int* deslocamentos = chave.getDeslocamentos();
    int comprimentoChave = chave.getComprimento();
    char* saida = new char[texto.getComprimento()]();
    char* bloco = texto.getBloco(comprimentoChave, posicao);
    while(bloco != NULL) {
        for(i = 0; i < comprimentoChave; i++) {
            saida[i+posicao] = bloco[i] - deslocamentos[i];
            if(saida[i+posicao] < 'A') {
                saida[i+posicao] = saida[i+posicao] + 26; 
            }
        }
        posicao = posicao + comprimentoChave;
        bloco = texto.getBloco(comprimentoChave, posicao);
    }
    saida[texto.getComprimento()] = '\0';
    std::cout << saida << std::endl;
    char c;
    std::cin.get(c);
    return;
}

void Vigenere::criarMapaTrigramas(Texto texto) {
    MapaTrigramas* mapa = texto.getMapaTrigramas();
    int comprimento = texto.getComprimento();
    char* entrada = texto.getEntrada();
    char trigrama[3];
    if (comprimento < 3) {
        std::cout << "O texto não tem comprimento suficiente. Mapa de trigramas não foi criado." << std::endl;
        return;
    }
    for (int i = 0; i < 3; i++) {
        trigrama[i] = entrada[i];
    }
    std::cout << "criando mapa: " << std::endl;
    for(int i = 3; i < comprimento; i++) {
        std::string s(trigrama);
        mapa->adicionarTrigrama(s, i - 3);
        trigrama[0] = trigrama[1];
        trigrama[1] = trigrama[2];
        trigrama[2] = entrada[i];
    }
    texto.setMapaTrigramas(mapa);
    mapa->imprimirMapa();
}

void Vigenere::analisarTextoCifrado(Texto texto) {
    int tamanhoBloco;
    std::cout << "Informe o tamanho da chave:" << std::endl;
    std::cin >> tamanhoBloco;
    int posicao;
    MapaCestos* mapa = texto.getMapaCestos();
    char* bloco = texto.getBloco(tamanhoBloco, posicao);
    while(bloco != NULL) {
        for(int i = 0; i < tamanhoBloco; i++) {
            mapa->adicionarAoCesto(i, bloco[i]);
        }
        posicao = posicao + tamanhoBloco;
        bloco = texto.getBloco(tamanhoBloco, posicao);
    }
    
}
