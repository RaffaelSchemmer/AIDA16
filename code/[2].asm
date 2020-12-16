
# C00000101 – Faça um algoritmo que leia um valor (inteiro) da memória de dados (word), referente a uma hora/minuto/segundo (porem toda ela em segundos apenas) e escreva no intervalo de endereços [2][7] da memória principal no formato de word (16 bits), o número de horas, minutos e segundos correspondente. Dica: Para converter segundos para minutos usa-se a divisão por 60.

.text

# Leitura de TIME para o banco de registradores $r0
li 0,0
lw $r0,$t0

# Carrega a constante 3600 para $r11
li 0,2
lw $r11,$t0

# Carrega a constante 60 para $r12
li 0,4
lb $r12,$t0

mov $r0,$r1
div 00,0,$r1,$r11 # Divide os segundos por 3600
mod 00,1,$r0,$r11

mov $r11,$r2
div 00,0,$r2,$r12 # Divide o que sobrar por 60
mod 00,1,$r11,$r12

li 0,2
sw $t0,$r1

li 0,4
sw $t0,$r2

li 0,6
sw $t0,$r12

halt

.data

.word 7170 # [0][1] Valor da hora em segundos
.word 3600 # [2][3] Quantidade de segundos de uma hora
.byte 60 # [4] Quantidade de segundos de um minuto

