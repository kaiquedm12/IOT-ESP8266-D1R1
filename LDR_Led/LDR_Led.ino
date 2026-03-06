// Definindo os pinos
const int pinoLDR = D6;          // Pino do sensor de luz
const int pinoLedVermelho = D3;  // Pino do LED Vermelho

void setup() {
  Serial.begin(115200); 
  
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLDR, INPUT); // O LDR envia informações, então é INPUT
  
  delay(100); 
  Serial.println("\nSistema do LDR iniciado!");
}

void loop() {
  // Lê o sinal do módulo LDR
  int leituraLDR = digitalRead(pinoLDR);

  if (leituraLDR == LOW) {
    digitalWrite(pinoLedVermelho, LOW); // DESLIGA o LED no escuro
    Serial.println("Log: Está escuro! LED Vermelho DESLIGADO.");
  } else {
    digitalWrite(pinoLedVermelho, HIGH);  // ACENDE o LED na luz
    Serial.println("Log: Tem luz! LED Vermelho LIGADO.");
  }

  // Um delay maior (meio segundo) para não inundar o Monitor Serial
  delay(500); 
}

