#include <iostream>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

int rpn(const vector<string>& input){
    stack<int> Stos;
    for (const auto& w : input){
        if (w == "+") {
           int a=Stos.top();
           Stos.pop();
            int b=Stos.top();
            Stos.pop();
            Stos.push(b+a);
        }
        else if (w == "-"){
            int a=Stos.top();
            Stos.pop();
            int b=Stos.top();
            Stos.pop();
            Stos.push(b-a);
        }
        else if (w == "*"){ 
           int a=Stos.top();
           Stos.pop();
            int b=Stos.top();
            Stos.pop();
            Stos.push(b*a);
        }
        else if (w == "/"){
           int a=Stos.top();
           Stos.pop();
            int b=Stos.top();
            Stos.pop();
            Stos.push(b/a);
    }
    else {
        Stos.push(stoi(w));
    }
} 
return Stos.top();
}

int main(){
vector<string> input { "2", "3",  "+" , "6" , "*" };
assert( rpn(input) == 30 );
return 0;
}


