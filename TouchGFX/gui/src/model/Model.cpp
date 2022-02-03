#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{
	setting[0].gID = 1;
	setting[0].sID = 1;

	setting[1].gID = 1;
	setting[1].sID = 2;

	setting[2].gID = 5;
	setting[2].sID = 5;

	setting[3].gID = 1;
	setting[3].sID = 2;
}

void Model::tick()
{
	myTimer++;
	if (myTimer > 0)
	{
		myTimer = 0;
		testCnt += 10;

		if (testCnt > 4095)
			testCnt = 0;

		modelListener->setChangePosi(5, 5, testCnt);
	}
}


void Model::setOpenSettingView(int gID, int sID)
{
	settingGid = gID;
	settingSid = sID;
	
	modelListener->setID_SettingPage(gID, sID);
}

int Model::getGroupID(int index)
{
	if (index < 10)
		return setting[index].gID;
	else
		return 0;
}

int Model::getSubID(int index)
{
	if (index < 10)
		return setting[index].sID;
	else
		return 0;
}

void Model::setScreenUp()
{
	modelListener->setID_SettingPage(settingGid, settingSid);
	int index = getIndex(settingGid, settingSid);
	if (index < 10)
	{
		modelListener->setSettingValue(
			setting[index].limit_min,
			setting[index].limit_max,
			setting[index].map_0,
			setting[index].map_4095,
			setting[index].filter,
			setting[index].reverse);
	}
}

void Model::setChangeLimitMin(int gID, int sID, int value)
{
	int index = getIndex(gID, sID);
	if (index < 10)
	{
		setting[index].limit_min = value;
	}
}

void Model::setChangeLimitMax(int gID, int sID, int value)
{
	int index = getIndex(gID, sID);
	if (index < 10)
	{
		setting[index].limit_max = value;
	}
}

void Model::setChangeMap_0(int gID, int sID, int value)
{
	int index = getIndex(gID, sID);
	if (index < 10)
	{
		setting[index].map_0 = value;
	}
}

void Model::setChangeMap_4095(int gID, int sID, int value)
{
	int index = getIndex(gID, sID);
	if (index < 10)
	{
		setting[index].map_4095 = value;
	}
}

void Model::setChangeFIlter(int gID, int sID, int value)
{
	int index = getIndex(gID, sID);
	if (index < 10)
	{
		setting[index].filter = value;
	}
}

void Model::setChangeReverse(int gID, int sID, bool value)
{
	int index = getIndex(gID, sID);
	if (index < 10)
	{
		setting[index].reverse = value;
	}
}

int Model::getIndex(int gID, int sID)
{
	for (int i = 0; i < 10; i++)
	{
		if ((setting[i].gID == gID) && (setting[i].sID == sID))
		{
			return i;
		}
	}
	return 10;
}
