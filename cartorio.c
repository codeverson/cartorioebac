#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca de Strings

int registro () //função responsável por cadastrar os usuários no sistema
{ 
	//início da criação de variáveis/strings (conjunto de variáveis)
	char arquivo [40];
	char cpf[40];        //colchetes é para criar uma String, se não copiará somente o 1 caractere
	char nome[40];      
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings (conjunto de variáveis)
	
	//cpf (criando novo arquivo)
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);            //Salvando na String CPF, que criamos logo acima. %s
	
	strcpy(arquivo, cpf); //copiando a String do CPF para Arquivo
	
	FILE *file;                     //acesse a função FILE e crie um file (arquivo)
	file = fopen(arquivo, "w");    //Criar um arquivo, com o nome da variável, write
	fprintf(file, cpf);           //salva no arquivo a variável CPF
	fclose(file);                //fechando o arquivo
	
	//nome (atualizando)
	
	file = fopen(arquivo, "a");   //a atualizar informações
	fprintf(file, ",");          //colocando uma vírgula
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
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	else 
	{ 	while(fgets(conteudo, 200, file) !=NULL); //enquanto (fgets) vai buscar no arquivo o conteúdo,(rodará) maximo 200 , restrição ao file.
		{ 
		printf("\nEssas são as informações do usuário: ");
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
		printf("Usuário não encontrado.\n");
		system("pause");
		fclose(file);
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário excluído com sucesso! \n");
		system("pause");
	}
						
}
	
int main ()
{
int opcao=0; //definindo a variável inteira opção
int laco=1;
	
		for(laco=1;laco=1;) //sempre que a variavel for 1, o programa retornará
		{ 
		
		system("cls"); 
			
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

		printf("### Cartório da EBAC ###\n\n");//inicio do menu // pulando duas linhas \n\n
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n"); //\t gera espaçamento
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu 
			
		scanf("%d", &opcao); //scanf escaneia o que o usuário digita, %d o coloca na variável opcao.
		
		system("cls");   //limpar a tela
		
		switch (opcao) //inicio da seleção do menu
		{ 
		case 1: 
		registro();    //chamada de função
		break;        //fim da opçao
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default: 
		printf("Essa opção não está disponível.\n");
		system ("pause");
		break;
		} //fim da seleção
		
	} 
}

