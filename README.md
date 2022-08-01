# SC-vigenere

Projeto da disciplina Segurança Computacional sob a orientação do Professor João José Gondim.

Autor: João Antonio Desiderio de Moraes (Mat.: 16/0126975)

## Como executar

O projeto foi desenvolvido e testado em C++ na plataforma Linux Ubuntu 20.04.4 LTS. 

Possui um arquivo Makefile de forma a facilitar sua compilação.

Para compilar, execute o comando "make" na raiz do projeto. O executável será criado na pasta "bin".

Para executar a partir da raiz do projeto, podes utilizar o comando "./bin/vigenere opção arquivo_texto.txt".

O parâmetro opção deve ser substituído por 1 para cifrar, 2 para decifrar e 3 para atacar. Por exemplo, o comando "./bin/vigenere 2 teste.txt" abre o arquivo teste.txt para decifrar.

## Objetivos

O trabalho explora a cifra histórica de Vigenère. É composto de duas partes:

- `Cifrador/decifrador`

O cifrador recebe uma senha e uma mensagem como entrada. A saída é o criptograma, ou seja, a mensagem cifrada utilizando a senha. O decifrador recebe como entrada a senha e o criptograma, e produz a mensagem original na saída.

- `Ataque de recuperação de senha por análise de frequência`

O ataque consiste em obter a senha geradora do criptograma a partir do seu conteúdo. O método utilizado é a análise de frequência de letras.

## A Cifra de Vigenere



## A implementação do cifrador/decfirador



## A implementação do ataque