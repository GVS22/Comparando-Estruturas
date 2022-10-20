#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

struct RecRedblack
{
    float chave;
    int value;
};

struct ArvoreRedblack
{
    RecRedblack reg;
    ArvoreRedblack *dir, *esq;
    ArvoreRedblack *pai;
    bool cor;
};

ArvoreRedblack *CriaArvoreRedblack();

void iniciaArvoreRedblack(ArvoreRedblack **t);

ArvoreRedblack *tree_minimum(ArvoreRedblack *auxiliar);

void inserirArvoreRedblack(ArvoreRedblack **t, RecRedblack r);

void insertFixUp(ArvoreRedblack **raiz, ArvoreRedblack *filho);

void ArvoreRedblack_insert(ArvoreRedblack **t, ArvoreRedblack *x, ArvoreRedblack *y, ArvoreRedblack *temp);

void removerArvoreRedblack(ArvoreRedblack **t, ArvoreRedblack *z, ArvoreRedblack *y, ArvoreRedblack *x);

void transplantArvoreRedblack(ArvoreRedblack **t, ArvoreRedblack *temp, ArvoreRedblack *tempFilho);

void removerFixUpArvoreRedblack(ArvoreRedblack **t, ArvoreRedblack *x, ArvoreRedblack *w);

void pesquisaRedblack(ArvoreRedblack **t, ArvoreRedblack **aux, RecRedblack r);

void pesquisaRedblackRemover(ArvoreRedblack **t, ArvoreRedblack *aux, RecRedblack r);

void rotacaoSimplesEsquerda(ArvoreRedblack **raiz, ArvoreRedblack *filho);

void rotacaoSimplesDireita(ArvoreRedblack **raiz, ArvoreRedblack *filho);



#endif