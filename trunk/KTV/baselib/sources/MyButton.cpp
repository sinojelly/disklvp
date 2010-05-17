#include "../headers/MyButton.h"

MyButton::MyButton(const QString& name,QImage* p_image,int x,int y,QWidget *parent) : QWidget(parent,Qt::FramelessWindowHint){
	this->setCursor(Qt::PointingHandCursor);
	this->_name = name;
	this->_p_image = p_image;
	this->setGeometry(x,y,this->_p_image->width(),this->_p_image->height());
	this->_initial();
}

MyButton::MyButton(const ButtonItemParameter& param,QWidget *parent,QImage* p_image) : QWidget(parent,Qt::FramelessWindowHint){
	this->setCursor(Qt::PointingHandCursor);
	this->_name = param.Name();
	if(p_image)	this->_p_image = p_image;
	else this->_p_image = param.GetImage();
	this->setGeometry(param.Left(),param.Top(),this->_p_image->width(),this->_p_image->height());
	this->_initial();

	// add by jelly
	this->_x = param.Left();
	this->_y = param.Top();
}

MyButton::~MyButton(){
	delete this->_p_image;
	if(this->_p_font) delete this->_p_font;
	if(this->_p_pen) delete this->_p_pen;
}

void MyButton::_initial(){
	this->_p_font = 0;
	this->_p_pen = 0;
	this->_x = 0;
	this->_y = 0;
	this->_enabled = true;
}
QString MyButton::Name() const{
	return this->_name;
}
void MyButton::SetImage(QImage* p_image){
	if(this->_p_image) delete this->_p_image;
	this->_p_image = p_image;
	this->setGeometry(this->_x,this->_y,this->_p_image->width(),this->_p_image->height());
	//this->repaint();
	this->update();
}
const QImage* MyButton::Image() const{
	return this->_p_image;
}

void MyButton::paintEvent(QPaintEvent *enent){
	QPainter painter;
	if(this->_p_image->isNull()){
		return;
	}
	painter.begin(this);
	painter.drawImage(QPoint(0,0),*this->_p_image);
	if(!this->_text.isEmpty()){
		if(this->_p_font)	painter.setFont(*this->_p_font);
		if(this->_p_pen)	painter.setPen(*this->_p_pen);
		painter.drawText(this->_x,this->_y,this->_text);
	}
	painter.end();
}
void MyButton::mousePressEvent(QMouseEvent *event){
	if(!this->IsEnabled()) return;
	emit click();
}

void MyButton::SetFont(QFont* p_font){
	if(this->_p_font) delete this->_p_font;
	this->_p_font = p_font;
}
void MyButton::SetPen(QPen* p_pen){
	if(this->_p_pen) delete this->_p_pen;
	this->_p_pen = p_pen;
}
void MyButton::SetText(const QString& text){
	this->_text = text;//trUtf8(text);
	//this->repaint();
	this->update();
}
void   MyButton::SetTextPoint(int x,int y){
	this->_x = x;
	this->_y = y;
}
bool MyButton::IsEnabled(){
	return this->_enabled;
}
void MyButton::Enabled(){
	this->_enabled = true;
	this->setCursor(Qt::PointingHandCursor);
}
void MyButton::Disabled(){
	this->_enabled = false;
	this->setCursor(Qt::ArrowCursor);
}
/************************************************************/

StarButton::StarButton(const QString& name,QImage* p_image,int x,int y,QWidget *parent)
	: MyButton(name,p_image,x,y,parent)
{
	this->_p_imageStar = 0;
	this->_pic_x = 2;
	this->_pic_y = 2;
}

StarButton::StarButton(const ButtonItemParameter& param,QWidget* parent,QImage* p_image)
	: MyButton(param,parent,p_image)
{
	this->_p_imageStar = 0;
	this->_pic_x = 2;
	this->_pic_y = 2;
}
void StarButton::SetImage(const QString& file,int x,int y){
	if(this->_p_imageStar) delete this->_p_imageStar;
	this->_p_imageStar = new QImage(file);
	this->_pic_x = x;
	this->_pic_y = y;
	//this->repaint();
	this->update();
}
StarButton::~StarButton(){
	if(this->_p_imageStar) delete this->_p_imageStar;
}
void StarButton::paintEvent(QPaintEvent* event){
	MyButton::paintEvent(event);

	QPainter painter;
	if(!this->_p_imageStar || this->_p_imageStar->isNull()){
		return;
	}
	painter.begin(this);
	painter.drawImage(QPoint(this->_pic_x,this->_pic_y),*this->_p_imageStar);
	painter.end();
}
