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
static char serverStatus[] = "Server status: ";
static  char clientStatus[] = "Client status: ";
static char connectedStatus[] ="Connected";
static  char waitingForClientStatus[] = "Waiting for a client";
static char waitingForIPReleaseStatus[] = "Retrieving data from DHCP server";
static  char disconnectedStatus[] = "Disconnected";


void updateLCDStatus(State serverState, State clientState,  char *serverIP, char *serverPort,  char *clientIP, char* clientPort);

#endif /* LCDUPDATE_H_ */
