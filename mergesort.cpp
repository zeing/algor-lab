#include<iostream>

using namespace std;
void swap(int *i,int *l) {
    int a;
    a=*i;
    *i=*l;
    *l=a;
}
int mergesort(int a[],int n);
void merges(int a[],int b[],int sizeB,int c[],int sizeC) {
  //  cout<<"merge"<<endl;
    int sB = sizeB;
    int sC = sizeC;
    int i=0,j=0,k=0;
    while(i<=sB && j<=sC) {
         // cout<<"I"<<i<<"   "<<"J"<<j<<"  ";
           // cout<<"B"<<b[i]<<"   "<<"C"<<c[j]<<endl;
        if(b[i]<=c[j]) {
        //    cout<<"Yes"<<endl;
            a[k]=b[i];
            i++;
        } else {
          //   cout<<"NO"<<endl;
            a[k]=c[j];
            j++;
        }
        k++;
    }
    while(i<sB) {
        a[k]=b[i];
        i++;
        k++;
    }
    while(j<sC) {
        a[k]=c[j];
        j++;
        k++;
    }


}

int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
   // cout<<"main"<<sizeof(a)<<endl;
    mergesort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}
int mergesort(int a[],int size) {
    int n=size;
    int mid=n/2;
    //a[size]=a[size-1]+1;
    int l[mid],r[n-mid];
    //cout<<"in func"<<n<<endl;
    if(n<2) return 0;
    for(int i=0;i<mid;i++)
        l[i]=a[i];
    for(int i=mid;i<n;i++)
        r[i-mid]=a[i];
   // cout<<"l"<<endl;
  /*  for(int i=0;i<mid;i++)
        cout<<l[i]<<" ";
        cout<<endl;
     cout<<"left"<<endl;*/
    mergesort(l,mid);
   // cout<<"r"<<endl;
  // cout<<"right"<<endl;
    mergesort(r,n-mid);
  /*   for(int i=0;i<n-mid;i++)
        cout<<r[i]<<" ";
         cout<<endl;*/

    merges(a,l,mid,r,n-mid) ;

}
