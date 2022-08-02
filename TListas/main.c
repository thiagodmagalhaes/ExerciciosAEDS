#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void MSG_MENU(){
    printf("\n******************** MENU ***********************");
    printf("\n\t1. INSERIR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. EXCLUIR");
    printf("\n\t4. ALTERAR");
    printf("\n\t5. IMPRIMIR LISTA");
    printf("\n\t6. SAIR");
}

int main(){
    // Declaração de variáveis:
    TLista lista;
    TProduto Item;
    TCelula *auxLista;

    // Inicialização da lista
    FLVazia(&lista);

    int opcao = 0;
    do{
        system("cls");
        MSG_MENU();
        printf("\n***********************************************");
        printf("\n\tDIGITE UMA OPCAO:");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                system("cls");
                LerProduto(&Item);
                Inserir(Item, &lista);
                printf("\n\n >>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<");
                system("PAUSE");
                break;
            case 2:
                /*  PESQUISAR */
                system("cls");
                printf("\n\tDIGITE O NOME DO PRODUTO: ");
                fflush(stdin);
                // USAR FGETS
                fgets(Item.nome,100,stdin);
                auxLista = Pesquisar(lista,Item);
                if(auxLista== NULL)
                    printf("\n\tPRODUTO NAO ENCONTRADO");

                else
                    ImprimirProduto(auxLista->prox->item);


                system("PAUSE");
                break;
            case 3:
                /*  EXCLUIR  */
                system("cls");
                printf("\n***********************************************");
                printf("\n\tDIGITE O NOME DO PRODUTO: ");
                fflush(stdin);
                fgets(Item.nome,100,stdin);
                auxLista = Pesquisar(lista,Item);
                if(auxLista== NULL)
                    printf("\n\tPRODUTO NAO ENCONTRADO");


                else
                {
                    Excluir(&lista, &Item);
                    printf("\n\tOBJETO EXCLUIDO COM SUCESSO!");
                    ImprimirProduto(Item);

                }


                system("PAUSE");
                break;

            case 4:
                /*  ALTERAR */
                system("cls");
                printf("\n\tDIGITE O NOME DO PRODUTO: ");
                fflush(stdin);
                fgets(Item.nome,100,stdin);
                auxLista = Pesquisar(lista,Item);
                if(auxLista == NULL)
                    printf("PRODUTO NAO ENCONTRADO");
                else
                {
                    LerProduto(&Item);
                    auxLista->prox->item = Item;
                    printf("\n\t PRODUTO ALTERADO COM SUCESSO!");
                }


                system("PAUSE");
                break;
            case 5:
                /*  IMPRIMIR */
                system("cls");
                printf("\n***********************************************");
                Imprimir(lista);
                system("PAUSE");
                break;

            case 6:
                system("cls");
                printf("\n\n >>>>>>>>>>>>>>>>>>>>>>> MSG: SAINDO DO SISTEMA! <<<<<<<<<<<<<<<<<<<<<<\n\n");
                system("PAUSE");
                break;

            default:
                system("cls");
                printf("\n\n >>>>>>>>>>>>>>>>>>>>>>> MSG: DIGITE UMA OPCAO VALIDA! <<<<<<<<<<<<<<<<<<<<<<\n\n");
                system("PAUSE");
                break;
        }
    } while(opcao != 6);

    return 0;
}
