#include "../headers/Newest.h"

Newest::Newest() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Newest.ini");
	this->AddButton(&config);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a ORDER BY a.songId DESC";
	this->DisplayData();
}
void Newest::ActionToDo(){
	//MyButton* p_mb = (MyButton*)this->sender();
}
