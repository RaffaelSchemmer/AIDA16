.text

#### NOP

# Instrução que não faz nada
nop

#### NOP

#Instrução que finaliza o simulador
halt

# ARITMÉTICAS [8] (Todas as combinações possíveis)

nop

#### SOMA

# Soma direta do conteúdo de ($r0 + $r1) que guarda resultado em 0 ($r0)
add 00,0,$r0,$r1

# Soma direta do conteúdo de ($r0 + $r1) que guarda resultado em 1 ($r1)
add 00,1,$r0,$r1

# Soma indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 0 ($r0)
add 01,0,$r0,$r1

# Soma indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 1 ($r1)
add 01,1,$r0,$r1

# Soma imediata do conteúdo do campo (constante). Guarda o resultado em 0 ($t0)
add 10,0,2,3

# Soma imediata do conteúdo do campo (constante). Guarda o resultado em 1 ($t1)
add 10,1,4,5

#### SUBTRAÇÃO

# Subtrai direta do conteúdo de ($r0 + $r1) que guarda resultado em 0 ($r0)
sub 00,0,$r0,$r1

# Subtrai direta do conteúdo de ($r0 + $r1) que guarda resultado em 1 ($r1)
sub 00,1,$r0,$r1

# Subtrai indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 0 ($r0)
sub 01,0,$r0,$r1

# Subtrai indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 1 ($r1)
sub 01,1,$r0,$r1

# Subtrai imediata do conteúdo do campo (constante). Guarda o resultado em 0 ($t0)
sub 10,0,2,3

# Subtrai imediata do conteúdo do campo (constante). Guarda o resultado em 1 ($t1)
sub 10,1,4,5

#### INCREMENTO

# Incremento direto do conteúdo de ($r0 + 1) que guarda resultado em 0 ($r0)
inc 00,0,$r0

# Incremento direto do conteúdo de ($r0 + 1) que guarda resultado em 1 ($r0)
inc 00,1,$r0

# Incremento indireto do conteúdo do registrador apontado por $r0 por 1 e que guarda o resultado em 0 ($r0)
inc 01,0,$r0

# Incremento indireto do conteúdo do registrador apontado por $r0 por 1 e que guarda o resultado em 1 ($r0)
inc 01,1,$r0

# Incremento imediato do conteúdo do campo (constante). Guarda o resultado em 0 ($t0)
inc 10,0,2

# Incremento imediato do conteúdo do campo (constante). Guarda o resultado em 1 ($t1)
inc 10,1,2

#### DECREMENTO

# decremento direto do conteúdo de ($r0 - 1) que guarda resultado em 0 ($r0)
dec 00,0,$r0

# decremento direto do conteúdo de ($r0 - 1) que guarda resultado em 1 ($r0)
dec 00,1,$r0

# decremento indireto do conteúdo do registrador apontado por $r0 por 1 e que guarda o resultado em 0 ($r0)
dec 01,0,$r0

# decremento indireto do conteúdo do registrador apontado por $r0 por 1 e que guarda o resultado em 1 ($r0)
dec 01,1,$r0

# decremento imediato do conteúdo do campo (constante). Guarda o resultado em 0 ($t0)
dec 10,0,2

# decremento imediato do conteúdo do campo (constante). Guarda o resultado em 1 ($t1)
dec 10,1,2

#### MULTIPLICAÇÃO

# multiplicação direta do conteúdo de ($r0 * $r1) que guarda resultado em 0 ($r0)
mul 00,0,$r0,$r1

# multiplicação direta do conteúdo de ($r0 * $r1) que guarda resultado em 1 ($r1)
mul 00,1,$r0,$r1

# multiplicação indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 0 ($r0)
mul 01,0,$r0,$r1

# multiplicação indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 1 ($r1)
mul 01,1,$r0,$r1

# multiplicação imediata do conteúdo do campo (constante). Guarda o resultado em 0 ($t0)
mul 10,0,2,3

# multiplicação imediata do conteúdo do campo (constante). Guarda o resultado em 1 ($t1)
mul 10,1,4,5

#### DIVISÃO

# divisão direta do conteúdo de ($r0 / $r1) que guarda resultado em 0 ($r0)
div 00,0,$r0,$r1

# divisão direta do conteúdo de ($r0 / $r1) que guarda resultado em 1 ($r1)
div 00,1,$r0,$r1

# divisão indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 0 ($r0)
div 01,0,$r0,$r1

# divisão indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 1 ($r1)
div 01,1,$r0,$r1

# divisão imediata do conteúdo do campo (constante). Guarda o resultado em 0 ($t0)
div 10,0,2,3

# divisão imediata do conteúdo do campo (constante). Guarda o resultado em 1 ($t1)
div 10,1,4,5

#### RESTO DA DIVISÃO

# resto da divisão inteira entre dois números. Guarda o resultado em 0 (
mod 00,0,$r0,$r1

# divisão direta do conteúdo de ($r0 / $r1) que guarda resultado em 1 ($r1)
mod 00,1,$r0,$r1

# divisão indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 0 ($r0)
mod 01,0,$r0,$r1

# divisão indireta do conteúdo do registrador apontado por $r0 e por $r1 e que guarda o resultado em 1 ($r1)
mod 01,1,$r0,$r1

# divisão imediata do conteúdo do campo (constante). Guarda o resultado em 0 ($t0)
mod 10,0,2,3

# divisão imediata do conteúdo do campo (constante). Guarda o resultado em 1 ($t1)
mod 10,1,4,5

# LÓGICAS [8]

# Transferência de Memória [7]

# (LOAD) CARGA DE CONSTANTE (li/lui) PARA REGISTRADOR

# Carga de constante 2 para a parte BAIXA dos bits do registrador $t0
li 0,2

# Carga de constante 2 para a parte BAIXA dos bits do registrador $t1
li 1,2

# Carga de constante 1 para a parte ALTA dos bits do registrador $t0
lui 0,1

# Carga de constante 2 para a parte ALTA dos bits do registrador $t1
lui 1,2

# (LOAD) CARGA DE BYTE (lb) e WORD (lw) DA MEMÓRIA PARA REGISTRADOR

# Carga da posição de memória (byte) apontada por $r1 parte a parte baixa de $r0 
# ($r0 <- MEM[$r1])
lb $r0,$r1

# Carga de duas posições de memória (word) apontada por $r1 parte o registrador $r0
# ($r0 <- MEM[$r1])
lw $r0,$r1

# (STORE) CARGA DE BYTE (lb) e WORD (lw) DO REGISTRADOR PARA MEMÓRIA 
# (MEM[$r0] <- $r1)
sw $r0,$r1

# Carga de duas posições de memória (word) apontada por $r1 parte o registrador $r0
# (MEM[$r0] <- $r1)
sb $r0,$r1

# Instrução que copia o endereço de $r1 para $r0 ($r1 <- $r0)
mov $r0,$r1

# Salto [7]

# Salta dez posições para frente na memória de instrução se o resultado da instrução anterior for zero
jz 10

# Salta dez posições para trás na memória de instrução se o resultado da instrução anterior for zero
jnz -10

# Salta dez posições para frente na memória de instrução se o resultado da instrução der overflow
jv 10

# Salta dez posições para frente na memória de instrução se o resultado da instrução não der overflow
jnv -10

# Salta dez posições para frente na memória de instrução se o resultado da instrução der carry
jc 10

# Salta dez posições para frente na memória de instrução se o resultado da instrução não der carry
jnc -10

# Salta dez posições para frente na memória de instrução quando encontrar esta instrução
jmp 10


.data

#.byte cria um dado de 8 bits na memória de dados

.byte 2

#.word cria um dado de 16 bits na memória de dados

.word 16
