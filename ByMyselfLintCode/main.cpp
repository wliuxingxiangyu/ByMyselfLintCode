#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>   
#include <queue> 
using namespace std;

int pow(int x,int y){
	if (y == 0) return 1;

	while(--y){
		x *=10;
	}
	return x;
}
//�ж�1221�Ƿ��ǻ�������myself˼·�ҡ�����λ�����м��ߣ�����lintcodeֱ�Ӳ���ԭ����
bool isPalindromeMy(int x) {//��������
	if (x<10 && x>-10)  return true;//-12321Ϊ����������ȡ����ֵ
	int temp=abs(x),itNum=0;//�������� Ϊ��mod�� ���λ 
	int power=1,high =temp/10,low,shang;
	while (high>10) { high /=10; power++;}

	while (itNum <= (power+1)/2 ){
	    shang=temp/pow(10,itNum);
		low=shang %10;
		cout<<"itNum="<<itNum<<",(power+1)/2="<<(power+1)/2  <<",high="<<high<<",low="<<low<<endl;
		if ( high != low)  return false;
		
		itNum++;
		high=temp%pow(10, power)/pow(10, power-1);
		power--;
	}
	return true;
}
//lintcode�ο�����
bool isPalindrome(int x) {
	if (x < 0) return false;
	int d = 1; // divisor
	while (x / d >= 10) d *= 10; //1234��d=1000.
	while (x > 0) {
		int q = x / d; // quotient
		int r = x % 10; // remainder
		if (q != r) return false;
		x = x % d / 10; //ȥ��x����ǰ���һλ��ģ����ݴΣ��ٳ�10.
		d /= 100;
	}
	return true;
}


int  main(){
	//int i=1234674321;
	int i=123721;
	cout<< "pow(10,2)="<< pow(10,2)<<endl;
	cout<< "isPalindrome(str)="<< isPalindrome(i)<<endl;
	//cout<< "isPalindrome(str)="<< isPalindromeMy(i)<<endl;
	system("pause");
}