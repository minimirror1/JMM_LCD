#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::setScreenUp()
{
    model->setScreenUp();
}
//View Call Function
void Screen2Presenter::setChangeLimitMin(int gID, int sID, int value)
{
}

void Screen2Presenter::setChangeLimitMax(int gID, int sID, int value)
{
}

void Screen2Presenter::setChangeMap_0(int gID, int sID, int value)
{
}

void Screen2Presenter::setChangeMap_4095(int gID, int sID, int value)
{
}

void Screen2Presenter::setChangeFIlter(int gID, int sID, int value)
{
}



//ModelListener override
void Screen2Presenter::setID_SettingPage(int gID, int sID)
{
    view.setID_SettingPage(gID, sID);
}

void Screen2Presenter::setChangePosi(int gID, int sID, int value)
{
    view.setChangePosi(gID, sID, value);
}

void Screen2Presenter::setSettingValue(int lim_min, int lim_max, int map_0, int map_4095, int filter)
{
    view.setSettingValue(lim_min, lim_max, map_0, map_4095, filter);
}

