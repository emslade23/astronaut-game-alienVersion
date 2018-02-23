#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "Alien.h"
#include "View.h"
#include "Input_Handling.h"
using namespace std;

void command_handling(Model& model, View& view, char command);

void do_move_command(Model& model, View& view, int id_num, double x, double y);
void do_depot_command(Model& model, View& view, int id1, int id2);
void do_deposit_moonstones_command(Model& model, View& view, int id1, int id2);
void attack_command(Model& model, View& view, int id1, int id2);
void do_stop_command(Model& model, View& view, int id1);
void do_lock_in_at_station_command(Model& model,View& view, int id1, int id2);
void do_go_command(Model& model, View& view);
void do_run_command(Model& model, View& view);
void do_quit_command(Model& model);

void new_command(Model& model, View& view, char TYPE, int id1, double x, double y);


#endif