# Dust Monitoring System using ESP32 and Blynk

## Overview

This project is an IoT-based Dust Monitoring System developed using ESP32 and Blynk.

The system continuously monitors dust levels and sends real-time updates to the Blynk dashboard. When the dust level exceeds a predefined threshold, the system activates visual and audio alerts and sends a notification through Blynk.

The project was developed and tested using the Wokwi simulator.

---

## Features

- Real-time dust level monitoring
- ESP32-based implementation
- Blynk cloud integration
- LED alert indication
- Buzzer warning system
- Push notifications
- Wokwi simulation support

---

## Components Used

- ESP32
- Dust Sensor (Simulated using Potentiometer)
- LED
- Resistor
- Buzzer
- Blynk IoT Platform

---

## Working Principle

1. Dust level is simulated using a sensor input.
2. ESP32 continuously reads sensor values.
3. Sensor data is sent to the Blynk dashboard.
4. When the dust level exceeds the threshold:
   - LED turns ON
   - Buzzer activates
   - Notification is sent through Blynk

---

## Project Structure

```text
ESP32-Dust-Monitoring-System
│
├── sketch.ino
├── diagram.json
├── libraries.txt
└── wokwi-project.txt
```

---

## Wokwi Simulation

Project Link:

https://wokwi.com/projects/429129598425196545

---

## Sample Alert Logic

```cpp
if (dustValue > 2000) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);

    Blynk.logEvent(
        "dust_alert",
        "High dust level detected!"
    );
}
```

---

## Applications

- Air Quality Monitoring
- Smart Cities
- Environmental Monitoring
- Industrial Safety Systems
- Indoor Air Quality Assessment

---

## Future Enhancements

- Real dust sensor integration
- AQI (Air Quality Index) calculation
- Historical data storage
- Mobile dashboard analytics
- Cloud-based monitoring

---

## Author

Hamsa Vardhini

BE Computer Science and Engineering

---

## License

This project is intended for academic and learning purposes.
