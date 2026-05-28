# 🌱 Protocolo Eden

## Estufa Inteligente Automatizada para Marte

### Global Solution 2026 — TuxLabs

---

# 📖 Descrição do Projeto

O **Protocolo Eden** é um projeto acadêmico desenvolvido para a disciplina de **Edge Computing**, com foco em agricultura espacial e automação inteligente.

A solução consiste em uma estufa inteligente automatizada capaz de monitorar e controlar variáveis essenciais para o cultivo de plantas em Marte utilizando sensores conectados a um Arduino Uno.

O sistema coleta dados de temperatura e umidade em tempo real e toma decisões automaticamente para manter o ambiente adequado para o desenvolvimento da plantação.

Toda a lógica é executada localmente no próprio Arduino, aplicando o conceito de Edge Computing.

---

# 🎯 Objetivo da Solução

O objetivo do projeto é simular uma solução tecnológica para agricultura em ambientes extremos, como Marte, utilizando automação embarcada de baixo custo.

A solução busca:

* Automatizar o controle ambiental da estufa
* Garantir condições ideais para cultivo
* Simular agricultura espacial inteligente
* Demonstrar conceitos de Edge Computing
* Reduzir intervenção humana no processo de cultivo

---

# 🥬 Cultura Escolhida

A planta utilizada como referência foi a alface, escolhida por:

* Fácil cultivo
* Crescimento rápido
* Baixo consumo de recursos
* Potencial utilização em agricultura espacial

As condições ideais para o cultivo da alface no sistema são:

* Temperatura entre 18°C e 24°C
* Umidade entre 50% e 70%

---

# ⚙️ Componentes Utilizados

* Arduino Uno
* Sensor DHT22
* LCD 16x2 I2C
* LEDs
* Resistores 220Ω
* Jumpers

---

# 💡 Explicação do Funcionamento

O sistema funciona de forma totalmente automática.

O sensor DHT22 realiza a leitura da temperatura e umidade da estufa. O Arduino processa essas informações e verifica se os valores estão dentro da faixa ideal para o cultivo da alface.

Se a temperatura estiver abaixo de 18°C:

* O sistema ativa o aquecimento
* O LED vermelho acende
* O LCD exibe a mensagem “Aquecendo”

Se a temperatura ultrapassar 24°C:

* O sistema ativa a refrigeração
* O LED azul acende
* O LCD exibe a mensagem “Resfriando”

Se a umidade estiver abaixo de 50%:

* O sistema ativa a irrigação
* O LED verde acende
* O LCD exibe a mensagem “Irrigando solo”

Se a umidade estiver acima de 70%:

* O sistema identifica excesso de umidade
* O LED amarelo de alerta é acionado
* O LCD exibe uma mensagem de alerta

Se qualquer valor estiver fora das condições ideais:

* O LED amarelo de alerta é acionado

Quando todas as condições estão corretas:

* O LCD exibe “Ambiente ideal”

---

# 🔌 Estrutura do Circuito

## Sensor DHT22

* VCC conectado ao 5V do Arduino
* GND conectado ao GND
* DATA conectado ao pino 2

---

## LCD 16x2 I2C

* VCC conectado ao 5V
* GND conectado ao GND
* SDA conectado ao A4
* SCL conectado ao A5

---

## LEDs

* LED de aquecimento conectado ao pino 8
* LED de refrigeração conectado ao pino 9
* LED de irrigação conectado ao pino 10
* LED de alerta conectado ao pino 13

---

# 🧠 Edge Computing Aplicado

O projeto utiliza o conceito de Edge Computing porque todas as decisões são tomadas localmente no Arduino.

O fluxo do sistema funciona da seguinte maneira:

1. O sensor coleta os dados
2. O Arduino processa as informações
3. O sistema decide automaticamente o que fazer
4. Os atuadores são acionados em tempo real

Isso reduz:

* Dependência de internet
* Latência
* Comunicação externa
* Necessidade de processamento em servidores remotos

Esse modelo é importante para Marte, pois a comunicação com a Terra possui atraso e não seria eficiente depender de respostas externas para controlar uma estufa.

---

# 🖥️ Simulação no Wokwi

O projeto foi desenvolvido e testado utilizando a plataforma Wokwi.

Link do projeto:

[https://wokwi.com/projects/465216501725642753](https://wokwi.com/projects/465216501725642753)

---

# ▶️ Instruções de Execução

1. Acesse o link do projeto no Wokwi:

   [https://wokwi.com/projects/465216501725642753](https://wokwi.com/projects/465216501725642753)

2. Verifique se o circuito contém os seguintes componentes:

   * Arduino Uno
   * Sensor DHT22
   * LCD 16x2 I2C
   * LEDs
   * Resistores

3. Abra o arquivo principal do código Arduino.

4. Confira se as bibliotecas estão importadas corretamente.

5. Clique em **Start Simulation**.

6. Observe no LCD os valores de temperatura, umidade e o status automático da estufa.

---

# 📚 Bibliotecas Utilizadas

```cpp
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

---

# 🧪 Tecnologias Utilizadas

* Arduino Uno
* Linguagem C++
* Wokwi
* Edge Computing
* Automação Inteligente
* Sensores

---

# 🌍 Aplicação do Projeto

O **Protocolo Eden** representa uma possível solução para agricultura autônoma em ambientes extremos.

A proposta pode ser aplicada em cenários como:

* Agricultura espacial
* Estufas autônomas
* Produção sustentável de alimentos
* Colonização de Marte
* Agricultura inteligente em locais remotos
* Controle ambiental automatizado

---

# 🚀 Conclusão

O projeto demonstra como uma solução simples com Arduino pode simular um sistema inteligente de cultivo automatizado.

Através do uso de sensores, LEDs, LCD e lógica de decisão local, o **Protocolo Eden** consegue representar uma estufa inteligente capaz de adaptar o ambiente conforme as necessidades da planta.

Essa abordagem mostra a importância da automação e do Edge Computing em situações onde autonomia, rapidez e eficiência são essenciais.

---

# 👨‍💻 Integrantes do Grupo — TuxLabs

* Felipe Roberto Cassiano — RM 569238
* Paulo Henrique Moreira Angueira — RM 573245
* Raphael Martins Manfredi — RM 570500
* Eduardo de Abreu Gouvêa — RM 573414
* Vinícius Mansur Magalhães — RM 571518
