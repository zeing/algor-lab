#include<iostream>
using namespace std;
void insertsort(int a[],int n) {
        for(int i=1; i<n; i++) {
                int j=i;
                while(j>0) {
                    if(a[j-1]>a[j])
                        swap(a[j-1],a[j]);
                    j--;
                }
        }
}
int binary_search(int a[], int l,int r, int x) {
    int mid=(l+r)/2;
    //cout<<l<<"  "<<r<<endl;
    if(x == a[mid]) return mid;
    else if(l!=r) {
            if(x < a[mid]) return binary_search(a, l, mid, x);
            else  return binary_search(a, mid+1, r, x);
    }
    if(x>a[mid])
        return mid+1;
    else return mid;
}
int insert_input(int a[], int n, int x) {
    //cout<<n;
    insertsort(a,n-1);
    int num=binary_search(a,0,n-1,x);

    for(int i=n-1; i>num; i--) {
        a[i]=a[i-1];
        //cout<<a[i]<<"dffg"<<endl;

    }

    a[num]=x;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    return 0;
}
int main() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0; i<n; i++)
            cin>>a[i];
    n++;
    cout<<"Input X "<<endl;
    int x;
    cin>>x;
    //insertsort(a,n);
    //cout<<binary_search(a,0,n,x);
    insert_input(a,n,x);

}
