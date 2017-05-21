**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

# Análise de agrupamentos

## Contexto da aplicação

Algoritmos de análise de dados são utilizados para obter conhecimento a partir de bases de informação. Em síntese,
um algoritmo de agrupamento é um tipo de algoritmo de análise que busca similaridades entre dados. Ao construir subconjuntos
com características em comum~(*clusters*), é possível entender padrões nos dados.

## Especificação da aplicação

Sua aplicação deverá receber como entrada um conjunto de dados, armazenado em um arquivo CSV como um dataframe de números reais.

Internamente, sua aplicação deverá representar os dados usando o tipo abstrato de dados (TAD) Conjunto, estudado nas disciplinas de Estruturas de Dados Básicas I.
Conforme a especificação do TAD Conjunto, esta classe deverá fornecer as seguintes operações básicas:
* Inserção
* Remoção
* Pertinência
* União
* Diferença
* Intersecção

Adicionalmente, sua implementação do TAD conjunto deverá fornecer as operações abaixo: 
* *Ordenar*, que retornará um TAD Sequência a partir da ordenação dos dados contidos no Conjunto, utilizando pra isso uma métrica passada como parâmetro.
* *Agrupar*, que retornará um conjunto de objetos da TAD Partição, utilizando para isto um algoritmo de agrupamento passado como parâmetro. 
