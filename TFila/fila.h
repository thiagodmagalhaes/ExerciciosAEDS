#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct produto{
    int codigo;
    char nome[100];
    char descricao[100];
    double preco;
    int unidade;
} TProduto;

typedef struct celula{
    TProduto item;
    struct celula *prox;
} TCelula;


typedef struct {
  TCelula *frente;
  TCelula *tras;
  int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int FVazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TFila *Fila,TProduto *Item);

void ImprimirFila(TFila Fila);

void ImprimirProduto(TProduto Item);

int Pesquisar(TFila Fila,TProduto Item);

void AlteraF(TFila Fila, TProduto Item);

void LerProduto(TProduto *item);





#endif // FILA_H_INCLUDED
