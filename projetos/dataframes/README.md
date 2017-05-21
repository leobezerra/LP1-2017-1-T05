**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

# Dataframes

## Contexto da aplicação

O TAD Dataframe é um tipo abstrato de dados usado por linguagens de alto nível que trabalham com a análise de bases de dados. Dentre as principais características do TAD Dataframe, destacam-se:

1. A independência de tipos entre as colunas, tornando o TAD Dataframe um tipo composto heterogêneo de dados.
1. A possibilidade de acessar colunas pelo seu nome.
1. A possibilidade de realizar consultas complexas, utilizando operações lógicas sobre os nomes das colunas.
1. A possibilidade de aplicar ordenações sobre os dados, baseada em métricas de ordenação que podem ser aplicadas de forma sequencial.

## Especificação da aplicação

Sua aplicação deverá receber como entrada um conjunto de dados, armazenado em um arquivo CSV como um *dataframe* contedo dois tipos possíveis de dados: numérico e texto

Internamente, sua aplicação deverá representar os dados usando o tipo abstrato de dados (TAD) **Conjunto**, estudado nas disciplinas de *Estruturas de Dados Básicas I*.
Conforme a especificação do **TAD Conjunto**, esta classe deverá fornecer as seguintes operações básicas:
* *Inserção*
* *Remoção*
* *Pertinência*
* *União*
* *Diferença*
* *Intersecção*

Adicionalmente, sua implementação do **TAD Conjunto** deverá fornecer as operações abaixo: 
* *Ordenar*, que retornará um objeto **TAD Sequência** a partir da ordenação dos dados contidos em um objeto do **TAD Conjunto**, utilizando pra isso uma métrica passada como parâmetro.
* *Agrupar*, que retornará um conjunto de objetos **TAD Partição**, utilizando para isto um algoritmo de agrupamento passado como parâmetro. 

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura de *dataframes* em arquivos CSV: 1,0 ponto
* Implementação do **TAD Conjunto** e suas operações básicas: 3,0 pontos
* Conversão do *dataframe* de entrada para a representação interna do **TAD Conjunto**: 1,0 ponto
* Implementação da operação *Ordenar*: 1,0 ponto
* Implementação da operação *Agrupar*: 4,0 pontos
