#ifndef __MOUSE__H__
#define __MOUSE__H__
#define LPM 1
#define PPM 2
#define SPM 4
#include <stdint.h>
#include <stddef.h>
#include "usb_device.h"
#include "usbd_hid.h"
typedef struct MouseHID{
	  uint8_t id;
	  uint8_t buttons;
	  int8_t X;
	  int8_t Y;
	  int8_t Wheel;
  }MouseHID_t;
void initMouse();
void mouseReleaseAll();
size_t mouePress(uint8_t key);
void  mouseClick(uint8_t key);
size_t mouseRelease(uint8_t key);
void mouseMove(int8_t X,int8_t Y,uint8_t angle);
void mouseSendReport(MouseHID_t *report);
#endif
