String ble_data;
int led_pin = 13;
int ble_status = 0;
void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  Serial.println("AT+ROLE=0");    // 设置蓝牙为主机
  delay(50);
  Serial.println("AT+BLEUSB=0");  // 设置蓝牙为主机
  delay(50);
  Serial.println("AT+CON=83:46:8c:e4:c2:84");  //连接mac地址的蓝牙从机
  delay(50);
  ble_data = "";
  while (Serial.available() > 0)  
  {
      ble_data += char(Serial.read());
      delay(2);
  }
  if (ble_data.endsWith("OK\r\n") > 0) {
    Serial.println("connect success");
    digitalWrite(led_pin, HIGH);
	ble_status = 1;
  }
  if (ble_data.endsWith("ERROR\r\n") > 0) {
    Serial.println("connect fail");
    digitalWrite(led_pin, LOW);
	ble_status = 0;
  }
}

void loop() {

  if (ble_status)
  {
	  Serial.println("on");
	  delay(1000);
	  Serial.println("off");
	  delay(1000);
  }
}