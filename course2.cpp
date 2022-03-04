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
int ThuatToan1(int A[], int n){
    int maxSum = 0;
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
    return maxSum;
}
int ThuatToan2(int A[], int n){
    int maxSum = 0;
    for( int i = 0; i < n; i++ ){
        int sum = 0;
        for( int j = i; j < n ; j++ ) {
            sum += A[j];
            maxSum = max(maxSum, sum);
        } 
    }
    return maxSum;
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
int ThuatToan3(int A[], int n){
    int maxSum = maxSubArraySum(A,0,n);
    return maxSum;
}
int ThuatToan4(int A[], int n){
    int maxSum = 0;
    int sum = 0;
    for( int j = 0; j < n; j++ ) {
        sum += A[j];
        if (sum > maxSum)	
            maxSum = sum;
        else if (sum < 0)
            sum = 0;
    }
    return maxSum;
} 
int main()
{
    int maxSum[4] = {0,0,0,0};
    int A[MAXN];
    float time[4] = {0,0,0,0};
    int n =2000;
    RandomArray(A,n);
    clock_t start, end;
    for(int i=1; i <= 4; i++){
        start = 0;
        end = 0;
        if (i==1){
            start = clock ();
            maxSum[i] = ThuatToan1(A,n);
            end = clock ();
            time[i] = (float)(end-start)/CLOCKS_PER_SEC;
        }
        if (i==2){
            start = clock ();
            maxSum[i] = ThuatToan2(A,n);
            end = clock ();
            time[i] = (float)(end-start)/CLOCKS_PER_SEC;
        }
        if (i==3){
            start = clock ();
            time[i] = ThuatToan3(A,n);
            end = clock ();
            time[i] = (float)(end-start)/CLOCKS_PER_SEC;
        }
        if (i==4){
            start = clock ();
            maxSum[i] = ThuatToan4(A,n);
            end = clock ();
            time[i] = (float)(end-start)/CLOCKS_PER_SEC;
        }        
    }
    cout<<"n = "<<n<<endl;
    for(int i=1; i<=4;i++){
        cout<<"Thoi gian chay thuat toan "<<i<<" = "<<setprecision(10)<<time[i]<<"\n    Ket qua = "<<maxSum[i]<<"\n";
    }
    
    return 0;
}
