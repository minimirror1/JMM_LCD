/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    monitor_Item1.setXY(15, 8);

    monitor_Item2.setXY(105, 8);

    monitor_Item3.setXY(195, 8);

    monitor_Item4.setXY(285, 8);

    monitor_Item5.setXY(375, 8);

    monitor_Item6.setXY(15, 144);

    monitor_Item7.setXY(105, 144);

    monitor_Item8.setXY(195, 144);

    monitor_Item9.setXY(285, 144);

    monitor_Item10.setXY(375, 144);

    checkModalWindow.setBackground(touchgfx::BitmapId(BITMAP_MODAL_CHECK_BACKGROUND_ID), 90, 36);
    checkModalWindow.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    checkModalWindow.setShadeAlpha(150);
    checkModalWindow.hide();

    checkYesButton.setXY(16, 125);
    checkYesButton.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    checkYesButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_7SKO));
    checkYesButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    checkYesButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    checkYesButton.setAction(buttonCallback);
    checkModalWindow.add(checkYesButton);

    checkNoButton.setXY(222, 125);
    checkNoButton.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    checkNoButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_T2SW));
    checkNoButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    checkNoButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    checkNoButton.setAction(buttonCallback);
    checkModalWindow.add(checkNoButton);

    add(__background);
    add(box1);
    add(monitor_Item1);
    add(monitor_Item2);
    add(monitor_Item3);
    add(monitor_Item4);
    add(monitor_Item5);
    add(monitor_Item6);
    add(monitor_Item7);
    add(monitor_Item8);
    add(monitor_Item9);
    add(monitor_Item10);
    add(checkModalWindow);
}

void Screen1ViewBase::setupScreen()
{
    monitor_Item1.initialize();
    monitor_Item2.initialize();
    monitor_Item3.initialize();
    monitor_Item4.initialize();
    monitor_Item5.initialize();
    monitor_Item6.initialize();
    monitor_Item7.initialize();
    monitor_Item8.initialize();
    monitor_Item9.initialize();
    monitor_Item10.initialize();
}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &checkYesButton)
    {
        //checkYesButtonPressed
        //When checkYesButton clicked hide checkModalWindow
        //Hide checkModalWindow
        checkModalWindow.setVisible(false);
        checkModalWindow.invalidate();

        //checkYesBtnGoToScreen2
        //When checkYesButtonPressed completed change screen to Screen2
        //Go to Screen2 with no screen transition
        application().gotoScreen2ScreenNoTransition();

        //checkYesButtonOk
        //When checkYesButtonPressed completed call virtual function
        //Call checkYesButtonOk
        checkYesButtonOk();
    }
    else if (&src == &checkNoButton)
    {
        //checkNoButtonPressed
        //When checkNoButton clicked hide checkModalWindow
        //Hide checkModalWindow
        checkModalWindow.setVisible(false);
        checkModalWindow.invalidate();
    }
}
