**Instituto Metrópole Digital (IMD), Universidade Federal do Rio Grande do Norte (UFRN)**  
*Leonardo Bezerra (leobezerra at imd.ufrn.br)*

---

# Redirecionamento de portas

## Contexto da aplicação

Dispositivos conectados a uma rede de computadores usando o protocolo TCP/IP devem gerenciar internamente as mensagens (pacotes de dados) que suas aplicações enviam ou recebem através da rede. Para tanto, o modelo TCP/IP determina diferentes códigos de identificação, seguindo a estrutura hierárquica abaixo:

* *Endereço MAC*, um endereço numérico de 6 bytes, representado como 6 valores em hexadecimal, que identifica fisicamente interfaces de rede (wireless, ethernet, ...) pressentes em um dispositivo.
* *Endereço IP*, um endereço numérico de 16 bytes, representado como 8 valores em hexadecimal, alocados a endereços MAC para que dispositivos possam se comunicar com outros em diferentes redes. 
* *Porta*, um endereço numérico de 2 bytes, representado como um único valor em decimal, usado para identificar aplicações vinculadas a um determinado endereço IP. 

Assim, quando uma aplicação deseja se comunicar através da rede, ela primeiro deve se registrar, escolhendo uma interface de rede e sendo vinculada a uma porta. Uma vez registrada, é responsabilidade do dispositivo gerenciar as mensagens que a aplicação envia e recebe, identificando-as com o endereço IP da interface de rede selecionada e com a porta associada à aplicação. Além disso, a nível de dispositivo uma aplicação é identificada pelo seu código de processo.

## Especificação da aplicação

Sua aplicação deverá atuar como gerenciador de serviços, recebendo dois arquivos de entrada. O primeiro arquivo, de configuração, deve ser usado para administrar a tabela que armazena as associações entre aplicações, portas, interfaces de rede e endereços IP. Mais precisamente, cada entrada deste arquivo será composta por um código de processo (identificador da aplicação) e um endereço IP (identificador da interface de rede).

Internamente, sua aplicação deverá implementar uma classe **PortForwarding** contendo a tabela de associações e fornecendo as seguintes funcionalidades:
* *Consultar aplicação/porta*, que retornar a porta associada a uma aplicação (ou a aplicação associada a uma porta). 
* *Registrar aplicação*, que tanto pode tentar associar uma aplicação a uma porta passada como parâmetro, como pode escolher uma porta para associar a aplicação caso nenhuma porta seja informada.
* *Remover aplicação/porta*, que permite desassociar uma aplicação de uma porta, seja pelo identificador da aplicação ou da porta.
* *Alterar porta*, que permite trocar a porta usada por uma aplicação para uma nova porta, desde que a mesma esteja livre.

O segundo arquivo de entrada é o buffer de rede, contendo pacotes escritos segundo o formato IPv6. Sua implementação deverá, então, extrair, armazenar em buffer e entregar os pacotes às aplicações correspondentes, executando para isso consultas à tabela de associações. No entanto, sua aplicação deverá manter buffers para cada interface de rede, permitindo ainda que pacotes de vídeo do tipo "video/mp4" sejam entregues antes dos demais pacotes. Note que sua implementação da classe **PortForwarding** deverá fazer uso do **TAD Fila**, estudado na disciplina *Estruturas de Dados Básicas I*. Adicionalmente, será necessário entender o conceito do **TAD Fila de prioridade**.

## Critérios de avaliação

Sua aplicação será avaliada de forma modular:

* Implementação da classe **PortForwarding** e suas funcionalidades básicas: 4,0 pontos.
* Leitura do buffer de rede: 2,0 pontos.
* Manutenção das múltiplas filas de prioridade: 4,0 pontos.

---

*Anterior:* [Feed de notícias](../news-feed/) | *Próximo:* [Projetos](../)
