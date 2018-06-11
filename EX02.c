#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int a;
	int b;
}XPTO;

void criaVetor(XPTO *v, int n){
	int i;
	for(i=0;i<n;i++){
		v[i].a = i%3;
		v[i].b = 100 - i%5;
	}
}

void imprimeVetor(XPTO *v, int n){
	int i;

	for(i=0;i<n;i++){
		printf("a = %d, b = %d\n", v[i].a, v[i].b);
	}
}

int porA(void *p1, void *p2){
	XPTO *pp1 = p1;
	XPTO *pp2 = p2;
	return pp1->a < pp2->a;
}

int porB(void *p1, void *p2){
	XPTO *pp1 = p1;
	XPTO *pp2 = p2;
	return pp1->b < pp2->b;
}

void troca(void *a, void *b, size_t tam){
	void* aux = malloc(tam);
	memcpy(aux, a, tam);
	memcpy(a, b, tam);
	memcpy(b, aux, tam);
	free(aux);
}

void ordena(void *v, size_t t, int n, int (*porA)(void *a, void *b)){
	int i,j;
	for(i = 0;i < n-1;i++){
		for(j = 0;j < n-1;j++){
			if(porA(v + j*, v + (j+1)*t) == 1){
				troca(v+ j*t, v + (j+1)*t, t);
			}
		}
	}
}

int main(int argc, char*argv[]){
	XPTO v[10];
	criaVetor(v, 10);
	// Ordenando por A
	ordena(v, sizeof(XPTO), 10, porA);
	imprimeVetor(v, 10);

	// Ordenando por B
	ordena(v, sizeof(XPTO), 10, porB);
	imprimeVetor(v, 10);

	return 0;
}
