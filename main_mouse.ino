#include <Wire.h>
#include <ESP8266WiFi.h>

#define ADXL345_ADDR 0x53

const char* ssid = "Groot++";
const char* password = "Muthukr3";
WiFiServer server(80);

void setup() {
    Serial.begin(115200);
    Wire.begin(4, 5); // SDA=D2(GPIO4), SCL=D1(GPIO5)

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
    server.begin();

    // Initialize ADXL345
    Wire.beginTransmission(ADXL345_ADDR);
    Wire.write(0x2D);
    Wire.write(0x08);
    Wire.endTransmission();
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        int16_t x, y, z;
        Wire.beginTransmission(ADXL345_ADDR);
        Wire.write(0x32);
        Wire.endTransmission(false);
        Wire.requestFrom(ADXL345_ADDR, 6, true);

        if (Wire.available() == 6) {
            x = Wire.read() | (Wire.read() << 8);
            y = Wire.read() | (Wire.read() << 8);
            z = Wire.read() | (Wire.read() << 8);
        }

        String data = String(x) + "," + String(y);
        client.println(data);
        client.stop();
        delay(2);
    }
}
