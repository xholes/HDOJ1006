#include <iostream>
#include <iomanip>
using namespace std;
#pragma region settings
//������֡���ʱ����ʱ���ٶȣ�������֡���ʱ����ʱ�
double vsm = 59.0 / 10, vsh = 719.0 / 120, vmh = 11.0 / 120, tsm = 360.0 / vsm, tsh = 360.0 / vsh, tmh = 360.0 / vmh;
//����һ��ʼ�����Ƕ����ڵ�Ŀ�귶Χ��
double b1, b2, b3, e1, e2, e3;
double total, angle, start, ended;
#pragma endregion
double max(double a, double b)
	{ return a > b ? a : b; }//�������������ֵ
double min(double a, double b)//������������Сֵ
{
	return a < b ? a : b;
}

int main()
{
	while (cin >> angle,angle!=-1)
	{
		total = 0; //��ʱ��
		b3 = angle / vmh; // ��ʱ������Ҫ��Ŀ�ʼʱ��
		e3 = (360 - angle) / vmh;// ��ʱ������Ҫ��Ľ���ʱ��
		b1 = angle / vsm;// ����������Ҫ��Ŀ�ʼʱ��
		e1 = (360 - angle) / vsm;	// ����������Ҫ��Ľ���ʱ��
		b2 = angle / vsh;// ��ʱ������Ҫ��Ŀ�ʼʱ��
		e2 = (360 - angle) / vsh;// ��ʱ������Ҫ��Ľ���ʱ��
		while (b3 < 43200)  //��12СʱΪһ�����ڣ�����һ������������������
		{
			while (b1 < e3)  //���ڷ�ʱ������Ҫ�����ǰ������������Ҫ���
			{
				while (b2 < e3&&b2 < e1)
				{
					start = max(max(b1, b2), b3);//��ȡ��ʼʱ��
					ended = min(min(e1, e2), e3);//��ȡ����ʱ��
					total += (ended - start > 0) ? ended - start : 0; //ͳ������Ҫ�����ʱ��
					b2 = b2 + tsh; e2 = e2 + tsh;
				}
				b2 = b2 - tsh; e2 = e2 - tsh;
				b1 = b1 + tsm; e1 = e1 + tsm;
			}
			b1 = b1 - tsm; e1 = e1 - tsm;
			b3 = b3 + tmh; e3 = e3 + tmh;
		}
		cout << fixed<<showpoint<<setprecision(3)<<(total / 432) << endl;
	}
	return 0;
}