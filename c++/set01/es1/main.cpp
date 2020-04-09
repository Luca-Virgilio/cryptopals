#include <iostream>
#include <string>
#include "Hex.h"
#include "Buffer.h"

using namespace std;
static const unsigned char base64_table[65] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/**
* base64_encode - Base64 encode
* @src: Data to be encoded
* @len: Length of the data to be encoded
* @out_len: Pointer to output length variable, or %NULL if not used
* Returns: Allocated buffer of out_len bytes of encoded data,
* or empty string on failure
*/
std::string base64_encode(const unsigned char *src, size_t len)
{
    unsigned char *out, *pos;
    const unsigned char *end, *in;

    size_t olen;

    olen = 4*((len + 2) / 3); /* 3-byte blocks to 4-byte */

    if (olen < len)
        return std::string(); /* integer overflow */

    std::string outStr;
    outStr.resize(olen);
    out = (unsigned char*)&outStr[0];

    end = src + len;
    in = src;
    pos = out;
    while (end - in >= 3) {
        *pos++ = base64_table[in[0] >> 2];
        *pos++ = base64_table[((in[0] & 0x03) << 4) | (in[1] >> 4)];
        *pos++ = base64_table[((in[1] & 0x0f) << 2) | (in[2] >> 6)];
        *pos++ = base64_table[in[2] & 0x3f];
        in += 3;
    }

    if (end - in) {
        *pos++ = base64_table[in[0] >> 2];
        if (end - in == 1) {
            *pos++ = base64_table[(in[0] & 0x03) << 4];
            *pos++ = '=';
        }
        else {
            *pos++ = base64_table[((in[0] & 0x03) << 4) |
                (in[1] >> 4)];
            *pos++ = base64_table[(in[1] & 0x0f) << 2];
        }
        *pos++ = '=';
    }

    return outStr;
}

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
string res="SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
string str3 = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
hex2.init(str3);
// Hex hex4=hex1;
// Hex hex5 (hex2);
// cout << hex2.getLength()<< endl;
// cout << hex2.getBuffer()<< endl;
Buffer buffer;
buffer.from(hex2);
// cout << buffer.getLength() << endl;
// cout << *(buffer.getPointer()) << ' ';
// cout << *(buffer.getPointer()+1) << ' ';
// cout << *(buffer.getPointer()+2) << ' ';
// cout << *(buffer.getPointer()+3) << endl;

// const char* p = str3.c_str();
// string b = base64_encode(reinterpret_cast<const unsigned char*>(p),str3.size());
string b =buffer.toBase64();
if(b.compare(res)==0){
    cout << "exercise completed!!!" << endl;
} else cout << "error" << endl;
    return 0;
}