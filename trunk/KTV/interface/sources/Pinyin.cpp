#include "../headers/Pinyin.h"

Pinyin::Pinyin() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Pinyin.ini");
	this->AddButton(&config, this);
	this->SetupSignalConnection(config.GetNameList());

	MyButton* p_mb = this->FindButton("Pinyin/show");
	if(p_mb){
		p_mb->Disabled();
		QFont* p_font = new QFont(GlobalData::Font,24, QFont::Normal);
		QPen* p_pen = new QPen();
		p_pen->setStyle(Qt::SolidLine);
		p_pen->setWidth(2);
		p_pen->setBrush(GlobalData::SongItemTextColor);
		p_mb->SetFont(p_font);
		p_mb->SetPen(p_pen);
		p_mb->SetTextPoint(25,27);
	}

	this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM song AS a ORDER BY a.songId DESC";
	this->_txt = "";
	this->DisplayData();
}
void Pinyin::ActionToDo(){

	MyButton* p_mb = (MyButton*)this->sender();

	if(p_mb->Name() == "Pinyin/del"){
		this->_txt = this->_txt.left(this->_txt.length() - 1);
	}
	else if(p_mb->Name() != "Pinyin/show"){
		this->_txt += p_mb->Name().right(1);
	}

	p_mb = this->FindButton("Pinyin/show");
	if(p_mb){
		p_mb->SetText(this->_txt);
	}

	this->_queryStr = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered FROM Song AS a WHERE a.pinyin LIKE '"+ this->_txt +"%'";
	this->DisplayData();

}
