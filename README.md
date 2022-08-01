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

O cifrador recebe uma senha e uma mensagem como entrada. A saída é o criptograma, ou seja, a mensagem resultante da cifração utilizando a senha. O decifrador recebe como entrada uma senha e o criptograma, e produz a mensagem resultante da aplicação dos deslocamentos inversos. Com a chave correta, a mensagem original é retomada.

- `Ataque de recuperação de senha por análise de frequência`

O ataque consiste em obter a senha geradora do criptograma a partir do seu conteúdo. O método utilizado é a análise de frequência de letras.

## A Cifra de Vigenere

Antes de abordar a cifra de Vigenere em si cabe comentar sobre a cifra de Cesar. Nesta, o método de cifração consiste em eleger um deslocamento alfabético e aplicá-lo a todo o texto em claro. Como exemplo, aplicaremos esse método à mensagem "ATAQUE" com um deslocamento de 3 (três) posições. A letra situada três posições após A é D; a que segue a letra U em três posições é W; e assim seguimos trocando as letras por aquelas três posições à frente, obtendo o criptograma "DWDTXH". Esse método foi bastante utilizado até ser eventualmente quebrado. Seu ataque é relativamente fácil visto que o número de substituições possíveis é limitado pelo número de letras no alfabeto. Sendo assim, existem no máximo 26 possibilidades de cifração neste esquema.

A cifra de Vigenere é um sistema de substituição polialfabética. Neste método a mensagem original é deslocada por uma chave representando um conjunto de valores. Retomamos o exemplo sobre a mensagem "ATAQUE" utilizando a chave "HTY". Para entender os deslocamentos da chave, consideremos os valores A = 0, B = 1, C = 2, ..., H = 7, ..., T = 19, ..., Y = 24, Z = 25. Utilizando essa relação, A será deslocado H = 7 posições, T será deslocado em 19; o terceiro A será deslocado em 24 posições. Agora que a chave foi utilizada até o fim retornamos a seu início para continuar a cifração. Esse processo resultará no criptograma "HMYXNC". A cifra é mais robusta pois disfarça melhor a frequência de letras. Para atacá-la é necessário saber o tamanho da chave. Essa informação permite agrupar as letras que foram deslocadas pelo mesmo valor e então analisar a frequência de letras.

## A implementação do cifrador/decfirador



## A implementação do ataque