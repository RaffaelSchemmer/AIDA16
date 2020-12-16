# C00000109 – Faça um algoritmo que leia dois valores (inteiros) da memória de dados (byte) e escreva no intervalo de endereços [0][3] da memória principal no formato de word (16 bits) os números em ordem decrescente.

.text
li 0,4 
li 1,5
lb $r0,$t0
lb $r1,$t1
li 0,0
li 1,1
div 01,0,$t0,$t1
jz 5
li 0,0
li 1,2
lw $r1,$t0
lw $r0,$t1
lw $r0,$t0
lw $r1,$t1
halt

.data
.word 0
.word 0
.byte 2
.byte 4