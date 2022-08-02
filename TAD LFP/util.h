#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

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

void LerProduto(TProduto *item);
void ImprimirProduto(TProduto item);

#endif // UTIL_H_INCLUDED
