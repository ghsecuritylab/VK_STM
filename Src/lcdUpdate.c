/*
 * lcdUpdate.c
 *
 *  Created on: 18.08.2017
 *      Author: PR6
 */
#include "lcdUpdate.h"

volatile  bool on =1;
volatile uint32_t screenTimer=0;
volatile uint32_t resetTimer = 0;
char buffer[4];

void TIM8_UP_TIM13_IRQHandler(){
    if (__HAL_TIM_GET_FLAG(&htim13, TIM_FLAG_UPDATE) != RESET)
    {
        if (__HAL_TIM_GET_ITSTATUS(&htim13, TIM_IT_UPDATE) != RESET)
        {
            __HAL_TIM_CLEAR_FLAG(&htim13, TIM_FLAG_UPDATE);
        	screenTimer++;
        	if(screenTimer==SCREEN_TIMEOUT)
        	{
        		turnOffDisplay();
        	}
        }
    }
}
void TIM8_TRG_COM_TIM14_IRQHandler(){
    if (__HAL_TIM_GET_FLAG(&htim14, TIM_FLAG_UPDATE) != RESET)
    {
        if (__HAL_TIM_GET_ITSTATUS(&htim14, TIM_IT_UPDATE) != RESET)
        {
            __HAL_TIM_CLEAR_FLAG(&htim14, TIM_FLAG_UPDATE);
        	resetTimer++;
        	if(resetTimer>=RESET_TIMEOUT){
        		TM_LCD_DisplayOn();
        		writeEEPROMSettings(1,0,21,0,0);
        		printLCD("Restored default settings. \nRestart pending...");
        		HAL_Delay(2000);
        		HAL_NVIC_SystemReset();
        		}
        }
        	}
}

/* USER CODE END PFP */
void EXTI15_10_IRQHandler(void){
	uint8_t pinStat =HAL_GPIO_ReadPin(GPIOI,GPIO_PIN_11);
	  if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_11) != RESET)
	  {
	    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_11);
		if(pinStat==GPIO_PIN_SET){
			HAL_TIM_Base_Start_IT(&htim14);
		}
		if(pinStat==GPIO_PIN_RESET)
		{
			if(isDisplayOn()){
				turnOffDisplay();
			}
			else{
				turnOnDisplay();
			}
        	HAL_TIM_Base_Stop_IT(&htim14);
        	resetTimer=0;
        }
	  }
}
void EnableTimers()
{
	HAL_NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
	HAL_NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn);
}
void DisableTimers(){
	HAL_NVIC_DisableIRQ(TIM8_UP_TIM13_IRQn);
	HAL_NVIC_DisableIRQ(TIM8_TRG_COM_TIM14_IRQn);
}
void turnOnDisplay()
{
	if(!isDisplayOn())
	{
		TM_LCD_DisplayOn();
		on=true;
		HAL_TIM_Base_Start_IT(&htim13);
	}
}
void turnOffDisplay()
{
	if(isDisplayOn()){
	screenTimer=0;
	TM_LCD_DisplayOff();
	HAL_TIM_Base_Stop_IT(&htim13);
	on=false;
	}
}
bool  isDisplayOn()
{
	return on;
}

void printLCD(char * str)
{
	TM_LCD_Fill(0x4321);
	TM_LCD_SetXY(0,0);
	TM_LCD_Puts(str);
}
void updateLCDStatus(State serverState, State clientState,char *serverIP,char *serverPort,char *clientIP,  char* clientPort)
{
	   TM_LCD_Fill(0x4321);
	   TM_LCD_SetXY(0,0);
	   if(readModeSettings())
		   TM_LCD_Puts("Mode: DHCP\n");
	   else
		   TM_LCD_Puts("Mode: STATIC\n");
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

