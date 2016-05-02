#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
#include <iostream>
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
string int2str(const int &int_temp)  {  //因为有些IDE不支持itoa方法，自定义的int->string
	stringstream stream;  
	stream<<int_temp;  
	string string_temp;
	stream>>string_temp ;   //此处也可以用 stream>>string_temp  
	return string_temp;
}
std::string to_string (int value);
void process(TreeNode* root,vector<int> vc,vector<string>&  v){
	if (root != NULL && root->left == NULL && root->right == NULL) {
		vc.push_back(root->val);
		string str="";
		str += int2str(vc[0]);
		
		for(unsigned int i=1;i<vc.size();i++){//1  ->3  ->5。。从第2个元素开始让“->”跟着后的数字。
			str += "->";
			str += int2str(vc[i]);

		}
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

	cout<<" strlen和size都是测有效字符，不包括“\0” "<<endl;
	char c[100]={'a','b'};
	cout<<"strlen(字符数组c)="  <<strlen(c)<<endl;//输出2
	// cout<<"c.size()="  <<c.size()<<endl;//报错，无此用法
	
	string str="abc";
	cout<<"字符串str.size()="  <<str.size()<<endl;//输出3
	//cout<<"strlen(str)="  <<strlen(str)<<endl;//报错，无此用法
	system("pause");
}