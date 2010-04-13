#include "../headers/StarListTemplate.h"

StarListTemplate::StarListTemplate() : Template() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Starlist.ini");
	QString imageFile = GlobalData::ImagePrefix + "Common/Starlist.png";
	this->AddButton(&config,1,&imageFile);
	this->_setupSignalConnection();
}
void StarListTemplate::_setupSignalConnection(){
	for(int i=1;i<this->_ITEMCOUNT + 1;i++){
		MyButton* p_mb = this->FindButton("starlist" + QString::number(i));
		if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(ItemClick()));
	}
}

void StarListTemplate::ItemClick(){
	/** do nothing here.  **/
}

void StarListTemplate::DisplayData(){
	PageInfo pi;
	QString str = this->_queryStr;
	this->_singerList = DbUtil::GetSinger_Page(str,this->_currentPage,QList<QVariant>(),&pi,10);
	this->_currentPage = pi.GetValidPage();
	this->_totalPages = pi.PageCount;
	this->ShowCurrentPage();
	this->ShowTotalPages();
	this->SetItemData(this->_singerList);
}

void StarListTemplate::SetItemData(const QList<SingerStruct>& singerList){
	int i = 1;
	for(;i<singerList.size() + 1 && i < this->_ITEMCOUNT + 1;i++){
		StarButton* p_mb = (StarButton*)this->FindButton("starlist" + QString::number(i));
		if(p_mb){
			QFont* p_font = new QFont(GlobalData::Font,GlobalData::SingerItemTextSize, QFont::Normal);
			QPen* p_pen = new QPen();
			p_pen->setStyle(Qt::SolidLine);
			p_pen->setWidth(4);
			p_pen->setBrush(GlobalData::SingerItemTextColor);
			p_mb->SetFont(p_font);
			p_mb->SetPen(p_pen);
			p_mb->SetTextPoint(GlobalData::SingerItemTextPosition_X,GlobalData::SingerItemTextPosition_Y);
			p_mb->SetText(singerList.at(i-1).Name);
			p_mb->SetImage(singerList.at(i-1).PicturePath,GlobalData::SingerItemPicturePosition_X,GlobalData::SingerItemPicturePosition_Y);
			p_mb->Enabled();
			p_mb->show();
		}
	}
	for(;i<this->_ITEMCOUNT + 1;i++){
		MyButton* p_mb = this->FindButton("starlist" + QString::number(i));
		if(p_mb){
			p_mb->hide();
			p_mb->Enabled();
		}
	}
}
