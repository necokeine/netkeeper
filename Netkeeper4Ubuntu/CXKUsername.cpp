//////////////////////////////////////////////////////////////////////////
// �ǿ��û������ʵ���ļ�
// ����:Huanfeng
// �汾:1.1
//////////////////////////////////////////////////////////////////////////

#include "CXKUsername.h"
#include "MD5.h"
#include<cstring>

/**CXKUsername::CXKUsername(CString username, INT ver, long lasttimec)*/
CXKUsername::CXKUsername(CString username, INT ver, int lasttimec)
:m_username(username),RADIUS(CString(string("zjxinlisx01"))),LR(CString(string("\r\n")))
{
	m_ver = ver;
	m_lasttimec = lasttimec;
}

long CXKUsername::GetLastTimeC()
{
	return m_lasttimec;
}
CString CXKUsername::Realusername()
{
	time_t m_time;						//�õ�ϵͳʱ�䣬��1970.01.01.00:00:00 ��ʼ������
	/**long m_time1c;*/						//ʱ�������m_time1cΪ���,����ʱ�������ĵ�һ�μ���
	int m_time1c;

	/**long m_time1convert;*/				//��ʱ�������Ľ���Ϊ��ʽ�ִ���ԭʼ���
	int m_time1convert;
	unsigned char ss[4] =
	{
		0,0,0,0
	};		//Դ���1,��m_time1convert���м���õ���ʽ��Դ���
	unsigned char ss2[4] =
	{
		0,0,0,0
	};		//md5���ܲ����һ����,m_time1c���ַ���ʽ
	CString strS1;						//md5���ܲ����һ����,ss2��������ʽ
	CString m_formatsring;				//��m_timece������ַ�,һ��Ϊ�����ַ�
	CString m_md5;						//�Գ�����(m_timec�ַ��ʾ+m_username+radius)��MD5����
	CString m_md5use;					//md5 Lowerģʽ��ǰ��λ



	//ȡ��ϵͳʱ��m_time
	time(&m_time);
	//ʱ�������m_time1cΪ���,����ʱ�������ĵ�һ�μ���
	//�Ӻ���////////////////////////////
	{
		LONG64 t;
		t = m_time;
		t *= 0x66666667;
		t >>= 0x20;
		t >>= 0x01;
		/**m_time1c = (long) t;*/
		m_time1c = (int) t;
	}
	//5���ڶ�̬�û���һ�´���
	if (m_time1c <= m_lasttimec)
	{
		m_time1c = m_lasttimec + 1;
	}
	m_lasttimec = m_time1c;
	{
		/**long t;*/
		int t;
		t = m_time1c;
		ss2[3] = (t & 0xFF);
		ss2[2] = (t & 0xFF00) / 0x100  ;
		ss2[1] = (t & 0xFF0000) / 0x10000;
		ss2[0] = (t & 0xFF000000) / 0x1000000;
		{
			//strS1�������Լӵõ�����Ӽӳ�����
			for (int i = 0; i < 4; i++)
			{
				strS1 += ss2[i];
			}
		}
	}

	/////////////////////////////////////
	//���ù��m_time1convertΪ���
	//�Ӻ���////////////////////////////
	{
		int t, t1, t2, t3;
		t = m_time1c;
		t1 = t;
		t2 = t;
		t3 = t;
		t3 = t3 << 0x10;
		t1 = t1 & 0x0FF00;
		t1 = t1 | t3;
		t3 = t;
		t3 = t3 & 0x0FF0000;
		t2 = t2 >> 0x10;
		t3 = t3 | t2;
		t1 = t1 << 0x08;
		t3 = t3 >> 0x08;
		t1 = t1 | t3;
		m_time1convert = t1;
	}
	/////////////////////////////////////

	//Դ���1,��m_time1convert���м���õ���ʽ��Դ���
	//�Ӻ���////////////////////////////
	{
		/**long t;*/
		int t;
		t = m_time1convert;
		ss[3] = (t & 0xFF);
		ss[2] = (t & 0xFF00) / 0x100  ;
		ss[1] = (t & 0xFF0000) / 0x10000;
		ss[0] = (t & 0xFF000000) / 0x1000000;
	}
	/////////////////////////////////////

	//��ʽ�������
	unsigned char pp[4] =
	{
		0,0,0,0
	};
	//�Ӻ���////////////////////////////
	{
		int i = 0, j = 0, k = 0;
		for (i = 0; i < 0x20; i++)
		{
			j = i / 0x8;
			k = 3 - (i % 0x4);
			pp[k] *= 0x2;
			if (ss[j] % 2 == 1)
			{
				pp[k]++;
			}
			ss[j] /= 2;
		}
	}
	/////////////////////////////////////
	//��ʽ�����,m_formatsringΪ���
	unsigned char pf[6] =
	{
		0,0,0,0,0,0
	};
	//�Ӻ���////////////////////////////
	{
	if(sizeof(int)==2){
		int t1, t2;
		t1 = pp[3];
		t1 /= 0x4;
		pf[0] = t1;
		t1 = pp[3];
		t1 = t1 & 0x3;
		t1 *= 0x10;
		pf[1] = t1;
		t2 = pp[2];
		t2 /= 0x10;
		t2 = t2 | t1;
		pf[1] = t2;
		t1 = pp[2];
		t1 = t1 & 0x0F;
		t1 *= 0x04;
		pf[2] = t1;
		t2 = pp[1];
		t2 /= 0x40;
		t2 = t2 | t1;
		pf[2] = t2;
		t1 = pp[1];
		t1 = t1 & 0x3F;
		pf[3] = t1;
		t2 = pp[0];
		t2 /= 0x04;
		pf[4] = t2;
		t1 = pp[0];
		t1 = t1 & 0x03;
		t1 *= 0x10;
		pf[5] = t1;
		}
	else{
	        short t1,t2 ;
		t1 = pp[3];
		t1 /= 0x4;
		pf[0] = t1;
		t1 = pp[3];
		t1 = t1 & 0x3;
		t1 *= 0x10;
		pf[1] = t1;
		t2 = pp[2];
		t2 /= 0x10;
		t2 = t2 | t1;
		pf[1] = t2;
		t1 = pp[2];
		t1 = t1 & 0x0F;
		t1 *= 0x04;
		pf[2] = t1;
		t2 = pp[1];
		t2 /= 0x40;
		t2 = t2 | t1;
		pf[2] = t2;
		t1 = pp[1];
		t1 = t1 & 0x3F;
		pf[3] = t1;
		t2 = pp[0];
		t2 /= 0x04;
		pf[4] = t2;
		t1 = pp[0];
		t1 = t1 & 0x03;
		t1 *= 0x10;
		pf[5] = t1;
		}
	}
	/////////////////////////////////////
	{
		int i;
		for (i = 0; i < 6; i++)
		{
			pf[i] += 0x20;
			if ((pf[i]) >= 0x40)
			{
				pf[i]++;
			}
		}
	}
	{
		for (int i = 0; i < 6; i++)
		{
			m_formatsring += pf[i];
		}
	}
	/////////////////////////////////////


	CString strInput;
	char temp[100];
	strInput = strS1 + m_username.Left(m_username.FindOneOf("@")) + RADIUS;
	strcpy(temp,strInput.c_str());
	m_md5 = MD5String(temp);
	m_md5use = m_md5.Left(2);
	m_realusername = m_formatsring + m_md5use + m_username;
	m_realusername = LR + m_realusername;//ǰ����λΪ�س�����0D0A,�������Ǻ����

//#define _debug	
#ifdef _debug
cout<<"m_username.FindOneOf(\"@\"):"<<m_username.FindOneOf("@")<<endl;	
cout<<"sizeof(int):"<<sizeof(int)<<",m_formatsring:"<<m_formatsring<<endl<<"temp:"<<temp<<",m_md5:"<<m_md5<<endl<<"m_realusername:"<<m_realusername<<", m_md5use:"<< m_md5use<<endl;
#endif
	return m_realusername;
}


