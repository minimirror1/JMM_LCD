#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <eeprom.h>
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
Model::Model() : modelListener(0)
{
#ifndef SIMULATOR
	EE_emul_Init((uint16_t *)&EepData[0].myIndex,sizeof(SettingData_TypeDef)*10);
	EE_ReadAllData((uint16_t *)&EepData[0].myIndex,sizeof(SettingData_TypeDef)*10);
	memcpy((uint8_t *)&setting[0].myIndex,(uint8_t *)&EepData[0].myIndex,sizeof(SettingData_TypeDef)*10);
#endif
	setID(0, 5, 1);
	setID(1, 5, 2);
	setID(2, 5, 3);
	setID(3, 5, 4);
	setID(4, 5, 5);
	setID(5, 5, 6);
	setID(6, 5, 7);
	setID(7, 5, 8);
	setID(8, 5, 9);
	setID(9, 5, 10);

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

		modelListener->setChangePosi(5, 5, testCnt);
	}
}


void Model::setOpenSettingView(int index, int gID, int sID)
{
	settingIndex = index;
	settingGid = gID;
	settingSid = sID;
	
	modelListener->setID_SettingPage(index, gID, sID);
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
}

void Model::setChangeGid(int index, int gID)
{
	setting[index].gID = gID;
}

void Model::setChangeSid(int index, int sID)
{
	setting[index].sID = sID;
}

void Model::setChangeLimitMin(int index, int value)
{
	if (index < 10)
	{
		setting[index].limit_min = value;
#ifndef SIMULATOR
		EepData[index].limit_min = value;
		EE_WriteStrData((uint16_t *)&EepData[index].limit_min,sizeof(EepData[0].limit_min));
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
	setting[index].gID = gID;
	setting[index].sID = sID;
#ifndef SIMULATOR
	EepData[index].gID = gID;
	EepData[index].sID = sID;
	EE_WriteStrData((uint16_t*) &EepData[index].gID, sizeof(EepData[0].gID));
	EE_WriteStrData((uint16_t*) &EepData[index].sID, sizeof(EepData[0].sID));
#endif
}
