#ifndef DB_H_
#define DB_H_
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlRecord>

class DB{
protected:
	QString _dbName;
	QString _driverName;
	QSqlDatabase _db;
	QSqlQuery _query;
public:
	DB();
	void SetQueryText(const QString& queryString);
	void BindParameter(const QString& placeholder,const QVariant& val, QSql::ParamType paramType = QSql::In);
	void BindParameter(int pos,const QVariant& val,QSql::ParamType paramType = QSql::In);
	int ExecuteNoQuery();
	QVariant LastInsertId()const;
	QSqlQuery GetRecords() const;
	QVariant ExecuteScalar();
	bool Open();
};
#endif /* DB_H_ */
