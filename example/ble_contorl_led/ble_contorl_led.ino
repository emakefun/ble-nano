String ble_data;
int led_pin = 13;

void setup(){
  Serial.begin(115200);
  Serial.println("ble control led");
  ble_data = "";
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, HIGH);
}

void loop(){
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
