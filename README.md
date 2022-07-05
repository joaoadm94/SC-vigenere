# SC-vigenere

Projeto da disciplina Segurança Computacional sob a orientação do Professor João José Gondim.
Autor: João Antonio Desiderio de Moraes (Mat.: 16/0126975)

## Objetivos

O trabalho explora a cifra história de Vigenère. É composto de duas partes:

- `Cifrador/decifrador`
O cifrador recebe uma senha e uma mensagem como entrada. A saída é o criptograma, ou seja, a mensagem cifrada utilizando a senha. O decifrador recebe como entrada a senha e o criptograma, e produz a mensagem original na saída.

- `Ataque de recuperação de senha por análise de frequência`
O ataque consiste em obter a senha geradora do criptograma a partir do seu conteúdo. O método utilizado é a análise de frequência de letras.