#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

//int folder = 1;
//int file = 1;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  delay(2000);
  Serial.println("Attempting to start");

  if(!myDFPlayer.begin(Serial1, true, true)) {
    Serial.println("Unable to start DF Player Mini!");
    while(true);
  } else {
    Serial.println("DF Player Mini started successfully.");
  }

  myDFPlayer.stop();
  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(1);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}

void loop() {
  //Serial.println("Attempting to play mp3 (" + String(folder) + ", " + String(file) + ".mp3)");
  Serial.println("Attempting to play next mp3");
  //myDFPlayer.playFolder(folder, file);
  //myDFPlayer.play(1);
  myDFPlayer.next();
  delay(5000);
}
