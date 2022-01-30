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
    if (Unicode::strlen(keyboardBuffer[0]) > 0)	//PValue�� ���� Ckeyboard���� �Է��� ���� ���� ���,
    {
        if ((updateFlag & 0x01) == 0x01)// update�� �ؾ��ϴ��� üũ.
        {
          memset(PValueBuffer, 0 , PVALUE_SIZE);	// PValue Widget �ʱ�ȭ.

          //string --> double(check only number)
          Unicode::toUTF8(keyboardBuffer[0], backbuf, PVALUE_SIZE);	//Unicode(UT16)���� UT8�� ��ȯ ��,
          double prPValue = atof((const char*)backbuf);				//double�� ��ȯ.(���⿡�� ���ڸ� ��ȯ��. ���ڰ� �ƴϸ� ������ 0)

          //double --> string(sprintf)
          Unicode::snprintfFloat(PValueBuffer, PVALUE_SIZE,"%4.3f", (float)prPValue);	//PValue Widget�� ��ȯ�� double ���� ���ڿ��� ����.
          PValue.invalidate();							//����� PValue Widget ���.

          updateFlag &= ~0x01; // ��÷� ���� ���� ����ϴ� ������ ���� ����.
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



