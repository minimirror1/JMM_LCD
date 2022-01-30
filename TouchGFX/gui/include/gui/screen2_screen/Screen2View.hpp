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

    virtual void KeyboardSeleted(uint8_t value);
    virtual void handleTickEvent();

    void setID_SettingPage(int gID, int sID);

    void setChangePosi(int gID, int sID, int value);

protected:

    int nowPosi;
    int groupID;
    int subID;

    void setPosi(int value);
    void setPosiText(int value);
    void setPosiProgress(int value);
};

#endif // SCREEN2VIEW_HPP
