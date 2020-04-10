#include <iostream>
#include "../libs/Buffer.h"
#include "../libs/Hex.h"

using namespace std;

int main (int argc, char* argv[]){
    
    string s1="90ff1";
    Hex h1 (s1, s1.size());
    cout << "h1 length: " << h1.getLength() << endl;
    cout << "h1 Buffer: " << h1.getBuffer() << endl;

    Buffer b;
    b.from(h1);
    for(int i=0; i<b.getLength();i++){
        cout << *(b.getPointer()+i);
    }
    // Buffer bnull;
    // cout << "b length: " << bnull.getLength() << endl;
    // cout << "b pointer: " << bnull.getPointer() << endl;


    return 0;
}