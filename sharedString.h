#pragma once
#include <istream>

namespace nsfw {
/*!
    \brief Класс-строка с разделяемыми ресурсами

    Подсчитывает ссылки для экономии памяти.
*/
class sharedString
{
    //! Искомая строка
    char* m_str;
    //! Длина строки
    unsigned int m_length;
    //! Количество ссылающихся на строку -1
    unsigned int *m_refCount = nullptr;
    //! Подсчёт длины строки до терминального нуля
    unsigned int getLength(const char* _str);
    //! Установка строки не зная длины строки
    void setString(const char* _str);
    //! Установка строки зная длину стоки
    void setString(const char* _str, unsigned int _size);
    //! Копирование содержимого строки к себе
    void copyString(const char* _str, unsigned int _size);
    /*!
     * Ссылаться на строку другого объекта
     * \param _other Объект, с которым надо делить ресурсы
     */
    void setNewRef(const sharedString& _other);
    //! Отвязаться от общих ресурсов
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
