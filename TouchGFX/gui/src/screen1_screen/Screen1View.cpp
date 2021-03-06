#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
    monitorCnt = 0;

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    monitor_item[0] = &monitor_Item1;
    monitor_item[1] = &monitor_Item2;
    monitor_item[2] = &monitor_Item3;
    monitor_item[3] = &monitor_Item4;
    monitor_item[4] = &monitor_Item5;
    monitor_item[5] = &monitor_Item6;
    monitor_item[6] = &monitor_Item7;
    monitor_item[7] = &monitor_Item8;
    monitor_item[8] = &monitor_Item9;
    monitor_item[9] = &monitor_Item10;

    tempIndex = 0;
    tempGid = 0;
    tempSid = 0;

    for (int i = 0; i < 10; i++)
    {
        monitor_item[i]->setPtr(this);
        monitor_item[i]->setSlotID(i);
        monitor_item[i]->setSlideID(presenter->getSlideID(i));
        //monitor_item[i]->setId(i, i);
        monitor_item[i]->setId(presenter->getGroupID(i), presenter->getSubID(i));
    }

}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::setCountMonitorItem()
{
    monitorCnt++;
}

void Screen1View::checkYesButtonOk()
{
    //presenter->setOpenSettingView(tempIndex, tempGid, tempSid);

}

void Screen1View::setOpenSettingView(int index, int gID, int sID)
{
    presenter->setCheckPosi();
    checkModalWindow.show();    
    presenter->setOpenSettingView(index, gID, sID);
}

void Screen1View::setChangePosi(int gID, int sID, int value)
{
    for (int i = 0; i < 10; i++)
    {
        monitor_item[i]->setPosi_ID(gID, sID, value);
    }
}

