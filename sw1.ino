#include <Ultrasonic.h>
Ultrasonic ultrassom(8,7);  //Define o nome do sensor(ultrassom) - trig(8) | echo(7) respectivamente

int distancia_base = 100;   //distância de controle em centimetro
int distancia_medida = 0;   //distância lida pelo sensor em centimetro

void setup() {

  Serial.begin(9600);   //inicia a serial para 9600 bauds
  pinMode(13, OUTPUT);  //informa pino de saída do led

}

void loop() {
  
  digitalWrite(13, HIGH);                   //Acende led de controle
  distancia_medida = ultrassom.Ranging(CM); //Faz a leitura de distancia do objeto

  if(distancia_medida < distancia_base)
  {
    Serial.write(1);        //Transmite alarme para o capacete do motociclista
    delay(500);             //Aguarda meio segundo para o próximo teste
  }
  else
  {
    Serial.write(0);        //Inibe alarme para o capacete do motociclista
    delay(500);             //Aguarda meio segundo para o próximo teste
    digitalWrite(13, HIGH); //Apaga led de controle
  }

}
