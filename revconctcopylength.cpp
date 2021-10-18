//Program-5: WAP to implement the various operations on string such as 
//a) length of string b) concatenation c) reverse a string d) copy a string
#include<iostream>
#include<string>
using namespace std;
class string_function
{
    string a,b,c,d,s1,s2,s3,ss;
    int i,j,n,length,w;
    public:
    void length_of_string()
    {	cout<<"\n\n...Length of string...\n\n";
        length=0;
        cout<<"Enter string=\n";

        cin>>a;
        for(i=0;a[i]!='\0';i++)
            {
                length++;
            }
        cout<<"Length of string=\t"<<length;
    }
    void concatenation()
    {	cout<<"\n\n...Concatination Operation...\n\n";

        cout<<"\nEnter string 1=\t";
        cin>>b;
        cout<<"\nEnter string 2=\t";
        cin>>c;
        //cout<<"\nYour entered strings are=\n"<<b<<"\n"<<c;
        n=0;
        for(i=0;b[i];i++)
        {
            d[n]=b[i];
            n++;
        }
        for(j=0;c[j];++j)
        {
            d[n]=c[j];
            n++;
        }
        cout<<"\nResultant string=\t\t";
        for(i=0;d[i];i++)
        {
                    cout<<d[i];
        }
    }
    void  copy()
    {
        cout<<"\n\n...Copy operation...\n\n";
        cout<<"\nEnter string=\t";
        cin>>s1;
        length=0;
        for(i=0;s1[i]!='\0';i++)
            {
                length++;
            }

        for(i=0;i<length;i++)
                    {
                        s2=s1;
                    }
            cout<<"\nCopied string=\t";

            cout<<s2;
    }
    void reverse()
    {
        cout<<"implementing Reverse of string ";
        cout<<"\n\nEnter string=";
        cin>>s3;
        length=0,w=0;
        for(i=0;s3[i]!='\0';i++)
        {
                        length++;
        }
        for(i=length-1;i>=0;i--,w++)
        {
            ss[w]=s3[i];
        }
        cout<<"\n reversed=";

        for(i=0;i<w;i++)
        cout<<ss[i];
    }
    
    
};
   int main()
{
    string_function s;
    char ans;
    int ch;
    do

    {
        cout<<"\t\tMEnu\n\n";
        cout<<"1)Length\n2)Concatination\n3)reverse\n4)copy\n\nenter your choice (1-4)=\t";
        cin>>ch;
        switch(ch)
        {
            case 1 :s.length_of_string(); break;
            case 2 :s.concatenation();	break;
            case 3 :s.reverse();	break;
            case 4 :s.copy();	break;
            default:cout<<"\n wrong selection..!!\n";
        }
    cout<<"\n\n want try more operation(Y/N)=";
    cin>>ans;
    }while(ans=='Y'||ans=='y');
    return 0;
}