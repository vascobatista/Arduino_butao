/*
  Desenvolvimento arduino
  Teste2 - Vasco Batista 25-2-2018

  - leds Azul pin12
  - led vermilho pin 11
  - Buatao pin 8 - ativalo a LOW

  função para ler inputs - esdo do butão

  função para altrar modeo

  ativar butões

  baseado em delais ???

*/
// Constantes pisca várias vezes
const int tempo = 150;


const int LED_PLACA = 13;
const int LED_AZUL = 12;
const int LED_VERMELHO = 11;

const int BUTAO = 8;


// Lista de variaveis globais
int mode = 0; //identifica o modo de funcionamento
// modo 0; modo inicial
// modo 1; modo especia


int input_status; // estado das intradas
int repete = 3;


//Lista de Funcoes

//Ler parametros de input
// funcao que le os sensores
void get_sensor() {
  // read the state of the BUTAO value:
  input_status = digitalRead(BUTAO);

}

// calculate
// funcao que com base nos dados dos sensores altera o modo de funcionar
void mode_calc()
{
  // altera o mode dependendo das entradas

  // led vermelho fica com a possiçao do butão
  digitalWrite(LED_VERMELHO, input_status);
  if (input_status == LOW)
    if (mode == 0)
    {
      mode = 1;
    }
    else {
      mode = 0;
    }


}





// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PLACA, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUTAO, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  // le o estado do sensores
  get_sensor();


  // muda o mode
  mode_calc();


  //

  if (mode == 1) {
    repete = 1;
  }
  else
  {
    repete = 3;
  }


  for (int i = 1; i <= repete; i++)
  {
    digitalWrite(LED_AZUL, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(tempo);                       // wait for a second
    digitalWrite(LED_AZUL, LOW);    // turn the LED off by making the voltage LOW
    delay(tempo);                       // wait for a second

  }
  delay(1000);    
  //  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(250);                       // wait for a second
  //  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //  delay(100);                       // wait for a second
  //  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //  delay(250);
  //digitalWrite(LED_AZUL, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);                       // wait for a second
 


}
