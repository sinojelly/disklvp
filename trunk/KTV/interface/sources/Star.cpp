#include "../headers/Star.h"
#include "../headers/SongList.h"

Star::Star() : StarListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Star2.ini");
	this->AddButton(&config, this);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT * FROM Singer ORDER BY singerId DESC";
	this->DisplayData();
}
void Star::ActionToDo(){
	MyButton* p_mb = (MyButton*)this->sender();
	if(p_mb->Name() == "Star/jvimage1") this->_queryStr = trUtf8("SELECT * FROM Singer WHERE singerCategory='港台女星' ORDER BY singerId DESC");
	if(p_mb->Name() == "Star/jvimage2") this->_queryStr = trUtf8("SELECT * FROM Singer WHERE singerCategory='港台男星' ORDER BY singerId DESC");
	if(p_mb->Name() == "Star/jvimage3") this->_queryStr = trUtf8("SELECT * FROM Singer WHERE singerCategory='大陆女星' ORDER BY singerId DESC");
	if(p_mb->Name() == "Star/jvimage4") this->_queryStr = trUtf8("SELECT * FROM Singer WHERE singerCategory='大陆男星' ORDER BY singerId DESC");
	if(p_mb->Name() == "Star/jvimage5") this->_queryStr = trUtf8("SELECT * FROM Singer WHERE singerCategory='欧美组合' ORDER BY singerId DESC");
	if(p_mb->Name() == "Star/jvimage6") this->_queryStr = trUtf8("SELECT * FROM Singer WHERE singerCategory='演唱组合' ORDER BY singerId DESC");
	this->DisplayData();
}
void Star::ItemClick(){
	QString queryString = "SELECT * FROM song ORDER BY songId DESC";
	MyButton* p_mb = (MyButton*)this->sender();

	int index = ItemTextToInt(p_mb->Name());
	if(index > 0 && index <= this->_singerList.size())
		queryString = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.singerId=" + QString::number(this->_singerList.at(index - 1).SingerId) + "  ORDER BY a.songId DESC";
	KtvScreenController::GetController()->Forward(
		new SongList(queryString));
}
