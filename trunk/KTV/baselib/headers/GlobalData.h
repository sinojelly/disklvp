#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_
#include <QString>
#include <QColor>
#include <QImage>
#include <QObject>

class GlobalData{
public:
	static QString ImagePrefix;
	static QString SingerPicturePrefix;
	static QString ConfigPrefix;

	static QImage TemplateImage1;
	static QImage TemplateImage2;
	static QImage TemplateImage3;

	static int CurrentUserId;

	static QString Font;
	/*****************
	 * for song list template item text
	 */
	static QColor SongItemTextColor;
	static int SongItemTextSize;
	static int SongItemTextPosition_X;
	static int SongItemTextPosition_Y;
	/*******************
	 * for star list template item text
	 */
	static QColor SingerItemTextColor;
	static int SingerItemTextSize;
	static int SingerItemTextPosition_X;
	static int SingerItemTextPosition_Y;
	static int SingerItemPicturePosition_X;
	static int SingerItemPicturePosition_Y;
	/*****************
	 * for page number
	 */
	static QColor PageNumberColor;
	static int PageNumberSize;
	static int PageNumberLeftPosition_X;
	static int PageNumberLeftPosition_Y;
	static int PageNumberRightPosition_X;
	static int PageNumberRightPosition_Y;
};

#endif /* GLOBALDATA_H_ */
