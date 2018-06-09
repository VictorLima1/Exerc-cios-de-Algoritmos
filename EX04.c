#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *v;
	int n;
	int max;
}VetorDinamico;

VetorDinamico criaVetor(int n){
	VetorDinamico vd;
	vd.v = malloc(sizeof(int)*n);
	vd.n = 0;
	vd.max = n;
	return vd;
}

void insereNumero(VetorDinamico *ve){
	ve->n = ve->n +1;
	int i, x;
	//printf("Qual valor deseja inserir? ");
	scanf("%d", &x);
	for(i = 0; i <= ve->max; i++){
		if(i == ve->n-1){
			ve->v[i] = x;
			return;
		}
	}	
}

void buscaElemento(VetorDinamico *ve){
	int i, x;
	printf("Qual valor deseja buscar? ");
	scanf("%d", &x);
	
	for(i = 0; i < ve->max; i++){
		if(ve->v[i] == x){
			printf("Encontrado o valor %d", ve->v[i]);
			return;
		}
	}
	printf("Valor inexistente");
}

void imprimeVetor(VetorDinamico *ve){
	int i;	
	for(i = 0; i < ve->max; i++){
		printf("%d  ", ve->v[i]);
	}
}

void copiaVetores(VetorDinamico *ve, VetorDinamico *va){
	for(
}

void inverteVetor(VetorDinamco *ve){
	int x = ve->max;
	for (i = 0; i < ve->max; i++){
		
	}
}

int main(){
	int x;
	printf("Quantos elementos existem no primeiro vetor? ");
	scanf("%d", &x);
	VetorDinamico d = criaVetor(x);
	printf("\nInsira os %d valores a serem guardados: \n", x);
	for(x = 0; x < d.max; x++){
		insereNumero(&d);
	}

	printf("\n\nQuantos elementos existem no segundo vetor? ");
	scanf("%d", &x);
	VetorDinamico c = criaVetor(x);
	printf("\nInsira os %d valores a serem guardados: \n", x);
	for(x = 0; x < c.max; x++){
		insereNumero(&c);
	}
	
	printf("\nPrimeiro vetor: ");
	imprimeVetor(&d);
	printf("\nSegundo vetor: ");
	imprimeVetor(&c);

	printf("\n\nDeseja procurar no primeiro ou no segundo vetor? Digite 1 ou 2: ");
	scanf("%d", &x);
	if(x == 1)
		buscaElemento(&d);
	else if(x == 2)
		buscaElemento(&c);
	
	
	return 0;
}