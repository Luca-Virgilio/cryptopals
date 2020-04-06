#include <iostream>
#include <string>
#include "Hex.h"
#include "Buffer.h"

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

Hex hex2; 
Hex hex1(str1,str1.size());
string str3 = "a210ff";
hex2.init(str3);
Hex hex4=hex1;
Hex hex5 (hex2);
cout << hex2.getLength()<< endl;
cout << hex2.getBuffer()<< endl;
Buffer buffer;
buffer.from(hex2);
cout << buffer.getLength() << endl;
cout << *(buffer.getPointer()) << ' ';
cout << *(buffer.getPointer()+1) << ' ';
cout << *(buffer.getPointer()+2) << ' ';
cout << *(buffer.getPointer()+3) << endl;


    return 0;
}