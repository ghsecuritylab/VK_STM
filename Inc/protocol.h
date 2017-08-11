/*
 * protocol.h
 *
 *  Created on: 08.08.2017
 *      Author: PR6
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_
#include <stddef.h>
#include <stdint.h>
#include "keyboard.h"
#include "mouse.h"
#include "lwip/sockets.h"
#include "lwip.h"



#define PROTOCOL_VER 0x01
#define LOGIN_REQ 0x10
#define KEYBOARD_WRITE_REQ 0x30
#define MOUSE_WRITE_REQ 0x40
#define DISCONNECT_REQ 0xF0
#define UNSUPORTED_PROTOCOL 0xF1
#define LOGIN_FAILED 0xF2
#define LOGIN_OK 0xF3
#define REQUEST_FAILED 0xF4
#define REQUEST_OK 0xF5
#define USER_ID "root,root"
  typedef enum StateEnum{
	 waitingForHanshake,connected,logged,disconnected
  }State;
int  receieveFullPacket(int socket, void* buffer,size_t size, struct sockaddr *addr, socklen_t *length_ptr);
void handlePacket(int socket,uint8_t * data,size_t size);
int sendResponse(int socket,uint8_t response);
uint8_t checkLogin(char *data,size_t size);
void handleKeyboardRequest(uint8_t * data,size_t size);
void handleMouseRequest(uint8_t *data, size_t size);
void handleConnectedState(int socket,uint8_t *data,size_t size);
void handleLoggedState(int socket,uint8_t *data,size_t size);
void handleWaitingState(int socket,uint8_t *data,size_t size);

#endif /* PROTOCOL_H_ */
