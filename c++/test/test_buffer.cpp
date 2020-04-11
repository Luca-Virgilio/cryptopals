#include <iostream>
#include "../libs/Buffer.h"
#include "../libs/Hex.h"

using namespace std;

int main (int argc, char* argv[]){
    
    string s1="90ff1";
    Hex h1 (s1, s1.size());
    cout << "h1 length: " << h1.getLength() << endl;
    cout << "h1 Buffer: " << h1.getBuffer() << endl;

// test toString
    // string s2="ciao";
    // Buffer b;
    // b.from(s2);
    // for(int i=0; i<b.getLength();i++){
    //     cout << b[i];
    // }
    // cout << endl;
    // string test = b.toString();
    // if(s2.compare(test)){
    //    cout << "toString correct"<<endl;
    // }

    // test toHex
    Buffer testHex;
    testHex.from(h1);
    Hex isHex = testHex.toHex();
    for (unsigned int i= 0; i<isHex.getLength(); i++){
        cout << isHex[i];
    }
    
    // Buffer bnull;
    // cout << "b length: " << bnull.getLength() << endl;
    // cout << "b pointer: " << bnull.getPointer() << endl;


    return 0;
}
