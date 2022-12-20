const int ledPin = 16;
bool ledStatus = false;



void setup() {
  Serial.begin(9600);//here 9600 is baud rate

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}
void loop() {
  if (Serial.available() > 0) { //checking data availability
    String data = Serial.readStringUntil('\n'); //reading line

    String checkstringforLED = "1";

    if(data.compareTo(checkstringforLED) == 0){
        digitalWrite(ledPin, HIGH);
        ledStatus = true;
    }else{
        digitalWrite(ledPin, LOW);
        ledStatus = false;
    }


    // Serial.print("You sent me: "); //retransmitting
    Serial.println(ledStatus); //retransmitting
  }
}