#include <BluetoothSerial.h>

#define LED 14
BluetoothSerial BT;
String btLED;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  BT.begin("animal");//請改名
}



void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
     if(BTdata == "a") {
      digitalWrite(LED, HIGH);
      Serial.println("HIGH");
     }
     else if(BTdata == "b"){
      digitalWrite(LED, LOW);
      Serial.println("LOW");
     }
    //顯示在序列視窗
//    Serial.println(BTdata);
//    btLED = BT.readString();
//    Serial.println(btLED);
  }
  //delay(1);
}
