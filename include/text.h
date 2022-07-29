class Chave {
    private:
        const int maxComprimento;
        int comprimento;
        char* chaveString;
    public:
        Chave();
        void setChave();
        int getComprimento();
        int getDeslocamento(int posicao);
        int* getDeslocamentos(); 
};

class Texto {
    private:
        const int maxComprimento;
        int comprimento;
        char* entrada;
        char* saída;
    public:
        Texto();
        int abrirArquivo(char *nomeArquivo);
        int getComprimento();
        char* getEntrada();
        char* getBloco(int tamanhoBloco, int posicao);
};

class MapaDeslocamento {
    private:
        std::map<char, int> mapaDeslocamento;
    public:
        void criarMapa();
        char getDeslocamento(char c);
};