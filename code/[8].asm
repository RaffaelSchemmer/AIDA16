
# C00000107 – Faça um algoritmo que leia dois valores (inteiros) da memória de dados (byte) e escreva no endereço [0] da memória principal no formato de byte (8 bits) o maior dos números lidos.

.text

li 0,1
lb $r0,$t0 # Leitura da constante

li 0,2
lb $r1,$t0 # Leitura da constante

mov $r0,$r2
add 00,0,$r2,$r1 # (V1 + V2)

mov $r0,$r3
sub 00,0,$r3,$r1 # (V1 - V2)

li 0,-1
mul 00,0,$t0,$r3
add 00,0,$t0,$r3
# Pula se forem diferentes (não precisa fazer módulo)
jz 2
li 0,-1
mul 00,1,$t0,$r3 # (|V1-V2|)

add 00,0,$r2,$r3 # (V1+V2 + |V1-V2|) 
li 0,2
div 00,0,$r2,$t0 # (V1+V2 + |V1-V2|) / 2


# Escreve $r2 no endereço [0]
li 0,0
sb $t0,$r2

halt

.data

.byte 0 # Endereço de escrita do resultado
.byte 40 # Primeiro valor
.byte 10 # Segundo valor
