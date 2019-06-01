#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main()
{
	long long t;
	scanf("%lld", &t);
	while (t--)
	{
		int h, m;
		scanf("%d:%d", &h, &m);
		if (h == 12 && m != 0) h = 11;
		else
		{
			h = 12 - h;
			if (m != 0) h--;
			if (h == 0) h = 12;
		}
		if (m != 0) m = 60 - m;
		printf("%02d:%02d\n", h, m);
	}
	//system("pause");
	return 0;
}