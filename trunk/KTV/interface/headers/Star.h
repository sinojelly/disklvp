#ifndef STARFILTERSCREEN_H_
#define STARFILTERSCREEN_H_
#include "StarListTemplate.h"
#include "../KtvScreenController.h"
#include "SongList.h"

class Star : public StarListTemplate {
public:
	Star();
	virtual void ActionToDo();
	virtual void ItemClick();
};
#endif /* STARFILTERSCREEN_H_ */
