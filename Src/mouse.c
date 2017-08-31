/*
 * mouse.c
 *
 *  Created on: 07.08.2017
 *      Author: PR6
 */
#include "mouse.h"

MouseHID_t mouse;
inline void initMouse()
{
	mouse.id=2;
}
inline void mouseReleaseAll()
{
	mouse.buttons=0;
}
inline size_t mousePress(uint8_t key)
{

	mouse.buttons |=key;
	mouseMove(0,0,0);
	return 0;
}
inline void mouseClick(uint8_t key)
{
	mouse.buttons=key;
	mouseMove(0,0,0);
	mouse.buttons=0;
	mouseMove(0,0,0);
}
inline size_t mouseRelease(uint8_t key)
{
	mouse.buttons &=~key;
	mouseMove(0,0,0);
	return key;
}
inline void mouseMove(int8_t X,int8_t Y,uint8_t angle)
{
	mouse.id=2;
	mouse.X=X;
	mouse.Y=Y;
	mouse.Wheel=angle;
	mouseSendReport(&mouse);
}
inline void mouseSendReport(MouseHID_t *report)
{
	USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *)report, sizeof(MouseHID_t));
}

