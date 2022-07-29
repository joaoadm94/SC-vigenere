class Vigenere {
    public:
        char* cifrar(Chave chave, Texto texto);
        char* decifrar(Chave chave, Texto texto);
};

class MapaDeslocamento {
    private:
        std::map<char, int> mapaDeslocamento;
    public:
        void criarMapa();
        char getDeslocamento(char c);
};