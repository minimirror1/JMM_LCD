/*
 * motionTask.c
 *
 *  Created on: Feb 7, 2022
 *      Author: shin
 */
#include "main.h"
#include "cmsis_os.h"

#include "motionManager.h"
#include "motionTask.h"

#include "uart.h"
#include "uart_datalink.h"
#include "uart_datalink_parsing.h"

#include "can_com.h"
#include "can_datalink.h"


#include "can_app_jms.h"

#include "uart_app_can2_bypass.h"

extern osMessageQueueId_t settingDataQueueHandle;
extern osMessageQueueId_t ctrDataQueueHandle;

SettingData_TypeDef msg[10];
UART_JMM_LCD_SettingTypeDef txMsg;

typedef struct {
	uint8_t test;
} MSGQUEUE_OBJ_t;

void MAL_UART_7_Init(void) {
	MAL_UART_HandleMatching(&muart7, &huart7);
	MAL_UART_Parsing_HandleReg(&muart7);
	MAL_UART_RxAppointment(&muart7);

}
void sendSettingData(void) {
	for (int i = 0; i < 10; i++) {

		txMsg.setting[i].gid = msg[i].gID;
		txMsg.setting[i].sid = msg[i].sID;
		txMsg.setting[i].reverse = msg[i].reverse;
		txMsg.setting[i].limitMin = msg[i].limit_min;
		txMsg.setting[i].limitMax = msg[i].limit_max;
		txMsg.setting[i].map0 = msg[i].map_0;
		txMsg.setting[i].map4095 = msg[i].map_4095;
		txMsg.setting[i].filter = msg[i].filter;
	}
	UART_App_JMM_LCD_Setting_Polling_TxReq(&txMsg);
}

uint8_t id = 0;
uint16_t posi = 0;

CtrData_TypeDef rxData;

void UART_App_JMM_LCD_MotionOut_Data_RxReq(uint8_t gid, uint8_t sid, uint16_t posi)
{
	rxData.gid = gid;
	rxData.sid = sid;
	rxData.posi = posi;

	osMessageQueuePut(ctrDataQueueHandle, &rxData, 0U, 0U);
}
/*void UART_CAN_JMS_POSI_DATA_RxReq(CAN_chHeader_TypeDef *pPacket)
{
	CAN_JMM_JMS_POSI_DATA_Typedef *pData = (CAN_JMM_JMS_POSI_DATA_Typedef *)pPacket->header.payload;

	id = pPacket->header.srcId;

	posi = pData->posi;

	rxData.gid = (id&0xF0)>>4;
	rxData.sid = id&0x0F;
	rxData.posi = posi;

	osMessageQueuePut(ctrDataQueueHandle, &rxData, 0U, 0U);
}*/

void UART_CAN_Parsing(CAN_chHeader_TypeDef *pPacket)
 {

	switch (pPacket->canCh) {
	case CAN_MOTOR:
		break;
	case CAN_MOTION:

		if (pPacket->header.cmdType == CMD_TYPE_REQ) {
			switch (pPacket->header.cmd) {
			case JMS_POSI_DATA_REQ:
				//UART_CAN_JMS_POSI_DATA_RxReq(pPacket);
				break;
			}
		}
		break;
	}
}

void StartMotionTask(void *argument) {
	/* USER CODE BEGIN StartMotionTask */
	uint32_t t_uartRxReset = 0;
	uint32_t t_pollingTick = 0;
	uint8_t f_first = RESET;
	osStatus_t status;

	MAL_UART_7_Init();
	/* Infinite loop */
	for (;;) {
		UART_COM_Process();

		status = osMessageQueueGet(settingDataQueueHandle, &msg[0], NULL, 0U); // wait for message
		if (status == osOK) {
			f_first = SET;
			sendSettingData();
		}

		//if (f_first) {
			if (t_pollingTick++ > 1000) {
				t_pollingTick = 0;
				sendSettingData();
			}
		//}
			if(t_uartRxReset >5000)
			{
				MAL_UART_RxAppointment(&muart7);
			}

		osDelay(1);

	}
	/* USER CODE END StartMotionTask */
}
