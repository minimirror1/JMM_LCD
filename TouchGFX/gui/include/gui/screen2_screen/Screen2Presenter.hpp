#ifndef SCREEN2PRESENTER_HPP
#define SCREEN2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen2View;

class Screen2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen2Presenter(Screen2View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen2Presenter() {};

    void setScreenUp();
//View Call Function
    void setChangeGid(int index, int gID);
    void setChangeSid(int index, int sID);
    void setChangeLimitMin(int index, int value);
    void setChangeLimitMax(int index, int value);
    void setChangeMap_0(int index, int value);
    void setChangeMap_4095(int index, int value);
    void setChangeFIlter(int index, int value);
    void setChangeReverse(int index, bool value);

//ModelListener override
    void setID_SettingPage(int index, int gID, int sID);

    void setChangePosi(int gID, int sID, int value);

    void setSettingValue(int index, int gID, int sID, int lim_min, int lim_max, int map_0, int map_4095, int filter, bool reverse);

private:
    Screen2Presenter();

    Screen2View& view;
};

#endif // SCREEN2PRESENTER_HPP
