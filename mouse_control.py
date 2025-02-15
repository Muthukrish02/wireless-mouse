import socket
import pyautogui

ESP8266_IP = "192.168.185.247"  
PORT = 80

prev_x, prev_y = 0, 0
sensitivity = 0.50  # Adjust sensitivity

def get_sensor_data():
    try:
        with socket.create_connection((ESP8266_IP, PORT), timeout=1) as s:
            data = s.recv(1024).decode().strip()
            return list(map(int, data.split(",")))
    except:
        return None

while True:
    result = get_sensor_data()
    if result:
        x, y = result
        dx = int((x - prev_x) * sensitivity)
        dy = int((y - prev_y) * sensitivity)
        pyautogui.moveRel(dx, -dy)  # Move mouse
        prev_x, prev_y = x, y
