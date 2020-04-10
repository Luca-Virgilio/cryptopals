#include "Hex.h"

Hex::Hex(std::string s, int len){
    buffer = new char [len];
    if(isValid(s,len)){
        s.copy(buffer,len);
        length=len;

    }
}
Hex::Hex(void) {
    length=128;
    buffer = new char[length];
}
Hex::Hex(const Hex& str){
    length = str.getLength();
    char *pointer = str.getBuffer();
    buffer = new char[length];

    for(uint i=0; i<length; i++){
        *(buffer+i)=*(pointer+i);
    }
}
Hex&Hex::operator=(const Hex &Y){
    if(&Y!=this){
        length = Y.getLength();
        char *pointer = Y.getBuffer();
        buffer = new char[length];

        for(uint i=0; i<length; i++){
            *(buffer+i)=*(pointer+i);
        }
    }
    return *this;
}


Hex::~Hex(void) {
    delete [] buffer;
    buffer = 0;
}

bool Hex::isValid(std::string &s, int len) {
    bool flag = true;
    int temp;
    for(int i=0; flag && i<len; i++){
        temp =static_cast<int>(s[i]);
        flag = (47<temp && temp<58) || (96<temp && temp<103);
    }
    return flag;
}

void Hex::init(std::string &s){
    if(isValid(s, s.size())&& s.size()<=128){
        length=s.size();
        s.copy(buffer,length);
        
    }
}

unsigned int Hex::getLength(void) const {
    return length;
}
char* Hex::getBuffer(void) const {
    return buffer;
}
char &Hex::operator[](unsigned int i)const{
    return *(buffer+i);
}
