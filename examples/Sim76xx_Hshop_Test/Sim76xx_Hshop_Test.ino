String SDT1="0934022501";  

int gui = 1;
String inputString;

void setup() {

  Serial.begin(115200);  // mở serial với baudrate  (SIM4G 7680c)
  

  guilenh();
  SMSTest();
  delay(20000);
  CallTest();
}

void delay2() {
  for (int b = 0; b < 1000; b++) {
    inputString = "";
    delay(1);
    if (Serial.available() > 0) {
      delay(500);  // wait data
      inputString = "";
      while (Serial.available()) {
        char inChar = (char)Serial.read();
        inputString += inChar;
      }
      delay(100);
      b = 1000;
      Serial.println(">>");
      Serial.println(inputString);
    }
  }
}

void guilenh() {

  Serial.print("AT\r\n");
  delay(500);
  delay2();

  Serial.print("ATE0\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CSCS=\"GSM\"\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CMGF=1\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CNMI=2,2,0,0,0\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CMGD=1\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CLIP=1\r\n");
  delay(500);
  delay2();

  Serial.print("AT&W\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CSQ\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CSQ\r\n");
  delay(500);
  delay2();

  Serial.print("AT+CSQ\r\n");
  delay(500);
  delay2();
}

void CallTest() {
  Serial.print("ATD");delay(200);   //call
  Serial.print(SDT1);delay(200);
  Serial.println(";");  delay2();
  delay(20000);
  Serial.println("AT+CHUP"); // 
}

void SMSTest() {

  Serial.print("AT+CMGS=\"" + SDT1 +"\"\r");  // Số điên thoại của người nhân theo format quốc tế
  delay(200);
  Serial.print("HE THONG DA KHOI DONG!");  // gửi nội dung tin nhắn
  delay(200);
  Serial.print((char)26);  // Kết thúc lênh gửi
  delay(5000);
}

void loop() {
  delay2();
}
