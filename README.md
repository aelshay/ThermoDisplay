# Arduino Temperature Monitor with LCD Display

A simple embedded systems project that uses an Arduino, a 100k thermistor, and a 16x2 LCD screen to measure and display real-time temperature in both °C and °F. Built as a personal learning project to practice circuit design, analog signal processing, and LCD interfacing.

---

## Components Used

- Arduino Uno
- 100k NTC Thermistor
- 100k Resistor (1% recommended)
- 16x2 LCD (HD44780, parallel interface)
- 10k Potentiometer (for LCD contrast)
- Breadboard and jumper wires

---

## Getting Started

1. Clone or download this repository
2. Open `ThermoDisplay.ino` in the Arduino IDE
3. Select your board (**Tools > Board > Arduino Uno**)
4. Connect your Arduino via USB
5. Upload the sketch
6. View real-time temperature readings on the LCD in both °C and °F

---

## Wiring Instructions

### Thermistor Voltage Divider:
- One leg of thermistor → **5V**
- Other leg of thermistor → **A0**
- A0 also connects to → **100kΩ resistor → GND**

### LCD Connections (4-bit mode):

| LCD Pin | Arduino Pin                         | Description            |
|---------|-------------------------------------|------------------------|
| VSS     | GND                                 | Ground                 |
| VDD     | 5V                                  | Power                  |
| VO      | Potentiometer middle pin (wiper)    | Contrast control       |
| RS      | D12                                 | Register Select        |
| RW      | GND                                 | Write mode             |
| E       | D11                                 | Enable                 |
| D4      | D5                                  | Data                   |
| D5      | D4                                  | Data                   |
| D6      | D3                                  | Data                   |
| D7      | D2                                  | Data                   |
| A       | 5V                                  | LCD backlight anode    |
| K       | GND                                 | LCD backlight cathode  |

### Potentiometer Wiring:
- Left pin → **GND**
- Right pin → **5V**
- Middle pin → **LCD pin 3 (VO)**

---

## Temperature Calculation

This project uses the **Steinhart–Hart equation** to convert thermistor resistance to temperature:

```cpp
float c1 = 0.000570569668;
float c2 = 0.000239294362;
float c3 = 0.000000047282773;
```

## Circuit Diagram

### 1. Breadboard Layout (Fritzing)
This shows the clean wiring diagram to replicate the setup easily:

![diagram](https://github.com/user-attachments/assets/10d6618d-bcd6-4b14-b73d-56959b9734a9)

### 2. Real Circuit Photo
This is the actual working setup on a physical breadboard:

![realbuild](https://github.com/user-attachments/assets/99bec27b-d7be-4a3d-9b3d-ee068029cebf)

## What I Learned

- How to use a 100k NTC thermistor in a voltage divider circuit
- Applying the Steinhart–Hart equation for accurate temperature readings
- Averaging analog readings to smooth out noisy sensor data
- Using a potentiometer to adjust LCD contrast in real-time
- Wiring a 16x2 LCD display in 4-bit parallel mode
- Visualizing circuit designs with Fritzing for clearer documentation
- Documenting and organizing a personal Arduino project for GitHub

---

## Troubleshooting & Challenges

- **Incorrect Temperature Readings**  
  Discovered that the original resistor used didn’t match the thermistor’s rating (100k). Replacing it with the correct 100k fixed resistor fixed the reading accuracy.

- **Noisy Analog Input**  
  Fluctuating temperature values were smoothed out by adding a function to average multiple analog readings.

- **Contrast Issues**  
  Initially had maximum contrast causing unreadable characters. Learned that contrast is controlled via the VO pin and resolved it by connecting a 10k potentiometer for adjustable contrast control.

- **LCD Not Displaying Characters**  
  Resolved by wiring the LCD in 4-bit mode correctly and tying RW to GND. Also ensured proper initialization in code.

- **Breadboard Power Rail Misunderstanding**  
  Realized the top and bottom power rails on the breadboard were not internally connected. Fixed by bridging the rails with jumper wires.

- **Unstable Thermistor Readings Due to Wiring**  
  Improved consistency by checking breadboard connections and verifying proper thermistor orientation.

- **Readability in Circuit Documentation**  
  Chose to include a clean Fritzing breadboard diagram instead of a messy schematic view, and paired it with a real photo for reference.
