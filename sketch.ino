#define BLYNK_PRINT Serial  // Debugging to Serial Monitor

#define BLYNK_TEMPLATE_ID "TMPL3zI5tBXlx"
#define BLYNK_TEMPLATE_NAME "Dust Monitor"
#define BLYNK_AUTH_TOKEN "4XwCfjT2VeOYooFm6Zoq4zaeuDqp7FRW"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";    // WiFi name
char pass[] = "";               // WiFi password 

BlynkTimer timer;

#define DUST_SENSOR_PIN 34  // Analog input (simulated dust sensor - potentiometer)
#define LED_PIN 2           // Onboard LED for alert
#define BUZZER_PIN 13        // Buzzer for alert

bool alertSent = false;

void setup() {
  Serial.begin(115200);

  pinMode(DUST_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, checkDustLevel);  // Check dust every 1 second
}

void checkDustLevel() {
  int dustValue = analogRead(DUST_SENSOR_PIN);
  Serial.print("Dust Level: ");
  Serial.println(dustValue);

  Blynk.virtualWrite(V0, dustValue);

  if (dustValue > 2000) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);  // Start buzzer tone

    if (!alertSent) {
      Blynk.logEvent("dust_alert", "High dust level detected!");
      alertSent = true;
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);  // Stop buzzer tone
    alertSent = false;
  }
}


void loop() {
  Blynk.run();
  timer.run();
}
