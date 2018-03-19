#
# Facilidades oferecidas por uma linguagem de programação de alto nível (C)
#
# Operadores aritméticos (+ - * / ^ %)
# 
# + : Utilizar instrução de soma (ADD)
# Exemplo : add 00,0,$r0,$r1 (Soma o conteúdo de $r0 por $r1 e coloca o resultado em $r0)
# 
# - : Utilizar instrução de soma (SUB)
# Exemplo: sub 00,0,$r0,$r1 (Subtrai o conteúdo de $r0 por $r1 e coloca o resultado em $r0)
#
# * : Utilizar instrução de soma (MUL)
# Exemplo: mul 00,0,$r0,$r1 (Multiplica o conteúdo de $r0 por $r1 e coloca o resultado em $r0)
#
# / : Utilizar instrução de soma (DIV)
# Exemplo: div 00,0,$r0,$r1 (Divide o conteúdo de $r0 por $r1 e coloca o resultado em $r0)
#
# % : Utilizar instrução de mod (MOD)
# Exemplo: mod 00,0,$r0,$r1 (Captura o resto de $r0 por $r1 e coloca o resultado em $r0)
#
# ^ : Utilizar instrução de jz e dec (laço de repetição)
#
# Carrega em $t0 a base e em $t1 o expoente.
# dec decrementa em uma unidade $t1 e jnz faz o laço executar $t1 vezes
# li 0,2
# li 1,3
# mul 00,0,$r0,$r0 
# dec 00,0,$t1
# jnz -2
#
#
#
# Operadores relacionais (> < == != >= <=)
# Os exemplos são estruturas condicionais do tipo (IF)
#
# < : Utilize a instrução de divisão e a instrução jz 
#
# Salta para frente se $r0 for menor que $r1 (2/3 resulta em 0) 
# div 00,0,$r0,$r1
# jz 10
#
# > : Utilize a instrução de divisão e a instrução jnz
#
# Salta para frente se $r0 for menor que $r1 (3/2 resulta em 1) 
# div 00,0,$r0,$r1
# jnz 10
#
# == : Utilize a instrução de subtração e a instrução jz 
#
# Salta para frente se $r0 for igual que $r1 (3 - 3 resulta em 0) 
# sub 00,0,$r0,$r1
# jz 10
#
# != : Utilize a instrução de subtração e a instrução jnz 
#
# Salta para frente se $r0 for menor que $r1 (2/3 resulta em 0) 
# sub 00,0,$r0,$r1
# jnz 10
#
# <= : Utilize a instrução de divisão e a instrução jz 
#
# Salta para frente se $r0 for igual que $r1 (3 - 3 resulta em 0) 
# sub 00,0,$r0,$r1
# jz 12
# Salta para frente se a divisão de $r0 por $r1 for 0 (2/3 resulta em 0) 
# div 00,0,$r0,$r1
# jz 10
#
# >= : Utilize a instrução de divisão e a instrução jz 
#
# Salta para frente se $r0 for igual que $r1 (3 - 3 resulta em 0) 
# sub 00,0,$r0,$r1
# jz 12
# Salta para frente se a divisão de $r0 por $r1 for 0 (3/2 resulta em 1) 
# div 00,0,$r0,$r1
# jnz 10
#
# Estrutura de repetição pré-testada do maior pro menor (DO-WHILE)
#
# Laço de repetição que repete 3 vezes e soma 3+2+1 a $t0
# li 0,0
# li 1,3
# add 00,0,$t0,$t1 
# dec 00,0,$t1
# jnz -2
