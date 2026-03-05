// Definindo os pinos do Wemos D1 R1
const int pinoBotao = D2; 
const int pinoLed1 = D3;       // Seu primeiro LED
const int pinoLedAmarelo = D4; // LED Amarelo
const int pinoLedVerde = D5;   // LED Verde

int estadoAnteriorBotao = HIGH; 
int contadorCliques = 0; // Vai controlar qual LED deve acender (0 a 3)

void setup() {
  Serial.begin(115200); 
  
  // Configurando os pinos
  pinMode(pinoBotao, INPUT_PULLUP); 
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);

  // Garante que todos iniciem desligados
  apagarTodosLeds();

  delay(100); 
  Serial.println("\nSistema iniciado. Pressione o botão para alternar os LEDs.");
}

void loop() {
  int estadoAtualBotao = digitalRead(pinoBotao);

  // Verifica se o botão FOI pressionado (transição de HIGH para LOW)
  if (estadoAtualBotao == LOW && estadoAnteriorBotao == HIGH) {
    
    contadorCliques++; // Adiciona 1 ao contador
    
    // Se passar de 3 (que é o último LED), zera o contador para apagar todos e recomeçar
    if (contadorCliques > 3) {
      contadorCliques = 0; 
    }

    // Primeiro, apagamos todos os LEDs para garantir que só um fique aceso
    apagarTodosLeds();

    // Agora, acendemos apenas o LED correspondente ao clique
    switch (contadorCliques) {
      case 0:
        Serial.println("Log: Clique 0 - Todos os LEDs apagados.");
        break;
      case 1:
        digitalWrite(pinoLed1, HIGH);
        Serial.println("Log: Clique 1 - LED 1 (D3) LIGADO.");
        break;
      case 2:
        digitalWrite(pinoLedAmarelo, HIGH);
        Serial.println("Log: Clique 2 - LED Amarelo (D4) LIGADO.");
        break;
      case 3:
        digitalWrite(pinoLedVerde, HIGH);
        Serial.println("Log: Clique 3 - LED Verde (D5) LIGADO.");
        break;
    }

    // Delay de debounce para evitar que um clique conte como vários
    delay(50); 
  }

  // Atualiza o estado para a próxima leitura
  estadoAnteriorBotao = estadoAtualBotao;
}

// Função auxiliar para deixar o código do loop mais limpo
void apagarTodosLeds() {
  digitalWrite(pinoLed1, LOW);
  digitalWrite(pinoLedAmarelo, LOW);
  digitalWrite(pinoLedVerde, LOW);
}