#include<iostream>
using namespace std;
void swap(int *i,int *l) {
    int a;
    a=*i;
    *i=*l;
    *l=a;
}
int quicksort(int a[],int i,int j);
int main() {
    int n;
    cin>>n;
    int a[n];
   // cout<<sizeof(a)/sizeof(a[0])<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int l=0,r=n,cen=(l+n)/2;
    if(a[cen]<a[l])
        swap(a[cen],a[l]);
    if(a[cen]>a[r])
        swap(a[cen],a[r]);
    if(a[cen]<a[l])
        swap(a[cen],a[l]);
    swap(a[cen],a[r]);
   // cout<<a[r];
   quicksort(a,l,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}
int quicksort(int a[],int i,int j) {
    int l=i,r=j;
    int p=(i+j)/2;
  //  cout<<"pi"<<a[p];
    while(i<=j) {
        while(a[i]<a[p])
            i++;
        while(a[j]>a[p]) {
          //  cout<<a[j]<<endl;
            j--;
        }
        if(i<=j) {
           /* if(j==p)
             p=j;
            if(i==p)
             p=i;*/

            swap(a[j],a[i]);
            i++;
            j--;
             //cout<<"Swap"<<" ";
        }
    };

    if(l<j) {
         //   cout<<"sfdf";
        quicksort(a,l,j+1);
    }
    if(r>i) {
           // cout<<"sfasfsdfsdgdf";
        quicksort(a,i,r+1);
    }

}
