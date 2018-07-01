#pragma once
#include <istream>

namespace nsfw {
class sharedString
{
    char* m_str;
    unsigned int m_length;
    unsigned int m_refCount = 0;
    unsigned int getLength(const char* _str);
    void setString(const char* _str);
    void setString(const char* _str, unsigned int _size);
    friend std::ostream& operator<< (std::ostream& out, const sharedString& _sharedString);
    friend std::istream& operator>> (std::istream& in, sharedString& _sharedString);
public:
    sharedString();
    sharedString(const sharedString& _other);
    sharedString(const char* _str);
    sharedString(const char* _str, unsigned int _size);
    ~sharedString();
    unsigned int size() const;
    sharedString& operator= (const char* _other);
    const char* c_str() const;
    bool operator== (const sharedString& _sharedString) const;
    bool operator!= (const sharedString& _sharedString) const;
    sharedString operator+ (const sharedString& _sharedString) const;
    char& operator[] (unsigned int _index);
    char operator[] (unsigned int _index) const;
};
std::ostream& operator<< (std::ostream& out, const sharedString& _sharedString);
std::istream& operator>> (std::istream& in, sharedString& _sharedString);
}
