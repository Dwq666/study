/*==========================================================
*
*  APPQuick 原生跨平台开发框架
*
*  A low-code native cross-platform development framework encapsulating 
*   most operating system underlying APIs and Kia graphics engines
*
*  一套封装了大多数操作系统底层API和Skia图形引擎的低代码原生跨平台开发框架
*
*  ThirdPartyLibTest.cpp
*
*  Created on: 2022年7月14日
*  Author: Daly
*  
*  版权所有:深圳市微方创业科技有限公司  
*  CopyRight:Microsquare Innovative Technology co. 
*  
*  The Creative Commons  License (CC) 
*  
*  Permission is hereby granted ,to any person obtaining a
*  copy of this software and associated documentation files
*  to can be use, copy, modify, merge, publish, distribute,
*  but not for commercial purposes.
*  
*  本框架即时授予CC License ,可以被修改，分发，复制，但不能用于商业用途
*  
*  
*==========================================================
*/
#include "Core/aqCore.h"
#include "ext/TinyXML.h"
#include "ext/json/json.h"
using namespace appQuick;

void ShowDom(TiXmlElement * aEle)
{
	TiXmlNode * lEleNode = aEle->FirstChild();
	while(lEleNode!=NULL)
	{
		TiXmlElement * lElement = AQCast(TiXmlElement,lEleNode);
		LOGI("%s",lElement->Attribute("p"));
		ShowDom(lElement);
		lEleNode = lElement->NextSibling();
	}

}



void xmlTest()
{
	int iSize=0;
	BYTE* lData = FileUtil::LoadDataFromFile("E:/Test.xml", iSize);
	CStringA lText(lData,iSize);
	TiXmlDocument * document = new TiXmlDocument();
	document->Parse(lText.c_str());
	TiXmlElement * lRoot = document->RootElement();
	LOGI("%s",lRoot->Attribute("p"));
	ShowDom(lRoot);
}

void jsonTest()
{
	Json::Reader reader;
	Json::Value root;

	int aSize=0;
	BYTE * lData = FileUtil::LoadDataFromFile("E:/jsonTest.json", aSize);
	CStringA lStr(lData,aSize);
	 if (reader.parse(lStr.c_str(), root))
	 {
	  int lSize=root.size();
	  for (int i=0;i<lSize;i++)
	  {
	   Json::Value lNode = root[i];
	   LOGI("name:%s    age:%d ",lNode["name"].asString().c_str(),lNode["age"].asInt());
	  }
	 }

}



void ThirdPartyLibTest()
{
	CStringA lstr;
	lstr.Append("<a pp=1 >  \r\n" );
	lstr.Append("\t  <b pp=2 /> \r\n");
	lstr.Append("\t <b pp=3 /> \r\n");
	lstr.Append("\t <b pp=4 /> \r\n");
	lstr.Append("\t <b pp=5 /> \r\n");
	lstr.Append("</a>");

	//FileUtil::SaveDataToFile("E:/aaa.xml",(BYTE *)lstr.c_str(),lstr.Len());

	//jsonTest();
	xmlTest();

}

