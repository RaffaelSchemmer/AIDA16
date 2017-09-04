.text

# Inicializa $r0 com o byte [0] a ser calculado (fatorial)
li 0,0
lb $r0,$t0

# Inicializa $r1 com N com o valor decrementado do fatorial
mov $r0,$r1

# Inicializa $t0 com 1 a ser o contador do programa
li 0,1

# Inicializa $r2 com N a ser o contador do fatorial
mov $r1,$r2

dec 00,0,$r1
mul 00,0,$r2,$r1
inc 00,0,$t0
mov $r0,$r3
div 00,1,$t0,$r3
jz -6

li 0,1
sw $t0,$r2

halt

.data

.byte 5
.word 0

