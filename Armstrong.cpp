#include <iostream>
#include <math.h>
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
void CreateEmptyList(LIST &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
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
void CreateList(LIST &L){
    int a;
    do{
        cin>>a;
        if(a == -1) break;
        else{
            AddHead(L, CreateNode(a));
        }
    }   
    while(true);
}
int SoChuSo(int n){
    int i = 0;
    while(n>0){
        n = n/10;
        i++;
    }
    return i;
}

void PrintList_Armstrong(LIST L){
    if(L.pHead != NULL){
        int check = 0;  // kiem tra xem co so thoa dieu kien hay khong
        for(Node* p = L.pHead; p != NULL; p = p->pNext){
                int SoMu = SoChuSo(p->data);
                int sum = 0;
                int temp = p->data;
            if(temp == 0) continue; //day Armstrong nguyen duong >= 1
            else{
                while(temp>0){
                    sum += pow((temp)%10,SoMu);
                    temp = temp/10;
                }
                if(sum == p->data){
                    cout<<p->data<<" ";
                    check++;
                }  
            }
        }
            if(check == 0) cout<<"Không có số armstrong trong mảng.";
    }
    else cout<<"Empty List.";
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}
