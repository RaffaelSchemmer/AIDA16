###############################################################################
# Bloco de leitura de bytes da memória de dados para o banco de registradores #
###############################################################################

.text # Aponta para as instruções do programa (memória de instruções)

li 0,1 # Carrega o número 0 para o registrador $t0
lb $r0,$t0 # Carrega o endereço (byte) 0 da memória de dados para o registrador $r0

li 0,2 # Carrega o número 1 para o registrador $t0
lb $r1,$t0 # Carrega o endereço (byte) 1 da memória de dados para o registrador $r1

li 0,3 # Carrega o número 2 para o registrador $t0
lb $r2,$t0 # Carrega o endereço (byte) 2 da memória de dados para o registrador $r2

li 0,4 # Carrega o número 3 para o registrador $t0
lb $r3,$t0 # Carrega o endereço (byte) 3 da memória de dados para o registrador $r3

li 0,5 # Carrega o número 4 para o registrador $t0
lb $r4,$t0 # Carrega o endereço (byte) 4 da memória de dados para o registrador $r4

li 0,6 # Carrega o número 5 para o registrador $t0
lb $r5,$t0 # Carrega o endereço (byte) 5 da memória de dados para o registrador $r5

li 0,7 # Carrega o número 6 para o registrador $t0
lb $r6,$t0 # Carrega o endereço (byte) 6 da memória de dados para o registrador $r6

li 0,8 # Carrega o número 7 para o registrador $t0
lb $r7,$t0 # Carrega o endereço (byte) 7 da memória de dados para o registrador $r7

li 0,9 # Carrega o número 8 para o registrador $t0
lb $r8,$t0 # Carrega o endereço (byte) 8 da memória de dados para o registrador $r8


###################################################
# Programa que soma N números da memória de dados #
###################################################

li 0,0
mov $t0,$r10 # $r10 guarda o somatório

li 0,10
mov $t0,$r11 # $r11 vai apontar para o $r10

li 0,9
mov $t0,$r9 # $r9 Será o registrador que guardará o número de interações do laço

add 01,0,$r11,$r9 # Soma no registrador apontado por $r11 (10) o conteúdo dos registradores do intervalo de $r8 a $r0
dec 00,0,$r9 # Decrementa uma unidade (-1) do registrador $r9
jnz -3 # Pula 3 instruções para trás (considerando jnz -3) caso a flag zero da instrução dec for diferente de zero

li 0,0 # Caso não pular, escreve 0 no registrador $t0
sb $t0,$r10 # Escreve o conteúdo do registrador $r10 na memória de dados (endereço 0), apontado por $t0
halt # Termina a execução do simulador

.data # Aponta para os dados do programa (memória de dados)

.word 9
.byte 8
.byte 7
.byte 6
.byte 5
.byte 4
.byte 3
.byte 2
.byte 1










