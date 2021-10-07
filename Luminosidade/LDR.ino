#define ledvermelho 12
#define ledazul 13
#define ldr A0

int sensorAlogPin = 0;
int valor = 0;

void setup(){
  pinMode(ldr, INPUT);
  pinMode(ledazul, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  valor = analogRead(sensorAlogPin);
  
  if (valor < 400) {
    digitalWrite(ledazul, HIGH);
    digitalWrite(ledvermelho, LOW);
    Serial.println("Luz detectada");
  } else {
    digitalWrite(ledazul, LOW);
    digitalWrite(ledvermelho, HIGH);
    Serial.println("Luz não detectada");
  }
  
}
