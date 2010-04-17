#include "../headers/BaseTemplate.h"
#include "../../Debug.h"
#include "../headers/Selected.h"
#include "../headers/Effection.h"
#include "../headers/Atmospheres.h"
#include "../headers/PlayScreen.h"
//#include <Phonon>
#include <QDialog>

BaseTemplate::BaseTemplate(const QImage* p_image,QWidget *parent)
    : QMainWindow(parent,Qt::FramelessWindowHint)
{
	this->_buttonList = new QList<MyButton*>();
	this->_p_image = p_image;
	InterfaceConfig config(GlobalData::ConfigPrefix + "Toolsicon.ini");
	this->AddButton(&config);
	this->_setupSignalConnection();
}

void BaseTemplate::_setupSignalConnection(){
	MyButton* p_mb = this->FindButton("Toolsicon/pagedown");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(NextPage()));
	p_mb = this->FindButton("Toolsicon/pageup");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(PreviousPage()));
	p_mb = this->FindButton("Toolsicon/next");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(NextSong()));
	p_mb = this->FindButton("Toolsicon/home");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(HomePage()));
	p_mb = this->FindButton("Toolsicon/BC");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(SingWith()));
	p_mb = this->FindButton("Toolsicon/stop");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(PlayAndPouse()));
	p_mb = this->FindButton("Toolsicon/YC");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(OriginalVoice()));
	p_mb = this->FindButton("Toolsicon/order");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(ViewSelected()));
	p_mb = this->FindButton("Toolsicon/phontom");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(Magic()));
	p_mb = this->FindButton("Toolsicon/effect");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(Effect()));
	p_mb = this->FindButton("Toolsicon/server");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(Service()));
	p_mb = this->FindButton("Toolsicon/Mood");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(Atmosphere()));
	p_mb = this->FindButton("Toolsicon/return");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(Back()));
	p_mb = this->FindButton("Toolsicon/replay");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(Resing()));
	p_mb = this->FindButton("Toolsicon/mute");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(Silent()));
	p_mb = this->FindButton("Toolsicon/add");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(VolumeUp()));
	p_mb = this->FindButton("Toolsicon/sub");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(VolumeDown()));
}

BaseTemplate::~BaseTemplate() {
	while(!this->_buttonList->isEmpty()){
		delete this->_buttonList->takeLast();
	}
	delete this->_buttonList;
}

void BaseTemplate::AddButton(InterfaceConfig* p_config,int buttonType,QString* p_imageFile){
	const QList<ButtonItemParameter*>* p_lbip = p_config->GetItemsList();
	for(int i=0;i<p_lbip->size();i++){
		ButtonItemParameter* p_bip = p_lbip->at(i);
		MyButton* p_mb;

		QImage* p_image = 0;
		if(p_imageFile){
			p_image = new QImage(*p_imageFile);
			if(p_image->isNull()){
				D::Print("Can not create image :" + (*p_imageFile));
				p_image = 0;
			}
		}

		if(buttonType == 0) p_mb = new MyButton(*p_bip,this,p_image);
		else p_mb = new StarButton(*p_bip,this,p_image);

		this->_buttonList->append(p_mb);
	}
}

void BaseTemplate::paintEvent(QPaintEvent *event){
	QPainter painter;
	this->setGeometry(0,0,this->_p_image->width(),this->_p_image->height());
	painter.begin(this);
	if(!this->_p_image->isNull()) painter.drawImage(QPoint(0,0),*this->_p_image);
	painter.end();
}

void BaseTemplate::mouseDoubleClickEvent(QMouseEvent *event){
	this->close();
}

void BaseTemplate::mousePressEvent(QMouseEvent *event){

}

MyButton* BaseTemplate::FindButton(const QString& name) const{
	MyButton* p_mb = 0;
	for(int i=this->_buttonList->size() - 1; i >= 0; i--){
		if(this->_buttonList->at(i)->Name() == name){
			p_mb = (*(this->_buttonList))[i];
			break;
		}
	}
	return p_mb;
}
int BaseTemplate::ItemTextToInt(const QString& str){
	QRegExp rx("(\\d{1,2})");
	int pos = rx.indexIn(str);
	if(pos > -1)
		return rx.cap(1).toInt();
	else return -1;
}

void BaseTemplate::NextPage(){
	/* do nothing here */
}
void BaseTemplate::PreviousPage(){
	/* do nothing here */
}

void BaseTemplate::HomePage(){
	KtvScreenController::GetController()->Home();
}
void BaseTemplate::Back(){
	KtvScreenController::GetController()->Back();
}
void BaseTemplate::PlayAndPouse(){
	KtvScreenController::GetController()->Forward(PlayScreen::Instance());
}
void BaseTemplate::Magic(){

}
void BaseTemplate::Silent(){
}
void BaseTemplate::OriginalVoice(){

}
void BaseTemplate::Atmosphere(){
	KtvScreenController::GetController()->Forward(Atmospheres::Instance());
	Atmospheres::Instance()->DisplayData();
}
void BaseTemplate::Resing(){

}
void BaseTemplate::Service(){

}
void BaseTemplate::SingWith(){

}
void BaseTemplate::Effect(){
	KtvScreenController::GetController()->Forward(Effection::Instance());
	Effection::Instance()->DisplayData();
}
void BaseTemplate::NextSong(){

}
void BaseTemplate::VolumeUp(){

}
void BaseTemplate::VolumeDown(){

}
void BaseTemplate::ViewSelected(){
	KtvScreenController::GetController()->Forward(Selected::Instance());
	Selected::Instance()->DisplayData();
}
