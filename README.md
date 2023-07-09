# Desafio Murano - Questão 6 - Grafos


Este é um projeto em C++ capaz de representar e manipular grafos não-direcionados com pesos em suas arestas. São esperadas entradas, com a descrição do grafo, no seguinte formato:

- **Linha 1**: Quantidade de Vértices
- **Linhas Seguintes**: Representam uma Aresta com o formato [**VérticeA**, **VérticeB**, **Peso da Aresta**]

Essa implementação é capaz de encontrar distâncias, caminhos mínimos entre vértices e a Excentricidade de um vértice usando algoritmo de Dijkstra e encontrar a Minimum Spanning Tree com o algoritmo de Prim.

## Organização do Projeto

- `functions.h`: Arquivo de cabeçalho para a declaração das funções para o teste.
- `functions.cpp`: Arquivo com a implementação das funções para o teste.
- `classes.h`: Arquivo de cabeçalho para classes relacionadas a Grafo.
- `classes.cpp`: Arquivo com a implementação das classes e métodos relacionadas a Grafo.
- `benchmark.cpp`: Arquivo para efetuar o teste e a medição do tempo de execução dos algoritmos.
- `timeResults`: Pasta com os arquivos gerados ao medir o tempo de execução.
- `statsResults`: Pasta com os arquivos gerados pelas funcionalidades (Distância, Caminhos mínimos e etc...)

## Teste da Implementação

A proposta é que sejam avaliados a funcionalidade e o tempo de execução em alguns grafos. Para cada grafo oferecido foi testado a definição do caminho mínimo, a definição da Minimum Spanning Tree e a Excentricidade para alguns vértices. Os resultados podem ser acessados no repositório nas pastas timeResults e statsResults ou gerados localmente com a implementação.

## Execução da Implementação

Para executar a implementação com um compilador C++ instalado basta:
1. Clonar o repositório com o comando `git clone https://github.com/guilhermedionisio/MuranoQ6.git`
2. Dentro do repositório usar o comando `make`
3. Executar o arquivo com `./benchmark`
4. Apagar arquivos objetos e resultados com `make clean`
5. Para apagar os arquivos de resultado pode-se usar o comando `make clean-results`

## Resultados Gerados

São gerados alguns arquivos após o teste de alguns vértices de cada grafo:

- `shortestPathStats.txt`: Armazena a distância e caminho mínimo do vértice 1 para alguns vértices.
- `shortestPathTime.csv`: Armazena o tempo, em milisegundos, levado para encontrar a distância e caminho mínimo para os vértices.

| Graph| Vertex 10 | Vertex 20 | Vertex 30 | Vertex 40 | Vertex 50 |
|------|-----------|-----------|-----------|-----------|-----------|
| 1    | 13        | 10        | 11        | 8         | 8         |
| 2    | 141       | 132       | 130       | 128       | 131       |
| 3    | 1668      | 1629      | 1611      | 1590      | 1591      |

- `shortestMinimumTreeStats.txt`: Armazena o peso total e o número de vértices da árvore mínima. O número de vértices é armazenado como forma de checar se o algoritmo funcionou corretamente.
- `minimumSpanningTreeTime.csv`: Armazena o tempo, em milisegundos, levado para encontrar a árvore mínima.

| Graph 1 | Graph 2 | Graph 3 |
|---------|---------|---------|
| 86      | 929     | 12182   |

- `eccentricityStats.txt`: Armazena a excentricidade, ou seja, o comprimento do caminho mais longo possível entre um vértice e todos os outros vértices do grafo.
- `eccentricityTime.csv`: Armazena o tempo, em milisegundos, levado para encontrar a excentricidade para alguns vértices.

| Graph| Vertex 10 | Vertex 20 | Vertex 30 | Vertex 40 | Vertex 50 |
|------|-----------|-----------|-----------|-----------|-----------|
| 1    | 8         | 6         | 7         | 6         | 7         |
| 2    | 81        | 81        | 79        | 80        | 82        |
| 3    | 1037      | 974       | 988       | 994       | 975       |



