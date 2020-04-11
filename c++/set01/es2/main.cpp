#include <iostream>
#include "../../libs/Buffer.h"
#include "../../libs/Hex.h"
using namespace std;

void xorBuffer (Buffer &b1, Buffer &b2){
    if(b1.getLength() != b2.getLength()){
        return;
    }
    Buffer::byte *pos;
    pos = b1.getPointer();
    for (int i=0; i<b1.getLength();i++){
        *pos=b1[i]^=b2[i];
        pos++;
    }
    
}

int main (int argc, char *argv[]){

    string s1="1c0111001f010100061a024b53535009181c";
    string s2="686974207468652062756c6c277320657965";
    string sRes="746865206b696420646f6e277420706c6179";
    cout << "s1= " << s1 << endl;
    cout << "s2= " << s2 << endl;

    Hex h1 (s1, s1.size());
    Hex h2 (s2, s2.size());

    Buffer b1, b2;
    b1.from(h1);
    b2.from(h2);
    xorBuffer(b1,b2);
    // Hex res = b1.toHex();
    // for (unsigned int i= 0; i<res.getLength(); i++){
    //     cout << res[i];
    // }
    string res = b1.toHexString();
    
    if(sRes.compare(res)==0){
        cout << "exercise completed!!!" << endl;
    } else {
        cout << "res=   " << res << endl;
        cout << "resEx= " << sRes << endl;

    }

    return 0;
}

