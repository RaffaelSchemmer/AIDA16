
# C00000105 – Faça um algoritmo que leia um valor (inteiro) N da memória de dados (byte) e escreva no endereço [0] da memória principal no formato de byte (8 bits) o seguinte resultado: (i) 0, se o valor é zero; (ii) 1, se o valor é maior que zero; (iii) -1, se o valor é negativo.

.text

li 0,0
lb $r0,$t0 # Leitura da constante

li 0,0
xor 00,0,$t0,$r0 # Se for ZERO
jz 5

li 0,1
xor 00,0,$t0,$r0 $ Se for 1
jz 7

li 0,-1
li 1,0
sb $t1,$t0 # Leitura da constante
halt

li 0,0
li 1,0
sb $t1,$t0 # Leitura da constante

halt

li 0,-1
li 1,0
sb $t1,$t0 # Leitura da constante

halt

.data

.byte 2 # [1]
