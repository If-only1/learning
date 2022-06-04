#include<iostream>
#include<fstream>
#include<filesystem>
namespace fs=std::filesystem;
using namespace std;
int main(){
    fs::path p1{"test.txt"};
    cout<<p1<<endl;
    fstream out1{p1,ios::out|ios::app};
    char c;
    while (!cin.get(c).eof()){
        out1.put(c);
    }
    out1.close();
    fstream in1{p1,ios::in};
    while(!in1.get(c).eof()){
        cout<<c;
    }
    in1.close();
    return 0;
} 


