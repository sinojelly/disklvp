#include "../headers/SongListTemplate.h"

SongListTemplate::SongListTemplate() : Template() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Songlist1.ini");
	QString imageFile = GlobalData::ImagePrefix + "Common/Songlist.png";
	this->AddButton(&config,this,0,&imageFile);
	this->_setupSignalConnection();
	this->SetupPageSignalConnection();
}
void SongListTemplate::_setupSignalConnection(){
	for(int i=1;i<this->_ITEMCOUNT + 1;i++){
		MyButton* p_mb = this->FindButton("songlist" + QString::number(i));
		if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(ItemClick()));
	}
}

void SongListTemplate::ItemClick(){
	MyButton* p_mb = (MyButton*)this->sender();
	int index = ItemTextToInt(p_mb->Name());
	if(index > 0 && index <= this->_songList.size()){
		DbUtil::AddSongToOrderList(this->_songList.at(index - 1));
	}
	this->DisplayData();
	p_mb->Disabled();
}

void SongListTemplate::DisplayData(){
	PageInfo pi;
	QString str = this->_queryStr;
	this->_songList = DbUtil::GetSong_Page(str,this->_currentPage,QList<QVariant>(),&pi,5);
	this->_currentPage = pi.GetValidPage();
	this->_totalPages = pi.PageCount;
	this->ShowCurrentPage();
	this->ShowTotalPages();
	this->SetItemData(this->_songList);
}

void SongListTemplate::SetItemData(const QList<SongStruct>& songList){
	int i = 1;
	MyButton* p_mb = 0;
	for(;(i<songList.size() + 1) && (i < this->_ITEMCOUNT + 1);i++){
		p_mb = this->FindButton("songlist" + QString::number(i));
		if(p_mb){
			QString txt = songList.at(i-1).Name;

			if(songList.at(i-1).BeOrdered) txt += trUtf8("（已选）");
			else if(songList.at(i-1).Finished) txt += trUtf8("（完成）");
			else if(songList.at(i-1).Priority) txt += trUtf8("（优先）");

			QFont* p_font = new QFont(GlobalData::Font,GlobalData::SongItemTextSize, QFont::Normal);
			QPen* p_pen = new QPen();
			p_pen->setStyle(Qt::SolidLine);
			p_pen->setWidth(4);
			p_pen->setBrush(GlobalData::SongItemTextColor);
			p_mb->SetFont(p_font);
			p_mb->SetPen(p_pen);
			p_mb->SetTextPoint(GlobalData::SongItemTextPosition_X,GlobalData::SongItemTextPosition_Y);
			p_mb->SetText(txt);
			p_mb->Enabled();
			p_mb->show();
			if(songList.at(i-1).Finished) p_mb->Disabled();
		}
	}
	for(;i<this->_ITEMCOUNT + 1;i++){
		p_mb = this->FindButton("songlist" + QString::number(i));
		if(p_mb){
			p_mb->hide();
			p_mb->Enabled();
		}
	}
}
