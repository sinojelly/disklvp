#include "../headers/Digital.h"

Digital::Digital() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Digital.ini");
	this->AddButton(&config);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a ORDER BY a.songId DESC";
	this->DisplayData();
}
void Digital::ActionToDo(){
	MyButton* p_mb = (MyButton*)this->sender();
	QString num = QString::number(ItemTextToInt(p_mb->Name()));
	if(num == "9")
		this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a ORDER BY a.songId DESC";
	else this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE LENGTH(a.songName) = " + num + " ORDER BY a.songId DESC";
	this->DisplayData();
}
