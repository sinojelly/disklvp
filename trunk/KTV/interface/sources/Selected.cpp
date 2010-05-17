#include "../headers/Selected.h"
#include "../KtvScreenController.h"

Selected::Selected() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Selected.ini");
	this->AddButton(&config, KtvScreenController::GetController()->getMainScreen());
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.*,b.orderId,b.priority,b.finished FROM Song AS a,OrderList AS b WHERE a.songId=b.songId ORDER BY b.finished DESC,b.priority DESC,b.orderId ASC";
	this->DisplayData();
	MyButton* p_mb = this->FindButton("Toolsicon/order");
	if(p_mb) p_mb->Disabled();
	this->_currentIndex = -1;
}
void Selected::ItemClick(){
	MyButton* p_mb = (MyButton*)this->sender();
	this->_currentIndex = ItemTextToInt(p_mb->Name()) - 1;
}
void Selected::ActionToDo(){
	if(this->_currentIndex == -1) return;
	int orderId = this->_songList.at(this->_currentIndex).OrderId;

	MyButton* p_mb = (MyButton*)this->sender();
	if(p_mb->Name() == "Selected/jvimage3"){
		DbUtil::SetPriority(orderId);
	}
	else if(p_mb->Name() == "Selected/jvimage4"){
		DbUtil::DeleteSongFromOrderList(orderId);
	}
	this->DisplayData();
	this->_currentIndex = -1;
}
