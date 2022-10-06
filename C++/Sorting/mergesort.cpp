#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high,vector<int>&temp){
    int l=low,m=mid+1;
    int k=0;
    while(l<=mid and m<=high){
        if(arr[l]<=arr[m]){
            temp[k++]=arr[l++];
        }
        else {
            temp[k++]=arr[m++];
        }
    }
    while(l<=mid)temp[k++]=arr[l++];
    while(m<=high)temp[k++]=arr[m++];
    k=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[k++];
    }
}
void mergeSort(vector<int>&arr,int low,int high,vector<int>&temp){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid,temp);
        mergeSort(arr,mid+1,high,temp);
        merge(arr,low,mid,high,temp);
    }
}
int main(){
     int n;
     cin>>n;
     vector<int>arr(n);
     vector<int>temp(n);
     int low=0,high=n-1;
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     mergeSort(arr,low,high,temp);
     for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
     }


    return 0;
}