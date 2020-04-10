
#ifndef Buffer_H
#define Buffer_H
#include "Hex.h"
#include <bitset>
#include <string>

class Buffer {
public:
    typedef std::bitset<8> byte;
private:    
    int length;
    byte *pointer;
    byte char_to_byte(char c1, char c2);
    int hex_to_int(char c);
public:
    Buffer(void);
    ~Buffer(void);
    int getLength(void)const;
    byte* getPointer(void)const;
    void from(Hex &str);
    std::string toBase64(void);
    
};

#endif