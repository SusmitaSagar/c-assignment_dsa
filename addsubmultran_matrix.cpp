//Program-3 program to perform following operations on tables using functions only
// a) Addition b) Subtraction c) Multiplication d) Transpose
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int** read(int m, int n, const char *name){  
    cout<<name<<" :Enter total "<< m*n  <<" elements of matrix"<<endl;  //total element
    int **A = new int*[m]; //memory allocation for no of rows
    for(int i=0; i<m; i++){
        A[i] =new int[n]; 
        for(int j=0; j<n; j++) //iterate index
        cin>>A[i][j];
    }
   return A; 
}
void display(int **A,int m,int n, const char* name){  
    cout<<name<<":"<<endl; 
    for(int i=0; i< m ; i++){
        for(int j=0; j<n; j++)
        cout<<A[i][j]<<"\t"; // display all element row by row
        cout<<"\n";
    }
}
void deallocate (int **A, int m){     // memory allo. for double pointer, pointer to pointer 
for(int i=0; i<m; i++) 
delete A[i];  //delete all colm till n-1
delete[]A;   
}

// for addition////
int** add(int **A,int **B,int m,int n){ //**a represnt 1st matrix,**b second , c is ans
int **C= new int*[m]; 
for(int i=0; i<m; i++){
    C[i]= new int[n]; //new n column after evaluatiom
    for(int j=0; j<n; j++)
    C[i][j] = A[i][j] + B[i][j];
}
return C;
}

///////for subtraction//////
int** subtract(int **A,int **B,int m,int n){ //**a represnt 1st matrix,**b second
int **C= new int*[m]; // final ans
for(int i=0; i<m; i++){
    C[i]= new int[n]; //new n column after evaluatiom
    for(int j=0; j<n; j++)
    C[i][j] = A[i][j] - B[i][j];
}
return C;
}

///// for multiplication////////
int** multiply(int **A,int **B,int m1,int n1,int n2){  //m1n1,m1n2
int **C=new int*[m1];  
for(int i=0; i<m1; i++){
    C[i] = new int[n2];
    for(int j=0; j<n2; j++){
        C[i][j] =0; 
        for(int k=0; k<n1; k++)
        C[i][j] += A[i][k] * B[k][j]; //multi and add
    }
}
return C;
}
/////// transpose ////////
int** transpose(int **A,int m, int n){  // m=n, n=m
    int **B = new int* [n];
    for(int i=0; i<n;i++){
        B[i]= new int[m];
        for(int j=0;j<m; j++){
        B[i][j] = A[j][i];   //just swap r and c 
     }
    }
    return B;
}

int main(){  
 int ch=0;
 do{
     system("cls"); 
     cout<<"\n. Matrix operaton option";
      cout<<"\n\t1. addition";
       cout<<"\n\t2. subtraction";
        cout<<"\n\t3. multiplication";
         cout<<"\n\t4. transpose";
         cout<<"\n\t5. exit";
         cout<<"\n\t enter the choice of operation:>>";
    cin>>ch;
  int m1, n1, m2, n2;
  int **X, **Y, **Z;
  switch (ch)
  {
   //addition//
case 1:
  cout<<"enter the order of matrix(M x N) :";
  cin>>m1>>n1;
  X=read(m1,n1,"matrix X");
  Y=read(m1, n1,"matrix Y");
  Z = add(X,Y,m1,n1);
  display(X, m1, n1, "Matrix X");
   display(Y, m1, n1, "Matrix Y");
    display(Z, m1, n1, "Matrix Z");
    deallocate(X, m1);
    deallocate(Y, m1);
    deallocate(Z, m1);
      break;

///subtraction//
case 2:
  cout<<"enter the order of matrix(M x N) :";
  cin>>m1>>n1;
  X=read(m1,n1,"matrix X");
  Y=read(m1, n1,"matrix Y");
  Z = subtract(X,Y,m1,n1);
  display(X, m1, n1, "Matrix X");
   display(Y, m1, n1, "Matrix Y");
    display(Z, m1, n1, "Matrix Z");
    deallocate(X, m1);
    deallocate(Y, m1);
    deallocate(Z, m1);
      break;

/////multiplication////
 case 3: 
      cout<<"enter order of matrix X (M x N): ";
      cin>>m1>>n1;
      X=read(m1,n1,"Matrix X");
      cout<<"enter order of matrix y(M x N): ";
      cin>>m2>>n2;
      Y=read(m2, n2, "matrix Y");
      if(n1==m2){ //  c of x = r of y
      Z = multiply (X,Y,m1,n1,n2);
      display(X,m1,n1,"matrix X");
      display(X,m2,n2,"matrix Y");
      display(Z,m1,n2,"matrix Z=X*Y");
      deallocate(X, m1);
       deallocate(Y, m2);
        deallocate(Z, m1);
      }
      else{
          cout<<"\n NOt possible to multiply these matrix as column should be equal to row";
          deallocate(X,m1);
          deallocate(Y,m2);
      }
         break;
       //// /// transpose///
case 4:
    cout<<"enter the order of atrix X (M x N):";
    cin>>m1>>n1;
    X=read(m1, n1, "matrix X");
    Y = transpose(X,m1,n1);
    display(X,m1,n1,"matrix X");
     display(Y,n1,m1,"matrix Y=X`");
     deallocate(X, m1);
     deallocate(Y,n1);
     break;
 ////////exit////////
case 5:
   cout<<"\n stop the process...";
   break;

  default:
  cout<<"\n invalid entery !!! chose option between 1 to 5";
    
  }
  getch();
 }while(1);
}


