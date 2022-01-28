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

    for (int i = 0; i < 10; i++)
    {
        monitor_item[i]->setSlotID(i);
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

