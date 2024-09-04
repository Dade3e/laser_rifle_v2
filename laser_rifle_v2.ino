// LASER RIFLE Attiny shot
// Davide Barchetta 2024

// ATMEL ATTINY 25/45/85 / ARDUINO
//
//                  +-\/-+
// Ain0 (D 5) PB5  1|    |8  Vcc
// Ain3 (D 3) PB3  2|    |7  PB2 (D 2) Ain1
// Ain2 (D 4) PB4  3|    |6  PB1 (D 1) pwm1
//            GND  4|    |5  PB0 (D 0) pwm0   -> laser
//                  +----+

#define AnalogPin 3 //ATTINY 3 (Ain3), NANO A0
#define LaserPin 0 //ATTINY 0, NANO 2
#define LaserTime 30
#define debounce 250
#define theshold 10
//#define LaserFreq 16000
/*
#define durata_sa 8
#define durata_sb 2

#define durata_1a 4
#define durata_1b 2

#define durata_0a 4
#define durata_0b 2
*/

#define debug false
#define info false

#define id 2

void setup() {

  pinMode(AnalogPin,INPUT);
  pinMode(LaserPin,OUTPUT);
  digitalWrite(LaserPin, LOW);

  if(info || debug)
    Serial.begin(115200);
    Serial.print("ID: ");
    Serial.println(id);
}

void loop() {
  int sensorValue = analogRead(AnalogPin);
  if(sensorValue > theshold){
    shot();
    delay(debounce);
    if(debug)
      Serial.println(sensorValue);
  }
  delay(1);
}

void shot(){
  //start msg
  /*
  tone(LaserPin, LaserFreq);
  delay(durata_sa);
  noTone(LaserPin);
  delay(durata_sb);
  for(int i=9; i>=0; i--)
  {
    bool m = bitRead(id, i);
    if(debug){
      Serial.print(m);
      Serial.print(" ");
    }
    if(m){  //true
      tone(LaserPin, LaserFreq);
      delay(durata_1a);
      noTone(LaserPin);
      delay(durata_1b);
    }else{
      noTone(LaserPin);
      delay(durata_0a);
      //noTone(LaserPin);
      delay(durata_0b);
    }
  }
  if(debug)
    Serial.println();
  noTone(LaserPin);
  */
  digitalWrite(LaserPin, HIGH);
  delay(LaserTime);
  digitalWrite(LaserPin, LOW);
}
