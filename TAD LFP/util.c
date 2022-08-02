#include "util.h"
#include <stdlib.h>
#include <stdio.h>

void LerProduto(TProduto *item)
{
    printf("\n\tDIGITE O CODIGO DO PRODUTO: ");
    fflush(stdin);
    scanf("%d", &item->codigo);

    printf("\tDIGITE O NOME DO PRODUTO: ");
    fflush(stdin);
    fgets(item->nome,100,stdin);

    printf("\tDIGITE A DESCRICAO DO PRODUTO: ");
    fflush(stdin);
    fgets(item->nome,100,stdin);

    printf("\tDIGITE O PRECO DO PRODUTO: ");
    fflush(stdin);
    scanf("%lf", &item->preco);

    printf("\tDIGITE O NUMERO DE UNIDADES DO PRODUTO: ");
    fflush(stdin);
    scanf("%d", &item->unidade);

}

void ImprimirProduto(TProduto item)
{
    printf("\n\t CODIGO do produto: %d", item.codigo);
    printf("\n\t NOME do produto: %s", item.nome);
    printf("\tDESCRICAO do produto: %s", item.descricao);
    printf("\n\t PRECO do produto: %.2f", item.preco);
    printf("\n\t UNIDADE do produto: %d", item.unidade);
    printf("\n");
}
