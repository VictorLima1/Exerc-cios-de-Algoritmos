#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

typedef struct aluno{
    char registro[10];
    char nome[50];
    char email[30];
    int telefone;
    float p1, p2, p3, media;
}aluno;

FILE *arq;
aluno contato;

char menu(){
    system("cls");
    printf("1 - Adicionar aluno\n");
    printf("2 - Mostrar todos os alunos\n");
    printf("3 - Procurar um aluno por nome\n");
    printf("4 - Procurar um aluno por registro\n");
    printf("5 - Modificar um aluno\n");
    printf("6 - Remover um aluno\n");
    printf("0 - Sair\n");
    printf("\n");
    printf("Valor que deseja: ");
    return (toupper(getche()));
}

int verifica(char nome[]){
    fread(&contato, sizeof(aluno), 1, arq);

    while(!feof(arq)){
        if (strcmp(contato.nome, nome) == 0){
            fseek(arq, -sizeof(aluno), SEEK_CUR);
            return 1;
        }
        fread(&contato, sizeof(aluno), 1, arq);
    }

    return 0;
}

int verifica_registro(char registro[]){
    fread(&contato, sizeof(aluno), 1, arq);

    while(!feof(arq)){
        if (strcmp(contato.registro,registro) == 0){
            fseek(arq, -sizeof(aluno), SEEK_CUR);
            return 1;
        }

        fread(&contato, sizeof(aluno), 1, arq);
    }

    return 0;
}

int verifica_num(int num){
    fread(&contato,sizeof(aluno),1,arq);
    while(!feof(arq)){
        if (contato.telefone == num){
            fseek(arq, -sizeof(aluno), SEEK_CUR);
            return 1;
        }
        fread(&contato, sizeof(aluno), 1, arq);
    }
    return 0;
}

void adicionar_aluno(){

    char nome[50];
    char registro[10];
    char email[30];
    float p1, p2, p3, media;

    arq = fopen("banco.bin","a+b");

    if (arq == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\n\n");
    printf("Digite o registro do aluno: ");
    fflush(stdin);
    gets(registro);

    printf("\n\n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(nome);

    printf("\n\n");
    printf("Digite o email: ");
    fflush(stdin);
    gets(email);

    if(verifica_registro(registro) == 1){

        if(verifica(nome) == 1){

            printf("\nNome ja existente.\n");
        }
        printf("\nRegistro ja existente.\n");
    }
    else{
        strcpy(contato.registro, registro);
        strcpy(contato.nome, nome);
        strcpy(contato.email, email);

        printf("\n\n");
        printf("Digite as notas da P1, P2 e P3 respectivamente: ");
        scanf("%f", &contato.p1);
        scanf("%f", &contato.p2);
        scanf("%f", &contato.p3);

        contato.media = ((contato.p1 + contato.p2 + contato.p3)/3);

        printf("\n\n");
        printf("Digite o telefone: ");
        scanf("%d", &contato.telefone);

        fwrite(&contato, sizeof(aluno), 1, arq);
    }
    fclose(arq);
}

void modificar_aluno(){
    char nome[50];
    char email[30];
    char registro[10];
    float p1, p2, p3;

    arq = fopen("banco.bin","r+b");

    if (arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite nome do aluno: ");
    fflush(stdin);
    gets(nome);

    if (verifica(nome) == 1){
        printf("\nDigite o novo nome do aluno: ");
        fflush(stdin);
        gets(nome);
        strcpy(contato.nome, nome);

        printf("\nDigite o novo registro do aluno: ");
        fflush(stdin);
        gets(registro);
        strcpy(contato.registro, registro);

        printf("\nDigite um novo numero de telefone do aluno: ");
        scanf("%d", &contato.telefone);

        printf("\nDigite o novo email do aluno: ");
        fflush(stdin);
        gets(email);
        strcpy(contato.email, email);

        printf("\nDigite as notas da P1, P2 e P3 respectivamente: ");
        scanf("%f", &contato.p1);
        scanf("%f", &contato.p2);
        scanf("%f", &contato.p3);

        contato.media = ((contato.p1 + contato.p2 + contato.p3)/3);

        fwrite(&contato, sizeof(aluno), 1, arq);
    }
    else{
        printf("\nNome nao existe.\n");
    }

    fclose(arq);
}

void remover_aluno(){
    char nome[50];
    FILE *tmp;

    arq = fopen("banco.bin","r+b");

    if (arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    tmp = fopen("banco.txt","a+b");

    printf("\n\n");
    printf("Digite nome do aluno: ");
    fflush(stdin);
    gets(nome);

    fread(&contato,sizeof(aluno),1,arq);
    while (!feof(arq)){
        if (strcmp(contato.nome, nome) != 0)
           fwrite(&contato, sizeof(aluno), 1, tmp);

        fread(&contato, sizeof(aluno), 1, arq);
    }

    fclose(arq);
    fclose(tmp);

    system("del banco.bin");
    system("ren banco.txt banco.bin");
}

void procura_aluno(){
    char nome[50];

    arq = fopen("banco.bin","r+b");

    if (arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(nome);

    if (verifica(nome) == 1){
        fread(&contato, sizeof(aluno), 1, arq);
        printf("\n----------------------------------------------\n");
        printf("Registro: %-20s\nNome: %-20s\nTelefone: %8d\nEmail: %-20s\nP1: %.1f\nP2: %.1f\nP3: %.1f\nMedia: %.1f\n", contato.registro,
               contato.nome, contato.telefone, contato.email, contato.p1, contato.p2, contato.p3, contato.media);
        printf("-----------------------------------------------\n");
    }
    else
    {
        printf("\nContato nao existe.\n");
    }

    fclose(arq);
}

void procura_registro(){
    char registro[10];

    arq = fopen("banco.bin","r+b");

    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n");
    printf("Digite o numero do registro: ");
    fflush(stdin);
    gets(registro);

    if (verifica_registro(registro) == 1)
    {
        fread(&contato, sizeof(aluno), 1, arq);
        printf("\n----------------------------------------------\n");
        printf("Registro: %-20s\nNome: %-20s\nTelefone: %8d\nEmail: %-20s\nP1: %.1f\nP2: %.1f\nP3: %.1f\nMedia: %.1f\n", contato.registro,
               contato.nome, contato.telefone, contato.email, contato.p1, contato.p2, contato.p3, contato.media);
        printf("-----------------------------------------------\n");

    }
    else
    {
        printf("\nContato nao existe.\n");
    }

    fclose(arq);
}

void mostrar_alunos(){
    arq = fopen("banco.bin","r+b");

    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    fread(&contato, sizeof(aluno), 1, arq);

    while (!feof(arq))
    {
        printf("\n----------------------------------------------\n");
        printf("Registro: %-20s\nNome: %-20s\nTelefone: %8d\nEmail: %-20s\nP1: %.1f\nP2: %.1f\nP3: %.1f\nMedia: %.1f\n", contato.registro,
               contato.nome, contato.telefone, contato.email, contato.p1, contato.p2, contato.p3, contato.media);
        printf("-----------------------------------------------\n");
        fread(&contato, sizeof(aluno), 1, arq);
    }

    fclose(arq);
}

int main(){
    char op;

    do
    {
        op = menu();

        switch(op)
        {
            case '1':
                adicionar_aluno();
                break;
            case '2':
                mostrar_alunos();
                break;
            case '3':
                procura_aluno();
                break;
            case '4':
                procura_registro();
                break;
            case '5':
                modificar_aluno();
                break;
            case '6':
                remover_aluno();
                break;
        }

        printf("\n");
        system("PAUSE");

    }while (op != '0');

    return 0;
}
