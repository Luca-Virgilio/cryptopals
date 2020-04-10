#include <iostream>
#include <string>
#include "../../libs/Hex.h"
#include "../../libs/Buffer.h"

using namespace std;

int main (int argc, char * argv[]){

string res="SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
string str3 = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
Hex hex2; 
hex2.init(str3);

Buffer buffer;
buffer.from(hex2);

string b =buffer.toBase64();
if(b.compare(res)==0){
    cout << "exercise completed!!!" << endl;
} else cout << "error" << endl;
    return 0;
}