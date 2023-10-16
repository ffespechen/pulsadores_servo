/*
  Proyecto didáctico Arduino con mínimos componentes.

  Pulsadores para controlar el giro de un servomotor.
  
  03 (tres) Pulsadores sin retención
  03 (tres) Resistencias 4k7 Ohm para pull-down
  01 (uno) servo motor RG90
  01 Arduino UNO R3
  01 Protoboard
  Cables M-M cantidad necesaria
 */

#include <Servo.h>

#define PULSADOR_IZQUIERDA 8
#define PULSADOR_DERECHA 4
#define PULSADOR_APAGAR 7

#define inicio 90

Servo miServo;

int posicion = inicio;

void setup() {

  pinMode(PULSADOR_IZQUIERDA, INPUT);
  pinMode(PULSADOR_DERECHA, INPUT);
  pinMode(PULSADOR_APAGAR, INPUT);

  miServo.attach(9);
  miServo.write(posicion);
  
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(PULSADOR_DERECHA) == 1){
    Serial.println("PULSADOR DERECHA");
    posicion -= 5;
    if (posicion > 180){
      posicion = 180;
    }
    miServo.write(posicion);
  }
  
  if(digitalRead(PULSADOR_IZQUIERDA) == 1){
    Serial.println("PULSADOR IZQUIERDA");
    posicion += 5;
    if(posicion < 0){
      posicion = 0; 
    }
    miServo.write(posicion);
  }
  
  if(digitalRead(PULSADOR_APAGAR) == 1){
    miServo.write(inicio);
    posicion = inicio;
  }

  Serial.print("Posición -> ");
  Serial.println(posicion);
  delay(200);
}
