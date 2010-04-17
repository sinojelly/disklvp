#include "KtvScreenController.h"

KtvScreenController* KtvScreenController::_p_ktv_ctl = 0;

KtvScreenController::KtvScreenController(){
	this->_p_screens = new QStack<QWidget*> ();
	this->_p_widget = 0;
}
KtvScreenController::~KtvScreenController(){
	//while(!this->_p_screens->isEmpty())
	//	delete this->_p_screens->pop();
	//if(this->_p_widget) delete this->_p_widget;
}

// ��һ��Widget(����)
void KtvScreenController::Forward(QWidget* p_widget){
	if(!this->_p_screens->isEmpty())
		this->_p_screens->top()->hide();
	this->_p_screens->push(p_widget);
	p_widget->show();
}

// �滻_p_screens��top widget(ÿ�����õľ���top widget)
// _p_widget����ǰһ�ε�_p_screens��top widget
void KtvScreenController::Replace(QWidget* p_widget){
	if(!this->_p_screens->isEmpty()){
		this->_p_screens->top()->hide();
		//if(this->_p_widget) delete this->_p_widget;
		this->_p_widget = this->_p_screens->pop();
	}
	this->_p_screens->push(p_widget);
	p_widget->show();
}

// ����ģʽ
KtvScreenController* KtvScreenController::GetController(){
	if(!KtvScreenController::_p_ktv_ctl)
		KtvScreenController::_p_ktv_ctl = new KtvScreenController();
	return KtvScreenController::_p_ktv_ctl;
}

//�˻�ջ����һ��widget
void KtvScreenController::Back(){
	if(this->_p_screens->size() > 1){
		this->_p_screens->top()->hide();
		//if(this->_p_widget){
		//	delete this->_p_widget;
		//}
		this->_p_widget = this->_p_screens->pop();
		this->_p_screens->top()->show();
	}
}

//��ջ��������Ԫ�ؽ���
void KtvScreenController::Toggle(){
	if(this->_p_screens->size() < 2) return;
	QWidget* p_widget1 = this->_p_screens->pop();
	p_widget1->hide();
	QWidget* p_widget2 = this->_p_screens->pop();
	p_widget2->show();
	this->_p_screens->push(p_widget1);
	this->_p_screens->push(p_widget2);
}

//��ʾջ�����һ��Ԫ�أ�����Ԫ��ɾ��
void KtvScreenController::Home(){
	if(this->_p_screens->size() < 2) return;
	while(this->_p_screens->size() > 1){
		//if(this->_p_widget){
		//	delete this->_p_widget;
		//}
		this->_p_widget = this->_p_screens->pop();
		this->_p_widget->hide();
	}
	this->_p_screens->top()->show();
}
