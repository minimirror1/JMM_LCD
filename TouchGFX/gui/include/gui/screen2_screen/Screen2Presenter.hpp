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
    void setChangeLimitMin(int gID, int sID, int value);
    void setChangeLimitMax(int gID, int sID, int value);
    void setChangeMap_0(int gID, int sID, int value);
    void setChangeMap_4095(int gID, int sID, int value);
    void setChangeFIlter(int gID, int sID, int value);
    void setChangeReverse(int gID, int sID, bool value);

//ModelListener override
    void setID_SettingPage(int gID, int sID);

    void setChangePosi(int gID, int sID, int value);

    void setSettingValue(int lim_min, int lim_max, int map_0, int map_4095, int filter, bool reverse);

private:
    Screen2Presenter();

    Screen2View& view;
};

#endif // SCREEN2PRESENTER_HPP
