// using iteration write a program to find an element in array using binary search method.
#include <iostream>
using namespace std;
//int key is value to be searched,
void binary_search(int key,int arr[],int length){ 
    int start=0,end=length-1,middle=length/2;
    
    while(start <= end){     //end element is greater, ascending
        
        if(key < arr[middle]){
            end = middle-1;
            middle = (start + end)/2;
        }else if(key > arr[middle]){
            start = middle+1;   
            middle = (start + end)/2;
        }
        if (key == arr[middle]){
            cout<<"Found at index "<<middle<<endl;
            return;
        }
        if(start >= end ){
            cout<<key<<" not found"<<endl;
            return;
        }
    }
}
//length= lenth of array, key= the value to be searched
int main()
{
    int length,i,key;
    cout<< "Enter Length of the array: ";
    cin>>length;
    int arr[length];
    cout<< "Enter the elements of your array"<<endl;
    for(i=0;i<length;i++){
        cout<<"Element"<<'('<<i<<") :";
        cin>>arr[i];
    }
    
    cout<<"Enter a value of key to  be searched: ";
    cin>>key;
    
    binary_search(key,arr,length);
    

    return 0;
}

// iterative is applied to  iterative loops , fun. eg. for loop
//include loop format, init,condt,exec.
//set of instruction repeditly executed
//fast execution,infinite loop use cpu cycle

//






