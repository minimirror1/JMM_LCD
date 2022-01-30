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


    virtual void setChangePosi(int gID, int sID, int value) {}

    virtual void setID_SettingPage(int gID, int sID) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
