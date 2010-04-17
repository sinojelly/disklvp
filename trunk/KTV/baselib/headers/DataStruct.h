#ifndef SONGSTRUCT_H_
#define SONGSTRUCT_H_
#include <QString>

class SongStruct{
public:
	QString Name;
	int SongId;
	QString SongPath;
	QString Category;
	int SingerId;
	QString LanguageCategory;
	int PlayCount;
	int OrderId;
	int BeOrdered;
	int Finished;
	int Priority;
public:
	SongStruct(int songId,const QString& name){
		this->Name = name;
		this->SongId = songId;
	}
};
class SingerStruct{
public:
	QString Name;
	QString PicturePath;
	QString FilePath;
	int SingerId;
	SingerStruct(int singerId,const QString& name,const QString& picturePath){
		this->SingerId = singerId;
		this->Name = name;
		this->PicturePath = picturePath;
	}
};
#endif /* SONGSTRUCT_H_ */
