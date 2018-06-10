#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char registro[10];
	char nome[50];
	char email[30];
	char telefone[20];
	int p1, p2, p3;
	int media;
}Aluno;

Aluno* leArquivo(Aluno *a, int n) {
  FILE* f = fopen("registros.txt","r");
  int i;
  for (i = 0; i < n; i = i+1) {
  	fscanf(f,"%s ", a[i].registro);
    fgets(a[i].nome, 50, f);
		a[i].registro[strcspn(a[i].registro, "\n")] = 0;
  	fscanf(f,"%s", a[i].email);
  	fscanf(f,"%s", a[i].telefone);
  	fscanf(f,"%i", &a[i].p1);
  	fscanf(f,"%i", &a[i].p2);
  	fscanf(f,"%i", &a[i].p3);
  	fscanf(f,"%i", &a[i].media);
  }
  fclose(f);
}

int contaLinhas(char* a){
	FILE* f = fopen(a, "r");
	char str[10000];
	int i=0;

	while(fgets(str, 10000, f) != NULL){
  	i++;
  }

  fclose(f);
	return i;
}

void insereAluno(){
	Aluno a;
	printf("Registro do aluno: ");
	fflush(stdin);
	fgets(a.registro, 10, stdin);
	a.registro[strcspn(a.registro, "\n")] = 0;
	printf("\nNome do aluno: ");
	fflush(stdin);
	fgets(a.nome, 50, stdin);
	a.nome[strcspn(a.nome, "\n")] = 0;
	printf("\nE-mail do aluno: ");
	fgets(a.email, 30, stdin);
	a.email[strcspn(a.email, "\n")] = 0;
	printf("\nTelefone do aluno: ");
	fgets(a.telefone, 20, stdin);
	a.telefone[strcspn(a.telefone, "\n")] = 0;
	printf("\nNota da P1: ");
	scanf("%i", &a.p1);
	printf("\nNota da P2: ");
	scanf("%i", &a.p2);
	printf("\nNota da P3: ");
	scanf("%i", &a.p3);

	a.media = (a.p1 + a.p2 + a.p3)/3;
	FILE* f = fopen("registros.txt", "a");
	fprintf(f, "%s\n%s\n%s\n%s\n%i\n%i\n%i\n%i\n", a.registro, a.nome, a.email, a.telefone, a.p1, a.p2, a.p3, a.media);
	fclose(f);
}

void mostraAluno(Aluno *a, int n){
	int i = 0;
  	for (i = 0; i < n; i++) {
			//fscanf()
		if(a[i].p1 == 0){

		}
		else{
			printf("Registro: %s\nNome: %sE-mail: %s\nTelefone: %s\nP1: %i\nP2: %i\nP3: %i\nMedia: %i\n\n", a[i].registro, a[i].nome, a[i].email, a[i].telefone, a[i].p1, a[i].p2, a[i].p3, a[i].media);
		}
  	}
	puts("");
}

void deletaAluno(Aluno *a, int n){
	//system("clear");
	FILE* f = fopen("registros.txt", "w");
	int opc, i = 0;
	printf("Quer apagar apenas um ou todos os alunos?\n1 - Apenas um\n2 - Todos\n\n");
	scanf("%i", &opc);

	if(opc == 1){
		//system("clear");
		char matricula[50];
		printf("Qual o regisstro do aluno que deseja apagar? ");
		scanf("%s", matricula);
		for (i = 0; i < n; i++){
			if(matricula != a[i].registro){
				fprintf(f, "%s\n%s\n%s\n%s\n%i\n%i\n%i\n%i\n", a[i].registro, a[i].nome, a[i].email, a[i].telefone, a[i].p1, a[i].p2, a[i].p3, a[i].media);
			}
		}
		//system("clear");
		puts("");
		puts("");
	}
}

int main(){
	int opc = 1, opc2;



	while(opc == 1){
		printf("1 - Inserir aluno\n2 - Mostrar todos\n3 - Alterar dados\n4 - Deletar aluno\n0 - Sair\n");
		scanf("%d", &opc2);

		//system("clear");

		if(opc2 == 1){
			insereAluno();
		}
		if(opc2 == 2){
			int n = contaLinhas("registros.txt");
			Aluno *a = malloc(sizeof(Aluno) * n);
			leArquivo(a, n);
      			mostraAluno(a, n);
			free(a);
		}
		if(opc2 == 4){
			int n = contaLinhas("registros.txt");
			Aluno *a = malloc(sizeof(Aluno) * n);
			deletaAluno(a, n);
			free(a);
		}
	}


	return 0;
}
