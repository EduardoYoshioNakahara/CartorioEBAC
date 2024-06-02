#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    setlocale(LC_ALL,"Portuguese");

    printf("Digite o CPF a ser utilizado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar ao conteúdo existente

    fprintf(file, "%s;", cpf);

    printf("Digite o seu nome: ");
    scanf("%s", nome);
    fprintf(file, "%s;", nome);

    printf("Digite o seu sobrenome: ");
    scanf("%s", sobrenome);
    fprintf(file, "%s;", sobrenome);

    printf("Digite o seu cargo: ");
    scanf("%s", cargo);
    fprintf(file, "%s\n", cargo); // Adiciona uma quebra de linha para separar os registros

    fclose(file);
    system("PAUSE");
}

int consulta() {
    char cpf[40];
    char conteudo[400];

    printf("Digite o cpf a ser consultado:");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if (cpf == NULL){
        printf("Não foi possivel abrir o arquivo, não localizado");
    }
    while ((fgets(conteudo, 200, file)!= NULL))
    {
        printf("\nEssas são as informações do usuário:");
        printf("%s", conteudo);
        printf("\n\n");
    }
   
    system("PAUSE");
}

int deletar() {
    char cpf[40];

    printf("Digite o cpf a ser deletado:");
    scanf("%s", cpf);

    remove(cpf);
    FILE *file;
    file = fopen(cpf,"r");
   

    if(file == NULL){
        printf("O usuário não se encontra no sistema!\n");
        system("pause");
    }

    system("PAUSE");
}

int main() {
    int opcao = 0;

    while (true) {
        system("cls");
        setlocale(LC_ALL,"PORTUGUESE");
        printf("\t Bem-vindo ao menu do cartório EBAC\n\n");
        printf("1 - Cadastrar usuário\n\n2 - Listar usuários\n\n3 - Apagar usuário\n\n4 - Sair\n\n");
        printf("\t Digite a opção desejada e pressione Enter: ");
       
        scanf("%i", &opcao);
       
        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Saindo do programa...\n");
                return 0; // Sair do programa
            default:
                printf("Opção inválida\n");
                system("PAUSE");
                break;
        }
    }
}
