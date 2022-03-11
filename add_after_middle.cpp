#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* pNext;
};
struct LIST{
    Node* pHead;
    Node* pTail;
};
Node* CreateNode(int init_data)
{
    Node* node = new Node;
    node->data = init_data;
    node->pNext = NULL;
    return node;
};
void CreateEmptyList(LIST& L){
    L.pHead = NULL;
    L.pTail = NULL;
}
void AddHead(LIST &list, Node* node) 
{
	if (list.pHead == NULL)
	{
		list.pHead = node;
		list.pTail = node;
	}
	else
	{
		node->pNext = list.pHead;
		list.pHead = node;
	}
}
void AddTail(LIST &list, Node* node)
{
	if (list.pHead == NULL)
	{
		list.pHead = node;
		list.pTail = node;
	}
	else
	{
		list.pTail->pNext = node;
		list.pTail = node;
	}
}
void CreateList(LIST &L){
    int a;
    do{
        cin>>a;
        if(a == -1) break;
        else{
            AddTail(L, CreateNode(a));
        }
    }   
    while(true);
}
int elements(LIST l){
    double i = 0;
    for(Node* p = l.pHead; p != NULL; p = p->pNext){
       i++;
    } 
    if(i/2 == (int)(i/2))
        return i/2;
    else 
        return (i/2)+1;
}
void InsertAfterQ(LIST& l, Node* p, Node* q) 
{
	if (q != NULL)
	{
		p->pNext = q->pNext;
		q->pNext = p;
		if (l.pTail == q)
			l.pTail = p;
	}
	else
		AddHead(l, p);
}
void add_after_middle(LIST& l, int Y){
    int temp = 1;
    for(Node* p = l.pHead; p != NULL; p = p->pNext){
        if(elements(l) == 0){
            AddTail(l,CreateNode(Y)); // 1 phan tu thi them vao tail
            break;
        }       
        else if(temp == elements(l)){
            InsertAfterQ(l,CreateNode(Y),p);
            break;
        }
        else temp++;
    }
}
void PrintList(LIST l)
{
	if (l.pHead != NULL)
	{
		Node* node = l.pHead;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->pNext; 
		}
	}
    else cout<<"Empty List.";
}
int main() {
    LIST L;
	int X, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_middle(L, Y);

	PrintList(L);

    return 0;
}
