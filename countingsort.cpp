#include<iostream>
using namespace std;
int max(int a[],int n) {
    int max=0;
    for(int i=0; i<n; i++) {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
int counting_sort (int A[], int n) {
    int m=max(A,n)+1;
    int D[m];
    int S[n];
    for(int i=0; i<m; i++)
        D[i]=0;
    for(int i=0; i<n; i++)
        D[A[i]]++;
    for(int i=1; i<m; i++)
        D[i]+=D[i-1];
         for(int i=0;i<m;i++)
        cout<<D[i]<<" ";
        cout<<endl;
    for(int i=0; i<n; i++) {
        S[--D[A[i]]]=A[i];
       // D[A[i]]--;
    }
    for(int i=0; i<n; i++)
        A[i]=S[i];

return 0;

}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    counting_sort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
}
