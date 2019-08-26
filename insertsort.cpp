#include<iostream>
using namespace std;
void swap(int* i,int* j) {
    int a=*i;
    *i=*j;
    *j=*i;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=1; i<n; i++) {
            int j=i;
            while(j>0) {
                if(a[j-1]>a[j])
                    swap(a[j-1],a[j]);
                j--;
            }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}
