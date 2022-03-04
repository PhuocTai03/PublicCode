#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <crtdefs.h>
#define MAXN 500000
#define max(a, b)  (a>b)?a:b
using namespace std;
void RandomArray(int A[], int n){
    srand (time(NULL));
    for(int i=0; i < n; i++)
        A[i]=(rand()%100+1) - 50;
}
float ThuatToan1(int A[], int n, int& maxSum){
    clock_t start, end;
    start = clock();
    maxSum = 0;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i; j < n; j ++) {
            int sum = 0;
            for (int k = i; k <= j; k ++) {
                sum += A[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    end = clock();
    return (float)(end-start)/CLOCKS_PER_SEC;
}
float ThuatToan2(int A[], int n, int& maxSum){
    clock_t start, end;
    start = clock();
    maxSum = 0;
    int sum = 0;
    for( int i = 0; i < n; i++ ){
        sum = 0;
        for( int j = i; j < n ; j++ ) {
            sum += A[j];
            maxSum = max(maxSum, sum);
        } 
    }
    end = clock();
    return (float)(end-start)/CLOCKS_PER_SEC;
}
int maxCrossingSum(int arr[], int l, int mid, int r) {
    // Include e lements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum) left_sum = sum;
    }
     // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid+1; i <= r; i++) {
        sum = sum + arr[i];
        if (sum > right_sum) right_sum = sum;
    } 
    // Return sum of elements on left and right of mid
    return left_sum + right_sum;
}
int maxSubArraySum(int arr[], int l, int r) {
   // Base Case: Only one element
   if (l == r) return arr[l];
   int mid = (l + r)/2;
    /* Return maximum of following three possible cases
      a) Maximum subarray sum in left half
      b) Maximum subarray sum in right half
      c) Maximum subarray sum such that the subarray crosses the midpoint */
   return max(max(maxSubArraySum(arr, l, mid),maxSubArraySum(arr, mid+1, r)),
                            maxCrossingSum(arr, l, mid, r));
}
float ThuatToan3(int A[], int n, int& maxSum){
    clock_t start, end;
    start = clock();
    maxSum = maxSubArraySum(A,0,n);
    end = clock();
    return (float)(end-start)/CLOCKS_PER_SEC;
}
float ThuatToan4(int A[], int n, int &maxSum){
    clock_t start, end;
    start = clock();
    maxSum = 0;
    int sum = 0;
    for( int j = 0; j < n; j++ ) {
        sum += A[j];
        if (sum > maxSum)	
            maxSum = sum;
        else if (sum < 0)
            sum = 0;
    }
    end = clock();
    return (float)(end-start)/CLOCKS_PER_SEC;
} 
int main()
{
    int maxSum1 = 0; int maxSum2 = 0; int maxSum3 = 0; int maxSum4 = 0;
    int A[MAXN];
    int n =1000;
    RandomArray(A,n);
    cout<<"n = "<<n<<endl;
    cout<<"Thoi gian chay thuat toan 1: "<<setprecision(10)<<ThuatToan1(A,n,maxSum1)<<"\n    Ket qua = "<<maxSum1<<"\n";
    cout<<"\nThoi gian chay thuat toan 2: "<<setprecision(10)<<ThuatToan2(A,n,maxSum2)<<"\n    Ket qua = "<<maxSum2<<"\n";
    cout<<"\nThoi gian chay thuat toan 3: "<<setprecision(10)<<ThuatToan3(A,n,maxSum3)<<"\n    Ket qua = "<<maxSum3<<"\n";
    cout<<"\nThoi gian chay thuat toan 4: "<<setprecision(10)<<ThuatToan4(A,n,maxSum4)<<"\n    Ket qua = "<<maxSum4<<"\n";
    return 0;
}