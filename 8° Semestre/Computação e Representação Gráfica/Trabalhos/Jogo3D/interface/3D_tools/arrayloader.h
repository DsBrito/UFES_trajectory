

#ifndef ARRAYLOADER_H
#define ARRAYLOADER_H

/*Arquivo criado para modularizar o código (auto_array) e tratar a parte de array separado, retirado de
    trechos de código presente no laboratório de Animação e Modelos,  extamente igual ao auto_array do arquivo imageloader.cpp aproximadamente linha 47
*/
// Just like auto_ptr, but for arrays
//  template <class T>

class auto_array
{
private:
    char *array;
    mutable bool isReleased;

public:
    explicit auto_array(char *array_ = nullptr) : array(array_), isReleased(false)
    {
    }

    auto_array(const auto_array &aarray);

    ~auto_array();

    char *get() const;

    char &operator*() const;

    auto_array &operator=(const auto_array &aarray);

    char *operator->() const;

    char *release();

    char *operator+(int i);

    char &operator[](int i);
};

#endif // ARRAYLOADER
