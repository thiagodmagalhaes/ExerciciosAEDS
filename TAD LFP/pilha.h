#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "util.h"


typedef struct
{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int PVazia(TPilha Pilha);

void Empilhar(TProduto x,TPilha *Pilha);

void Desempilhar(TPilha *Pilha,TProduto *Item);

void PImprimirProduto(Item);

void ImprimirPilha(TPilha Pilha);

void PLiberar(TPilha *Pilha);

int PTamanho(TPilha Pilha);

void PAltera(TPilha Pilha, TProduto Item);

int PPesquisar(pilha,Item);







#endif // PILHA_H_INCLUDED
