#include "Buffer.h"

/**************************  constructors and distructor   **************************/

Buffer::Buffer(void){
    length = static_cast<uint>(0);
    pointer = new byte [64];
}

Buffer::~Buffer(void){
    delete [] pointer;
    pointer=NULL;
}
/**************************  getter and setter   **************************/

int Buffer::getLength(void)const{
    return static_cast<int>(length);
}
Buffer::byte* Buffer::getPointer(void)const{
    return pointer;
}

/**************************  operator  **************************/

Buffer&Buffer::operator=(const Buffer &Y){
    if(&Y!=this){
        length = Y.getLength();
        byte *pointerY = Y.getPointer();
        pointer = new byte[length];

        for(uint i=0; i<length; i++){
            *(pointer+i)=*(pointerY+i);
        }
    }
    return *this;
}

Buffer::byte &Buffer::operator[](unsigned int i)const{
    return *(pointer+i);
}
//**************************     methods     **************************//

void Buffer::from(const std::string &str){
    if(str.size()>64){
        return ;
    }
    length = str.size();
    const char *end, *pos;
    pos = &str[0];
    end = pos + length;
    byte *out= pointer;

    for( ; pos!=end; pos++){
        *out = byte(static_cast<int>(*pos));
        out++;
    }

}


void Buffer::from(Hex &str){
    //to check
    length = (str.getLength()+1)/2;
    //padding?
    byte *p_temp = pointer;
    for(uint i=0;i<str.getLength();i=i+2){
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
  byte b1 (hex_to_int(c1));
  byte b2 (hex_to_int(c2));
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

std::string Buffer::toBase64(void) const{
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

std::string Buffer::toString(void)const {
    
    std::string outStr;
    outStr.resize(length);
    char *out= &outStr[0];
    byte *pos, *end;
    pos = pointer;
    end = pos + length;
    while(end-pos>0){
        *out=static_cast<char>((*pos).to_ulong());
        pos++;
        out++;
    } 
    return outStr;

}

Hex Buffer::toHex(void)const {
    static const char encode_hex[17]= "0123456789abcdef";

    std::string outStr;
    outStr.resize(length*2);
     char *out= &outStr[0];
     char *start_out= out;
    byte *pos, *end;
    pos = pointer;
    end = pos + length;
    while(end-pos>0){
        *out= encode_hex[(*pos >> 4).to_ulong()];
        *(out+1)=  encode_hex[(*pos &= 0xf).to_ulong()];
        pos++;
        out=out+2;
    } 
    Hex res(start_out, length*2);
    return res;
}

std::string Buffer::toHexString(void)const {
    static const char encode_hex[17]= "0123456789abcdef";

    std::string outStr;
    outStr.resize(length*2);
    char *out= &outStr[0];
    byte *pos, *end;
    pos = pointer;
    end = pos + length;
    while(end-pos>0){
        *out= encode_hex[(*pos >> 4).to_ulong()];
        *(out+1)=  encode_hex[(*pos &= 0xf).to_ulong()];
        pos++;
        out=out+2;
    } 
    return outStr;

}

