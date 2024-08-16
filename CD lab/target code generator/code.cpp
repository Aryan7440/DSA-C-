#include <bits/stdc++.h>
using namespace std;
vector<char>A={'X','A','B','C','D','E','F'};
vector<string>RES;
unordered_map<char,char>S;
int j=0;
void MOV(char a,char b){
    string temp="MOV ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void DIV(char a,char b){
    string temp="DIV ";
    temp+=a;
    temp+=char(32);
    temp+=b;
    RES.push_back(temp);
}
void MULT(char a,char b){
    string temp="MUL ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void ADD(char a,char b){
    string temp="ADD ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
}
void SUB(char a,char b){
    string temp="SUB ";
    temp+=b;
    temp+=char(32);
    temp+=a;
    RES.push_back(temp);
    // RES.push_back("SUB "+a+' '+b);
}
void convert(string s){
    for(int i=0;i<s.length();i++){
        if(int(s[i])>=97&&int(s[i])<=122){
            S[s[i]]=A[j];
            j++;
            
        }
        
    }
    cout<<endl;
    for(int i=0;i<s.length();i++){
        if(s[i]=='/'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            DIV(S[s[i-1]],S[s[i+1]]);
        }
        
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='*'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            MULT(S[s[i-1]],S[s[i+1]]);
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            ADD(S[s[i-1]],S[s[i+1]]);
        }
        
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            MOV(s[i-1],S[s[i-1]]);
            MOV(s[i+1],S[s[i+1]]);
            SUB(S[s[i-1]],S[s[i+1]]);
        }
    }
    MOV(s[0],S[s[0]]);
}
void show(){
    for(int i=0;i<RES.size();i++){
        bool b=false;
        for(int j=0;j<i;j++){
            if(RES[j]==RES[i])
              b=true;
        }
        if(b==false){
            cout<<RES[i]<<endl;
        }
    }
}
int main(){
    
    cout<<"Enter a expression"<<endl;
    string s;
    cin>>s;
    convert(s);
    show();
    
    return 0;

}