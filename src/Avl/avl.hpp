#ifndef AVL_HPP
#define AVL_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct RecAVL
{
    float chave;
    int value;
};

struct ArvoreAVL
{
    RecAVL reg;
    ArvoreAVL *dir, *esq;
    int ID;
};

ArvoreAVL *CriaArvoreAVL();

void inserirArvoreAVL(ArvoreAVL **t, RecAVL r);

void removerArvoreAVL(ArvoreAVL **t, ArvoreAVL **f, RecAVL r);

void pesquisaAVL(ArvoreAVL **t, ArvoreAVL **aux, RecAVL r);

int isInArvoreAVL(ArvoreAVL *t, RecAVL r);

void antecessor(ArvoreAVL **t, ArvoreAVL *aux);

void rebalanceArvore(ArvoreAVL **t);

int getID(ArvoreAVL **t);

int getMaxID(int left, int right);

void rotacaoSimplesDireita(ArvoreAVL **t);

void rotacaoSimplesEsquerda(ArvoreAVL **t);

void rotacaoDuplaDireita(ArvoreAVL **t);

void rotacaoDuplaEsquerda(ArvoreAVL **t);

#endif