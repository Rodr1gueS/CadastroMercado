#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define PRODUTOS 50
#define VENDEDOR 50

typedef struct{
    char nomeVendedor[VENDEDOR],nomeProduto[PRODUTOS],cidade[VENDEDOR],estado[VENDEDOR];
    float preco [PRODUTOS];
    int ativo,quantidade[PRODUTOS],mesValidade[PRODUTOS],diaValidade[PRODUTOS],anoValidade[PRODUTOS],tel[VENDEDOR];
}Mercado;

Mercado mercado[PRODUTOS];

void menu();
void cadastrar();
void remover();
void pesquisar();
void listar();
void mais();

int main()
{
    setlocale(LC_ALL,"");

    system ("color 4f"); //mudando a cor da tela e letra


    //fprintf(file, listar());


    menu();


    return 0;

}

void menu(){
    int opc;
    do{
    system("cls");

    printf("\t\t\t\t\n=======================================\n");
    printf("\t\t\t\t\n=======================================\n");
    printf("\tMercadinho Do CEFET\n");
    printf("\t\t\t\n=======================================\n");
    printf("\t\t\t\n=======================================\n");

    printf("\t\n 1 - cadastro\n");
    printf("\t\n 2 - Visualizar cadastro\n");
    printf("\t\n 3 - Mais\n");
    printf("\t\n 4 - Deletar cadastro\n");
    printf("\t\n 5 - Pesquisar Produto\n");
    printf("\t\n 6 - Sair\n");

    printf("\t\n Opcao desejada:");
    scanf("%d", &opc);
    printf("\t.........");
    getchar();
    system("cls");

    switch(opc){
        case 1 :
            cadastrar();
        break;
        case 2:
            listar();
        break;
        case 3:
            mais();
        break;

        case 4:
            remover();
        break;
        case 5:
            pesquisar();
        break;
            getchar();



    }
    getchar();
}while(opc!=6);

    FILE *file;
    file = fopen ("test.txt","w");
      for(int i = 0; i< PRODUTOS; i++){
        if(mercado[i].ativo==1){
            fprintf(file,"-----------------------\n");
            fprintf(file,"Codigo: %d\n", i+1);
            fprintf(file,"Nome %s\n",mercado[i].nomeProduto);
            fprintf(file,"Preco: %0.2f\n",mercado[i].preco[0]);
            fprintf(file,"Dia da validade: %d\n",mercado[i].diaValidade[0]);
            fprintf(file,"Męs da validade: %d\n",mercado[i].mesValidade[0]);
            fprintf(file,"Ano da validade: %d\n",mercado[i].anoValidade[0]);
            fprintf(file,"Quatidade: %d\n",mercado[i].quantidade[0]);

            printf("\t\t\n......Cadastro do fornecedor do produto.....\n\n");

            fprintf(file,"Nome do fornecedor: %s\n",mercado[i].nomeVendedor);
            fprintf(file,"Telefone para contato: %d\n",mercado[i].tel[0]);
            fprintf(file,"Cidade: %s\n",mercado[i].cidade);
            fprintf(file,"Estado: %s\n",mercado[i].estado);




        }


}
fclose(file);
}
void cadastrar(){
    system("cls");
    char nomeVendedor[VENDEDOR],nomeProduto[PRODUTOS],cidade[VENDEDOR],estado[VENDEDOR];
    float preco[PRODUTOS];
    int opc,mesValidade[PRODUTOS], diaValidade[PRODUTOS],anoValidade[PRODUTOS],tel[VENDEDOR],quantidade[PRODUTOS];

    do{
        printf("\nNome do produto: ");
        fgets(nomeProduto, sizeof(nomeProduto), stdin);
        printf("\nPreco do produto: ");
        scanf("%f", &preco[0]);
        printf("\nDia da Validade: ");
        scanf("%d", &diaValidade[0]);
        printf("\nMes da Validade: ");
        scanf("%d", &mesValidade[0]);
        printf("\nAno da Validade: ");
        scanf("%d", &anoValidade[0]);
        printf("\nQuantidade: ");
        scanf("%d", &quantidade[0]);
        fflush(stdin);


        printf("\t\t\n......Cadastro do fornecedor do produto.....\n\n");

        printf("\nNome do fornecedor: ");
        fgets(nomeVendedor, sizeof(nomeVendedor), stdin);
        printf("\ntelefone para contato: ");
        scanf("%d", &tel[0]);
        fflush(stdin);
        printf("\nEstado: ");
        fgets(estado, sizeof(estado), stdin);
        fflush(stdin);
        printf("\nCidade: ");
        fgets(cidade, sizeof(cidade), stdin);



        for (int i = 0; i< PRODUTOS; i++){
                if(mercado[i].ativo ==0)
                {
                    mercado[i].preco[0] = preco [0];
                    mercado[i].diaValidade[0] = diaValidade [0];
                    mercado[i].mesValidade[0] = mesValidade [0];
                    mercado[i].anoValidade[0] = anoValidade [0];
                    mercado[i].quantidade[0] = quantidade [0];
                    mercado[i].tel[0] = tel [0];
                    strcpy(mercado[i].nomeProduto, nomeProduto);
                    strcpy(mercado[i].nomeVendedor, nomeVendedor);
                    strcpy(mercado[i].estado, estado);
                    strcpy(mercado[i].cidade, cidade);
                    mercado[i].ativo=1;
                    break;
                }

        }
        printf("\n1- Continuar\n6- Sair\n");
        scanf("%d", &opc);
        getchar();
    }while(opc!=6);

}
void listar(){
    int opc;

    system("cls");
    printf("\nLista de Produtos\n");
     for(int i = 0; i< PRODUTOS; i++){
        if(mercado[i].ativo==1){
            printf("--------------------------\n");
            printf("Codigo: %d\n", i+1);
            printf("Nome %s\n",mercado[i].nomeProduto);
            printf("Preco: %0.2f\n",mercado[i].preco[0]);
            printf("Dia da validade: %d\n",mercado[i].diaValidade[0]);
            printf("Mes da validade: %d\n",mercado[i].mesValidade[0]);
            printf("Ano da validade: %d\n",mercado[i].anoValidade[0]);
            printf("Quantidade: %d\n",mercado[i].quantidade[0]);

            printf("\t\t\n......Cadastro do fornecedor do produto.....\n\n");

            printf("Nome do fornecedor: %s\n",mercado[i].nomeVendedor);
            printf("Telefone para contato: %d\n",mercado[i].tel[0]);
            printf("Cidade : %s\n",mercado[i].cidade);
            printf("Estado: %s\n",mercado[i].estado);



        }


}


}
void remover(){
int codigo;
    listar();
    printf("\nDigite o codigo do produto a ser removido: ");
    scanf("%d", &codigo);
    --codigo;
    mercado[codigo].ativo=0;
    printf("\nproduto excluido com sucesso!\n");
    getchar();
}
void mais(){
    int opc;
    do{
            system("cls");

            printf("\n\t.....Mais sobre o mercadinho....\n\n");
            printf("\t Olá consumidor, criamos esse espaço para que\n");
            printf("\t consiga ver sobre seu produto\n");
            printf("\t e sobre seu fornecedor\n");

            printf("\t...............\n\n");
            printf("\t Desenvolvido por: \n\n");
            printf("\t Igor, Giovanna, Gabriel Reis e Yuri \n\n");
            printf("\t...............\n\n");

            printf("\n6- Sair");
            scanf("%d", &opc);
            getchar();

            system("cls");
    }while(opc!=6);
}
void pesquisar(){
char nomeVendedor[VENDEDOR],nomeProduto[PRODUTOS];
int opc;
    do{
        system("cls");
        printf("\nDigite o nome do produto para pesquisar ");
        fgets(nomeProduto,sizeof(nomeProduto),stdin);
        for(int i = 0; i< PRODUTOS; i++){
            if(strstr(mercado[i].nomeProduto,nomeProduto)!=NULL){
                    printf("-------\n");
                    printf("Código: %d\n", i+1);
                    printf("Nome %s\n",mercado[i].nomeProduto);
                    printf("Preço: %0.2f\n",mercado[i].preco[0]);
                    printf("Dia da validade: %d\n",mercado[i].diaValidade[0]);
                    printf("Męs da validade: %d\n",mercado[i].mesValidade[0]);
                    printf("Ano da validade: %d\n",mercado[i].anoValidade[0]);
                    printf("Nome do fornecedor: %s\n",mercado[i].nomeVendedor);
                    printf("Telefone para contato: %d\n",mercado[i].tel[0]);
                    printf("Cidade : %s\n",mercado[i].cidade);
                    printf("Estado: %s\n",mercado[i].estado);
                }

    }
    printf("\nDigite 6 para sair ou 1 para nova pesquisa: ");
    scanf("%d",&opc );
    getchar();

    }while(opc!=6);
}
