#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <crtdefs.h>
#define MAXN 500000
// A utility function to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// A utility function to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }
using namespace std;
void RandomArray(int A[], int n){
    srand (time(NULL));
    for(int i=0; i < n; i++)
        A[i]=(rand()%100+1) - 50;
}
float ThuatToan1(int A[], int n, int& maxSum){
    clock_t start, end;
    start = clock();
    maxSum = INT_MIN;
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
    maxSum = INT_MIN;
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
// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
int maxCrossingSum(int arr[], int l, int m, int r)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= r; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    // Return sum of elements on left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return max(left_sum + right_sum, left_sum, right_sum);
}
 
// Returns sum of maximum sum subarray in aa[l..r]
int maxSubArraySum(int arr[], int l, int r)
{
    // Base Case: Only one element
    if (l == r)
        return arr[l];
 
    // Find middle point
    int m = (l + r) / 2;
 
    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */
    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, r),
               maxCrossingSum(arr, l, m, r));
}
 
/*Driver program to test maxSubArraySum*/
float ThuatToan3(int A[], int n, int& maxSum){
    clock_t start, end;
    start = clock();
    maxSum = maxSubArraySum(A,0,n-1);
    end = clock();
    return (float)(end-start)/CLOCKS_PER_SEC;
}
float ThuatToan4(int A[], int n, int &maxSum){
    clock_t start, end;
    start = clock();
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
    int A[MAXN];
    int testcase[] = {10, 100, 1000, 5000, 10000, 20000, 50000, 100000, 200000, 300000, 400000, 500000};
	int n = 0;
    do{
        int maxSum1 = 0; int maxSum2 = 0; int maxSum3 = 0; int maxSum4 = 0;
        RandomArray(A,testcase[n]);
        cout<<"\nTruong hop n = "<<testcase[n];
        cout<<"\nThoi gian chay thuat toan 1: "<<setprecision(10)<<ThuatToan1(A,testcase[n],maxSum1)<<"\n"<<"Ket qua = "<<maxSum1<<"\n";
        cout<<"\nThoi gian chay thuat toan 2: "<<setprecision(10)<<ThuatToan2(A,testcase[n],maxSum2)<<"\n"<<"Ket qua = "<<maxSum2<<"\n";
        cout<<"\nThoi gian chay thuat toan 3: "<<setprecision(10)<<ThuatToan3(A,testcase[n],maxSum3)<<"\n"<<"Ket qua = "<<maxSum3<<"\n";
        cout<<"\nThoi gian chay thuat toan 4: "<<setprecision(10)<<ThuatToan4(A,testcase[n],maxSum4)<<"\n"<<"Ket qua = "<<maxSum4<<"\n"
             <<"-------------------------------------------------------------------------------------------\n"
             <<endl; 
        n++;
    } while (n <= 4);
    do{
        int maxSum1 = 0; int maxSum2 = 0; int maxSum3 = 0; int maxSum4 = 0;
        cout<<"\nTruong hop n = "<<testcase[n]; //Thuattoan1 > 5 phut
        //cout<<"\nThoi gian chay thuat toan 1: "<<setprecision(10)<<ThuatToan1(A,testcase[n],maxSum1)<<"\n"<<"Ket qua = <<maxSum1<<"\n";
        cout<<"\nThoi gian chay thuat toan 2: "<<setprecision(10)<<ThuatToan2(A,testcase[n],maxSum2)<<"\n"<<"Ket qua = "<<maxSum2<<"\n";
        cout<<"\nThoi gian chay thuat toan 3: "<<setprecision(10)<<ThuatToan3(A,testcase[n],maxSum3)<<"\n"<<"Ket qua = "<<maxSum3<<"\n";
        cout<<"\nThoi gian chay thuat toan 4: "<<setprecision(10)<<ThuatToan4(A,testcase[n],maxSum4)<<"\n"<<"Ket qua = "<<maxSum4<<"\n"
             <<"-------------------------------------------------------------------------------------------\n"
             <<endl; 
        n++;
    } while (n <= 10);
    do{
        int maxSum1 = 0; int maxSum2 = 0; int maxSum3 = 0; int maxSum4 = 0;
        cout<<"\nTruong hop n = "<<testcase[n]; //Thuattoan1 > 5 phut
        //cout<<"\nThoi gian chay thuat toan 1: "<<setprecision(10)<<ThuatToan1(A,testcase[n],maxSum1)<<"\n"<<"Ket qua = "<<maxSum1<<"\n";
        //cout<<"\nThoi gian chay thuat toan 2: "<<setprecision(10)<<ThuatToan2(A,testcase[n],maxSum2)<<"\n"<<"Ket qua = "<<maxSum2<<"\n";
        cout<<"\nThoi gian chay thuat toan 3: "<<setprecision(10)<<ThuatToan3(A,testcase[n],maxSum3)<<"\n"<<"Ket qua = "<<maxSum3<<"\n";
        cout<<"\nThoi gian chay thuat toan 4: "<<setprecision(10)<<ThuatToan4(A,testcase[n],maxSum4)<<"\n"<<"Ket qua = "<<maxSum4<<"\n"
             <<"-------------------------------------------------------------------------------------------\n"
             <<endl; 
        n++;
    } while (n <= 11);
    return 0;
}
