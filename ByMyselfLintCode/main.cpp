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
//判断1221是否是回文数？myself思路乱。两个位数往中间走，不如lintcode直接操作原数。
bool isPalindromeMy(int x) {//代码有误
	if (x<10 && x>-10)  return true;//-12321为回文数，先取绝对值
	int temp=abs(x),itNum=0;//迭代次数 为了mod出 最低位 
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
//lintcode参考代码
bool isPalindrome(int x) {
	if (x < 0) return false;
	int d = 1; // divisor
	while (x / d >= 10) d *= 10; //1234的d=1000.
	while (x > 0) {
		int q = x / d; // quotient
		int r = x % 10; // remainder
		if (q != r) return false;
		x = x % d / 10; //去除x的最前最后一位。模最高幂次，再除10.
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