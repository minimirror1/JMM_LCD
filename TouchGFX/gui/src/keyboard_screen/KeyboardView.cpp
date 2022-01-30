#include <gui/keyboard_screen/KeyboardView.hpp>

extern Unicode::UnicodeChar keyboardBuffer[4][10];
extern uint8_t keyboardSelection;
extern uint8_t updateFlag;

KeyboardView::KeyboardView()
{
    Ckeyboard.setPosition(80, 16, 320, 240);
    add(Ckeyboard);
}

void KeyboardView::setupScreen()
{
    KeyboardViewBase::setupScreen();
}

void KeyboardView::tearDownScreen()
{
    KeyboardViewBase::tearDownScreen();
}

void KeyboardView::getKeyboardBuffer() 
{
    Unicode::UnicodeChar* buff = Ckeyboard.getBuffer();
    Unicode::strncpy(keyboardBuffer[keyboardSelection], buff, Unicode::strlen(buff) + 1);
    updateFlag |= (1 << keyboardSelection);
}