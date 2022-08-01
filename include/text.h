#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <fstream> 
#include <string>
#include <ctype.h>
#include <regex>
#include <map>

class MapaDeslocamento {
    private:
        std::map<char, int> mapaDeslocamento;
    public:
        MapaDeslocamento();
        void criarMapa();
        char getDeslocamento(char c);
};

class MapaTrigramas {
    private:
        std::map<std::string, std::vector<int>> trigramas;
        int* frequenciaMultiplos;
        void calcularFrequenciaMultiplos(int numero);
    public:
        MapaTrigramas();
        void adicionarTrigrama(std::string trigrama, int posicao);
        void imprimirMapa();
        void gerarMapaEspacos(MapaTrigramas* mapaDestino);
        void imprimirFrequenciaMultiplos();
};

class MapaCestos {
    private:
        std::vector<std::map<char, int>> cestos;
    public:
        void adicionarAoCesto(int cesto, char letra);
        void imprimirCestos(int tamanho);
        void imprimirCesto();
        char buscarLetraMaisFrequente(int posicao);
};

class Chave {
    private:
        const int maxComprimento;
        int comprimento;
        char* chaveString;
    public:
        Chave();
        void obterChaveUsuario();
        int getComprimento();
        int getDeslocamento(int posicao);
        int* getDeslocamentos(); 
};

class Texto {
    private:
        const int maxComprimento;
        int comprimento;
        char* entrada;
        char* saida;
        int tamanhoBlocoEscolhido;
        MapaTrigramas* mapaTrigramas;
        MapaTrigramas* mapaEspacos;
        MapaCestos* mapaCestos;
    public:
        Texto();
        int abrirArquivo(char *nomeArquivo);
        int getComprimento();
        char* getEntrada();
        char* getSaida();
        void setSaida(char* novaSaida);
        char* getBloco(int tamanhoBloco, int posicao);
        void setComprimento(int comprimento);
        MapaTrigramas* getMapaTrigramas();
        void setMapaTrigramas(MapaTrigramas* mapaTrigramas);
        MapaTrigramas* getMapaEspacos();
        void setMapaEspacos(MapaTrigramas* mapaEspacos);
        MapaCestos* getMapaCestos();
        void setMapaCestos(MapaCestos* mapaCestos);
        char* criarSaida();
        void copiarSaida(Texto texto);
};

#endif