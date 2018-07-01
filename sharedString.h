#pragma once
#include <istream>

namespace nsfw {
class sharedString
{
    char* m_str = nullptr;
    unsigned int m_length = 0;
    unsigned int m_refCount = 0;
    unsigned int getLength(const char* _str);
    void setString(const char* _str);
    friend std::ostream& operator<< (std::ostream& out, const sharedString& _sharedString);
    friend std::istream& operator>> (std::istream& in, sharedString& _sharedString);
public:
    sharedString();
    sharedString(const char* _str);
    ~sharedString();
    unsigned int size();
    sharedString& operator= (const char* _other);
    const char* c_str() const;
    bool operator== (const sharedString& _sharedString);
    bool operator!= (const sharedString& _sharedString);
    sharedString operator+ (const sharedString& _sharedString);
};
std::ostream& operator<< (std::ostream& out, const sharedString& _sharedString);
std::istream& operator>> (std::istream& in, sharedString& _sharedString);
}
