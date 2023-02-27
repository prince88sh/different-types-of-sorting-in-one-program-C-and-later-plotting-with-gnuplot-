#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>
#include <fstream>
using namespace std;
using namespace std::chrono;
class sorting
{
    int i,j;
    public:
    void bubble_sort(int a[],int n);
    void insertion_sort(int a[],int n);
    void selection_sort(int a[],int n);
    void merge_sort(int a[],int b[],int m,int n);
    void quick_sort(int a[],int l,int h);
    int partitionn(int a[],int low,int high);
};

void sorting ::bubble_sort(int a[],int n)
{
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1)-i;j++)
        {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        }
    //     cout<<"\nAfter "<<i+1<<" iteration elements are\n";
    //     for(int b=0;b<n;b++)
    //     cout<<" "<<a[b];
    }
}

void sorting ::selection_sort(int a[],int n)
{
    int temp,low,loc;
    for(i=0;i<n-1;i++)
    {
        low=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
        if(low>a[j])
        {
            loc=j;
            low=a[j];
        }
            temp=a[i];
            a[i]=a[loc];
            a[loc]=temp;
        }
        // cout<<"\nAfter "<<i+1<<" iteration elements are\n";
        // for(int b=0;b<n;b++)
        // cout<<" "<<a[b];
    }
    // cout<<"hello"<<endl;
    // for(int k=0;k<n-1;k++)
    // cout<<"==>"<<a[k]<<"    ";
}

void sorting ::insertion_sort(int a[],int n)
{
    for(i=1;i<n;i++)
    {
    int key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
        // cout<<"\nAfter "<<i+1<<" iteration elements are\n";
        // for(int b=0;b<n;b++)
        // cout<<" "<<a[b];
    }
}

void sorting ::merge_sort(int a[], int b[], int m, int n)
{
    int c[m+n];
    for(int i=0;i<m;i++)
        c[i]=a[i];
    for(int j=0;j<n;j++)
        c[j+m]=b[j];
    
    sort(c,c+m+n);
    
    // for(int i=0;i<m+n;i++)
    //     cout<<c[i]<<" ";
}

void sorting :: quick_sort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p=partitionn(arr,l,h);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,h);
    }
}
int sorting :: partitionn(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high-1;j++)
    {
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

int main()
{
    int n[]={10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,120000,130000,140000};
    int s=sizeof(n)/sizeof(n[0]);
 int t=0;
 int res,x; 
while(t<s)
{
    cout<<"\n======================================\n";
    cout<<"running for I/P= "<<n[t]<<" \n";
    x=n[t];
    int a[x];
    for(int i=0;i<x;i++){
    a[i]=rand()%x;
    }
    cout<<endl;
    cout<<"======>"<<endl;
    clock_t time_req;
    time_req=clock();

    sorting obj;
    res=n[t];
    obj.quick_sort(a,0,x-1);

time_req=clock()-time_req;
cout<<"Execution time :- "<<fixed << setprecision(8) <<(double)time_req/CLOCKS_PER_SEC<<" sec.."<<endl;
t++;
ofstream myfile;
myfile.open ("quick_sort.txt",ios::out |ios::app);
if (myfile.is_open())
{
    myfile << x <<"\t";
    myfile<<(double)time_req/CLOCKS_PER_SEC<<endl;
    myfile.close();
}
}
return 0;
}