#include "redblack.hpp"

ArvoreRedblack *temp, *vazio;

void iniciaArvoreRedblack(ArvoreRedblack **t)
{

    vazio = (ArvoreRedblack *)malloc(sizeof(ArvoreRedblack));

    vazio->cor = true;

    vazio->esq = NULL;

    vazio->dir = NULL;

    vazio->pai = NULL;

    vazio->reg.chave = 0;

    (*t) = vazio;
}

void insertFixUp(ArvoreRedblack **raiz, ArvoreRedblack *filho)
{

    ArvoreRedblack *tio;

    while ((filho != *raiz) && (filho->pai->cor == false))
    {

        if (filho->pai == filho->pai->pai->esq)
        {

            tio = filho->pai->pai->dir;

            if ((tio != NULL) && (tio->cor == false))
            {

                filho->pai->cor = true;

                tio->cor = true;

                filho->pai->pai->cor = false;

                filho = filho->pai->pai;
            }
            else
            {

                if (filho == filho->pai->dir)
                {

                    filho = filho->pai;

                    rotacaoSimplesEsquerda(raiz, filho);
                }

                filho->pai->cor = true;

                filho->pai->pai->cor = false;

                rotacaoSimplesDireita(raiz, filho->pai->pai);
            }
        }
        else
        {

            tio = filho->pai->pai->esq;

            if ((tio != NULL) && (tio->cor == false))
            {

                filho->pai->cor = true;

                tio->cor = true;

                filho->pai->pai->cor = false;

                filho = filho->pai->pai;
            }
            else
            {

                if (filho == filho->pai->esq)
                {

                    filho = filho->pai;

                    rotacaoSimplesDireita(raiz, filho);
                }

                filho->pai->cor = true;

                filho->pai->pai->cor = false;

                rotacaoSimplesEsquerda(raiz, filho->pai->pai);
            }
        }
    }

    (*raiz)->cor = true;
}

void inserirArvoreRedblack(ArvoreRedblack **t, RecRedblack r)
{

    if ((temp = (ArvoreRedblack *)malloc(sizeof(ArvoreRedblack))) != NULL)
    {

        temp->pai = vazio;

        temp->esq = vazio;

        temp->dir = vazio;

        temp->reg = r;

        temp->cor = true;

        ArvoreRedblack_insert(t, *t, vazio, temp);
    }
}

void ArvoreRedblack_insert(ArvoreRedblack **t, ArvoreRedblack *x, ArvoreRedblack *y, ArvoreRedblack *temp)
{

    while (x != vazio)
    {

        y = x;

        if (temp->reg.chave < x->reg.chave)

            x = x->esq;

        else

            x = x->dir;
    }

    temp->pai = y;

    if (y == vazio)

        (*t) = temp;

    else if (temp->reg.chave < y->reg.chave)

        y->esq = temp;

    else

        y->dir = temp;

    temp->esq = vazio;

    temp->dir = vazio;

    temp->cor = false;

    insertFixUp(t, temp);
}

void pesquisaRedblack(ArvoreRedblack **t, ArvoreRedblack **aux, RecRedblack r)
{

    if (*t == NULL)
    {

       

        return;
    }

    if ((*t)->reg.chave > r.chave)
    {
        pesquisaRedblack(&(*t)->esq, aux, r);
        return;
    }

    if ((*t)->reg.chave < r.chave)
    {
        pesquisaRedblack(&(*t)->dir, aux, r);
        return;
    }

    *aux = *t;
}

void rotacaoSimplesEsquerda(ArvoreRedblack **raiz, ArvoreRedblack *filho)
{

    ArvoreRedblack *x, *y;

    x = filho;

    y = filho->dir;

    x->dir = y->esq;

    if (y->esq != vazio)

        y->esq->pai = x;

    y->pai = x->pai;

    if (x->pai == vazio)

        *raiz = y;

    else
    {

        if (x == x->pai->esq)

            x->pai->esq = y;

        else if (x == x->pai->dir)

            x->pai->dir = y;
    }

    y->esq = x;

    x->pai = y;
}

void rotacaoSimplesDireita(ArvoreRedblack **raiz, ArvoreRedblack *filho)
{

    ArvoreRedblack *x, *y;

    x = filho;

    y = filho->esq;

    x->esq = y->dir;

    if (y->dir != vazio)

        y->dir->pai = x;

    y->pai = x->pai;

    if (x->pai == vazio)
    {

        *raiz = y;
    }

    else
    {

        if (x == x->pai->dir)

            x->pai->dir = y;

        else if (x == x->pai->esq)

            x->pai->esq = y;
    }

    y->dir = x;

    x->pai = y;
}




ArvoreRedblack *tree_minimum(ArvoreRedblack *auxiliar)
{

    while (auxiliar->esq != vazio)

        auxiliar = auxiliar->esq;

    return auxiliar;
}

void removerArvoreRedblack(ArvoreRedblack **t, ArvoreRedblack *z, ArvoreRedblack *y, ArvoreRedblack *x)
{

    y = z;

    bool corOriginal = y->cor;

    if (z->esq == vazio)
    {

        x = z->dir;

        transplantArvoreRedblack(t, z, z->dir);
    }

    else if (z->dir == vazio)
    {

        x = z->esq;

        transplantArvoreRedblack(t, z, z->esq);
    }
    else
    {

        y = tree_minimum(z->dir);

        corOriginal = y->cor;

        x = y->dir;

        if (y->pai == z)

            x->pai = y;
        else
        {

            transplantArvoreRedblack(t, y, y->dir);

            y->dir = z->dir;

            y->dir->pai = y;
        }

        transplantArvoreRedblack(t, z, y);

        y->esq = z->esq;

        y->esq->pai = y;

        y->cor = z->cor;
    }
    if (corOriginal == true)

        removerFixUpArvoreRedblack(t, x, x);

    free(z);
}

void transplantArvoreRedblack(ArvoreRedblack **t, ArvoreRedblack *temp, ArvoreRedblack *tempFilho)
{

    if (temp->pai == vazio)
    {

        (*t) = tempFilho;
    }

    else if (temp == temp->pai->esq)
    {

        temp->pai->esq = tempFilho;
    }

    else

        temp->pai->dir = tempFilho;

    tempFilho->pai = temp->pai;
}

void removerFixUpArvoreRedblack(ArvoreRedblack **t, ArvoreRedblack *x, ArvoreRedblack *w)
{

    while (x != (*t) && x->cor == true)
    {

        if (x == x->pai->esq)
        {

            w = x->pai->dir;

            if (w->cor == false)
            {

                w->cor = true;

                x->pai->cor = false;

                rotacaoSimplesEsquerda(t, x->pai);

                w = x->pai->dir;
            }
            else if (w->esq->cor == true && w->dir->cor == true)
            {

                w->cor = false;

                x = x->pai;
            }
            else if (w->dir->cor == true)
            {

                w->esq->cor = true;

                w->cor = false;

                rotacaoSimplesDireita(t, w);

                w = x->pai->dir;
            }
            else
            {

                w->cor = x->pai->cor;

                x->pai->cor = true;

                w->dir->cor = true;

                rotacaoSimplesEsquerda(t, x->pai);

                x = (*t);
            }
        }
        else
        {
            w = x->pai->esq;

            if (w->cor == false)
            {

                w->cor = true;

                x->pai->cor = false;

                rotacaoSimplesDireita(t, x->pai);

                w = x->pai->esq;
            }

            else if (w->dir->cor == true && w->esq->cor == true)
            {

                w->cor = false;

                x = x->pai;
            }

            else if (w->esq->cor == true)
            {

                w->dir->cor = true;

                w->cor = false;

                rotacaoSimplesEsquerda(t, w);

                w = x->pai->esq;
            }

            else
            {
                w->cor = x->pai->cor;

                x->pai->cor = true;

                w->esq->cor = true;

                rotacaoSimplesDireita(t, x->pai);

                x = (*t);
            }
        }
    }
    x->cor = true;
}

void pesquisaRedblackRemover(ArvoreRedblack **t, ArvoreRedblack *aux, RecRedblack r)
{

    while (aux != vazio && r.chave != aux->reg.chave)
    {

        if (r.chave < aux->reg.chave)
        {

            aux = aux->esq;
        }
        else
        {

            aux = aux->dir;
        }
    }
    
    if (aux->reg.chave == r.chave)
    {

        removerArvoreRedblack(t, aux, aux, aux);
    }

    else
    {
    }
}