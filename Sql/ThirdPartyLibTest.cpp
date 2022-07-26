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

