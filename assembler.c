/* Universidade Regional Integrada do Alto uruguai e das Missões */
/* Montador do AIDA */
/* Disciplina : Trabalho de conclusao - 10 Semestre */
/* Professor : Mr.Carlos petry */
/* Aluno : Raffael Bottoli Schemmer */
/* Data Termino : 17/11/2009 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 65536

FILE *in,*out;

char matriz_entrada[TAM][256];
char tauxiliar[256],tauxiliar2[256];
char c;

int mem_inst,mem_data,ponteiro,tamanho,modo,tmp;
int contador,contador1,contador2,contador3,tamanho_arquivo;
int flag_t=0,flag_m=0,parada=0;
unsigned short int instrucao;
char MEM_INST[TAM][256];
char MEM_DATA[TAM][256];

struct instrucao
{
	unsigned short int formato;
	unsigned short int parametro;
	unsigned short int opcode;
	unsigned short int modo_end;
	unsigned short int reg_dest;
	unsigned short int reg0;
	unsigned short int reg1;
	unsigned short int cont;
	unsigned short int desl;
}i[TAM];
struct celula
{
	unsigned short int tipo;
	unsigned short int valor_word;
	unsigned char valor_byte;
}m[TAM];
void TABELA_DE_ERROS(int erro) /* Mostra os erros gerados pelo montador */
{
	printf("\n|| -- Tratamento dos erros (Lexicos/Sintaticos/Semanticos) -- ||\n\n");
	switch(erro)
	{
		case(0):
		{
			printf("Linha [%d] : Erro(%d) : Falta parametros na instrucao\n",contador+2,erro+1);
			break;
		}
		case(1):
		{
			printf("Linha [%d] : Erro(%d) : Can't open file input !!\n",contador+2,erro+1); 
			break;
		}
		case(2):
		{
			printf("Linha [%d] : Erro(%d) : Can't open output !!\n",contador+2,erro+1); 
			break;
		}
		case(3):
		{
			printf("Linha [%d] : Erro(%d) : .text nao encontrado !!\n",contador+2,erro+1);
			break;
		}
		case(4):
		{
			printf("Linha [%d] : Erro(%d) : .data nao encontrado !!\n",contador+2,erro+1);
			break;
		}
		case(5):
		{
			printf("Linha [%d] : Erro(%d) : Opcode nao encontrado na instrucao !!\n",contador+2,erro+1);
			break;
		}
		case(6): 
		{
			printf("Linha [%d] : Erro(%d) : Falta operandos na instrucao do tipo R !!\n",contador+2,erro+1);
			break;
		}
		case(7):
		{
			printf("Linha [%d] : Erro(%d) : Modo de enderecamento nao suportado pela instrucao do tipo R !!\n",contador+2,erro+1);
			break;
		}
		case(8):
		{
			printf("Linha [%d] : Erro(%d) : .byte nao comporta essa capacidade !!\n",contador+2,erro+1);
			break;
		}
		case(9):
		{
			printf("Linha [%d] : Erro(%d) : Registrador destino nao suportado pela instrucao do tipo R !!\n",contador+2,erro+1);
			break;
		}
		case(10):
		{
			printf("Linha [%d] : Erro(%d) : Constante nao suportada pela instrucao do tipo R !!\n",contador+2,erro+1);
			break;
		}
		case(11):
		{
			printf("Linha [%d] : Erro(%d) : Registrador nao suportado !!\n",contador+2,erro+1);
			break;
		}
		case(12):
		{
			printf("Linha [%d] : Erro(%d) : Constante nao suportada !!\n",contador+2,erro+1);
			break;
		}
		case(13):
		{
			printf("Linha [%d] : Erro(%d) : Registrador destino nao suportado pela instrucao do tipo I !!\n",contador+2,erro+1);
			break;
		}
		case(14):
		{
			printf("Linha [%d] : Erro(%d) : Falta parametros na instrucao do tipo I !!\n",contador+2,erro+1);
			break;
		}
		case(15):
		{
			printf("Linha [%d] : Erro(%d) : Falta parametros na instrucao do tipo Load/Store !!\n",contador+2,erro+1);
			break;
		}
		case(16):
		{
			printf("Linha [%d] : Erro(%d) : Falta parametros na instrucao do tipo Branch !!\n",contador+2,erro+1);
			break;
		}
		case(17):
		{
			printf("Linha [%d] : Erro(%d) : Tamanho do salto do desvio nao suportado !!\n",contador+2,erro+1);
			break;
		}
		case(18):
		{
			printf("Linha [%d] : Erro(%d) : Excesso de parametros !!\n",contador+2,erro+1);
			break;
		}
		case(19):
		{
			printf("Linha [%d] : Erro(%d) : Token de representacao de dado desconhecido !!\n",contador+2,erro+1);
			break;
		}
		case(20):
		{
			printf("Linha [%d] : Erro(%d) : Instrucao halt nao encontrada no codigo assembly !!\n",contador+2,erro+1);
			break;
		}
	}
	printf("\n");
	exit(0);
}
void ARQUIVO_ENTRADA(int parametro,char nome_arquivo[30]) /* Responsavel por abrir o arquivo de entrada */
{
	if(parametro <= 1) TABELA_DE_ERROS(0); // Erro quando parametro nao eh informado
	in = fopen(nome_arquivo,"rb");
	if(in == NULL) TABELA_DE_ERROS(1); // Erro quando nao eh possivel abrir o arquivo de entrada(Ex: arquivo nao encontrado)
}
void ARQUIVO_SAIDA(char nome_arquivo[30]) /* Responsavel por abrir o arquivo de saida */
{
	tamanho = strlen(nome_arquivo);
	nome_arquivo[tamanho-3] = '\0'; /* Troca a extensao de saida para .bin */
	strcat(nome_arquivo,"bin");	
	out = fopen(nome_arquivo,"w+b");
	if(out == NULL) TABELA_DE_ERROS(2); // Erro quando nao eh possivel abrir o arquivo de saida
}
void LE_ARQUIVO_ENTRADA() /* Funcao que le o arquivo de entrada informado */
{
	tamanho_arquivo = 0;
	while(!feof(in)) /* Enquanto for diferente do final do arquivo executa */
	{
		tauxiliar[0] = '\0';
		fgets(tauxiliar,256,in); /* Copia 256 caracteres do arquivo na matriz */
		tamanho = strlen(tauxiliar); /* Obtem o tamanho da linha da matriz temporaria auxiliar */
		contador1=0;
		for(contador=0;(tauxiliar[contador] == 32 || tauxiliar[contador] == 9);contador++)
		tauxiliar2[0] = '0';
		contador2=0;
		while(contador < tamanho)
		{
			tauxiliar2[contador2] = tauxiliar[contador];
			contador++;
			contador2++;
		}
		tauxiliar2[contador2+1] = '\0';
		strcpy(tauxiliar,tauxiliar2);
		if(feof(in)){break;}
		else if(tauxiliar[0] == 35 || tauxiliar[0] == 10){}
		else
		{
			for(contador=0;contador < tamanho;contador++) /* Faz a leitura para a matriz principal char a char da matriz auxiliar */
			{
				if(tauxiliar[contador] != 32 && tauxiliar[contador] != 9)
				{
					if(tauxiliar[contador] == 35 || tauxiliar[contador] == 10)
					{
						matriz_entrada[tamanho_arquivo][contador1] = '\0';
						break;
					}
					matriz_entrada[tamanho_arquivo][contador1] =  tauxiliar[contador];
					contador1++;
				}	
			}
			tamanho_arquivo++;
		}
	}
}
void CARREGA_MEMORIA_DE_INSTRUCAO()
{
	for(contador=0;contador<tamanho_arquivo;contador++)
	{
		tamanho = strlen(matriz_entrada[contador]);
		if(matriz_entrada[contador][0] == '.' && matriz_entrada[contador][1] == 't' && 
		matriz_entrada[contador][2] == 'e' && matriz_entrada[contador][3] == 'x' 
		&& matriz_entrada[contador][4] == 't')
		{
			break;
		}
	}
	if(contador == tamanho_arquivo){TABELA_DE_ERROS(3);} // .text nao encontrado
	mem_inst=0;
	contador++;
	int flag=0;
	do
	{
			if(matriz_entrada[contador][0] == '.' && matriz_entrada[contador][1] == 'd' && 
			matriz_entrada[contador][2] == 'a' && matriz_entrada[contador][3] == 't' 
			&& matriz_entrada[contador][4] == 'a')
			{
				flag = 1;
				break;
			}
			if(matriz_entrada[contador][0] == 'h' && matriz_entrada[contador][1] == 'a' && 
			matriz_entrada[contador][2] == 'l' && matriz_entrada[contador][3] == 't')
			{
				parada = 1;
			}
			tamanho = strlen(matriz_entrada[contador]);
			for(contador2=0;contador2 < tamanho;contador2++)
			{
				MEM_INST[mem_inst][contador2] = matriz_entrada[contador][contador2];
			}
			MEM_INST[mem_inst][contador2++] = '\0';
			tamanho = strlen(MEM_INST[mem_inst]);
			contador++;
			tolower(MEM_INST[mem_inst]);
			mem_inst++;
	}while(contador < tamanho_arquivo);
	if(flag == 0){TABELA_DE_ERROS(4);} // .data nao encontrado
	if(parada == 0){TABELA_DE_ERROS(20);} // halt nao encontrado
}
void CARREGA_MEMORIA_DE_DADOS()
{
	mem_data = 0;
	contador++;
	while(contador < tamanho_arquivo)
	{
		tamanho = strlen(matriz_entrada[contador]);
		strcpy(MEM_DATA[mem_data],matriz_entrada[contador]);
		contador++;
		mem_data++;
	}
}
int verifica_registrador()
{
	if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '0' && (strlen(tauxiliar) == 3)){return(0);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '1' && (strlen(tauxiliar) == 3)){return(1);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '2' && (strlen(tauxiliar) == 3)){return(2);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '3' && (strlen(tauxiliar) == 3)){return(3);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '4' && (strlen(tauxiliar) == 3)){return(4);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '5' && (strlen(tauxiliar) == 3)){return(5);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '6' && (strlen(tauxiliar) == 3)){return(6);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '7' && (strlen(tauxiliar) == 3)){return(7);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '8' && (strlen(tauxiliar) == 3)){return(8);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '9' && (strlen(tauxiliar) == 3)){return(9);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '1' && tauxiliar[3] == '0' && (strlen(tauxiliar) == 4)){return(10);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '1' && tauxiliar[3] == '1' && (strlen(tauxiliar) == 4)){return(11);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '1' && tauxiliar[3] == '2' && (strlen(tauxiliar) == 4)){return(12);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 'r' && tauxiliar[2] == '1' && tauxiliar[3] == '3' && (strlen(tauxiliar) == 4)){return(13);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 't' && tauxiliar[2] == '0' && (strlen(tauxiliar) == 3)){return(14);}
	else if(tauxiliar[0] == '$' && tauxiliar[1] == 't' && tauxiliar[2] == '1' && (strlen(tauxiliar) == 3)){return(15);}
	else{TABELA_DE_ERROS(11);} // Banco de registrador nao suportado */
	return(-1);
}
void formato_r(int tipo,int parametros) // Formato R Ok
{
	/* Verifica o formato da instrucao */
	i[contador].parametro = parametros;
	i[contador].formato = 0;
	if(tipo == 0)contador1 = 3;
	else contador1 = 2;
	
	/* Separa o modo de enderecamento */
	contador2=0;
	while(MEM_INST[contador][contador1] != ',')
	{
		if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){TABELA_DE_ERROS(6);} // Falta parametros na instrucao
		tauxiliar[contador2] = MEM_INST[contador][contador1];
		contador1++;
		contador2++;
	}
	/* Trata o modo de enderecamento */
	contador1++;
	tauxiliar[contador2] = '\0';
	if(tauxiliar[0] == '0' && tauxiliar[1] == '0' && (strlen(tauxiliar) == 2))
	{
		modo = 0;
		i[contador].modo_end = 0;
	}
	else if(tauxiliar[0] == '0' && tauxiliar[1] == '1' && (strlen(tauxiliar) == 2))
	{
		modo = 1;
		i[contador].modo_end = 1;
	}
	else if(tauxiliar[0] == '1' && tauxiliar[1] == '0' && (strlen(tauxiliar) == 2))
	{
		modo = 2;
		i[contador].modo_end = 2;
	}
	else{TABELA_DE_ERROS(7);} // Modo de enderecamento nao suportado
	contador2=0;
	/* Separa o registrador destino */
	while(MEM_INST[contador][contador1] != ',') // Aqui separa o registrador destino
	{
		if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){TABELA_DE_ERROS(6);} // Falta parametros na instrucao
		tauxiliar[contador2] = MEM_INST[contador][contador1];
		contador1++;
		contador2++;	
	}
	contador1++;
	tauxiliar[contador2] = '\0';
	contador2=0; // Aqui trata o registrador destino
	if(tauxiliar[0] == '0' && (strlen(tauxiliar) == 1)){i[contador].reg_dest = 0;}
	else if(tauxiliar[0] == '1' && (strlen(tauxiliar) == 1)){i[contador].reg_dest = 1;}
	else {TABELA_DE_ERROS(9);} // Registrador destino nao suportado
	/* Se a instrucao tem 2 parametros(1) busca o primeiro */
	if(parametros == 1)
	{
		while(MEM_INST[contador][contador1] != ',') // Aqui pega o primeiro operando
		{
			if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){TABELA_DE_ERROS(6);} // Falta parametros 
			tauxiliar[contador2] = MEM_INST[contador][contador1];
			contador1++;
			contador2++;
		}
		contador1++;
		tauxiliar[contador2] = '\0';
	}
	else /* Se a instrucao tem 1 parametro(0) busca o parametro */
	{
		while(1)
		{
			if(MEM_INST[contador][contador1] == ',')
			{
				TABELA_DE_ERROS(18);
			}
			if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){break;} 
			tauxiliar[contador2] = MEM_INST[contador][contador1];
			contador1++;
			contador2++;
		}
		contador1++;
		tauxiliar[contador2] = '\0';
		if((strlen(tauxiliar)) > 0){}
		else{TABELA_DE_ERROS(6);} // Falta parametros
	}
	/* Se o modo de enderecamento for imediato avalia os campos */
	if(modo == 2)
	{
		if(parametros == 1)
		{
			contador3 = atoi(tauxiliar);
			if(contador3 >= 0 && contador3 <= 15){}
			else{TABELA_DE_ERROS(10);} // Constante nao suportada
			i[contador].reg0 = contador3;
			contador2=0;
			while(1) // Aqui pega o segundo operando
			{
				if(MEM_INST[contador][contador1] == ',')
				{
					TABELA_DE_ERROS(18);
				}
				if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){break;} // Falta parametros na instrucao
				tauxiliar[contador2] = MEM_INST[contador][contador1];
				contador1++;
				contador2++;
			}
			if(strlen(tauxiliar) > 0){}
			else{TABELA_DE_ERROS(6);} // Falta parametros
			contador1++;
			tauxiliar[contador2] = '\0';
			contador3 = atoi(tauxiliar);
			if(contador3 >= 0 && contador3 <= 15){}
			else{TABELA_DE_ERROS(10);} // Constante nao suportada
			i[contador].reg1 = contador3;
		}
		else
		{
			contador3 = atoi(tauxiliar);
			i[contador].reg0 = contador3;
			if(contador3 >= 0 && contador3 <= 15){}
			else{TABELA_DE_ERROS(10);} // Constante nao suportada
		}
	}
	else
	{		
		if(parametros == 1)
		{
			i[contador].reg0 = verifica_registrador();	
			contador2=0;
			while(1)
			{
				if(MEM_INST[contador][contador1] == ',')
				{
					TABELA_DE_ERROS(18);
				}
				if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){break;} // Falta parametros na instrucao
				tauxiliar[contador2] = MEM_INST[contador][contador1];
				contador1++;
				contador2++;
			}
			if(strlen(tauxiliar) > 0){}
			else{TABELA_DE_ERROS(6);} // Falta parametros
			contador1++;
			tauxiliar[contador2] = '\0';
			i[contador].reg1 = verifica_registrador();	
			contador2=0;
		}
		else
		{
			i[contador].reg0 = verifica_registrador();	
			contador2=0;
		}
	}
}
void formato_i(int tipo)
{
	i[contador].formato = 1;
	if(tipo == 0)contador1 = 3;
	else contador1 = 2;
	contador2=0;
	while(MEM_INST[contador][contador1] != ',') // Aqui busca o registrador destino
	{
		if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){TABELA_DE_ERROS(14);} // Falta parametros na instrucao
		tauxiliar[contador2] = MEM_INST[contador][contador1];
		contador1++;
		contador2++;
	}
	tauxiliar[contador2] = '\0';
	contador1++;
	contador2=0; // Aqui trata o registrador destino
	if(tauxiliar[0] == '0' && (strlen(tauxiliar) == 1)){i[contador].reg_dest = 0;}
	else if(tauxiliar[0] == '1' && (strlen(tauxiliar) == 1)){i[contador].reg_dest = 1;}
	else {TABELA_DE_ERROS(13);} // Registrador destino nao suportado
	while(1)
	{
			if(MEM_INST[contador][contador1] == ',')
			{
				TABELA_DE_ERROS(18);
			}
			if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){break;} // Falta parametros na instrucao
			tauxiliar[contador2] = MEM_INST[contador][contador1];
			contador1++;
			contador2++;
	}
	contador1++;
	tauxiliar[contador2] = '\0';
	if(strlen(tauxiliar) > 0){}
	else{TABELA_DE_ERROS(0);}
	contador3 = atoi(tauxiliar);
	if(i[contador].opcode == 16)
	{
		if(contador3 >= -128 && contador3 <= 127)
		{
			i[contador].cont = contador3;
		}
		else{TABELA_DE_ERROS(12);} // Faixa nao representavel
	}
	else if(i[contador].opcode == 17)
	{
		if(contador3 >= -128 && contador3 <= 127)
		{
			i[contador].cont = contador3;
		}
		else{TABELA_DE_ERROS(12);} // Faixa nao representavel
	}
}
void formato_ls(int tipo)
{
	contador1=0;
	i[contador].formato = 2;
	if(tipo == 1)contador1 = 2;
	else contador1 = 3;
	contador2=0;
	while(MEM_INST[contador][contador1] != ',') // Aqui busca o primeiro operando
	{
		if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){TABELA_DE_ERROS(15);} // Falta parametros na instrucao
		tauxiliar[contador2] = MEM_INST[contador][contador1];
		contador1++;
		contador2++;
	}
	contador1++;
	tauxiliar[contador2] = '\0'; // Aqui trata o modo de enderecamento
	if(strlen(tauxiliar) > 0){}
	else{TABELA_DE_ERROS(0);}
	i[contador].reg0 = verifica_registrador();
	contador2=0;
	tauxiliar[contador2] = '\0';
	while(1)
	{
		if(MEM_INST[contador][contador1] == ',')
		{
			TABELA_DE_ERROS(18);
		}
		if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){break;} // Falta parametros na instrucao
		tauxiliar[contador2] = MEM_INST[contador][contador1];
		contador1++;
		contador2++;
	}	
	if(strlen(tauxiliar) > 0){}
	else{TABELA_DE_ERROS(0);}
	contador1++;
	tauxiliar[contador2] = '\0';		
	i[contador].reg1 = verifica_registrador();	
}
void formato_branch(int tipo) // Ok
{
	contador1=0;
	i[contador].formato = 3;
	if(tipo == 0)contador1 = 3;
	else contador1 = 2;
	contador2=0;
	while(1)
	{
			if(MEM_INST[contador][contador1] == ',')
			{
				TABELA_DE_ERROS(18);
			}
			if(MEM_INST[contador][contador1] == 13 || MEM_INST[contador][contador1] == 0){break;} // Falta parametros na instrucao
			tauxiliar[contador2] = MEM_INST[contador][contador1];
			contador1++;
			contador2++;
	}
	contador1++;
	tauxiliar[contador2] = '\0';
	contador3 = atoi(tauxiliar);
	if(strlen(tauxiliar) > 0){}
	else{TABELA_DE_ERROS(0);}
	if(contador3 >= -1024 && contador3 <= 1023)
	{
		i[contador].desl = contador3;
	}
	else
	{
		TABELA_DE_ERROS(17); // Tamanho do desvio nao suportado
	}
}
void ANALISE_LEXICA_SINTATICA_INSTRUCAO()
{
	for(contador=0;contador<mem_inst;contador++)
	{
		tamanho = strlen(MEM_INST[contador]);
		if(MEM_INST[contador][0] == 'o' && MEM_INST[contador][1] == 'r')
		{
			formato_r(1,1);
			i[contador].opcode = 12;
		}
		else if(MEM_INST[contador][0] == 'n' && MEM_INST[contador][1] == 'o' && MEM_INST[contador][2] == 'p' && (strlen(MEM_INST[contador]) == 3))
		{
			i[contador].opcode = 0;
		}
		else if(MEM_INST[contador][0] == 'a' && MEM_INST[contador][1] == 'd' && MEM_INST[contador][2] == 'd')
		{
			i[contador].opcode = 1;
			formato_r(0,1);
		}
		else if(MEM_INST[contador][0] == 's' && MEM_INST[contador][1] == 'u' && MEM_INST[contador][2] == 'b')
		{
			i[contador].opcode = 2;
			formato_r(0,1);
		}
		else if(MEM_INST[contador][0] == 'i' && MEM_INST[contador][1] == 'n' && MEM_INST[contador][2] == 'c')
		{
			i[contador].opcode = 3;
			formato_r(0,0);
		}
		else if(MEM_INST[contador][0] == 'd' && MEM_INST[contador][1] == 'e' && MEM_INST[contador][2] == 'c')
		{
			i[contador].opcode = 4;
			formato_r(0,0);
		}
		else if(MEM_INST[contador][0] == 'm' && MEM_INST[contador][1] == 'u' && MEM_INST[contador][2] == 'l')
		{
			i[contador].opcode = 5;
			formato_r(0,1);
		}
		else if(MEM_INST[contador][0] == 'd' && MEM_INST[contador][1] == 'i' && MEM_INST[contador][2] == 'v')
		{
			i[contador].opcode = 6;
			formato_r(0,1);
		}
		else if(MEM_INST[contador][0] == 'm' && MEM_INST[contador][1] == 'o' && MEM_INST[contador][2] == 'd')
		{
			i[contador].opcode = 7;
			formato_r(0,1);
		}
		else if(MEM_INST[contador][0] == 's' && MEM_INST[contador][1] == 'h' && MEM_INST[contador][2] == 'r')
		{
			i[contador].opcode = 8;
			formato_r(0,0);
		}
		else if(MEM_INST[contador][0] == 's' && MEM_INST[contador][1] == 'h' && MEM_INST[contador][2] == 'l')
		{
			i[contador].opcode = 9;
			formato_r(0,0);
		}
		else if(MEM_INST[contador][0] == 'r' && MEM_INST[contador][1] == 'o' && MEM_INST[contador][2] == 'r')
		{
			i[contador].opcode = 10;
			formato_r(0,0);
		}
		else if(MEM_INST[contador][0] == 'r' && MEM_INST[contador][1] == 'o' && MEM_INST[contador][2] == 'l')
		{
			i[contador].opcode = 11;
			formato_r(0,0);
		}
		else if(MEM_INST[contador][0] == 'a' && MEM_INST[contador][1] == 'n' && MEM_INST[contador][2] == 'd')
		{
			i[contador].opcode = 13;
			formato_r(0,1);
		}
		else if(MEM_INST[contador][0] == 'x' && MEM_INST[contador][1] == 'o' && MEM_INST[contador][2] == 'r')
		{
			i[contador].opcode = 14;
			formato_r(0,1);
		}
		else if(MEM_INST[contador][0] == 'n' && MEM_INST[contador][1] == 'o' && MEM_INST[contador][2] == 't')
		{
			i[contador].opcode = 15;
			formato_r(0,0);
		}
		
		else if(MEM_INST[contador][0] == 'l' && MEM_INST[contador][1] == 'i')
		{
			i[contador].opcode = 16;
			formato_i(1);
		}
		else if(MEM_INST[contador][0] == 'l' && MEM_INST[contador][1] == 'u' && MEM_INST[contador][2] == 'i')
		{
			i[contador].opcode = 17;
			formato_i(0);
		}
		else if(MEM_INST[contador][0] == 'l' && MEM_INST[contador][1] == 'w')
		{
			i[contador].opcode = 18;
			formato_ls(1);
		}
		else if(MEM_INST[contador][0] == 's' && MEM_INST[contador][1] == 'w')
		{
			i[contador].opcode = 19;
			formato_ls(1);
		}
		else if(MEM_INST[contador][0] == 'l' && MEM_INST[contador][1] == 'b')
		{
			i[contador].opcode = 20;
			formato_ls(1);
		}
		else if(MEM_INST[contador][0] == 's' && MEM_INST[contador][1] == 'b')
		{
			i[contador].opcode = 21;
			formato_ls(1);
		}
		else if(MEM_INST[contador][0] == 'm' && MEM_INST[contador][1] == 'o' && MEM_INST[contador][2] == 'v')
		{
			i[contador].opcode = 22;
			formato_ls(0);
		}
		
		else if(MEM_INST[contador][0] == 'j' && MEM_INST[contador][1] == 'v')
		{
			i[contador].opcode = 23;
			formato_branch(1);
		}
		else if(MEM_INST[contador][0] == 'j' && MEM_INST[contador][1] == 'n' && MEM_INST[contador][2] == 'v')
		{
			i[contador].opcode = 24;
			formato_branch(0);
		}
		else if(MEM_INST[contador][0] == 'j' && MEM_INST[contador][1] == 'z')
		{
			i[contador].opcode = 25;
			formato_branch(1);
		}
		else if(MEM_INST[contador][0] == 'j' && MEM_INST[contador][1] == 'n' && MEM_INST[contador][2] == 'z')
		{
			i[contador].opcode = 26;
			formato_branch(0);
		}
		else if(MEM_INST[contador][0] == 'j' && MEM_INST[contador][1] == 'c')
		{
			i[contador].opcode = 27;
			formato_branch(1);
		}
		else if(MEM_INST[contador][0] == 'j' && MEM_INST[contador][1] == 'n' && MEM_INST[contador][2] == 'c')
		{
			i[contador].opcode = 28;
			formato_branch(0);
		}
		else if(MEM_INST[contador][0] == 'j' && MEM_INST[contador][1] == 'm' && MEM_INST[contador][2] == 'p')
		{
			i[contador].opcode = 29;
			formato_branch(0);
		}
		else if(MEM_INST[contador][0] == 'h' && MEM_INST[contador][1] == 'a' && MEM_INST[contador][2] == 'l' && MEM_INST[contador][3] == 't' && (strlen(MEM_INST[contador]) == 4))
		{
			i[contador].opcode = 30;
		}
		else{TABELA_DE_ERROS(5);} // Opcode nao encontrado
	}	
}
void ANALISE_LEXICA_SINTATICA_DADOS()
{
	tmp = 0;
	for(contador=0;contador<mem_data;contador++)
	{
		if(MEM_DATA[contador][0] == '.' && MEM_DATA[contador][1] == 'b' && 
		MEM_DATA[contador][2] == 'y' && MEM_DATA[contador][3] == 't' 
		&& MEM_DATA[contador][4] == 'e')
		{
			contador1 = 5;
			contador2=0;
			while(1)
			{
				if(MEM_DATA[contador][contador1] == ',')
				{
					TABELA_DE_ERROS(18);
				}
				if(MEM_DATA[contador][contador1] == 13 || MEM_DATA[contador][contador1] == 0){break;} // Falta parametros na instrucao
				tauxiliar[contador2] = MEM_DATA[contador][contador1];
				contador1++;
				contador2++;
			}
			if(strlen(tauxiliar) == 0)
			{
				TABELA_DE_ERROS(0);
			}
			contador1++;
			tauxiliar[contador2] = '\0';
			contador3 = atoi(tauxiliar);
			if(contador3 >= -128 && contador3 <= 127)
			{
				contador3 = contador3 << 24;
				contador3 = contador3 >> 24;
				m[contador].valor_byte = (char)contador3;
				m[contador].tipo = 0;
				tmp = tmp + 1;
			}
			else{TABELA_DE_ERROS(8);}
		}
		else if(MEM_DATA[contador][0] == '.' && MEM_DATA[contador][1] == 'w' && 
		MEM_DATA[contador][2] == 'o' && MEM_DATA[contador][3] == 'r' 
		&& MEM_DATA[contador][4] == 'd')
		{
				contador2=0;
			contador1 = 5;
			while(1)
			{
				if(MEM_DATA[contador][contador1] == ',')
				{
					TABELA_DE_ERROS(18);
				}
				if(MEM_DATA[contador][contador1] == 13 || MEM_DATA[contador][contador1] == 0){break;} // Falta parametros na instrucao
				tauxiliar[contador2] = MEM_DATA[contador][contador1];
				contador1++;
				contador2++;
			}
			contador1++;
			if(strlen(tauxiliar) == 0)
			{
				TABELA_DE_ERROS(0);
			}
			tauxiliar[contador2] = '\0';
			contador3 = atoi(tauxiliar);
			if(contador3 <= 32767 && contador3 >= -32768)
			{
				contador3 = contador3 << 16;
				contador3 = contador3 >> 16;
				m[contador].valor_word = (unsigned short int)contador3;
				m[contador].tipo = 1;
				tmp = tmp + 2;			
			}
			else{TABELA_DE_ERROS(8);}
		}
		else{TABELA_DE_ERROS(19);}
	}
}
void ESCREVE_AQUIVO_SAIDA() // Bloco de escrita Ok
{
	fwrite(&mem_inst,sizeof(unsigned short int),1,out);
	fwrite(&tmp,sizeof(unsigned short int),1,out);
	for(contador=0;contador<mem_inst;contador++)
	{
		if(i[contador].formato == 0)
		{
			if(i[contador].opcode == 0)
			{
				instrucao = 0;
				instrucao = instrucao | i[contador].opcode;
				fwrite(&instrucao,sizeof(unsigned short int),1,out);
			}
			else
			{
				instrucao = 0;
				instrucao = instrucao | i[contador].opcode;
				instrucao = instrucao << 2;
				instrucao = instrucao | i[contador].modo_end;
				instrucao = instrucao << 1;
				instrucao = instrucao | i[contador].reg_dest;
				instrucao = instrucao << 4;
				instrucao = instrucao | i[contador].reg0;
				instrucao = instrucao << 4;
				instrucao = instrucao | i[contador].reg1;				
				fwrite(&instrucao,sizeof(unsigned short int),1,out);
			}
		}
		else if(i[contador].formato == 1) // Formato I
		{
			instrucao = 0;
			instrucao = i[contador].opcode;
			instrucao = instrucao << 2; 
			instrucao = instrucao | 0;
			instrucao = instrucao << 1;
			instrucao = instrucao | i[contador].reg_dest;
			instrucao = instrucao << 8;
			i[contador].cont = i[contador].cont << 8;
			i[contador].cont = i[contador].cont >> 8;
			instrucao = instrucao | i[contador].cont;
			fwrite(&instrucao,sizeof(unsigned short int),1,out);
		}
		else if(i[contador].formato == 2) // Formato L/S
		{
			instrucao = 0;
			instrucao = i[contador].opcode;
			instrucao = instrucao << 7;
			instrucao = instrucao | i[contador].reg0;
			instrucao = instrucao << 4;
			instrucao = instrucao | i[contador].reg1;
			fwrite(&instrucao,sizeof(unsigned short int),1,out);
		}
		else if(i[contador].formato == 3)
		{
			instrucao = 0;
			instrucao = i[contador].opcode;
			instrucao = instrucao << 11;
			i[contador].desl = i[contador].desl << 5;
			i[contador].desl = i[contador].desl >> 5;
			instrucao = instrucao | i[contador].desl;
			fwrite(&instrucao,sizeof(unsigned short int),1,out);
		}
	}
	for(contador=0;contador<mem_data;contador++)
	{
		if(m[contador].tipo == 0)
		{
			fwrite(&m[contador].valor_byte,sizeof(unsigned char),1,out);
		}
		else if(m[contador].tipo == 1)
		{
			c = m[contador].valor_word >> 8;
			fwrite(&c,sizeof(unsigned char),1,out);
			m[contador].valor_word = m[contador].valor_word << 8;
			c = m[contador].valor_word >> 8;
			fwrite(&c,sizeof(unsigned char),1,out);
		}
	}
}	
int main(int argc,char *argv[])
{
	ARQUIVO_ENTRADA(argc,argv[1]); // Ok
	LE_ARQUIVO_ENTRADA(); // Ok
	CARREGA_MEMORIA_DE_INSTRUCAO(); // Ok
	CARREGA_MEMORIA_DE_DADOS(); // Ok
	ANALISE_LEXICA_SINTATICA_INSTRUCAO(); // Ok
	ANALISE_LEXICA_SINTATICA_DADOS(); // Ok
	ARQUIVO_SAIDA(argv[1]); // Ok
	ESCREVE_AQUIVO_SAIDA(); // Ok
	return(0);
}
