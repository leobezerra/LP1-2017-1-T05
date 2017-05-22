**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

# Feed de notícias

## Contexto da aplicação

Em uma rede social, um **feed de notícias** é o serviço de *streaming* responsável por assegurar que os posts criados por fontes (produtores de conteúdo, ou  *publishers*)) sejam entregues a usuários (assinantes, ou *subscribers*). Neste contexto, um assinante é um usuário comum, enquanto um produtor pode ser um amigo ou uma página que tenha decidido seguir. Dada a grande quantidade de posts produzidos nas redes sociais atuais, torna-se fundamental coletar as notícias recebidas por um assinante e organizá-las em função da sua data e relevância. 

## Especificação da aplicação

Sua aplicação deverá receber como entrada um conjunto de notícias e um arquivo de configuração. Mais precisamente, cada notícia apresenta-se em formato JSON (*JavaScript Object Notation*), especificando o código de identificação do produtor, o conteúdo da mensagem e a data/hora de criação da notícia. 

Por sua vez, o arquivo de configuração também contém entradas em formato JSON, divididas, porém, em duas categorias. A primeira entrada informa o critério de rankeamento das notícias, assim como a taxa de atualização do feed de notícias. As demais entradas especificam os relacionamentos existentes entre o assinante e os produtores de contéudo, detalhando o código de identificação do produtor, a última vez em que houve interação entre o usuário e o produtor e a frequência de interações ao longo dos últimos 5, 30 e 365 dias. 

Internamente, sua aplicação deverá implementar uma classe **NewsFeed**, contendo uma lista de notícias e implementando as seguintes funcionalidades: 
* *Renderizar*, que apresenta na tela 10 notícias. 
* *Frequência*, que permite configurar a velocidade com a qual a operação *Renderizar* é chamada.
* *Ordenar*, que permite configurar a heurística usada para rankear as notícias.

Adicionalmente, sua implementação da classe **NewsFeed** deverá fazer uso dos **TADs Fila, Sequência** e **Conjunto**.

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura do **TAD Dataframe** a partir de arquivos CSV: 1,0 ponto
* Implementação do **TAD Dataframe** e suas operações básicas para um único tipo de dados: 3,0 pontos
* Implementação do **TAD Dataframe** e suas operações básicas para ambos os tipos de dados: 3,0 pontos
* Implementação da operação *Ordenar*: 2,0 ponto
* Persistência do **TAD Dataframe** em arquivos CSV: 1,0 ponto
