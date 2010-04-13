#ifndef PLAYSCREEN_H_
#define PLAYSCREEN_H_
#include "../../baselib/headers/GlobalData.h"
#include "../headers/BaseTemplate.h"
#include <Phonon>
#include <QObject>

class PlayScreen : public BaseTemplate {
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
