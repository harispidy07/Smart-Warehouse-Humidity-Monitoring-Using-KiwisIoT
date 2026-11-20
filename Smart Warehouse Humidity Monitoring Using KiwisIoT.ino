#include <DHT.h>
#include <KiwisIoT.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

// DHT11 sensor
#define DHT_PIN D2
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

// Humidity threshold
const float HUMIDITY_LIMIT = 60.0;

// Update interval
unsigned long lastSend = 0;
const unsigned long SEND_INTERVAL = 5000;

float humidity = 0;
float temperature = 0;

String humidityStatus = "NORMAL";

void setup()
{
  Serial.begin(115200);

  dht.begin();

  kiwisiot.begin();

  Serial.println("Warehouse Humidity Monitoring Started");
}

void loop()
{
  kiwisiot.run();

  if (millis() - lastSend >= SEND_INTERVAL)
  {
    lastSend = millis();

    humidity = dht.readHumidity();
    temperature = dht.readTemperature();

    // Sensor validation
    if (isnan(humidity) || isnan(temperature))
    {
      Serial.println("DHT11 Sensor Error");
      return;
    }

    // Humidity evaluation
    if (humidity > HUMIDITY_LIMIT)
    {
      humidityStatus = "HIGH HUMIDITY";
    }
    else
    {
      humidityStatus = "NORMAL";
    }

    // Serial Monitor
    Serial.println("----------------------");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity Status: ");
    Serial.println(humidityStatus);

    // Send data to KiwisIoT
    kiwisiot.send("0", String(humidity, 1));

    kiwisiot.send("1", String(temperature, 1));

    kiwisiot.send("2", humidityStatus);
  }
}