
# C00000100 – Faça um algoritmo que leia um valor (inteiro) N da memória de dados (byte), que representa o lado de um quadrado, e calcule a área do quadrado. O resultado (área do quadrado) deve ser escrito no intervalo de endereço [1][2] da memória principal no formato de word (16 bits).

.text

# Leitura de N para o banco de registradores
li 0,0
lb $r0,$t0

mul 00,0,$r0,$r0
li 0,1
sw $t0,$r0

halt

.data

.byte 5 # Lado do quadrado no byte [0] da memória de dados
