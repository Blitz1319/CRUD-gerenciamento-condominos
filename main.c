//GRUPO: ANTONIO GABRIEL, MOISES DE FARIAS e GUILHERME SOLIZ ;

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define MAX 50

int n, i, j=0, a=0, soma=0, cont;

FILE* arquivo;

//declarando as estruturas para cadastrar o usuário;

struct cadastrar{
	char nome[50];
	char cpf[11];
	int apto;
	float debito;
}morador[MAX];

//criando os protótipos das funções do menu;

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
	
	menu(); // chamada da função MENU;
	
	return 0;
}

int menu(void){
	
	//criando as opções do menu;
	
	a = 1;
	
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tBEM VINDO AO SISTEMA DE CADASTRO NEEDCOND\n\n\n\n\n\n\n");
	system("pause");
	system("cls");
	
	//criando um menu de interaçãoo com loop;
	
	do{
		system("color 9F ");
		system("cls");
		printf("\n----------------------------1: Inserir um novo morador no condomínio (CPF, Nome, Apartamento e Débito);----------------");
		printf("\n----------------------------2: Consultar morador pelo CPF;-------------------------------------------------------------");
		printf("\n----------------------------3: Atualizar o débito do morador pelo cpf (Devedor ou Pagador);----------------------------");
		printf("\n----------------------------4: Exibir os moradores devedores;----------------------------------------------------------");
		printf("\n----------------------------5: Exibir os moradores quites;-------------------------------------------------------------");
		printf("\n----------------------------6: Remover morador do condomínio pelo CPF;-------------------------------------------------");
		printf("\n----------------------------7: Listar todos os moradores do condomínio;------------------------------------------------");
		printf("\n----------------------------0: Sair do programa;-----------------------------------------------------------------------");
		printf("\n\nDigite sua opção: ");
		scanf("%d",&a);
		system("cls");
		
	getchar();
		
	switch(a){

		//chamada das funções do menu de interação;

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
						abrir_arquivo();//Função pora abrir o arquivo e armazenar os cadastros dentro do arquivo;
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
	printf("Nº de moradores cadastrados: \n\t%c%d", 26, cont);
	printf("\n\nDigite o número de moradores que deseja cadastrar: ");
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
		
		printf("Digite o N° do apartamento: \n\t%c",26);
		scanf("%d", &morador[i].apto);
		fflush(stdin);
		
		printf("\n\n");
		
		printf("Digite o valor do seu débito: \n\t%c",26);
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
		
		//cmp_cpf -> comparador de cpf através do strcmp;
	
		printf("~~~~~~~~~~~~~~~~\n");
		printf("Digite seu cpf: ");
		scanf("%s", &cmp_cpf);
	
	for(i = 0; i <= cont; i++){
		
		if(strcmp(cmp_cpf,morador[i].cpf) == 0){ //Através da condição "if" o cpf do comparador vai ser comparado com o cpf já cadastrado na estrutura(" == 0 " -> verdadeiro);
			
			printf("~~~~~~~~~~~~~~~~\n");
			printf("Nº do cadastro: %d\n", i);
			printf("Nome: %s\n", morador[i].nome);
			printf("CPF: %s\n", morador[i].cpf);
			printf("Nº apartamento: %d\n", morador[i].apto);
			printf("Valor do débito: R$%0.2f\n", morador[i].debito);
			
			f = 0; //Uma pequena declaração para que o segundo "if" dentro dessa função não seja ativado caso este "if" seja verdadeiro;
			
		}
		
	}
	if(f == 1){
			
			printf("\nMORADOR NÃO ENCONTRADO !!!!");
			
		}
		
		printf("\n\n");
		
		system("pause");

}
void Atualizar_o_debito_do_condominio_pelo_cpf(){
	
	system("cls");
	
	int i, f = 1, novo_debito;
	char cmp_cpf[11];
	
	printf("\tATUALIZAR DÉBITO DO MORADOR PELO CPF\n\n");
	
	//cmp_cpf -> comparador de cpf através do strcmp;
	
	printf("~~~~~~~~~~~~~~~~\n");
	printf("Digite seu cpf: ");
	scanf("%s", &cmp_cpf);

		for(i = 0; i <= cont; i++){
		
			if(strcmp(cmp_cpf,morador[i].cpf) == 0){ //Através da condição "if" o cpf do comparador vai ser comparado com o cpf já cadastrado na estrutura(" == 0 " -> verdadeiro);
				
				printf("~~~~~~~~~~~~~~~~\n");
				printf("Nº do cadastro: %d\n", i);
				printf("Nome: %s\n", morador[i].nome);
				printf("CPF: %s\n", morador[i].cpf);
				printf("Nº apartamento: %d\n", morador[i].apto);
				printf("Valor do débito: R$%0.2f\n", morador[i].debito);
				
				f = 0; //Uma pequena declaração para que o segundo "if" dentro dessa função não seja ativado caso este "if" seja verdadeiro;
				
				printf("\n\nDigite o valor do novo débito: ");
				scanf("%d", &novo_debito); //Variável que vai armazenar o novo débito digitado;
			
				morador[i].debito = novo_debito; //Igualdade para a troca de valor do antigo débito pelo novo dentro do array da estrutura;
					
					system("cls");
					
					printf("Débito alterado com sucesso!\n\n");
					
					system("pause");
				
						
			}
			if(f == 1){
				
				printf("\n\nMORADOR NÃO ENCONTRADO!!!!!!!\n\n");
				
				system("pause");
				
			}	
		}	

}
void Exibir_os_condominios_devedores(){
		
	system("cls");
		
		int i;
		
		printf("\tLISTA DE MORADORES DEVEDORES\n\n");
		
		for(i = 0; i <= cont; i++){ 
			
			if(morador[i].debito > 0){ //Condição para listar os moradores em que o valor armazenado na variável debito dentro do array da estrutura for > 0;
			
				printf("~~~~~~~~~~~~~~~~\n");
				printf("Nº do cadastro: %d\n", i);
				printf("Nome: %s\n", morador[i].nome);
				printf("CPF: %s\n", morador[i].cpf);
				printf("Nº apartamento: %d\n", morador[i].apto);
				printf("Valor do débito: R$%0.2f\n\n", morador[i].debito);
		}

		}

}
void Exibir_os_condominios_quites(){
	
	system("cls");
		
		int i;
		
		printf("\tLISTA DE MORADORES QUITES\n\n");
		
		for(i = 0; i <= cont; i++){
			
			if(morador[i].debito == 0){ //Condição para listar os moradores em que o valor armazenado na variável debito dentro do array da estrutura for == 0;
			
				printf("~~~~~~~~~~~~~~~~\n");
				printf("Nº do cadastro: %d\n", i);
				printf("Nome: %s\n", morador[i].nome);
				printf("CPF: %s\n", morador[i].cpf);
				printf("Nº apartamento: %d\n", morador[i].apto);
				printf("Valor do debito: R$%0.2f\n\n", morador[i].debito);
		}

		}

}
void Remover_os_condominios(){
	
	system("cls");
	
	int f, b = 1;

		printf("Digite o Nº do morador que deseja excluir: ");
		scanf("%d", &f); //Procurador de posição do array;
		
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

		cont--; //Quando remover o cadastro "num" ficará com - 1;
		
		}
		if(b == 1){
		
		printf("\n\nMORADOR NÂO ENCONTRADO !!!!!\n\n");
		
		system("pause");
	}
}

void listar_condominios(){
	
	system("cls");
	
	
	int i = 0;
	
	printf("\tLISTA DE MORADORES DO CONDOMÍNIO\n\n");

	for(i = 0; i <= cont; i++){ //Condição para listar todos os moradores dentro do array da estrutura;
	
			printf("~~~~~~~~~~~~~~~~\n\n");
			printf("Nº do cadastro: %d\n", i);
			printf("Nome: %s\n", morador[i].nome);
			printf("CPF: %s\n", morador[i].cpf);
			printf("Nº apartamento: %d\n", morador[i].apto);
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
	
	cont = fread(morador, sizeof(struct cadastrar), MAX, arquivo); //Vai adcionar a variável de quantidade de cadastro("num") o conteudo do arquivo;
	fclose(arquivo);
}
