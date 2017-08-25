###############################################################################
# Bloco de leitura de bytes da memória de dados para o banco de registradores #
###############################################################################

.text # Aponta para as instruções do programa (memória de instruções)

li 0,0 # Carrega o número 0 para o registrador $t0
lb $r0,$t0 # Carrega o endereço (byte) 0 da memória de dados para o registrador $r0

li 0,1 # Carrega o número 1 para o registrador $t0
lb $r1,$t0 # Carrega o endereço (byte) 1 da memória de dados para o registrador $r1

li 0,2 # Carrega o número 2 para o registrador $t0
lb $r2,$t0 # Carrega o endereço (byte) 2 da memória de dados para o registrador $r2

li 0,3 # Carrega o número 3 para o registrador $t0
lb $r3,$t0 # Carrega o endereço (byte) 3 da memória de dados para o registrador $r3

li 0,4 # Carrega o número 4 para o registrador $t0
lb $r4,$t0 # Carrega o endereço (byte) 4 da memória de dados para o registrador $r4

li 0,5 # Carrega o número 5 para o registrador $t0
lb $r5,$t0 # Carrega o endereço (byte) 5 da memória de dados para o registrador $r5

li 0,6 # Carrega o número 6 para o registrador $t0
lb $r6,$t0 # Carrega o endereço (byte) 6 da memória de dados para o registrador $r6

li 0,7 # Carrega o número 7 para o registrador $t0
lb $r7,$t0 # Carrega o endereço (byte) 7 da memória de dados para o registrador $r7

li 0,8 # Carrega o número 8 para o registrador $t0
lb $r8,$t0 # Carrega o endereço (byte) 8 da memória de dados para o registrador $r8

#####################################################
# Bloco das instruções aritméticas (Modo direto 00) #
#####################################################

add 00,0,$r0,$r1 # Soma o conteúdo do $r0 com o conteúdo do $r1 e coloca em $r0
sub 00,0,$r0,$r1 # Subtrai o conteúdo de $r0 com o conteúdo de $r1 e coloca em $r0
mul 00,1,$r0,$r1 # Multiplica o conteúdo de $r0 com o conteúdo de $r1 e coloca em $r1
div 00,1,$r5,$r7 # Divide o conteúdo de $r5 com o conteúdo de $r7 e coloca em $r5
inc 00,0,$r0 # Incrementa o valor de $r0 em uma unidade (+1)
dec 00,0,$r1 # Decrementa o valor de $r0 em uma unidade (-1)
mod 00,0,$r6,$r7 # Captura o resto da divisão de $r6 por $r7 colocando o resultado em $r6
mov $r0,$r1 # Move o conteúdo do registrador $r0 para o registrador $r1

#######################################################
# Bloco das instruções aritméticas (Modo imediato 10) #
#######################################################

add 10,0,2,3 # Soma o número 2 com o número 3 e coloca em $t0
sub 10,0,3,2 # Subtrai o número 3 com o número 2 e coloca em $t0
mul 10,1,5,4 # Multiplica o número 5 com o número 4 e coloca em $t1
div 10,1,4,2 # Divide o número 4 pelo número 2 e coloca em $t1
mod 10,1,8,4 # Captura o resto da divisão de 8 e de 4 colocando o resultado em $t1

#######################################################
# Bloco das instruções aritméticas (Modo indireto 01) #
#######################################################

li 0,0 # Carrega o número 1 para o registrador $t0
li 1,1 # Carrega o número 2 para o registrador $t1

lb $r10,$t0 # 
lb $r11,$t1 # 

li 0,10 # Carrega o número 1 para o registrador $t0
li 1,20 # Carrega o número 2 para o registrador $t1

lb $r0,$t0 # 
lb $r1,$t1 # 

add 10,0,$r10,r11 # Soma o conteúdo apontado por $r0 e o por $r1

################################
# Bloco das instruções lógicas #
################################

li 0,16 # Carrega o número 16 para o registrador $t0
mov $t0,$r1 # Move o conteúdo do registrador $r0 para o registrador $r1

and 00,0,$r0,$r1 # Realiza a operação AND entre os dados de $r0 e $r1
or 00,0,$r0,$r2 # Realiza a operação OR entre os dados de $r0 e $r1
xor 00,0,$r0,$r3 # Realiza a operação XOR entre os dados de $r0 e $r1
not 00,0,$r0 # Realiza a operação NOT entre os dados de $r0


li 0,16 # Carrega o número 16 para o registrador $t0
mov $t0,$r1 # Move o conteúdo do registrador $t0 para o registrador $r1

shr 00,0,$r1 # Desloca um bit para a direita (divide o número) presente em $r1
shl 00,0,$r1 # Desloca um bit para a esquerda (multiplica o número) presente em $r1
ror 00,0,$r1 # Realiza a rotação do bit menos significativo para o mais significativo
rol 00,0,$r1 # Realiza a rotação do bit mais significativo para o menos significativo

###############################################################################
# Bloco de escrita de bytes da memória de dados para o banco de registradores #
###############################################################################

lui 0,1 # Carrega o número 1 para os 8 bits mais significativos do registrador (00000001 00000000) ou 256.
li 1,0 # Carrega o número 0 para o registrador $t1
sb $t1,$r1 # Carrega para o endereço 0 da memória de dados (apontado por $t1) o conteúdo do registrador $r1

nop # Instrução que não faz nada

halt

.data # Aponta para os dados do programa (memória de dados)

.byte 9
.byte 8
.byte 7
.byte 6
.byte 5
.byte 4
.byte 3
.byte 2
.byte 1
