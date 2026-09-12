# Security Proximity Alert System

**IEEE RAS VITC – Task 2: Sensors & Embedded Systems**

## 1. Problem

A security system needs a simple way to detect when an object or person approaches a protected area.

## 2. Solution

This project uses an **HC-SR04 ultrasonic sensor** connected to an **Arduino Uno**. The sensor continuously measures the distance to an object.

If the measured distance is **less than or equal to the configured threshold**, the system:

- Turns on a red LED
- Activates a buzzer
- Prints an alert message to the Serial Monitor

If the object is outside the threshold, the LED and buzzer remain off.

The default alert threshold is **50 cm** and can be changed in the Arduino code.

## 3. Components

| Component | Purpose |
|---|---|
| Arduino Uno | Main controller |
| HC-SR04 | Distance measurement |
| Red LED | Visual alert |
| 220 Ω resistor | LED current limiting |
| Piezo buzzer | Audible alert |
| Breadboard + jumper wires | Connections |

## 4. Wiring

### HC-SR04
- VCC → Arduino 5V
- GND → Arduino GND
- TRIG → Arduino D9
- ECHO → Arduino D10

### LED
- Arduino D7 → 220 Ω resistor → LED anode (+)
- LED cathode (-) → Arduino GND

### Buzzer
- Buzzer positive (+) → Arduino D8
- Buzzer negative (-) → Arduino GND

## 5. Working

1. Arduino sends a short trigger pulse to the HC-SR04.
2. The sensor sends an ultrasonic pulse and receives its echo.
3. Arduino measures the echo time.
4. The echo time is converted into distance in centimetres.
5. The distance is compared with `ALERT_DISTANCE_CM`.
6. If the object is within the threshold, the LED and buzzer are activated.
7. The current distance and system status are shown on the Serial Monitor.

## 6. Configurable Threshold

The threshold can be changed here:

```cpp
const int ALERT_DISTANCE_CM = 50;
```

For example, changing `50` to `30` makes the system trigger only when an object is 30 cm or closer.

## 7. Simulation

This project includes a `diagram.json` file for Wokwi.

Wokwi supports Arduino Uno and the HC-SR04 ultrasonic sensor, and the HC-SR04 distance can be changed interactively during simulation.

### Quick setup

1. Open Wokwi Arduino Uno: https://wokwi.com/projects/new/arduino-uno
2. Open the project.
3. Replace the generated `sketch.ino` with the `sketch.ino` from this repository.
4. Open `diagram.json` and replace its contents with the `diagram.json` from this repository.
5. Start the simulation.
6. Click the HC-SR04 sensor and change its distance.
7. Open the Serial Monitor to observe the readings.

## 8. Expected Output

When distance is greater than 50 cm:

```text
Distance: 80 cm -> SAFE
```

When distance is 50 cm or less:

```text
Distance: 35 cm -> ALERT: Object detected!
```

The LED turns on and the buzzer sounds during the alert.

## 9. Future Improvements

This basic prototype can be extended into a larger security system by adding:

- Multiple ultrasonic sensors for wider coverage
- PIR motion detection
- Wireless notifications
- A display for local status
- Data logging
- A mobile/web dashboard

## 10. Files

- `sketch.ino` – Arduino program
- `diagram.json` – Wokwi circuit layout
