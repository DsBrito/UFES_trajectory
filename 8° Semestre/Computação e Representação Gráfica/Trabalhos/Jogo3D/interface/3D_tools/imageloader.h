

#ifndef OBJLOADER_H
#define OBJECT_IMAGELOADER_H

#include <fstream>
/*Arquivo  enviado pelo professor, extamente igual ao arquivo imageloader.h presente no laboratório de Animação e de Modelos.
 */
class Image
{
public:
    Image(char *ps, int w, int h);

    ~Image();

    static Image *loadBMP(const char *filename);

    /* An array of the form (R1, G1, B1, R2, G2, B2, ...) indicating the
     * color of each pixel in image.  Color components range from 0 to 255.
     * The array starts the bottom-left pixel, then moves right to the end
     * of the row, then moves up to the next column, and so on.  This is the
     * format in which OpenGL likes images.
     */
    char *pixels;
    int width;
    int height;
};

#endif // OBJLOADER_H
