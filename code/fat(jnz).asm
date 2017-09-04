.text

# Inicializa $r0 com o byte [0] a ser calculado (fatorial)
li 0,0
lb $r0,$t0


# Inicializa $r1 com 1 a ser o buffer do fatorial
li 0,1
mov $t0,$r1

mul 00,1,$r0,$r1
dec 00,0,$r0
jnz -3

li 0,1
sw $t0,$r1

halt

.data

.byte 5
.word 0
