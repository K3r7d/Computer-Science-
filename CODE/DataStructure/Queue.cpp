#include<iostream>
#include<string>
#include<queue>

using namespace std;


int prefix(string *t, int size){
    queue<int> q;
    for(int i = 0; i < size; i++){
        if(t[i] == "+" || t[i] == "-"){
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            if(t[i] == "+") q.push(a+b);
            else if(t[i] == "-") q.push(a-b);
        }
        else{
            q.push(stoi(t[i]));
        }
    }
    return q.front();
}

int main(){
    string t[] = {"-","+","2","-","9","6","4"};
    cout<<prefix(t,7); // answer = -5
    return 0;
}
