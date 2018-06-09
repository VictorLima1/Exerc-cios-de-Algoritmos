#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int v[100];
	int n;
	int max;
}VetorEstatico;

VetorEstatico criaVetor(){
	VetorEstatico ve;
	ve.n = 0;
	ve.max = 100;
	return ve;
}

void insereDados(VetorEstatico *ve){
	ve->n = (ve->n + 1);
	int i = ve->n - 1;
	//printf("%d", ve->n);
	printf("Insira um valor: ");
	scanf("%d", ve->v+i);
}

void procuraNum(VetorEstatico *ve, int num){
	int i;
	for(i = 0; i < ve->n; i++){
		if(num == ve->v[i]){
			printf("Encontrado: %d\n", ve->v[i]);
			return;
		}		
	}
	printf("Valor não encontrado");
}

void deletaItem(VetorEstatico *ve, int num){
	int i, aux, del = 0;
	for(i = 0; i <= ve->n; i++){
		if(num == ve->v[i]){
			aux = ve->v[i+2];
			ve->v[i] = ve->v[i+1];
			ve->v[i+1] = aux;
			del = 1;
		}		
	}
	
	if (del == 1){
		ve->n = ve->n - 1;
	}
	else{
		printf("Valor inexistente");
	}
	
}

void imprimeVetor(VetorEstatico *ve){
	int i;
	printf("\n\n\nImprimindo o vetor:\n");
	for(i = 0; i < ve->n; i++){
		printf("%d\n", ve->v[i]);
	}
}

int main(){
	int i = 1;
	int opc;
	VetorEstatico ve = criaVetor();
	while(i!=0){
		printf("\n\n\nO que deseja?\n1 - Inserir\n2 - Procurar\n3 - Deletar\n4 - Imprimir\n\n\n");
		scanf("%d", &opc);
		if(opc == 1)
			insereDados(&ve);
		else if (opc == 2){
			int x;
			printf("Qual valor deseja procurar? ");
			scanf("%d", &x);
			procuraNum(&ve, x);
		}
		else if(opc == 3){
			int x;
			printf("Qual valor deseja deletar? ");
			scanf("%d", &x);
			deletaItem(&ve, x);
		}
		else if(opc == 4)
			imprimeVetor(&ve);
		else
			printf("Escolha apenas algum valor mostrado");
			
	}
}
