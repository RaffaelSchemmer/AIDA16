
# C00000103 – O produto vetorial AxB de dois vetores A=[ax,ay] e B=[bx,by] é um vetor perpendicular ao plano formado pelos vetores A e B, de módulo igual a |ax*by-ay*bx|. Faça um algoritmo que leia as componentes ax,ay,bx,by dos vetores A e B da memória de dados (word) nos endereços [2][9] e calcule e escreva o módulo do vetor resultante do produto vetorial. O resultado deve ser escrito no endereço [0][1] da memória principal no formato de word (16 bits).

.text

li 0,2
lw $r1,$t0 # Leitura de AX

li 0,4
lw $r2,$t0 # Leitura de AY

li 0,6
lw $r3,$t0 # Leitura de BX

li 0,8
lw $r4,$t0 # Leitura de BY

mul 00,0,$r1,$r4 # A = AX * BY

mul 00,0,$r2,$r3 # B = AY * BX

sub 00,0,$r1,$r2 # X = A - B

# Realiza módulo se número for negativo

mov $r1,$t0 # $t0 = $r1
shl $t0 # Desloca o bit mais significativo (negativo) para a esquerda
jc 2 # Pula duas unidades se der carry
li 0,-1 # $t0 = -1
mul 00,0,$r1,$t0 # Faz número negativo se tornar positivo (NUM * -1)

li 0,0 # Escreve $r1 no endereço [0][1]
sw $t0,$r1

halt

.data

.word 0 # [0][1]
.word 2 # AX [2][3]
.word 2 # AY [4][5]
.word 3 # BX [6][7]
.word 4 # BY [8][9]

