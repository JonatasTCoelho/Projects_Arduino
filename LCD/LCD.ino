#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

#define led1 8
#define buzzer 10
#define botao1 2
#define botao2 3

int temperatura;
int tempSet = 30;

void setup()
{             
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2); 
  pinMode(led1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  Serial.begin(9600);
}


void loop()
{
  String temp = String ((float(analogRead(A0)) * 5 / (1023)) / 0.01);
  temperatura = temp.toInt(); 
  Serial.println(temperatura); 
  bool readBotao1 = digitalRead(botao1); 
  bool readBotao2 = digitalRead(botao2);

  if(readBotao1 == LOW){
    tempSet++;
    delay(200);
  }
  if(readBotao2 == LOW){
    tempSet--;
    delay(200);
  }
          
  lcd.setCursor(3, 0);
  lcd.print("TEMP: " + temp.substring(0,2)+ ((char)223)+ "C");
  lcd.setCursor(1, 1);
  lcd.print("ALARME: ");
  lcd.print(tempSet); 
  lcd.setCursor(1, 12);

  if(temperatura > tempSet){
      digitalWrite(led1, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(led1, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
   }
   
   else {
      digitalWrite(led1, LOW);
      digitalWrite(buzzer, LOW);
  }
}
