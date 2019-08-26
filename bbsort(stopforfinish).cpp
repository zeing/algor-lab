#include<iostream>
using namespace std;
void swap(int* i,int* j) {
    int a=*i;
    *i=*j;
    *j=*i;
}
void bubble(int a[], int n) {
    bool m;
    for(int i=0; i<n; i++) {
        m=false;
        for(int j=0; j<n-i-1; j++) {
                if(a[j]>a[j+1]) {
                    swap(a[j],a[j+1]);
                    m=true;
                }

        }
        if(!m) break;
    }
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    bubble(a,n);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
        cout<<endl;

}

