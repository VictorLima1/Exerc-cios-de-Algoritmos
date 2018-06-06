#include <stdio.h>
#include <stdlib.h>

struct Complexo{
	int real;
	int imaginario;
};

struct Complexo insereComplexo(int r, int i){
	struct Complexo novo;
	novo.real = r;
	novo.imaginario = i;
	return novo;
}

/* Por ser um ponteiro, é preciso utilizar "->" no a pois ele é um ponteiro. Ele APONTA para a estrutura, 
logo não tem suas variáveis então ponto não é viável;
"a->" pode ser substituído também por "(*a)";
b também pode ser um ponteiro, mas é necessário o uso de "b->" ou (*b), e é preciso trocar a passagem no main para (&a, %b),
mas o código já funciona dessa maneira. 
*/
void somaComplexos(struct Complexo *a, struct Complexo b){
	a->real += b.real;
	a->imaginario += b.imaginario;
}

int main(int argc, char *argv[]){
	struct Complexo a, b;
	a = insereComplexo(4, 7);
	b = insereComplexo(8, 10);
	somaComplexos(&a, b);
	// Não é necessário utilizar "->" aqui, é "a estrutura em si", logo o ponto é suficiente.
	printf("%d\n", a.real);
	printf("%d\n", a.imaginario);
	system("pause");
	return 0;
}
