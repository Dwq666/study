#include "SqlForeign.h"
using namespace appQuick;
using namespace std;

vector<string> Data_Alg::Data_ins(const CString& satabname, vector<vector<void *> >& vaData)
{
    CStringA lsql;
    vector<string> svec;
//获取表名
	CStringA tabname = satabname.AsAnsi().c_str();

	//获取数组数据
	vector<vector<void *> > lvec = vaData;

	//定义保存字段名称的字符串,初始化"(" 
	string slFieldName="(";
	//定义保存字段值的字符串
	string slValue ;
	for (int i = 0; i < lvec.size(); i++)
	{	
		slValue = "(";
		//获取lvec二维数组的第一行数组
		vector<void *> vlvec = lvec[i];
		for (int j = 0; j < vlvec.size(); j++)
		{	
			//判断i是否为0
			if (i == 0)
			{
			    slFieldName = slFieldName + (char*)vlvec[j] + ",";
			    slValue = "";
			//判断j是否循环到最后一个数
			if (j == vlvec.size() - 1)
			{	
				//去掉字符串的最后一个字符
				slFieldName.pop_back();
			    slFieldName = slFieldName + ")";
			}
			}
			else
			{
				slValue = slValue + "\"" + (char*)vlvec[j]+"\""+ ",";
				//判断j是否循环到最后一个数
				if (j == vlvec.size() - 1)
				{	
					//去掉字符串的最后一个字符
					slValue.pop_back();
				    slValue = slValue+ ")";
				}
			}
		}

		if (i > 0)
		{	
			//拼接sql插入语句
			lsql = CStringA("") + "insert into " + tabname.c_str() + " " + slFieldName.c_str() + " " + "values " + slValue.c_str() + ";";
            svec.push_back(lsql.c_str());
		}

        }

    return svec;

}


vector<string> Data_Alg::Data_upd(const CString& satabname, vector<vector<void *> >& vaData)
{  

    vector<string> svec;
    //获取表名
	CStringA sltabname = satabname.AsAnsi().c_str();

	//获取数组数据
	vector<vector<void*> > lvec = vaData;
	//定义一个存放字段名称的数组
	vector<char *> slFieldName;
	//存放sql语句更换字段值的字符串
	CStringA slsetText;
	//存放sql语句条件的字符串
	CStringA slwhereText;
	for (int i = 0; i < lvec.size(); i++)
	{	
		//初始化
		slwhereText = "";
		slsetText = "";
		vector<void*> vlvec = lvec[i];	
		for (int j = 0; j < vlvec.size(); j++)
		{	
			
			if (i == 0)
			{
				//往数组添加字段名称数据
				slFieldName.push_back((char *)vlvec[j]);
			}
			else
			{	
				CStringA sltext = CStringA("") + "\"" + (char*)vlvec[j] + "\"";
				if (j == 0)
				{	
					//拼接sql条件语句
					slwhereText.Append(slFieldName.at(j));
					slwhereText.Append(" = ");
					slwhereText.Append(sltext.c_str());
				}
				else
				{	
					//拼接sql更换值语句
					slsetText.Append(slFieldName.at(j));
					slsetText.Append(" = ");
					slsetText.Append(sltext.c_str());
					slsetText.Append(" ,");
					if (j == vlvec.size() - 1)
					{	
						string a = slsetText.c_str();
						//去除字符串的最后一个字符
						a.pop_back();
						slsetText = a.c_str();
					}

				}	
			}
		}

		//拼接sql更新语句
        if (i > 0)
        {

		CStringA lsql = CStringA("") + "update " + sltabname.c_str() + " set " + slsetText.c_str() + " where " + slwhereText.c_str();
		svec.push_back(lsql.c_str());
        
        }
	}

    return svec;

}