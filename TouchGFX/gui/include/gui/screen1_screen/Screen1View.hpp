#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>


class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setCountMonitorItem();

    virtual void checkYesButtonOk();

//container callback
    void setOpenSettingView(int index, int gID, int sID);
//Presenter callback
    void setChangePosi(int gID, int sID, int value);
private:
    Monitor_Item *monitor_item[10];
    int monitorCnt;

    int tempIndex;
    int tempGid;
    int tempSid;

protected:
};

#endif // SCREEN1VIEW_HPP
