.text

#Bubble-sort usando o simulador do computador hipotético AIDA16
#Trabalho realizado para a disciplina Arquitetura de Computadores I
#Alunos: Clodoaldo Ivan Fávero Sobrinho, Maridiane Lugaresi
#O AIDA16 é uma arquitetura hipotética desenvolvida por Rodrigo Motta em seu TCC
#O montador e simulador para a arquitetura foram desenvolvidos por Rafael Schemmer 


########## Estrutura geral ##########
# Os valores iniciarão na memória principal
# e serão carregados para os registradores $r0 a $r9.
#
# O registrador $r10 irá guardar o tamanho do vetor - 1,
# sendo utilizado como variável de comparação para testar se chegou ao final do loop.
#
# Os registradores $t0 e $t1 conterão as variáveis de controle dos loops
# externo e interno, respectivamente (seriam os nossos i e j).
#
# O registrador $r11 será usado para guardar o valor de $t0 ou $t1, e usado
# para subtrair $t0 ou $t1 de TAMANHO, guardando o resultado para checar se é 0
# e sair do loop. Antes da subtração deverá receber o valor de $t0 ou $t1.
#
# Como o bubble-sort compara os elementos $r[j] $r[j + 1], será necessário mais um
# registrador que guarde o valor de j e o incremente, tornando-o j + 1.
# Para isso, será utilizado também o $r11.
# 
# O registrador $r12 guarda o endereço 13, será utilizado como ponteiro para auxiliar na comparação.
#
# $r13 armazenará temporariamente o valor de $r[$t1]


### 1. Lendo os valores da memória
### Aproveitamos o fato dos registradores já estarem inicializados em 0 
### para transferir valores através da adição com modo de endereçamento INDIRETO. 
### Por exemplo, se o valor no endereço apontado por $t0 for zero ($r[$t0] = 0),  
### uma instrução add 01, 0, $t0, $t1 acaba se tornando na prática uma cópia do valor 
### no endereço apontado por $t1 para o endereço apontado por $t0, conforme exemplo abaixo.
###
## div 01, 0, $t0, $t1, supondo que $r[$t0] = 0 e $r[$t1] = 5
## É o mesmo que: $r[$t0] = $r[$t0] + $r[$t1]
## Porém, como $r[$t0] = 0, temos que 
## $r[$t0] = 0 + $r[$t1], logo:
## $r[$t0] = $r[$t1]


li 1, 10              #Quantidade de elementos que serão lidos da memória, e ao mesmo tempo 
                      #serve como ponteiro para $r10

### INICIO DO LOOP 

lb $r10, $t0          # $r10 = memoria[$t0] Guarda em $r10 o valor no endereço de memória apontado por $t0 
add 01, 0, $t0, $t1   # $r[$t0] = $r[$t0] + $r[t1], como $r[$t0] = 0 e $t1 = 10, temos que $r[$t0] = 0 + $r[10], e portanto $r[$t0] = $r[10]
inc 00, 0, $t0        # $t0 = $t0 + 1
mov $t0, $r10         # $r10 = $t0
sub 00, 0, $r10, $t1  # $r10 = $r10 - $t1
jnz -6                # volta -6

### SAI DO LOOP  

### Fim da leitura de valores da memória


### Definindo os parametros iniciais
li 1, 13
mov $t1, $r12 #### $r12 guarda o endereço 13

### (Tamanho do vetor - 1) ficara armazenado em $r10
li 1, 9  
mov $t1, $r10  

### Inicialização da variável contadora do loop externo (i)
li 0, 0 # i = 0

### Inicialização da variável de controle do loop interno (j)
li 1, 0 # j = 0

### Loop interno
mov $t1, $r11 
inc 00, 0, $r11       #### $r11 = $t1 + 1

### INICIO COMPARACAO
## PROBLEMA: div 01, 0, $t1, $r11. Sobrescreve o valor de $r[$t1]. 
## SOLUÇÃO: guardar $r[$t1] temporariamente em outro registrador.
## $r[$t1] será guardado em $r13, através da adição com modo
## de endereçamento indireto, utilizando $r12 como ponteiro para $r13.
## Para isso funcionar, devemos nos certificar que $r13 contenha 0 antes
## de efetuarmos a adição.
##
## Também devemos lembrar de devolver o valor a $r[$t1] ao final da comparação.
## Para isso, vamos nos aproveitar do fato que $r11 guarda o valor $t1 + 1, 
## então copiaremos o valor de $r11 para $t1, e utilizaremos a operação de decremento em $t1,
## assim restaurando seu valor original.


sub 00, 0, $r13, $r13 # Reseta $r13 para 0
add 01, 0, $r12, $t1  # Como $r12 = 13, e $r13 = 0 temos que: $r[13] = 0 + $r[$t1], logo $r[13] = $r[$t1]
div 01, 0, $t1, $r11   
jz 6                  # Se der zero, não executa o bloco de troca, pois $r[$t1] < $r[$t1 + 1], logo já estão em ordem crescente

### INICIO TROCA 
## Para a troca, utilizaremos adição e subtração, conforme o exemplo abaixo. 
## Suponha que x = 3 e y = 5, como trocar os valores entre x e y com adição e subtração?
## Passo 1: x = x + y  >>>  x = 3 + 5  >>>  x = 8
## Passo 2: y = x - y  >>>  y = 8 - 5  >>>  y = 3 
## Passo 3: x = x - y  >>>  x = 8 - 3  >>>  x = 5

sub 01, 0, $t1, $t1      # zera o registrador apontado por $t1 
add 01, 0, $t1, $r12     # $r[t1] = $r[$t1] + $r[$r12], como $r[$t1] = 0, e $r12 = 13, temos que: $r[$t1] = 0 + $r[13], logo $r[$t1] = $r[13]
add 01, 0, $t1, $r11     # $r[$t1] = $r[$t1] + $r[$r11]
sub 01, 1, $t1, $r11     # $r[$r11] = $r[$t1] - $r[$r11] 
sub 01, 0, $t1, $r11     # $r[$t1] = $r[$t1] - $r[$r11]
jmp 1                    # Pula a próxima instrução e vai para o fim do bloco de instruções do loop interno

### FIM TROCA
# temos que devolver o valor para $r[$t1], caso não tenha entrada na função troca
add 01, 0, $t1, $r12     #### como $r[t1] = 0, e $r12 = 13, estamos devolvendo o valor de $r[$t1]

### FIM COMPARACAO

### Fim do bloco de instruções do loop interno 
inc 00, 0, $t1        #### $t1 = $t1 + 1 (j++) (incremento da variável de controle)
mov $t1, $r11         #### $r11 = $t1
mov $r10, $r13        #### $r13 = tamanho - 1
sub 00, 0, $r13, $t0  #### $r13 = tamanho - 1 - i
sub 00, 0, $r11, $r13 #### $r11 = $r11 - $r1    #### Lembrando que $r13 = tamanho - 1 - i
jnz -19               #### se $r11 - $r13 != 0, volta pra execução do bloco do loop interno (mov $t1, $r11)
### Saída do loop interno

### Fim do bloco de instruções do loop externo
inc 00, 0, $t0        #### $t0 = $t0 + 1 (i++)
mov $t0, $r11         #### $r11 = $t0
sub 00, 0, $r11, $r10 #### $r11 = $r11 - $r10  #### Lembrando que $r10 = tamanho - 1
jnz -24             #### se $r11 - $r10 != 0, entra para a inicialização de j (li 1, 0)
### Saída do loop externo

### Ordenação concluída


### Armazenano os valores ordenados na memória
li 0, 10
mov $t0, $r13 ### $r13 = tamanho 
li 0, 0 
mov $t0, $r12 #### $r12 = variável de controle
li 1, 10      #### $t1 = ponteiro para $r10
sub 00, 0, $r10, $r10
####### INICIO DO LOOP ########
add 01, 0, $t1, $r12
sb $r12, $r10
inc 00, 0, $r12
sub 00, 0, $r10, $r10
mov $r12, $r11
sub 00, 0, $r11, $r13
jnz -7
########  SAI DO LOOP  ########


halt # Fim

.data

.byte 55
.byte 50
.byte 45
.byte 40
.byte 35
.byte 30
.byte 25
.byte 20
.byte 15
.byte 10
