#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        for(int j=1;j<arr.size();j++){
            if(arr[j-1]>arr[j])swap(arr[j-1],arr[j]);
        }
    }
}
void selectionSort(vector<int>&arr){
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        mini=INT_MAX;
        int idx;
        for(int j=i;j<arr.size();j++){
            if(mini>arr[j]){
                mini=arr[j];
                idx=j;
            }
        }
        arr[idx]=arr[i];
        arr[i]=mini;
    }
}
void insertionSort(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        int temp=arr[i];
        int j=i;
        while(j>0 and arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
            }
        arr[j]=temp;
    }
}
void merge(vector<int>&arr,int low,int mid,int high,vector<int>&temp){
    int l=low,m=mid+1,k=0;
    while(l<=mid and m<=high){
        if(arr[l]<=arr[m])temp[k++]=arr[l++];
        else temp[k++]=arr[m++];
    }
    while(l<=mid)temp[k++]=arr[l++];
    while(m<=high)temp[k++]=arr[m++];
    k=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[k++];
    }
}
void mergeSort(vector<int>&arr,int low ,int high,vector< int>& temp){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid,temp);
        mergeSort(arr,mid+1,high,temp);
        merge(arr,low,mid,high,temp);
    }


}
int pivotElement(vector<int>&arr,int low,int high){
     int temp=arr[high];
     int idx=0;
     for(int i=0;i<high;i++){
         if(arr[i]<=temp){
             swap(arr[i],arr[idx]);
             idx++;
         }
     }
     swap(arr[idx],arr[high]);
     return idx;
}
void quickSort(vector<int>&arr, int low,int high){
    if(high>low){
        int idx=pivotElement(arr,low,high);
        quickSort(arr,low,idx-1);
        quickSort(arr,idx+1,high);
    }

}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // bubbleSort(arr);
    // selectionSort(arr);
    // insertionSort(arr);
    // vector<int>temp(n);
    // mergeSort(arr,0,n-1,temp);
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}