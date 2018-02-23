#ifndef MODEL_H
#define MODEL_H
 
#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Alien.h"
#include "View.h"
#include "Input_Handling.h"
#include <list> 
 
using namespace std;
 
class Model
{
private:
    int time;
    int count_down;
    list<Person*> person_ptrs1;
    //list<Person*> person_ptrs2;
    list<Oxygen_Depot*> depot_ptrs1;
    list<Space_Station*> station_ptrs1;
    list<Alien*> alien_ptrs1;
    list<Game_Object*> object_ptrs1;
    list<Game_Object*> active_ptrs;
 /*
    Game_Object* object_ptrs[10];
    int num_objects;
    Person* person_ptrs[10];
    int num_persons;
   Oxygen_Depot* depot_ptrs[10];
    int num_depots;
   Space_Station* station_ptrs[10];
    int num_stations;
    Model(const Model&);
    int num_aliens;
    Alien* alien_ptrs[10];
   
 */
public:
    Model();
    ~Model();
    Person* get_Person_ptr(int id);
    Oxygen_Depot* get_Oxygen_Depot_ptr(int id);
    Space_Station* get_Space_Station_ptr(int id);
    Alien* get_Alien_ptr(int id);
    bool update();
    void display(View &view);
    void show_status();
    void handle_new_command(char TYPE, int id, double x, double y);   
};
#endif