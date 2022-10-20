# Comparando Estruturas

</p>
Trabalho realizado para a disciplina de Algoritmos e Estrutura de Dados 2 \
CEFET - MG Campus V \
Gabriel Vitor Silva 


## Compilar ##
```
make clean
make
make run
```
# Problema
 Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) - Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2) - Qual o tempo necessário para montar a estrutura em memória. 

3) - Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4) - Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?
 About
=====
 
 O método de compressão de Huffman usa as probabilidades de ocorrência dos símbolos no conjunto de dados a ser compactado para determinar palavras de código binário, de tamanho variável, para representar cada símbolo. Este programa segue exatamente o algoritmo de Huffman. Ele lê palavras frequentes do arquivo de entrada e os substitui por uma palavra de código binária.
 
 ## Desenvolvimento: #
 
 # parte 1 
 
Para contabilizar a recorrencia de cada palavra, declarei um map com uma string para cada palavra e um float para sua frequencia e com um loop e uma regra para armazenar todas as palavras menos os simbolos:

```
 while (file >> palavra)
    {

        palavra.erase(remove_if(palavra.begin(), palavra.end(), ::ispunct), palavra.end());
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        
        frequencia[palavra]++;
        contPalavras++;
    }

```

 # parte 2
 
 Para normalizar as frequencias das palavras, e amarzenar na struct Arvore e depois colocado na fila de prioridade:
 
 
```
for (auto item : frequencia)
    {
        cout << "palavra: " << item.first << " | Frequencia: " << item.second << endl;
        item.second /= contPalavras;

        Arvore *no = new Arvore(item.first, item.second);
        fila.push(no);
    }
```

 # parte 3
 
 Para criar a Arvore de huffman foi chamada a fila e foi montando arvore por arvore ate reduzir a arvore inteira:
 
 
```
while (fila.size() != 1)
    {
        Arvore *esq = fila.top();
        fila.pop();
        Arvore *dir = fila.top();
        fila.pop();
        Arvore *no = new Arvore("$", esq->frequencia + dir->frequencia);
        no->esq = esq;
        no->dir = dir;
        fila.push(no);
    }
    arvoreHuffman = fila.top();
```

# parte 4
 
 Para trocar as palavras por codigo foi pego o codigo em cada palavra e armazenado em uma variavel global tipo map de string e bool, no final da função: 
 
 
```
void imprimirArvore(Arvore *arvoreHuffman, vector<bool> codigo, int altura)
{
    if (arvoreHuffman->esq)
    {
        codigo.insert(codigo.begin(), false);
        imprimirArvore(arvoreHuffman->esq, codigo, altura + 1);
    }
    if (arvoreHuffman->dir)
    {
        codigo.insert(codigo.begin(), true);
        imprimirArvore(arvoreHuffman->dir, codigo, altura + 1);
    }
    if (!arvoreHuffman->esq && !arvoreHuffman->dir)
    {
        pair<string, vector<bool>> aux;
        aux.second.clear();
        aux.first = arvoreHuffman->palavra;
        cout <<"palavra: "<< arvoreHuffman->palavra << " Codigo: ";

        for (int i = 0; i < altura; i++)
        {
            cout << codigo.at(i);
            aux.second.push_back(codigo.at(i));
        }
        cout << endl;
        gTradutor.insert(aux);
    }
}
```

# parte 5
 
para converter o arquivo original em um arquivo binario foi usado as seguintes funções: 
 
 
```
void textoVector(vector<string> *vectorPalavra)
{

    string palavra;
    ifstream file("src/arquivo.txt");
    while (file >> palavra)
        vectorPalavra->push_back(palavra);

    file.close();
}

void convertBinary(vector<string> vectorPalavra)
{
    ofstream file("src/binary.bin", ios::out | ios::binary);
    if (!file.good())
    {
        cout << "Cannot open file!" << endl;
        return;
    }
    string textoAux;
    map<string, vector<bool>>::iterator it;
    for (auto item : vectorPalavra)
    {
        textoAux.assign("");
        it = gTradutor.find(item);
        if (it != gTradutor.end())
        {
            for (auto i : it->second)
                textoAux.append(to_string(i));
            file.write(textoAux.c_str(), (textoAux.size()));
        }
    }

    file.close();
}
```
Nao houve nenhuma ganho de espaço, o arquivo binario ficou maior que o original, acredito que se deve ao fato que o algoritimo de hullman foi usado em palavras e ele é originalmente pensado para ser usado em caracteres como por exemplo:

![image](https://user-images.githubusercontent.com/54191675/192070056-08857b62-196a-45c8-b2c0-898317eb8a1c.png)


## Saida ## 
O leitor deve esperar de saida as palavras e sua codificação:

![image](https://user-images.githubusercontent.com/54191675/192070372-0faff0cb-ab4d-4651-9667-a8da2c77e05d.png)

e que seu arquivo original, o texto "A arte da guerra" tenha convertido para binario no arquivo binary.dat.

![image](https://user-images.githubusercontent.com/54191675/192070462-750f49eb-1dd9-4b03-8f6c-bca9b91738eb.png)

