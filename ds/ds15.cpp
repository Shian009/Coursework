//Binary search Trees
#include<iostream>
#include"stackLL.h"
#include"queueLL.h"
using namespace std;
template<class T>
class BST_Node
{
	public:
		T info;
		BST_Node *left, *right;
};

template<class T>
class BST
{
	BST_Node<T> *root;
	public:
		BST_Node<T>* return_root()
		{
			return root;
		}

		void insert(T x)
		{
			BST_Node<T> *t = new BST_Node<T>();
			t->info = x;
			t->left = t->right = NULL;
			if(root == NULL)
			{
				root = t;
				return;
			}
			BST_Node<T> *p, *q;
			p = q = root;
			while(p != NULL)
			{
				q = p;
				if(p->info > x)
					p = p->left;
				else
					p = p->right;
			}
			if(q->info > x)
				q->left = t;
			else
				q->right = t;
		}

		BST_Node<T>* search(T target)
		{
			if(root == NULL)
				return NULL;
			BST_Node<T> *p = root;
			while(p != NULL)
			{
				if(p->info == target)
					return p;
				if(p->info > target)
					p = p->left;
				else
					p = p->right;
			}
			return NULL;
		}

		void preorder()			//iterative
		{
			Stack<BST_Node<T>*> s;
			BST_Node<T> *p = root;
			if(p != NULL)
			{
				s.push(p);
				while(!s.isEmpty())
				{
					p = s.pop();
					cout<<p->info<<" ";
					if(p->right != NULL)
						s.push(p->right);
					if(p->left != NULL)
						s.push(p->left);
				}
				cout<<endl;
			}
			else
				cout<<"\nTree is Empty!\n";
		}

		void inorder()			//iterative
		{
			Stack<BST_Node<T>*> s;
			BST_Node<T> *p = root;
			if(p != NULL)
			{
				while(p != NULL)
				{
					while(p != NULL)
					{
						if(p->right != NULL)
							s.push(p->right);
						s.push(p);
						p = p->left;
					}
					p = s.pop();
					while(!s.isEmpty() && p->right == NULL)
					{
						cout<<p->info<<" ";
						p = s.pop();
					}
					cout<<p->info<<" ";
					if(!s.isEmpty())
						p = s.pop();
					else
						p = NULL;
				}
				cout<<endl;
			}
			else
				cout<<"\nTree is Empty!\n";
		}

		void postorder()
		{
			Stack<BST_Node<T>*> s;
			BST_Node<T> *p = root;
			BST_Node<T> *q = root;
			while(p != NULL)
			{
				while(p->left != NULL)
				{
					s.push(p);
					p = p->left;
				}
				while(p != NULL && (p->right == NULL || p->right == q))
				{
					cout<<p->info<<" ";
					q = p;
					if(s.isEmpty())
						return;
					p = s.pop();
				}
				s.push(p);
				p = p->right;
			}
			cout<<"\nTree is Empty!\n";
		}

		void bfs()
		{
			Queue<BST_Node<T>*> q;
			BST_Node<T> *p = root;
			if(p != NULL)
			{
				q.enqueue(p);
				while(!q.isEmpty())
				{
					p = q.dequeue();
					cout<<p->info<<" ";
					if(p->left != NULL)
						q.enqueue(p->left);
					if(p->right != NULL)
						q.enqueue(p->right);
				}
				cout<<endl;
			}
			else
				cout<<"\nTree is Empty!\n";		
		}

		int height(BST_Node<T> *p)
		{
			if(p == NULL)
				return 0;
			else
			{
				int lft = height(p->left);
				int rght = height(p->right);

				if(lft > rght)
					return (lft + 1);
				else
					return (rght + 1);
			}
		}

		void mirror(BST_Node<T> *p)
		{
			if(p != NULL)
			{
				mirror(p->left);
				mirror(p->right);
				
				BST_Node<T> *temp = p->left;
				p->left = p->right;
				p->right = temp;
			}
		}

		void delByCopying(T target)				//by finding the predecessor
		{
			BST_Node<T> *p = root;
			BST_Node<T> *q = NULL;
			BST_Node<T> *t;
			if(root == NULL)
			{
				cout<<"\nTree is empty!\n";
				return;
			}
			while(p != NULL)
			{
				if(p->info == target)
					break;
				q = p;
				if(p->info > target)
					p = p->left;
				else
					p = p->right;
			}
			if(p == NULL)
			{
				cout<<"\nValue to be deleted is not present in the tree!\n";
				return;
			}

			if(p->left != NULL && p->right != NULL)			//finding the predecessor and copying it's value in p
			{
				q = p;
				t = p->left;
				while(t->right != NULL)
				{
					q = t;
					t = t->right;
				}
				p->info = t->info;
				p = t;
			}

			if(q != NULL)			//not the root BST_Node to be deleted (physically)
			{
				if(p->left == NULL && p->right == NULL)				//leaf BST_Node
				{
					if(q->right == p)
						q->right = NULL;
					else
						q->left = NULL;
				}
				else if(p->left == NULL && p->right != NULL)		//has only right child 
				{
					if(q->right == p)
						q->right = p->right;
					else
						q->left = p->right;
				}
				else if(p->left != NULL && p->right == NULL)		//has only left child
				{
					if(q->right == p)
						q->right = p->left;
					else
						q->left = p->left;
				}
			}

			else				//root BST_Node to be deleted
			{
				if(p->left == NULL && p->right == NULL)
					root = NULL;
				else if(p->left == NULL && p->right != NULL)
					root = p->right;
				else
					root = p->left;
			}
			delete p;
		}

		void delByMerging(T target)				//by using left child to replace and hence, finding the predecessor
		{
			BST_Node<T> *p = root;
			BST_Node<T> *q = NULL;
			BST_Node<T> *t;
			if(root == NULL)
			{
				cout<<"\nTree is empty!\n";
				return;
			}
			while(p != NULL)
			{
				if(p->info == target)
					break;
				q = p;
				if(p->info > target)
					p = p->left;
				else
					p = p->right;
			}
			if(p == NULL)
			{
				cout<<"\nValue to be deleted is not present in the tree!\n";
				return;
			}

			if(p->left != NULL && p->right != NULL)			//finding the predecessor
			{
				t = p->left;
				while(t->right != NULL)
					t = t->right;
				t->right = p->right;
				p->right = NULL;
			}

			if(q != NULL)			//not the root BST_Node to be deleted (physically)
			{
				if(p->left == NULL && p->right == NULL)				//leaf BST_Node
				{
					if(q->right == p)
						q->right = NULL;
					else
						q->left = NULL;
				}
				else if(p->left == NULL && p->right != NULL)		//has only right child 
				{
					if(q->right == p)
						q->right = p->right;
					else
						q->left = p->right;
				}
				else if(p->left != NULL && p->right == NULL)		//has only left child
				{
					if(q->right == p)
						q->right = p->left;
					else
						q->left = p->left;
				}
			}

			else				//root BST_Node to be deleted
			{
				if(p->left == NULL && p->right == NULL)
					root = NULL;
				else if(p->left == NULL && p->right != NULL)
					root = p->right;
				else
					root = p->left;
			}
			delete p;
		}

		int leafCount(BST_Node<T> *p)
		{
			if(p == NULL)
				return 0;
			if(p->left == NULL && p->right == NULL)
				return 1;
			return leafCount(p->left) + leafCount(p->right);
		}

		int totalBST_Nodes(BST_Node<T> *p)
		{
			if(p == NULL)
				return 0;
			return 1 + totalBST_Nodes(p->left) + totalBST_Nodes(p->right);
		}
};

int main()
{
	BST<int> b;
	cout<<"BINARY SEARCH TREES\n";
	int val,target,ch,ele;
	do
	{
		cout<<"\nMENU\n"
			<<"1.Insertion\n"
			<<"2.Deletion by Copying\n"
			<<"3.Deletion by Merging\n"
			<<"4.Search a value\n"
			<<"5.Display Pre-order traversal\n"
			<<"6.Display Post-order traversal\n"
			<<"7.Display In-order traversal\n"
			<<"8.Display Level-By-Level traversal\n"
			<<"9.Count the non-leaf and leaf BST_Nodes\n"
			<<"10.Height of the tree\n"
			<<"11.Create a mirror image (in Pre-order)\n"
			<<"12.Exit\n";		
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{	
			case 1:	{
						cout<<"\nEnter the value to be inserted: ";
						cin>>val;
						b.insert(val);
						break;
					}
			case 2:	{
						cout<<"\nEnter the value to be deleted: ";
						cin>>ele;
						b.delByCopying(ele);
						break;
					}
			case 3:	{
						cout<<"\nEnter the value to be deleted: ";
						cin>>ele;
						b.delByMerging(ele);
						break;
					}
			case 4:	{
						cout<<"\nEnter value to be searched: ";
						cin>>target;
						BST_Node<int> *y = b.search(target);
						if(y != NULL)
							cout<<"Value is present in the tree!\n";
						else
							cout<<"Value is not present in the tree!\n";
						break;
					}
			case 5:	{
						cout<<"\nPre-order traversal: \n";
						//BST_Node<int> *root = b.return_root();
						b.preorder();
						break;
					}
			case 6:	{
						cout<<"\nPost-order traversal: \n";
						//BST_Node<int> *root = b.return_root();
						b.postorder();
						break;
					}
			case 7:	{
						cout<<"\nIn-order traversal: \n";
						//BST_Node<int> *root = b.return_root();
						b.inorder();
						break;
					}
			case 8:	{
						cout<<"\nLevel-By-Level traversal: \n";
						//BST_Node<int> *root = b.return_root();
						b.bfs();
						break;
					}
			case 9:	{
						BST_Node<int> *root = b.return_root();
						int leaf = b.leafCount(root);
						int nleaf = b.totalBST_Nodes(root) - leaf;
						if(leaf == 1 && nleaf == 0)
						{
							cout<<"\nOnly root BST_Node present.\n";
						}
						else
						{
							cout<<"\nNumber of leaf nodes: "<<leaf;
							cout<<"\nNumber of non-leaf nodes: "<<nleaf<<endl;
						}	
						break;
					}
			case 10:{
						BST_Node<int> *root = b.return_root();
						int h = b.height(root);
						cout<<"\nHeight of the tree (assuming root at level 1): "<<h<<endl;
						break;
					}
			case 11:{
						BST_Node<int> *root = b.return_root();
						b.mirror(root);
						cout<<"\nMirror Image (In-order traversal): \n";
						b.inorder();
						break;
					}
			case 12:return 0;
			default:cout<<"\nInvalid choice!! Please choose a valid option!\n";
		}
	}while(ch != 12);
	return 0;
}