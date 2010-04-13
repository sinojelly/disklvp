#include "../headers/Language.h"

Language::Language() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Language.ini");
	this->AddButton(&config);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a ORDER BY a.songId DESC";
	this->DisplayData();
}
void Language::ActionToDo(){
	MyButton* p_mb = (MyButton*)this->sender();
	if(p_mb->Name() == "Language/jvimage2") this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songLanguage='国语歌曲' ORDER BY a.songId DESC");
	if(p_mb->Name() == "Language/jvimage3") this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songLanguage='闽南歌曲' ORDER BY a.songId DESC");
	if(p_mb->Name() == "Language/jvimage4") this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songLanguage='粤语歌曲' ORDER BY a.songId DESC");
	if(p_mb->Name() == "Language/jvimage5") this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songLanguage='韩语歌曲' ORDER BY a.songId DESC");
	if(p_mb->Name() == "Language/jvimage6") this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songLanguage='日语歌曲' ORDER BY a.songId DESC");
	if(p_mb->Name() == "Language/jvimage7") this->_queryStr = trUtf8("SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a WHERE a.songLanguage='英文歌曲' ORDER BY a.songId DESC");
	if(p_mb->Name() == "Language/jvimage1") this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a ORDER BY a.songId DESC";
	this->DisplayData();
}
