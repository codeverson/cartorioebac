#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca de Strings

int registro () //fun��o respons�vel por cadastrar os usu�rios no sistema
{ 
	//in�cio da cria��o de vari�veis/strings (conjunto de vari�veis)
	char arquivo [40];
	char cpf[40];        //colchetes � para criar uma String, se n�o copiar� somente o 1 caractere
	char nome[40];      
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings (conjunto de vari�veis)
	
	//cpf (criando novo arquivo)
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);            //Salvando na String CPF, que criamos logo acima. %s
	
	strcpy(arquivo, cpf); //copiando a String do CPF para Arquivo
	
	FILE *file;                     //acesse a fun��o FILE e crie um file (arquivo)
	file = fopen(arquivo, "w");    //Criar um arquivo, com o nome da vari�vel, write
	fprintf(file, cpf);           //salva no arquivo a vari�vel CPF
	fclose(file);                //fechando o arquivo
	
	//nome (atualizando)
	
	file = fopen(arquivo, "a");   //a atualizar informa��es
	fprintf(file, ",");          //colocando uma v�rgula
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);        //Salvando na String nome, que criamos logo acima.
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	//sobrenome (atualizando)
	
	file = fopen(arquivo, "a");  
	fprintf(file, ",");          
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");     //Abre o arquivo 
	fprintf(file, sobrenome);      //e atualiza ele com a String sobrenome.
	fclose(file);
	
	//cargo
	
	file = fopen(arquivo, "a");  
	fprintf(file, ",");          
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
		
	system ("pause");
	}
int consulta()
{ 
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	FILE *file;
	file = fopen(cpf, "r"); //r = read
	
	if(file == NULL)
	{ 
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	else 
	{ 	while(fgets(conteudo, 200, file) !=NULL); //enquanto (fgets) vai buscar no arquivo o conte�do,(rodar�) maximo 200 , restri��o ao file.
		{ 
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		}	 
	}
	fclose(file);
	system("pause");
}
int deletar()
{ 
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
		
	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)    //se 
	{
		printf("Usu�rio n�o encontrado.\n");
		system("pause");
		fclose(file);
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio exclu�do com sucesso! \n");
		system("pause");
	}
						
}
	
int main ()
{
int opcao=0; //definindo a vari�vel inteira op��o
int laco=1;
	
		for(laco=1;laco=1;) //sempre que a variavel for 1, o programa retornar�
		{ 
		
		system("cls"); 
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

		printf("### Cart�rio da EBAC ###\n\n");//inicio do menu // pulando duas linhas \n\n
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n"); //\t gera espa�amento
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //fim do menu 
			
		scanf("%d", &opcao); //scanf escaneia o que o usu�rio digita, %d o coloca na vari�vel opcao.
		
		system("cls");   //limpar a tela
		
		switch (opcao) //inicio da sele��o do menu
		{ 
		case 1: 
		registro();    //chamada de fun��o
		break;        //fim da op�ao
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default: 
		printf("Essa op��o n�o est� dispon�vel.\n");
		system ("pause");
		break;
		} //fim da sele��o
		
	} 
}

