#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <string>
#include <vector>

namespace Utils {

void set(std::string id, float* matrix);
void set2(std::string id);
std::vector<std::string> getIDs();
void debug_view_matrix(std::string text = "");
float* get(std::string id);

} // namespace Utils

#endif