#include "../headers/PlayScreen.h"
#include "../../sqlite/DB.h"
#include <QTimer>
#include <QUrl>

PlayScreen::PlayScreen() : BaseTemplate(&GlobalData::TemplateImage1){
    _player =
        new Phonon::VideoPlayer(Phonon::VideoCategory, this/*, window, parentWidget*/);
    //_player->play(Phonon::MediaSource(QString::fromLocal8Bit("D:\\Projects\\Google\\disklvp\\陈卫民\\2004.mpg"))); //trUtf8
    //player->show();
	_player->move(110, 220);
    _player->resize(800, 500 );

	_timer = new QTimer(this);   //创建并启动定时器
	connect(_timer, SIGNAL(timeout()), this, SLOT(CheckPlaying()));   //每当定时器超时时调用函数CheckPlaying
	_timer->start(1000*2); //2s
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
		//_player->play(Phonon::MediaSource(QString::fromLocal8Bit("D:\\Users\\舞蹈-花仙子.DAT")));		
		int fieldNo = db.GetRecords().record().indexOf("songPath");
		QString songPath = db.GetRecords().value(fieldNo).toString();//QString::fromLocal8Bit(db.GetRecords().value(fieldNo).toString());

		_player->play(Phonon::MediaSource(QUrl::fromLocalFile(songPath)));//(QString::fromLocal8Bit(songPath)));

		// 删除orderlist已播放歌曲
		fieldNo = db.GetRecords().record().indexOf("songId");
		int songId = db.GetRecords().value(fieldNo).toInt();
		sql = QString("delete from OrderList where OrderList.songId==:songId"); // 不能直接加QString(songId)，后面根本没加上去		
		db.SetQueryText(sql);
		db.BindParameter(":songId",songId);
		db.ExecuteNoQuery();
		return;
	}
}
