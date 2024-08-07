// bool b=1;

// void setup() {
//   // put your setup code here, to run once:
//     Serial.begin(9600);
//     delay(500);
//     Serial.println("Hola Mundo");
//     pinMode(2, INPUT_PULLUP);

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   bool a=digitalRead(2);
//   if(a && !b)
//   {
//     Serial.println("OFF");
//     b=1;
//   }
//   else if(!a && b){
//     Serial.println("ON");
//     b=0;
//   }
//   delay(100);
// }

const int numBotones = 13;  // Número de botones
const int pinesBotones[numBotones] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0};  // Pines donde están conectados los botones
bool estadoBotones[numBotones] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  // Estados anteriores de los botones

void setup() {
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("Hola Mundo");
  
  for (int i = 0; i < numBotones; i++) {
    pinMode(pinesBotones[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < numBotones; i++) {
    bool estadoActual = digitalRead(pinesBotones[i]);
    if (estadoActual && !estadoBotones[i]) {
      Serial.print("Botón ");
      Serial.print(i);
      Serial.println(" OFF");
      estadoBotones[i] = 1;
    }
    else if (!estadoActual && estadoBotones[i]) {
      Serial.print("Botón ");
      Serial.print(i);
      Serial.println(" ON");
      estadoBotones[i] = 0;
    }
  }
  delay(100);
}
