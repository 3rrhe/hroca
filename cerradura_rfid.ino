// Inclusión de librerías
#include <SPI.h>
#include <MFRC522.h>
// Definimos constantes
#define LED 6 // Led indicador
bool debug = true; // Seteamos el modo Debug a true, nos ayuda a mostrar mensajes en la consola
MFRC522 mfrc522(53, 9); // Creamos una instancia de la librería MFRC522 indicando los puerto SS y RST respectivamente

// Ciclo inicial
void setup() 
{
  if (debug) { Serial.begin(9600); }   // Inicializa la comunicacion serial
  SPI.begin();          // Inicializa el bus SPI
  mfrc522.PCD_Init();   // Inicializa el MFRC522
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  if (debug) {
    Serial.println("Ponga su Tarjeta para la lectura...");
    Serial.println();
  }
}

// Ciclo infinito
void loop() 
{
  // Esperando nuevas tarjeras
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Selección de tarjeta
  if (!mfrc522.PICC_ReadCardSerial())  {
    return;
  }
  
  if (debug) { Serial.print("UID tag :"); }
  String content = "";
  byte letter;
  
  for (byte i = 0; i < mfrc522.uid.size; i++) { // Leemos el código UID de las tarjetas y la almacenamos en la variable content
    if (debug) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    }
    
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  if (debug) {
    Serial.println();
    Serial.print("Message : ");
  }
  
  content.toUpperCase(); // Convertimos content a mayusculas

  // Verficamos si los UID de las tarjetas que se coloquen en el lector RFID son los que tienen autorización o no
  if (content.substring(1) == "7A E0 3D B3" || content.substring(1) == "2C F8 DD 32") {
    if (debug) { Serial.println("Acceso Autorizado"); }
    
    digitalWrite(LED, HIGH); // Encendemos el led y derivado del puente entre el LED y la chapa esta se abre
    delay(1000);
    digitalWrite(LED, LOW); // Apagamos el led y derivado del puente entre el LED y la chapa esta se cierra
  }
}
