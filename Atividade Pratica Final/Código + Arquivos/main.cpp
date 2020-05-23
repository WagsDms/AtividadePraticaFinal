#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#define MAXTAM 3

using namespace std;

typedef float numero;
typedef char letra;

struct aluno{
	letra nome[50];
	letra codigo[50];
	numero nota_prova1;
	numero nota_prova2;
	numero nota_prova3; 
	int status;
}aluno[10];

struct ficha_disciplina{
	letra nome_disciplina[40];
	letra codigo_disciplina[40];
}disciplina;

struct pilha{
	numero nota[MAXTAM];
	numero media[10];
	int Topo;
};

pilha *p;

int i, opc;
letra pesq[50];

void inicializa(){
    for(i=0; i<10; i++){
    	aluno[i].status=0;
	}
	p->Topo=-1;
}

bool verifica(int n){
	if (n==0){
        return true;
	}
	else{
        return false;
	}
}

void cadastro_disciplina(){
	
	system("cls");
	
	printf("\n---------- CADASTRAR DISCIPLINA -----------\n");
		
	printf("\n Nome da Disciplina: ");
	fflush(stdin);
	fgets(disciplina.nome_disciplina, 40, stdin);
	
	printf("\n Codigo da disciplina: ");
	fflush(stdin);
	fgets(disciplina.codigo_disciplina, 40, stdin);
}

void inserir_nome(){
   char cod[50];
   int tam,aux;
   FILE *P;
   
   	system("cls");

		printf("\n---------- CADASTRAR ALUNO -----------\n");
		
      	for(i=0;i<=10;i++){
      		printf("\n Código do aluno: ");
      		fflush(stdin);
      		scanf("%s",&cod);


      		strcpy(aluno[i].codigo,cod);

      		tam=strlen(aluno[i].codigo);

      		if(tam!=7){
       			if(tam<7){
       		 		printf("\n Código de aluno incorreto");
					printf("\n Digitos insuficientes");
        		 	_sleep(200);
        			aux=0,
       				inserir_nome();
       		 	}
       		 	else{
       		 		printf("\n Código de aluno incorreto");
					printf("\n Muitos digitos");
        			_sleep(200);
        			aux=0;
        			inserir_nome();
        	}
    	}
      	else{
      		aux=1;
	 	}
		if(aux==1){
   			printf("\n Nome do aluno: ");
   			fflush(stdin);
   			gets(aluno[i].nome);
   			strlwr(aluno[i].nome);
   			aluno[i].nome[0]=toupper(aluno[i].nome[0]);
   			aluno[i].status+1;
		}

  	 	P=fopen("DiarioAlunos.txt", "a+");
 		fwrite(&aluno, sizeof(aluno), 1, P);
   		fclose(P);
		  }
}

void cadastro_estudante(){
	inserir_nome();
	system("cls");
	printf("\n---------- CADASTRAR ALUNO -----------\n");
	printf("\n Cadastro realizado com sucesso!");
}
void inserir_nota(){
	
	FILE *P;
	P=fopen("Diario.txt", "r");
	
	system("cls");
	
    fread(&aluno, sizeof(aluno), 1, P);
	printf("\n---------- LANÇAR NOTA -----------\n");
    printf("\n Informe o Código do Aluno que quer adicionar uma nota: ");
      fflush(stdin);
      scanf("%s",&pesq);
            for(i=0;i<10;i++){
                if(strcmp(pesq,aluno[i].codigo)==0){
                	system("cls");
                	printf("\n---------- LANÇAR NOTA -----------\n");
                	printf("\n Nome: %s",aluno[i].nome);
                	printf("\n Código: %s",aluno[i].codigo);
                	printf("\n Disciplina: %s",disciplina.nome_disciplina);
                	printf("\n Código: %s",disciplina.codigo_disciplina);
					
					do{
						printf("\n Digite a Nota da Avaliação 1:\n");
            			scanf("%f",&aluno[i].nota_prova1);
            			if(aluno[i].nota_prova1>10){
            				printf("\n Nota inválida!");
						}
					}while(aluno[i].nota_prova1>10);
					
					do{
						printf("\n Digite a Nota da Avaliação 2:\n");
            			scanf("%f",&aluno[i].nota_prova2);
            			if(aluno[i].nota_prova2>10){
            				printf("\n Nota inválida!");
						}
					}while(aluno[i].nota_prova2>10);
					
					do{
						printf("\n Digite a Nota da Avaliação 3:\n");
            			scanf("%f",&aluno[i].nota_prova3);
            			if(aluno[i].nota_prova3>10){
            				printf("\n Nota inválida!");
						}
					}while(aluno[i].nota_prova3>10);
           		}
            }
            if (i==10){
            	printf("\n Aluno não encontrado");
            	
			}
            }


void lancar_nota(){
	
	system("cls");
	
	for(i=0;i<=5;i++){
	
		system("cls");
		inserir_nota();
		system("cls");
		printf("\n---------- LANÇAR NOTA -----------\n");
		printf("\n Notas Inseridas: ");
		_sleep(200);
	}

	system("cls");
}

void alterar_nota(){
	FILE *P;
	P=fopen("Diario.txt", "r");
	
	system("cls");
	
    fread(&aluno, sizeof(aluno), 1, P);
	
	printf("\n---------- ALTERAR NOTA -----------\n");
    printf("\n Informe o Código do Aluno que quer adicionar uma nota: ");
      fflush(stdin);
      scanf("%s",&pesq);
            for(i=0;i<10;i++){
                if(strcmp(pesq,aluno[i].codigo)==0){
                	system("cls");
                	printf("\n---------- ALTERAR NOTA -----------\n");
                	printf("\n Nome: %s",aluno[i].nome);
                	printf("\n Código: %s",aluno[i].codigo);
                	printf("\n Disciplina: %s",disciplina.nome_disciplina);
                	printf("\n Código: %s",disciplina.codigo_disciplina);
					printf("\n Notas lançadas: ");
					printf("\n Avaliação 1: %.2f",aluno[i].nota_prova1);
					printf("\n Avaliação 2: %.2f",aluno[i].nota_prova2);
					printf("\n Avaliação 3: %.2f",aluno[i].nota_prova3);
					printf("\n Selecione a Avaliação que deseja mudar a nota:");
					do{
						printf("\n [1] Avaliação 1");
						printf("\n [2] Avaliação 2");
						printf("\n [3] Avaliação 3");
						printf("\n [0] Sair");
						scanf("%d", &opc);
						switch(opc){
							case 1:
								do{
									system("cls");
									printf("\n---------- ALTERAR NOTA -----------\n");
									printf("\n\n Digite a Nota da Avaliação 1:\n");
            						scanf("%f",&aluno[i].nota_prova1);
            						if(aluno[i].nota_prova1>10){
            							printf("\n Nota inválida!");
									}
								}while(aluno[i].nota_prova1>10);
								break;
							case 2:
								do{
									system("cls");
									printf("\n---------- ALTERAR NOTA -----------\n");
									printf("\n\n Digite a Nota da Avaliação 1:\n");
            						scanf("%f",&aluno[i].nota_prova1);
            						if(aluno[i].nota_prova1>10){
            							printf("\n Nota inválida!");
									}
								}while(aluno[i].nota_prova1>10);
								break;
							case 3:
								do{
									system("cls");
									printf("\n---------- ALTERAR NOTA -----------\n");
									printf("\n\n Digite a Nota da Avaliação 1:\n");
            						scanf("%f",&aluno[i].nota_prova1);
            						if(aluno[i].nota_prova1>10){
            							printf("\n Nota inválida!");
									}
								}while(aluno[i].nota_prova1>10);
								break;
						}
					}while(opc!=0);
           		}
            }
            if (i==10){
            	printf("\n Aluno não encontrado");
			}
}

void media(pilha *p){
	for(i=0;i<=10;i++){
		p->nota[p->Topo]==aluno[i].nota_prova1;
		p->Topo++;
		p->nota[p->Topo]==aluno[i].nota_prova2;
		p->Topo++;
		p->nota[p->Topo]==aluno[i].nota_prova3;
		p->media[i]=+p->nota[p->Topo];
	}
	
}
void relatorio(){
    int n;
    
    FILE *P;
	P=fopen("DiarioAluno.txt", "r");
    fread(&aluno, sizeof(aluno), 1, P);

    for(i=0; i<10; i++){
   		if(aluno[i].status==1){
      		printf("\n Nome: %s",aluno[i].nome);
            printf("\n Código: %s",aluno[i].codigo);
        	printf("\n Disciplina: %s",disciplina.nome_disciplina);
            printf("\n Código: %s",disciplina.codigo_disciplina);
			printf("\n Avaliação 1: %.2f",aluno[i].nota_prova1);
			printf("\n Avaliação 2: %.2f",aluno[i].nota_prova2);
			printf("\n Avaliação 3: %.2f",aluno[i].nota_prova3);
			printf("\n Média: %2.f", p->media[i]);
	  		n=0;
	  		P=fopen("DiarioNotas.txt", "w+");
  			fwrite(&aluno, sizeof(aluno), 1, P);
   			fclose(P);
     	}
    }
    verifica(n);
    if(verifica(n)==true)
    {
    printf("\n Enter voltar ao menu...");
    system("cls");
    }
    else
    {
   	printf("\n Nenhum aluno encontrado");
	printf("\n Enter voltar ao menu...");
   	system("cls");
    }
}

void credit(){
	printf("\n Programa desenvolvido por:");
	printf("\n Pedro Vinicius Braz de Carvalho - RA: 3071710");
	printf("\n André Vinicius Nunes Anastácio - RA: 1201287");
	printf("\n Wagner Dimas de Oliveira Pereira - RA: 2221089");
	printf("\n Agradecemos a atenção!!!");
	_sleep(200);
}

int main(){
	
	setlocale(LC_ALL, "");
	do{
		system("cls");
		printf("\n Gerenciamento de Alunos");
		printf("\n [1] Cadastro Disciplina");
		printf("\n [2] Cadastro Aluno");
		printf("\n [3] Lançar Nota");
		printf("\n [4] Alterar nota");
		printf("\n [5] Relatório");
		printf("\n [6] Créditos");
		printf("\n [0] Fim");
		printf("\n Escolha uma opção: ");
		scanf("%d", & opc);
		switch(opc){
			case 1:
				system("cls");
				cadastro_disciplina();
				break;
			case 2:
				system("cls");
				cadastro_estudante();
				break;
			case 3:
				system("cls");
				lancar_nota();
				break;
			case 4:
				system("cls");
				alterar_nota();
				break;
			case 5: 
				system("cls");
				relatorio();
				break;
			case 6:
				system("cls");
				credit();
				break;
			case 0:
				system("cls");
				printf("\n FIM \n");
				break;
			default:
			    printf("\n Opcão invalida \n");				
		}
		system("Pause>null");
	}while(opc!=0);
}
