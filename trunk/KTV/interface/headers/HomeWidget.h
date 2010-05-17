#ifndef HOME_WIDGET_H
#define HOME_WIDGET_H

#include "Template.h"
#include <QWidget>


class HomeWidget : public Template
{
	Q_OBJECT;
private:
	void _setupSignalConnection();
public:
	HomeWidget();
public slots:
	void AllSongClick() const;
	void NewestSongClick() const;
	void HotOrderClick() const;
	void PrivateSongClick() const;
	void PinyinFilterClick() const;
	void LanguageCategoryFilterClick() const;
	void DigitalFilterClick() const;
	void StarFilterClick() const;
	void BihuaFilterClick() const;
	void CategoryFilterClick() const;

private:
	QWidget *mainScreen;
};

#endif
