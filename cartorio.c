#include <stdio.h> // biblioteca de comunica��o de usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string



int registro() // fun��es dentro a int main - fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // texto ao usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo // w = write
	fprintf(file, cpf); // salvar valor da vari�vel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); // a = atualizar informa��o
	fprintf(file, ","); // , = separar informa��o
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose (file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200]; // vari�vel para ver o conte�do
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // armazenar o cpf informado
	
	FILE *file;
	file = fopen (cpf, "r"); // "r" - read, ler arquivo
	
	if(file == NULL) // caso n�o encontre. NULL=nulo
	{
		printf("Arquivo n�o localizado\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL); // "enquanto procura dentre os 200 caracteres no arquivo se diferente de nulo" 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); // deleta o cpf informado
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O CPF informado n�o foi encontrado!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // vari�vel
	int laco=1;
	
	for(laco=1;laco=1;) // for: repeti��o /vari�vel laco: laco de repeti��o 
	{
	
		system("cls"); // limpar tela
	
		setlocale(LC_ALL, "Portuguese"); // localiza��o - acesso � acentos
	
		printf("### Cart�rio da EBAC ###\n\n"); 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t 1 - Registrar nomes:\n"); // "\t" tab; espa�o
		printf("\t 2 - Consultar nomes:\n");
		printf("\t 3 - Deletar nomes:\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); // esquanear o que o usu�rio coloca; armazenar na vari�vel "opcao"
	
		system("cls"); // limpar a tela
	
		
		switch(opcao) // escolha da vari�vel a ser lida
		{
			case 1: // abertura da op��o
			registro(); // chamando a fun��o
			break; // fechamento da op��o
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default: // "falhas", op��es n�o listadas
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;	
		}
	}
}
