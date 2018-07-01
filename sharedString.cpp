#include "sharedString.h"

unsigned int nsfw::sharedString::getLength(const char *_str)
{
    unsigned int _size = 0;
    while (_str[_size] != '\0') ++_size;
    return _size;
}

void nsfw::sharedString::setString(const char *_str)
{
    if (m_str != nullptr)
        delete[] this->m_str;
    m_length = getLength(_str);
    m_str = new char[m_length+1];
    for (unsigned int i = 0; i < m_length; ++i)
        m_str[i] = _str[i];
    m_str[m_length] = '\0';
}

bool nsfw::sharedString::operator ==(const nsfw::sharedString &_sharedString)
{
    if (this->m_length != _sharedString.m_length)
        return false;
    for (unsigned int i = 0; i < this->m_length; ++i) {
        if (this->m_str[i] != _sharedString.m_str[i])
            return false;
    }
    return true;
}

nsfw::sharedString::sharedString()
{
    if (m_str != nullptr)
        delete[] m_str;
    m_str = nullptr;
}

nsfw::sharedString::sharedString(const char *_str)
{
    setString(_str);
}

nsfw::sharedString::~sharedString()
{
    if (m_refCount == 0)
        delete[] m_str;
}

nsfw::sharedString &nsfw::sharedString::operator =(const char *_other)
{
    if (m_str != _other)
        setString(_other);
    return *this;
}

const char *nsfw::sharedString::c_str() const
{
    return const_cast<char*>(m_str);
}

unsigned int nsfw::sharedString::size()
{
    return m_length;
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
