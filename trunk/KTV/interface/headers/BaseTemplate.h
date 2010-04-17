#ifndef KTV_H
#define KTV_H
#include <QtGui/QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QList>
#include <QPainter>
#include <QPoint>
#include <QImage>
#include <QFont>
#include <QPen>
#include <QRegExp>
#include "../../baselib/headers/MyButton.h"
#include "../../baselib/headers/Config.h"
#include "MainInterface.h"
#include "../KtvScreenController.h"
#include "../../Singleton.h"

class BaseTemplate : public QMainWindow,public MainInterface
{
    Q_OBJECT;
protected:
	QList<MyButton*> *_buttonList;
	const QImage* _p_image;
public:
    BaseTemplate(const QImage* p_image,QWidget *parent = 0);
    virtual ~BaseTemplate();
    MyButton* FindButton(const QString& name) const;
    void AddButton(InterfaceConfig* p_config,int buttonType = 0,QString* p_imageFile = 0);
    static int ItemTextToInt(const QString& str);
protected:
	void paintEvent(QPaintEvent *);
	void mouseDoubleClickEvent(QMouseEvent *);
	void mousePressEvent(QMouseEvent *);
public slots:
	virtual void NextPage();
	virtual void PreviousPage();
	virtual void HomePage();
	virtual void Back();
	virtual void PlayAndPouse();
	virtual void Magic();
	virtual void Silent();
	virtual void OriginalVoice();
	virtual void Atmosphere();
	virtual void Resing();
	virtual void Service();
	virtual void SingWith();
	virtual void Effect();
	virtual void NextSong();
	virtual void VolumeUp();
	virtual void VolumeDown();
	virtual void ViewSelected();
private:
	void _setupSignalConnection();
};

#endif // KTV_H
