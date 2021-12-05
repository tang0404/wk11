#include <BluetoothSerial.h>
BluetoothSerial BT;

#define LED_1a 12
#define LED_1b 13
#define LED_2a 14
#define LED_2b 27

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("animal");//請改名
  pinMode(LED_1a, OUTPUT);
  pinMode(LED_1b, OUTPUT);
  pinMode(LED_2a, OUTPUT);
  pinMode(LED_2b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    if(BTdata == "1a"){
      digitalWrite(LED_1a, HIGH);
    }
    else if(BTdata == "1b"){
      digitalWrite(LED_1b, HIGH);
    }
    else if(BTdata == "2a"){
      digitalWrite(LED_2a, HIGH);
    }
    else if(BTdata == "2b"){
      digitalWrite(LED_2b, HIGH);
    }
    else if(BTdata == "0"){
      digitalWrite(LED_1a, LOW);
      digitalWrite(LED_1b, LOW);
      digitalWrite(LED_2a, LOW);
      digitalWrite(LED_2b, LOW);
    }
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
