#define led1 11
#define led2 10
#define led3 9
#define led4 8

char controle='0';

void setup() {
  
  Serial.begin(9600);

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);

  Serial.println("Digite um numero de 0 a 4");
} 

void loop() {  
 
  if (Serial.available()) {
   controle = Serial.read();

   if(controle=='0'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Serial.println(controle);
   }
     if(controle=='1'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Serial.println(controle);
   }
   if(controle=='2'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    Serial.println(controle);
   }
   if(controle=='3'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);                                         
    digitalWrite(led4, HIGH);
    Serial.println(controle);
   }
      if(controle=='4'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);                                         
    digitalWrite(led4, HIGH);
    Serial.println(controle);
   }
             
  }
}
