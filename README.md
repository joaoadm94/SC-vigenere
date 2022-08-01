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

O mecanismo de cifração e decifração foi explicado acima e sua implementação foi bastante direta. A linguagem utilizada foi C++, com ênfase nas capacidades de Orientação a Objetos. Foram criadas classes Chave e Texto para organizar os dados e métodos cabíveis a cada estrutura. O programa lê o arquivo de texto informado no parâmetro de execução. A chave é dada pelo usuário no terminal durante a execução. 

Caso o processo de **cifração** seja selecionado, o programa soma os deslocamentos dados pela chave aos caracteres correspondentes para produzir o criptograma. O texto é cifrado em blocos do tamanho da chave para facilitar o processo. Um mapa de deslocamentos foi utilizado para acesso rápido a cada deslocamento possível. Os deslocamentos seguem a sequência A = 0, B = 1, ..., Y = 24, Z = 25. 

No caso da **decifração** o processo é o mesmo exceto pelo fato que os deslocamentos são subtraídos de cada caractere. Em ambos casos o alfabeto é circular, ou seja, ao passar da letra Z continuamos na letra A e vice-versa.

Os seguintes compromissos foram feitos nessa implementação:

- Os caracteres especiais foram desprezados. A utilização de caracteres com acentos resulta em comportamento inesperado.

- Quaisquer caracteres fora do intervalo A-Z, incluindo espaços e tabulações, são removidos do texto.

- Todo o texto é convertido para letras maiúsculas durante o processo.

- O resultado da cifração é exibido no console, porém não é salvo em arquivo.

- Chave de até 20 caracteres, e texto de até 5000 caracteres, são os valores padrão, podendo ser alterados.

## A implementação do ataque

O ataque a essa cifra se baseia na informação da frequência de letras em uma determinada língua. Dado um texto de tamanho suficiente esperamos que a frequência das letras presentes seja compatível com a frequência encontrada por pesquisadores de forma geral. No caso da cifra de Cesar, a análise seria simples pois todas as letras foram deslocadas pelo mesmo valor. Assim, as letras do criptograma poderiam ser ordenadas pela sua frequência. Digamos que a letra mais frequente seja 'J'. Na língua inglesa, a letra mais frequente é 'E'. Portanto podemos tentar decifrar a mensagem considerando o deslocamento entre essas letras com grande chance de sucesso.

No caso da cifra de Vigenere a frequência das letras fica menos aparente visto que foram aplicados n deslocamentos diferentes para uma chave de tamanho n. Por isso o primeiro passo do ataque é escolher um tamanho de chave. Usaremos esse tamanho para agrupar as letras que foram deslocadas pelo mesmo componente da chave. Fazendo a mesma análise de frequência descrita acima em um conjunto de letras podemos nos aproximar do caractere da chave correspondente aquele conjunto. Repetimos para todos para obter a chave.

Na implementação do projeto, obtemos uma sugestão para o tamanho da chave pelo seguinte procedimento: a partir do criptograma, buscamos todos os trigramas (conjuntos de três letras) que se repetem ao longo do texto. Cada trigrama corresponderia a conjuntos de três letras comuns no texto que teriam sido convertidos pelos mesmos componentes da chave. Em seguida, calculamos os espaços entre os trigramas repetidos. Nesse espaçamento a chave se repetiu várias vezes até estar na mesma posição para gerar os trigramas. Calculamos então se o espaço é múltiplo dos números 2 a k, onde k é o tamanho máximo de chave que estamos considerando - nesse caso, 20. Fazendo isso para todos os espaços e acumulando os resultados obtidos, podemos ter uma boa ideia do tamanho da chave. Afinal, se a maioria dos espaços é múltiplo de 7 então este é um bom palpite para o nosso tamanho de senha.

Eleito o tamanho, é feita a divisão em grupos, análise de frequência dentro desses grupos e uma sugestão de chave é feita a partir da letra mais frequente em cada grupo. O algoritmo não é perfeito em parte devido a simplicidade dessa análise. Passos mais sofisticados podem ser adicionados. Ainda assim, a assistência oferecida pelo programa é grande, permitindo realizar várias tentativas sobre o mesmo texto para nos aproximar da chave.

Características da implementação do ataque feita no projeto:

- Sugere um tamanho de chave porém permite a seleção de qualquer valor.

- Sugere uma letra mais frequente ('A' para português, 'E' para inglês) porém permite a seleção de qualquer letra. Essas duas características permitem experimentar bastante com o algoritmo de análise.

- Funciona de forma muito precisa para criptogramas cuja chave utilizada tem comprimento igual a números primos. Para outros casos, principalmente em criptogramas codificados com chaves de comprimento par, é necessário análise adicional por parte do usuário. É muito provável que o programa sugira uma chave de tamanho 2 quando a verdadeira tem tamanho 4, 6 ou 8. 



