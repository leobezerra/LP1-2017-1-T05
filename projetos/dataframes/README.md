**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

# Dataframes

## Contexto da aplicação

O **TAD Dataframe** é um tipo abstrato de dados usado por linguagens de alto nível que trabalham com a análise de bases de dados. Dentre as principais características do **TAD Dataframe**, destacam-se:

1. A independência de tipos entre as colunas, tornando o **TAD Dataframe** um tipo composto de dados heterogêneos.
1. A possibilidade de acessar uma coluna pelo seu nome.
1. A possibilidade de realizar consultas complexas, utilizando operações lógicas sobre os nomes das colunas.
1. A possibilidade de aplicar ordenações sobre os dados, baseadas em métricas de ordenação que podem ser aplicadas de forma sequencial a diferentes colunas.

## Especificação da aplicação

Sua aplicação deverá receber como entrada uma base de dados (*dataset*), armazenada em um arquivo CSV como um *dataframe*, contendo dois tipos possíveis de dados: numérico e texto. Para poder diferenciar entre estes tipos de dados, considere que os dados do tipo texto estarão delimitados por aspas duplas.

Internamente, sua aplicação deverá implementar o **TAD Dataframe**, utilizando para isto as estruturas de dados vistas na disciplina *Estruturas de Dados Básicas I*.
Conforme explicado anteriormente, esta classe deverá fornecer as seguintes operações básicas:
* *Acesso*, por nomes de colunas e/ou índices. 
* *Adição e remoção de coluna*, sendo a remoção por nome ou índice da coluna.
* *Adição e remoção de linhas*, sendo a remoção por índices, intervalo ou condição (expressão lógica).
* *Pesquisa*, tendo como parâmetro uma expressão lógica.
* *Ordenação*, tendo como parâmetro uma métrica de comparação e o nome das colunas, na ordem em que devem ser avaliadas.

Adicionalmente, sua implementação do **TAD Conjunto** deverá fornecer as operações de estatística abaixo: 
* *Mediana*, que retornará um objeto **TAD Sequência** a partir da ordenação dos dados contidos em um objeto do **TAD Conjunto**, utilizando pra isso uma métrica passada como parâmetro.
* *Agrupar*, que retornará um conjunto de objetos **TAD Partição**, utilizando para isto um algoritmo de agrupamento passado como parâmetro. 

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura de *dataframes* em arquivos CSV: 1,0 ponto
* Implementação do **TAD Conjunto** e suas operações básicas: 3,0 pontos
* Conversão do *dataframe* de entrada para a representação interna do **TAD Conjunto**: 1,0 ponto
* Implementação da operação *Ordenar*: 1,0 ponto
* Implementação da operação *Agrupar*: 4,0 pontos
