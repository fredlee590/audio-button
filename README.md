Audio Button
============

Simple audio button based on an Arduino sketch running on the [Adafruit ItsyBitsy
(3.3V variant)](https://www.adafruit.com/product/3675) that controls a [DFPlayer
Mini](https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299).

Hardware
--------
Under construction.

Software
--------

This system's behavior is controlled entirely via Arduino sketch, located in
`sw/audio-button/`. At the moment, the only sketch is one that cycles through
the audio files on the SD card.

This and future sketches of course, rely on the provided [DFRobotDFPlayerMini
library for
Arduino](https://github.com/DFRobot/DFRobotDFPlayerMini/archive/1.0.3.zip)

TODO: Add button support.
