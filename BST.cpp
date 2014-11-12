#include <iostream>
using namespace std;
struct BST_Node
{
	int data;
	BST_Node* left;
	BST_Node* right;
	int children;
};
class BST{
//private:
public:
	int height;
	int num;
	BST_Node* root;
	bool deleteTree(BST_Node* root);
	int insert(int src, BST_Node* node);
	BST(): height(0), num(0) {
		root = new BST_Node;
		root->data = -1;
		root->left = root->right = NULL;
		root->children = -1;
	};
	~BST(){
		deleteTree(root);
	};
	BST( BST &src){
		cloneTree(src);
	};
	void insert(int);
	int getHeight();
	void preOrder( BST_Node *node, void (*func)(BST_Node*) );
	void postOrder( BST_Node *node, void (*func)(BST_Node*) );
	void inOrder( BST_Node *node, void (*func)(BST_Node*) );
	int countSubTree(BST_Node* root, BST_Node* tar);
	bool isSubTree(BST_Node* root, BST_Node *tar);
	void show( BST_Node* node );
};
bool BST::deleteTree( BST_Node* node )
{
	if( node->data == -1 ){
		delete []node;
		node = NULL;
		return true;
	}
	if( node->left != NULL ){
		this->deleteTree(node->left);
	}
	if( node->right != NULL ){
		this->deleteTree(node->right);
	}
	delete []node;
	return true;
}
void BST::insert( int src )
{
	this->num += 1;
	int newHeight = this->insert(src, this->root);
	height = (height > newHeight) ? height : newHeight;
}
int BST::insert( int src, BST_Node* node)
{
	node->children += 1;
	if( node->data == -1 ){// insert this node 
		node->data = src;
		node->left = node->right = NULL;
		node->children = 1;
		return 1;
	}
	if( node->data > src ){
		if( node->left != NULL ){
			return this->insert( src, node->left ) +1;
		}else{
			node->left = new BST_Node;
			node->left->data = src;
			node->left->left = node->left->right = NULL;
			node->left->children = 1;
			return 2;
		}
	}else{
		if( node->right != NULL ){
			return this->insert( src, node->right )+1;
		}else{
			node->right = new BST_Node;
			node->right->data = src;
			node->right->left = node->right->right = NULL;
			node->right->children = 1;
			return 2;
		}
	}
}
void BST::preOrder( BST_Node *node, void (*func)(BST_Node*) )
{
	func(node);
	if( node == NULL )
		return ;
	preOrder( node->left, func );
	preOrder( node->right, func );
}
void BST::inOrder( BST_Node *node, void (*func)(BST_Node*) )
{
	if( node == NULL )
	{
		func(node);
		return ;
	}
	inOrder( node->left, func );
	func(node);
	inOrder( node->right, func );
}
void BST::postOrder( BST_Node *node, void (*func)(BST_Node*) )
{
	if( node == NULL )
	{
		func(node);
		return ;
	}
	postOrder( node->left, func );
	postOrder( node->right, func );
	func(node);
}
int BST::getHeight()
{
	return this->height;
}
void show( BST_Node* node )
{
	if( node == NULL )
		cout<<'#'<<' ';
	else
		cout<<node->data<<' ';
}
int BST::countSubTree(BST_Node* root, BST_Node* tar)
{
	if( root == NULL || tar == NULL )
			return 0;
	int temp1 = countSubTree(root->left, tar);
	int temp2 = isSubTree( root, tar );
	int temp3 = countSubTree(root->right, tar);
	return temp1+temp2+temp3;
}
bool BST::isSubTree(BST_Node* root, BST_Node* tar)
{
	if( root == NULL )
		if( tar == NULL )
			return true;
		else
			return false;
	if( tar == NULL )
		if( root == NULL )
			return true;
		else
			return false;
	bool temp1 = isSubTree(root->left, tar->left);
	bool temp2 = ((root->left == NULL)^(tar->left ==NULL)) && ((root->right == NULL)^(tar->right ==NULL));
	bool temp3 = isSubTree(root->right,  tar->right);
	return temp1 && (!temp2) && temp3;
}

int main()
{
	BST tree, sub_tree;
	int input, len1, len2;
	cin>>len1;
	for( ; len1>0; len1-- )
	{
		cin>>input;
		tree.insert(input);
	}
	cin>>len2;
	for( ; len2>0; len2-- )
	{
		cin>>input;
		sub_tree.insert(input);
	}
	tree.preOrder(tree.root, &show );
	cout<<endl;
	tree.inOrder(tree.root, &show );
	cout<<endl;
	tree.postOrder(tree.root, &show );
	cout<<endl;
	cout<<tree.getHeight()<<endl;
	cout<<tree.countSubTree(tree.root, sub_tree.root)<<endl;
	return 0;
}
