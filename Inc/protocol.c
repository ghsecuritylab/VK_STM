/*
 * protocol.c
 *
 *  Created on: 08.08.2017
 *      Author: PR6
 */
#include "protocol.h"
State state;
int receieveFullPacket(int socket, void* buffer,size_t size, struct sockaddr *addr, socklen_t *length_ptr)
{
	 int packetSize;
	 int recSize;
	 uint8_t sizeBuffer;
	packetSize = recvfrom(socket,(void*)&sizeBuffer, 1, MSG_WAITALL, addr, length_ptr);
	if (packetSize <=0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		return -1;
	}
	recSize = recvfrom(socket,(void*)buffer, sizeBuffer,MSG_WAITALL, addr, length_ptr);
	if(recSize<packetSize)
	{
		return -1;
	}
	return recSize;
}
int sendResponse(int socket,uint8_t response)
{
	uint8_t  send_buffer[2];
	int sent_data;
	send_buffer[0]=0x01;
	send_buffer[1]=response;
	sent_data = send(socket, &send_buffer,2,0);
	 return sent_data;
}
uint8_t checkLogin(char *data,size_t size)
{
	if(memcmp((void*)USER_ID,(void*)(data),size)==0)
		return LOGIN_OK;
	else
		return LOGIN_FAILED;
}
void handleKeyboardRequest(uint8_t * data,size_t size)
{
	KeyReport report;
	memcpy(&report,&data[1],size-1);
	keyboardSendReport(&report);
}
void handleMouseRequest(uint8_t *data, size_t size)
{
	MouseHID_t report;
	memcpy(&report,&data[1],size-1);
	mouseSendReport(&report);
}

void handlePacket(int socket,uint8_t * data,size_t size)
{
	switch(state)
	{
	case waitingForHanshake:{
		handleWaitingState(socket,(uint8_t*)data,size);
		break;
	}
	case connected:{
		handleConnectedState(socket,data,size);
		break;
	}
	case logged:{
		handleLoggedState(socket,data,size);
		break;
	}
	default:
		break;
	}
}

void handleWaitingState(int socket,uint8_t *data,size_t size)
{
	uint8_t packetID = data[0];
	switch(packetID)
	{
	case PROTOCOL_VER:
	{
		if(sendResponse(socket,PROTOCOL_VER)<0) {
			state=disconnected;
		}
		else{
		state=connected;
		}
		break;
	}
	default:
	{
		sendResponse(socket,UNSUPORTED_PROTOCOL);
		state=disconnected;
	}
	}
}
void handleConnectedState(int socket,uint8_t *data,size_t size)
{
	uint8_t packetID = data[0];
	switch(packetID)
	{
	case DISCONNECT_REQ:
	{
		state=disconnected;
		break;
	}
	case LOGIN_REQ:
	{
		uint8_t logresult=checkLogin((char*)data,size);
		if(logresult==LOGIN_OK)
		{
			state=logged;
		}
		if(sendResponse(socket,logresult)<0){
			state=disconnected;
		}
		break;
	}
	default:
		if(sendResponse(socket,LOGIN_FAILED)<0){
			state=disconnected;
		}
	}
}
void handleLoggedState(int socket,uint8_t *data,size_t size)
{
	uint8_t packetID = data[0];
	switch(packetID)
	{
	case DISCONNECT_REQ:
	{
		state=disconnected;
		break;
	}
	case KEYBOARD_WRITE_REQ:
	{
		handleKeyboardRequest(data,size);
		if(sendResponse(socket,REQUEST_OK)<0){
			state=disconnected;
		}
		break;
	}
	case MOUSE_WRITE_REQ:
	{
		handleMouseRequest(data,size);
		if(sendResponse(socket,REQUEST_OK)<0){
			state=disconnected;
		}
		break;
	}
	default:
	{
		if(sendResponse(socket,REQUEST_FAILED)<0){
			state=disconnected;
		}
	}
    }
}
