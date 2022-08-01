#include "text.h"

#define MAX_COMP_CHAVE 20

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

MapaTrigramas::MapaTrigramas() {
    frequenciaMultiplos = new int[MAX_COMP_CHAVE];
    for (int i = 0; i < MAX_COMP_CHAVE; i++) {
        frequenciaMultiplos[i] = 0;
    }
}

void MapaTrigramas::adicionarTrigrama(std::string trigrama, int posicao) {
    trigramas[trigrama].push_back(posicao);
}

void MapaTrigramas::imprimirMapa() {
    std::map<std::string, std::vector<int>>::const_iterator it;
    std::vector<int> v;

    for (it = trigramas.cbegin(); it != trigramas.cend(); it++) {
        std::cout << it->first << " [";
        v = it->second;
        for(long unsigned int i = 0; i < v.size(); i++) {
            std::cout << v.at(i);
            if (i == v.size() - 1) {
                break;
            }
            std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void MapaTrigramas::calcularFrequenciaMultiplos(int numero) {
    for (int i = 2; i < MAX_COMP_CHAVE+1; i++) {
        /* std::cout << frequenciaMultiplos[i] << std::endl;
        std::cout << i << std::endl; */
        if (numero%i == 0) {
            frequenciaMultiplos[i-2]++;
        }
    }
}

void MapaTrigramas::imprimirFrequenciaMultiplos() {
    std::cout << "Frequencia de multiplos" << std::endl;
    int max = 0;
    int maxIndice = 0;
    for (int i = 0; i < MAX_COMP_CHAVE; i++) {
        std::cout << i+2 << " ~> " << frequenciaMultiplos[i] << std::endl; 
        if (frequenciaMultiplos[i] > max) {
            max = frequenciaMultiplos[i];
            maxIndice = i+2;
        }
    } 
    std::cout << "Mais frequente: múltiplos de " << maxIndice << std::endl;
}

void MapaTrigramas::gerarMapaEspacos(MapaTrigramas* mapaDestino) {
    std::map<std::string, std::vector<int>>::const_iterator it;
    std::vector<int> v;
    std::string s;
    int espaco = 0;

    std::cout << "Criando mapa de espaços entre trigramas repetidos: " << std::endl;
    for (it = trigramas.cbegin(); it != trigramas.cend(); it++) {
        s = it->first;
        v = it->second;
        for(long unsigned int i = 1; i < v.size(); i++) {
            espaco = v.at(i) - v.at(i-1);
            calcularFrequenciaMultiplos(espaco);
            mapaDestino->adicionarTrigrama(s, espaco); 
        }
    }
    //mapaDestino->imprimirMapa();
    imprimirFrequenciaMultiplos();
}

void MapaCestos::adicionarAoCesto(int cesto, char letra) {
    if((int)cestos.size() < cesto + 1) {
        std::map<char, int> map;
        cestos.push_back(map);
    }
    cestos.at(cesto)[letra] = cestos.at(cesto)[letra] + 1;
}

/*
void MapaCestos::imprimirCestos(int tamanho) {
    std::map<char, int>* c;
    int maxs[tamanho];
    for(int i = 0; i < 26; i++) {
        std::cout << (char) i + 65 << ": ";
        for(int j = 0; j < tamanho; j++) {
            c = cestos.at(j)
        }
    }
}*/

char MapaCestos::buscarLetraMaisFrequente(int posicao) {
    std::map<char, int>::const_iterator it;
    std::string s;
    char maxChar;
    int max = 0;

    std::cout << "Buscar letra mais frequente na posicao " << posicao << ": " << std::endl;
    for (it = cestos.at(posicao).cbegin(); it != cestos.at(posicao).cend(); it++) {
        if(it->second > max) {
            maxChar = it->first;
            max = it->second;
        }
    }
    std::cout << "Letra mais frequente: '" << maxChar;
    std::cout << "', com " << max << " ocorrências" << std::endl;
    return maxChar;
}

int processar(char* texto){
    int comprimento = 0;
    int i = 0;
    while(texto[i] != '\0'){
        texto[i] = toupper(texto[i]);
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[comprimento] = texto[i];
            comprimento++;
        }
        i++;
    }
    texto[comprimento+1] = '\0';
    return comprimento;
}

Chave::Chave() : maxComprimento(MAX_COMP_CHAVE) {
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
void Chave::obterChaveUsuario() {
    std::cout << "Digite a chave utilizada para cifrar/decifrar a mensagem (max. " << maxComprimento << " caracteres)" << std::endl;
    std::fgets(chaveString, maxComprimento, stdin);
    comprimento = processar(chaveString);
}

Texto::Texto() : maxComprimento(5000) {
    entrada = new char[maxComprimento];
    saida = new char[maxComprimento];
    mapaTrigramas = new MapaTrigramas();
    mapaEspacos = new MapaTrigramas();
    mapaCestos = new MapaCestos();
}

int Texto::getComprimento() {
    return comprimento;
}

char* Texto::getEntrada() {
    return entrada;
}

char* Texto::getSaida() {
    return saida;
}

void Texto::setSaida(char* novaSaida) {
    saida = novaSaida;
}

char* Texto::criarSaida(){
    saida = new char[comprimento];
    return saida;
}

void Texto::copiarSaida(Texto texto) {
    comprimento = texto.getComprimento();
    entrada = new char[comprimento];
    char* origem = texto.getSaida();
    for (int i = 0; i < comprimento; i++) {
        entrada[i] = origem[i];
    }
}

void Texto::setComprimento(int comprimento) {
    this->comprimento = comprimento;
}

MapaTrigramas* Texto::getMapaTrigramas() {
    return mapaTrigramas;
}

void Texto::setMapaTrigramas(MapaTrigramas* mapaTrigramas) {
    this->mapaTrigramas = mapaTrigramas;
}

MapaTrigramas* Texto::getMapaEspacos() {
    return mapaEspacos;
}

void Texto::setMapaCestos(MapaCestos* mapaCestos) {
    this->mapaCestos = mapaCestos;
}

MapaCestos* Texto::getMapaCestos() {
    return mapaCestos;
}

void Texto::setMapaEspacos(MapaTrigramas* mapaEspacos) {
    this->mapaEspacos = mapaEspacos;
}


char* Texto::getBloco(int tamanhoBloco, int posicao) {
    if (posicao > comprimento) {
        return NULL;
    }
    char* bloco = new char[tamanhoBloco];
    int i = 0;
    while(i < tamanhoBloco){
        bloco[i] = entrada[posicao+i];
        if (entrada[posicao+i] == '\0') {
            break;
        }
        i++;
    }
    return bloco;
}

int Texto::abrirArquivo(char *nomeArquivo) {
    std::ifstream meuArquivo;
    meuArquivo.open(nomeArquivo, std::ios::in); // read
    if (meuArquivo.is_open()){
        std::cout << "Texto aberto corretamente." << std::endl;
        meuArquivo.get(entrada, maxComprimento, '\0');
        meuArquivo.close();
    } else {
        std::cout << "Texto nao foi aberto." << std::endl;
        std::cout << "A execucao sera interrompida." << std::endl;
        return 1;
    }
    comprimento = processar(entrada);
    return 0;
}
