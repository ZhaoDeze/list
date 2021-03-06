/*
描述
本题练习对哈夫曼编码进行译码。

输入
第1行一个正整数n, 表示字符数。
接着n行，每行第一个是字符的ASCII码值，第2个是该字符的哈夫曼编码，编码和字符之间用一个空格分割。
最后一行是一串文本的哈夫曼编码
输出
译码后的文本

注：字符均为英文字符,可以是空格，字符数n<100,译码后的文本总长度<1000。
样例输入1
23
32 111
46 010011
73 0111110
83 011110
97 1000
98 11010
99 10011
100 10110
101 0010
102 01000
104 01110
105 11011
108 1010
109 0111111
110 10010
111 000
114 0110
115 0101
116 11001
117 11000
118 010010
119 0011
121 10111
01111001110000001111110111000110000110111010001010000001110011011101000011011001010111110001001010110111100110001001010011001010001010111101110001100001101111100110001101010100010010111110001001010110111011111011100111101110101010111110100010111011111110111010111001110110100011011001010110010011111011110011100000011111101110001100001101111100110001101010100010010111110001001010110111101110001100001101110100010100000011100110111010000110110010101111001111011101010101111101000101110001101001001011011000110000101010011
样例输出1
Show your flowcharts and conceal your tables and I will be mystified. Show your tables and your flowcharts will be obvious.
样例输入2
5
65 10
66 11
67 010
68 011
69 00
1110111001010010100111001110111101011101100110001101110110000001111
样例输出2
BABACACADADABBCBABEBEDDABEEEBB
*/
#include<iostream>
#include<cstring>
#define MAX 1000
using namespace std;
typedef struct Code{
	int c_ASCII;
	char *str;
}*Cd;
void input(Cd &cd,int n)
{
	cd = new Code[n + 1];
	int i = 1;
	while (i <= n)
	{
		cin >> cd[i].c_ASCII;
		cd[i].str = new char[10];
		cin >> cd[i].str;
		i++;
	}
}
void Decoding(Cd &cd, int n,char s[])
{
	char *p = s;
	char s1[10];
	int i = 0, k;
	while (*p!='\0')
	{
		s1[i++] = *p;
		s1[i] = '\0';
		for (int k = 1; k <= n; k++)
		{
			if (strcmp(s1, cd[k].str) == 0)
			{
				cout << char(cd[k].c_ASCII);
				memset(s1, '\0', sizeof(s1));
				i = 0;
				break;
			}
		}
		p++;
	}
}
int main()
{
	int n;
	cin >> n;
	Cd cd;
	input(cd, n);
	char str1[MAX];
	cin >> str1;
	Decoding(cd, n, str1);
	return 0;
}
