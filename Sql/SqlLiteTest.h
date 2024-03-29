#ifndef SQLLITETEST_H_
#define SQLLITETEST_H_

#include "SqlForeign.h"
#include "ext/sqlite3.h"
#include "db/serverTable.h"

using  namespace std;
using  namespace appQuick;
using  namespace db;

namespace appQuick {

namespace db {

class SqlLiteTest:public DB_sql
{
public:
	sqlite3 * mdb ;
	CString sdbFile;
	CString sPath;

public:
	SqlLiteTest(const Information* aInf);
	virtual ~SqlLiteTest();
	virtual bool Connect(const Information* aInf);//连接数据库
	virtual bool isTable(); //判断数据表是否存在 
	virtual bool execSql(const CString & aSql);//执行sql语句
	virtual bool querysql(const CString & aSql);//查询sql语句
	virtual void insertsql(const CString & satabname,vector<vector<void  *> > & vaData);//插入语句
	virtual void updatesql(const CString& satabname, vector<vector<void*> >& vaData);//更新语句
	virtual void deletesql(const CString& satabname, const CString& sawheretext);
	virtual void createTablesql(const CString& atabname, vector<vector<void*> >& aData);

public:
	void Sqllitetest();


};


}
}




#endif /* SQLLITETEST_H_ */
