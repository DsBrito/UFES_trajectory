

#include "imageloader.h"
#include "arrayloader.h"

using namespace std;

#include <cassert>

/*Arquivo  enviado pelo professor, extamente igual ao arquivo imageloader.cpp presente no laboratório de Animação e de Modelos.
Apenas estão comentado as partes que não estão sendo utilizadas nesse arquivo.
*/

Image::Image(char *ps, int w, int h) : pixels(ps), width(w), height(h)
{
}

Image::~Image()
{
    delete[] pixels;
}

namespace
{
    int toInt(const char *bytes)
    {
        return (int)(((unsigned char)bytes[3] << 24) |
                     ((unsigned char)bytes[2] << 16) |
                     ((unsigned char)bytes[1] << 8) |
                     (unsigned char)bytes[0]);
    }

    // Converts a two-character array to a short, using little-endian form
    short toShort(const char *bytes)
    {
        return (short)(((unsigned char)bytes[1] << 8) |
                       (unsigned char)bytes[0]);
    }

    // Reads the next four bytes as an integer, using little-endian form
    int readInt(ifstream &input)
    {
        char buffer[4];
        input.read(buffer, 4);
        return toInt(buffer);
    }

    // Reads the next two bytes as a short, using little-endian form
    short readShort(ifstream &input)
    {
        char buffer[2];
        input.read(buffer, 2);
        return toShort(buffer);
    }

    // IREI SEPARAR O AUTOARRAY EM UM NOVO ARQUIVO. <<<<<<<
    /*
     // Just like auto_ptr, but for arrays
     template <class T>
     class auto_array
     {
     private:
         T *array;
         mutable bool isReleased;

     public:
         explicit auto_array(T *array_ = NULL) : array(array_), isReleased(false)
         {
         }

         auto_array(const auto_array<T> &aarray)
         {
             array = aarray.array;
             isReleased = aarray.isReleased;
             aarray.isReleased = true;
         }

         ~auto_array()
         {
             if (!isReleased && array != NULL)
             {
                 delete[] array;
             }
         }

         T *get() const
         {
             return array;
         }

         T &operator*() const
         {
             return *array;
         }

         void operator=(const auto_array<T> &aarray)
         {
             if (!isReleased && array != NULL)
             {
                 delete[] array;
             }
             array = aarray.array;
             isReleased = aarray.isReleased;
             aarray.isReleased = true;
         }

         T *operator->() const
         {
             return array;
         }

         T *release()
         {
             isReleased = true;
             return array;
         }

         void reset(T *array_ = NULL)
         {
             if (!isReleased && array != NULL)
             {
                 delete[] array;
             }
             array = array_;
         }

         T *operator+(int i)
         {
             return array + i;
         }

         T &operator[](int i)
         {
             return array[i];
         }
     };*/
}

Image *Image::loadBMP(const char *filename)
{
    ifstream input;
    input.open(filename, ifstream::binary);
    assert(!input.fail() || !"Could not find file");
    char buffer[2];
    input.read(buffer, 2);
    assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
    input.ignore(8);
    int dataOffset = readInt(input);

    // Read the header
    int headerSize = readInt(input);
    int width_ = 0;
    int height_ = 0;
    switch (headerSize)
    {
    case 40:
        // V3
        width_ = readInt(input);
        height_ = readInt(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
        assert(readShort(input) == 0 || !"Image is compressed");
        break;
    case 12:
        // OS/2 V1
        width_ = readShort(input);
        height_ = readShort(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
        break;
    case 64:
        // OS/2 V2
        assert(!"Can't load OS/2 V2 bitmaps");
    case 108:
        // Windows V4
        assert(!"Can't load Windows V4 bitmaps");
    case 124:
        // Windows V5
        assert(!"Can't load Windows V5 bitmaps");
    default:
        assert(!"Unknown bitmap format");
    }

    // Read the data
    int bytesPerRow = ((width_ * 3 + 3) / 4) * 4 - (width_ * 3 % 4);
    int size = bytesPerRow * height_;
    auto_array pixels_(new char[size]);
    input.seekg(dataOffset, ios_base::beg);
    input.read(pixels_.get(), size);

    // Get the data into the right format
    auto_array pixels2(new char[width_ * height_ * 3]);
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                pixels2[3 * (width_ * y + x) + c] =
                    pixels_[bytesPerRow * y + 3 * x + (2 - c)];
            }
        }
    }

    input.close();
    return new Image(pixels2.release(), width_, height_);
}