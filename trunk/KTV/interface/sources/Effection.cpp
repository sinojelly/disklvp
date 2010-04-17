#include "../headers/Effection.h"

Effection::Effection() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Effect.ini");
	this->AddButton(&config);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.*,b.orderId,b.priority,b.finished FROM Song AS a,OrderList AS b WHERE a.songId=b.songId ORDER BY b.finished DESC,b.priority DESC,b.orderId ASC";
	this->DisplayData();
	MyButton* p_mb = this->FindButton("Toolsicon/effect");
	if(p_mb) p_mb->Disabled();
}
void Effection::ActionToDo(){
	//MyButton* p_mb = (MyButton*)this->sender();
	DisplayData();
}
void Effection::ItemClick(){
	/* do nothing here. */
}
