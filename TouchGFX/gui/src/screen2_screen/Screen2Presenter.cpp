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

void Screen2Presenter::setID_SettingPage(int gID, int sID)
{
    view.setID_SettingPage(gID, sID);
}

//ModelListener override
void Screen2Presenter::setChangePosi(int gID, int sID, int value)
{
    view.setChangePosi(gID, sID, value);
}

