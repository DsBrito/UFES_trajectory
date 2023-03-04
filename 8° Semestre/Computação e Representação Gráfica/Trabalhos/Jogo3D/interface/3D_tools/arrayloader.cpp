
#include "arrayloader.h"

/*Arquivo criado para modularizar o código (auto_array) e tratar a parte de array separado, retirado de
    trechos de código presente no laboratório de Animação e Modelos,  extamente igual ao auto_array do arquivo imageloader.cpp aproximadamente linha 47
*/

auto_array::auto_array(const auto_array &aarray)
{
    array = aarray.array;
    isReleased = aarray.isReleased;
    aarray.isReleased = true;
}

auto_array::~auto_array()
{
    if (!isReleased && array != nullptr)
    {
        delete[] array;
    }
}

char *auto_array::get() const
{
    return array;
}

char &auto_array::operator*() const
{
    return *array;
}

auto_array &auto_array::operator=(const auto_array &aarray)
{
    if (&aarray != this)
    {
        if (!isReleased && array != nullptr)
        {
            delete[] array;
        }
        array = aarray.array;
        isReleased = aarray.isReleased;
        aarray.isReleased = true;
    }

    return *this;
}

char *auto_array::operator->() const
{
    return array;
}

char *auto_array::release()
{
    isReleased = true;
    return array;
}

char *auto_array::operator+(int i)
{
    return array + i;
}

char &auto_array::operator[](int i)
{
    return array[i];
}
