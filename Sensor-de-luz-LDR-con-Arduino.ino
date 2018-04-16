/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

const int sensorPinT = A0;
const int minSensorT = 50;
const int maxSensorT = 1015;
int valT;
byte arrayT[8];
String resultSerialT;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valT = analogRead(sensorPinT);
  valT = map(valT, minSensorT, maxSensorT, 0, 100);
  valT = constrain(valT, 0, 100);
  for (int iT = 0; iT < 7; iT++)
    arrayT[iT] = valT;
  for (int iT = 0; iT < 7; iT++)
    valT += arrayT[iT];
  valT = valT / sizeof(arrayT);
  resultSerialT = "Hay un: " + String(valT) + "% de luz" ;
  Serial.println(resultSerialT);
  delay(500);
}
