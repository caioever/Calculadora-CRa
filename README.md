# Calculadora-CRa
Uma simples calculadora de CR(coeficiente de rendimento) em C

## Introdução

O CRa é calculado com as médias de cada materia, multiplicado pelas horas que a matéria tem e dividido pela soma das horas.

Um exemplo de como os dados são coletados:

(10.0:60 
10.0:60
10.0:60
10.0:60) -- > Aqui são as matérias

10.0:60 --- > o campo da esquerda é a nota em ponto flutuante, a da direita são as horas Notas:Horas
10.0:60
10.0:60
10.0:60
        --- > toda vez que você pular a linha ele vai entender como fim das medias do periodo
10.0:60
10.0:60
10.0:60

## Como compilar

```
$ gcc calculadora_CR.c -o calculadora_CR
```