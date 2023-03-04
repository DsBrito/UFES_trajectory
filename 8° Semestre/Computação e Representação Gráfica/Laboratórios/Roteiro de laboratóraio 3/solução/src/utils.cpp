#include "../include/utils.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <algorithm>
#include <cstdio>

namespace Utils {

std::map<std::string, float[16]> transformationMatrices;

void set(std::string id, float* matrix) {
    for (int i = 0; i < 16; i++) {
        transformationMatrices[id][i] = matrix[i];
    }
}

void set2(std::string id) {
    float mat[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, mat);
    for (int i = 0; i < 16; i++) {
        transformationMatrices[id][i] = mat[i];
    }
}

float* get(std::string id) { return transformationMatrices[id]; }

std::vector<std::string> getIDs() {
    std::vector<std::string> ids;
    for (auto it = transformationMatrices.begin();
         it != transformationMatrices.end(); it++) {
        ids.push_back(it->first);
    }
    std::sort(ids.begin(), ids.end());
    return ids;
}

void debug_view_matrix(std::string text) {
    float mat[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, mat);
    if (text.length()) {
        printf("\n\n%s: \n", text.c_str());
    } else {
        printf("\n\nMatrix is: \n");
    }
    printf("%f %f %f %f\n", mat[0], mat[1], mat[2], mat[3]);
    printf("%f %f %f %f\n", mat[4], mat[5], mat[6], mat[7]);
    printf("%f %f %f %f\n", mat[8], mat[9], mat[10], mat[11]);
    printf("%f %f %f %f\n\n", mat[12], mat[13], mat[14], mat[15]);
}
} // namespace Utils