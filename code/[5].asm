
# C00000104 – O produto escalar AxB de dois vetores A=[a1,a2,a3...] e B=[b1,b2,b3...] é dado pelo somatório a1*b1+a2*b2+a3*b3+.... Faça um algoritmo que leia da memória de dados (byte) dos endereços [2][7] as coordenadas ax,ay,az,bx,by,bz de dois vetores no espaço tridimensional e calcule e escreva seu produto escalar. O resultado deve ser escrito no endereço [0][1] da memória principal no formato de word (16 bits).

.text

li 0,2
lb $r1,$t0 # Leitura de A1

li 0,3
lb $r2,$t0 # Leitura de A2

li 0,4
lb $r3,$t0 # Leitura de A3

li 0,5
lb $r4,$t0 # Leitura de B1

li 0,6
lb $r5,$t0 # Leitura de B2

li 0,7
lb $r6,$t0 # Leitura de B3

mul 00,0,$r1,$r4

mul 00,0,$r2,$r5

mul 00,0,$r3,$r6

add 00,0,$r1,$r2
add 00,0,$r1,$r3

# Escreve $r1 no endereço [0][1]
li 0,0
sw $t0,$r1

halt

.data

.word 0 # PE [0][1]

.byte 1 # A1 [2]
.byte 2 # A2 [3]
.byte 3 # A3 [4]
.byte 4 # B1 [5]
.byte 5 # B2 [6]
.byte 6 # B3 [7]
