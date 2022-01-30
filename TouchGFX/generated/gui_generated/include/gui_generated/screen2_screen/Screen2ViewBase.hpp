/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN2VIEWBASE_HPP
#define SCREEN2VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/progress_indicators/CircleProgress.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565Bitmap.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Screen2ViewBase : public touchgfx::View<Screen2Presenter>
{
public:
    Screen2ViewBase();
    virtual ~Screen2ViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::CircleProgress posiProgress;
    touchgfx::PainterRGB565Bitmap posiProgressPainter;
    touchgfx::TextAreaWithOneWildcard posi;
    touchgfx::ToggleButton toggleButton1;
    touchgfx::Button button1;
    touchgfx::TextAreaWithTwoWildcards id;
    touchgfx::TextArea textArea1_2;

    /*
     * Wildcard Buffers
     */
    static const uint16_t POSI_SIZE = 10;
    touchgfx::Unicode::UnicodeChar posiBuffer[POSI_SIZE];
    static const uint16_t IDBUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar idBuffer1[IDBUFFER1_SIZE];
    static const uint16_t IDBUFFER2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar idBuffer2[IDBUFFER2_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen2ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SCREEN2VIEWBASE_HPP
