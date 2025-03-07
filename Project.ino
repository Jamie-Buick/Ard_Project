#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);


int chk;
float hum = NAN;
float temp = NAN;
float lastHum = NAN;
float lastTemp = NAN;



void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  if(isnan(temp) || isnan(hum))
  {
    Serial.println("Failed to read the DHT sensor");
    return;
  }

  if(temp != lastTemp || hum !=lastHum) {

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  lastTemp = temp;
  lastHum = hum;

  }



}


