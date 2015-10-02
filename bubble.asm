# Universidade Regional Integrada do Alto uruguai e das Missões 
# Bubble Sort - Exemplo pratico de validacao do ISS e do Assembler 
# Disciplina :Trabalho de conclusao - 10 Semestre 
# Professor : Mr.Carlos petry 
# Aluno : Raffael Bottoli Schemmer 
# Data Termino : 17/11/2009 

# Algoritimo em C traduzido para o ASM AIDA-16
# int vet[10] = {9,8,7,6,5,4,3,2,1,0};
# int contador=0,contador2,tmp;
# do
# {
#	contador2=contador;
#	do
#	{
#		if(vet[contador] > vet[contador2]) 
#		{
#			tmp = vet[contador];
#			vet[contador] = vet[contador2];
#			vet[contador2] = tmp;
#		}
#		contador2++;
#	}while(contador2 < 10);
#	contador++;
# }while(contador < 10);

.text
li 0,10
nop
li 1,0
mov $t0,$r2
nop
li 0,0
mov $t0,$r10
mov $t0,$r11
nop
lb $r0,$r10 
nop
lb $r1,$r11
nop
mov $r0,$r3
div 00,0,$r3,$r1
nop
jz 2
nop
mov $r0,$r5
sb $r10,$r1
sb $r11,$r5
nop
inc 00,0,$r10
nop
mov $r10,$r4
nop
div 00,0,$r4,$r2
jz -10
nop
inc 00,0,$r11
mov $r11,$r10
mov $r11,$r5
nop
div 00,0,$r5,$r2
jz -14
nop
halt
.data
.byte 9
.byte 8
.byte 7
.byte 6
.byte 5
.byte 4
.byte 3
.byte 2
.byte 1
.byte 0
