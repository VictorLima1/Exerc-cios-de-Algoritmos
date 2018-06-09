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
  for (i = 0; i < n; i++) {
  	fscanf(f,"%s", (a[i].registro));
  	fscanf(f,"%s", (a[i].nome));
  	fscanf(f,"%s", (a[i].email));
  	fscanf(f,"%s", (a[i].telefone));
  	fscanf(f,"%i", (a[i].p1));
  	fscanf(f,"%i", (a[i].p2));
  	fscanf(f,"%i", (a[i].p3));
  	fscanf(f,"%i", (a[i].media));
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
	fflush(stdin);
	printf("Registro do aluno: ");
	fflush(stdin);
	scanf("%s", a.registro);
	fflush(stdin);
	printf("\nNome do aluno: ");
	fflush(stdin);
	scanf("%s", a.nome);
	fflush(stdin);
	printf("\nE-mail do aluno: ");
	fflush(stdin);
	scanf("%s", a.email);
	fflush(stdin);
	printf("\nTelefone do aluno: ");
	fflush(stdin);
	scanf("%s", a.telefone);
	fflush(stdin);
	printf("\nNota da P1: ");
	fflush(stdin);
	scanf("%i", &a.p1);
	fflush(stdin);
	printf("\nNota da P2: ");
	fflush(stdin);
	scanf("%i", &a.p2);
	fflush(stdin);
	printf("\nNota da P3: ");
	fflush(stdin);
	scanf("%i", &a.p3);

	a.media = (a.p1 + a.p2 + a.p3)/3;
	FILE* f = fopen("registros.txt", "a");
	fprintf(f, "%s %s %s %s %i %i %i %i\n", a.registro, a.nome, a.email, a.telefone, a.p1, a.p2, a.p3, a.media);
	fclose(f);
}

void mostraAluno(Aluno *a, int n){
	int i = 0;
  	for (i = 0; i < n; i++) {
		if(a[i].nome == ""){

		}
		else{
			printf("Registro: %s\nNome: %s\nE-mail: %s\nTelefone: %s\nP1: %i\nP2: %i\nP3: %i\nMédia: %i\n\n", a[i].registro, a[i].nome, a[i].email, a[i].telefone, a[i].p1, a[i].p2, a[i].p3, a[i].media);
		}
  	}
	puts("");
}

void deletaAluno(Aluno *a, int n){
	system("clear");
	FILE* f = fopen("registros.txt", "w");
	int opc, i = 0;
	printf("Quer apagar apenas um ou todos os alunos?\n1 - Apenas um\n2 - Todos\n\n");
	scanf("%i", &opc);

	if(opc == 1){
		system("clear");
		char nome[50];
		printf("Qual o nome do aluno que deseja apagar? ");
		scanf("%s", nome);
		for (i = 0; i < n; i++){
			if(strcmp(nome, a[i].nome) != 0){
				fprintf(f, "%s %s %s %s %i %i %i %i\n", a[i].registro, a[i].nome, a[i].email, a[i].telefone, a[i].p1, a[i].p2, a[i].p3, a[i].media);
			}
		}
		system("clear");
		printf("%s deletado(a).", nome);
		puts("");
		puts("");
	}
}

int main(){
	int opc = 1, opc2;



	while(opc == 1){
		printf("1 - Inserir aluno\n2 - Mostrar todos\n3 - Alterar dados\n4 - Deletar aluno\n0 - Sair\n");
		scanf("%d", &opc2);

		system("clear");

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
