#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Tree{
	public:
		T data;
		vector<Tree<T>*>child;
		
		Tree(T data)
		{
			this->data=data;
			
		}
		 ~Tree() {
            for (int i = 0; i < child.size(); i++) {
                delete child[i];
            }
	}
};

Tree<int>* maxDataNode(Tree<int>* root) {
    
    Tree<int>* maxNode = new Tree<int>(0);
    int max = 0;
    for(int i=0; i<root->child.size();i++){
        if(maxDataNode(root->child[i])->data > max)
        {    
            max = maxDataNode(root->child[i])->data;
            maxNode = maxDataNode(root->child[i]);
        }
    }
    if(root->data > maxNode->data)
    {
        maxNode = root;
        return maxNode;
    }
    return maxNode;

}
Tree<int>*input()
{
	int val;
	cout<<"Enter root data= ";
	cin>>val;
	Tree<int>*root=new Tree<int>(val);
	queue<Tree<int>*>q;
	
	q.push(root);
	
	while(!q.empty())
	{
		Tree<int>*temp=q.front();
		q.pop()	;
		int n;
		cout<<"Enter number of children of "<<temp->data<<" = ";
		cin>>n;	
		
		for(int i=1;i<=n;i++)
		{
			int v;
			cout<<"Enter data of "<<i<<"th child of "<<temp->data<<" = ";
			cin>>v;
			Tree<int>*t=new Tree<int>(v);
			temp->child.push_back(t);
			q.push(t);
			
			
		}
	}
	return root;		
	
}
int main()
{
	Tree<int>*root=input();
	cout<<"Max of all nodes of tree= "<<maxDataNode(root)->data;
	return 0;
}
