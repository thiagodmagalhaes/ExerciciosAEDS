#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "listas.h"
#include "fila.h"

void MSG_MENU()
{
    printf("\n******************** MENU ***********************");
    printf("\n\t1. ADICIONAR ELEMENTO NA LISTA");
    printf("\n\t2. ADICIONAR ELEMENTO NA FILA");
    printf("\n\t3. ADICIONAR ELEMENTO NA PILHA");
    printf("\n\t4. INVERTER PILHA COM FILA");
    printf("\n\t5. INVERTER FILA COM PILHA");
    printf("\n\t6. INVERTER LISTA COM PILHA OU FILA");
    printf("\n\t7. EXCLUIR ELEMENTO DA FILA");
    printf("\n\t8. EXCLUIR ELEMENTO DA PILHA");
    printf("\n\t9. IMPRIMIR LISTA");
    printf("\n\t10. IMPRIMIR FILA");
    printf("\n\t11. IMPRIMIR PILHA");
    printf("\n\t12. DIVIDIR PILHA EM 2 PILHAS");
    printf("\n\t13. JUNTAR DUAS FILAS NUMA TERCEIRA");
    printf("\n\t14. SAIR");
}

int main()
{
    // Declaração de variáveis:
    TPilha pilha;
    TFila fila;
    TLista lista;
    TProduto Item;

    // Inicialização da lista
    FPVazia(&pilha);
    FLVazia(&lista);
    FFVazia(&fila);

    int opcao = 0;
    do
    {
        system("cls");
        MSG_MENU();
        printf("\n***********************************************");
        printf("\n\tDIGITE UMA OPCAO:");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            LerProduto(&Item);
            Inserir(Item, &lista);
            printf("\n\n >>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<");
            printf("\n\n");
            system("PAUSE");
            break;
        case 2:
            system("cls");
            LerProduto(&Item);
            Enfileirar(Item, &fila);
            printf("\n\n >>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<");
            printf("\n\n");
            system("PAUSE");
            break;
        case 3:
            system("cls");
            LerProduto(&Item);
            Empilhar(Item, &pilha);
            printf("\n\n >>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<");
            printf("\n\n");
            system("PAUSE");
            break;

        case 4:
            /* INVERTER PILHA COM FILA */
            system("cls");
            TFila aFila;
            FFVazia(&aFila);
            printf("\n\t>>>>>>>>>>  ANTES: <<<<<<<<<");
            while(!PVazia(pilha))
            {
                Desempilhar(&pilha, &Item);
                ImprimirProduto(Item);
                Enfileirar(Item,&aFila);
            }
            printf("\n\t>>>>>>>>  DEPOIS:  <<<<<<<<<");
            while(!FVazia(aFila))
            {
                Desenfileirar(&aFila,&Item);
                Empilhar(Item,&pilha);

            }
            ImprimirPilha(pilha);
            printf("\n\n");
            system("PAUSE");
            break;

        case 5:
            /* INVERTER FILA COM PILHA */
            system("cls");
            TPilha aPilha;
            FPVazia(&aPilha);
            printf("\n\t>>>>>>>>>>  ANTES: <<<<<<<<<");
            while(!FVazia(fila))
            {
                Desenfileirar(&fila, &Item);
                ImprimirProduto(Item);
                Empilhar(Item,&aPilha);
            }
            printf("\n\t>>>>>>>>  DEPOIS:  <<<<<<<<<");
            while(!PVazia(aPilha))
            {
                Desempilhar(&aPilha,&Item);
                Enfileirar(Item,&fila);

            }
            ImprimirFila(fila);
            printf("\n\n");
            system("PAUSE");
            break;

       case 6:
            /* LISTA COM PILHA */
            system("cls");
            TCelula *Aux1, *Aux2;
            TPilha auxP;
            FPVazia(&auxP);
            Aux1 = LPesquisar(lista, Item);
            printf("\n\t>>>>>>>> ANTES <<<<<<<<<<");
            ImprimirLista(lista);
            if(Aux1 != NULL)
            {
                Aux2 = Aux1->prox;
                Aux1->prox = Aux2 -> prox;
                Item = Aux2->item;
                Empilhar(Item,&auxP);
                if (Aux1->prox == NULL)
                    lista.ultimo = Aux1;
                //free(Aux2);
                lista.tamanho--;
            }
            printf("\n\t>>>>>>>>> DEPOIS <<<<<<<<<<<<<<");
            while(PVazia(auxP))
            {
                Desempilhar(&auxP,&Item);
                Inserir(Item,&lista);
            }
            ImprimirLista(lista);
            printf("\n\n");
            system("PAUSE");
            break;

        case 7:
            /*  EXCLUIR ITEM FILA */
            system("cls");
            printf("\n***********************************************");
            Desenfileirar(&fila,&Item);
            printf("\n\tOBJETO EXCLUIDO COM SUCESSO!");
            ImprimirProduto(Item);
            printf("\n\n");
            system("PAUSE");
            break;


        case 8:
            /*  EXCLUIR ITEM PILHA  */
            system("cls");
            printf("\n***********************************************");
            Desempilhar(&pilha,&Item);
            printf("\n\tOBJETO EXCLUIDO COM SUCESSO!");
            ImprimirProduto(Item);
            printf("\n\n");
            system("PAUSE");
            break;

        case 9:
            /*  IMPRIMIR LISTA*/
            system("cls");
            printf("\n***********************************************");
            if(LVazia(lista))
                printf("\n\tA LISTA ESTA VAZIA!!!");
            else
                ImprimirLista(lista);
            printf("\n\n");
            system("PAUSE");
            break;
        case 10:
            /*  IMPRIMIR FILA*/
            system("cls");
            printf("\n***********************************************");
            if(FVazia(fila))
                printf("\n\tA FILA ESTA VAZIA!!!");
            else
                ImprimirFila(fila);
            printf("\n\n");
            system("PAUSE");
            break;
        case 11:
            /*  IMPRIMIR PILHA*/
            system("cls");
            printf("\n***********************************************");
            if(PVazia(pilha))
                printf("\n\tA PILHA ESTA VAZIA!!!");
            else
                ImprimirPilha(pilha);
            printf("\n\n");
            system("PAUSE");
            break;

        case 12:
            system("cls");
            TPilha a1, a2;
            int cont = 2;
            FPVazia(&a1);
            FPVazia(&a2);
            if(PVazia(pilha))
                printf("\n\t PILHA VAZIA!!!!");
            else
            {
                printf("\n\t >>>>>> PILHA COMPLETA <<<<<<<<<");
                ImprimirPilha(pilha);
                while(!PVazia(pilha))
                {
                    if(cont%2 ==0)
                    {
                        Desempilhar(&pilha,&Item);
                        Empilhar(Item,&a2);
                        cont++;
                    }
                    else
                    {
                        Desempilhar(&pilha,&Item);
                        Empilhar(Item,&a1);
                        cont++;
                    }
                }
                printf("\n\t >>>>>>>>>>> PILHA DIVIDIDA <<<<<<<<<<<\n");
                printf("\n\t >>>>>>>>>>>      P1     <<<<<<<<<<<<<<<\n");
                ImprimirPilha(a2);
                printf("\n\t >>>>>>>>>>>      P2     <<<<<<<<<<<<<<<\n");
                ImprimirPilha(a1);
            }

            system("PAUSE");
            break;

        case 13:
            system("cls");
            TFila f1,f2,f3;
            int j = 0;
            FFVazia(&f1);
            FFVazia(&f2);
            FFVazia(&f3);
            printf("\n\t >>>>>>>>>> INSERINDO 3 ELEMENTOS NA PRIMEIRA FILA <<<<<<<<<<\n" );
            for(int i=0; i<3; i++)
            {
                LerProduto(&Item);
                Enfileirar(Item,&f1);
            }

            printf("\n\t >>>>>>>>>> INSERINDO 3 ELEMENTOS NA SEGUNDA FILA <<<<<<<<<<\n" );
            for(int i=0; i<3; i++)
            {
                LerProduto(&Item);
                Enfileirar(Item,&f2);
            }

            for(int i=0; i<3; i++)
            {
                Desenfileirar(&f1,&Item);
                Enfileirar(Item,&f3);
                Desenfileirar(&f2,&Item);
                Enfileirar(Item,&f3);
            }
            printf("\n\t >>>>>>>>>>> RESULTADO <<<<<<<<<<<<\n");
            ImprimirFila(f3);

            system("PAUSE");
            break;
        case 14:
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
    }
    while(opcao != 6);

    return 0;
}
