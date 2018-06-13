
/*************************************
* The original code is written by Laurens Wuyts
* For questions: laurens.wuyts@gmail.com
* multifunctional abuilities with digiread program
* by m3ni, admin@m3ni.ir
* m3ni021@gmail.com
* 
* 
* Microcontroller: ATtiny85
* Dev board:       Digispark 16mhz
* 
*************************************/
#include "TrinketHidCombo.h"

#define TRINKET_PINx  PINB



uint8_t situation = 0;
uint8_t START = 0;
uint8_t x = 0;
uint8_t BIT = 0;
uint8_t Id = 0;
uint8_t Id_inv = 0;
uint8_t Data = 0;
uint8_t Data_back = 0;
uint8_t Data_inv = 0;
uint8_t Repeat = 0;
uint8_t sended = 0;
uint8_t val = 0;

uint16_t Time_old = 0;
uint16_t Time = 0;
uint16_t TimeDelta = 0;
 
void setup(void) {
  attachInterrupt(0, IR_Read, FALLING);
  pinMode(1,OUTPUT);
  digitalWrite(1,LOW);
  TrinketHidCombo.begin();
}
 
void loop(void) {
  if(sended == 1) {
    val = Data_back,DEC;
    if (val == 232) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_UP); 
      }
    if (val == 80) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_MUTE);  
      }
    if (val == 56) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_VOL_DOWN); 
      }
//    if (val == 208) {
//      TrinketHidCombo.pressSystemCtrlKey(SYSCTRLKEY_POWER);
//      }
    if (val == 98) {
      TrinketHidCombo.mouseMove(-5,0,0);
      }
    if (val == 176) {
      TrinketHidCombo.mouseMove(5,0,0);
      }
    if (val == 162) {
      TrinketHidCombo.mouseMove(0,-5,0);
      }
    if (val == 146) {
      TrinketHidCombo.mouseMove(0,5,0);
      }
    if (val == 240) {
      TrinketHidCombo.mouseMove(0,0,MOUSEBTN_LEFT_MASK);
      TrinketHidCombo.mouseMove(0,0,0);
      }
    if (val == 218) {
      TrinketHidCombo.mouseMove(0,0,MOUSEBTN_RIGHT_MASK);
      TrinketHidCombo.mouseMove(0,0,0);
      }
    if (val == 148) {
      TrinketHidCombo.mouseMove(0,0,MOUSEBTN_MIDDLE_MASK);
      TrinketHidCombo.mouseMove(0,0,0);
      }
    if (val == 104) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_PLAYPAUSE);
      }
    if (val == 8) {
      TrinketHidCombo.pressMultimediaKey(MMKEY_KB_MENU);
      }
    if (val == 130) {
      TrinketHidCombo.pressKey(0, KEYCODE_MOD_LEFT_ALT, KEYCODE_F4);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 48) {
      TrinketHidCombo.pressKey(0, KEYCODE_PAGE_UP);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 136) {
      TrinketHidCombo.pressKey(0, KEYCODE_PAGE_DOWN);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 216) {
      TrinketHidCombo.pressKey(0, KEYCODE_F1);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 82) {
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.write("This is a sample text from M3NI's AVR");
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 194) {
      TrinketHidCombo.pressKey(0, KEYCODE_U);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 2) {
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_I);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 226) {
      TrinketHidCombo.pressKey(0, KEYCODE_G);
      TrinketHidCombo.pressKey(0, 0);
    }
    if (val == 34) {
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.write("Hello Players!");
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.write("Gameplay of this player is enhanced by");
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.write("An Attiny85 Chip. Powered by an AI - v0.2 Beta");
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.write("Send your feedbacks to admin@m3ni.ir");
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      TrinketHidCombo.write("Thankyou!");
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
      }
    if (val == 120) {
      TrinketHidCombo.pressKey(0, KEYCODE_ENTER);
      TrinketHidCombo.pressKey(0, 0);
    }
    

    sended = 0;
  } else {
    delay(10);
  }
}

void IR_Read(void) {
  digitalWrite(1,HIGH);
  Time = micros();
  if (Time_old != 0) {
    TimeDelta = Time - Time_old;
    if ((TimeDelta > 12000)&&(TimeDelta < 14000)) {
      START = 1;
      x = 0;
      situation = 1;
      Id = 0;
      Id_inv = 0;
      Data = 0;
      Data_inv = 0;
    } else if ((TimeDelta > 10000)&&(TimeDelta < 12000)) {
      situation = 2; // repeat
    } else if ((TimeDelta > 1500)&&(TimeDelta < 2500)) {
      situation = 3; //"1"
      BIT = 1;
    } else if ((TimeDelta > 1000)&&(TimeDelta < 1500)) {
      situation = 3; //"0"
      BIT = 0;
    } else situation = 5; 
    if (situation == 3) {
      if (x < 8) {
        Id |= BIT;
        if (x < 7) Id <<= 1;  
        x++;
      } else if (x < 16) {
        Id_inv |= BIT;
        if (x < 15) Id_inv <<= 1;
        x++;
      } else if (x < 24) {
        Data |= BIT;
        if (x < 23) Data <<= 1;
        x++;
      } else if (x < 32) {
        Data_inv |= BIT;
        if (x < 31) {
          Data_inv <<= 1;
        } else {
          
          /* DO SOMETHING HERE */
          sended = 1;
          
          Data_back = Data;
          Repeat = 0;
        }
        x++;
      }
    } else if (situation == 2) {
      if(Repeat == 1) {
        
        /* DO SOMETHING HERE */
       /* sended = 1;*/
        
      } else {
        Repeat = 1;
      }
    }
  }
  Time_old = Time;
  digitalWrite(1,LOW);
}
