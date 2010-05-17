#include "../headers/PlayScreen.h"
#include "../../sqlite/DB.h"
#include <QTimer>
#include <QUrl>


PlayScreen::PlayScreen() : Template(){
    _player =
        new Phonon::VideoPlayer(Phonon::VideoCategory, this/*, window, parentWidget*/);
    //_player->play(Phonon::MediaSource(QString::fromLocal8Bit("D:\\Projects\\Google\\disklvp\\������\\2004.mpg"))); //trUtf8
    //player->show();
	_player->move(110, 220);
    _player->resize(800, 500 );

	_timer = new QTimer(this);   //������������ʱ��
	connect(_timer, SIGNAL(timeout()), this, SLOT(CheckPlaying()));
	_timer->start(1000*2); //2s

#if 0
	QList<Phonon::EffectDescription> effectDescriptions =
		Phonon::BackendCapabilities::availableAudioEffects();

	{
		int i=0;
		QMessageBox::information(NULL, "Title", ((Phonon::EffectDescription)effectDescriptions.at(i))., QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}

#endif
}

void PlayScreen::Silent(){
	static bool bSilent = false;
	static float volume;

	if (bSilent)
	{
		_player->setVolume(volume);
		MyButton *p_mb = this->FindButton("Toolsicon/mute");
		if(p_mb) p_mb->SetImage(new QImage(GlobalData::ImagePrefix + p_mb->Name() + ".png"));
		bSilent = false;
		return;
	}

	volume = _player->volume();
	_player->setVolume(0);
	//player->showFullScreen();
	//player->repaint();

	MyButton *p_mb = this->FindButton("Toolsicon/mute");
	if(p_mb) p_mb->SetImage(new QImage(GlobalData::ImagePrefix + p_mb->Name() + "_1.png"));

	bSilent = true;
}

void PlayScreen::CheckPlaying()
{
	if (_player->isPlaying())
	{
		return;
	}	
	NextSong();
}

void PlayScreen::NextSong()
{
	QString sql = QString("select Song.songId,Song.songPath,priority from Song, OrderList where Song.songId==OrderList.songId order by priority desc");
	DB db;
	db.SetQueryText(sql);
	db.GetRecords().clear();
	if(!db.GetRecords().exec()) return; //throw "exec in getsong_page error.";
	//QList<SingerStruct> list;
	while(db.GetRecords().next()){
		//_player->play(Phonon::MediaSource(QString::fromLocal8Bit("D:\\Users\\�赸-������.DAT")));		
		int fieldNo = db.GetRecords().record().indexOf("songPath");
		QString songPath = db.GetRecords().value(fieldNo).toString();//QString::fromLocal8Bit(db.GetRecords().value(fieldNo).toString());

		_player->play(Phonon::MediaSource(QUrl::fromLocalFile(songPath)));//(QString::fromLocal8Bit(songPath)));

		fieldNo = db.GetRecords().record().indexOf("songId");
		int songId = db.GetRecords().value(fieldNo).toInt();
		sql = QString("delete from OrderList where OrderList.songId==:songId"); 
		db.SetQueryText(sql);
		db.BindParameter(":songId",songId);
		db.ExecuteNoQuery();
		return;
	}
}
