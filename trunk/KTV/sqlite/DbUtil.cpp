#include "DbUtil.h"
#include <stdio.h>

QList<SongStruct> DbUtil::GetSong_Page(const QString& sql,int page,QList<QVariant> param,PageInfo* pageInfo,int pageSize){
	DB db;
	db.SetQueryText(sql);
	for(int i=0;i<param.size();i++){
		db.BindParameter(i,param.at(i));
	}
	QString querystr = db.GetRecords().lastQuery();

	QString countstr = QString("SELECT COUNT(*) FROM ( ")+ querystr + QString(") AS countTable");
	db.SetQueryText(countstr);
	pageInfo->RecordCount = db.ExecuteScalar().toInt();
	pageInfo->PageSize = pageSize;
	pageInfo->CurrentPage = page;
	pageInfo->Caculate();

	db.GetRecords().clear();
	querystr = querystr + " LIMIT " + QString::number(pageInfo->GetValidStartIndex()) + "," + QString::number(pageSize);
	db.SetQueryText(querystr);
	if(!db.GetRecords().exec()) throw "exec in getsong_page error.";
	QList<SongStruct> list;
	while(db.GetRecords().next()){
		int fieldNo = db.GetRecords().record().indexOf("songId");
		int songId = db.GetRecords().value(fieldNo).toInt();
		fieldNo = db.GetRecords().record().indexOf("songName");
		QString songName = db.GetRecords().value(fieldNo).toString();
		SongStruct sstruct(songId,songName);
		fieldNo = db.GetRecords().record().indexOf("OrderId");
		if(fieldNo != -1){
			sstruct.OrderId = db.GetRecords().value(fieldNo).toInt();
		}

		fieldNo = db.GetRecords().record().indexOf("BeOrdered");
		if(fieldNo != -1){
			sstruct.BeOrdered = db.GetRecords().value(fieldNo).toInt();
		}
		else sstruct.BeOrdered = 0;

		fieldNo = db.GetRecords().record().indexOf("Finished");
		if(fieldNo != -1){
			sstruct.Finished = db.GetRecords().value(fieldNo).toInt();
		}
		else sstruct.Finished = 0;

		fieldNo = db.GetRecords().record().indexOf("Priority");
		if(fieldNo != -1){
			sstruct.Priority = db.GetRecords().value(fieldNo).toInt();
		}
		else sstruct.Priority = 0;

		list.append(sstruct);
	}
	return list;
}
QList<SingerStruct> DbUtil::GetSinger_Page(const QString& sql,int page,QList<QVariant> param,PageInfo* pageInfo,int pageSize){
	DB db;
	db.SetQueryText(sql);
	for(int i=0;i<param.size();i++){
		db.BindParameter(i,param.at(i));
	}
	QString querystr = db.GetRecords().lastQuery();

	QString countstr = QString("SELECT COUNT(*) FROM ( ")+ querystr + QString(") AS countTable");
	db.SetQueryText(countstr);
	pageInfo->RecordCount = db.ExecuteScalar().toInt();
	pageInfo->PageSize = pageSize;
	pageInfo->CurrentPage = page;
	pageInfo->Caculate();

	db.GetRecords().clear();
	querystr = querystr + " LIMIT " + QString::number(pageInfo->GetValidStartIndex()) + "," + QString::number(pageSize);
	db.SetQueryText(querystr);
	if(!db.GetRecords().exec()) throw "exec in getsong_page error.";
	QList<SingerStruct> list;
	while(db.GetRecords().next()){
		int fieldNo = db.GetRecords().record().indexOf("singerId");
		int singerId = db.GetRecords().value(fieldNo).toInt();
		fieldNo = db.GetRecords().record().indexOf("singerName");
		QString singerName = db.GetRecords().value(fieldNo).toString();
		fieldNo = db.GetRecords().record().indexOf("singerPic");
		QString singerPic = GlobalData::SingerPicturePrefix + db.GetRecords().value(fieldNo).toString();
		list.append(SingerStruct(singerId,singerName,singerPic));
	}
	return list;
}

void DbUtil::AddSongToOrderList(const SongStruct& song){
	DB db;
	db.SetQueryText("INSERT INTO orderList(songId) VALUES (:songId)");
	db.BindParameter(":songId",song.SongId);
	db.ExecuteNoQuery();
}
void DbUtil::UpdateSongLibrary(){
	DB db;
	db.SetQueryText(QObject::trUtf8("DELETE FROM OrderList"));
	db.ExecuteNoQuery();
	db.SetQueryText(QObject::trUtf8("SELECT songName FROM Song WHERE pinyin IS NULL AND songLanguage!='英文歌曲'"));
	if(!db.GetRecords().exec()) throw "exec in UpdateSongLibrary error.";
	QList<QString> list;
	while(db.GetRecords().next()){
		list.append( db.GetRecords().value(0).toString());
	}
	for(int i=0;i<list.size();i++){
		QString str = list[i];
		QString pinyin = "";
		for(int j=0;j<str.length();j++){
			QChar word = str[j];
			db.SetQueryText("SELECT pinyin FROM Dic WHERE word=:word");
			db.BindParameter(":word",word);
			if(!db.GetRecords().exec()) throw "exec in UpdateSongLibrary error.";
			if(db.GetRecords().next()){
				pinyin += db.GetRecords().value(0).toString();
			}
		}
		if(pinyin.length() == 0) continue;
		db.SetQueryText("UPDATE Song SET pinyin=:pinyin WHERE songName=:songName");
		db.BindParameter(":pinyin",pinyin);
		db.BindParameter(":songName",str);
		db.ExecuteNoQuery();
	}
}

int DbUtil::RegisterUser(QString uid,QString pwd){
	DB db;
	db.SetQueryText("INSERT INTO User(account,pwd) VALUES(:account,:pwd)");
	db.BindParameter(":account",uid);
	db.BindParameter(":pwd",pwd);
	return db.ExecuteNoQuery();
}

int DbUtil::Login(QString uid,QString pwd){
	DB db;
	db.SetQueryText("SELECT userId FROM User WHERE account=:account AND pwd=:pwd");
	db.BindParameter(":account",uid);
	db.BindParameter(":pwd",pwd);
	if(!db.GetRecords().exec()) throw "exec in Login error.";
	if(db.GetRecords().next()){
		bool ok = false;
		int userId = db.GetRecords().value(0).toInt(&ok);
		if(ok) return userId;
		else return 0;
	}
	else return 0;
}
int DbUtil::SetPriority(int orderId){
	DB db;
	db.SetQueryText("UPDATE OrderList SET priority=1 WHERE orderId=:orderId");
	db.BindParameter(":orderId",orderId);
	return db.ExecuteNoQuery();
}
int DbUtil::DeleteSongFromOrderList(int orderId){
	DB db;
	db.SetQueryText("DELETE FROM OrderList WHERE orderId=:orderId");
	db.BindParameter(":orderId",orderId);
	return db.ExecuteNoQuery();
}
