# DC Motor Speed and Direction Control using L298N

## MY TASK
To control the speed of a DC motor using a potentiometer and change its rotation direction using a push button.

---

## APPROACH

### 1. Understanding the Motor Driver
I first studied the **L298N motor driver** to understand how it controls a DC motor and how its pins are used.

---

### 2. Pin Functions
- **Enable pins (ENA/ENB):** Used for speed control using PWM  
- **Input pins (IN1, IN2):** Used for controlling motor direction  

---

### 3. Direction Control Logic

| IN1 | IN2 | OUTPUT   |
|-----|-----|----------|
| 0   | 0   | STOP     |
| 1   | 0   | FORWARD  |
| 0   | 1   | REVERSE  |
| 1   | 1   | STOP     |

Note: Only (1,0) and (0,1) are used for normal direction switching. The other states result in stopping or braking.

---

### 4. Pin Mapping Decision
Based on the above understanding:
- Enable pins were connected to PWM-capable pins on the Arduino for speed control  
- Input pins were connected to digital pins for direction control  

---

### 5. Direction Control Implementation
A push button was used to toggle motor direction.  
To ensure immediate response without relying on polling, **external interrupts (`attachInterrupt()`)** were used.

---

### 6. Speed Control Implementation
A potentiometer was used to control motor speed.  
The analog reading (0–1023) was linearly mapped to a PWM range (0–255) and used to control the enable pin.

---
