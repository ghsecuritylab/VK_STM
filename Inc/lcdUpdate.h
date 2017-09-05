/*
 * lcdUpdate.h
 *
 *  Created on: 18.08.2017
 *      Author: PR6
 */

#ifndef LCDUPDATE_H_
#define LCDUPDATE_H_
#include "tm_stm32_lcd.h"
#include "protocol.h"
#include "stm32f7xx_hal_tim.h"
#include "settings.h"
#include <stdbool.h>

#define SCREEN_TIMEOUT 20
#define RESET_TIMEOUT 5

extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim14;


static char serverStatus[] = "Server status: ";
static  char clientStatus[] = "Client status: ";
static char connectedStatus[] ="Connected";
static  char waitingForClientStatus[] = "Waiting for a client";
static char waitingForIPReleaseStatus[] = "Retrieving data from DHCP server";
static  char disconnectedStatus[] = "Disconnected";


void updateLCDStatus(State serverState, State clientState,  char *serverIP, char *serverPort,  char *clientIP, char* clientPort);
void turnOnDisplay();
void turnOffDisplay();
bool isDisplayOn();
void printLCD(char * str);
void EnableTimers();
void DisableTimers();

#endif /* LCDUPDATE_H_ */
