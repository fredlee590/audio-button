#include <DFRobotDFPlayerMini.h>
#define HW_INT_PIN 7
#define LED_PIN 13

DFRobotDFPlayerMini myDFPlayer;

bool play_when_ready;

void queue_playback() {
  play_when_ready = true;
}

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  delay(2000);
  Serial.println("Attempting to start");

  if(!myDFPlayer.begin(Serial1, true, true)) {
    Serial.println("Unable to start DF Player Mini!");
    //while(true);
  } else {
    Serial.println("DF Player Mini started successfully.");

    myDFPlayer.stop();
    myDFPlayer.setTimeOut(500);
    myDFPlayer.volume(10);
    myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
    myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  }

  play_when_ready = false;
  pinMode(HW_INT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  attachInterrupt(digitalPinToInterrupt(HW_INT_PIN), queue_playback, FALLING);
}

void loop() {
  Serial.println("loop");
  if (play_when_ready) {
    Serial.println("playing");
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    myDFPlayer.next();
    play_when_ready = false;
  }
  delay(100);
}
