////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright 2020 Christopher James Baker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

////////////////////////////////////////////////////////////////////////////////
// This sketch was only for personal practice and discovery purposes regarding
// the creation of musical notes & chords using both active and passive buzzers.
//  (the sound is much better with a passive buzzer but also works with active)
// There are libraries and other hardware/software configurations which would
// be faster and/or higher quality, but that was not the point. The point was to
// learn how to take the most basic circuit connected to an active or passive 
// buzzer and generate musical notes by toggling the circuit HIGH/LOW, and then
// see how effectively chords could be played through the same single active or
// passive buzzer, and then make music from those notes and chords. I chose the
// opening of Beethoven's 5th Symphony as the music to play.
//
// Special thanks to https://pages.mtu.edu/~suits/NoteFreqCalcs.html for the
// valuable insights into the science of generating musical notes
//
// Extra special thanks to Ludwig van Beethoven for being so flippin' awesome!

////////////////////////////////////////////////////////////////////////////////
// PINOUTS
// This project only requires one data pin to signal HIGH/LOW to the buzzer, so
// this can be used with any board.
const byte BUZZER_PIN = A5;

//Octaves 0-8
const byte OCTAVE_COUNT = 9;
//Notes C-B Indexing
const byte NOTE_COUNT = 12;
const byte NOTE_C_IX= 0;
const byte NOTE_Cs_IX= 1;
const byte NOTE_Db_IX= 1;
const byte NOTE_D_IX= 2;
const byte NOTE_Ds_IX= 3;
const byte NOTE_Eb_IX= 3;
const byte NOTE_E_IX= 4;
const byte NOTE_F_IX= 5;
const byte NOTE_Fs_IX= 6;
const byte NOTE_Gb_IX= 6;
const byte NOTE_G_IX= 7;
const byte NOTE_Gs_IX= 8;
const byte NOTE_Ab_IX= 8;
const byte NOTE_A_IX= 9;
const byte NOTE_As_IX= 10;
const byte NOTE_Bb_IX= 10;
const byte NOTE_B_IX= 11;
const String NOTE_NAME[NOTE_COUNT] = {
  "C", "C#/Db", "D", "D#/Eb",
  "E", "F", "F#/Gb", "G", 
  "G#/Ab", "A", "A#/Bb", "B"
};
/////////////////////////////////
// NOTES/OCTAVES C0-B8 
//  For Indexing/Scaling
//  e.g. A4 = NOTE_A_IX+ (octave * NOTE_COUNT)
//  equals A4 = 9 + (4 * 12)
//  equals A4 = 57
const byte NOTE_C0 = 0;
const byte NOTE_Cs0 = 1;
const byte NOTE_Db0 = 1;
const byte NOTE_D0 = 2;
const byte NOTE_Ds0 = 3;
const byte NOTE_Eb0 = 3;
const byte NOTE_E0 = 4;
const byte NOTE_F0 = 5;
const byte NOTE_Fs0 = 6;
const byte NOTE_Gb0 = 6;
const byte NOTE_G0 = 7;
const byte NOTE_Gs0 = 8;
const byte NOTE_Ab0 = 8;
const byte NOTE_A0 = 9;
const byte NOTE_As0 = 10;
const byte NOTE_Bb0 = 10;
const byte NOTE_B0 = 11;
const byte NOTE_C1 = 12;
const byte NOTE_Cs1 = 13;
const byte NOTE_Db1 = 13;
const byte NOTE_D1 = 14;
const byte NOTE_Ds1 = 15;
const byte NOTE_Eb1 = 15;
const byte NOTE_E1 = 16;
const byte NOTE_F1 = 17;
const byte NOTE_Fs1 = 18;
const byte NOTE_Gb1 = 18;
const byte NOTE_G1 = 19;
const byte NOTE_Gs1 = 20;
const byte NOTE_Ab1 = 20;
const byte NOTE_A1 = 21;
const byte NOTE_As1 = 22;
const byte NOTE_Bb1 = 22;
const byte NOTE_B1 = 23;
const byte NOTE_C2 = 24;
const byte NOTE_Cs2 = 25;
const byte NOTE_Db2 = 25;
const byte NOTE_D2 = 26;
const byte NOTE_Ds2 = 27;
const byte NOTE_Eb2 = 27;
const byte NOTE_E2 = 28;
const byte NOTE_F2 = 29;
const byte NOTE_Fs2 = 30;
const byte NOTE_Gb2 = 30;
const byte NOTE_G2 = 31;
const byte NOTE_Gs2 = 32;
const byte NOTE_Ab2 = 32;
const byte NOTE_A2 = 33;
const byte NOTE_As2 = 34;
const byte NOTE_Bb2 = 34;
const byte NOTE_B2 = 35;
const byte NOTE_C3 = 36;
const byte NOTE_Cs3 = 37;
const byte NOTE_Db3 = 37;
const byte NOTE_D3 = 38;
const byte NOTE_Ds3 = 39;
const byte NOTE_Eb3 = 39;
const byte NOTE_E3 = 40;
const byte NOTE_F3 = 41;
const byte NOTE_Fs3 = 42;
const byte NOTE_Gb3 = 42;
const byte NOTE_G3 = 43;
const byte NOTE_Gs3 = 44;
const byte NOTE_Ab3 = 44;
const byte NOTE_A3 = 45;
const byte NOTE_As3 = 46;
const byte NOTE_Bb3 = 46;
const byte NOTE_B3 = 47;
const byte NOTE_C4 = 48;
const byte NOTE_Cs4 = 49;
const byte NOTE_Db4 = 49;
const byte NOTE_D4 = 50;
const byte NOTE_Ds4 = 51;
const byte NOTE_Eb4 = 51;
const byte NOTE_E4 = 52;
const byte NOTE_F4 = 53;
const byte NOTE_Fs4 = 54;
const byte NOTE_Gb4 = 54;
const byte NOTE_G4 = 55;
const byte NOTE_Gs4 = 56;
const byte NOTE_Ab4 = 56;
const byte NOTE_A4 = 57;
const byte NOTE_As4 = 58;
const byte NOTE_Bb4 = 58;
const byte NOTE_B4 = 59;
const byte NOTE_C5 = 60;
const byte NOTE_Cs5 = 61;
const byte NOTE_Db5 = 61;
const byte NOTE_D5 = 62;
const byte NOTE_Ds5 = 63;
const byte NOTE_Eb5 = 63;
const byte NOTE_E5 = 64;
const byte NOTE_F5 = 65;
const byte NOTE_Fs5 = 66;
const byte NOTE_Gb5 = 66;
const byte NOTE_G5 = 67;
const byte NOTE_Gs5 = 68;
const byte NOTE_Ab5 = 68;
const byte NOTE_A5 = 69;
const byte NOTE_As5 = 70;
const byte NOTE_Bb5 = 70;
const byte NOTE_B5 = 71;
const byte NOTE_C6 = 72;
const byte NOTE_Cs6 = 73;
const byte NOTE_Db6 = 73;
const byte NOTE_D6 = 74;
const byte NOTE_Ds6 = 75;
const byte NOTE_Eb6 = 75;
const byte NOTE_E6 = 76;
const byte NOTE_F6 = 77;
const byte NOTE_Fs6 = 78;
const byte NOTE_Gb6 = 78;
const byte NOTE_G6 = 79;
const byte NOTE_Gs6 = 80;
const byte NOTE_Ab6 = 80;
const byte NOTE_A6 = 81;
const byte NOTE_As6 = 82;
const byte NOTE_Bb6 = 82;
const byte NOTE_B6 = 83;
const byte NOTE_C7 = 84;
const byte NOTE_Cs7 = 85;
const byte NOTE_Db7 = 85;
const byte NOTE_D7 = 86;
const byte NOTE_Ds7 = 87;
const byte NOTE_Eb7 = 87;
const byte NOTE_E7 = 88;
const byte NOTE_F7 = 89;
const byte NOTE_Fs7 = 90;
const byte NOTE_Gb7 = 90;
const byte NOTE_G7 = 91;
const byte NOTE_Gs7 = 92;
const byte NOTE_Ab7 = 92;
const byte NOTE_A7 = 93;
const byte NOTE_As7 = 94;
const byte NOTE_Bb7 = 94;
const byte NOTE_B7 = 95;
const byte NOTE_C8 = 96;
const byte NOTE_Cs8 = 97;
const byte NOTE_Db8 = 97;
const byte NOTE_D8 = 98;
const byte NOTE_Ds8 = 99;
const byte NOTE_Eb8 = 99;
const byte NOTE_E8 = 100;
const byte NOTE_F8 = 101;
const byte NOTE_Fs8 = 102;
const byte NOTE_Gb8 = 102;
const byte NOTE_G8 = 103;
const byte NOTE_Gs8 = 104;
const byte NOTE_Ab8 = 104;
const byte NOTE_A8 = 105;
const byte NOTE_As8 = 106;
const byte NOTE_Bb8 = 106;
const byte NOTE_B8 = 107;
/////////////////////////////////
// CHORDS
const byte CHORD_COUNT = 9;
const byte CHORD_MAJOR = 0;
const byte CHORD_MINOR = 1;
const byte CHORD_AUGMENTED = 2;
const byte CHORD_DIMINISHED = 3;
const byte CHORD_DOMINANT_7TH = 4;
const byte CHORD_MAJOR_7TH = 5;
const byte CHORD_MINOR_7TH = 6;
const byte CHORD_HALF_DIMINISHED_7TH = 7;
const byte CHORD_DIMINISHED_7TH = 8;
const String CHORD_NAME[CHORD_COUNT] = {
  "Major", "Minor", "Augmented", "Diminished", "Dominant-7th",
  "Major-7th", "Minor-7th", "Half-Diminished-7th", "Diminished-7th"
};
const byte CHORD_NOTE_COUNT[CHORD_COUNT] = {
  3, 3, 3, 3, 4, 4, 4, 4, 4
};
const byte CHORD_NOTE_COUNT_MAX = 4;
const byte CHORD_NOTE_ROOT = 0;
const byte CHORD_NOTE_THIRD = 1;
const byte CHORD_NOTE_FIFTH = 2;
const byte CHORD_NOTE_SEVENTH = 3;
const byte CHORD_NOTE_SHIFT[CHORD_COUNT][CHORD_NOTE_COUNT_MAX] = {
  { //MAJOR
    0, 4, 7, 0
  },
  { //MINOR
    0, 3, 7, 0
  },
  { //AUGMENTED
    0, 4, 8, 0
  },
  { //DIMINISHED
    0, 3, 6, 0
  },
  { //DOMINANT 7TH
    0, 4, 7, 10
  },
  { //MAJOR 7TH
    0, 4, 7, 11
  },
  { //MINOR 7TH
    0, 3, 7, 10
  },
  { //HALF-DIMINISHED 7TH
    0, 3, 6, 10
  },
  { //DIMINISHED 7TH
    0, 3, 6, 9
  }
};
/////////////////////////////////
// What's the frequency, Kenneth?
// https://pages.mtu.edu/~suits/NoteFreqCalcs.html
const int A4_Hz_DEFAULT = 440; //Set to your desired A4 frequency
const float TWELFTH = 1.0/12.0;
const float F_A = pow(2, TWELFTH);
const unsigned int MAX_MICROSEC_DELAY = 16383;
const unsigned long FULL_MEASURE = 1000; //milliseconds per whole note
const unsigned long REFRAIN = 16;
/////////////////////////////////
// Note values are the number of microseconds per half cycle required to perform 
//   1. HIGH for the half cycle
//   2. LOW for the half cycle
//  resulting in a full cycle generating a square wave at the frequency of the note
unsigned int notes[NOTE_COUNT*OCTAVE_COUNT];

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  setNotesToA4Hz(A4_Hz_DEFAULT);
  playBeethoven5th();
}

void loop() {
  // This plays in all chords, with a natural refresher in between
  delay(1000);
  playBeethoven5thInChord(CHORD_MAJOR);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_MINOR);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_AUGMENTED);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_DIMINISHED);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_DOMINANT_7TH);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_MAJOR_7TH);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_MINOR_7TH);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_HALF_DIMINISHED_7TH);
  delay(1000);
  playBeethoven5th();
  delay(1000);
  playBeethoven5thInChord(CHORD_DIMINISHED_7TH);
  delay(1000);
  playBeethoven5th();
}

void setNotesToA4Hz(int inA4Hz) {
  // https://pages.mtu.edu/~suits/NoteFreqCalcs.html
  float A4Hz = (float)inA4Hz;
  for (int i=0; i<(NOTE_COUNT*OCTAVE_COUNT); i++) {
    int n = i - (int)NOTE_A4;
    float noteHz = A4Hz * pow(F_A, float(n));
    float usPerCycle = 1000000.0/noteHz;
    notes[i] = (unsigned int)(usPerCycle/2.0);
  }
}

////////////////////////////////////////////////////////////////////////////////
// The functions playNote and playChord have the following to take note of:
//   division parameter - used to identify the type of note in 1/x form
//     ie. whole=1, half=2, quarter=4, eighth=8, etc...
//   FULL_MEASURE - identifies the tempo in ms per whole note
//   REFRAIN - rather arbitrary number to separate notes
//   MAX_MICROSEC_DELAY - Largest accurate value usable in delayMicroseconds()
//     https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/
void playNote(byte note, unsigned long division) {
  unsigned long sustain = (FULL_MEASURE / division) - REFRAIN;
  unsigned int halfCycle = notes[note];
  unsigned long finish = millis() + sustain;
  // Can we play in microseconds or must we use milliseconds?
  if (halfCycle > MAX_MICROSEC_DELAY) {
    unsigned long halfCycleMillis = (unsigned long)(halfCycle/1000);
    do {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(halfCycleMillis);
      digitalWrite(BUZZER_PIN, LOW);
      delay(halfCycleMillis);
    } while (millis() < finish);
  }
  else {
    do {
      digitalWrite(BUZZER_PIN, HIGH);
      delayMicroseconds(halfCycle);
      digitalWrite(BUZZER_PIN, LOW);
      delayMicroseconds(halfCycle);
    } while (millis() < finish);
  }
  delay(REFRAIN);
}

void playChord(byte note, byte chord, unsigned long division) {
  //Serial.print(CHORD_NOTE_COUNT[chord]);
  //Serial.print(" notes in ");
  //Serial.print(NOTE_NAME[(note % NOTE_COUNT)]);
  //Serial.print(note / NOTE_COUNT);
  //Serial.println(CHORD_NAME[chord]);
  unsigned int usCycle[CHORD_NOTE_COUNT[chord]];
  bool valid = true;
  for (int i=0; i<CHORD_NOTE_COUNT[chord]; i++) {
    //Serial.print(i);
    //Serial.print(" shift ");
    //Serial.print(CHORD_NOTE_SHIFT[chord][i]);
    //Serial.print(" to ");
    //Serial.println(NOTE_NAME[((note + CHORD_NOTE_SHIFT[chord][i]) % NOTE_COUNT)]);
    if ((note + CHORD_NOTE_SHIFT[chord][i]) < (NOTE_COUNT * OCTAVE_COUNT)) {
      usCycle[i] = notes[(note + CHORD_NOTE_SHIFT[chord][i])];
    }
    else {
      Serial.print("Invalid chord ");
      Serial.print(NOTE_NAME[note % NOTE_COUNT]);
      Serial.print(note / NOTE_COUNT);
      Serial.println(CHORD_NAME[chord]);
      return;
    }
    //Serial.println("");
  }
  unsigned long sustain = (FULL_MEASURE / division) - REFRAIN;
  unsigned long finish = millis() + sustain;
  // If all notes can be played in microseconds
  if (
  (usCycle[0] <= MAX_MICROSEC_DELAY)
  && (usCycle[CHORD_NOTE_COUNT[chord]] <= MAX_MICROSEC_DELAY)) {
    do {
      for (int i=0; i<CHORD_NOTE_COUNT[chord]; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delayMicroseconds(usCycle[i]);
        digitalWrite(BUZZER_PIN, LOW);
        delayMicroseconds(usCycle[i]);
      }
    } while (millis() < finish);
  }
  // if all notes must be in milliseconds
  else if (
  (usCycle[0] > MAX_MICROSEC_DELAY)
  && (usCycle[CHORD_NOTE_COUNT[chord]] > MAX_MICROSEC_DELAY)) {
    unsigned long msCycle[CHORD_NOTE_COUNT[chord]];
    for (int i=0; i<CHORD_NOTE_COUNT[chord]; i++) {
      msCycle[i] = (unsigned long)(usCycle[i] / 1000);
    }
    do {
      for (int i=0; i<CHORD_NOTE_COUNT[chord]; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(msCycle[i]);
        digitalWrite(BUZZER_PIN, LOW);
        delay(msCycle[i]);
      }
    } while (millis() < finish);
  }
  // mix of notes in microseconds and milliseconds
  else {
    unsigned long msCycle[CHORD_NOTE_COUNT[chord]];
    bool micros[CHORD_NOTE_COUNT[chord]];
    for (int i=0; i<CHORD_NOTE_COUNT[chord]; i++) {
      if (usCycle[i] > MAX_MICROSEC_DELAY) {
        msCycle[i] = (unsigned long)(usCycle[i] / 1000);
        micros[i] = false;
      }
      else {
        msCycle[i] = 0;
        micros[i] = true;
      }
    }
    do {
      for (int i=0; i<CHORD_NOTE_COUNT[chord]; i++) {
        if (micros[i]) {
          digitalWrite(BUZZER_PIN, HIGH);
          delayMicroseconds(usCycle[i]);
          digitalWrite(BUZZER_PIN, LOW);
          delayMicroseconds(usCycle[i]);
        } 
        else {
          digitalWrite(BUZZER_PIN, HIGH);
          delay(msCycle[i]);
          digitalWrite(BUZZER_PIN, LOW);
          delay(msCycle[i]);
        }
      }
    } while (millis() < finish);
  }
  delay(REFRAIN);
}

void playBeethoven5th() {
  Serial.println("Natural");
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_Eb4, 1);
  playNote(NOTE_F4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_D4, 1);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_C4, 8);
  playNote(NOTE_Eb4, 8);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_Eb4, 4);
  playNote(NOTE_Eb4, 4);
  playNote(NOTE_Eb4, 4);
  playNote(NOTE_C4, 1);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_B4, 8);
  playNote(NOTE_D4, 8);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_D4, 1);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_Eb4, 1);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_Eb4, 1);
  playNote(NOTE_G4, 4);
  playNote(NOTE_G4, 4);
  playNote(NOTE_F4, 4);
  playNote(NOTE_Eb4, 4);
  delay(750);
  playNote(NOTE_C4, 4);
  delay(750);
  playNote(NOTE_G4, 1);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_Ab4, 4);
  playNote(NOTE_F4, 1);
}

void playBeethoven5thInChord(byte chord) {
  Serial.println(CHORD_NAME[chord]);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_Eb4, chord, 1);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_D4, chord, 1);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_C4, chord, 8);
  playChord(NOTE_Eb4, chord, 8);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_Eb4, chord, 4);
  playChord(NOTE_Eb4, chord, 4);
  playChord(NOTE_Eb4, chord, 4);
  playChord(NOTE_C4, chord, 1);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_B4, chord, 8);
  playChord(NOTE_D4, chord, 8);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_D4, chord, 1);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_Eb4, chord, 1);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_Eb4, chord, 1);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_G4, chord, 4);
  playChord(NOTE_F4, chord, 4);
  playChord(NOTE_Eb4, chord, 4);
  delay(750);
  playChord(NOTE_C4, chord, 4);
  delay(750);
  playChord(NOTE_G4, chord, 1);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_Ab4, chord, 4);
  playChord(NOTE_F4, chord, 1);
}
