#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
}

void process(TreeNode* root,string str,vector<string>&  v){
	if (root == NULL) {
		v.push_back(str);
		return ; 
	}
	char* strTemp=str;
	char c[1];
	itoa(root->val,c,10);
	strcat(str,c);
	if(root->left != NULL){
		process(root->left,str,v);
	}
	if(root->right != NULL){
		process(root->right,str,v);
	}
	//从str中删除字符c
	int len = strlen(str); // 获取str的字符串长度
	str[len - 1]= '\0'; // 用'\0'覆盖最后一个有效字符
}

vector<string> binaryTreePaths(TreeNode* root) {
	if (root == NULL) return;
	vector<string>  v;
	string str;
	process(root,str,v);
	return v;
}

int  main(){
	system("pause");
}