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


#################################
# Bloco das instruções de salto #
#################################

######
# Exemplo de uso da instrução de salto jnz
######

li 0,5 # Carrega o número 5 para o registrador $t0
mov $t0,$r9
li 0,1 # Carrega o número 1 para o registrador $t0
mov $t0,$r10
nop
nop
sub 00,0,$r9,$r10
jnz -4

######
# Exemplo de uso da instrução de salto jz (condicional) e jmp (incondicional)
######

li 0,5 # Carrega o número 5 para o registrador $t0
mov $t0,$r9
li 0,1 # Carrega o número 1 para o registrador $t0
mov $t0,$r10
nop
nop
sub 00,0,$r9,$r10
jz 2
jmp -5
nop # Instrução que não faz nada
halt # Finaliza a execução do simulador (termina o programa)

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
