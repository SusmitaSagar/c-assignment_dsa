#include <iostream>
using namespace std;

int main(){
    int i,j,value,rows,columns,check=0;
    
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>columns;
    int arr[rows][columns];
    cout<<"please enter the elements of array"<<endl;
    for (i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            cout<<"element "<<"("<<i<<','<<j<<"): ";
            cin>>arr[i][j];
        }
    }
    
    cout<<"Enter the element you need to search: ";
    cin>>value;
    
    for (i=0;i<rows;i++){
        for (j=0;j<columns;j++){
            if (value == arr[i][j]){
                cout<<value<<" found at position " << " ("<<i<<','<<j<<")"<<endl;
                check = 1;
            }
        }
    }
    if (check == 0){
        cout<<value<<" element not found"<<endl;
    }
    
    return 0;
}