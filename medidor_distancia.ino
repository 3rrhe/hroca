// Incluimos las librerías
#include <LiquidCrystal.h>

// Pines del sensor
const int trigPin = 9;
const int echoPin = 10;
// Variables
long duration;
int distance;
bool debug = true; // Agregamos debug como true, esto nos ayuda a ver mensajes en la consola

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Instanciamos el LCD

// Ciclo inicial
void setup() {
  lcd.begin(16, 2); // Iniciamos el LCD
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  if (debug) { Serial.begin(9600); }
}

// Ciclo infinito
void loop() {
  // Encendemos y apagamos el trigger para obtener una lectura en el pin echo
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // Leemos el pulso
  distance = (duration * 0.034) / 2; // Convertimos el pulso a una distancia en CM
  
  if (debug) { Serial.println(distance); }

  lcd.clear(); // Limpiamos el LCD
  lcd.setCursor(0, 0); // Seteamos el cursos a la columna 0 y la fila 0
  // Mostamos la distancia en el LCD
  lcd.print("Distancia: ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(500);
}
