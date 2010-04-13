#ifndef MAINSCREEN_H_
#define MAINSCREEN_H_
#include "../../baselib/headers/GlobalData.h"
#include "../headers/BaseTemplate.h"
#include "../KtvScreenController.h"
#include "Newest.h"
#include "Private.h"
#include "Pinyin.h"
#include "Language.h"
#include "Digital.h"
#include "Star.h"
#include "Stroke.h"
#include "Category.h"

class KtvMainScreen : public BaseTemplate {
	Q_OBJECT;
private:
	void _setupSignalConnection();
public:
	KtvMainScreen();
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
};
#endif /* MAINSCREEN_H_ */
