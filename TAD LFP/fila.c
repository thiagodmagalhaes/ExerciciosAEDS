#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "util.h"

// passagem por referência: alteração será permanente!

void FFVazia(TFila *Fila)
{
    Fila->frente =
        (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int FVazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item)
{
    TCelula* aux;
    if (!FVazia(*Fila))
    {
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
    else
        printf("\n\tFILA VAZIA!!!");
}

void ImprimirFila(TFila Fila)
{
    TFila auxFila;
    TProduto auxItem;
    FFVazia(&auxFila);

    while(!FVazia(Fila))
    {
        Desenfileirar(&Fila,&auxItem);
        ImprimirProduto(auxItem);
        Enfileirar(auxItem, &auxFila);
    }

     while(!FVazia(auxFila))
    {
        Desenfileirar(&auxFila,&auxItem);
        Enfileirar(auxItem,&Fila);
    }

    free(auxFila.frente);

}

int FPesquisar(TFila Fila, TProduto Item)
{
    int retorno=-1;
    TProduto auxItem;
    TFila auxFila;
    FFVazia(&auxFila);

    if(FVazia(Fila))
    {
        retorno = 0;
        return retorno;
    }
    else
    {
        while(!FVazia(Fila))
        {
            Desenfileirar(&Fila,&auxItem);
            if(auxItem.codigo == Item.codigo)
                retorno =1;
            Enfileirar(auxItem,&auxFila);
        }

        while(!FVazia(auxFila))
        {
            Desenfileirar(&auxFila,&auxItem);
            Enfileirar(auxItem,&Fila);
        }
    free(&auxFila.frente);
    }
    return retorno;
}

void AlteraF(TFila Fila, TProduto Item)
{
    TProduto auxItem;
    TFila auxFila;
    FFVazia(&auxFila);

    while(!FVazia(Fila))
    {
        Desenfileirar(&Fila,&auxItem);
        if(auxItem.codigo == Item.codigo)
        {
            LerProduto(&auxItem);

        }

        Enfileirar(auxItem,&auxFila);
    }

    while(!FVazia(auxFila))
    {
        Desenfileirar(&auxFila,&auxItem);
        Enfileirar(auxItem,&Fila);
    }
    free(&auxFila.frente);
    printf("\n\tPRODUTO ALTERADO COM SUCESSO!!!!");
}


