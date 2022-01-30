#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0)
{

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

void Model::setScreenUp()
{
	modelListener->setID_SettingPage(settingGid, settingSid);
}
