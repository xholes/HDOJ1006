#include <iostream>
#include <iomanip>
using namespace std;
#pragma region settings
//设置秒分、秒时、分时差速度，设置秒分、秒时、分时差；
double vsm = 59.0 / 10, vsh = 719.0 / 120, vmh = 11.0 / 120, tsm = 360.0 / vsm, tsh = 360.0 / vsh, tmh = 360.0 / vmh;
//设置一开始，相差角度所在的目标范围；
double b1, b2, b3, e1, e2, e3;
double total, angle, start, ended;
#pragma endregion
double max(double a, double b)
	{ return a > b ? a : b; }//求两个数的最大值
double min(double a, double b)//求两个数的最小值
{
	return a < b ? a : b;
}

int main()
{
	while (cin >> angle,angle!=-1)
	{
		total = 0; //总时间
		b3 = angle / vmh; // 分时针满足要求的开始时间
		e3 = (360 - angle) / vmh;// 分时针满足要求的结束时间
		b1 = angle / vsm;// 分秒针满足要求的开始时间
		e1 = (360 - angle) / vsm;	// 分秒针满足要求的结束时间
		b2 = angle / vsh;// 秒时针满足要求的开始时间
		e2 = (360 - angle) / vsh;// 秒时针满足要求的结束时间
		while (b3 < 43200)  //以12小时为一个周期，至少一个周期能满足条件；
		{
			while (b1 < e3)  //当在分时针满足要求结束前，分秒针满足要求的
			{
				while (b2 < e3&&b2 < e1)
				{
					start = max(max(b1, b2), b3);//求取开始时间
					ended = min(min(e1, e2), e3);//求取结束时间
					total += (ended - start > 0) ? ended - start : 0; //统计满足要求的总时间
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