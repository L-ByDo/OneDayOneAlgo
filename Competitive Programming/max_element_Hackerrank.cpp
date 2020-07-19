#include<iostream>
using namespace std;
#include<stack>
int main(){
    long int n,q,num,top;
    cin>>n;
    stack<long int>s;
    stack<long int>maxStack;
    maxStack.push(-1);
    while(n>0){
        cin>>q;
        if(q==1){
            cin>>num;
                s.push(num);   //this will always be pushed
            if(num>=maxStack.top()){  //if number is greater than top,then push into it
                maxStack.push(num);
            }
            
        }
        else if(q==2){
            if(maxStack.top()==s.top()){  //if both top elements are same, means we need to pop that same element because that cant be our answer anymore
                maxStack.pop();
            }
            s.pop();  //this will alwys be popped out
        }
        else{
            
            top=maxStack.top();
            cout<<top<<"\n";
        }
        n--;
    }
}
