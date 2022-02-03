#include <gui/screen2_screen/Screen2View.hpp>

#ifndef SIMULATOR
#include <stdlib.h>
#endif

Unicode::UnicodeChar keyboardBuffer[4][30];
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

void Screen2View::keyBoardSelected(uint8_t value)
{
    if (value > 0)
    {
        keyboardSelection = (value - 1);
    }
}

void Screen2View::handleTickEvent()
{
    //static uint8_t backbuf[20] = { 0, };
    if (Unicode::strlen(keyboardBuffer[0]) > 0)	//PValue�� ���� Ckeyboard���� �Է��� ���� ���� ���,
    {
        if ((updateFlag & 0x01) == 0x01)// update�� �ؾ��ϴ��� üũ.
        {
            //memset(limitMinVar_textAreaBuffer, 0, LIMITMINVAR_TEXTAREA_SIZE);	// PValue Widget �ʱ�ȭ.
            //Unicode::strncpy(limitMinVar_textAreaBuffer, keyboardBuffer[0], Unicode::strlen(keyboardBuffer[0]));
            //limitMinVar_textArea.invalidate();							//����� PValue Widget ���.

            uint8_t utf8Buff[20];
            Unicode::toUTF8(keyboardBuffer[0], utf8Buff, 20);	//Unicode(UT16)���� UT8�� ��ȯ ��,            
            int value = atoi((const char*)utf8Buff);
            if (value > 4095)
                value = 4095;
            presenter->setChangeLimitMin(groupID, subID, value);            

            Unicode::snprintf(limitMinVar_textAreaBuffer, LIMITMINVAR_TEXTAREA_SIZE, "%d", value);
            limitMinVar_textArea.setWildcard(limitMinVar_textAreaBuffer);
            limitMinVar_textArea.invalidate();

            

            memset(keyboardBuffer[0], 0, 30);
#if 0
            memset(PValueBuffer, 0, PVALUE_SIZE);	// PValue Widget �ʱ�ȭ.

            //string --> double(check only number)
            Unicode::toUTF8(keyboardBuffer[0], backbuf, PVALUE_SIZE);	//Unicode(UT16)���� UT8�� ��ȯ ��,
            double prPValue = atof((const char*)backbuf);				//double�� ��ȯ.(���⿡�� ���ڸ� ��ȯ��. ���ڰ� �ƴϸ� ������ 0)

            //double --> string(sprintf)
            Unicode::snprintf(PValueBuffer, PVALUE_SIZE, "%d", (int)prPValue);	//PValue Widget�� ��ȯ�� double ���� ���ڿ��� ����.
            PValue.invalidate();							//����� PValue Widget ���.
#endif

            updateFlag &= ~0x01; // ��÷� ���� ���� ����ϴ� ������ ���� ����.
        }
    }
    else if (Unicode::strlen(keyboardBuffer[1]) > 0)	//PValue�� ���� Ckeyboard���� �Է��� ���� ���� ���,
    {
        if ((updateFlag & 0x02) == 0x02)// update�� �ؾ��ϴ��� üũ.
        {
            //memset(limitMaxVar_textAreaBuffer, 0, LIMITMAXVAR_TEXTAREA_SIZE);	// PValue Widget �ʱ�ȭ.
            //Unicode::strncpy(limitMaxVar_textAreaBuffer, keyboardBuffer[1], Unicode::strlen(keyboardBuffer[1]));
            //limitMaxVar_textArea.invalidate();
            //memset(keyboardBuffer[1], 0, 30);

            uint8_t utf8Buff[20];
            Unicode::toUTF8(keyboardBuffer[1], utf8Buff, 20);	//Unicode(UT16)���� UT8�� ��ȯ ��,            
            int value = atoi((const char*)utf8Buff);
            if (value > 4095)
                value = 4095;
            presenter->setChangeLimitMax(groupID, subID, value);
            

            Unicode::snprintf(limitMaxVar_textAreaBuffer, LIMITMAXVAR_TEXTAREA_SIZE, "%d", value);
            limitMaxVar_textArea.setWildcard(limitMaxVar_textAreaBuffer);
            limitMaxVar_textArea.invalidate();            

            memset(keyboardBuffer[1], 0, 30);

            updateFlag &= ~0x02; // ��÷� ���� ���� ����ϴ� ������ ���� ����.
        }
    }
    else if (Unicode::strlen(keyboardBuffer[2]) > 0)	//PValue�� ���� Ckeyboard���� �Է��� ���� ���� ���,
    {
        if ((updateFlag & 0x04) == 0x04)// update�� �ؾ��ϴ��� üũ.
        {
            //memset(map_0Var_textAreaBuffer, 0, MAP_0VAR_TEXTAREA_SIZE);	// PValue Widget �ʱ�ȭ.
            //Unicode::strncpy(map_0Var_textAreaBuffer, keyboardBuffer[2], Unicode::strlen(keyboardBuffer[2]));
            //map_0Var_textArea.invalidate();
            //memset(keyboardBuffer[2], 0, 30);

            uint8_t utf8Buff[20];
            Unicode::toUTF8(keyboardBuffer[2], utf8Buff, 20);	//Unicode(UT16)���� UT8�� ��ȯ ��,            
            int value = atoi((const char*)utf8Buff);
            if (value > 4095)
                value = 4095;
            presenter->setChangeMap_0(groupID, subID, value);            

            Unicode::snprintf(map_0Var_textAreaBuffer, MAP_0VAR_TEXTAREA_SIZE, "%d", value);
            map_0Var_textArea.setWildcard(map_0Var_textAreaBuffer);
            map_0Var_textArea.invalidate();            

            memset(keyboardBuffer[2], 0, 30);
            updateFlag &= ~0x04; // ��÷� ���� ���� ����ϴ� ������ ���� ����.
        }
    }
    else if (Unicode::strlen(keyboardBuffer[3]) > 0)	//PValue�� ���� Ckeyboard���� �Է��� ���� ���� ���,
    {
        if ((updateFlag & 0x08) == 0x08)// update�� �ؾ��ϴ��� üũ.
        {
            //memset(map_4095Var_textAreaBuffer, 0, MAP_4095VAR_TEXTAREA_SIZE);	// PValue Widget �ʱ�ȭ.
            //Unicode::strncpy(map_4095Var_textAreaBuffer, keyboardBuffer[3], Unicode::strlen(keyboardBuffer[3]));
            //map_4095Var_textArea.invalidate();
            //memset(keyboardBuffer[3], 0, 30);

            uint8_t utf8Buff[20];
            Unicode::toUTF8(keyboardBuffer[3], utf8Buff, 20);	//Unicode(UT16)���� UT8�� ��ȯ ��,            
            int value = atoi((const char*)utf8Buff);
            if (value > 4095)
                value = 4095;
            presenter->setChangeMap_4095(groupID, subID, value);            

            Unicode::snprintf(map_4095Var_textAreaBuffer, MAP_4095VAR_TEXTAREA_SIZE, "%d", value);
            map_4095Var_textArea.setWildcard(map_4095Var_textAreaBuffer);
            map_4095Var_textArea.invalidate();            

            memset(keyboardBuffer[3], 0, 30);

            updateFlag &= ~0x08; // ��÷� ���� ���� ����ϴ� ������ ���� ����.
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

void Screen2View::setSettingValue(int lim_min, int lim_max, int map_0, int map_4095, int filter, bool reverse)
{
    //limit min
    Unicode::snprintf(limitMinVar_textAreaBuffer, LIMITMINVAR_TEXTAREA_SIZE,"%d", lim_min);
    limitMinVar_textArea.setWildcard(limitMinVar_textAreaBuffer);
    limitMinVar_textArea.invalidate();
    //limit max
    Unicode::snprintf(limitMaxVar_textAreaBuffer, LIMITMAXVAR_TEXTAREA_SIZE, "%d", lim_max);
    limitMaxVar_textArea.setWildcard(limitMaxVar_textAreaBuffer);
    limitMaxVar_textArea.invalidate();
    //map_0
    Unicode::snprintf(map_0Var_textAreaBuffer, MAP_0VAR_TEXTAREA_SIZE, "%d", map_0);
    map_0Var_textArea.setWildcard(map_0Var_textAreaBuffer);
    map_0Var_textArea.invalidate();
    //map_4095
    Unicode::snprintf(map_4095Var_textAreaBuffer, MAP_4095VAR_TEXTAREA_SIZE, "%d", map_4095);
    map_4095Var_textArea.setWildcard(map_4095Var_textAreaBuffer);
    map_4095Var_textArea.invalidate();

    //filter
    Unicode::snprintf(FilterVar_textAreaBuffer, FILTERVAR_TEXTAREA_SIZE, "%d", filter);
    FilterVar_textArea.setWildcard(FilterVar_textAreaBuffer);
    float posiX = 0;
    posiX = (float)slider1.getX() + 20;
    posiX += ((float)slider1.getWidth()-70) * ((float)slider1.getValue() / 14);
    FilterVar_textArea.setX((int16_t)posiX);
    FilterVar_textArea.invalidate();

    slider1.setValue(filter);

    //reverse
    toggleButton1.forceState(reverse);

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
void Screen2View::filter_value(int value)
{
    Unicode::snprintf(FilterVar_textAreaBuffer, FILTERVAR_TEXTAREA_SIZE, "%d", value);
    FilterVar_textArea.setWildcard(FilterVar_textAreaBuffer);
    float posiX = 0;
    posiX = (float)slider1.getX() + 20;
    posiX += ((float)slider1.getWidth() - 70) * ((float)slider1.getValue() / 14);
    FilterVar_textArea.setX((int16_t)posiX);
    FilterVar_textArea.invalidate();
    
    presenter->setChangeFIlter(groupID, subID, value);
}

void Screen2View::reverseButton()
{
    presenter->setChangeReverse(groupID, subID, toggleButton1.getState());
}





