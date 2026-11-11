#include "utils.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;

bool is_a_num(string input){
    bool is_num = true;

    if (!isalnum(input[0]) || input[0] != '-'){
        is_num = false;
    }

    for (int i = 1; i < input.length(); i++){
        if (!isalnum(input[i])){
            is_num = false;
        }
    }
    return is_num;
}

bool parse_command_line_arguments(
    int* maze_size, const char *const *const argv, int argc){
    
    string first_arg = "./";
    string other_arg = "--";
    string default_arg = "gen-maze";
    string maze_size_arg = "maze-size";
    string arg_left;
    string arg_right;
    bool valid = true;

    for (int i = 0; i < argc; i++){
        std::stringstream ss(argv[i]);
        std::getline(ss, arg_left, '=');

        if (argc > 0 && arg_left[0] == '.'){
            std::cout << "Invalid format for command line arguments!\n";
            valid = false;
        }

        if (arg_left == first_arg + default_arg || 
            arg_left == other_arg + default_arg){} // Do nothing
        
        if (arg_left == first_arg + maze_size_arg || 
            arg_left == other_arg + maze_size_arg){
            if (is_a_num(arg_right)){
                *maze_size = stoi(arg_right);
                std::cout << "maze_size: " << *maze_size << std::endl;
            }
        }
    }
    return valid;
}