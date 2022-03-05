//Nhập bốn số nguyên và xuất các giá trị vừa nhập
#include <bits/stdc++.h>
using namespace std;
void Nhap(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<"Phan tu "<<i<<" = "; 
        cin>>arr[i]; 
    }
}
void Xuat(int arr[], int n){
    for(int i=0; i<n; i++)
        cout<<"Phan tu "<<i<<" = "<<arr[i]<<endl;
}
int main(){
    int n = 7;
    do{
        switch (n)
        {
        case 1:{
            cout<<"Case 1: \n";
            int a,b,c,d;
            cout<<"a = "; cin>>a;
            cout<<"b = "; cin>>b;
            cout<<"c = "; cin>>c;
            cout<<"d = "; cin>>d;
            cout<<"-------------\n";
            cout<<"a = "<<a;
            cout<<"\nb = "<<b;
            cout<<"\nc = "<<c;
            cout<<"\nd = "<<d;
            cout<<endl;
            break;
        }
        case 2:{
            cout<<"Case 2: \n";
            int arr[4];
            cout<<"a = "; cin>>arr[0];
            cout<<"b = "; cin>>arr[1];
            cout<<"c = "; cin>>arr[2];
            cout<<"d = "; cin>>arr[3];
            cout<<"-------------\n";
            cout<<"a = "<<arr[0];
            cout<<"\nb = "<<arr[1];
            cout<<"\nc = "<<arr[2];
            cout<<"\nd = "<<arr[3]<<endl;
            break;
        }
        case 3:{
            cout<<"Case 3: \n";
            int i = 0;
            int arr[4];
            do{
                cout<<"Phan tu "<<i<<" = "; cin>>arr[i];
                i++;
            }while(i < 4);
            cout<<"-------------\n";
            i = 0;
            do{
                cout<<"Phan tu "<<i<<" = "<<arr[i]<<endl;
                i++;
            } while (i < 4);
            break;
        }
        case 4:{
            cout<<"Case 4: \n";
            int arr[4];
            for(int i=0; i<4; i++){
                cout<<"Phan tu "<<i<<" = "; 
                cin>>arr[i];  
            }
            cout<<"-------------\n";
            for(int i = 0; i < 4; i++)
                cout<<"Phan tu "<<i<<" = "<<arr[i]<<endl; 
            break;
        }
        case 5:{
            cout<<"Case 5: \n";
            int arr[4];
            for(int i=0; i<4; i++)
                {
                    cout<<"Phan tu "<<i<<" = "; cin>>arr[i];
                    cout<<"Ket qua = "<<arr[i]<<endl; 
                }     
            break;      
        }
        case 6:{
            cout<<"Case 6: \n";
            int n = 4;
            int arr[n];
            Nhap(arr,n);
            cout<<endl;
            Xuat(arr,n);
            break;
        }
        case 7:{
            cout<<"Case 7: \n";
            int i = 0;
            FILE *file = fopen("baitapB2.txt","r"); //r=read : doc
            char *s = new char; // gan dai
            do
            {
                char line[150];
                s=fgets(line,150,file);
                if(s==NULL) break;
                else {
                    cout<<"Phan tu "<<i<<" = "<<s<<endl;
                    i++;
                }
            } while (true);
            fclose(file);
            break;
        }
        default:
            break;
        }
        n++;
    }while (n <=7 );
    return 0;
}