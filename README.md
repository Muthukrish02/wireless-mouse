# ESP8266 Wireless Mouse using ADXL345

## 🚀 Overview
This project transforms an **ESP8266 + ADXL345 Accelerometer** into a wireless mouse. The ESP8266 sends motion data to a **PC via TCP**, where a Python script processes it and moves the mouse accordingly.

## 🛠️ Hardware Requirements
- **ESP8266 (NodeMCU / Wemos D1 Mini)**
- **ADXL345 Accelerometer**
- **Jumper Wires**
- **PC with Wi-Fi**

## 📡 Wiring Diagram
| ESP8266 | ADXL345 |
|---------|--------|
| **D1 (GPIO5)** | SCL |
| **D2 (GPIO4)** | SDA |
| **GND** | GND |
| **3.3V** | VCC |

## 🔧 Installation Steps

### **1️⃣ ESP8266 Setup**
1. Open **Arduino IDE**.
2. Install **ESP8266 Board Support** via Board Manager.
3. Install **"ESP8266WiFi"** and **"Wire"** libraries.
4. Upload the provided **ESP8266 Code** (edit Wi-Fi credentials and PC IP first).

### **2️⃣ PC Setup**
1. Install **Python 3.7+**.
2. Install dependencies:
   ```sh
   pip install pyautogui numpy
   ```
3. Run the Python script:
   ```sh
   python mouse_control.py
   ```

## 🎯 Features
✅ **Wireless mouse movement**
✅ **Fast response with TCP**
✅ **Kalman filtering for smooth movement**
✅ **Minimal latency (~5ms)**

## 📽️ Demo Video
_A demo video link can be added here once recorded._

## 📜 License
This project is **open-source** under the MIT License.

---
💡 *Feel free to contribute! Fork this repo and improve the accuracy or add gesture support!* 🚀

