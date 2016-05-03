#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
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

void process(TreeNode *root, int target,vector<vector<int>>&  resvv,vector<int>& v,int sum){
	if(root == NULL) return;
	if(root->left == NULL && root->right == NULL ){//叶子结点
		if(sum+ root->val == target){ //找到了，加入resvv
			v.push_back(root->val);
			resvv.push_back(v);
			v.pop_back();
		}
		return;//到了叶子就要返回
	}
	v.push_back(root->val);
	sum += root->val;
	process(root->left, target,resvv,v,sum);
	process(root->right, target,resvv,v,sum);
	if(v.size() != 0)  v.pop_back();//返回时要弹出 最后的元素，不管是否找到。

}

vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
	vector<vector<int>>  resvv;
	if(root == NULL) return resvv;

	vector<int> v;
	int sum=0;
	process(root,target,resvv,v,sum);

	return resvv;
}

int  main(){
	TreeNode* root=new TreeNode(1);//test1
	root->left=new TreeNode(2);
	root->left->left=new TreeNode(3);

	TreeNode* root2=new TreeNode(1);//test2
	root2->left=new TreeNode(2);
	root2->right=new TreeNode(4);

	root2->left->left=new TreeNode(2);
	root2->left->right=new TreeNode(5);
	binaryTreePathSum(root2,5);
	cout<< "maxPathSum(root)="<<endl;
	system("pause");
}