#ifndef BINARIA_HPP
#define BINARIA_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

struct RecBinaria
{
    float chave;
    int value;
};

struct ArvoreBinaria
{
    RecBinaria reg;
    ArvoreBinaria *dir, *esq;
};

ArvoreBinaria *CriaArvoreBinaria();

bool ArvoreBinariaVazia(ArvoreBinaria **t);

void inserirArvoreBinaria(ArvoreBinaria **t, RecBinaria r);

void removerArvoreBinaria(ArvoreBinaria **t, RecBinaria r);

void pesquisaBinaria(ArvoreBinaria **t, ArvoreBinaria **aux, RecBinaria r);

int isInBinaria(ArvoreBinaria *t, RecBinaria r);

void antecessor(ArvoreBinaria **t, ArvoreBinaria *aux);

#endif