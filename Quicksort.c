#include<stdio.h>
void QuickSort(int a[],int down,int up)
{
    int pivot,d,u,temp;
    pivot = down;
    d = down;
    u = up;
    if(u>d)
    {
        while(d<u)
        {
            while(a[d]>a[pivot]&&d<up)
            d++;
            while(a[u]<a[pivot])
            u--;
            if(u>d)
            {
                temp=a[u];
                a[u]=a[d];
                a[d]=temp;
            }
        }
    }
    temp = a[d];
    a[d]=a[pivot];
    a[pivot]=temp;
    QuickSort(a,down,d-1);
    QuickSort(a,u+1,up);

}
int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("enter %d number: ",n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    QuickSort(a,0,n-1);

    printf("Sorted number is: ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    getch();
    return 0;
}

