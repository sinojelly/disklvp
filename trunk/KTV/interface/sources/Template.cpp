#include "../headers/Template.h"
#include "../../Debug.h"

Template::Template(const QImage* p_image): BaseTemplate(p_image){
	InterfaceConfig config(GlobalData::ConfigPrefix + "Page.ini");
	this->AddButton(&config);
	this->_p_currentPageBut = this->FindButton("Page/current");
	this->_p_totalPageBut = this->FindButton("Page/total");
	this->InitialPageZone(1,1);
}
void Template::SetupSignalConnection(const QList<QString> nameList){
	for(int i=0;i<nameList.size();i++){
		MyButton* p_mb = this->FindButton(nameList.at(i));
		if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(ActionToDo()));
	}
}

void Template::InitialPageZone(int currentPage,int totalPage){
	QFont font(GlobalData::Font, GlobalData::PageNumberSize, QFont::Bold);
	QPen pen;
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(4);
	pen.setBrush(GlobalData::PageNumberColor);

	MyButton* p_mb = this->_p_currentPageBut;
	if(p_mb){
		p_mb->SetTextPoint(GlobalData::PageNumberLeftPosition_X,GlobalData::PageNumberLeftPosition_Y);
		p_mb->SetFont(new QFont(font));
		p_mb->SetPen(new QPen(pen));
		p_mb->setCursor(Qt::ArrowCursor);
	}

	p_mb = this->_p_totalPageBut;
	if(p_mb){
		p_mb->SetTextPoint(GlobalData::PageNumberRightPosition_X,GlobalData::PageNumberRightPosition_Y);
		p_mb->SetFont(new QFont(font));
		p_mb->SetPen(new QPen(pen));
		p_mb->setCursor(Qt::ArrowCursor);
	}
	this->_currentPage = currentPage;
	this->_totalPages = totalPage;
	this->ShowCurrentPage();
	this->ShowTotalPages();
}
void Template::ShowCurrentPage(){
	MyButton* p_mb = this->_p_currentPageBut;
	if(p_mb) p_mb->SetText(QString::number(this->_currentPage));
}
void Template::ShowTotalPages(){
	MyButton* p_mb = this->_p_totalPageBut;
	if(p_mb) p_mb->SetText(QString::number(this->_totalPages));
}
void Template::NextPage(){
	if(this->_currentPage < this->_totalPages){
		this->_currentPage ++;
		this->DisplayData();
	}
}
void Template::PreviousPage(){
	if(this->_currentPage > 1){
		this->_currentPage --;
		this->DisplayData();
	}
}

void Template::ActionToDo(){
	/** do nothing here **/
}
void Template::DisplayData(){
	/** do nothing here */
}
