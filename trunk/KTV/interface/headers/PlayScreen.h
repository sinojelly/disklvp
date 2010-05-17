#ifndef PLAYSCREEN_H_
#define PLAYSCREEN_H_
#include "../../baselib/headers/GlobalData.h"
#include "../headers/Template.h"
#include <Phonon/VideoPlayer>
#include <QObject>

class PlayScreen : public Template{
	Q_OBJECT;
	DECLARE_SINGLETON(PlayScreen);
public:
	PlayScreen();

private:
	Phonon::VideoPlayer *_player;
	QTimer * _timer;

public:
	//Phonon::VideoPlayer *GetPlayer() { return _player; }
	virtual void Silent();
	virtual void NextSong();

public slots:
	void CheckPlaying();

};
#endif /* MAINSCREEN_H_ */
