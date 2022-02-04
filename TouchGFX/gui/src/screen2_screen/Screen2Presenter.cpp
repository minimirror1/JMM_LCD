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
void Screen2Presenter::setChangeGid(int index, int gID)
{
}
void Screen2Presenter::setChangeSid(int index, int sID)
{
}
void Screen2Presenter::setChangeLimitMin(int index, int value)
{
    model->setChangeLimitMin(index, value);
}

void Screen2Presenter::setChangeLimitMax(int index, int value)
{
    model->setChangeLimitMax(index, value);
}

void Screen2Presenter::setChangeMap_0(int index, int value)
{
    model->setChangeMap_0(index, value);
}

void Screen2Presenter::setChangeMap_4095(int index, int value)
{
    model->setChangeMap_4095(index, value);
}

void Screen2Presenter::setChangeFIlter(int index, int value)
{
    model->setChangeFIlter(index, value);
}

void Screen2Presenter::setChangeReverse(int index, bool value)
{
    model->setChangeReverse(index, value);
}



//ModelListener override
void Screen2Presenter::setID_SettingPage(int index, int gID, int sID)
{
    view.setID_SettingPage(index, gID, sID);
}

void Screen2Presenter::setChangePosi(int gID, int sID, int value)
{
    view.setChangePosi(gID, sID, value);
}

void Screen2Presenter::setSettingValue(int index, int gID, int sID, int lim_min, int lim_max, int map_0, int map_4095, int filter, bool reverse)
{
    view.setSettingValue(index, gID, sID, lim_min, lim_max, map_0, map_4095, filter, reverse);
}

