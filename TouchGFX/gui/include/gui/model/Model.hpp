#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;


#ifndef SIMULATOR
#include "motionManager.h"
#include "cmsis_os.h"
#else
typedef struct {
    int myIndex;
    int gID;
    int sID;
    int limit_min;
    int limit_max;
    int map_0;
    int map_4095;
    int filter;
    int reverse;
}SettingData_TypeDef;
#endif

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

//Presenter1 Call funtion
    void setOpenSettingView(int index, int gID, int sID);

    int getGroupID(int index);
    int getSubID(int index);

//Presenter2 Call funtion
    void setScreenUp();

    void setChangeGid(int index, int gID);
    void setChangeSid(int index, int sID);
    void setChangeLimitMin(int index, int value);
    void setChangeLimitMax(int index, int value);
    void setChangeMap_0(int index, int value);
    void setChangeMap_4095(int index, int value);
    void setChangeFIlter(int index, int value);
    void setChangeReverse(int index, bool value);

private:
    int myTimer;
    int testCnt;

    int settingIndex;
    int settingGid;
    int settingSid;

    SettingData_TypeDef setting[10];
#ifndef SIMULATOR


    CtrData_TypeDef ctrMsg;
    osStatus_t status;


    int firstMemSend;
#endif

    int getIndex(int gID, int sID);

    void setID(int index, int gID, int sID);


protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
