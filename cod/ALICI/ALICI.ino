#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN); 
int data[2];

void setup()   
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}
void loop() {
  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    int y = data[1];
    int x = data[0];
    radio.read( data, sizeof(data) ); 
    Serial.print(" x = ");
    Serial.println(x);
   // Serial.print(" y = ");
   // Serial.println(y);
    //delay(300);
  }
}
