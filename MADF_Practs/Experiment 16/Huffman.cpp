#include<iostream>
#include<queue>
#include<map>
using namespace std;

map<char,string>encode;		//map for encoding

//struct to create a huffman tree node
struct hnode
{
	char c;
	int f;
	struct hnode *left,*right;
	
	hnode(char data, int freq)
	{
		left=right=NULL;
		this->c = data;
		this->f = freq;
	}
	
}; typedef struct hnode node;


void EncodeChar(char *data)
{
	map<char,string> :: iterator itr;
	
	int size = strlen(data);
	for(int i=0;i<size;i++)
		cout<<encode[data[i]];
		
	cout<<endl;
}
		
	
void printCodes(node *root, string str)		//prints the code of each char 
{
	if(!root)
		return;

	if(root->c != '*')
		{
			encode[root->c] = str;
			cout<<root->c<<" : "<<str<<endl;
		}
		
	printCodes(root->left,str + "0");
	printCodes(root->right,str + "1");
	
}

struct compare		//used by the STL to create a minheap
{
	 bool operator()(node* l, node* r)
 
    {
        return (l->f > r->f);
    }
};
	

void GenHuff(char *data, int *freq, int n)
{
	
	node *left,*right,*top;		//temp pointers
	
	priority_queue<node *, vector<node*>, compare>minHeap;//STL priority queue creates minHeap
	
	for(int i=0;i<n;i++)
		minHeap.push(new node(data[i],freq[i]));
		
	
	while(minHeap.size()>1)
	{
		left = minHeap.top();
		minHeap.pop();
		
		right = minHeap.top();
		minHeap.pop();
		
		top = new node('*', left->f + right->f);//'*' indicates new node having left and right child
		top->left = left;
		top->right = right;
		
		minHeap.push(top);
	}
	
	printCodes(minHeap.top(), "");
	
		
}
	
	
int main()
{
	//int n; //number of unique characters
	int count,freq[20];
	map<char,int>obj;
	char data[100],chars[20];
	
	cout<<"Enter a string: ";
	cin.getline(data,100);
	
	int n = strlen(data);
	for(int i=0;i<n;i++)
		{
			if(obj.count(data[i]) != 1)
				obj[data[i]] = 1;
			
			else
			{
				count = obj[data[i]];
				obj[data[i]] = ++count;
			}
		}
	
	map<char,int> :: iterator it;
	
	int i=0;
	for(it=obj.begin(); it!=obj.end(); it++)
		{
			chars[i] = it->first;
			freq[i] = it->second;
			i++;
		}
	n = i;
	int j = strlen(chars);
	for(int i=0;i<j;i++)
		cout<<chars[i]<<" : "<<freq[i]<<endl;
		
	

	cout<<"\nThe Huffman codes of each char are: \n";
	GenHuff(chars,freq,n);
	
	cout<<"\nThe encoded string is: ";
	EncodeChar(data);
	
	return 0;
}
	
