#include <LiquidCrystal.h>

int buttonPin = 7; // O botão está ligado ao pino 7
int counter = 0;   // Começamos com a contagem em 0
int buttonState = 0; // Estado atual do botão
int lastButtonState = 0; // Estado anterior do botão

// Inicializa a biblioteca com os números dos pinos onde o LCD está conectado
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.print("Contador:"); // Exibe um texto inicial no LCD
  pinMode(buttonPin, INPUT); // Define o pino do botão como entrada
}

void loop() {
  buttonState = digitalRead(buttonPin); // Lê o estado do botão

  // Verifica se o botão foi pressionado (mudança de estado)
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      counter += 1; // Incrementa o contador

      // Converte o valor do contador em uma string
      String counterString = String(counter);

      // Atualiza a exibição no LCD
      lcd.setCursor(9, 1); // Move o cursor para a segunda linha, posição 9 (após "Contador:")
      lcd.print("   "); // Limpa os caracteres antigos
      lcd.setCursor(9, 1); // Move o cursor de volta para a posição 9
      lcd.print(counterString); // Exibe o valor do contador como uma string
    }
    delay(50); // Aguarda um pouco para evitar contagens erradas (debounce)
  }

  lastButtonState = buttonState; // Atualiza o estado anterior do botão
}
