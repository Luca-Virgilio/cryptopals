#include <iostream>
#include <bitset>
#include <string>
#include "Hex.cpp"

using namespace std;

int main (int argc, char * argv[]){
/**
    // string test = "ciao";
    int a =254;
    // char c = 'c';
    string p = bitset<8>(a).to_string();
    cout << hex << a << dec << endl;
    // cout << static_cast<int>(c) << endl;
    cout << p << endl;
    bitset<8> value(a);
    cout << value << endl;
    cout << value[0] << endl;
    //transform string in char []
    // char sss [test.size()+1];
    // test.copy(sss, test.size() +1);
    // cout << sss << endl;
**/
string str1="a13";
string str2="app";

Hex hex2; 
Hex hex1(str1,str1.size());
string str3 = "ff";
hex2.init(str3);

cout << hex1.getLength() << endl;
cout << hex1.getBuffer() << endl;
cout << hex2.getLength() << endl;
cout << hex2.getBuffer() << endl;
    return 0;
}