#include "Avl/avl.cpp"
#include "Binaria/binaria.hpp"
#include "RedBlack/redblack.hpp"
#include "QuickSort/quicksort.hpp"
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace chrono;

void lendoArquivos(int tamanho)
{
    map<float, int> Mapa;

    unordered_map<float, int> u_Mapa;

    map<float, int>::iterator iteratorMap;

    unordered_map<float, int>::iterator iteratorMapaDesordenado;

    ArvoreBinaria *raizBinaria = CriaArvoreBinaria();
    RecBinaria r;

    ArvoreAVL *raizAVL = CriaArvoreAVL();
    RecAVL rAVL;

    ArvoreRedblack *raizRedblack;
    RecRedblack recRedblack;

    iniciaArvoreRedblack(&raizRedblack);
    vector<float> ComparaTempo;

    vector<float> values;

    string numero;

    steady_clock::time_point inicio, final;

    float aux;
    double montagemBinaria, montagemAVL, montagemRedblack, montagemMap, montagemMapaDesordenado, montagemVector, montagemOrdem = 0.0;
    double buscaBinaria, buscaAVL, buscaRedblack, buscaMap, buscaMapaDesordenado, buscaVector, buscaOrdem = 0.0;
    double remocaoBinaria, remocaoAVL, remocaoRedblack, remocaoMap, remocaoMapaDesordenado, remocaoVector, remocaoOrdem = 0.0;
    int cont = 0;

    ifstream arquivo;

    arquivo.open("src/files/Dados.txt");

    if (arquivo.is_open())
    {

        while (arquivo >> numero && cont < tamanho)
        {

            cont++;
            aux = stof(numero);

            values.push_back(aux);

            r.chave = rAVL.chave = recRedblack.chave = aux;

            r.value = rAVL.value = recRedblack.value = 1;

            //-----------------------Binaria-------------------------

            inicio = steady_clock::now();
            inserirArvoreBinaria(&raizBinaria, r);
            final = steady_clock::now();
            auto temp = duration_cast<duration<double>>(final - inicio);
            montagemBinaria += (double)temp.count();

            //-----------------------AVL----------------------------

            inicio = steady_clock::now();
            inserirArvoreAVL(&raizAVL, rAVL);
            final = steady_clock::now();
            auto tempAVL = duration_cast<duration<double>>(final - inicio);
            montagemAVL += (double)tempAVL.count();

            //-----------------------RedBlack-------------------------

            inicio = steady_clock::now();
            inserirArvoreRedblack(&raizRedblack, recRedblack);
            final = steady_clock::now();
            auto tempRedblack = duration_cast<duration<double>>(final - inicio);
            montagemRedblack += (double)tempRedblack.count();

            //-----------------------Map----------------------------

            inicio = steady_clock::now();
            Mapa.insert({aux, 1});
            final = steady_clock::now();
            auto tempMap = duration_cast<duration<double>>(final - inicio);
            montagemMap += (double)tempMap.count();

            //-----------------------MapaDesordenado-----------------

            inicio = steady_clock::now();
            u_Mapa.insert({aux, 1});
            final = steady_clock::now();
            auto tempOutroMapa = duration_cast<duration<double>>(final - inicio);
            montagemMapaDesordenado += (double)tempOutroMapa.count();

            //-----------------------Vector-------------------------

            inicio = steady_clock::now();
            ComparaTempo.push_back(aux);
            final = steady_clock::now();
            auto tempVector = duration_cast<duration<double>>(final - inicio);
            montagemVector += (double)tempVector.count();
        }

        inicio = steady_clock::now();
        Quicksort sort(ComparaTempo);
        sort.Sort();
        final = steady_clock::now();
        auto tempOrdenamento = duration_cast<duration<double>>(final - inicio);
        montagemOrdem += (double)tempOrdenamento.count();

        arquivo.close();
    }
    else
    {

        cout << "Arquivo não encontrado." << endl;
    }
    ifstream arquivoDeEntrada;

    arquivoDeEntrada.open("src/files/entrada.txt");

    if (arquivoDeEntrada.is_open())
    {

        while (arquivoDeEntrada >> numero)
        {

            iteratorMap = Mapa.find(aux);

            iteratorMapaDesordenado = u_Mapa.find(aux);

            aux = stof(numero);

            values.push_back(aux);

            r.chave = rAVL.chave = recRedblack.chave = aux;

            r.value = rAVL.value = recRedblack.value = 1;

            //-----------------------Binaria-------------------------

            inicio = steady_clock::now();
            pesquisaBinaria(&raizBinaria, &raizBinaria, r);
            final = steady_clock::now();
            auto temp = duration_cast<duration<double>>(final - inicio);
            buscaBinaria += (double)temp.count();

            inicio = steady_clock::now();
            removerArvoreBinaria(&raizBinaria, r);
            final = steady_clock::now();
            auto tempRemocao = duration_cast<duration<double>>(final - inicio);
            remocaoBinaria += (double)tempRemocao.count();

            //-----------------------AVL----------------------------

            inicio = steady_clock::now();
            pesquisaAVL(&raizAVL, &raizAVL, rAVL);
            final = steady_clock::now();
            auto tempAVL = duration_cast<duration<double>>(final - inicio);
            buscaAVL += (double)tempAVL.count();

            inicio = steady_clock::now();
            removerArvoreAVL(&raizAVL, &raizAVL, rAVL);
            final = steady_clock::now();
            auto tempAVLRemocao = duration_cast<duration<double>>(final - inicio);
            remocaoAVL += (double)tempAVLRemocao.count();

            //-----------------------RedBlack-------------------------

            inicio = steady_clock::now();
            pesquisaRedblack(&raizRedblack, &raizRedblack, recRedblack);
            final = steady_clock::now();
            auto tempRedblack = duration_cast<duration<double>>(final - inicio);
            buscaRedblack += (double)tempRedblack.count();

            inicio = steady_clock::now();
            final = steady_clock::now();
            auto tempRedblackRemocao = duration_cast<duration<double>>(final - inicio);
            remocaoRedblack += (double)tempRedblackRemocao.count();

            //-----------------------Map----------------------------

            inicio = steady_clock::now();
            iteratorMap = Mapa.find(aux);
            final = steady_clock::now();
            auto tempMap = duration_cast<duration<double>>(final - inicio);
            buscaMap += (double)tempMap.count();

            inicio = steady_clock::now();
            iteratorMap = Mapa.find(aux);

            if (iteratorMap != Mapa.end())
            {
                Mapa.erase(iteratorMap);
            }

            final = steady_clock::now();
            auto tempMapRemocao = duration_cast<duration<double>>(final - inicio);
            remocaoMap += (double)tempMapRemocao.count();

            //-----------------------MapaDesordenado-----------------

            inicio = steady_clock::now();
            iteratorMapaDesordenado = u_Mapa.find(aux);
            final = steady_clock::now();
            auto tempMapaDesordenado = duration_cast<duration<double>>(final - inicio);
            buscaMapaDesordenado += (double)tempMapaDesordenado.count();

            inicio = steady_clock::now();
            iteratorMapaDesordenado = u_Mapa.find(aux);

            if (iteratorMapaDesordenado != u_Mapa.end())
            {
                u_Mapa.erase(iteratorMapaDesordenado);
            }

            final = steady_clock::now();
            auto tempOutroMapaRemocao = duration_cast<duration<double>>(final - inicio);
            remocaoMapaDesordenado += (double)tempOutroMapaRemocao.count();

            //-----------------------Vector-------------------------

            inicio = steady_clock::now();
            binary_search(ComparaTempo.begin(), ComparaTempo.end(), aux);
            final = steady_clock::now();
            auto tempVector = duration_cast<duration<double>>(final - inicio);
            buscaVector += (double)tempVector.count();

            inicio = steady_clock::now();
            if (binary_search(ComparaTempo.begin(), ComparaTempo.end(), aux))
            {

                ComparaTempo.erase(lower_bound(ComparaTempo.begin(), ComparaTempo.end(), aux));
            }

            final = steady_clock::now();
            auto tempVectorRemocao = duration_cast<duration<double>>(final - inicio);
            remocaoVector += (double)tempVectorRemocao.count();
        }

        arquivoDeEntrada.close();
    }

    else
    {

        cout << "Arquivo não encontrado." << endl;
    }
    cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
    cout << "+      Tipo         +      Tamanho      +      Inserção     +       Busca       +      Remoção      +" << endl;
    cout << "+-------------------+-------------------+-------------------+-------------------+-------------------+" << endl;
    cout << "+  Árvore Binária   +    " << tamanho << "          |   " << fixed << (double)(montagemBinaria) << " s      |   " << fixed << (double)(buscaBinaria) << " s      |   " << fixed << (double)(remocaoBinaria) << " s" << endl;
    cout << "+---------------------------------------------------------------------------------------------------+" << endl;
    cout << "+     Árvore AVL    +    " << tamanho << "          |   " << fixed << (double)(montagemAVL) << " s      |   " << fixed << (double)(buscaAVL) << " s      |   " << fixed << (double)(remocaoAVL) << " s" << endl;
    cout << "+-------------------+-------------------------------------------------------------------------------+   " << endl;
    cout << "+  Árvore Redblack  +    " << tamanho << "          |   " << fixed << (double)(montagemRedblack) << " s      |   " << fixed << (double)(buscaRedblack) << " s      |   " << fixed << (double)(remocaoRedblack) << " s" << endl;
    cout << "+---------------------------------------------------------------------------------------------------+   " << endl;
    cout << "+         Map       +    " << tamanho << "          |   " << fixed << (double)(montagemMap) << " s      |   " << fixed << (double)(buscaMap) << " s      |   " << fixed << (double)(remocaoMap) << " s" << endl;
    cout << "+----------------------------------------------------------------------------------------------------+" << endl;
    cout << "+  Mapa Desordenado +    " << tamanho << "          |   " << fixed << (double)(montagemMapaDesordenado) << " s      |   " << fixed << (double)(buscaMapaDesordenado) << " s      |   " << fixed << (double)(remocaoMapaDesordenado) << " s" << endl;
    cout << "+----------------------------------------------------------------------------------------------------+" << endl;
    cout << "+        Vector     +    " << tamanho << "          |   " << fixed << (double)(montagemVector) << " s      |   " << fixed << (double)(buscaVector) << " s      |   " << fixed << (double)(remocaoVector) << " s" << endl;
    cout << "+----------------------------------------------------------------------------------------------------+" << endl
         << endl;
}

int main()
{

    int operador = -1;

    while (operador != 0)
    {

        cout << "+---+-----------------------------+" << endl;
        cout << "|[1] | Estruturas com 500 dados   |\n"
             << "|[2] | Estruturas com 5000 dados  |\n"
             << "|[3] | Estruturas com 50000 dados |\n"
             << "|[4] | Estruturas com 500000 dados|\n"
             << "|[0] | SAIR!                      |\n"
             << "+---------------------------------+\n"
             << endl;
        cin >> operador;

        switch (operador)
        {
        case 0:
            cout << "Fim do programa!\n\n";
            break;

        case 1:
            lendoArquivos(500);
            break;

        case 2:
            lendoArquivos(5000);
            break;

        case 3:
            lendoArquivos(50000);
            break;

        case 4:
            lendoArquivos(500000);
            break;

        default:
            break;
        }
    }

    return 0;
}
