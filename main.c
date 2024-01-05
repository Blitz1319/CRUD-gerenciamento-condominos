//GRUPO: ANTONIO GABRIEL, MOISES DE FARIAS e GUILHERME SOLIZ ;

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define MAX 50

int n, i, j=0, a=0, soma=0, cont;

FILE* arquivo;

//declarando as estruturas para cadastrar o usu�rio;

struct cadastrar{
	char nome[50];
	char cpf[11];
	int apto;
	float debito;
}morador[MAX];

//criando os prot�tipos das fun��es do menu;

int menu();
void Inserir_um_novo_condominio();
void Consultar_condominio_pelo_cpf();
void Atualizar_o_debito_do_condominio_pelo_cpf();
void Exibir_os_condominios_devedores();
void Exibir_os_condominios_quites();
void Remover_os_condominios();
void listar_condominios();
void abrir_arquivo();
void ler_arquivo();

int main(int argc, char *argv[]) {
		
	ler_arquivo();
	
	setlocale(LC_ALL,"portuguese");
	
	/////////////////// MENU PRINCIPAL ///////////////////////
	
	menu(); // chamada da fun��o MENU;
	
	return 0;
}

int menu(void){
	
	//criando as op��es do menu;
	
	a = 1;
	
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tBEM VINDO AO SISTEMA DE CADASTRO NEEDCOND\n\n\n\n\n\n\n");
	system("pause");
	system("cls");
	
	//criando um menu de intera��oo com loop;
	
	do{
		system("color 9F ");
		system("cls");
		printf("\n----------------------------1: Inserir um novo morador no condom�nio (CPF, Nome, Apartamento e D�bito);----------------");
		printf("\n----------------------------2: Consultar morador pelo CPF;-------------------------------------------------------------");
		printf("\n----------------------------3: Atualizar o d�bito do morador pelo cpf (Devedor ou Pagador);----------------------------");
		printf("\n----------------------------4: Exibir os moradores devedores;----------------------------------------------------------");
		printf("\n----------------------------5: Exibir os moradores quites;-------------------------------------------------------------");
		printf("\n----------------------------6: Remover morador do condom�nio pelo CPF;-------------------------------------------------");
		printf("\n----------------------------7: Listar todos os moradores do condom�nio;------------------------------------------------");
		printf("\n----------------------------0: Sair do programa;-----------------------------------------------------------------------");
		printf("\n\nDigite sua op��o: ");
		scanf("%d",&a);
		system("cls");
		
	getchar();
		
	switch(a){

		//chamada das fun��es do menu de intera��o;

					case 1:
						Inserir_um_novo_condominio(); 
						break;
					case 2:
						Consultar_condominio_pelo_cpf();
						break;
					case 3:
						Atualizar_o_debito_do_condominio_pelo_cpf(); 
						break;
					case 4:
						Exibir_os_condominios_devedores(); 
						break;
					case 5:
						Exibir_os_condominios_quites();
						break;
					case 6:
						Remover_os_condominios();
						break;
					case 7:
						listar_condominios();
						break;
					case 0:
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tOBRIGADO POR USAR O NEEDCOND :)\n\n\n\n\n\n\n");
						abrir_arquivo();//Fun��o pora abrir o arquivo e armazenar os cadastros dentro do arquivo;
						exit(0);
							}
		getchar();
	}while(a!=0);
	
	system("pause");
	
}

void Inserir_um_novo_condominio(){
	
	//////////////////// CADASTRAR NOVO MORADOR ///////////////////////////
	
	int n, i;
	
	system("cls");
	
	printf("\n");
	
	//Definir quantas vezes o "for" vai cadastrar um morador;
	printf("N� de moradores cadastrados: \n\t%c%d", 26, cont);
	printf("\n\nDigite o n�mero de moradores que deseja cadastrar: ");
	scanf("%d", &n);
	
	soma = n + cont;
	
	for(i = cont; i < soma; i++){
		
		system("cls");
		
		//Dados do morador;
		
		printf("~~~~~~~~~~~~~~~~PREENCHA SEUS DADOS~~~~~~~~~~~~~~~~~~");
		printf("\n\n");
		
		fflush(stdin); //Limpar o buffer do teclado;
		printf("Digite o nome do morador: \n\t%c",26);
		gets(morador[i].nome);//Gravando dentro do array da estrutura;
		fflush(stdin);
		
		printf("\n\n");
		
		printf("Digite o CPF do morador: \n\t%c",26);
		gets(morador[i].cpf);
		fflush(stdin);
		
		printf("\n\n");
		
		printf("Digite o N� do apartamento: \n\t%c",26);
		scanf("%d", &morador[i].apto);
		fflush(stdin);
		
		printf("\n\n");
		
		printf("Digite o valor do seu d�bito: \n\t%c",26);
		scanf("%f", &morador[i].debito);
		fflush(stdin);
		
		printf("\n\nMORADOR CADASTRADO COM SUCESSO !!!!!\n\n");
		
		system("pause");
		
		j++;
		
		a++;

		cont++;
	
	}
	
}
void Consultar_condominio_pelo_cpf(){
	
	system("cls");
	
	int i, f = 1;
	char cmp_cpf[11];
	
	printf("\tCONSULTAR MORADOR PELO CPF\n\n");
		
		//cmp_cpf -> comparador de cpf atrav�s do strcmp;
	
		printf("~~~~~~~~~~~~~~~~\n");
		printf("Digite seu cpf: ");
		scanf("%s", &cmp_cpf);
	
	for(i = 0; i <= cont; i++){
		
		if(strcmp(cmp_cpf,morador[i].cpf) == 0){ //Atrav�s da condi��o "if" o cpf do comparador vai ser comparado com o cpf j� cadastrado na estrutura(" == 0 " -> verdadeiro);
			
			printf("~~~~~~~~~~~~~~~~\n");
			printf("N� do cadastro: %d\n", i);
			printf("Nome: %s\n", morador[i].nome);
			printf("CPF: %s\n", morador[i].cpf);
			printf("N� apartamento: %d\n", morador[i].apto);
			printf("Valor do d�bito: R$%0.2f\n", morador[i].debito);
			
			f = 0; //Uma pequena declara��o para que o segundo "if" dentro dessa fun��o n�o seja ativado caso este "if" seja verdadeiro;
			
		}
		
	}
	if(f == 1){
			
			printf("\nMORADOR N�O ENCONTRADO !!!!");
			
		}
		
		printf("\n\n");
		
		system("pause");

}
void Atualizar_o_debito_do_condominio_pelo_cpf(){
	
	system("cls");
	
	int i, f = 1, novo_debito;
	char cmp_cpf[11];
	
	printf("\tATUALIZAR D�BITO DO MORADOR PELO CPF\n\n");
	
	//cmp_cpf -> comparador de cpf atrav�s do strcmp;
	
	printf("~~~~~~~~~~~~~~~~\n");
	printf("Digite seu cpf: ");
	scanf("%s", &cmp_cpf);

		for(i = 0; i <= cont; i++){
		
			if(strcmp(cmp_cpf,morador[i].cpf) == 0){ //Atrav�s da condi��o "if" o cpf do comparador vai ser comparado com o cpf j� cadastrado na estrutura(" == 0 " -> verdadeiro);
				
				printf("~~~~~~~~~~~~~~~~\n");
				printf("N� do cadastro: %d\n", i);
				printf("Nome: %s\n", morador[i].nome);
				printf("CPF: %s\n", morador[i].cpf);
				printf("N� apartamento: %d\n", morador[i].apto);
				printf("Valor do d�bito: R$%0.2f\n", morador[i].debito);
				
				f = 0; //Uma pequena declara��o para que o segundo "if" dentro dessa fun��o n�o seja ativado caso este "if" seja verdadeiro;
				
				printf("\n\nDigite o valor do novo d�bito: ");
				scanf("%d", &novo_debito); //Vari�vel que vai armazenar o novo d�bito digitado;
			
				morador[i].debito = novo_debito; //Igualdade para a troca de valor do antigo d�bito pelo novo dentro do array da estrutura;
					
					system("cls");
					
					printf("D�bito alterado com sucesso!\n\n");
					
					system("pause");
				
						
			}
			if(f == 1){
				
				printf("\n\nMORADOR N�O ENCONTRADO!!!!!!!\n\n");
				
				system("pause");
				
			}	
		}	

}
void Exibir_os_condominios_devedores(){
		
	system("cls");
		
		int i;
		
		printf("\tLISTA DE MORADORES DEVEDORES\n\n");
		
		for(i = 0; i <= cont; i++){ 
			
			if(morador[i].debito > 0){ //Condi��o para listar os moradores em que o valor armazenado na vari�vel debito dentro do array da estrutura for > 0;
			
				printf("~~~~~~~~~~~~~~~~\n");
				printf("N� do cadastro: %d\n", i);
				printf("Nome: %s\n", morador[i].nome);
				printf("CPF: %s\n", morador[i].cpf);
				printf("N� apartamento: %d\n", morador[i].apto);
				printf("Valor do d�bito: R$%0.2f\n\n", morador[i].debito);
		}

		}

}
void Exibir_os_condominios_quites(){
	
	system("cls");
		
		int i;
		
		printf("\tLISTA DE MORADORES QUITES\n\n");
		
		for(i = 0; i <= cont; i++){
			
			if(morador[i].debito == 0){ //Condi��o para listar os moradores em que o valor armazenado na vari�vel debito dentro do array da estrutura for == 0;
			
				printf("~~~~~~~~~~~~~~~~\n");
				printf("N� do cadastro: %d\n", i);
				printf("Nome: %s\n", morador[i].nome);
				printf("CPF: %s\n", morador[i].cpf);
				printf("N� apartamento: %d\n", morador[i].apto);
				printf("Valor do debito: R$%0.2f\n\n", morador[i].debito);
		}

		}

}
void Remover_os_condominios(){
	
	system("cls");
	
	int f, b = 1;

		printf("Digite o N� do morador que deseja excluir: ");
		scanf("%d", &f); //Procurador de posi��o do array;
		
		if(f<cont){
				
			while(f<cont){
				
				strcpy(morador[f].nome,morador[f+1].nome);
			 	strcpy(morador[f].cpf,morador[f+1].cpf);
				morador[f].apto = morador[f+1].apto;
				morador[f].debito = morador[f+1].debito;

				printf("\n\nMORADOR EXCLUIDO COM SUCESSO !!!!!!!\n\n");

				system("pause");
	
				f++;
			}
		b = 0;

		cont--; //Quando remover o cadastro "num" ficar� com - 1;
		
		}
		if(b == 1){
		
		printf("\n\nMORADOR N�O ENCONTRADO !!!!!\n\n");
		
		system("pause");
	}
}

void listar_condominios(){
	
	system("cls");
	
	
	int i = 0;
	
	printf("\tLISTA DE MORADORES DO CONDOM�NIO\n\n");

	for(i = 0; i <= cont; i++){ //Condi��o para listar todos os moradores dentro do array da estrutura;
	
			printf("~~~~~~~~~~~~~~~~\n\n");
			printf("N� do cadastro: %d\n", i);
			printf("Nome: %s\n", morador[i].nome);
			printf("CPF: %s\n", morador[i].cpf);
			printf("N� apartamento: %d\n", morador[i].apto);
			printf("Valor do debito: R$%0.2f\n\n", morador[i].debito);	
		
	}
}

void abrir_arquivo(){
	
	arquivo = fopen("moradores.txt", "w+"); //Vai abrir o arquivo na forma de escrita;
	
	if (arquivo == NULL){
		
		printf("Erro na abertura de arquivo!!");
		system("pause");

	}
	
	fwrite(morador, sizeof(struct cadastrar), cont, arquivo); //Vai escrever todo o tamanho da estrutura;
	fclose(arquivo);
}

void ler_arquivo(){
	
	arquivo = fopen("moradores.txt","r"); //Vai abrir o arquivo na forma de leitura;
	
	cont = fread(morador, sizeof(struct cadastrar), MAX, arquivo); //Vai adcionar a vari�vel de quantidade de cadastro("num") o conteudo do arquivo;
	fclose(arquivo);
}
