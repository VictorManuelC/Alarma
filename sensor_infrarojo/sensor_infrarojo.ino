//se inicializan las variables a utilizar
int sensPin = 2; // Sensor Pin
int ledPin = 13; // LED Pin
int pzSpeaker = 5; //Pieza-speaker Pin
int val = 0; // variable de entrada status

//se inicializan las funciones de las variables antes inicializadas
void setup() {
   pinMode(sensPin, INPUT); 
   pinMode(pzSpeaker, OUTPUT); 
   pinMode(ledPin, OUTPUT); 
   
}
void loop(){
   val = digitalRead(sensPin); // lee el sensor
   if (val == HIGH) { //checa si esta en arriba
      digitalWrite(ledPin, HIGH); //prende el led a utilizar

     //prende el speake para que suene
      playTone(500, 600);
      delay(100);
      playTone(500, 800);
      delay(100);
   } else {
      digitalWrite(ledPin, LOW); // apagamos el led y se apaga el speaker
      playTone(0, 0);
      delay(300);
   }
}
//duracion de la frecuencia del speaker
void playTone(long duration, int freq) {
   duration *= 1000;
   int period = (1.0 / freq) * 1000000;
   long elapsed_time = 0;
   while (elapsed_time < duration) {
      digitalWrite(pzSpeaker,HIGH);
      delayMicroseconds(period / 2);
      digitalWrite(pzSpeaker, LOW);
      delayMicroseconds(period / 2);
      elapsed_time += (period);
   }
}
