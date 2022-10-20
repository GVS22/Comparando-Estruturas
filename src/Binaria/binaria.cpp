#include "binaria.hpp"

ArvoreBinaria *CriaArvoreBinaria()
{

    return nullptr;
}

bool ArvoreBinariaVazia(ArvoreBinaria **t)
{

    return *t == nullptr;
}

void inserirArvoreBinaria(ArvoreBinaria **t, RecBinaria r)
{

    if (ArvoreBinariaVazia(t))
    {

        *t = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));

        (*t)->esq = nullptr;

        (*t)->dir = nullptr;

        (*t)->reg = r;
    }
    else
    {

        if (r.chave < (*t)->reg.chave)
        {

            inserirArvoreBinaria(&(*t)->esq, r);
        }

        if (r.chave > (*t)->reg.chave)
        {

            inserirArvoreBinaria(&(*t)->dir, r);
        }
    }
}

void pesquisaBinaria(ArvoreBinaria **t, ArvoreBinaria **aux, RecBinaria r)
{

    if (*t == nullptr)
    {

     

        return;
    }

    if ((*t)->reg.chave > r.chave)
    {
        pesquisaBinaria(&(*t)->esq, aux, r);
        return;
    }

    if ((*t)->reg.chave < r.chave)
    {
        pesquisaBinaria(&(*t)->dir, aux, r);
        return;
    }

    *aux = *t;
}

int isInArvoreBinariaBinaria(ArvoreBinaria *t, RecBinaria r)
{

    if (t == nullptr)
    {

        return 0;
    }

    return t->reg.chave == r.chave || isInArvoreBinariaBinaria(t->esq, r) || isInArvoreBinariaBinaria(t->dir, r);
}

void antecessor(ArvoreBinaria **t, ArvoreBinaria *aux)
{

    if ((*t)->dir != nullptr)
    {

        antecessor(&(*t)->dir, aux);

        return;
    }

    aux->reg = (*t)->reg;

    aux = *t;

    *t = (*t)->esq;

    free(aux);
}

void removerArvoreBinaria(ArvoreBinaria **t, RecBinaria r)
{

    ArvoreBinaria *aux;

    if (*t == nullptr)
    {


        return;
    }

    if (r.chave < (*t)->reg.chave)
    {
        removerArvoreBinaria(&(*t)->esq, r);
        return;
    }

    if (r.chave > (*t)->reg.chave)
    {
        removerArvoreBinaria(&(*t)->dir, r);
        return;
    }

    if ((*t)->dir == nullptr)
    {

        aux = *t;

        *t = (*t)->esq;

        free(aux);

        return;
    }

    if ((*t)->esq != nullptr)
    {
        antecessor(&(*t)->esq, *t);
        return;
    }

    aux = *t;

    *t = (*t)->dir;

    free(aux);
}
