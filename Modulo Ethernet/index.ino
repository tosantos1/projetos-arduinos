#include "ThingSpeak.h"
#include <SPI.h>
#include <Ethernet.h>

unsigned long time;
unsigned long timeAtual;

byte mac[] = { 0xC8, 0xD3, 0xFF, 0x00, 0x07, 0xA8};
EthernetClient client;
unsigned long ChannelNumber = 583960;
unsigned int FieldNumber = 6;

int led = 2;
int x = 30000;
float potenciometro = 0.00;

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);
  ThingSpeak.begin(client);
  pinMode(led, OUTPUT);
  timeAtual = time;
}
void loop() {
  time = millis();
  Serial.print("Ultimo valor enviado: ");
  Serial.println(potenciometro);

  if (potenciometro >= 0) {
    digitalWrite(led, potenciometro);
  }


  if (time - timeAtual < x) {
    potenciometro = ThingSpeak.readFloatField(ChannelNumber, FieldNumber);
    timeAtual = time;
  }

}