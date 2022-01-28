#ifndef MONITOR_ITEM_HPP
#define MONITOR_ITEM_HPP

#include <gui_generated/containers/Monitor_ItemBase.hpp>

class Screen1View;

class Monitor_Item : public Monitor_ItemBase
{
public:
    Monitor_Item();
    virtual ~Monitor_Item() {}

    virtual void initialize();

    void setPtr(Screen1View* ptr);
    //void setName();

    void setSlotID(int value);
    
    void setId(int gID, int sID);

    void setPosi_ID(int gID, int sID, int value);

private:
    int slotID;
    int nowPosi;
    int groupID;
    int subID;
    
    void setPosi(int value);
    void setPosiText(int value);
    void setPosiProgress(int value);

    void setIDText();

protected:
    Screen1View* viewPtr;
};

#endif // MONITOR_ITEM_HPP
