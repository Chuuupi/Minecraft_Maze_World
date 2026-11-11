#ifndef UTILS_H
#define UTILS_H

#include <string>

bool is_a_num(std::string input);

bool parse_command_line_arguments(
    int* maze_size, const char *const *const argv, int argc);

#endif