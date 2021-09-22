#include <iostream>
using namespace std;

int main(){
    int i,j,value,rows,columns,check=0;
    
    cout<<"Choose the shape of the 2D array..."<<endl;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>columns;
    int arr[rows][columns];
    cout<<"Enter the values..."<<endl;
    for (i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            cout<<"element "<<'('<<i<<','<<j<<"): ";
            cin>>arr[i][j];
        }
    }
    
    cout<<"Enter the number to search: ";
    cin>>value;
    
    for (i=0;i<rows;i++){
        for (j=0;j<columns;j++){
            if (value == arr[i][j]){
                cout<<value<<" found at"<<" ("<<i<<','<<j<<")"<<endl;
                check = 1;
            }
        }
    }
    if (check == 0){
        cout<<value<<" not found"<<endl;
    }
    
    return 0;
}