#include "../headers/Atmospheres.h"
#include <QUrl>
#include <QDir>

Atmospheres::Atmospheres() : SongListTemplate() {
	InterfaceConfig config(GlobalData::ConfigPrefix + "Atmosphere.ini");
	this->AddButton(&config);
	this->SetupSignalConnection(config.GetNameList());
	this->_queryStr = "SELECT a.*,b.orderId,b.priority,b.finished FROM Song AS a,OrderList AS b WHERE a.songId=b.songId ORDER BY b.finished DESC,b.priority DESC,b.orderId ASC";
	this->DisplayData();
	MyButton* p_mb = this->FindButton("Toolsicon/Mood");
	if(p_mb) p_mb->Disabled();
	_music = NULL;
}
void Atmospheres::ActionToDo(){
	//MyButton* p_mb = (MyButton*)this->sender();
	DisplayData();
	MyButton* p_mb = (MyButton*)this->sender();
	QString midPath = "";
	if(p_mb->Name() == "Atmosphere/jvimage1") midPath = QString::fromLocal8Bit("file://"+QDir::currentPath()+"/口哨.wav");
	if(p_mb->Name() == "Atmosphere/jvimage2") midPath = QString::fromLocal8Bit("file://"+QDir::currentPath()+"/口哨.wav");
	if(p_mb->Name() == "Atmosphere/jvimage3") midPath = QString::fromLocal8Bit("file://"+QDir::currentPath()+"/口哨.wav");
	if(p_mb->Name() == "Atmosphere/jvimage4") midPath = QString::fromLocal8Bit("file://"+QDir::currentPath()+"/口哨.wav");

        if (midPath == "")
	{
		return;
	}
	if (_music == NULL)
	{
		_music = Phonon::createPlayer(Phonon::MusicCategory);
	}
	_music->setCurrentSource(Phonon::MediaSource(QUrl::fromLocalFile(midPath)));
	_music->play();
}
void Atmospheres::ItemClick(){
	/* do nothing here */
}

void Atmospheres::Clear()
{
	if (_music != NULL)
	{
		_music->clear();
		delete _music;
		_music = NULL;
	}
}
