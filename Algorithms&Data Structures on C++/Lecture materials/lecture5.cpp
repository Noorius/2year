#include <iostream>

using namespace std;

void heapify(int arr[], int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i= n/2 -1; i >= 0; i--)
        heapify(arr,)
}

void printArray(int arr[], int n){
    for(int i=0;i <n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={12,11,13,51,6,7};
    int n =sizeof(arr)/sizeof(int);

    printArray(arr,n);
    heapify(arr,n,0);
    printArray(arr,n);

    return 0;
}