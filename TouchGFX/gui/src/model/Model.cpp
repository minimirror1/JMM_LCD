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
