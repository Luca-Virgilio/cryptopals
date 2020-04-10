#ifndef Hex_H
#define Hex_H
#include <string>

class Hex {
    unsigned int length;
    char *buffer; 
public:    
    Hex(void);
    Hex(std::string s, int len);
    Hex(const Hex& str);
    Hex &operator=(const Hex &Y);
    ~Hex(void);
    bool isValid(std::string &s, int len);
    void init(std::string &s);
    unsigned int getLength(void) const;
    char* getBuffer(void) const;
    char &operator[](unsigned int i)const;



};


#endif