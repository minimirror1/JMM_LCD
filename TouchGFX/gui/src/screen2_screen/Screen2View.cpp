#include <gui/screen2_screen/Screen2View.hpp>

#ifndef SIMULATOR
#include <stdlib.h>
#endif

Unicode::UnicodeChar keyboardBuffer[7][30];
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
	if (Unicode::strlen(keyboardBuffer[0]) > 0)
	{
		if ((updateFlag & 0x01) == 0x01)
		{
			uint8_t utf8Buff[20];
			Unicode::toUTF8(keyboardBuffer[0], utf8Buff, 20);
			int value = atoi((const char*)utf8Buff);
			if (value > 4095)
				value = 4095;
			presenter->setChangeLimitMin(myIndex, value);

			Unicode::snprintf(limitMinVar_textAreaBuffer, LIMITMINVAR_TEXTAREA_SIZE, "%d", value);
			limitMinVar_textArea.setWildcard(limitMinVar_textAreaBuffer);
			limitMinVar_textArea.invalidate();



			memset(keyboardBuffer[0], 0, 30);
			updateFlag &= ~0x01;
		}
	}
	else if (Unicode::strlen(keyboardBuffer[1]) > 0)
	{
		if ((updateFlag & 0x02) == 0x02)
		{

			uint8_t utf8Buff[20];
			Unicode::toUTF8(keyboardBuffer[1], utf8Buff, 20);
			int value = atoi((const char*)utf8Buff);
			if (value > 4095)
				value = 4095;
			presenter->setChangeLimitMax(myIndex, value);


			Unicode::snprintf(limitMaxVar_textAreaBuffer, LIMITMAXVAR_TEXTAREA_SIZE, "%d", value);
			limitMaxVar_textArea.setWildcard(limitMaxVar_textAreaBuffer);
			limitMaxVar_textArea.invalidate();

			memset(keyboardBuffer[1], 0, 30);

			updateFlag &= ~0x02;
		}
	}
	else if (Unicode::strlen(keyboardBuffer[2]) > 0)
	{
		if ((updateFlag & 0x04) == 0x04)
		{

			uint8_t utf8Buff[20];
			Unicode::toUTF8(keyboardBuffer[2], utf8Buff, 20);
			int value = atoi((const char*)utf8Buff);
			if (value > 4095)
				value = 4095;
			presenter->setChangeMap_0(myIndex, value);

			Unicode::snprintf(map_0Var_textAreaBuffer, MAP_0VAR_TEXTAREA_SIZE, "%d", value);
			map_0Var_textArea.setWildcard(map_0Var_textAreaBuffer);
			map_0Var_textArea.invalidate();

			memset(keyboardBuffer[2], 0, 30);
			updateFlag &= ~0x04;
		}
	}
	else if (Unicode::strlen(keyboardBuffer[3]) > 0)
	{
		if ((updateFlag & 0x08) == 0x08)
		{

			uint8_t utf8Buff[20];
			Unicode::toUTF8(keyboardBuffer[3], utf8Buff, 20);
			int value = atoi((const char*)utf8Buff);
			if (value > 4095)
				value = 4095;
			presenter->setChangeMap_4095(myIndex, value);

			Unicode::snprintf(map_4095Var_textAreaBuffer, MAP_4095VAR_TEXTAREA_SIZE, "%d", value);
			map_4095Var_textArea.setWildcard(map_4095Var_textAreaBuffer);
			map_4095Var_textArea.invalidate();

			memset(keyboardBuffer[3], 0, 30);

			updateFlag &= ~0x08;
		}
	}
	else if (Unicode::strlen(keyboardBuffer[4]) > 0)
	{
		if ((updateFlag & 0x10) == 0x10)
		{

			uint8_t utf8Buff[20];
			Unicode::toUTF8(keyboardBuffer[4], utf8Buff, 20);
			int value = atoi((const char*)utf8Buff);
			if (value > 100)
				value = 100;
			//model

			groupID = value;
			setID_SettingPage(myIndex, groupID, subID);
			memset(keyboardBuffer[4], 0, 30);

			updateFlag &= ~0x10;
		}
	}
	else if (Unicode::strlen(keyboardBuffer[5]) > 0)
	{
		if ((updateFlag & 0x20) == 0x20)
		{

			uint8_t utf8Buff[20];
			Unicode::toUTF8(keyboardBuffer[5], utf8Buff, 20);
			int value = atoi((const char*)utf8Buff);
			if (value > 100)
				value = 100;
			//model

			subID = value;
			setID_SettingPage(myIndex, groupID, subID);
			memset(keyboardBuffer[5], 0, 30);

			updateFlag &= ~0x20;
		}
	}
	else if (Unicode::strlen(keyboardBuffer[6]) > 0)
	{
		if ((updateFlag & 0x40) == 0x40)
		{

			uint8_t utf8Buff[20];
			Unicode::toUTF8(keyboardBuffer[6], utf8Buff, 20);
			int value = atoi((const char*)utf8Buff);
			if (value > 100)
				value = 100;

			setSlideID_SettingPage(myIndex, value);

			memset(keyboardBuffer[6], 0, 30);
			updateFlag &= ~0x40;
		}
	}
}

void Screen2View::setSlideID_SettingPage(int index, int slideID)
{
	slideId = slideID;

	presenter->setChangeSlideid(index, slideId);

	Unicode::snprintf(slide_idBuffer, SLIDE_ID_SIZE, "%d", slideId);
	slide_id.setWildcard(slide_idBuffer);
	slide_id.invalidate();
}

void Screen2View::setID_SettingPage(int index, int gID, int sID)
{
	myIndex = index;
	groupID = gID;
	subID = sID;

	presenter->setChangeGid(index, gID);
	presenter->setChangeSid(index, sID);

	Unicode::snprintf(idBuffer1, IDBUFFER1_SIZE, "%d", gID);
	id.setWildcard1(idBuffer1);
	id.invalidate();

	Unicode::snprintf(idBuffer2, IDBUFFER2_SIZE, "%d", sID);
	id.setWildcard2(idBuffer2);
	id.invalidate();

}

void Screen2View::setSettingValue(int index, int gID, int sID, int lim_min, int lim_max, int map_0, int map_4095, int filter, bool reverse)
{
	//limit min
	Unicode::snprintf(limitMinVar_textAreaBuffer, LIMITMINVAR_TEXTAREA_SIZE, "%d", lim_min);
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
	posiX += ((float)slider1.getWidth() - 70) * ((float)slider1.getValue() / 14);
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

	presenter->setChangeFIlter(myIndex, value);
}

void Screen2View::reverseButton()
{
	presenter->setChangeReverse(myIndex, toggleButton1.getState());
}





