#include "../headers/Register.h"
#include "../headers/Private.h"

Register::Register(QString type) : SongListTemplate() {
	this->_type = type;

	InterfaceConfig config(GlobalData::ConfigPrefix + "Register.ini");
	this->AddButton(&config);

	this->SetupSignalConnection(config.GetNameList());

	MyButton* p_mb = this->FindButton("Register/account");
	if(p_mb) p_mb->Disabled();
	p_mb = this->FindButton("Register/pwd");
	if(p_mb) p_mb->Disabled();

	/*******************************************************/
	p_mb = this->FindButton("Register/show1");
	QFont* p_font = new QFont(GlobalData::Font,24, QFont::Normal);
	QPen* p_pen = new QPen();
	p_pen->setStyle(Qt::SolidLine);
	p_pen->setWidth(2);
	p_pen->setBrush(GlobalData::SongItemTextColor);
	p_mb->SetFont(p_font);
	p_mb->SetPen(p_pen);
	p_mb->SetTextPoint(25,27);

	p_mb = this->FindButton("Register/show2");
	p_font = new QFont(GlobalData::Font,24, QFont::Normal);
	p_pen = new QPen();
	p_pen->setStyle(Qt::SolidLine);
	p_pen->setWidth(2);
	p_pen->setBrush(GlobalData::SongItemTextColor);
	p_mb->SetFont(p_font);
	p_mb->SetPen(p_pen);
	p_mb->SetTextPoint(25,27);
	/**************************************************************/


	this->_txt1 = "";
	this->_txt2 = "";
	this->_currentItem = 1;

	this->_queryStr = "SELECT a.* FROM Song AS a,OrderList AS b WHERE a.songId=b.songId ORDER BY b.orderId DESC";
	this->DisplayData();
}
void Register::ActionToDo(){
	MyButton* p_mb = (MyButton*)this->sender();
	QString name = p_mb->Name();
	if(name == "Register/confirm"){
		if(!this->_txt1.isEmpty() && !this->_txt2.isEmpty()){
			if(this->_type == "register"){
				if(DbUtil::RegisterUser(this->_txt1,this->_txt2)){
					this->_txt1 = "";
					this->_txt2 = "";
					this->_type = "login";
				}
			}
			else if(this->_type == "login"){
				int userId = DbUtil::Login(this->_txt1,this->_txt2);
				if(userId){
					GlobalData::CurrentUserId = userId;
					KtvScreenController::GetController()->Forward(new Private());
				}
			}
		}
		return;
	}
	else if(name == "Register/del"){
		if(this->_currentItem == 1) this->_txt1 = this->_txt1.left(this->_txt1.length() - 1);
		else if(this->_currentItem == 2) this->_txt2 = this->_txt2.left(this->_txt2.length() - 1);
	}
	else if(name == "Register/show1"){
		this->_currentItem = 1;
	}
	else if(name == "Register/show2"){
		this->_currentItem = 2;
	}
	else{
		if(this->_currentItem == 1) this->_txt1 += name.right(1);
		else if(this->_currentItem == 2) this->_txt2 += name.right(1);
	}

	p_mb = this->FindButton("Register/show1");
	p_mb->SetText(this->_txt1);

	p_mb = this->FindButton("Register/show2");
	p_mb->SetText(this->_txt2);
}
