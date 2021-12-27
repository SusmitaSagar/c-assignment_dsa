//Write a C++ program that uses stack operations to convert a given
// infix expression into its postfix equivalent.
#include<iostream>
#include<stack>
using namespace std;

//presedence is unique value given to every operator.
int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return 0; 
} 
//boolean
bool isOperator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
//infixToPostfix is user defined function.
string InfixToPostfix(stack<char> st, string infix)//st=stack
{
 string postfix;
 for(int i=0;i<infix.length();i++)
 {
  if((infix[i] >= 'a' && infix[i] <= 'z')
    ||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
		 postfix+=infix[i];
		}
		else if(infix[i] == '(') //opening bracket
		{
		 st.push(infix[i]);
		}
		else if(infix[i] == ')') //closing bracket
		{
		while((st.top()!='(') && (!st.empty()))
			{
				char temp=st.top(); //return top of stack,stored in temp
				postfix+=temp;
				st.pop();
			}
			if(st.top()=='(')
			{
				st.pop(); //removed
			}
		}
		else if(isOperator(infix[i]))
		{
		 if(st.empty())
			{
				st.push(infix[i]);
			}
			else
			{ //presedence is unique value given to every operator
			 if(precedence(infix[i])>precedence(st.top()))
				{
					st.push(infix[i]); 
				}	
			 else if((precedence(infix[i])==precedence(st.top()))&&(infix[i]=='^'))
				{
					st.push(infix[i]);
				}
			 else
				{
				 while((!st.empty())&&( precedence(infix[i])<=precedence(st.top())))
				{
					postfix+=st.top();
					st.pop();
				}
				 st.push(infix[i]);
				}
			}}}
	while(!st.empty())
	{
		postfix+=st.top();
		st.pop();
	}
	return postfix;
}
int main() 
{  
  	string infix_expression, postfix_equivalent;
  	cout<<"Enter your Infix Expression :"<<endl;
  	cin>>infix_expression;
  	stack <char> stack; //predefined stack
	cout<<"INFIX EXPRESSION: "<<infix_expression<<endl;
  	postfix_equivalent = InfixToPostfix(stack, infix_expression);
  	cout<<endl<<"POSTFIX EQUIVALENT: "<<postfix_equivalent;
	return 0;
}