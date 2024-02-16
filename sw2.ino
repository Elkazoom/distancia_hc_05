int dado_sensor = 0;    //Variável para o dado recebido

void setup() 
{

  Serial.begin(9600);   //Abre a porta serial, configura a taxa de transferência para 9600 bps
  pinMode(13, OUTPUT);  //Configura o pino 13 como saída digital

}

void loop() {                     //Inicia loop "infinito"

  if (Serial.available() > 0)     //Verifica se existe dado vindo na serial
  {
 
    dado_sensor = Serial.read();  //Caso exista dado, o valor é armazenado

    if(dado_sensor == 1)          //Caso o dado recebido é um, ativa a saida digital 13
    {
      digitalWrite(13, HIGH);     //Liga saída digital
    }
    else                          //Caso o dado recebido é um, desativa a saida digital 13
    {
      digitalWrite(13, LOW);      //Desliga saída digital
    }
  }
}