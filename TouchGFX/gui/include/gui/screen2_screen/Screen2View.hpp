#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    

    virtual void keyBoardSelected(uint8_t value);
    virtual void filter_value(int value);
    virtual void reverseButton();
    virtual void resetYesButtonPressed();

    void setID_SettingPage(int index, int gID, int sID);

    void setSettingValue(int index, int gID, int sID, int lim_min, int lim_max, int map_0, int map_4095, int filter, bool reverse);

    void setChangePosi(int gID, int sID, int value);

    void setSlideID_SettingPage(int index, int slideID);

protected:

    int nowPosi;
    int myIndex;
    int groupID;
    int subID;
    int slideId;

    void setPosi(int value);
    void setPosiText(int value);
    void setPosiProgress(int value);
};

#endif // SCREEN2VIEW_HPP
