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
};