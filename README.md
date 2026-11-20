# Smart Warehouse Humidity Monitoring Using KiwisIoT

## Project Overview

This project monitors temperature and humidity conditions inside a warehouse using IoT technology. The NodeMCU ESP8266 collects environmental data and sends it to the KiwisIoT dashboard, allowing users to monitor warehouse conditions remotely and identify abnormal environmental changes.

## Hardware Components

- NodeMCU ESP8266
- DHT11 Temperature and Humidity Sensor
- Jumper wires
- Power supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- DHT Sensor Library
- KiwisIoT Arduino Library
- KiwisIoT Dashboard

## Circuit Connections

| DHT11 Sensor | NodeMCU ESP8266 |
| ------------ | --------------- |
| VCC          | 3.3V            |
| GND          | GND             |
| DATA         | D2              |

## Working Principle

The DHT11 sensor measures the temperature and humidity inside the warehouse. The NodeMCU ESP8266 reads the sensor data and compares the values against predefined environmental limits.

The ESP8266 transmits temperature, humidity, and warehouse status to the KiwisIoT platform over Wi-Fi. If the monitored values exceed the configured limits, the system reports an ALERT status.

## KiwisIoT Dashboard

| Channel   | Data                              |
| --------- | --------------------------------- |
| Channel 0 | Temperature (°C)                  |
| Channel 1 | Humidity (%)                      |
| Channel 2 | Warehouse Status (NORMAL / ALERT) |

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the project configuration.

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

## Applications

- Warehouse environmental monitoring
- Product storage management
- Food and grocery storage
- Electronics storage facilities
- Humidity-sensitive product monitoring

## Project Reference

**Hackster.io Project:**  
[Smart Warehouse Humidity Monitoring Using KiwisIoT](https://www.hackster.io/harispidy07/smart-warehouse-humidity-monitoring-using-kiwisiot-f780f9)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Monitor warehouse environmental conditions with connected IoT technology._
