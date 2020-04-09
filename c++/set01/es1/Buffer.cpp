#include "Buffer.h"

Buffer::Buffer(void){
    length = 0;
    pointer = new byte [64];
}
Buffer::~Buffer(void){
    delete [] pointer;
    pointer=NULL;
}

int Buffer::getLength(void)const{
    return length;
}
Buffer::byte* Buffer::getPointer(void)const{
    return pointer;
}
void Buffer::from(Hex &str){
    //to check
    length = (str.getLength()+1)/2;
    int b;
    //padding?
    Buffer::byte *p_temp = pointer;
    for(int i=0;i<str.getLength()-1;i=i+2){
        if(i+1<str.getLength()){
            *(p_temp)= char_to_byte(str[i],str[i+1]);
            p_temp++;

        } else {
            *(p_temp)= char_to_byte(str[i],'0');
            p_temp++;
        }
    }
}

Buffer::byte Buffer::char_to_byte(char c1, char c2){
  Buffer::byte b1 (hex_to_int(c1));
  Buffer::byte b2 (hex_to_int(c2));
  b1=b1<<4;
  //or?
  for (int i=0;i<4;i++){
      b1[i]=b2[i];
  }
  return b1; 
}
// to change
int Buffer::hex_to_int(char c){
      int v = static_cast<int>(c);
    if(47<v && v<58){
        v=v-48;
    }else{
        v=v-87;
    }
    return v;
}

std::string Buffer::toBase64(void){
    static const unsigned char base64_encode[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    unsigned char *pos, *out;
    byte *end, *in;

    size_t olen;

    olen = 4*((length + 2) / 3); /* 3-byte blocks to 4-byte */

    if (olen < length)
        return std::string(); /* integer overflow */

    std::string outStr;
    outStr.resize(olen);
    out = (unsigned char*)&outStr[0];

    end = pointer + length;
    in = pointer;
    pos = out;
    while (end - in >= 3) {
        *pos++ = base64_encode[(*in >> 2).to_ulong()];
        *pos++ = base64_encode[(((*in &= 0x03) << 4) | (*(in+1) >> 4)).to_ulong()];
        *pos++ = base64_encode[(((*(in+1) &= 0x0f) << 2) | (*(in+2) >> 6)).to_ulong()];
        *pos++ = base64_encode[(*(in+2) &= 0x3f).to_ulong()];
        in += 3;
    }

    if (end - in) {
        *pos++ = base64_encode[(*in >> 2).to_ulong()];
        if (end - in == 1) {
            *pos++ = base64_encode[((*in &= 0x03) << 4).to_ulong()];
            *pos++ = '=';
        }
        else {
            *pos++ = base64_encode[(((*in &= 0x03) << 4) | (*(in+1) >> 4)).to_ulong()];
            *pos++ = base64_encode[((*(in+1) &= 0x0f) << 2).to_ulong()];
        }
        *pos++ = '=';
    }

    return outStr;
}