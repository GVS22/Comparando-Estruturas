#include "avl.hpp"

ArvoreAVL *CriaArvoreAVL()
{

    return NULL;
}

void inserirArvoreAVL(ArvoreAVL **t, RecAVL r)
{

    if (*t == NULL)
    {

        *t = (ArvoreAVL *)malloc(sizeof(ArvoreAVL));

        (*t)->esq = NULL;

        (*t)->dir = NULL;

        (*t)->ID = 0;

        (*t)->reg = r;
    }
    else
    {

        if (r.chave < (*t)->reg.chave)
        {

            inserirArvoreAVL(&(*t)->esq, r);

            if ((getID(&(*t)->esq) - getID(&(*t)->dir)) == 2)
            {

                if (r.chave < (*t)->esq->reg.chave)

                    rotacaoSimplesDireita(t);
                else

                    rotacaoDuplaDireita(t);
            }
        }

        if (r.chave > (*t)->reg.chave)
        {

            inserirArvoreAVL(&(*t)->dir, r);

            if ((getID(&(*t)->dir) - getID(&(*t)->esq)) == 2)
            {

                if (r.chave > (*t)->dir->reg.chave)

                    rotacaoSimplesEsquerda(t);

                else

                    rotacaoDuplaEsquerda(t);
            }
        }
    }

    (*t)->ID = getMaxID(getID(&(*t)->esq), getID(&(*t)->dir)) + 1;
}

void pesquisaAVL(ArvoreAVL **t, ArvoreAVL **aux, RecAVL r)
{

    if (*t == NULL)
    {

        return;
    }

    if ((*t)->reg.chave > r.chave)
    {
        pesquisaAVL(&(*t)->esq, aux, r);
        return;
    }

    if ((*t)->reg.chave < r.chave)
    {
        pesquisaAVL(&(*t)->dir, aux, r);
        return;
    }

    *aux = *t;
}

int isInArvoreAVL(ArvoreAVL *t, RecAVL r)
{

    if (t == NULL)
    {

        return 0;
    }

    return t->reg.chave == r.chave || isInArvoreAVL(t->esq, r) || isInArvoreAVL(t->dir, r);
}

void antecessor(ArvoreAVL **t, ArvoreAVL *aux)
{

    if ((*t)->dir != NULL)
    {

        antecessor(&(*t)->dir, aux);

        return;
    }

    aux->reg = (*t)->reg;

    aux = *t;

    *t = (*t)->esq;

    free(aux);
}

void rebalanceArvore(ArvoreAVL **t)
{
    int balance;

    int esq = 0;

    int dir = 0;

    balance = getID(&(*t)->esq) - getID(&(*t)->dir);

    if ((*t)->esq)
    {

        esq = getID(&(*t)->esq->esq) - getID(&(*t)->esq->dir);
    }

    if ((*t)->dir)
    {

        dir = getID(&(*t)->dir->esq) - getID(&(*t)->dir->dir);
    }

    if (balance == 2 && esq >= 0)

        rotacaoSimplesDireita(t);

    if (balance == 2 && esq < 0)

        rotacaoDuplaDireita(t);

    if (balance == -2 && dir <= 0)

        rotacaoSimplesEsquerda(t);

    if (balance == -2 && dir > 0)

        rotacaoDuplaEsquerda(t);
}
void removerArvoreAVL(ArvoreAVL **t, ArvoreAVL **f, RecAVL r)
{

    ArvoreAVL *aux;

    if (*t == NULL)
    {

        return;
    }

    if (r.chave < (*t)->reg.chave)
    {
        removerArvoreAVL(&(*t)->esq, t, r);
        return;
    }

    if (r.chave > (*t)->reg.chave)
    {
        removerArvoreAVL(&(*t)->dir, t, r);
        return;
    }

    if ((*t)->dir == NULL)
    {
        aux = *t;

        *t = (*t)->esq;

        free(aux);

        return;

        rebalanceArvore(f);
    }

    if ((*t)->esq != NULL)
    {

        antecessor(&(*t)->esq, *t);

        rebalanceArvore(f);

        rebalanceArvore(t);

        return;
    }

    aux = *t;

    *t = (*t)->dir;

    free(aux);

    rebalanceArvore(f);

    rebalanceArvore(t);
}

int getID(ArvoreAVL **t)
{

    if (*t == NULL)

        return -1;

    return (*t)->ID;
}

int getMaxID(int esq, int dir)
{

    if (esq > dir)

        return esq;

    return dir;
}

void rotacaoSimplesDireita(ArvoreAVL **t)
{

    ArvoreAVL *aux;

    aux = (*t)->esq;

    (*t)->esq = aux->dir;

    aux->dir = (*t);

    (*t)->ID = getMaxID(getID(&(*t)->esq), getID(&(*t)->dir)) + 1;

    aux->ID = getMaxID(getID(&aux->esq), (*t)->ID) + 1;

    (*t) = aux;
}

void rotacaoSimplesEsquerda(ArvoreAVL **t)
{

    ArvoreAVL *aux;

    aux = (*t)->dir;

    (*t)->dir = aux->esq;

    aux->esq = (*t);

    (*t)->ID = getMaxID(getID(&(*t)->esq), getID(&(*t)->dir)) + 1;

    aux->ID = getMaxID(getID(&aux->esq), (*t)->ID) + 1;

    (*t) = aux;
}

void rotacaoDuplaDireita(ArvoreAVL **t)
{

    rotacaoSimplesEsquerda(&(*t)->esq);

    rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(ArvoreAVL **t)
{

    rotacaoSimplesDireita(&(*t)->dir);

    rotacaoSimplesEsquerda(t);
}