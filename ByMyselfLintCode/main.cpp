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

bool isCharOrNumber(char c){
	if ( (c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z') ){ 
		return true;
	} else{
		return false;
	}
}

bool isPalindromeMy(string& s) {
	int len=s.size();
	if( len == 0) return true;
	int i=0,j=len-1;
	char c1,c2;
	while(i<j){
		while(i<len && ! isCharOrNumber(s[i]) ) i++;
		if(i==len) return true; //全是非字符，返回true.

		if(s[i]>='A' && s[i]<='Z'  ) c1=s[i]+32;
		else c1=s[i];

		while(j>0 && ! isCharOrNumber(s[j]) )  j--;

		if(s[j]>='A' && s[j]<='Z'  ) c2=s[j]+32;
		else c2=s[j];

		if(c1 != c2) return false;
		i++;j--;
	}
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return true;

}

//lintcode参考代码
bool isPalindrome(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string ::iterator left,right;
	left = s.begin(), right = prev(s.end());
	while (left < right) {
		if (!::isalnum(*left)) ++left;
		else if (!::isalnum(*right)) --right;
		else if (*left != *right) return false;
		else{ left++, right--; }
	}
	return true;
}


int  main(){
	string str=".,";
	//string str="A man, a plan, a canal: Panama";
	cout<< "isPalindrome(str)="<< isPalindrome(str)<<endl;

	system("pause");
}