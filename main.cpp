#include <mcpp/mcpp.h>
#include <ctime>
#include <iostream>

#include "utils.h"
#include "maze.h"

using namespace mcpp;

int main(const int argc, const char *const *const argv){

    //====== ESTABLISH CONNECTION AND SET DEFAULT VALS =======================//
    MinecraftConnection mc;
    //Coordinate player_pos = mc.getPlayerPosition();

    // int loc_x = player_pos.x;
    // int loc_z = player_pos.z;
    // int loc_y = mc.getHeight(Coordinate2D(loc_x, loc_z));

    int maze_size = 200;
    // int seed = time(nullptr);

    //===== PARSE COMMAND LINE ARGS ==========================================//
    if (parse_command_line_arguments(&maze_size, argv, argc)){
        std::cout << "Valid!\n";

    }

    return 0;
}