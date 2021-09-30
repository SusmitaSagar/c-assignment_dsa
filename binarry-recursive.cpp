// using recursion finding the element in the array using Binary Search method
#include <iostream>
using namespace std;

void binary_search(int key,int arr[],int len){
    
    int start=0,end=len-1,mid=len/2;
    
    while(start<=end){
        
        if (key == arr[mid]){
            cout<<"Found at index "<<mid<<endl;
            return;
        }else if(key < arr[mid]){
            end = mid-1;
            mid = (start + end)/2;
        }else{
            start = mid+1;
            mid = (start + end)/2;
        }
    }
    cout<<"your required key is not found"<<endl;
    return ;
}
void b_search_recursive(int key,int arr[],int first,int last){
    int mid = (first+last)/2;
    if(first>last){
        cout<<"Element not found"<<endl;
        return;
    }
    if(key == arr[mid]){
        cout<<"Found at index "<<mid<<endl;
        return;
    }else if(key < arr[mid]){
        b_search_recursive(key,arr,first,mid-1);
    }else{
        b_search_recursive(key,arr,mid+1,last);
    }
}
int main()
{
    int length,i,key;
    cout<< "Enter the Length of the array: ";
    cin>>length;
    int arr[length];
    cout<< "Enter the sorted value of element of array"<<endl;
    for(i=0;i<length;i++){
        cout<<"Element"<<'('<<i<<") :";
        cin>>arr[i];
    }
    
    cout<<"Enter a key to be searched: ";
    cin>>key;
   
    b_search_recursive(key,arr,0,length);
    

    return 0;
}



// in recursion
// the function call itself until the base condition is reached