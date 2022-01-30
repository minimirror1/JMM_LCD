#include <gui/screen2_screen/Screen2View.hpp>

Unicode::UnicodeChar keyboardBuffer[4][10];
uint8_t keyboardSelection;
uint8_t updateFlag;

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

void Screen2View::KeyboardSeleted(uint8_t value)
{
    if (value > 0)
    {
        keyboardSelection = (value - 1);
    }
}

void Screen2View::handleTickEvent()
{
    static uint8_t backbuf[10] = { 0, };
    if (Unicode::strlen(keyboardBuffer[0]) > 0)	//PValue에 대해 Ckeyboard에서 입력한 값이 있을 경우,
    {
        if ((updateFlag & 0x01) == 0x01)// update를 해야하는지 체크.
        {
          memset(PValueBuffer, 0 , PVALUE_SIZE);	// PValue Widget 초기화.

          //string --> double(check only number)
          Unicode::toUTF8(keyboardBuffer[0], backbuf, PVALUE_SIZE);	//Unicode(UT16)에서 UT8로 변환 후,
          double prPValue = atof((const char*)backbuf);				//double로 변환.(여기에서 숫자만 변환됨. 숫자가 아니면 무조건 0)

          //double --> string(sprintf)
          Unicode::snprintfFloat(PValueBuffer, PVALUE_SIZE,"%4.3f", (float)prPValue);	//PValue Widget에 변환된 double 값을 문자열로 저장.
          PValue.invalidate();							//변경된 PValue Widget 출력.

          updateFlag &= ~0x01; // 상시로 같은 값을 출력하는 동작을 막기 위해.
        }
    }
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



