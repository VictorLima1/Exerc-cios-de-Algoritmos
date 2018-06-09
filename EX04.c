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
	printf("Valor inexistente\n");
}

void deletaElemento(VetorDinamico *ve){
	int num;
	printf("Qual valor deseja deletar?" );
	scanf("%d", &num);
	int i, aux, del = 0;
	for(i = 0; i <= ve->n; i++){
		if(num == ve->v[i]){
			aux = ve->v[i+2];
			ve->v[i] = ve->v[i+1];
			ve->v[i+1] = aux;
			del = 1;
			ve->n = ve->n - 1;
		}		
	}
	
	if (del == 0){
		printf("Valor inexistente");
	}
	
}

void imprimeVetor(VetorDinamico *ve){
	int i;
	for(i = 0; i < ve->n; i++){
		printf("%d  ", ve->v[i]);
	}
}

void copiaVetores(VetorDinamico *ve, VetorDinamico *va){
	int i;
	if(ve->n < va->n){
		printf("\nO segundo vetor tem mais valores que o primeiro. Copiando apenas o que for possivel.\n");
	}

	if(ve->n > va->n){
		printf("\nO primeiro vetor tem mais valores. Os valores restantes serao zerados.\n");
	}

	for(i = 0; i < ve->n; i++){
		ve->v[i] = va->v[i];
	}

}

/*void inverteVetor(VetorDinamico *ve){
	int x = ve->n, i;
	VetorDinamico reserva;

	for(i = 0; i < ve->n; i++){
		reserva.v[i] = ve->v[i];
	}

	for (i = 0; i < ve->n; i++){
		ve->v[i] = reserva.v[i+x];
		x--;
	}
}*/

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

	printf("\n\nEm qual vetor deseja deletar um elemento? Digite 1 ou 2: ");
	scanf("%d", &x);
	if(x == 1)
		deletaElemento(&d);
	else if(x == 2)
		deletaElemento(&c);

	printf("\nPrimeiro vetor: ");
	imprimeVetor(&d);
	printf("\nSegundo vetor: ");
	imprimeVetor(&c);

	copiaVetores(&d, &c);
	printf("\n\n\nCopiando do segundo para o primeiro vetor: \n");
	printf("\nPrimeiro vetor: ");
	imprimeVetor(&d);
	printf("\nSegundo vetor: ");
	imprimeVetor(&c);

	printf("\n\nInvertendo o primeiro vetor:");
	inverteVetor(&d);
	printf("\nPrimeiro vetor: ");
	imprimeVetor(&d);

	return 0;
}
