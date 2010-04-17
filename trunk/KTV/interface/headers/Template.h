#ifndef GENERALSCREENTEMPLATE_H_
#define GENERALSCREENTEMPLATE_H_
#include "BaseTemplate.h"
#include "../../baselib/headers/GlobalData.h"
#include <QFont>
#include <QPen>
#include <QList>
#include <QString>

class Template : public BaseTemplate{
	Q_OBJECT;
protected:
	int _currentPage;
	int _totalPages;
private:
	MyButton* _p_currentPageBut;
	MyButton* _p_totalPageBut;
public:
	Template(const QImage* p_image = &GlobalData::TemplateImage2);
	virtual void ShowCurrentPage();
	virtual void ShowTotalPages();
	virtual void NextPage();
	virtual void PreviousPage();
	virtual void InitialPageZone(int currentPage=1,int totalPage=1);
	virtual void DisplayData();
	virtual void SetupSignalConnection(const QList<QString> nameList);
public slots:
	virtual void ActionToDo();
};
#endif /* GENERALSCREENTEMPLATE_H_ */
