
# C00000106 – Faça um algoritmo que leia um valor (inteiro) N da memória de dados (byte) e escreva no endereço [0] da memória principal no formato de byte (8 bits) o seguinte resultado: 0, se o valor é par; 1, se o valor é ímpar.

.text

li 0,0
lb $r0,$t0 # Leitura da constante

li 1,2
mod 00,0,$r0,$t1

# Escreve $r1 no endereço [2][3]
li 0,1
sb $t0,$r0

halt

.data

.byte 10 # Constante a ser lida
.byte 0 # Endereço de escrita da saída do programa
