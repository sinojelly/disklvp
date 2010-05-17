#include "interface/headers/KtvMainScreen.h"
#include "interface/KtvScreenController.h"
#include <QtGui>
#include <QApplication>

#include "interface/headers/Atmospheres.h"

int main(int argc, char *argv[])
{
	
	DbUtil::UpdateSongLibrary();

	Q_INIT_RESOURCE(app);

    QApplication a(argc, argv);
    a.setApplicationName("KTV");

	KtvMainScreen *p_mainScreen = new KtvMainScreen();
	
    //a.setActiveWindow(new KtvMainScreen());
	KtvScreenController::GetController()->setMainScreen(p_mainScreen);
    p_mainScreen->display();

    //KtvScreenController::GetController()->Forward(new KtvMainScreen());

    /*return*/int ret = a.exec();
	Atmospheres::Instance()->Clear();
	return ret;
}
