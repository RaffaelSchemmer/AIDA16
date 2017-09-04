/* Universidade Regional Integrada do Alto uruguai e das Missões */
/* Simulador AIDA */
/* Disciplina :Trabalho de conclusao - 10 Semestre */
/* Professor : Mr.Carlos petry */
/* Aluno : Raffael Bottoli Schemmer */
/* Data Termino : 17/11/2009 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 65536 /* Constante que define o tamanho das memorias */

FILE *in;

unsigned short int MEM_INST[TAM]; /* Implementa a memoria de instrucoes*/
unsigned char MEM_DATA[TAM]; /*Implementa a memoria de dados */

unsigned short int mem_inst,mem_data; /* Contador do numero de instrucoes e de dados */
int ciclos,end_mem,ini_inter,fim_inter,contador2,flag=0,tempo;

short int BD[15]; /* Implementa o banco de registradores */
unsigned short int PC; /* Implementa o contador de programa */

unsigned short int instrucao0;
unsigned short int instrucao1;

unsigned short int temp0,temp1,temp2,x,y,z;
char sinstrucao[40],temp[20],c;
struct instrucao
{
	unsigned short int opcode;
	unsigned short int formato;
	short int desl;
	unsigned short int reg0;
	unsigned short int reg1;
	short int cost;
	unsigned short int regdest;
	unsigned short int modo;
}inst0,inst1,t;

unsigned short int tinstrucao0,tinstrucao1;
short int overflow,zero,carry;
int contador,flag2;
char opt,opt1;

void registrador(struct instrucao x)
{
	if(x.reg0 == 0)strcat(sinstrucao,"$r0");
	if(x.reg0 == 1)strcat(sinstrucao,"$r1");
	if(x.reg0 == 2)strcat(sinstrucao,"$r2");
	if(x.reg0 == 3)strcat(sinstrucao,"$r3");
	if(x.reg0 == 4)strcat(sinstrucao,"$r4");
	if(x.reg0 == 5)strcat(sinstrucao,"$r5");
	if(x.reg0 == 6)strcat(sinstrucao,"$r6");
	if(x.reg0 == 7)strcat(sinstrucao,"$r7");
	if(x.reg0 == 8)strcat(sinstrucao,"$r8");
	if(x.reg0 == 9)strcat(sinstrucao,"$r9");
	if(x.reg0 == 10)strcat(sinstrucao,"$r10");
	if(x.reg0 == 11)strcat(sinstrucao,"$r11");
	if(x.reg0 == 12)strcat(sinstrucao,"$r12");
	if(x.reg0 == 13)strcat(sinstrucao,"$r13");
	if(x.reg0 == 14)strcat(sinstrucao,"$t0");
	if(x.reg0 == 15)strcat(sinstrucao,"$t1");
	if(x.opcode == 3 || x.opcode == 4 || x.opcode == 8 || x.opcode == 9 || x.opcode == 10 || x.opcode == 11 || x.opcode == 15){}
	else
	{
		if(x.reg1 == 0)strcat(sinstrucao,",$r0");
		if(x.reg1 == 1)strcat(sinstrucao,",$r1");
		if(x.reg1 == 2)strcat(sinstrucao,",$r2");
		if(x.reg1 == 3)strcat(sinstrucao,",$r3");
		if(x.reg1 == 4)strcat(sinstrucao,",$r4");
		if(x.reg1 == 5)strcat(sinstrucao,",$r5");
		if(x.reg1 == 6)strcat(sinstrucao,",$r6");
		if(x.reg1 == 7)strcat(sinstrucao,",$r7");
		if(x.reg1 == 8)strcat(sinstrucao,",$r8");
		if(x.reg1 == 9)strcat(sinstrucao,",$r9");
		if(x.reg1 == 10)strcat(sinstrucao,",$r10");
		if(x.reg1 == 11)strcat(sinstrucao,",$r11");
		if(x.reg1 == 12)strcat(sinstrucao,",$r12");
		if(x.reg1 == 13)strcat(sinstrucao,",$r13");
		if(x.reg1 == 14)strcat(sinstrucao,",$t0");
		if(x.reg1 == 15)strcat(sinstrucao,",$t1");			
	}
}
int retorna_instrucao(struct instrucao t)
{
	sinstrucao[0] = '\0';
	if(t.opcode == 0)strcpy(sinstrucao,"nop");
	else if(t.opcode == 1)strcpy(sinstrucao,"add ");
	else if(t.opcode == 2)strcpy(sinstrucao,"sub ");
	else if(t.opcode == 3)strcpy(sinstrucao,"inc ");
	else if(t.opcode == 4)strcpy(sinstrucao,"dec ");
	else if(t.opcode == 5)strcpy(sinstrucao,"mul ");
	else if(t.opcode == 6)strcpy(sinstrucao,"div ");
	else if(t.opcode == 7)strcpy(sinstrucao,"mod ");
	else if(t.opcode == 8)strcpy(sinstrucao,"shr ");
	else if(t.opcode == 9)strcpy(sinstrucao,"shl ");
	else if(t.opcode == 10)strcpy(sinstrucao,"ror ");
	else if(t.opcode == 11)strcpy(sinstrucao,"rol ");
	else if(t.opcode == 12)strcpy(sinstrucao,"or ");
	else if(t.opcode == 13)strcpy(sinstrucao,"and ");
	else if(t.opcode == 14)strcpy(sinstrucao,"xor ");
	else if(t.opcode == 15)strcpy(sinstrucao,"not ");
	else if(t.opcode == 16)strcpy(sinstrucao,"li ");
	else if(t.opcode == 17)strcpy(sinstrucao,"lui ");
	else if(t.opcode == 18)strcpy(sinstrucao,"lw ");
	else if(t.opcode == 19)strcpy(sinstrucao,"sw ");
	else if(t.opcode == 20)strcpy(sinstrucao,"lb ");
	else if(t.opcode == 21)strcpy(sinstrucao,"sb ");
	else if(t.opcode == 22)strcpy(sinstrucao,"mov ");
	else if(t.opcode == 23)strcpy(sinstrucao,"jv ");
	else if(t.opcode == 24)strcpy(sinstrucao,"jnv ");
	else if(t.opcode == 25)strcpy(sinstrucao,"jz ");
	else if(t.opcode == 26)strcpy(sinstrucao,"jnz ");
	else if(t.opcode == 27)strcpy(sinstrucao,"jc ");
	else if(t.opcode == 28)strcpy(sinstrucao,"jnc ");
	else if(t.opcode == 29)strcpy(sinstrucao,"jmp ");
	else if(t.opcode == 30)
	{
		strcpy(sinstrucao,"halt");
		return(0);
	}
	else
	{
		strcpy(sinstrucao,"    ");
		return(0);
	}
	if(t.formato == 0)
	{
		if(t.modo == 2)
		{
			strcat(sinstrucao,"10,");
			sprintf(temp,"%d",t.regdest);
			strcat(sinstrucao,temp);
			strcat(sinstrucao,",");
			sprintf(temp,"%d",t.reg0);
			strcat(sinstrucao,temp);
			if(t.opcode == 3 || t.opcode == 4 || t.opcode == 8 || t.opcode == 9 || t.opcode == 10 || t.opcode == 11 || t.opcode == 15){}
			else
			{
				strcat(sinstrucao,",");
				sprintf(temp,"%d",t.reg1);
				strcat(sinstrucao,temp);
			}
		}
		else
		{
			if(t.opcode == 0 || t.opcode == 30){}
			else if(t.modo == 0)
			{
				strcat(sinstrucao,"00,");
				sprintf(temp,"%d",t.regdest);
				strcat(sinstrucao,temp);
				strcat(sinstrucao,",");
				registrador(t);
			}
			else if(t.modo == 1)
			{
				strcat(sinstrucao,"01,");
				sprintf(temp,"%d",t.regdest);
				strcat(sinstrucao,temp);
				strcat(sinstrucao,",");
				registrador(t);
			}
		}
	}
	else if(t.formato == 1)
	{
		sprintf(temp,"%d",t.regdest);
		strcat(sinstrucao,temp);
		strcat(sinstrucao,",");
		sprintf(temp,"%d",t.cost);
		strcat(sinstrucao,temp);
	}
	else if(t.formato == 2)
	{
		registrador(t);
	}
	else if(t.formato == 3)
	{
		sprintf(temp,"%d",t.desl);
		strcat(sinstrucao,temp);
	}
}
void TABELA_DE_ERROS(int erro) /* Mostra os erros gerados pelo montador */
{
	switch(erro)
	{
		case(0):
		{
			printf("Erro(%d) : O arquivo .bin nao foi especificado !!\n",erro+1);
			break;
		}
		case(1):
		{
			printf("Erro(%d) : Arquivo nao encontrado !!\n",erro+1);
			break;
		}
	}
	exit(0);
}
void ARQUIVO_ENTRADA(int parametro,char nome_arquivo[30]) /* Responsavel por abrir o arquivo de entrada */
{
	if(parametro <= 1) TABELA_DE_ERROS(0);
	in = fopen(nome_arquivo,"rb");
	if(in == NULL) TABELA_DE_ERROS(1);
	contador = strlen(nome_arquivo);
	if(!(nome_arquivo[contador-3] == 'b' && nome_arquivo[contador-2] == 'i' && nome_arquivo[contador-1] == 'n'))TABELA_DE_ERROS(1);
}
void LE_MEMORIA_INSTRUCAO() /* Funcao responsavel por iniciar a memoria de instrucoes */
{
	fread(&mem_inst,sizeof(unsigned short int),1,in); /* Le o numero de instrucoes no .bin */
	fread(&mem_data,sizeof(unsigned short int),1,in); /* Le o numero de dados no .bin */
	for(contador=0;contador<mem_inst;contador++)
	{
		fread(&MEM_INST[contador],sizeof(unsigned short int),1,in); /* Le as instrucoes */
	}
}
void LE_MEMORIA_DADOS() /* Funcao responsavel por iniciar a memoria de dados */
{
	for(contador=0;contador<mem_data;contador++)
	{
		fread(&MEM_DATA[contador],sizeof(char),1,in); /* Le os dados */
	}
}
void INICIA_SIMULADOR() /* Funcao responsavel por iniciar o simulador */
{
	PC = 0; /* Inicia o contador de programa */
	for(contador=0;contador<16;contador++){BD[contador] =0;} /* inicia o banco de registradores */
	for(contador=0;contador<TAM;contador++)
	{
		MEM_INST[contador] = -1;
		MEM_DATA[contador] = -1;
	}
	flag2=0;
	zero=-1,carry=-1,overflow=-1;
}
int BUSCA_INSTRUCAO() /* Funcao responsavel por buscar as instrucoes */
{	
	instrucao0 = MEM_INST[PC]; /* Busca a primeira molecula (Instrucao 0 + Instrucao 1) */
	if(instrucao0 == 61440)
	{
		return(1);
	}
	PC++;
	return(0);
}
struct instrucao Decodifica(unsigned short int instrucao0)
{
	tinstrucao0 = instrucao0;
	tinstrucao0 = tinstrucao0 >> 11;
	tinstrucao0 = tinstrucao0 | 0;
	t.opcode = tinstrucao0;
	if(t.opcode >= 0 && t.opcode <= 15) /* Trata instrucao do formato R - 5 Campos */
	{
		t.formato = 0; /* Pega o formato da instrucao */
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 5;
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 14; /* Pega o modo de enderecamento da instrucao 0 */
		tinstrucao0 = tinstrucao0 | 0;
		t.modo = tinstrucao0;
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 7;
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 15; /* Pega o registrador destino da instrucao 0 */
		tinstrucao0 = tinstrucao0 | 0;
		t.regdest = tinstrucao0;
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 8;
		tinstrucao0 = tinstrucao0 | 0; 
		tinstrucao0 = tinstrucao0 >> 12; /* Pega o operando 0 da instrucao */
		tinstrucao0 = tinstrucao0 | 0;
		t.reg0 = tinstrucao0;
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 12; 
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 12; /* Pega o operando 1 da instrucao */
		tinstrucao0 = tinstrucao0 | 0;
		t.reg1 = tinstrucao0;
	}
	if(t.opcode >= 16 && t.opcode <= 17) /* Trata instrucao do formato I - 3 Campos */
	{
		t.formato = 1; /* Pega o formato da instrucao */
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 7;
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 15; /* Pega o registrador destino da instrucao */
		tinstrucao0 = tinstrucao0 | 0;
		t.regdest = tinstrucao0;
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 8; /* Pega a constante da instrucao */
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 8; 
		tinstrucao1 = tinstrucao0 >> 7;
		if(tinstrucao1 == 1)
		{
			tinstrucao1 = tinstrucao0;
			tinstrucao1 = ~(tinstrucao1); //0000 0000 1111 1110           1111 1111 0000 0001
			tinstrucao1 = tinstrucao1 << 8;
			tinstrucao1 = tinstrucao1 >> 8;
			tinstrucao1 = tinstrucao1 + 1;
			tinstrucao1 = tinstrucao1 << 8;
			tinstrucao1 = tinstrucao1 >> 8;
			tinstrucao0 = tinstrucao1;
			t.cost = tinstrucao0;
			t.cost = t.cost*-1;
		}
		else
		{
			t.cost = tinstrucao0;
		}
	}
	if(t.opcode >= 18 && t.opcode <= 22) /* Trata instrucao do formato Load/Store - 3 Campos */
	{
		t.formato = 2; /* Pega o formato da instrucao */
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 8;
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 12;
		tinstrucao0 = tinstrucao0 | 0;
		t.reg0 = tinstrucao0;
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 12;
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 12; /* Pega o operando 1 da instrucao */
		tinstrucao0 = tinstrucao0 | 0;
		t.reg1 = tinstrucao0;
	}
	if(t.opcode >= 23 && t.opcode <= 29) /* Trata instrucao do formato Branch - 2 Campos */
	{
		t.formato = 3; /* Pega o formato da instrucao */
		tinstrucao0 = instrucao0;
		tinstrucao0 = tinstrucao0 << 5;
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao0 = tinstrucao0 >> 5; /* Pega o deslocamento da instrucao */
		tinstrucao0 = tinstrucao0 | 0;
		tinstrucao1 = tinstrucao0 >> 10;
		if(tinstrucao1 == 1)
		{
			
			tinstrucao1 = tinstrucao0;
			tinstrucao1 = ~(tinstrucao1); //0000 0000 1111 1110           1111 1111 0000 0001
			tinstrucao1 = tinstrucao1 << 5;
			tinstrucao1 = tinstrucao1 >> 5;
			tinstrucao1 = tinstrucao1 + 1;
			tinstrucao1 = tinstrucao1 << 5;
			tinstrucao1 = tinstrucao1 >> 5;
			tinstrucao0 = tinstrucao1;
			t.desl = tinstrucao0;
			t.desl = t.desl*-1;
		}
		else
		{
			t.desl = tinstrucao0;
		}
		}
	return(t);
}
int DECODIFICA_INSTRUCAO() /* Funcao responsavel por decodificar as instrucoes lidas */
{
	inst0 = Decodifica(instrucao0);
}
void Ula(struct instrucao t,int tipo) /* Funcao que implementa a unidade logica 0 */
{
	// Bloco para tratar de carry e overflow
	if(t.opcode == 1 || t.opcode == 2 || t.opcode == 5 || t.opcode == 6 || t.opcode == 7) // R
	{
		if(t.modo == 0)
		{
			if(BD[t.reg0] >= 0 && BD[t.reg1] >= 0 && (BD[t.reg0] + BD[t.reg1]) < 0) overflow = 1;
			else if(BD[t.reg0] < 0 && BD[t.reg1] < 0 && (BD[t.reg0] + BD[t.reg1]) >= 0)overflow =1; 
			else if(BD[t.reg0] < 0 && BD[t.reg1] >= 0 && (BD[t.reg0] -BD[t.reg1]) < 0)overflow = 1;
			else if(BD[t.reg0] >= 0 && BD[t.reg1] < 0 && (BD[t.reg0] - BD[t.reg1]) >= 0)overflow =1;
			else overflow=0;
			if(overflow == 1)carry=1;
			else carry=0;
		}
		else if(t.modo == 1)
		{
			temp0 = BD[t.reg0];
			temp1 = BD[t.reg1];
			if(BD[temp0] >= 0 && BD[temp1] >= 0 && (BD[temp0] + BD[temp1]) < 0) overflow = 1;
			else if(BD[temp0] < 0 && BD[temp1] < 0 && (BD[temp0] + BD[temp1]) >= 0)overflow =1; 
			else if(BD[temp0] < 0 && BD[temp1] >= 0 && (BD[temp0] - BD[temp1]) < 0)overflow = 1;
			else if(BD[temp0] >= 0 && BD[temp1] < 0 && (BD[temp0] - BD[temp1]) >= 0)overflow =1;
			else overflow=0;
			if(overflow == 1)carry=1;
			else carry=0;
		}
		else if(t.modo == 2)
		{
			if(t.reg0 >= 0 && t.reg1 >= 0 && (t.reg0 + t.reg1) < 0) overflow = 1;
			else if(t.reg0 < 0 && t.reg1 < 0 && (t.reg0 + t.reg1) >= 0)overflow =1; 
			else if(t.reg0 < 0 && t.reg1 >= 0 && (t.reg0 - t.reg1) < 0)overflow = 1;
			else if(t.reg0 >= 0 && t.reg1 < 0 && (t.reg0 - t.reg1) >= 0)overflow =1;
			else overflow=0;
			if(overflow == 1)carry=1;
			else carry=0;
		}
		
	}
	else if(t.opcode == 3 || t.opcode == 4) // inc/dec
	{
		if(t.opcode == 3)
		{
			if(t.modo == 0)
			{
				if(BD[t.reg0] >= 0 && 1 >= 0 && (BD[t.reg0] + 1) < 0) overflow = 1;
				else if(BD[t.reg0] < 0 && 1 < 0 && (BD[t.reg0] + 1) >= 0)overflow =1; 
				else if(BD[t.reg0] < 0 && 1 >= 0 && (BD[t.reg0] - 1) < 0)overflow = 1;
				else if(BD[t.reg0] >= 0 && 1 < 0 && (BD[t.reg0] - 1) >= 0)overflow =1;
				else overflow=0;
				if(overflow == 1)carry=1;
				else carry=0;
			}
			else if(t.modo == 1)
			{
				temp0 = BD[t.reg0];
				if(BD[temp0] >= 0 && 1 >= 0 && (BD[temp0] + 1) < 0) overflow = 1;
				else if(BD[temp0] < 0 && 1 < 0 && (BD[temp0] + 1) >= 0)overflow =1; 
				else if(BD[temp0] < 0 && 1 >= 0 && (BD[temp0] - 1) < 0)overflow = 1;
				else if(BD[temp0] >= 0 && 1 < 0 && (BD[temp0] - 1) >= 0)overflow =1;
				else overflow=0;
				if(overflow == 1)carry=1;
				else carry=0;
			}
			else if(t.modo == 2)
			{
				if(t.reg0 >= 0 && 1 >= 0 && (t.reg0 + 1) < 0) overflow = 1;
				else if(t.reg0 < 0 && 1 < 0 && (t.reg0 + 1) >= 0)overflow =1; 
				else if(t.reg0 < 0 && 1 >= 0 && (t.reg0 - 1) < 0)overflow = 1;
				else if(t.reg0 >= 0 && 1 < 0 && (t.reg0 - 1) >= 0)overflow =1;
				else overflow=0;
				if(overflow == 1)carry=1;
				else carry=0;
			}
		}
		else if(t.opcode == 4)
		{
			if(t.modo == 0)
			{
				if(BD[t.reg0] >= 0 && -1 >= 0 && (BD[t.reg0] + -1) < 0) overflow = 1;
				else if(BD[t.reg0] < 0 && -1 < 0 && (BD[t.reg0] + -1) >= 0)overflow =1; 
				else if(BD[t.reg0] < 0 && -1 >= 0 && (BD[t.reg0] - -1) < 0)overflow = 1;
				else if(BD[t.reg0] >= 0 && -1 < 0 && (BD[t.reg0] - -1) >= 0)overflow =1;
				else overflow=0;
				if(overflow == 1)carry=1;
				else carry=0;
			}
			else if(t.modo == 1)
			{
				temp0 = BD[t.reg0];
				if(BD[temp0] >= 0 && -1 >= 0 && (BD[temp0] + -1) < 0) overflow = 1;
				else if(BD[temp0] < 0 && -1 < 0 && (BD[temp0] + -1) >= 0)overflow =1; 
				else if(BD[temp0] < 0 && -1 >= 0 && (BD[temp0] - -1) < 0)overflow = 1;
				else if(BD[temp0] >= 0 && -1 < 0 && (BD[temp0] - -1) >= 0)overflow =1;
				else overflow=0;
				if(overflow == 1)carry=1;
				else carry=0;
			}
			else if(t.modo == 2)
			{
				if(t.reg0 >= 0 && -1 >= 0 && (t.reg0 + -1) < 0) overflow = 1;
				else if(t.reg0 < 0 && -1 < 0 && (t.reg0 + -1) >= 0)overflow =1; 
				else if(t.reg0 < 0 && -1 >= 0 && (t.reg0 - -1) < 0)overflow = 1;
				else if(t.reg0 >= 0 && -1 < 0 && (t.reg0 - -1) >= 0)overflow =1;
				else overflow=0;
				if(overflow == 1)carry=1;
				else carry=0;
			}
		}
	}
	switch(t.formato)
	{
		case(0): /* Executa instrucoes do tipo R */
		{
			switch(t.opcode)
			{
				case(0): /* Instrucao Nop */
				{
					zero=-1,carry=-1,overflow=-1;
					break;
				}
				case(1):
				{
					switch(t.modo)
					{
						case(0): /* Soma modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] + BD[t.reg1];
								if(BD[t.reg0] == 0) zero = 1;
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] + BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
						case(1): /* Soma modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] + BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] + BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;		
							}
							break;
						}
						case(2): /* Soma modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 + t.reg1;
								if(BD[14] == 0)
								{								
									zero = 1;
								}
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 + t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
					}
					break;
				}
				case(2):
				{
					switch(t.modo)
					{
						case(0): /* Subtracao modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] - BD[t.reg1];
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] - BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
						case(1): /* Subtacao modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] - BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;	
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] - BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;	

							}
							break;
						}
						case(2): /* Subtracao modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 - t.reg1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;	
							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 - t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;	

							}
							break;
						}
					}
					break;
				}
				case(3):
				{
					switch(t.modo)
					{
						case(0): /* Incremento modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] + 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;	
							}
							else if(t.regdest == 1)
							{
								BD[t.reg0] = BD[t.reg0] + 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		

							}
							break;
						}
						case(1): /* Incremento modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								BD[temp0] = BD[temp0] + 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								BD[temp0] = BD[temp0] + 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		

							}
							break;
						}
						case(2): /* Incremento modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 + 1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;	

							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 + 1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;	
							}
							break;
						}
					}
					break;
				}
				case(4):
				{
					switch(t.modo)
					{
						case(0): /* Decremento modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] - 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								BD[t.reg0] = BD[t.reg0] - 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;	
							}
							break;
						}
						case(1): /* Decremento modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								BD[temp0] = BD[temp0] - 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								BD[temp0] = BD[temp0] - 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
						case(2): /* Decremento modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 - 1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 - 1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
					}
					break;
				}
				case(5):
				{
					switch(t.modo)
					{
						case(0): /* Multiplicacao modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] * BD[t.reg1];
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] * BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;		

							}
							break;
						}
						case(1): /* Multiplicacao modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] * BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] * BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;		

							}
							break;
						}
						case(2): /* Multiplicacao modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 * t.reg1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 * t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;		

							}
							break;
						}
					}
					break;
				}
				case(6):
				{
					switch(t.modo)
					{
						case(0): /* Divisao modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] / BD[t.reg1];
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] / BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;		

							}
							break;
						}
						case(1): /* Divisao modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] / BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] / BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;		

							}
							break;
						}
						case(2): /* Divisao modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 / t.reg1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 / t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
					}
					break;
				}
				case(7):
				{
					switch(t.modo)
					{
						case(0): /* Resto da divisao modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] % BD[t.reg1];
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] % BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
						case(1): /* Resto da divisao modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] % BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		

							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] % BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;
							}
							break;
						}
						case(2): /* Resto da divisao modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 % t.reg1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;
							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 % t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;	
							}
							break;
						}
					}
					break;
				}
				case(8):
				{
					switch(t.modo)
					{
						case(0): /* Deslocamento a direita modo direto */
						{
							if(t.regdest == 0)
							{
								x = BD[t.reg0] << 15;
								x = x >> 15;
								BD[t.reg0] = BD[t.reg0] >> 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;
								if(x == 1)carry=1;
								else carry=0;
							}
							else if(t.regdest == 1)
							{
								x = BD[t.reg0] << 15;
								x = x >> 15;
								BD[t.reg0] = BD[t.reg0] >> 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;	
								if(x == 1)carry=1;
								else carry=0;
							}
							overflow=-1;
							break;
						}
						case(1): /* Deslocamento a direita modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								x = BD[temp0] << 15;
								x = x >> 15;
								BD[temp0] = BD[temp0] >> 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;
								if(x == 1)carry=1;
								else carry=0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								x = BD[temp0] << 15;
								x = x >> 15;
								BD[temp0] = BD[temp0] >> 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;
								if(x == 1)carry=1;
								else carry=0;		
							}
							overflow=-1;
							break;
						}
						case(2): /* Deslocamento a direita modo imediato */
						{
							if(t.regdest == 0)
							{
								x = t.reg0 << 15;
								x = x >> 15;
								BD[14] = t.reg0 >> 1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;
								if(x == 1)carry=1;
								else carry=0;	
							}
							else if(t.regdest == 1)
							{
								x = t.reg0 << 15;
								x = x >> 15;
								BD[15] = t.reg0 >> 1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;	
								if(x == 1)carry=1;
								else carry=0;		
							}
							overflow=-1;
							break;
						}
					}
					break;
				}
				case(9):
				{
					switch(t.modo)
					{
						case(0): /* Deslocamento a esquerda modo direto */
						{
							if(t.regdest == 0)
							{
								x = BD[t.reg0] >> 15;
								BD[t.reg0] = BD[t.reg0] << 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
								if(x == 1)carry=1;
								else carry=0;	
							}
							else if(t.regdest == 1)
							{
								x = BD[t.reg0] >> 15;
								BD[t.reg0] = BD[t.reg0] << 1;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;
								if(x == 1)carry=1;
								else carry=0;	
							}
							overflow=-1;
							break;
						}
						case(1): /* Deslocamento a esquerda modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								x = BD[temp0] >> 15;
								BD[temp0] = BD[temp0] << 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;	
								if(x == 1)carry=1;
								else carry=0;
							
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								x = BD[temp0] >> 15;
								BD[temp0] = BD[temp0] << 1;
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;	
								if(x == 1)carry=1;
								else carry=0;
							}
							overflow=-1;
							break;
						}
						case(2): /* Deslocamento a esquerda modo imediato */
						{
							if(t.regdest == 0)
							{
								x = t.reg0 >> 15;
								BD[14] = t.reg0 << 1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		
								if(x == 1)carry=1;
								else carry=0;
							}
							else if(t.regdest == 1)
							{
								x = t.reg0 >> 15;
								BD[15] = t.reg0 << 1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;	
								if(x == 1)carry=1;
								else carry=0;
							}
							overflow=-1;
							break;
						}
					}
					break;
				}
				case(10):
				{
					switch(t.modo)
					{
						case(0): /* Rotacao a direita modo direto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0] >> 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[t.reg0] << 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[t.reg0] = temp0;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0] >> 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[t.reg0] << 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[t.reg0] = temp0;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							carry=-1,overflow=-1;
							break;
						}
						case(1): /* Rotacao a direita modo indireto */
						{
							if(t.regdest == 0)
							{
								temp2 = BD[t.reg0];
								temp0 = BD[temp2] >> 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[temp2] << 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[temp2] = temp0;
								if(BD[temp2] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp2 = BD[t.reg0];
								temp0 = BD[temp2] >> 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[temp2] << 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[temp2] = temp0;
								if(BD[temp2] == 0)zero = 1;
								else zero = 0;		
							}
							carry=-1,overflow=-1;
							break;
						}
						case(2): /* Rotacao a direita modo imediato */
						{
							if(t.regdest == 0)
							{
								temp0 = t.reg0 >> 15 ;
								temp0 = temp0 | 0;
								temp1 = t.reg0 << 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[14] = temp0;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = t.reg0 >> 15 ;
								temp0 = temp0 | 0;
								temp1 = t.reg0 << 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[15] = temp0;
								if(BD[15] == 0)zero = 1;
								else zero = 0;		
							}
							carry=-1,overflow=-1;
						}
						break;
					}
					break;
				}
				case(11):
				{
					switch(t.modo)
					{
						case(0): /* Rotacao a esquerda modo direto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0] << 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[t.reg0] >> 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[t.reg0] = temp0;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0] << 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[t.reg0] >> 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[t.reg0] = temp0;
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							carry=-1,overflow=-1;
							break;
						}
						case(1): /* Rotacao a esquerda modo indireto */
						{
							if(t.regdest == 0)
							{
								temp2 = BD[t.reg0];
								temp0 = BD[temp2] << 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[temp2] >> 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[temp2] = temp0;
								if(BD[temp2] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp2 = BD[t.reg0];
								temp0 = BD[temp2] << 15 ;
								temp0 = temp0 | 0;
								temp1 = BD[temp2] >> 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[temp2] = temp0;
								if(BD[temp2] == 0)zero = 1;
								else zero = 0;		
							}
							carry=-1,overflow=-1;
							break;
						}
						case(2): /* Rotacao a esquerda modo imediato */
						{
							if(t.regdest == 0)
							{
								temp0 = t.reg0 << 15 ;
								temp0 = temp0 | 0;
								temp1 = t.reg0 >> 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[14] = temp0;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = t.reg0 << 15 ;
								temp0 = temp0 | 0;
								temp1 = t.reg0 >> 1;
								temp1 = temp1 | 0;
								temp0 = temp1 | temp0;
								BD[15] = temp0;
								if(BD[15] == 0)zero = 1;
								else zero = 0;		
							}
							carry=-1,overflow=-1;
							break;
						}
					}
					break;
				}
				case(12):
				{
					switch(t.modo)
					{
						case(0): /* OR logico modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] | BD[t.reg1];
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] | BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(1): /* OR logico modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] | BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] | BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(2): /* OR logico modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 | t.reg1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 | t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
					}
					break;
			}
			case(13):
				{
					switch(t.modo)
					{
						case(0): /* AND logico modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] & BD[t.reg1];
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] & BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(1): /* AND logico modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] & BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] & BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(2): /* AND logico modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 & t.reg1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 & t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
					}
					break;
			}
			case(14):
				{
					switch(t.modo)
					{
						case(0): /* XOR logico modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = BD[t.reg0] ^ BD[t.reg1];
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[t.reg1] = BD[t.reg0] ^ BD[t.reg1];
								if(BD[t.reg1] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(1): /* XOR logico modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp0] = BD[temp0] ^ BD[temp1];
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								temp1 = BD[t.reg1];
								BD[temp1] = BD[temp0] ^ BD[temp1];
								if(BD[temp1] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(2): /* XOR logico modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = t.reg0 ^ t.reg1;
								if(BD[14] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[15] = t.reg0 ^ t.reg1;
								if(BD[15] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
					}
					break;
			}
			case(15):
				{
					switch(t.modo)
					{
						case(0): /* NOT logico modo direto */
						{
							if(t.regdest == 0)
							{
								BD[t.reg0] = ~(BD[t.reg0]);
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[t.reg0] = ~(BD[t.reg0]);
								if(BD[t.reg0] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(1): /* NOT logico modo indireto */
						{
							if(t.regdest == 0)
							{
								temp0 = BD[t.reg0];
								BD[temp0] = ~(BD[temp0]);
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								temp0 = BD[t.reg0];
								BD[temp0] = ~(BD[temp0]);
								if(BD[temp0] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
						case(2): /* NOT logico modo imediato */
						{
							if(t.regdest == 0)
							{
								BD[14] = ~(t.reg0);
								if(BD[14] == 0)zero = 1;
								else zero = 0;		
							}
							else if(t.regdest == 1)
							{
								BD[15] = ~(t.reg0);
								if(BD[15] == 0)zero = 1;
								else zero = 0;		
							}
							carry = -1,overflow = -1;
							break;
						}
					}
					break;
				}
			}
			break;
		}
		case(1): /* Executa instrucoes do tipo I */
		{
			switch(t.opcode)
			{
				case(16): /* Li */
				{
					if(t.regdest == 0)
					{
						BD[14] = 0;
						BD[14] = t.cost;
					}
					else if(t.regdest == 1)
					{
						BD[15] = 0;
						BD[15] = t.cost;
					}
					carry = -1,zero = -1,overflow = -1;
					break;
				}
				case(17): /* Lui */
				{
					if(t.regdest == 0)
					{
						BD[14] = 0;
						BD[14] = t.cost;
						BD[14] = BD[14] << 8;
						BD[14] = BD[14] | 0;
					}
					else if(t.regdest == 1)
					{
						BD[15] = 0;
						BD[15] = t.cost;
						BD[15] = BD[15] << 8;
						BD[15] = BD[15] | 0;
					}
					carry = -1,zero = -1,overflow = -1;
					break;
				}
			}
			break;
		}
		case(2): /* Executa instrucoes do tipo Load/Store */
		{
			switch(t.opcode)
			{
				case(18): /* lw */
				{
					x = (unsigned short int) MEM_DATA[BD[t.reg1]];
					x = x << 8;
					x = x | 0;
					y = (unsigned short int) MEM_DATA[BD[t.reg1]+1];
					BD[t.reg0] = x | y;
					carry = -1,zero = -1,overflow = -1;
					break;
				}
				case(19): /* sw */
				{
					x = BD[t.reg1] >> 8;
					y = BD[t.reg1] << 8;
					y = y >> 8;
					MEM_DATA[BD[t.reg0]] =  x;
					MEM_DATA[BD[t.reg0]+1] =  y;
					carry = -1,zero = -1,overflow = -1;
					break;
				}
				case(20): /* lb */
				{
					BD[t.reg0] = (unsigned short int)MEM_DATA[BD[t.reg1]];
					carry = -1,zero = -1,overflow = -1;
					break;
				}
				case(21): /* sb */
				{
				 	MEM_DATA[BD[t.reg0]] = BD[t.reg1];
					carry = -1,zero = -1,overflow = -1;
					break;
				}
				case(22): /* mov */
				{
					BD[t.reg1] = BD[t.reg0];
					carry = -1,zero = -1,overflow = -1;
					break;
				}
			}
			break;
		}
		case(3): /* Executa instrucoes do tipo branch */ // carry zero overflow
		{
			switch(t.opcode)
			{
				case(23): /* jv */
				{
					if(overflow == 1)
					{
						PC = PC + (t.desl);
						overflow = -1;
					}
					break;
				}
				case(24): /* jnv */
				{
					if(overflow == 0)
					{
						PC = PC + (t.desl);
						overflow = -1;
					}
					break;
				}
				case(25): /* jz */
				{
					if(zero == 1)
					{
						PC = PC + (t.desl);
						zero = -1;
					}
					break;
				}
				case(26): /* jnz */
				{
					if(zero == 0)
					{
						PC = PC + (t.desl);
						zero = -1;
					}
					break;
				}
				case(27): /* jc */
				{
					if(carry == 1)
					{
						PC = PC + (t.desl);
						carry = -1;
					}
					break;
				}
				case(28): /* jnc */
				{
					if(carry == 0)
					{
						PC = PC + (t.desl);
						carry = -1;
					}
					break;
				}
				case(29): /* jmp */
				{
					PC = PC + (t.desl);
					break;
				}
			}
			break;
		}
	}
}
int EXECUTA()
{
	Ula(inst0,1);
}
void INTERFACE_SIMULADOR()
{
	do
	{
		printf("\33[H\33[2J");
		/*
		printf("\n\t\t|| -- 	           ISS AIDA      	      -- ||\n");
		printf("\t\t|| --  				    	      -- ||\n");
		printf("\t\t|| --    (E) - Executar numero X de fases    --  ||\n");
		printf("\t\t|| --    (C) - Executar fase a fase          --  ||\n");
		printf("\t\t|| --    (M) - Mostrar ende word memoria dado -- ||\n");
		printf("\t\t|| --    (I) - Mostrar conte end memoria inst -- ||\n");
		printf("\t\t|| --    (Y) - Mostrar inter mem instrucao    -- ||\n");
		printf("\t\t|| --    (D) - Mostrar inter mem dados        -- ||\n");
		printf("\t\t|| --    (B) - Mostrar conteudo BR MI MD      -- ||\n");
		printf("\t\t|| --    (S) - Sair do simulador              -- ||\n");
		printf("\t\t|| --  				    	      -- ||\n");
		printf("\n\t\t\t\t\t\t   Opcao [ ]\b\b");
		fflush(stdin);
		scanf("%c",&opt);
		fflush(stdin);
		*/
		opt = 'C'; 
		opt = toupper(opt);
		if(opt == 'S')
		{
			printf("\33[H\33[2J");
			break;
		}
		switch(opt)
		{
			case('E'): /* Executa um numero de ciclos especificado */
			{
				printf("\nEntre com o numero de fases : [   ]\b\b\b\b");
				scanf("%d",&ciclos);
				printf("\nEntre com o tempo em segundos de cada fase : [  ]\b\b\b");
				scanf("%d",&tempo);
				fflush(stdin);
				do
				{
					for(contador=0;contador<ciclos;contador++)
					{
						fflush(stdin);
						printf("\33[H\33[2J");
						printf("\n||----------------|_-_-_-_-_Execucao da fase_-_-_-_-_|-------------------||\n");
						printf("||----------------|----------------------------------|-------------------||\n");
						printf("||----------------|----------------------------------|-------------------||\n");
						printf("||    Banco Reg   |       Memoria de Instrucao       |      Mem Data     ||\n||\t\t  |\t\t      \t\t     |\t\t         ||\n");
						for(contador2=0;contador2<16;contador2++)
						{
							instrucao0 = MEM_INST[((PC)+contador2)];
							DECODIFICA_INSTRUCAO();
							retorna_instrucao(inst0);
							printf("|| BD[%2d] : %5d | MInst[%2d] : %20s | Mdata[%2d] :",contador2,BD[contador2],((PC)+contador2),sinstrucao,(contador2));
							if(MEM_DATA[(contador2)] != 255)printf(" %5d ||\n",MEM_DATA[(contador2)]);
							else printf("       ||\n");
						}
						printf("||----------------|----------------------------------|-------------------||\n");
						if(flag == 1 || flag == 2)
						{
							printf("\nExecucao encerrada, encerrando simulador !!\n\n");
							sleep(3);
							printf("\33[H\33[2J");
							exit(0);
						}
						instrucao1 = MEM_INST[(PC+1)];
						instrucao0 = MEM_INST[(PC)];
						x = PC;
						flag = BUSCA_INSTRUCAO();
						inst0 = Decodifica(instrucao0);
						retorna_instrucao(inst0);
						printf("\nInstrucao[%d] : %s\t\t",x,sinstrucao);
						inst1 = Decodifica(instrucao1);
						retorna_instrucao(inst1);
						printf("\n");
						DECODIFICA_INSTRUCAO();
						EXECUTA();
						sleep(tempo);
					}
					printf("\n\nPressione Enter ou qualquer outra tecla para sair !! [ ]\b\b");
					opt1 = getchar();
				}while(opt1 == 10);
				break;
			}
			case('C'): /* Executa ciclo a ciclo */
			{
				do
				{
					fflush(stdin);
					printf("\33[H\33[2J");
					printf("\n||----------------|_-_-_-_Execucao fase a fase_-_-_-_|-------------------||\n");
					printf("||----------------|----------------------------------|-------------------||\n");
					printf("||----------------|----------------------------------|-------------------||\n");
	printf("||    Banco Reg   |       Memoria de Instrucao       |      Mem Data     ||\n||\t\t  |\t\t      \t\t     |\t\t         ||\n");
					for(contador2=0;contador2<16;contador2++)
					{
						instrucao0 = MEM_INST[((PC)+contador2)];
						DECODIFICA_INSTRUCAO();
						retorna_instrucao(inst0);
printf("|| BD[%2d] : %5d | MInst[%2d] : %20s | Mdata[%2d] :",contador2,BD[contador2],((PC)+contador2),sinstrucao,(contador2));
						if(MEM_DATA[(contador2)] != 255)printf(" %5d ||\n",MEM_DATA[(contador2)]);
						else printf("       ||\n");
					}
					printf("||----------------|----------------------------------|-------------------||\n");
					if(flag == 1 || flag == 2)
					{
						printf("\nExecucao encerrada, encerrando simulador !!\n\n");
						sleep(3);
						printf("\33[H\33[2J");
						exit(0);
					}
					instrucao1 = MEM_INST[(PC+1)];
					instrucao0 = MEM_INST[(PC)];
					x = PC;
					flag = BUSCA_INSTRUCAO();
					inst0 = Decodifica(instrucao0);
					retorna_instrucao(inst0);
					printf("\nInstrucao[%d] : %s\t\t",x,sinstrucao);
					inst1 = Decodifica(instrucao1);
					retorna_instrucao(inst1);
					//printf("Instrucao[%d] : %s\n",x+1,sinstrucao);
					DECODIFICA_INSTRUCAO();
					EXECUTA();
					printf("\n\nPressione uma tecla para continuar !! [ ]\b\b");
					opt1 = getchar();
				}while(opt1 == 10);
				break;
			}
			case('M'): /* Mosta o conteudo de uma word da memoria de dados */
			{
				printf("\nEntre com o endereco da memoria de dados : ");
				scanf("%d",&end_mem);
				fflush(stdin);
				temp0=0,temp1=0;
				temp0 =  MEM_DATA[end_mem];
				temp0 = temp0 << 8;
				temp1 =  MEM_DATA[(end_mem+1)];
				temp1 = temp1 << 8;
				temp1 = temp1 >> 8;
				temp0 = temp0 | temp1;
				if(MEM_DATA[end_mem] == 255 || MEM_DATA[(end_mem+1)] == 255)
				{
					printf("\nEnd Word [%d/%d] :   \n",end_mem,(end_mem+1));
				}
				else
				{
					printf("\nEnd Word [%d/%d] : %xs\n",end_mem,(end_mem+1),temp0);
				}
				printf("\nPressione uma tecla para continuar !! [ ]\b\b");
				getchar();
				break;
			}
			case('I'): /* Mosta o conteudo de um endereco da memoria de instrucoes */
			{
				printf("\nEntre com o endereco da memoria de instrucoes : ");
				scanf("%d",&end_mem);
				fflush(stdin);
				instrucao0 = MEM_INST[end_mem];
				DECODIFICA_INSTRUCAO();
				retorna_instrucao(inst0);
				printf("\nEnd [%d] : %s\n",end_mem,sinstrucao);
				printf("\nPressione uma tecla para continuar !! [ ]\b\b");
				getchar();
				break;
			}
			case('Y'): /* Mostra um intervalo de enderecos da memoria de instrucoes */
			{
				printf("\nEntre com enderedo do inicio do intervalo : ");
				scanf("%d",&ini_inter);
				fflush(stdin);
				printf("\nEntre com endereco do final do intervalo : ");
				scanf("%d",&fim_inter);printf("\n||----------------|_-_-_BD / MEM INST / MEM DATA_-_-_|-------------------||\n");
				printf("||----------------|----------------------------------|-------------------||\n");
	printf("||----------------|----------------------------------|-------------------||\n");
		printf("||    Banco Reg   |       Memoria de Instrucao       |      Mem Data     ||\n||\t\t  |\t\t      \t\t     |\t\t         ||\n");
				for(contador2=0;contador2<16;contador2++)
				{
					instrucao0 = MEM_INST[(PC+contador2)];
					DECODIFICA_INSTRUCAO();
					retorna_instrucao(inst0);
printf("|| BD[%2d] : %5d | MInst[%2d] : %20s | Mdata[%2d] : %5d ||\n",contador2,BD[contador2],(PC+contador2),sinstrucao,contador2,MEM_DATA[contador2]);
				}
				printf("||----------------|----------------------------------|-------------------||\n");
				printf("\nPressione uma tecla para continuar !! [ ]\b\b");
				fflush(stdin);
				printf("\33[H\33[2J");
				printf("\n\n||---_-_-_-_-_Memoria de instrucao_-_-_-_-_---||\n");
				printf("||                                            ||\n");
				for(contador=ini_inter;contador<fim_inter;contador++)
				{
					instrucao0 = MEM_INST[contador];
					DECODIFICA_INSTRUCAO();
					retorna_instrucao(inst0);
					printf("||      End [%3d] : %20s      ||\n",contador,sinstrucao);
				}
				printf("||                                            ||\n");
				printf("\nPressione uma tecla para continuar !! [ ]\b\b");
				getchar();
				break;
			}
			case('D'): /* Mostra um intervalo de enderecos da memoria de dados */
			{
				printf("\nEntre com enderedo do inicio do intervalo : ");
				scanf("%d",&ini_inter);
				fflush(stdin);
				printf("\nEntre com endereco do final do intervalo : ");
				scanf("%d",&fim_inter);
				fflush(stdin);
				printf("\33[H\33[2J");
				printf("\n\n||-----_-_Memoria de dados_-_----||\n");
				printf("||                               ||\n");
				for(contador=ini_inter;contador<fim_inter;contador++)
				{
					printf("||      End [%3d] : %5x        ||\n",contador,MEM_DATA[contador]);
				}
				printf("||                               ||\n");
				printf("\nPressione uma tecla para continuar !! [ ]\b\b");
				getchar();
				break;
			}
			case('B'): /* Mostra o banco de registradores a memoria de instrucoes e a memoria de dados */
			{
				printf("\33[H\33[2J");
				printf("\n||----------------|_-_-_BD / MEM INST / MEM DATA_-_-_|-------------------||\n");
				printf("||----------------|----------------------------------|-------------------||\n");
				printf("||----------------|----------------------------------|-------------------||\n");
printf("||    Banco Reg   |       Memoria de Instrucao       |      Mem Data     ||\n||\t\t  |\t\t      \t\t     |\t\t         ||\n");
				for(contador2=0;contador2<16;contador2++)
				{
					instrucao0 = MEM_INST[(PC+contador2)];
					DECODIFICA_INSTRUCAO();
					retorna_instrucao(inst0);
printf("|| BD[%2d] : %5x | MInst[%2d] : %20s | Mdata[%2d] :",contador2,BD[contador2],(PC+contador2),sinstrucao,contador2);
					if(MEM_DATA[(contador2)] != 255)printf(" %5x ||\n",MEM_DATA[(contador2)]);
					else printf("       ||\n");
				}
				printf("||----------------|----------------------------------|-------------------||\n");
				printf("\nPressione uma tecla para continuar !! [ ]\b\b");
				getchar();
				break;
			}
			default:
			{
				printf("\nOpcao invalida !!\n");
				printf("\nPressione uma tecla para continuar !! [ ]\b\b");
				getchar();
				break;
			}
		}
	}while(1);
}
int main(int argc,char *argv[])
{
	ARQUIVO_ENTRADA(argc,argv[1]); 
	INICIA_SIMULADOR();
	LE_MEMORIA_INSTRUCAO();
	LE_MEMORIA_DADOS();
	INTERFACE_SIMULADOR();
	return(0);
}
