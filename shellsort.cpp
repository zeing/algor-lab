#include<iostream>
using namespace std;
void swap(int* i,int* j) {
    int a=*i;
    *i=*j;
    *j=*i;
}
void shell_sort(int a[],int n) {
    int k=n/2;
    while (k>1) {
        for(int i=0; i<n-k; i++) {
            if(a[i]> a[i+k])
                swap(a[i],a[i+k]);
        }
        k=k/2;
    }

      for(int i=0; i<n; i++) {
            for(int j=0; j<n-i-j; j++) {
                if(a[j]>a[j+1])
                    swap(a[j+1],a[j]);
            }
    }




}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    shell_sort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
}
