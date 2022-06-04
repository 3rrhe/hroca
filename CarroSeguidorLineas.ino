//inicializamos variables
int firstInfra = 10;
int secondInfra = 11;
int infra1Value = 0;
int infra2Value = 0;
int IN4 = 4;
int IN3 = 3;
int IN2 = 6;
int IN1 = 7;
//int ENA = 9; Fue conectado con un puente directamente al driver L298N
//int ENB = 8; Fue conectado con un puente directamente al driver L298N

void setup() { 
  Serial.begin(9600);
  
  pinMode(firstInfra, INPUT);
  pinMode(secondInfra, INPUT);
  
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  
  // pinMode (ENA, OUTPUT);  
  // pinMode (ENB, OUTPUT);
}
 
void loop() { 
  // Obtenemos e imprimimos la lectura del infrarrojo #1.
  infra1Value = digitalRead(firstInfra);
  Serial.print("SENSOR | 1 | ");
  Serial.println(infra1Value);
  
  // Obtenemos e imprimimos la lectura del infrarrojo #2.
  infra2Value = digitalRead(secondInfra);
  Serial.print("SENSOR | 2 | ");
  Serial.println(infra2Value);
  
  // analogWrite(ENA, 255);
  // analogWrite(ENB, 255);
  
  if(infra1Value==0) {
    if(infra2Value==0) {
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0); 
    } else {
      digitalWrite(IN1,0);
      digitalWrite(IN2,0);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0); 
    }
  } else {
    if(infra2Value==0) {
        digitalWrite(IN3,0);
        digitalWrite(IN4,0);
        digitalWrite(IN1,0);
        digitalWrite(IN2,1);
    } else {
        digitalWrite(IN1,1);
        digitalWrite(IN2,0);
        digitalWrite(IN3,0);
        digitalWrite(IN4,1);
    } 
  }
}
