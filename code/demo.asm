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
#
#
# Operadores relacionais (> < == != >= <=)
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
# <= : Utilize a instrução de divisão e a instrução jz 
#
# Salta para frente se $r0 for igual que $r1 (3 - 3 resulta em 0) 
# sub 00,0,$r0,$r1
# jz 12
# Salta para frente se a divisão de $r0 por $r1 for 0 (2/3 resulta em 0) 
# div 00,0,$r0,$r1
# jz 10
