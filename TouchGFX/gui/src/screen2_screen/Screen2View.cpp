#include <gui/screen2_screen/Screen2View.hpp>
Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    presenter->setScreenUp();
    setPosi(0);
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::setID_SettingPage(int gID, int sID)
{
    groupID = gID;
    subID = sID;

    Unicode::snprintf(idBuffer1, IDBUFFER1_SIZE, "%d", gID);
    id.setWildcard1(idBuffer1);
    id.invalidate();

    Unicode::snprintf(idBuffer2, IDBUFFER2_SIZE, "%d", sID);
    id.setWildcard2(idBuffer2);
    id.invalidate();

}

void Screen2View::setChangePosi(int gID, int sID, int value)
{
    if ((groupID == gID) && (subID == sID))
        setPosi(value);
}


void Screen2View::setPosi(int value)
{
    nowPosi = value;
    setPosiText(nowPosi);
    setPosiProgress(nowPosi);
}

void Screen2View::setPosiText(int value)
{
    Unicode::snprintf(posiBuffer, POSI_SIZE, "%d", value);
    posi.setWildcard(posiBuffer);
    posi.invalidate();
}

void Screen2View::setPosiProgress(int value)
{
    posiProgress.setValue(value);
}



