/*
   by McKelvin
   修改了CXKUsername的Realusername()，注释了开头的LR，换行符由外部添加
   */
#include "CXKUsername.h"
#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char *argv[])
{

	string pppoe_name="0571XXXX@GDPF.XY",
		   pppoe_pass="@@@@@@";

	if(argc<2)
	{
		cerr<<"----\nUsage:"<<argv[0]<<" username password\n----\n\n";
		return 0;
	}

	pppoe_name = argv[1];
	pppoe_pass = argv[2];

	CXKUsername user(pppoe_name);

	//NetworMananger Style
	//以下内容写入/etc/NetworkManager/system-connections 相应DSL拨号配置文件
	cout<<"[pppoe]\n"
		<<"service=GDPF\n"
		<<"username=\\r\\n"<<user.Realusername()<<"\n"//一定要记得加上\\r\\n
		<<"password="<<pppoe_pass<<"\n"
		<<"\n"

		<<"[connection]\n"
		<<"id=NetKeeper\n"
		<<"uuid=63e0076c-fdbc-4cb0-9b07-2516cfc9149d\n"
		<<"type=pppoe\n"
		<<"autoconnect=false\n"
		<<"\n"
		<<"[ppp]\n"
		//<<"refuse-mschap=true\n"
		//<<"mru=1492\n"
		//<<"mtu=1492\n"
		<<"lcp-echo-failure=5\n"
		<<"lcp-echo-interval=30\n"
		<<"\n"

		<<"[802-3-ethernet]\n"
		<<"duplex=full\n"
		<<"\n"

		<<"[ipv4]\n"
		<<"method=auto\n";

		

		

}
