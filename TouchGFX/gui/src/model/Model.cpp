#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <eeprom.h>
#include "cmsis_os.h"
#include "string.h"
/* Virtual address defined by the user: 0xFFFF value is prohibited */
uint16_t VirtAddVarTab[NB_OF_VAR];
uint16_t VarDataTab[NB_OF_VAR] = { 'M', 'a', 't', 'e', 'u', 's', 'z', ' ', 'S', 'a', 'l', 'a', 'm', 'o', 'n', ' ', 'm', 's', 'a', 'l', 'a', 'm', 'o', 'n', '.', 'p', 'l' };
uint8_t VarDataTabRead[NB_OF_VAR];
uint16_t VarIndex, VarDataTmp = 0;

//최소 uint 16 사용
#if 0
#pragma pack(1)
typedef struct __EEPemul_Data_TypeDef
{
	uint16_t flag;
	uint32_t encoderSt1_cnt;

}EEPemul_Data_TypeDef;
#pragma pack()

EEPemul_Data_TypeDef EepData;
#endif
SettingData_TypeDef EepData[10];
#endif

#ifndef SIMULATOR
extern osMessageQueueId_t settingDataQueueHandle;
extern osMessageQueueId_t ctrDataQueueHandle;
extern osMessageQueueId_t setSettingViewHandle;
#endif
Model::Model() : modelListener(0)
{
#ifndef SIMULATOR
	EE_emul_Init((uint16_t *)&EepData[0].myIndex,sizeof(SettingData_TypeDef)*10);
	EE_ReadAllData((uint16_t *)&EepData[0].myIndex,sizeof(SettingData_TypeDef)*10);
	memcpy((uint8_t *)&setting[0].myIndex,(uint8_t *)&EepData[0].myIndex,sizeof(SettingData_TypeDef)*10);
	firstMemSend = 120;
#endif
//	setID(0, 5, 1);
//	setID(1, 5, 2);
//	setID(2, 5, 3);
//	setID(3, 5, 4);
//	setID(4, 5, 5);
//	setID(5, 5, 6);
//	setID(6, 5, 7);
//	setID(7, 5, 8);
//	setID(8, 5, 9);
//	setID(9, 5, 10);

}

void Model::tick()
{
	myTimer++;
	if (myTimer > 0)
	{
		myTimer = 0;
		testCnt += 10;

		if (testCnt > 4095)
			testCnt = 0;

		//modelListener->setChangePosi(5, 5, testCnt);
	}
#ifndef SIMULATOR
	//status = osMessageQueueGet(ctrDataQueueHandle, &ctrMsg, NULL, 0U); // wait for message
	status = osMessageQueueGet(ctrDataQueueHandle, &ctrData, NULL, 0U); // wait for message
	if (status == osOK) {
		for(int i = 0; i < 10 ; i++)
		{
			if((ctrData.arr[i].gid != 0)&&(ctrData.arr[i].sid != 0))
			{
				modelListener->setChangePosi(ctrData.arr[i].gid, ctrData.arr[i].sid, ctrData.arr[i].posi);
			}
		}

		//if((ctrMsg.gid != 0)&&(ctrMsg.sid != 0))
			//modelListener->setChangePosi(ctrMsg.gid, ctrMsg.sid, ctrMsg.posi);
	}

	if(firstMemSend != 0)
	{
		firstMemSend--;
		if(firstMemSend == 0)
			osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
	}
#endif


}

#ifndef SIMULATOR
uint16_t setiingViewTrigger = 1;
#endif
void Model::setCheckPosi(void)
{
#ifndef SIMULATOR
	osMessageQueuePut(setSettingViewHandle, &setiingViewTrigger, 0U, 0U);
#endif
}

void Model::setOpenSettingView(int index, int gID, int sID)
{
	settingIndex = index;
	settingGid = gID;
	settingSid = sID;
	
	modelListener->setID_SettingPage(index, gID, sID);
}
int Model::getSlideID(int index)
{
	if (index < 10)
		return setting[index].slideID;
	else
		return 0;
}
int Model::getGroupID(int index)
{
	if (index < 10)
		return setting[index].gID;
	else
		return 0;
}

int Model::getSubID(int index)
{
	if (index < 10)
		return setting[index].sID;
	else
		return 0;
}

void Model::setScreenUp()
{
	modelListener->setID_SettingPage(settingIndex, setting[settingIndex].gID, setting[settingIndex].sID);
	modelListener->setSettingValue(
		settingIndex,
		setting[settingIndex].gID,
		setting[settingIndex].sID,
		setting[settingIndex].limit_min,
		setting[settingIndex].limit_max,
		setting[settingIndex].map_0,
		setting[settingIndex].map_4095,
		setting[settingIndex].filter,
		setting[settingIndex].reverse);
	modelListener->setSlideID_SettingPage(settingIndex, setting[settingIndex].slideID);
}

void Model::setChangeSlideid(int index, int slideID)
{
	setting[index].slideID = slideID;

	for (int i = 0; i < 10; i++) {
		
		if( (setting[index].slideID == setting[i].slideID) && (index != i) )
		{
			setting[i].slideID = 0;

#ifndef SIMULATOR
			EepData[i].slideID = 0; 
			EE_WriteStrData((uint16_t*)&EepData[i].slideID, sizeof(EepData[0].slideID));
#endif
		}
	}
#ifndef SIMULATOR
	EepData[index].slideID = slideID;
	EE_WriteStrData((uint16_t*)&EepData[index].slideID, sizeof(EepData[0].slideID));
	osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
}

void Model::setChangeGid(int index, int gID)
{
	setting[index].gID = gID;
#ifndef SIMULATOR
	EepData[index].gID = gID;
	EE_WriteStrData((uint16_t*)&EepData[index].gID, sizeof(EepData[0].gID));
	osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
}

void Model::setChangeSid(int index, int sID)
{
	setting[index].sID = sID;
#ifndef SIMULATOR
	EepData[index].sID = sID;
	EE_WriteStrData((uint16_t*)&EepData[index].sID, sizeof(EepData[0].sID));
	osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
}

void Model::setChangeLimitMin(int index, int value)
{
	if (index < 10)
	{
		setting[index].limit_min = value;
#ifndef SIMULATOR
		EepData[index].limit_min = value;
		EE_WriteStrData((uint16_t *)&EepData[index].limit_min,sizeof(EepData[0].limit_min));
		 osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
	}
}

void Model::setChangeLimitMax(int index, int value)
{
	if (index < 10)
	{
		setting[index].limit_max = value;
#ifndef SIMULATOR
		EepData[index].limit_max = value;
		EE_WriteStrData((uint16_t *)&EepData[index].limit_max,sizeof(EepData[0].limit_max));
		 osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
	}
}

void Model::setChangeMap_0(int index, int value)
{
	if (index < 10)
	{
		setting[index].map_0 = value;
#ifndef SIMULATOR
		EepData[index].map_0 = value;
		EE_WriteStrData((uint16_t *)&EepData[index].map_0,sizeof(EepData[0].map_0));
		 osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
	}
}

void Model::setChangeMap_4095(int index, int value)
{
	if (index < 10)
	{
		setting[index].map_4095 = value;
#ifndef SIMULATOR
		EepData[index].map_4095 = value;
		EE_WriteStrData((uint16_t *)&EepData[index].map_4095,sizeof(EepData[0].map_4095));
		 osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
	}
}

void Model::setChangeFIlter(int index, int value)
{
	if (index < 10)
	{
		setting[index].filter = value;
#ifndef SIMULATOR
		EepData[index].filter = value;
		EE_WriteStrData((uint16_t *)&EepData[index].filter,sizeof(EepData[0].filter));
		 osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
	}
}

void Model::setChangeReverse(int index, bool value)
{
	if (index < 10)
	{
		setting[index].reverse = value;
#ifndef SIMULATOR
		EepData[index].reverse = value;
		EE_WriteStrData((uint16_t *)&EepData[index].reverse,sizeof(EepData[0].reverse));
		 osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
	}
}

int Model::getIndex(int gID, int sID)
{
	for (int i = 0; i < 10; i++)
	{
		if ((setting[i].gID == gID) && (setting[i].sID == sID))
		{
			return i;
		}
	}
	return 10;
}
void Model::setID(int index, int gID, int sID)
{
	setting[index].myIndex = index;
	setting[index].gID = gID;
	setting[index].sID = sID;
#ifndef SIMULATOR
	EepData[index].myIndex = index;
	EepData[index].gID = gID;
	EepData[index].sID = sID;
	EE_WriteStrData((uint16_t*) &EepData[index].gID, sizeof(EepData[0].gID));
	EE_WriteStrData((uint16_t*) &EepData[index].sID, sizeof(EepData[0].sID));
	osMessageQueuePut(settingDataQueueHandle, &setting[0], 0U, 0U);
#endif
}
