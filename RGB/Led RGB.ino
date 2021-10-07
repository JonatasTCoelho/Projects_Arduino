
int op; //Variável que guardará o valor do potenciômetro
int pot = A5;

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  op = analogRead(pot);
  if (op > 0 && op < 100) { 
    analogWrite(5, 204);     
    analogWrite(6, 204);
    analogWrite(9, 204);
  }
  if (op > 100 && op < 200) {
    analogWrite(5, 255);
    analogWrite(6, 102);    
    analogWrite(9, 102);
  }
  if (op > 200 && op < 300) {
    analogWrite(5, 255);
    analogWrite(6, 102);
    analogWrite(9, 0);
  }
  if (op > 300 && op < 400) {
    analogWrite(5, 153);
    analogWrite(6, 51);
    analogWrite(9, 0);
  }
  if (op > 400 && op < 500) {
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 153);
  }
  if (op > 500 && op < 600) {
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 102);
  }
  if (op > 600 && op < 700) {
    analogWrite(5, 102);
    analogWrite(6, 51);
    analogWrite(9, 51);
  }
  if (op > 800 && op < 900) {
    analogWrite(5, 21);
    analogWrite(6, 21);
    analogWrite(9, 21);
  }
}
