
#ifndef Buffer_H
#define Buffer_H
#include "Hex.h"
#include <bitset>
#include <string>

class Buffer {
public:
    typedef std::bitset<8> byte;
    // typedef unsigned int uint;
private:    
    uint length;
    byte *pointer;
    byte char_to_byte(char c1, char c2);
    int hex_to_int(char c);
public:
    Buffer(void);
    ~Buffer(void);
    int getLength(void)const;
    byte* getPointer(void)const;
    Buffer &operator=(const Buffer &Y);
    byte &operator[](unsigned int i)const;
    void from(Hex &str);
    void from(const std::string &str);
    std::string toBase64(void)const;
    std::string toString(void)const;
    Hex toHex(void)const;
    std::string toHexString(void)const;

    
};

#endif