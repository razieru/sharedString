#pragma once
#include <istream>

namespace nsfw {
class sharedString
{
    char* m_str;
    unsigned int m_length;
    unsigned int *m_refCount = nullptr;
    unsigned int getLength(const char* _str);
    void setString(const char* _str);
    void setString(const char* _str, unsigned int _size);
    void copyString(const char* _str, unsigned int _size);
    void setNewRef(const sharedString& _other);
    void breakaway();
public:
    sharedString();
    sharedString(const sharedString& _other);
    sharedString(const char* _str);
    sharedString(const char* _str, unsigned int _size);
    ~sharedString();
    unsigned int size() const;
    const unsigned int* use_count() const;
    sharedString& operator= (const char* _other);
    sharedString& operator= (const sharedString& _other);
    const char* c_str() const;
    bool operator== (const sharedString& _sharedString) const;
    bool operator!= (const sharedString& _sharedString) const;
    sharedString operator+ (const sharedString& _sharedString) const;
    char& operator[] (unsigned int _index);
    char operator[] (unsigned int _index) const;
    friend std::ostream& operator<< (std::ostream& out, const sharedString& _sharedString);
    friend std::istream& operator>> (std::istream& in, sharedString& _sharedString);
};
std::ostream& operator<< (std::ostream& out, const sharedString& _sharedString);
std::istream& operator>> (std::istream& in, sharedString& _sharedString);
}
