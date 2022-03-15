/*
 * motionManager.h
 *
 *  Created on: Feb 7, 2022
 *      Author: shin
 */

#ifndef APPLICATION_USER_MOTION_TASK_INC_MOTIONMANAGER_H_
#define APPLICATION_USER_MOTION_TASK_INC_MOTIONMANAGER_H_


#ifndef SIMULATOR
#pragma pack(1)
#endif

typedef struct {
    int myIndex;
    int slideID;
    int gID;
    int sID;
    int limit_min;
    int limit_max;
    int map_0;
    int map_4095;
    int filter;
    int reverse;
}SettingData_TypeDef;
typedef struct {
	SettingData_TypeDef setting[10];
}SettingDataArr_TypeDef;


typedef struct {
    int gid;
    int sid;
    int	posi;
}CtrData_TypeDef;

typedef struct {
	CtrData_TypeDef arr[10];
}CtrDataArr_TypeDef;

#ifndef SIMULATOR
#pragma pack()
#endif



#endif /* APPLICATION_USER_MOTION_TASK_INC_MOTIONMANAGER_H_ */
