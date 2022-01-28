#include <gui/containers/Monitor_Item.hpp>

Monitor_Item::Monitor_Item()
{

}

void Monitor_Item::initialize()
{
    Monitor_ItemBase::initialize();

    setPosi(2048);   

    setId(5,5);
}

void Monitor_Item::setPtr(Screen1View* ptr)
{
    viewPtr = ptr;
}

void Monitor_Item::setSlotID(int value)
{
    slotID = value;

    Unicode::snprintf(slotBuffer, SLOT_SIZE, "%d", slotID);
    slot.setWildcard(slotBuffer);
    slot.invalidate();
}

void Monitor_Item::setPosi(int value)
{
    nowPosi = value;
    setPosiText(nowPosi);
    setPosiProgress(nowPosi);
}

void Monitor_Item::setId(int gID, int sID)
{
    groupID = gID;
    subID = sID;
    setIDText();
}

void Monitor_Item::setPosiText(int value)
{
    Unicode::snprintf(posiBuffer, POSI_SIZE, "%d", value);
    posi.setWildcard(posiBuffer);
    posi.invalidate();
}

void Monitor_Item::setPosiProgress(int value)
{
    posiProgress.setValue(value);
}

void Monitor_Item::setIDText()
{
    Unicode::snprintf(idBuffer1, IDBUFFER1_SIZE, "%d", groupID);
    id.setWildcard1(idBuffer1);    
    id.invalidate();

    Unicode::snprintf(idBuffer2, IDBUFFER2_SIZE, "%d", subID);
    id.setWildcard2(idBuffer2);
    id.invalidate();
}
