#ifndef MYBUTTON_H_
#define MYBUTTON_H_
#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QMessageBox>
#include <QFont>
#include <QPen>
#include "GlobalData.h"
#include "Config.h"

class MyButton : public QWidget{
	Q_OBJECT;
protected:
	QImage *_p_image;
	QString _name;
	QFont* _p_font;
	QPen* _p_pen;
	QString _text;
	int _x;
	int _y;
	bool _enabled;
private:
	void _initial();
public:
	MyButton(const QString& name,QImage* p_image,int x,int y,QWidget *parent = 0);
	MyButton(const ButtonItemParameter& param,QWidget *parent = 0,QImage* p_image = 0);
	QString Name() const;
	const QImage* Image() const;
	virtual ~MyButton();
	void DrawText();
	void SetFont(QFont* p_font);
	void SetPen(QPen* p_pen);
	void SetText(const QString& text);
	void SetTextPoint(int x,int y);
	bool IsEnabled();
	void Enabled();
	void Disabled();
	void SetImage(QImage* p_image);
protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
signals:
	void click();
};

class StarButton : public MyButton{
protected:
	QImage* _p_imageStar;
	int _pic_x;
	int _pic_y;
public:
	StarButton(const QString& name,QImage* p_image,int x,int y,QWidget *parent = 0);
	StarButton(const ButtonItemParameter& param,QWidget *parent = 0,QImage* p_image = 0);
	void SetImage(const QString& file,int x,int y);
	virtual ~StarButton();
protected:
	virtual void paintEvent(QPaintEvent* event);
};
#endif /* MYBUTTON_H_ */
