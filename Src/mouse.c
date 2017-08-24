/*
 * mouse.c
 *
 *  Created on: 07.08.2017
 *      Author: PR6
 */
#include "mouse.h"

MouseHID_t mouse;
void initMouse()
{
	mouse.id=2;
}
void mouseReleaseAll()
{
	mouse.buttons=0;
}
size_t mousePress(uint8_t key)
{

	mouse.buttons |=key;
	mouseMove(0,0,0);
	return 0;
}
void mouseClick(uint8_t key)
{
	mouse.buttons=key;
	mouseMove(0,0,0);
	HAL_Delay(30);//meadmeadmd
	mouse.buttons=0;
	mouseMove(0,0,0);
	HAL_Delay(30);//there has to be delay between changes
}
size_t mouseRelease(uint8_t key)
{
	mouse.buttons &=~key;
	mouseMove(0,0,0);
	return key;
}
void mouseMove(int8_t X,int8_t Y,uint8_t angle)
{
	mouse.id=2;
	mouse.X=X;
	mouse.Y=Y;
	mouse.Wheel=angle;
	mouseSendReport(&mouse);
}
void mouseSendReport(MouseHID_t *report)
{
	USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t *)report, sizeof(MouseHID_t));
	HAL_Delay(100);
}

