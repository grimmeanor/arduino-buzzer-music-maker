# arduino-buzzer-music-maker
Generate music using simple active and passive buzzer circuits pulled HIGH/LOW

This sketch was only for personal practice and discovery purposes regarding
the creation of musical notes & chords using both active and passive buzzers.
 (the sound is much better with a passive buzzer but also works with active)
There are libraries and other hardware/software configurations which would
be faster and/or higher quality, but that was not the point. The point was to
learn how to take the most basic circuit connected to an active or passive 
buzzer and generate musical notes by toggling the circuit HIGH/LOW, and then
see how effectively chords could be played through the same single active or
passive buzzer, and then make music from those notes and chords. I chose the
opening of Beethoven's 5th Symphony as the music to play.

[Project assembly](https://user-images.githubusercontent.com/20711484/184712946-89a3d328-0530-4271-ac1d-f30e6506cacf.png) only requires one data pin to signal HIGH/LOW to the buzzer,
so this can be used with any board. Then connect the buzzer ground pin to GND
on the Arduino. That's it!

Special thanks to https://pages.mtu.edu/~suits/NoteFreqCalcs.html for the
valuable insights into the science of generating musical notes

Extra special thanks to Ludwig van Beethoven for being so flippin' awesome!
