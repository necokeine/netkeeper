#include"dail.h"
#include <cstdlib>
#include <windows.h>
#include "ras.h"
#include "raserror.h"

//#define _debug  on
#define _DSL_PATH  "/etc/ppp/peers/dsl-provider" 
 // "/home/zhouchuan/programming/daillinux/dsl-provider"// "/etc/ppp/peers/dsl-provider"
#define _DATA_NAME "Netkeeper.dat"
#define _DSL_DATA  "Netkeeper.pppoe"

int main(int argc, char *argv[])
{
#ifdef _debug 
cout<<"sizeof(long)"<<sizeof(long)<<endl;
cout<<"sizeof(char)"<<sizeof(char)<<endl;
cout<<"sizeof(int)"<<sizeof(int)<<endl;
cout<<"sizeof(short)"<<sizeof(short)<<endl;
cout<<"sizeof(unsigned char)"<<sizeof(unsigned char)<<endl;
cout<<"sizeof(unsigned short int)"<<sizeof(unsigned short int)<<endl;
cout<<"sizeof(unsigned long int)"<<sizeof(unsigned long int)<<endl; 
cout<<"sizeof(long longt)"<<sizeof(long long)<<endl;
#endif
 string sdata;
 string sUsername;
 string sPassword;

 //从数据文件中读取用户名和密码
 fstream fileUN(_DATA_NAME,ios::in);
 if(fileUN.good())
 {
 fileUN>>sUsername;
 fileUN>>sPassword;
 fileUN.close();
 }
 else
 {
 //第一次时输入用户名和密码到数据文件
 fileUN.close();
 fileUN.open(_DATA_NAME,ios::out);
 cout<<"This is you first time to use ,Username:";
 cin>>sUsername;
 fileUN<<sUsername<<endl;
 cout<<"Password:";
 cin>>sPassword;
 fileUN<<sPassword<<endl;
 fileUN.close();
 }

 CXKUsername  user(sUsername);
#ifdef _debug 
 cout<<"You username and password is:"<<endl;
 cout<<sUsername<<endl;
 cout<<sPassword<<endl; 
#endif
 string sRealUsername(user.Realusername());
// cout<<"You dymanic username is:"<<endl;
 cout <<sRealUsername<<endl;
// call
 char line[1000];
 RASDIALPARAMS ras_now;
 HRASCONN handle = NULL;
 ras_now.dwSize=sizeof(ras_now);
 strcpy(ras_now.szEntryName,"test_ras");
 strcpy(ras_now.szUserName, sRealUsername.c_str());
 strcpy(ras_now.szPassword, sPassword.c_str());
 //ras_now.szUserName = username;
 //ras_now.szPassword = password;
 //ras_now.szDomain="*";
 DWORD dwRet;
 for (int i=0;i<10;i++){
		 dwRet=RasDial(NULL,NULL,&ras_now,NULL,NULL,&handle);
		 if (dwRet==0) break;
 }
 if (dwRet==0) cout<<"you win"<<endl;
 else{
		 cout<<"cannian"<<dwRet<<endl;
		 RasHangUp(handle);
		 system("pause"); 
 }
 //将生成后的真实用户名和密码写入文件尾
 fstream fileData(_DSL_DATA,ios::in);
 if(fileData.fail())
 {
// cout<<"open file <"<<_DSL_DATA<<"> error! "<<endl;
// cout<<"Please read Readme.txt!"<<endl;
 fileData.close();
 return EXIT_SUCCESS;
 }
 else
 {

  fstream fileDSL(_DSL_PATH,ios::out);  
 while(!fileData.eof())
 {	
	getline(fileData,sdata); 
 	fileDSL<<sdata<<endl; 	
 } 
 fileDSL<<"user \""<<sRealUsername<<"\""<<endl;
 fileDSL<<"password \""<<sPassword<<"\""<<endl;
 fileDSL<<endl;
 fileData.close();
 fileDSL.close();
 }


 return EXIT_SUCCESS;
}
