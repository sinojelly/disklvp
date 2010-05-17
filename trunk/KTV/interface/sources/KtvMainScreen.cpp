#include "../headers/KtvMainScreen.h"
#include "../KtvScreenController.h"
#include "../headers/HomeWidget.h"
#include "../KtvScreenController.h"
#include "../headers/Atmospheres.h"
#include "../headers/Effection.h"
#include "../headers/Selected.h"
#include "../headers/Digital.h"
#include "../headers/Category.h"
#include "../headers/PlayScreen.h"

KtvMainScreen::KtvMainScreen(const QImage* p_image,QWidget *parent) : QMainWindow(parent,Qt::FramelessWindowHint){
	_p_image = p_image;
}

void KtvMainScreen::display(void)
{
	InterfaceConfig config(GlobalData::ConfigPrefix + "Toolsicon.ini");
	this->AddButton(&config, this);
	KtvScreenController::GetController()->Forward(new HomeWidget());
	this->_setupSignalConnection();
	show();
}

void KtvMainScreen::_setupSignalConnection(){
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

/***************************************************************************************************************
 * SLOTS implementation.
 */

void KtvMainScreen::paintEvent(QPaintEvent *event){
	QPainter painter;
	this->setGeometry(0,0,this->_p_image->width(),this->_p_image->height());
	painter.begin(this);
	if(!this->_p_image->isNull()) painter.drawImage(QPoint(0,0),*this->_p_image);
	painter.end();
}

void KtvMainScreen::mouseDoubleClickEvent(QMouseEvent *event){
	this->close();
}

void KtvMainScreen::mousePressEvent(QMouseEvent *event){

}

void KtvMainScreen::NextPage(){
	/* do nothing here */
}
void KtvMainScreen::PreviousPage(){
	/* do nothing here */
}

void KtvMainScreen::HomePage(){
	KtvScreenController::GetController()->Home();
}
void KtvMainScreen::Back(){
	KtvScreenController::GetController()->Back();
}
void KtvMainScreen::PlayAndPouse(){
	KtvScreenController::GetController()->Forward(PlayScreen::Instance());
}
void KtvMainScreen::Magic(){

}
void KtvMainScreen::Silent(){
}
void KtvMainScreen::OriginalVoice(){

}
void KtvMainScreen::Atmosphere(){
	KtvScreenController::GetController()->Forward(Atmospheres::Instance());
	Atmospheres::Instance()->DisplayData();
}
void KtvMainScreen::Resing(){

}
void KtvMainScreen::Service(){

}
void KtvMainScreen::SingWith(){

}
void KtvMainScreen::Effect(){
	KtvScreenController::GetController()->Forward(Effection::Instance());
	Effection::Instance()->DisplayData();
}
void KtvMainScreen::NextSong(){

}
void KtvMainScreen::VolumeUp(){

}
void KtvMainScreen::VolumeDown(){

}
void KtvMainScreen::ViewSelected(){
	KtvScreenController::GetController()->Forward(Selected::Instance());
	Selected::Instance()->DisplayData();
}
