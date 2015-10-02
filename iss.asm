# Universidade Regional Integrada do Alto uruguai e das Missões */
# Arquivo de validacao do ISS
# Disciplina :Trabalho de conclusao - 10 Semestre */
# Professor : Mr.Carlos petry */
# Aluno : Raffael Bottoli Schemmer */
# Data Termino : 17/11/2009 */

.text

# nop   #							# - (TESTADO)
# nop   #							# - (TESTADO)

# Teste da instrucao de soma

# add 00,0,$r0,$r1 #		# ( O: T C: T Z: T)		# - (TESTADO) Add Direto(1)
# add 00,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Add Direto(0)
# add 10,1,-2,1    #		# ( O: T C: T Z: T)		# - (TESTADO) Add Imediato(t1)
# add 10,0,0,1     #		# ( O: T C: T Z: T)		# - (TESTADO) Add Imediato(t0)
# add 01,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Add Indireto(0)
# add 01,1,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Add Indireto(1)

# Teste da instrucao de subtracao

# sub 00,1,$r0,$r1 #		# ( O: T C: T Z: T)		# - (TESTADO) Sub Direto(1)
# sub 00,0,$r0,$r1 #		# ( O: T C: T Z: T)		# - (TESTADO) Sub Direto(0)
# sub 01,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Sub Indireto(0)
# sub 01,1,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Sub Indireto(1)
# sub 10,1,2,1 	   #	  	# ( O: T C: T Z: T)		# - (TESTADO) Sub Imediato(t1)
# sub 10,0,2,1 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Sub Imediato(t0)

# Teste da instrucao de incremento

# inc 00,1,$r0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Inc Direto(1)
# inc 00,0,$r0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Inc Direto(0)
# inc 01,0,$t0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Inc Indireto(0)
# inc 01,1,$t0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Inc Indireto(1)
# inc 10,1,3 	   # 		# ( O: T C: T Z: T)		# - (TESTADO) Inc Imediato(t1)
# inc 10,1,4 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Inc Imediato(t0)


# Teste da instrucao de decremento

# dec 00,1,$r0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Dec Direto(1)
# dec 00,0,$r0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Dec Direto(0)
# dec 01,0,$t0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Dec Indireto(0)
# dec 01,1,$t0	   #		# ( O: T C: T Z: T)		# - (TESTADO) Dec Indireto(1)
# dec 10,1,5 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Dec Imediato(t1)
# dec 10,0,5 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Dec Imediato(t0)

# Teste da instrucao de multiplicacao

# mul 00,1,$r0,$r1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mul Direto(1)
# mul 00,0,$r0,$r1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mul Direto(0)
# mul 01,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mul Indireto(0)
# mul 01,1,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mul Indireto(1)
# mul 10,1,5,2 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Mul Imediato(t1)
# mul 10,0,5,3 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Mul Imediato(t0)

# Teste da instrucao de divisao

# div 00,1,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Div Direto(1)
# div 00,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Div Direto(0)
# div 01,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Div Indireto(0)
# div 01,1,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Div Indireto(1)
# div 10,1,6,2	   #		# ( O: T C: T Z: T)		# - (TESTADO) Div Imediato(t1)
# div 10,0,5,2 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Div Imediato(t0)

# Teste da instrucao de resto da divisao (VERIFICAR)

# mod 00,1,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mod Direto(1)
# mod 00,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mod Direto(0)
# mod 01,0,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mod Indireto(0)
# mod 01,1,$t0,$t1 #		# ( O: T C: T Z: T)		# - (TESTADO) Mod Indireto(1)
# mod 10,1,6,4 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Mod Imediato(t1)
# mod 10,0,6,4 	   #		# ( O: T C: T Z: T)		# - (TESTADO) Mod Imediato(t0)

# Teste da instrucao de deslocamento a direita

# shr 00,0,$r0	#		# ( Z: T C: T)		# - (TESTADO) Ror Direto
# shr 01,0,$t0	#		# ( Z: T C: T)		# - (TESTADO) Ror Indireto
# shr 10,0,4	#		# ( Z: T C: T)		# - (TESTADO) Ror Imediato(t0)
# shr 10,1,4	#		# ( Z: T C: T)		# - (TESTADO) Ror Imediato(t1)

# Teste da instrucao de deslocamento a esquerda

# shl 00,0,$r0	#		# ( Z: T C: T)		# - (TESTADO) Shl Direto
# shl 01,0,$t0	#		# ( Z: T C: T)		# - (TESTADO) Shl Indireto
# shl 10,0,4	#		# ( Z: T C: T)		# - (TESTADO) Shl Imediato(t0)
# shl 10,1,4	#		# ( Z: T C: T)		# - (TESTADO) Shl Imediato(t1)

# Teste da instrucao de rotacao a direita (PROBLEMA) Se entrar com 1 fica com 2

# ror 00,0,$t0	#		# ( Z: T)		# - (TESTADO) Ror Direto
# ror 01,0,$t0	#		# ( Z: T)		# - (TESTADO) Ror Indireto
# ror 10,0,4	#		# ( Z: T)		# - (TESTADO) Ror Imediato(t0)
# ror 10,1,4	#		# ( Z: T)		# - (TESTADO) Ror Imediato(t1)

# Teste da instrucao de rotacao a esquerda (PROBLEMA) Se entrar com 1 fica com o maximo

# rol 00,0,$t0	#		# ( Z: T)		# - (TESTADO) Rol Direto
# rol 01,0,$t0	#		# ( Z: T)		# - (TESTADO) Rol Indireto
# rol 10,0,4	#		# ( Z: T)		# - (TESTADO) Rol Imediato(t0)
# rol 10,1,4	#		# ( Z: T)		# - (TESTADO) Rol Imediato(t1)

# Teste da instrucao de OR logico

# or 00,0,$r0,$r1  #		# ( Z: T)		# - (TESTADO) Or Direto
# or 01,0,$t0,$t1  #		# ( Z: T)		# - (TESTADO) Or Indireto
# or 10,0,4,1	   #		# ( Z: T)		# - (TESTADO) Or Imediato(t0)
# or 10,1,4,1	   #		# ( Z: T)		# - (TESTADO) Or Imediato(t1)

# Teste da instrucao de AND logico (PROBLEMAS NO AND)

# and 00,0,$t0,$t1  #		# ( Z: T)		# - (TESTADO) And Direto
# and 01,0,$t0,$t1  #		# ( Z: T)		# - (TESTADO) And Indireto
# and 10,0,2,1	    #		# ( Z: T)		# - (TESTADO) And Imediato(t0)
# and 10,1,1,1	    #		# ( Z: T)		# - (TESTADO) And Imediato(t1)

# Teste da instrucao de XOR logico

# xor 00,0,$t0,$t1  #		# ( Z: T)		# - (TESTADO) Xor Direto
# xor 01,0,$t0,$t1  # 		# ( Z: T)		# - (TESTADO) Xor Indireto
# xor 10,1,1,0	    #		# ( Z: T)		# - (TESTADO) Xor Imediato(t0)
# xor 10,0,4,1	    #		# ( Z: T)		# - (TESTADO) Xor Imediato(t1)

# Teste da instrucao de NOT logico

# not 00,0,$t0	#		# ( Z: T)		# - (TESTADO) Not Direto
# not 01,0,$t0	#		# ( Z: T)		# - (TESTADO) Not Indireto
# not 10,0,4	#		# ( Z: T)		# - (TESTADO) Not Imediato(t0)
# not 10,1,4	#		# ( Z: T)		# - (TESTADO) Not Imediato(t1)

# Teste da instrucao de carga baixa de registrador

# li 0,2	#					# - (TESTADO) Li(t0)
# li 1,1 	#					# - (TESTADO) Li(t1)

# Teste da instrucao de carga alta de registrador

# lui 0,1  	#					# - (TESTADO) Lui(t0)
# lui 1,1  	#					# - (TESTADO) Lui(t1)

# Teste da instrucao de leitura de word da memoria

# lw $t0,$t1 	#					# - (TESTADO) Lw

# Teste da instrucao de escrita de word na memoria

# sw $t1,$t0  	#					# - (TESTADO) Sw

# Teste da instrucao de leitura de byte da memoria

# lb $t0,$t1  	#					# - (TESTADO) Lb

# Teste da instrucao de escrita de byte na memoria

# sb $t0,$t1  	#					# - (TESTADO) Sb

# Teste da instrucao de movimentacao de registradores

# mov $t0,$r0   #					# - (TESTADO) Mov

# Teste da instrucao de desvio se der overflow

# jv 1 		#					# - (TESTADO) Desvia se instrucao anterior der overflow

# Teste da instrucao de desvio se nao der overflow

# jnv 2 	#					# - (TESTADO) Desvia se instrucao anterior nao der overflow

# Teste da instrucao de desvio se der zero 

# jz 2 		#					# - (TESTADO) Desvia se instrucao anterior der zero

# Teste da instrucao de desvio se nao der zero 

# jnz 2		#					# - (TESTADO) Desvia se instrucao anterior nao der zero

# Teste da instrucao de desvio se der carry

# jc 5 		#					# - (TESTADO) Desvia se instrucao anterior der carry

# Teste da instrucao de desvio se nao der carry

# jnc 6		#					# - (TESTADO) Desvia se instrucao anterior nao der carry

# Teste da instrucao de desvio

# jmp 1 	#					# - (TESTADO) Desv ia se instrucao

halt

.data

#.word 2
#.word 1

#.byte 3
#.byte 4
#.byte 5
