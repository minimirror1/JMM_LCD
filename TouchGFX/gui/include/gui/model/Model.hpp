#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

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

//Presenter2 Call funtion
    void setScreenUp();

private:
    int myTimer;
    int testCnt;

    int settingGid;
    int settingSid;

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
