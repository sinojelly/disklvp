#ifndef MAINSCREEN_H_
#define MAINSCREEN_H_
#include "../../baselib/headers/GlobalData.h"
#include "../KtvScreenController.h"
#include "Newest.h"
#include "Private.h"
#include "Pinyin.h"
#include "Language.h"
#include "Digital.h"
#include "Star.h"
#include "Stroke.h"
#include "Category.h"
#include "BaseTemplate.h"
#include <QtGui/QMainWindow>

class KtvMainScreen : public QMainWindow, public BaseTemplate{
	Q_OBJECT;
private:
	void _setupSignalConnection();
public:
	KtvMainScreen(const QImage* p_image = &GlobalData::TemplateImage1,QWidget *parent = 0);
	void display(void);

protected:
	void paintEvent(QPaintEvent *);
	void mouseDoubleClickEvent(QMouseEvent *);
	void mousePressEvent(QMouseEvent *);
private:
	const QImage* _p_image;

public slots:
	void NextPage();
	void PreviousPage();
	void HomePage();
	void Back();
	void PlayAndPouse();
	void Magic();
	void Silent();
	void OriginalVoice();
	void Atmosphere();
	void Resing();
	void Service();
	void SingWith();
	void Effect();
	void NextSong();
	void VolumeUp();
	void VolumeDown();
	void ViewSelected();
};
#endif /* MAINSCREEN_H_ */
