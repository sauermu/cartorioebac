#include <stdio.h> // biblioteca de comunicação de usuário
#include <stdlib.h> // biblioteca de alocação de espaço
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string



int registro() // funções dentro a int main - função responsável por cadastrar os usuários no sistema
{
	// início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // texto ao usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo // w = write
	fprintf(file, cpf); // salvar valor da variável
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); // a = atualizar informação
	fprintf(file, ","); // , = separar informação
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
	char conteudo[200]; // variável para ver o conteúdo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // armazenar o cpf informado
	
	FILE *file;
	file = fopen (cpf, "r"); // "r" - read, ler arquivo
	
	if(file == NULL) // caso não encontre. NULL=nulo
	{
		printf("Arquivo não localizado\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL); // "enquanto procura dentre os 200 caracteres no arquivo se diferente de nulo" 
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("O CPF informado não foi encontrado!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // variável
	int laco=1;
	
	for(laco=1;laco=1;) // for: repetição /variável laco: laco de repetição 
	{
	
		system("cls"); // limpar tela
	
		setlocale(LC_ALL, "Portuguese"); // localização - acesso à acentos
	
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t 1 - Registrar nomes:\n"); // "\t" tab; espaço
		printf("\t 2 - Consultar nomes:\n");
		printf("\t 3 - Deletar nomes:\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); // esquanear o que o usuário coloca; armazenar na variável "opcao"
	
		system("cls"); // limpar a tela
	
		
		switch(opcao) // escolha da variável a ser lida
		{
			case 1: // abertura da opção
			registro(); // chamando a função
			break; // fechamento da opção
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default: // "falhas", opções não listadas
			printf("Essa opção não está disponível!\n\n");
			system("pause");
			break;	
		}
	}
}
