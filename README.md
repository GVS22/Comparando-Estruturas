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


<p align="justify">
	Para a realização dos balanceamentos, a AVL modifica o método de inserção da árvore binária, introduzindo nela um procedimento de avaliação de peso e quatro modelos de rotação. Utilizada a [AVL_Tree](https://github.com/mpiress/avl_tree) como referencia.

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

   ## Analise dos Resultados: ##
   

	500 elementos:

![image](https://user-images.githubusercontent.com/54191675/197081015-0a0dfdf6-992b-4648-9f50-f31543e168d2.png)
![image](https://user-images.githubusercontent.com/54191675/197081028-676340ae-fd87-4944-8576-7134b3e86c60.png)
![image](https://user-images.githubusercontent.com/54191675/197081082-9fcfa069-f7a7-4ed9-9e0d-2ffdc8033391.png)
![image](https://user-images.githubusercontent.com/54191675/197081093-83eb5df0-e8f5-4c0a-b644-b7ba5c9fcdce.png)
![image](https://user-images.githubusercontent.com/54191675/197081133-0ae93610-fb69-47b5-8713-7de4b06576c0.png)
![image](https://user-images.githubusercontent.com/54191675/197081119-4520c90a-c93c-411f-9f17-ac1cd90b0f6c.png)
	
	5000 elementos:

![image](https://user-images.githubusercontent.com/54191675/197081793-02150e40-e79e-407a-b11b-35fef1deaabe.png)
![image](https://user-images.githubusercontent.com/54191675/197081807-3708e99e-0e5c-46f0-b02d-d0ce9212311d.png)
![image](https://user-images.githubusercontent.com/54191675/197081825-315e0d3d-e702-43fa-9479-e4bca13f0dde.png)
![image](https://user-images.githubusercontent.com/54191675/197081838-bfc11027-ed07-4ede-9681-8dccf6b843c4.png)
![image](https://user-images.githubusercontent.com/54191675/197081846-9d6920c1-5a9b-48f2-9d30-40b434ea8c32.png)
![image](https://user-images.githubusercontent.com/54191675/197081856-af548bec-35e3-4a3f-9f30-ebdd90221a46.png)
	
	50000 elementos:

![image](https://user-images.githubusercontent.com/54191675/197082543-d12e1eab-81ea-48d8-8886-9341d88038c3.png)
![image](https://user-images.githubusercontent.com/54191675/197082558-3e272ae0-cae6-4a39-88a5-7c8245c3bebf.png)
![image](https://user-images.githubusercontent.com/54191675/197082579-f992d62a-300b-4024-85dc-7c9dea7ad77a.png)
![image](https://user-images.githubusercontent.com/54191675/197082618-08413a3d-087b-4576-8d74-02a1482b9cc4.png)
![image](https://user-images.githubusercontent.com/54191675/197082633-03e471d0-db34-4069-9f6f-d30a224385b3.png)
![image](https://user-images.githubusercontent.com/54191675/197082649-10896834-fc02-465a-8dbf-fd8c905bed6f.png)

	500000 elementos:

![image](https://user-images.githubusercontent.com/54191675/197083169-6213e8eb-6437-4ede-96e5-f94953a9ce11.png)
![image](https://user-images.githubusercontent.com/54191675/197083185-85798bad-a6c4-4296-933a-d9ea335d41ea.png)
![image](https://user-images.githubusercontent.com/54191675/197083203-66086bff-d9d6-492b-b8a7-287ca9677b31.png)
![image](https://user-images.githubusercontent.com/54191675/197083232-31740a76-b7d4-4932-bf62-76229c85eeaf.png)
![image](https://user-images.githubusercontent.com/54191675/197083260-660a8102-57d4-4ab8-a768-b9119099d006.png)
![image](https://user-images.githubusercontent.com/54191675/197083288-ff779efa-07d3-4104-9d82-bce800a0502b.png)
	



## Conclusão

As estruturas de arvores mostrou sua superioridad, quando comparada pricipalmente ao vector que mesmo com bons algoritimos de ordenação apresentou um tempo inferior aos das árvores, e quando comparada as estruturas MAP e U_MAP não apresentaram um melhor desempenho mas seus resultados não deixaram a desejar, para certo tipos de entradas são mais do que recomendados.

As árvores apresentaram um otimo resultado, tendo uma implementação mais complicada que os maps, ideal para problemas de massas de dados muito grandes.
	


## Configuração utilizada

<table align="center">
	<tr>
		<td><strong>Processador</strong></td>
		<td>11th Gen Intel(R) Core(TM) i7-11800H @ 2.30GHz   2.30 GHz</td>
	</tr>
	<tr>
		<td><strong>Memória RAM</strong></td>
		<td>16,0 GB (utilizável: 15,7 GB)</td>
	</tr>
	<tr>
		<td><strong>GPU</strong></td>
		<td>AMD Radeon Graphics - 2GB - 1.9GHz</td>
	</tr>
	<tr>
		<td><strong>Sistema Operacional</strong></td>
		<td>Windows 11 subsistema WSL Linux Ubuntu 22.04.1</td>
	</tr>
</table>


## Referencias

CORMEN, Thomas. Algoritmos - Teoria e Prática 3º Ed. São Paulo: ELSEVIER ISBN13, 2012.

https://github.com/mpiress

https://learn.microsoft.com/pt-br

https://cplusplus.com/reference/algorithm/binary_search/

https://www.geeksforgeeks.org/quick-sort/


## Contato

email: mygabriel@mail.com




	

	






 
 


