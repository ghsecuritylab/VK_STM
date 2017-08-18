/*
 * lcdUpdate.c
 *
 *  Created on: 18.08.2017
 *      Author: PR6
 */
#include "lcdUpdate.h"


void updateLCDStatus(State serverState, State clientState,char *serverIP,char *serverPort,char *clientIP,  char* clientPort)
{
	   TM_LCD_Fill(0x4321);
	   TM_LCD_SetXY(0,0);
	   TM_LCD_Puts(serverStatus);
	   switch(serverState)
	   {
	   case disconnected:
		   TM_LCD_Puts(disconnectedStatus);
		   break;
	   case connected:
		   TM_LCD_Puts(connectedStatus);
		   break;
	   default:
		   break;
	   }
	   TM_LCD_Putc('\n');
	   TM_LCD_Puts("IP:  ");
	   TM_LCD_Puts(serverIP);
	   TM_LCD_Putc('\n');;
	   TM_LCD_Puts("Port: ");
	   TM_LCD_Puts(serverPort);
	   TM_LCD_Putc('\n');
	   TM_LCD_Puts(clientStatus);
	   switch(clientState)
	   {
	   case disconnected:
		   TM_LCD_Puts(disconnectedStatus);
		   break;
	   case connected:
		   TM_LCD_Puts(connectedStatus);
		   break;
	   default:
		   break;
	   }
	   TM_LCD_Putc('\n');
	   TM_LCD_Puts("IP: ");
	   TM_LCD_Puts(clientIP);
	   TM_LCD_Putc('\n');;
	   TM_LCD_Puts("Port: ");
	   TM_LCD_Puts(clientPort);
	   TM_LCD_Putc('\n');
}

