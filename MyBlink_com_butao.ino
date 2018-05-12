/*
  Desenvolvimento arduino
  Teste2 - Vasco Batista 25-2-2018

  - leds Azul pin12
  - led vermilho pin 11
  - Buatao pin 8 - ativalo a LOW

  função para ler inputs - esdo do butão

  função para altrar modeo

  ativar butões

  verificação do tempo para piscar led

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


//variavei de input
int input_status; // estado das intradas

// variaveis de outpu

int repete ; // numero repetições

// variaveis controlo
unsigned long previousMillis = 0; // contador de tempo anterior
unsigned long currentMillis = 0; // contador de tempo

int conta_pisca_azul = 3;
int interval = 1000; // intervalo para mudar estado


// estado atuadores
int estao_placa;
int estado_azul;
int estado_vermelho;

//Lista de Funcoes

//Ler parametros de input
// funcao que le os sensores
void get_sensor() {
  // read the state of the BUTAO value - led vermelho toma esse valor
  input_status = digitalRead(BUTAO);
  if (input_status == HIGH) {
    estado_vermelho = LOW;
  }
  else
  {
    estado_vermelho = HIGH;

  }
  digitalWrite(LED_VERMELHO, estado_vermelho);

  delay(50);

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


  estao_placa = LOW;
  estado_azul = LOW;
  estado_vermelho = LOW;

  // inicializa atuadores led
  digitalWrite(LED_PLACA, estao_placa);
  digitalWrite(LED_AZUL, estado_azul);
  digitalWrite(LED_VERMELHO, estado_vermelho);

  // initialize serial communication:
  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop() {



  // le o estado do sensores
  get_sensor();

  // muda o mode
  mode_calc();

  // valida o estado
  if (mode == 1) {
    repete = 1;

  }
  else
  {
    repete = 3;
  }



  //
  currentMillis = millis(); // atualiza o tempo

  // verifica se o tempo passou para  executar alterações estados
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    Serial.print("diff: ");
    Serial.println(currentMillis - previousMillis);
    previousMillis = currentMillis;

    Serial.print("Mode: ");
    Serial.println(mode);

    Serial.print("Milies: ");
    Serial.println(currentMillis);

    Serial.print("Estado Azul: ");
    Serial.println(estado_azul);

    Serial.print("Conta pisca azul ");
    Serial.println(conta_pisca_azul);


    Serial.print("intervalo ");
    Serial.println(interval);
    Serial.println();

    if (conta_pisca_azul > 0 ) {
      interval = 250;
     

      if (estado_azul == LOW) {
        estado_azul = HIGH;
      } else {
        estado_azul = LOW;
         conta_pisca_azul--;
      }
    }
    else
    {
      estado_azul = LOW;
      interval = 1000;
      conta_pisca_azul = repete;

    }
  }
  digitalWrite(LED_AZUL, estado_azul);



}
