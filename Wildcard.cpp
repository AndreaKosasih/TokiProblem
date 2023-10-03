#include <iostream>
using namespace std;

int main() {
    string s; int n; cin >> s >> n; 
    string b = "", f = ""; 
    int current = 0; 
    for(int i = 0; i < s.length(); i++) {
        if(s[i]=='*') current = 1; 
        else if (current==0) b+=s[i];
        else f+=s[i];
    }
    for(int i = 0; i<n; i++) {
        string a; cin >> a; 
        if(a.length()<s.length()-1) continue; 
        bool same = true; 
        for(int j = 0; j<b.length();j++){
            if(b[j]!=a[j]) {
                same = false; 
                break; 
            }
        }
        if(!same) continue; 
        for(int j = 0; j<f.length();j++) {
            if(f[f.length()-1-j]!=a[a.length()-1-j]){
                same = false; 
                break; 
            }
        }
        if(!same) continue; 
        cout << a << endl; 
    }
}
