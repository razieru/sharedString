#include "sharedString.h"

nsfw::sharedString::sharedString()
{
    m_str = nullptr;
    m_length = 0;
    m_refCount = new unsigned int(0);
}

nsfw::sharedString::sharedString(const nsfw::sharedString &_other)
{
    if ((m_refCount != nullptr) && (*m_refCount > 0))
        (*m_refCount)--;
    else {
        m_refCount = (unsigned int*)_other.use_count();
        (*m_refCount)++;
        if (m_str != nullptr)
            delete[] this->m_str;
        m_length = _other.size();
        m_str = (char*)_other.c_str();
    }
}

nsfw::sharedString::sharedString(const char *_str)
{
    setString(_str);
}

nsfw::sharedString::sharedString(const char *_str, unsigned int _size)
{
    setString(_str,_size);
}

unsigned int nsfw::sharedString::getLength(const char *_str)
{
    unsigned int _size = 0;
    while (_str[_size] != '\0') ++_size;
    return _size;
}

void nsfw::sharedString::setString(const char *_str)
{
    setString(_str,getLength(_str));
}

void nsfw::sharedString::setString(const char *_str, unsigned int _size)
{
    if (m_str != nullptr)
        delete[] this->m_str;
    if (m_refCount != nullptr)
        delete m_refCount;
    m_refCount = new unsigned int(0);
    m_length = _size;
    m_str = new char[m_length+1];
    for (unsigned int i = 0; i < m_length; ++i)
        m_str[i] = _str[i];
    m_str[m_length] = '\0';
}

bool nsfw::sharedString::operator ==(const nsfw::sharedString &_sharedString) const
{
    if (this->m_length != _sharedString.m_length)
        return false;
    for (unsigned int i = 0; i < this->m_length; ++i) {
        if (this->m_str[i] != _sharedString.m_str[i])
            return false;
    }
    return true;
}

bool nsfw::sharedString::operator!=(const nsfw::sharedString &_sharedString) const
{
    return !(this->operator==(_sharedString));
}

nsfw::sharedString nsfw::sharedString::operator+(const nsfw::sharedString &_sharedString) const
{
    char* newStr = new char[this->m_length + _sharedString.size() + 1];
    unsigned int i = 0,j = 0;
    for (;j<this->m_length;++j) {
        newStr[i] = this->m_str[j];
        ++i;
    }
    auto _cpStr = _sharedString.c_str();
    for (j=0;j<_sharedString.size();++j) {
        newStr[i] = _cpStr[j];
        ++i;
    }
    newStr[i] = '\0';
    sharedString newSharedString(newStr,i);
    return newSharedString;
}

char& nsfw::sharedString::operator[](unsigned int _index)
{
    return m_str[_index];
}

char nsfw::sharedString::operator[](unsigned int _index) const
{
    return m_str[_index];
}

nsfw::sharedString::~sharedString()
{
    if (m_refCount == 0)
        delete[] m_str;
    else
        (*m_refCount)--;
}

nsfw::sharedString &nsfw::sharedString::operator =(const char *_other)
{
    if (m_str != _other)
        setString(_other);
    return *this;
}

nsfw::sharedString &nsfw::sharedString::operator=(const nsfw::sharedString &_other)
{
    if (m_str != _other.c_str())
        setString(_other.c_str());
    return *this;
}

const char *nsfw::sharedString::c_str() const
{
    return const_cast<char*>(m_str);
}

unsigned int nsfw::sharedString::size() const
{
    return m_length;
}

const unsigned int *nsfw::sharedString::use_count() const
{
    return const_cast<unsigned int*>(m_refCount);
}

std::ostream &nsfw::operator <<(std::ostream &out, const nsfw::sharedString &_sharedString)
{
    return out << _sharedString.m_str;
}

std::istream &nsfw::operator>>(std::istream &in, nsfw::sharedString &_sharedString)
{
    char* tmpStr = new char[500];
    in >> tmpStr;
    _sharedString.setString(tmpStr);
    delete[] tmpStr;
    return in;
}
