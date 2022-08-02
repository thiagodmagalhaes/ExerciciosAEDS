#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void MSG_MENU(){
    printf("\n******************** MENU ***********************");
    printf("\n\t1. ENFILEIRAR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. DESENFILEIRAR");
    printf("\n\t4. ALTERAR");
    printf("\n\t5. IMPRIMIR FILA");
    printf("\n\t6. SAIR");
}

int main(){
    // Declaração de variáveis:
    TFila fila;
    TProduto Item;

    // Inicialização da lista
    FFVazia(&fila);

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
                Enfileirar(Item, &fila);
                printf("\n\n >>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<");
                printf("\n\n");
                system("PAUSE");
                break;
            case 2:
                /*  PESQUISAR */
                system("cls");
                printf("\n\tDIGITE O CODIGO PRODUTO: ");
                fflush(stdin);
                scanf("%d", &Item.codigo);
                int retorno;
                retorno = Pesquisar(fila,Item);
                if(retorno==1)
                    printf("\n\tPRODUTO ENCONTRADO!!!!");
                else if(retorno==0)
                    printf("\n\tFILA VAZIA!!!");
                else
                    printf("\n\tPRODUTO NAO FOI ENCONTRADO!!!");
                printf("\n\n");
                system("PAUSE");
                break;
            case 3:
                /*  EXCLUIR  */
                system("cls");
                printf("\n***********************************************");
                Desenfileirar(&fila,&Item);
                printf("\n\tOBJETO EXCLUIDO COM SUCESSO!");
                ImprimirProduto(Item);
                printf("\n\n");
                system("PAUSE");
                break;

            case 4:
                /*  ALTERAR */
                system("cls");
                printf("\n\tDIGITE O CODIGO PRODUTO: ");
                fflush(stdin);
                scanf("%d", &Item.codigo);
                int r = Pesquisar(fila,Item);
                if(r==1)
                    AlteraF(fila,Item);
                printf("\n\n");
                system("PAUSE");
                break;
            case 5:
                /*  IMPRIMIR */
                system("cls");
                printf("\n***********************************************");
                ImprimirFila(fila);
                printf("\n\n");
                system("PAUSE");
                break;

            case 6:
                system("cls");
                printf("\n\n >>>>>>>>>>>>>>>>>>>>>>> MSG: SAINDO DO SISTEMA! <<<<<<<<<<<<<<<<<<<<<<\n\n");
                printf("\n\n");
                system("PAUSE");
                break;

            default:
                system("cls");
                printf("\n\n >>>>>>>>>>>>>>>>>>>>>>> MSG: DIGITE UMA OPCAO VALIDA! <<<<<<<<<<<<<<<<<<<<<<\n\n");
                printf("\n\n");
                system("PAUSE");
                break;
        }
    } while(opcao != 6);

    return 0;
}
