#include <WiFi.h>
#include <WakeOnLan.h>

const char* ssid     = "NetworkName"; //Your ssid
const char* password = "NetworkPassword"; // password for network
const char* targetMac = "AA:BB:CC:DD:EE:FF";  // Replace with your PC’s MAC

#define TRIG_PIN 5
#define ECHO_PIN 18

WiFiUDP udp;
WakeOnLan wol(udp);

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");

}

void loop() {
  long duration, distance;

  // Trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 50) {
    Serial.println("Person detected. Sending Wake-on-LAN...");
    wol.sendMagicPacket(targetMac);
    delay(15000);  // avoid spamming
  }

  delay(1000);
}

