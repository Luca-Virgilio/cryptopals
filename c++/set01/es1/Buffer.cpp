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
    length = (str.getLength()-1)/2;
    int b;
    //padding?
    Buffer::byte *p_temp = pointer;
    for(int i=0;i<str.getLength()-1;i=i+2){
        if(i+1<str.getLength()-1){
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