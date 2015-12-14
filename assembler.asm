/* # Universidade Regional Integrada do Alto uruguai e das Missões */
/* # [TEST] Assembly code (ASM) that check's the assembler behavior */
/* # Class name : Final Graduate Work - 10th semester */
/* # Advisor : MSc. Carlos Alberto petry (carlos.petry@passofundo.ifsul.edu.br) */
/* # Student : Raffael Bottoli Schemmer (raffael.schemmer@gmail.br) */
/* # Finish Date (Last Revision) : 17/11/2009 (12:00 AM) */

#.text

############################################
##    (100%) Test of Non Operate TAG      ##
############################################

#nop                             - Ok 100% (Assembler accept this command)

############################################
##   (100%) Test of ADD Instructions (R)  ##
############################################

# Adding Instruction using direct mode (Corrent Sintax)
#add 00,1,$r9,$r4# 					     - Ok 100% (Assembler accept this command)
#add 01,1,$r12,$r3#              - Ok 100% (Assembler accept this command)
#add 00,1,$t0,$t1#               - Ok 100% (Assembler accept this command)
#add 10,1,2,1#		               - Ok 100% (Assembler accept this command)

# Adding Instruction using direct mode (Wrong Sintax)
#ad 02,1,$r9,$r4 # Opcode desconhecido 			- OK ERRO ENCONTRADO + 100%
#add 02,1,$r9,$r4 # Modo de enderecamento invalido	- OK ERRO ENCONTRADO + 100% 
#add 00,3,$r9,$r4 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#add 01,1,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#add 10,1,2,16 # Excesso de capacidade de representacao - OK ERRO ENCONTRADO + 100%
#add 01,1,$r12,$r16 # Registador nao representavel	- OK ERRO ENCONTRADO + 100%
#add 01,1,$r12,$r16,$r17 # Excesso de parametros direto - OK ERRO ENCONTRADO + 100%
#add 10,1,$r12,$r16,$r17 # Excesso de parametros imediat- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de subtracao R - Type (CORRETA)
#sub 00,1,$t1,$r6					- OK COMANDO VALIDO + 100% + 100% = 4598
#sub 01,1,$t0,$r2					- OK COMANDO VALIDO + 100% + 100% = 5090
#sub 10,1,3,4						- OK COMANDO VALIDO + 100% + 100% = 5428

# Teste de instrucoes de subtracao R - Type (ERRADA)
#su 02,1,$r9,$r4 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#sub 02,1,$r9,$r4 # Modo de enderecamento invalido	- OK ERRO ENCONTRADO + 100%
#sub 02,3,$r9,$r4 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#sub 01,1,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#sub 10,1,2,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#sub 01,1,$r12,$r16 # Registador nao representavel	- OK ERRO ENCONTRADO + 100%
#sub 01,1,$r12,$r16,$r17 # Excesso de parametros	- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de incremento R - Type (CORRETA)
#inc 00,1,$r7						- OK COMANDO VALIDO + 100% + 100% = 6512
#inc 01,1,$r8						- OK COMANDO VALIDO + 100% + 100% = 7040
#inc 10,1,10						- OK COMANDO VALIDO + 100% + 100% = 7584

# Teste de instrucoes de adicao R - Type (ERRADA)
#in 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#inc 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#inc 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#inc 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#inc 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#inc 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#inc 01,1,$r12,$r16 # Excesso de parametros#		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de decremento R - Type (CORRETA)
#dec 00,1,$r9						- OK COMANDO VALIDO + 100% + 100% = 8592
#dec 01,1,$r10						- OK COMANDO VALIDO + 100% + 100% = 9120
#dec 10,1,9						- OK COMANDO VALIDO + 100% + 100% = 9616

# Teste de instrucoes de decremento R - Type (ERRADA)
#de 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#dec 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#dec 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#dec 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#dec 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#dec 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#dec 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de istrucoes de multiplicacao R - Type (CORRETA)
#mul 00,1,$r13,$r11					- OK COMANDO VALIDO + 100% + 100% = 10715
#mul 01,1,$r0,$r12					- OK COMANDO VALIDO + 100% + 100% = 11020
#mul 10,1,13,3						- OK COMANDO VALIDO + 100% + 100% = 11731

# Teste de instrucoes de multiplicacao R - Type (ERRADA)
#mu 02,1,$r9,$r4 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#mul 02,1,$r9,$r4 # Modo de enderecamento invalido	- OK ERRO ENCONTRADO + 100%
#mul 02,3,$r9,$r4 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#mul 01,1,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#mul 10,1,2,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#mul 01,1,$r12,$r16 # Registador nao representavel	- OK ERRO ENCONTRADO + 100%
#mul 01,1,$r12,$r16,$r17 # Excesso de parametros	- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de divisao R - Type (CORRETA)
#div 00,1,$t0,$r1					- OK COMANDO VALIDO + 100% + 100% = 12769
#div 01,1,$t1,$r2					- OK COMANDO VALIDO + 100% + 100% = 13298
#div 10,1,11,2						- OK COMANDO VALIDO + 100% + 100% = 13746

# Teste de instrucoes de divisao R - Type (ERRADA)
#di 02,1,$r9,$r4 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#div 02,1,$r9,$r4 # Modo de enderecamento invalido	- OK ERRO ENCONTRADO + 100%
#div 02,3,$r9,$r4 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#div 01,1,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#div 10,1,2,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#div 01,1,$r12,$r16 # Registador nao representavel	- OK ERRO ENCONTRADO + 100%
#div 01,1,$r12,$r16,$r17 # Excesso de parametros	- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de resto da divisao R - Type (CORRETA)
#mod 00,1,$t0,$r1					- OK COMANDO VALIDO + 100% + 100% = 14817					
#mod 01,1,$t1,$r0					- OK COMANDO VALIDO + 100% + 100% = 15344
#mod 10,1,15,2						- OK COMANDO VALIDO + 100% + 100% = 15858

# Teste de instrucoes de resto da divisao R - Type (ERRADA)

#mo 02,1,$r9,$r4 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#mod 02,1,$r9,$r4 # Modo de enderecamento invalido	- OK ERRO ENCONTRADO + 100%
#mod 02,3,$r9,$r4 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#mod 01,1,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#mod 10,1,2,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#mod 01,1,$r12,$r16 # Registador nao representavel	- OK ERRO ENCONTRADO + 100%
#mod 01,1,$r12,$r16,$r17 # Excesso de parametros	- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de deslocamento a direita R - Type (CORRETA)
#shr 00,0,$r1						- OK COMANDO VALIDO + 100% + 100% = 16400
#shr 01,1,$r2						- OK COMANDO VALIDO + 100% + 100% = 17184
#shr 10,0,2						- OK COMANDO VALIDO + 100% + 100% = 17440

# Teste de instrucoes de deslocamento a direita R - Type (ERRADA)
#sh 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#shr 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#shr 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#shr 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#shr 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#shr 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#shr 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de deslocamento a esquerda R - Type (CORRETA)
#shl 00,0,$r1						- OK COMANDO VALIDO + 100% + 100% = 18448				
#shl 01,1,$r2						- OK COMANDO VALIDO + 100% + 100% = 19232
#shl 10,0,3						- OK COMANDO VALIDO + 100% + 100% = 19504

# Teste de instrucoes de deslocamento a esquerda R - Type (ERRADA)
#sh 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#shl 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#shl 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#shl 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#shl 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#shl 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de rotacao a direita R - Type (CORRETA)
#ror 00,1,$r4						- OK COMANDO VALIDO + 100% + 100% = 20800
#ror 01,1,$r5						- OK COMANDO VALIDO + 100% + 100% = 21344
#ror 10,0,10						- OK COMANDO VALIDO + 100% + 100% = 21664

# Teste de instrucoes de rotacao a direita R - Type (ERRADA)
#ro 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#ror 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#ror 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#ror 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#ror 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#ror 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#ror 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de rotacao a direita R - Type (CORRETA)
#rol 00,1,$r7#						- OK COMANDO VALIDO + 100% + 100% = 22896
#rol 01,0,$r8#						- OK COMANDO VALIDO + 100% + 100% = 23168
#rol 10,1,9#						- OK COMANDO VALIDO + 100% + 100% = 23952

# Teste de instrucoes de rotacao a esquerda R - Type (ERRADA)
#ro 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#rol 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#rol 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#rol 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#rol 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#rol 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#rol 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de OR logico R - Type (CORRETA)
#or 00,1,$r9						- OK COMANDO VALIDO + 100% + 100% = 24976
#or 10,0,8						- OK COMANDO VALIDO + 100% + 100% = 25728
#or 01,1,$r7						- OK COMANDO VALIDO + 100% + 100% = 25456

# Teste de instrucoes de OR logico R - Type (ERRADA)
#o 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#or 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#or 00,3,$r3 # Registrador destino desconhecido		- OK ERRO ENCONTRADO + 100%
#or 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#or 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#or 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#or 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de AND logico R - Type (CORRETA)
#and 10,0,10						- OK COMANDO VALIDO + 100% + 100% = 27808
#and 00,0,$r12						- OK COMANDO VALIDO + 100% + 100% = 26816
#and 01,1,$r11						- OK COMANDO VALIDO + 100% + 100% = 27568

# Teste de instrucoes de AND logico R - Type (ERRADA)
#an 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#and 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#and 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#and 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#and 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#and 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#and 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de XOR logico R - Type (CORRETA)
#xor 00,0,$t1						- OK COMANDO VALIDO + 100% + 100% = 28912
#xor 01,1,$t0						- OK COMANDO VALIDO + 100% + 100% = 29664
#xor 10,0,7						- OK COMANDO VALIDO + 100% + 100% = 29808

# Teste de instrucoes de XOR logico R - Type (ERRADA)
#xo 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#xor 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#xor 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#xor 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#xor 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#xor 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#xor 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de NOT logico R - Type (CORRETA)
#not 00,0,$r5						- OK COMANDO VALIDO + 100% + 100% = 30800
#not 01,0,$t1						- OK COMANDO VALIDO + 100% + 100% = 31472
#not 10,1,14						- OK COMANDO VALIDO + 100% + 100% = 32224

# Teste de instrucoes de NOT logico R - Type (ERRADA)
#no 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#not 03,1,$r3 # Modo de enderecamento invalido		- OK ERRO ENCONTRADO + 100%
#not 00,3,$r3 # Registrador destino desconhecido	- OK ERRO ENCONTRADO + 100%
#not 00,$r3 # Falta operandos				- OK ERRO ENCONTRADO + 100%
#not 10,1,16 # Excesso de capacidade de representacao	- OK ERRO ENCONTRADO + 100%
#not 00,1,$r16 # Registador nao representavel		- OK ERRO ENCONTRADO + 100%
#not 01,1,$r12,$r16 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de Carga em parte baixa I - Type (CORRETA)
#li 0,50#						- OK COMANDO VALIDO + 100% + 100% = 32718
#li 1,45#						- OK COMANDO VALIDO + 100% + 100% = 32467

# Teste de instrucoes de Carga em parte baixa I - Type (ERRADA)
#l 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#li 3,$r3 # Registrador destino desconhecido		- OK ERRO ENCONTRADO + 100%
#li 0, # Falta operandos				- OK ERRO ENCONTRADO + 100%
#li 1,5,$r0 # Excesso de parametros			- OK ERRO ENCONTRADO + 100%
#li 0,255 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%

# Teste de instrucoes de Carga em parte alta I - Type (CORRETA)
#lui 0,255#						- OK COMANDO VALIDO + 100% + 100% = 30465
#lui 1,255#						- OK COMANDO VALIDO + 100% + 100% = 30209

# Teste de instrucoes de Carga em parte alta I - Type (ERRADA)
#lu 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#lui 3,$r3 # Registrador destino desconhecido		- OK ERRO ENCONTRADO + 100%
#lui 0, # Falta operandos				- OK ERRO ENCONTRADO + 100%
#lui 1,5,$r0 # Excesso de parametros			- OK ERRO ENCONTRADO + 100%
#lui 0,255 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de leitura de palavra de memoria LS - Type (CORRETA)
#lw $r0,$r1#						- OK COMANDO VALIDO + 100% + 100% = 28671

# Teste de instrucoes de leitura de palavra de memoria LS - Type (ERRADA)
#l 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#lw $r3,$r16 # Registrador nao representavel		- OK ERRO ENCONTRADO + 100%
#lw $r0, # Falta operandos				- OK ERRO ENCONTRADO + 100%
#lw $r0,$r1,$r0 # Excesso de parametros			- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de escrita de palavra de memoria LS - Type (CORRETA)
#sw $r2,$r3#						- OK COMANDO VALIDO + 100% + 100% = 26589

# Teste de instrucoes de escrita de palavra de memoria LS - Type (ERRADA)
#s 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#sw $r3,$r16 # Registrador nao representavel		- OK ERRO ENCONTRADO + 100%
#sw $r0, # Falta operandos				- OK ERRO ENCONTRADO + 100%
#sw $r0,$r1,$r0 # Excesso de parametros			- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de leitura de celula de memoria LS - Type (CORRETA)
#lb $r4,$r5#						- OK COMANDO VALIDO + 100% + 100% = 24507

# Teste de instrucoes de leitura de celula de memoria LS - Type (ERRADA)
#l 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#lb $r3,$r16 # Registrador nao representavel		- OK ERRO ENCONTRADO + 100%
#lb $r0, # Falta operandos				- OK ERRO ENCONTRADO + 100%
#lb $r0,$r1,$r0 # Excesso de parametros			- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de escrita de celula memoria LS - Type (CORRETA)
#sb $r6,$r7#						- OK COMANDO VALIDO + 100% + 100% = 22425

# Teste de instrucoes de escrita de celula de memoria LS - Type (ERRADA)
#s 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#sb $r3,$r16 # Registrador nao representavel		- OK ERRO ENCONTRADO + 100%
#sb $r0, # Falta operandos				- OK ERRO ENCONTRADO + 100%
#sb $r0,$r1,$r0 # Excesso de parametros			- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de movimentacao de conteudo de registrador LS - Type (CORRETA)
#mov $r8,$r9#						- OK COMANDO VALIDO + 100% + 100% = 20343

# Teste de instrucoes de movimentacao de conteudo de registrador LS - Type (ERRADA)
#mo 00,1,$r3 # Opcode desconhecido			- OK ERRO ENCONTRADO + 100%
#mov $r3,$r16 # Registrador nao representavel		- OK ERRO ENCONTRADO + 100%
#mov $r0, # Falta operandos				- OK ERRO ENCONTRADO + 100%
#mov $r0,$r1,$r0 # Excesso de parametros		- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de desvio caso der overflow Branch - Type (CORRETA)
#jv 1#							- OK COMANDO VALIDO + 100% + 100% = 18431

# Teste de instrucoes de desvio caso der overflow  Branch - Type (ERRADA)
#j 1 # Opcode desconhecido				- OK ERRO ENCONTRADO + 100%
#jv 2049 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%
#jv  # Falta operandos					- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de desvio caso nao der overflow Branch - Type (CORRETA)
#jnv 2#							- OK COMANDO VALIDO + 100% + 100% = 16382

# Teste de instrucoes de desvio caso nao der overflow  Branch - Type (ERRADA)
#jn 1 # Opcode desconhecido				- OK ERRO ENCONTRADO + 100%
#jnv 2049 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%
#jnv  # Falta operandos					- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de desvio caso der zero Branch - Type (CORRETA)
#jz 3#							- OK COMANDO VALIDO + 100% + 100% = 14333

# Teste de instrucoes de desvio caso der zero  Branch - Type (ERRADA)
#j 1 # Opcode desconhecido				- OK ERRO ENCONTRADO + 100%
#jz 2049 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%
#jz  # Falta operandos					- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de desvio caso nao der zero Branch - Type (CORRETA)
#jnz 4#							- OK COMANDO VALIDO + 100% + 100% = 12284

# Teste de instrucoes de desvio caso nao der overflow  Branch - Type (ERRADA)
#jn 1 # Opcode desconhecido				- OK ERRO ENCONTRADO + 100%
#jnz 2049 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%
#jnz  # Falta operandos					- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de desvio caso der carry Branch - Type (CORRETA)
#jc 5#							- OK COMANDO VALIDO + 100% + 100% = 10235

# Teste de instrucoes de desvio caso der carry  Branch - Type (ERRADA)
#j 1 # Opcode desconhecido				- OK ERRO ENCONTRADO + 100%
#jc 2049 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%
#jc  # Falta operandos					- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de desvio caso nao der carry Branch - Type (CORRETA)
#jnc 6#							- OK COMANDO VALIDO + 100% + 100% = 8186

# Teste de instrucoes de desvio caso nao der carry  Branch - Type (ERRADA)
#jn 1 # Opcode desconhecido				- OK ERRO ENCONTRADO + 100%
#jnc 2049 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%
#jnc  # Falta operandos					- OK ERRO ENCONTRADO + 100%

# Teste de instrucao de desvio Branch - Type (CORRETA)
#jmp 7#							- OK COMANDO VALIDO + 100% + 100% = 6137

# Teste de instrucoes de desvio Branch - Type (ERRADA)
#jm 1 # Opcode desconhecido				- OK ERRO ENCONTRADO + 100%
#jmp 2049 # Faixa nao representavel			- OK ERRO ENCONTRADO + 100%
#jmp  # Falta operandos					- OK ERRO ENCONTRADO + 100%

############################################
##         (100%) Test of Halt TAG        ##
############################################

#halt #                       - Ok 100% (Assembler accept this command)

############################################
##      (100%) Test of Data Block TAG     ##
############################################

#.data #						          - Ok 100% (Assembler accept this command)

############################################
## (100%) Test of Loading Bytes to Memory ##
############################################

# Load one cell of data (Corrent Sintax)
#.byte 8						          - Ok 100% (Assembler accept this command)

# Load one cell of data (Wrong Sintax)
#.byte 							          - Ok 100% (Assembler found this error)
#byte  							          - Ok 100% (Assembler found this error)
#.byte 512						        - Ok 100% (Assembler found this error)

############################################
## (100%) Test of Loading Words to Memory ##
############################################

# Load one word of data (Corrent Sintax)
#.word 512#						        - Ok 100% (Assembler accept this command)

# Load one word of data (Wrong Sintax)
#1 # .word              		  - Ok 100% (Assembler found this error) Output: "Not Found"
#.word			                  - Ok 100% (Assembler found this error) Output: "Need Value" 
