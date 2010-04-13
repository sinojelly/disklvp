#include "../headers/Private.h"

Private::Private() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Private.ini");
	this->AddButton(&config);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.* FROM Song AS a,PrivateSong AS b WHERE a.songId=b.songId AND b.userId=" + QString::number(GlobalData::CurrentUserId) + " ORDER BY a.songId DESC";
	this->DisplayData();
}
void Private::ActionToDo(){
	MyButton* p_mb = (MyButton*)this->sender();
	if(p_mb->Name() == "Private/jvimage4") KtvScreenController::GetController()->Forward(new Register("register"));
	if(p_mb->Name() == "Private/jvimage3") KtvScreenController::GetController()->Forward(new Register("login"));
}
