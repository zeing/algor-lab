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
    int min=0;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(j==i)
                min=j;
            else if(a[min]>a[j])
                min=j;
        }
            swap(a[min],a[i]);


        }

     for(int j=0; j<n; j++)
        cout<<a[j]<<endl;

}
