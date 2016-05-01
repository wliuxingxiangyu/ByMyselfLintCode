#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream> 
#include <stack> 
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
//string int2String(int a){
//	stack<int> s;
//	while (a){ 
//		s.push(a%10);
//		a=a/10;
//	}
//    char str[ s.size() ];
//	while (s.size() ){ 
//		cout<< 
//		str[]= s.top();
//		s.pop();
//	}
//	return str;
//}
string int2str(const int &int_temp)  {  
	stringstream stream;  
	stream<<int_temp;  
	string string_temp;
	stream>>string_temp ;   //此处也可以用 stream>>string_temp  
	return string_temp;
}
void process(TreeNode* root,vector<int> vc,vector<string>&  v){
	if (root != NULL && root->left == NULL && root->right == NULL) {
		vc.push_back(root->val);
		string str="";
		vector<int>::iterator it;
		for (it=vc.begin();it!=vc.end();it++){ 
			str += int2str(*it);
			// str +=itoa((*it),strTemp,10);//itoa函数int-->string有些IDE不识别。	
			str += "->";
		}
		int len=str.size();
		str [len-2]='\0';
		cout<<str<<endl;
		v.push_back(str);
		return ; 
	}

	vc.push_back(root->val );//int 10+48_'0'=58_':'

	if(root->left != NULL){
		process(root->left,vc ,v);
	}

	if(root->right != NULL){
		process(root->right,vc,v);
	}

	//从vc中删除尾字符，往上回溯。进入下一个分支。
	vc.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string>  v;
	if (root == NULL) return v;
	vector<int> vc;
	process(root,vc,v);
	return v;
}

int  main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);

	root->left->left=NULL;
	root->left->right=new TreeNode(5);

	binaryTreePaths(root);
	system("pause");
}