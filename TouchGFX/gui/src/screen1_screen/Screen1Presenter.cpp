#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::setOpenSettingView(int gID, int sID)
{
    model->setOpenSettingView(gID, sID);
}

int Screen1Presenter::getGroupID(int index)
{
    return model->getGroupID(index);
}

int Screen1Presenter::getSubID(int index)
{
    return model->getSubID(index);
}

//ModelListener override
void Screen1Presenter::setChangePosi(int gID, int sID, int value)
{
    view.setChangePosi(gID, sID, value);
}
