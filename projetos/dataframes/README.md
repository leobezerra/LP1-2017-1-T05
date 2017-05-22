**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

## Dataframes

O **TAD Dataframe** é um tipo abstrato de dados usado por linguagens de alto nível que trabalham com análise de bases de dados. Dentre as principais características do **TAD Dataframe**, destacam-se:

1. A independência de tipos entre as colunas, tornando o **TAD Dataframe** um tipo composto de dados heterogêneos.
1. A possibilidade de acessar uma coluna pelo seu nome.
1. A possibilidade de realizar consultas complexas, utilizando operações lógicas sobre os nomes das colunas e/ou valores das linhas.

## Especificação da aplicação

Sua aplicação deverá receber como entrada uma base de dados (*dataset*), armazenada em um arquivo CSV como um *dataframe*, contendo dois tipos possíveis de dados: numérico e texto. Para poder diferenciar entre estes tipos de dados, considere que os dados do tipo texto estarão delimitados por aspas duplas.

Internamente, sua aplicação deverá implementar o **TAD Dataframe**, utilizando para isto as estruturas de dados vistas na disciplina *Estruturas de Dados Básicas I*.
Conforme explicado anteriormente, esta classe deverá fornecer as seguintes operações básicas:
* *Acesso*, por nomes de colunas e/ou índices. 
* *Adição e remoção de coluna*, sendo a remoção por nome ou índice da coluna.
* *Adição e remoção de linhas*, sendo a remoção por índices, intervalo ou condição (expressão lógica).
* *Pesquisa*, tendo como parâmetro uma expressão lógica.

Adicionalmente, sua implementação do **TAD Dataframe** deverá fornecer as seguintes funcionalidades: 
* *Ordenar*, tendo como parâmetro uma métrica de comparação e o nome das colunas, na ordem em que devem ser avaliadas.
* *Persistir*, que salva o estado atual do dataframe em um arquivo CSV.

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura do **TAD Dataframe** a partir de arquivos CSV: 1,0 ponto
* Implementação do **TAD Dataframe** e suas operações básicas para um único tipo de dados: 3,0 pontos
* Implementação do **TAD Dataframe** e suas operações básicas para ambos os tipos de dados: 3,0 pontos
* Implementação da operação *Ordenar*: 2,0 ponto
* Persistência do **TAD Dataframe** em arquivos CSV: 1,0 ponto

---

*Anterior:* [Análise de agrupamentos](../clustering) | *Próximo:* [Feed de notícias](../news-feed/)
