String ble_data;
int led_pin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  Serial.println("AT+ROLE=1");  // 设置蓝牙为从机
  delay(50);
  Serial.println("AT+BLEUSB=0");  //设置数据通信模式为0
  delay(50);
}

void loop() {
  while (Serial.available() > 0)  
  {
      ble_data += char(Serial.read());
      delay(2);
  }
  if (ble_data.compareTo("on") == 0) {
    Serial.println("turn on led");
    digitalWrite(led_pin, HIGH);
  }
  if (ble_data.compareTo("off") == 0) {
    Serial.println("turn off led");
    digitalWrite(led_pin, LOW);
  }   
  ble_data = "";
}