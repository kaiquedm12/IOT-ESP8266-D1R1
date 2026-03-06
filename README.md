# 🔌 IOT com ESP8266 D1R1 — Projetos Práticos

Bem-vindo ao repositório de projetos de **Internet das Coisas (IoT)** utilizando o **ESP8266 D1R1**. Aqui você encontrará os projetos desenvolvidos com descrição detalhada, hardware utilizado e demonstração em vídeo.

---

## 📁 LDR_Led

### O que o projeto faz

Este projeto utiliza um **sensor LDR (Light Dependent Resistor)** para detectar a presença ou ausência de luz ambiente e controla um **LED vermelho** com base nessa leitura.

![Foto do projeto LDR_Led](https://github.com/user-attachments/assets/ceaa4664-2b91-4b36-bbe7-cca75cfce9dc)

### Hardware utilizado

| Componente      | Pino no ESP8266 D1R1 |
|-----------------|----------------------|
| Sensor LDR      | D6                   |
| LED Vermelho    | D3                   |

### Como funciona

1. **Configuração (`setup`):**
   - Inicializa a comunicação serial a 115200 baud para monitoramento.
   - Define o pino do LED como saída (`OUTPUT`) e o pino do LDR como entrada (`INPUT`).

2. **Loop principal (`loop`):**
   - Faz a leitura digital do módulo LDR a cada **500 ms**.
   - Se o valor lido for **LOW** (escuro): o LED vermelho é **desligado** e uma mensagem de log é enviada ao Monitor Serial.
   - Se o valor lido for **HIGH** (com luz): o LED vermelho é **ligado** e uma mensagem de log é enviada ao Monitor Serial.

### Lógica resumida

```
LDR lê LOW  (escuro) → LED Vermelho DESLIGADO
LDR lê HIGH (com luz) → LED Vermelho LIGADO
```

### Exemplo de saída no Monitor Serial

```
Sistema do LDR iniciado!
Log: Tem luz! LED Vermelho LIGADO.
Log: Tem luz! LED Vermelho LIGADO.
Log: Está escuro! LED Vermelho DESLIGADO.
```

### 🎥 Demonstração em vídeo

https://github.com/user-attachments/assets/5e0a6379-61f3-4bb4-9759-8d562c487b9e

