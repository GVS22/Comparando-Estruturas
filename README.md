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
  
 ## Estruturas : ##
 
 # Arvore Binaria 
 <p> </p>

<p align="justify">
	Em uma árvore binária, cada elemento é denominado nó da árvore e sua posição na estrutura pode levar a uma de três nomenclaturas. Se o nó é o primeiro inserido, denominamos tal elemento como <b>raiz</b> da árvore. Partindo da <b>raiz</b>, temos por designação dois filhos, <b>filho esquerdo</b> e <b>filho direto</b>. Um filho é posicionado a esquerda, se somente se, seu valor de teste é menor que o valor do nó onde este será conectado. Este nó de conexão é conhecido como <b>nó pai</b>. Por conseguinte, os filhos tidos como direitos seguem a mesma regra, contudo, para valores maiores. Utilizada a [Bynari_Tree](https://github.com/mpiress/basic_tree) como referencia.
</p>

# Arvore AVL
 <p> </p>

<p align="justify">
	Em uma árvore binária do tipo AVL, os nós se mantêm aprocimadamente balanciados. Isso permite que processos de inserção, remoção e pesquisa sejam realizados sob custo computacional de O(logn). 
</p>

<p align="justify">
	Para a realização dos balanceamentos, a AVL modifica o método de inserção da árvore binária, introduzindo nela um procedimento de avaliação de peso e quatro modelos de rotação. Utilizada a [AVL_Tree](https://github.com/mpiress/avl_tree) como referencia.
</p>
# Arvore RedBlack
<p> </p>

<p align="justify">
	Em uma árvore binária do tipo Red Black (RB), os nós se mantêm aprocimadamente balanciados por meio de uma estratégia de cores. Diferente da AVL, em uma RB os nós são avaliados considerando um processo de parentesco, em que vizinhos são considerados e esses devem obedecer certos critérios de cor para indicar que a estrutura se encontra balanceada. Isso permite que processos de inserção, remoção e pesquisa sejam realizados sob custo computacional de O(logn). Utilizada a [RedBlack_Tree](https://github.com/mpiress/RedBlack) como referencia.
 
 # Map
<p> </p>

<p align="justify">
 
 Usado para o armazenamento e a recuperação de dados de uma coleção em que cada elemento é um par que contém um valor de dados e uma chave de classificação. O valor da chave é exclusivo e usado para classificar os dados automaticamente.

O valor de um elemento em um mapa pode ser alterado diretamente. O valor de chave é uma constante e não pode ser alterado. Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave devem ser inseridos para novos elementos.
 
  # unordered_map
<p> </p>

<p align="justify">
 
 Usado para o armazenamento e a recuperação de dados de uma coleção em que cada elemento é um par que contém um valor de dados e uma chave de classificação. O valor da chave é exclusivo e usado para classificar os dados automaticamente.

O valor de um elemento em um mapa pode ser alterado diretamente. O valor de chave é uma constante e não pode ser alterado. Em vez disso, os valores de chave associados aos elementos antigos devem ser excluídos e os novos valores de chave devem ser inseridos para novos elementos.
 
   # Vector 
 <p> </p>

<p align="justify">
 
 A classe de vetor da biblioteca padrão C++ é um modelo de classe para contêineres de sequência. Um vetor armazena elementos de um determinado tipo de maneira linear e permite o acesso aleatório rápido a qualquer elemento. Um vetor é o contêiner preferencial para uma sequência quando o desempenho de acesso aleatório é reduzido.
 
 ## Arquivo : ##
  <p> </p>
 
 <p align="justify">
  
 Para gerar os arquivos com numeros do tipo float aleatorio foi usado o exel com a função RAND() / ALEATORIO() para gerar numeros entre 0 e 999 com até 3 casas apos a virgula, foi criado dois arquivos um chamado DADOS com 500 mil numeros para ser usado para criação das estruturas e outro chamado ENTRADA com 10 mil numeros para a busca e remoção nas estruturas. 
 Para gerar as estruturas foi usado o arquivo DADOS e foi pego os primeiros 500 numeros depois os 5000 primeiros e assim por diante.
  
  ## Medição de tempo: ##
  <p> </p>
 
 Para medir o tempo das funções foi utilizado a blibioteca CHRONO, pois ela mostra resultados precisos.
 
 ![image](https://user-images.githubusercontent.com/54191675/197070851-0360fd73-264e-4df5-afa1-e53c9dd183a1.png)
  
   ## Resultados: ##
  <p> </p>
O progama se inicia com um menu de escolha para qual quantidade de dados a serem analizadas:

![image](https://user-images.githubusercontent.com/54191675/197071548-f6a99a15-0d49-4896-a853-52b56bc7bf1d.png)

Depois da escolha, exemplo se a escholha for o "3":
![image](https://user-images.githubusercontent.com/54191675/197071696-f25f8b28-465b-43b2-a0a7-67215c4f6049.png)




 
 


