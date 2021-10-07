#define NOTE_D4  294
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_A5  880

int tons[4] = { NOTE_A5, NOTE_A4, NOTE_G4, NOTE_D4 };
int sequencia[100] = {};

int rodada_atual = 0;
int passo_atual = 0;

int pinobuzzer = 7;

int Leds[3] = { 8, 9, 10,};

int Botoes[3] = { 2, 3, 4};

 
int botao_pressionado = 0;
int jogo_perdido = false;

 

void setup() {
  
  for (int i = 0; i <= 2; i++) {

    pinMode(Leds[i], OUTPUT);

  }
 
  for (int i = 0; i <= 2; i++) {
      pinMode(Botoes[i], INPUT_PULLUP);
  }

  pinMode(pinobuzzer, OUTPUT);

  randomSeed(analogRead(0));

}
 
void loop() {

  if (jogo_perdido) {

      int sequencia[100] = {};
  
      rodada_atual = 0;
      passo_atual= 0;
  
      jogo_perdido = false;

  }
 
  if (rodada_atual == 0) {

    Som_Inicio();

    delay(500);

  }
 

  proximaRodada();


  reproduzirSequencia();


  aguardarJogador();
 

  delay(1000);
}
 

void proximaRodada() {

  int numero_sorteado = random(0, 3);

  sequencia[rodada_atual++] = numero_sorteado;

}

void reproduzirSequencia() {
  for (int i = 0; i < rodada_atual; i++) {

    tone(pinobuzzer, tons[sequencia[i]]);

    digitalWrite(Leds[sequencia[i]], HIGH);
    delay(500);

    noTone(pinobuzzer);

    digitalWrite(Leds[sequencia[i]], LOW);
    delay(100);

  }

  noTone(pinobuzzer);

}


void aguardarJogador() {

  for (int i = 0; i < rodada_atual; i++) {
    aguardarJogada();

    verificarJogada();

 
      if ( jogo_perdido) {
  
        break;
      }
    
    passo_atual++;

  }

  passo_atual = 0;
}

 
void aguardarJogada() {
  boolean jogada_efetuada = false;

  while (!jogada_efetuada) {
    for (int i = 0; i <= 2; i++) {
      if (!digitalRead(Botoes[i]) == HIGH) {

        botao_pressionado = i;
        tone(pinobuzzer, tons[i]);

        digitalWrite(Leds[i], HIGH);
        delay(300);

        digitalWrite(Leds[i], LOW);
        noTone(pinobuzzer);

        jogada_efetuada = true;

      }
    }
    delay(10);
  }
}

 
void verificarJogada() {
  if (sequencia[passo_atual] != botao_pressionado) {
    // Jogo finalizado

    for (int i = 0; i <= 2; i++) {
      tone(pinobuzzer, tons[i]);
      digitalWrite(Leds[i], HIGH);

      delay(200);

      digitalWrite(Leds[i], LOW);
      noTone(pinobuzzer);
    }

 

    tone(pinobuzzer, tons[3]);

    for (int i = 0; i <= 2; i++) {

      digitalWrite(Leds[0], HIGH);
      digitalWrite(Leds[1], HIGH);
      digitalWrite(Leds[2], HIGH);
      
      delay(100);

      digitalWrite(Leds[0], LOW);
      digitalWrite(Leds[1], LOW);
      digitalWrite(Leds[2], LOW);

      delay(100);

    }

    noTone(pinobuzzer);

    jogo_perdido = true;

  }

}
 
void Som_Inicio() {

  tone(pinobuzzer, tons[0]);

  digitalWrite(Leds[0], HIGH);
  digitalWrite(Leds[1], HIGH);
  digitalWrite(Leds[2], HIGH);

  delay(500);

  digitalWrite(Leds[0], LOW);
  digitalWrite(Leds[1], LOW);
  digitalWrite(Leds[2], LOW);
  
  delay(500);
  noTone(pinobuzzer);
}
