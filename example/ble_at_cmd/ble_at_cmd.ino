String ble_data;
int led_pin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  Serial.println("AT+ROLE=0");  // 设置蓝牙为主机
  delay(50);                   // AT设置完必须50ms以上
  Serial.println("AT+CON=83:46:8c:e4:c2:84");  //连接mac地址的蓝牙从机
  delay(50);
}

void loop() {
  while (Serial.available() > 0)  
  {
      ble_data += char(Serial.read());
      delay(2);
  }
  if (ble_data.endsWith("OK\r\n") > 0) {
    Serial.println("connect success");
    digitalWrite(led_pin, HIGH);
  }
  if (ble_data.endsWith("ERROR\r\n") > 0) {
    Serial.println("connect fail");
    digitalWrite(led_pin, LOW);
  }
  ble_data = "";
}