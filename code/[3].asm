
# C00000102 – Faça um algoritmo que leia um valor (inteiro) da memória de dados (word), entre 0 e 9999 e escreva no intervalo de endereços [2][3] da memória principal no formato de word (16 bits), a soma dos seus dígitos. Dica: O dígito menos significativo de um número inteiro pode ser obtido pelo resto da divisão do número por 10. Os dígitos restantes podem ser obtidos pela divisão inteira por 10.

.text

li 0,0
lb $r0,$t0 # Leitura da constante

li 0,0
lw $r0,$t0 # Leitura da constante

li 0,1
mov $r10,$t0 # Leitura de 1 em $r10

li 0,2
lw $r11,$t0 # Leitura de 10 em $r11

li 0,4
lw $r12,$t0 # Leitura de 100 em $r12

li 0,6
lw $r13,$t0 # Leitura de 1000 em $r13

mov $r0,$r1
div 00,0,$r1,$r13 # Primeiro termo da constante
mod 00,0,$r0,$r13

mov $r0,$r2
div 00,0,$r2,$r12 # Segundo termo da constante
mod 00,0,$r0,$r12

mov $r0,$r3
div 00,0,$r3,$r11 # Terceiro termo da constante
mod 00,0,$r0,$r11

mov $r0,$r4

add 00,0,$r1,$r2
add 00,0,$r1,$r3
add 00,0,$r1,$r4

# Escreve $r1 no endereço [2][3]
li 0,2
sw $t0,$r1

halt

.data

.word 6565 # Número de 4 dígitos
.word 10 # Constante 10
.word 100 # Constante 100
.word 1000 # Constante 1000

