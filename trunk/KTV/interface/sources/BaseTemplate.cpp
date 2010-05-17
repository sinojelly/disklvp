#include "../headers/BaseTemplate.h"
#include "../../Debug.h"
#if 0
#include "../headers/Selected.h"
#include "../headers/Effection.h"
#include "../headers/Atmospheres.h"
#include "../headers/PlayScreen.h"
#include "../KtvScreenController.h"
#endif

BaseTemplate::BaseTemplate()
{
	this->_buttonList = new QList<MyButton*>();
}

BaseTemplate::~BaseTemplate() {
	while(!this->_buttonList->isEmpty()){
		delete this->_buttonList->takeLast();
	}
	delete this->_buttonList;
}

void BaseTemplate::AddButton(InterfaceConfig* p_config, QWidget *parent,int buttonType,QString* p_imageFile){
	const QList<ButtonItemParameter*>* p_lbip = p_config->GetItemsList();
	for(int i=0;i<p_lbip->size();i++){
		ButtonItemParameter* p_bip = p_lbip->at(i);
		MyButton* p_mb;

		QImage* p_image = 0;
		if(p_imageFile){
			p_image = new QImage(*p_imageFile);
			if(p_image->isNull()){
				D::Print("Can not create image :" + (*p_imageFile));
				p_image = 0;
			}
		}

		if(buttonType == 0) p_mb = new MyButton(*p_bip,parent,p_image);
		else p_mb = new StarButton(*p_bip,parent,p_image);

		this->_buttonList->append(p_mb);
	}
}

MyButton* BaseTemplate::FindButton(const QString& name) const{
	MyButton* p_mb = 0;
	for(int i=this->_buttonList->size() - 1; i >= 0; i--){
		if(this->_buttonList->at(i)->Name() == name){
			p_mb = (*(this->_buttonList))[i];
			break;
		}
	}
	return p_mb;
}
int BaseTemplate::ItemTextToInt(const QString& str){
	QRegExp rx("(\\d{1,2})");
	int pos = rx.indexIn(str);
	if(pos > -1)
		return rx.cap(1).toInt();
	else return -1;
}