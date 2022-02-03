#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

typedef struct {
    int myIndex;
    int gID;
    int sID;
    int limit_min;
    int limit_max;
    int map_0;
    int map_4095;
    int filter;
}SettingData_TypeDef;

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
    void setOpenSettingView(int gID, int sID);

    int getGroupID(int index);
    int getSubID(int index);

//Presenter2 Call funtion
    void setScreenUp();

    void setChangeLimitMin(int gID, int sID, int value);
    void setChangeLimitMax(int gID, int sID, int value);
    void setChangeMap_0(int gID, int sID, int value);
    void setChangeMap_4095(int gID, int sID, int value);
    void setChangeFIlter(int gID, int sID, int value);

private:
    int myTimer;
    int testCnt;

    int settingGid;
    int settingSid;

    SettingData_TypeDef setting[10];

    int getIndex(int gID, int sID);


protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
