#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "util.h"



typedef struct {
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;

void FLVazia(TLista *Lista);

int LVazia(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

TCelula* LPesquisar(TLista Lista, TProduto Item);

void LLiberar(TLista *Lista);

void Excluir(TLista *Lista, TProduto *Item);

void ImprimirLista(TLista Lista);




#endif // LISTAS_H_INCLUDED
