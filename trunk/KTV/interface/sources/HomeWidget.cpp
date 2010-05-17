#include "../headers/HomeWidget.h"
#include "../headers/SongList.h"
#include "../KtvScreenController.h"
#include "../headers/Newest.h"
#include "../headers/Private.h"
#include "../headers/Pinyin.h"
#include "../headers/Language.h"
#include "../headers/Digital.h"
#include "../headers/Star.h"
#include "../headers/Stroke.h"
#include "../headers/Category.h"

HomeWidget::HomeWidget() : Template(){
	InterfaceConfig config(GlobalData::ConfigPrefix + "MainScreen.ini");
	this->AddButton(&config, this);
	this->_setupSignalConnection();
	MyButton* p_mb = this->FindButton("Toolsicon/pageup");
	if(p_mb) p_mb->Disabled();
	p_mb = this->FindButton("Toolsicon/pagedown");
	if(p_mb) p_mb->Disabled();
}

void HomeWidget::_setupSignalConnection(){
	MyButton* p_mb = this->FindButton(trUtf8("全部歌曲"));
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(AllSongClick()));
	p_mb = this->FindButton("MainScreen/jvimage2");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(NewestSongClick()));
	p_mb = this->FindButton("MainScreen/jvimage3");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(HotOrderClick()));
	p_mb = this->FindButton("MainScreen/jvimage4");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(PrivateSongClick()));
	p_mb = this->FindButton("MainScreen/jvimage5");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(PinyinFilterClick()));
	p_mb = this->FindButton("MainScreen/jvimage6");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(LanguageCategoryFilterClick()));
	p_mb = this->FindButton("MainScreen/jvimage7");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(DigitalFilterClick()));
	p_mb = this->FindButton("MainScreen/jvimage8");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(StarFilterClick()));
	p_mb = this->FindButton("MainScreen/jvimage9");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(BihuaFilterClick()));
	p_mb = this->FindButton("MainScreen/jvimage10");
	if(p_mb)QObject::connect(p_mb, SIGNAL(click()),this, SLOT(CategoryFilterClick()));
}

void HomeWidget::AllSongClick() const{
	QString allSongQueryString = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered  FROM Song AS a ORDER BY a.songRegTime DESC";
	KtvScreenController::GetController()->Forward(new SongList(allSongQueryString));
}
void HomeWidget::NewestSongClick() const{
	KtvScreenController::GetController()->Forward(new Newest());
}
void HomeWidget::HotOrderClick() const{
	QString hotOrderQueryString = "SELECT a.*,(SELECT COUNT(*) FROM OrderList WHERE a.songId=OrderList.songId) AS BeOrdered  FROM Song AS a ORDER BY a.songPlayCount DESC";
	KtvScreenController::GetController()->Forward(new SongList(hotOrderQueryString));
}
void HomeWidget::PrivateSongClick() const{
	KtvScreenController::GetController()->Forward(new Private());
}
void HomeWidget::PinyinFilterClick() const{
	KtvScreenController::GetController()->Forward(new Pinyin());
}
void HomeWidget::LanguageCategoryFilterClick() const{
	KtvScreenController::GetController()->Forward(new Language());
}
void HomeWidget::DigitalFilterClick() const{
	KtvScreenController::GetController()->Forward(new Digital());
}
void HomeWidget::StarFilterClick() const{
	KtvScreenController::GetController()->Forward(new Star());
}
void HomeWidget::BihuaFilterClick() const{
	KtvScreenController::GetController()->Forward(new Stroke());
}
void HomeWidget::CategoryFilterClick() const{
	KtvScreenController::GetController()->Forward(new Category());
}
