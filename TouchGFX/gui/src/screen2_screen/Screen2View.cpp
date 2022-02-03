#include <gui/screen2_screen/Screen2View.hpp>

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
    if (Unicode::strlen(keyboardBuffer[0]) > 0)	//PValue에 대해 Ckeyboard에서 입력한 값이 있을 경우,
    {
        if ((updateFlag & 0x01) == 0x01)// update를 해야하는지 체크.
        {
            //memset(limitMinVar_textAreaBuffer, 0, LIMITMINVAR_TEXTAREA_SIZE);	// PValue Widget 초기화.
            //Unicode::strncpy(limitMinVar_textAreaBuffer, keyboardBuffer[0], Unicode::strlen(keyboardBuffer[0]));
            //limitMinVar_textArea.invalidate();							//변경된 PValue Widget 출력.
            

            Unicode::snprintf(limitMinVar_textAreaBuffer, LIMITMINVAR_TEXTAREA_SIZE, keyboardBuffer[0]);
            limitMinVar_textArea.setWildcard(limitMinVar_textAreaBuffer);
            limitMinVar_textArea.invalidate();
            memset(keyboardBuffer[0], 0, 30);
#if 0
            memset(PValueBuffer, 0, PVALUE_SIZE);	// PValue Widget 초기화.

            //string --> double(check only number)
            Unicode::toUTF8(keyboardBuffer[0], backbuf, PVALUE_SIZE);	//Unicode(UT16)에서 UT8로 변환 후,
            double prPValue = atof((const char*)backbuf);				//double로 변환.(여기에서 숫자만 변환됨. 숫자가 아니면 무조건 0)

            //double --> string(sprintf)
            Unicode::snprintf(PValueBuffer, PVALUE_SIZE, "%d", (int)prPValue);	//PValue Widget에 변환된 double 값을 문자열로 저장.
            PValue.invalidate();							//변경된 PValue Widget 출력.
#endif

            updateFlag &= ~0x01; // 상시로 같은 값을 출력하는 동작을 막기 위해.
        }
    }
    else if (Unicode::strlen(keyboardBuffer[1]) > 0)	//PValue에 대해 Ckeyboard에서 입력한 값이 있을 경우,
    {
        if ((updateFlag & 0x02) == 0x02)// update를 해야하는지 체크.
        {
            //memset(limitMaxVar_textAreaBuffer, 0, LIMITMAXVAR_TEXTAREA_SIZE);	// PValue Widget 초기화.
            //Unicode::strncpy(limitMaxVar_textAreaBuffer, keyboardBuffer[1], Unicode::strlen(keyboardBuffer[1]));
            //limitMaxVar_textArea.invalidate();
            //memset(keyboardBuffer[1], 0, 30);

            Unicode::snprintf(limitMaxVar_textAreaBuffer, LIMITMAXVAR_TEXTAREA_SIZE, keyboardBuffer[1]);
            limitMaxVar_textArea.setWildcard(limitMaxVar_textAreaBuffer);
            limitMaxVar_textArea.invalidate();
            memset(keyboardBuffer[1], 0, 30);

            updateFlag &= ~0x02; // 상시로 같은 값을 출력하는 동작을 막기 위해.
        }
    }
    else if (Unicode::strlen(keyboardBuffer[2]) > 0)	//PValue에 대해 Ckeyboard에서 입력한 값이 있을 경우,
    {
        if ((updateFlag & 0x04) == 0x04)// update를 해야하는지 체크.
        {
            //memset(map_0Var_textAreaBuffer, 0, MAP_0VAR_TEXTAREA_SIZE);	// PValue Widget 초기화.
            //Unicode::strncpy(map_0Var_textAreaBuffer, keyboardBuffer[2], Unicode::strlen(keyboardBuffer[2]));
            //map_0Var_textArea.invalidate();
            //memset(keyboardBuffer[2], 0, 30);

            Unicode::snprintf(map_0Var_textAreaBuffer, MAP_0VAR_TEXTAREA_SIZE, keyboardBuffer[2]);
            map_0Var_textArea.setWildcard(map_0Var_textAreaBuffer);
            map_0Var_textArea.invalidate();
            memset(keyboardBuffer[2], 0, 30);
            updateFlag &= ~0x04; // 상시로 같은 값을 출력하는 동작을 막기 위해.
        }
    }
    else if (Unicode::strlen(keyboardBuffer[3]) > 0)	//PValue에 대해 Ckeyboard에서 입력한 값이 있을 경우,
    {
        if ((updateFlag & 0x08) == 0x08)// update를 해야하는지 체크.
        {
            //memset(map_4095Var_textAreaBuffer, 0, MAP_4095VAR_TEXTAREA_SIZE);	// PValue Widget 초기화.
            //Unicode::strncpy(map_4095Var_textAreaBuffer, keyboardBuffer[3], Unicode::strlen(keyboardBuffer[3]));
            //map_4095Var_textArea.invalidate();
            //memset(keyboardBuffer[3], 0, 30);

            Unicode::snprintf(map_4095Var_textAreaBuffer, MAP_4095VAR_TEXTAREA_SIZE, keyboardBuffer[3]);
            map_4095Var_textArea.setWildcard(map_4095Var_textAreaBuffer);
            map_4095Var_textArea.invalidate();
            memset(keyboardBuffer[3], 0, 30);

            updateFlag &= ~0x08; // 상시로 같은 값을 출력하는 동작을 막기 위해.
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

void Screen2View::setSettingValue(int lim_min, int lim_max, int map_0, int map_4095, int filter)
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
    FilterVar_textArea.invalidate();

    slider1.setValue(filter);

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
    FilterVar_textArea.invalidate();
}





