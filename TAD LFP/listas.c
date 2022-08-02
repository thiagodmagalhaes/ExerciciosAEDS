#include <stdlib.h>
#include <stdio.h>
#include "listas.h"
#include "util.h"

// passagem por referência: alteração será permanente!
void FLVazia(TLista *Lista)
{
  Lista -> primeiro =(TCelula *) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> primeiro;
  Lista -> primeiro -> prox = NULL;
  Lista -> tamanho = 0;
}

// passagem de parâmetro por valor: a alteração NÃO é permanente!
int LVazia(TLista Lista)
{
  return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista)
{
  Lista -> ultimo -> prox =(TCelula *) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> ultimo -> prox;
  Lista -> ultimo -> item = x;
  Lista -> ultimo -> prox = NULL;
  Lista -> tamanho++;
}

TCelula* LPesquisar(TLista Lista, TProduto Item)
{
   TCelula* Aux;
   Aux = Lista.primeiro;
   while(Aux->prox != NULL){
      if(strcmp(Aux->prox->item.nome,Item.nome)==0)
         return Aux;
      Aux = Aux->prox;
   }
   return NULL;
}

void Excluir(TLista *Lista, TProduto *Item)
{
  /* Obs.: o item a ser retirado e o apontado por Aux1 */
  TCelula *Aux1, *Aux2;
  Aux1 = LPesquisar(*Lista, *Item);
  if (Aux1 != NULL) {
     Aux2 = Aux1->prox;
     Aux1->prox = Aux2 -> prox;
     *Item = Aux2->item;
     if (Aux1->prox == NULL)
        Lista->ultimo = Aux1;
     free(Aux2);
     Lista->tamanho--;
  }
}

void ImprimirLista(TLista Lista)
{
  TCelula* Aux;
  Aux = Lista.primeiro -> prox;
  while (Aux != NULL){
    printf("\n");
    ImprimirProduto(Aux->item);
    Aux = Aux -> prox;
  }
}


/*
void LLiberar(TLista *Lista)
{
    while (Lista->primeiro->prox != NULL)
    {
        free(Lista->)
    }
    TProduto Item;
    while(!FLVazia(*Lista))
    {
        Desempilhar(Lista, &Item);
    }
    free(Pilha->topo);
}*/


