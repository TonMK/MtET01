#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);

  // ตั้งชื่อ Bluetooth
  SerialBT.begin("ESP32_BT");

  Serial.println("Bluetooth Started!");
}

void loop() {

  // รับข้อมูลจาก Bluetooth
  if (SerialBT.available()) {
    String data = SerialBT.readStringUntil('\n');

    Serial.print("Received from Bluetooth: ");
    Serial.println(data);

    // ส่งข้อความตอบกลับ
    SerialBT.print("You sent: ");
    SerialBT.println(data);
  }

  // ส่งข้อมูลจาก Serial Monitor ไปยัง Bluetooth
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');

    SerialBT.print("PC: ");
    SerialBT.println(data);
  }
}