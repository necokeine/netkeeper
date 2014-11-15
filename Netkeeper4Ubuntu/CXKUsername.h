//////////////////////////////////////////////////////////////////////////
// �ǿ��û������ͷ�ļ�
// ����:Huanfeng
// �汾:1.1
//////////////////////////////////////////////////////////////////////////
#ifndef _CXKUsername_H_ 
#define _CXKUsername_H_ 
#include <string>
#include <iostream>
#include <unistd.h>
#include "CString.h"

using namespace std;

typedef int INT;
//typedef string CString ;
typedef long long   LONG64;

class CXKUsername
{
public:
	/**CXKUsername (CString username, INT ver = 18, long lasttimec = 0); */
	CXKUsername (CString username, INT ver = 18, int lasttimec = 0);
	CString Realusername();
	long GetLastTimeC();
private:
	INT m_ver;				//�ǿյİ汾��V12��V18����
	/**long m_lasttimec;*/		//�ϴγɹ���ʱ�䴦��
	int m_lasttimec;

	CString m_username;		//ԭʼ�û���
	CString m_realusername;	//������û���
	CString RADIUS;
	CString LR;
};

#endif // _CXKUsername_H_ 
