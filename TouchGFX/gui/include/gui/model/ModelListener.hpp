#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

//Screen2
    virtual void setChangePosi(int gID, int sID, int value) {}

    virtual void setID_SettingPage(int index, int gID, int sID) {}

    virtual void setSettingValue(int index, int gID, int sID, int lim_min, int lim_max, int map_0, int map_4095, int filter, bool reverse) {}

    virtual void setSlideID_SettingPage(int index, int slideID) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
