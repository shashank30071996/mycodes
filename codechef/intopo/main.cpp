#include <bits/stdc++.h>
/*1) Scan the given expression from left to right.
2) First operator seen is simply pushed onto stack.
3) If we see an operand, append it to the postfix expression.
4) If we see an operator (x), pop off all the operators which are of lower precedence than 'x' and append them to the postfix expression. Then, push the operator 'x' onto stack.
5) If we see an opening parenthesis, simply push it onto stack.
6) If we see a closing parenthesis, pop off all elements from stack till opening parenthesis and append them to postfix expression except the opening & closing parenthesis.
7) Finally, pop off all the elements (operators) from stack till it's empty and append them to postfix expression.*/
using namespace std;
string infixtopost(string e);
bool IsOperator(char C);
bool IsOperand(char C);
int hashigher(char op1,char op2);
int weight(char c);
int IsRight(char c);
void print(stack<char> &s);
int main()
{
    string s;
    cout << "Hello world!" << endl;
    cin>>s;
    string post=infixtopost( s);
    cout<<"the postfix expression is "<<post<<endl;
    return 0;
}
string infixtopost(string e)
{
    stack<char> s;
    string post="";
    for(int i=0;i<e.length();i++)
    {
        cout<<post<<" "<<i<<endl;
        if(e[i]==' ')
            continue;
        else if(e[i]=='(')
                    s.push(e[i]);
        else if(IsOperand(e[i]))
        {
            post=post+e[i];
        }
        else if(IsOperator(e[i]))
        { cout<<post<<" "<<i<<endl;
           print(s);
           cout<<endl;
            while(!s.empty() && s.top()!='(' && hashigher(s.top(),e[i]))
            {
                print(s);
                cout<<endl;
                post=post+s.top();
                s.pop();
            }
            s.push(e[i]);
        }
        else if(e[i]==')')
        {
            while(!s.empty()&& s.top()!='(')
            {
                post=post+s.top();
                s.pop();
            }
            s.pop();
        }

    }
    while(!s.empty() ){
        post=post+s.top();
        s.pop();
    }
    return post;
}

bool IsOperand(char C)
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}

int hashigher(char op1, char op2)
{
    int g1=weight(op1);
    int g2=weight(op2);
    if(g1 == g2)
	{
		if(IsRight(op1)) return false;
		else return true;
	}
	return g1>g2?true:false;
}
int weight(char c)
{
    int w=-1;
    switch(c)
    {
    case '+':
    case '-':
        w=1;
    case '*':
    case '/':
        w=2;
    case '$':
        w=3;
    }
    return w;
}
int IsRight(char c)
{
    if(c == '$') return true;
	return false;
}
void print(stack<char> &s)
{
    if(s.empty())
    {
        cout << endl;
        return;
    }
    char x= s.top();
    s.pop();
    print(s);
    s.push(x);
    cout << x << " ";
 }
