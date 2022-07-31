#ifndef VIGENERE_H
#define VIGENERE_H

#include "text.h"

class Vigenere {
    public:
        static void cifrar(Chave chave, Texto texto);
        static void decifrar(Chave chave, Texto texto);
        static void criarMapaTrigramas(Texto texto);
        static void analisarTextoCifrado(Texto texto);
};

#endif