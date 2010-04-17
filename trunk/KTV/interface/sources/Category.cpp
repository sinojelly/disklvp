#include "../headers/Category.h"

Category::Category() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Category.ini");
	this->AddButton(&config);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a ORDER BY a.songId DESC";
	this->DisplayData();
}
void Category::ActionToDo(){
	MyButton* p_mb = (MyButton*)this->sender();
	if(p_mb->Name() == "Category/jvimage1")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='怀旧'");
	if(p_mb->Name() == "Category/jvimage2")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='舞蹈'");
	if(p_mb->Name() == "Category/jvimage3")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='戏剧'");
	if(p_mb->Name() == "Category/jvimage4")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='革命'");
	if(p_mb->Name() == "Category/jvimage5")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='DISCO'");
	if(p_mb->Name() == "Category/jvimage6")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='民歌'");
	if(p_mb->Name() == "Category/jvimage7")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='儿童'");
	if(p_mb->Name() == "Category/jvimage8")	this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songCategory='祝福'");
	DisplayData();
}
