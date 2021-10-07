#include <MakerRobotics028KY.h>

#define ledAzul     13
#define ledVermelho 11
#define ledAmarelo  12
#define lm35 A0
Temperatura sensor (A0);

float valor;

void setup() {
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(lm35, INPUT);
  Serial.begin(9600);

  Serial.print("Sensor de temperatura ligado!");
  Serial.print("\n");
}

void loop() {
  valor = sensor.CalcularTemperatura();
  
  if(valor < 27){
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);

    Serial.print("A temperatura é:");
    Serial.print(valor);
    Serial.print(" \n");
  }

    if(valor > 27 && valor < 29) {
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);

    Serial.print("A temperatura é: ");
    Serial.print(valor);
    Serial.print(" \n");

  }
  
    if(valor > 29 || valor > 30) {
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);

    Serial.print("A temperatura é:");
    Serial.print(valor);
    Serial.print(" \n");

  }

}
