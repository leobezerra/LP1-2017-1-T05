**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

# Redirecionamento de portas

## Contexto da aplicação

Dispositivos conectados a uma rede de computadores usando o protocolo TCP/IP devem gerenciar internamente as mensagens (pacotes de dados) que suas aplicações enviam ou recebem através da rede. Para tanto, o modelo TCP/IP determina diferentes códigos de identificação, seguindo a estrutura hierárquica abaixo:

* *Endereço MAC*, um endereço numérico de 6 bytes, representado como 6 valores em hexadecimal, que identifica interfaces de rede (wireless, ethernet, ...) em um dispositivo.
* *Endereço IP*, um endereço numérico de 16 bytes, representado como 8 valores em hexadecimal, alocados a endereços MAC para que dispositivos possam se comunicar com outros em rede. 
* *Porta*, um endereço numérico de 2 bytes, representado como um único valor em decimal, usado para identificar aplicações vinculadas a um determinado endereço IP. 

Assim, quando uma aplicação deseja se comunicar através da rede, ela primeiro deve se registrar, escolhendo uma interface de rede e sendo vinculado a uma porta. Uma vez registrado, é responsabilidade do dispositivo gerenciar as mensagens que uma aplicação envia e recebe, identificando-as com o endereço IP da interface de rede selecionada e com a porta associada à aplicação.

## Especificação da aplicação

Sua aplicação deverá receber como entrada um conjunto de notícias e um arquivo de configuração. Mais precisamente, cada notícia apresenta-se em formato JSON (*JavaScript Object Notation*), especificando o código de identificação do produtor, o conteúdo da mensagem e a data/hora de criação da notícia. 

Por sua vez, o arquivo de configuração também contém entradas em formato JSON, divididas, porém, em duas categorias. A primeira entrada informa o critério de rankeamento das notícias, assim como a taxa de atualização do feed de notícias. As demais entradas especificam os relacionamentos existentes entre o assinante e os produtores de contéudo, detalhando o código de identificação do produtor, a última vez em que houve interação entre o usuário e o produtor e a frequência de interações ao longo dos últimos 5, 30 e 365 dias. 

Internamente, sua aplicação deverá implementar uma classe **NewsFeed**, contendo uma lista de notícias e implementando as seguintes funcionalidades: 
* *Renderizar*, que apresenta na tela 10 notícias. 
* *Frequência*, que permite configurar a velocidade com a qual a operação *Renderizar* é chamada.
* *Ordenar*, que permite configurar a heurística usada para rankear as notícias.

Note que sua implementação da classe **NewsFeed** deverá fazer uso dos **TADs Fila, Sequência** e/ou **Conjunto**, estudados na disciplina *Estruturas de Dados Básicas I*. 

Adicionalmente, sua aplicação deverá implementar as seguintes heurísticas de ordenação:
* *Notícias mais recentes*, onde as 10 notícias criadas a menos tempo são exibidas.
* *Notícias de contatos mais recentemente ativos*, onde os produtores são inicialmente rankeados em função da data de sua última interação com o assinante. Em seguida, as notícias criadas por estes produtores ao longo do último dia são adicionadas à visualização, até totalizar 10 mensagens.
* *Notícias mais relevante*, onde as notícias são rankeadas em função de sua relevância. Esta métrica é calculada como a média ponderada da frequência de interações entre o assinante e o produtor da notícia ao longo dos últimos 5, 30 e 365 dias, com pesos 6, 4 e 2, respectivamente. Uma vez rankeados os produtores, as notícias de cada um são adicionadas à visualização 

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Leitura dos arquivos de entrada em formato JSON: 2,0 pontos.
* Implementação da classe **NewsFeed** e suas funcionalidades básicas *Renderizar* e *Frequência*: 4,0 pontos.
* Implementação da funcionalidade *Ordenar*: 4,0 pontos.

---

*Anterior:* [Dataframes](../dataframes) | *Próximo:* [Servidor DNS](../dns-server/)
