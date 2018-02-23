#include <iostream>
#include <stdlib.h>
#include <list>
#include "Model.h"
using namespace std;
 
Model::Model()
{
    time = -1;
    count_down = 10;
   
  //creating objects on the heap
  /*
   person_ptrs[0] = new Astronaut(1,Cart_Point(5,1));
    person_ptrs[1] = new Astronaut(2,Cart_Point(10,1));
    depot_ptrs[0] = new Oxygen_Depot(Cart_Point(1,20),1);
    depot_ptrs[1] = new Oxygen_Depot(Cart_Point(10,20),2);
    station_ptrs[0]= new Space_Station();
    station_ptrs[1] = new Space_Station(Cart_Point(5,5), 2);
    alien_ptrs[0] = new Alien(1, Cart_Point(7,14));
    alien_ptrs[1] = new Alien(2, Cart_Point(7,5));
    
    */
    Astronaut* pa1 = new Astronaut(1, Cart_Point(5, 1));
    Astronaut* pa2 = new Astronaut(2, Cart_Point(10, 1));
    Oxygen_Depot* od1 = new Oxygen_Depot(Cart_Point(1, 20), 1);
    Oxygen_Depot* od2 = new Oxygen_Depot(Cart_Point(10, 20), 2);
    Space_Station* ss1 = new Space_Station();
    Space_Station* ss2 = new Space_Station(Cart_Point(5, 5), 2);
    Alien* a1 = new Alien(1, Cart_Point(7, 14));
    Alien* a2 = new Alien(2, Cart_Point(7, 5));
    
    
    person_ptrs1.push_back(pa1);
    person_ptrs1.push_back(pa2);
    //person_ptrs2.push_back(pa1);
    //person_ptrs2.push_back(pa2);
 
    depot_ptrs1.push_back(od1);
    depot_ptrs1.push_back(od2);
    
 
    station_ptrs1.push_back(ss1);
    station_ptrs1.push_back(ss2);
 
    alien_ptrs1.push_back(a1);
    alien_ptrs1.push_back(a2);
 
    object_ptrs1.push_back(pa1);
    object_ptrs1.push_back(pa2);
    object_ptrs1.push_back(od1);
    object_ptrs1.push_back(od2);
    object_ptrs1.push_back(ss1);
    object_ptrs1.push_back(ss2);
    object_ptrs1.push_back(a1);
    object_ptrs1.push_back(a2);
 
    active_ptrs.push_back(pa1);
    active_ptrs.push_back(pa2);
    active_ptrs.push_back(od1);
    active_ptrs.push_back(od2);
    active_ptrs.push_back(ss1);
    active_ptrs.push_back(ss2);
    active_ptrs.push_back(a1);
    active_ptrs.push_back(a2);
 
    /*       
    object_ptrs[0] = person_ptrs[0];
    object_ptrs[1] = person_ptrs[1];
 
    object_ptrs[2] = depot_ptrs[0];
    object_ptrs[3] = depot_ptrs[1];
             
    object_ptrs[4] = station_ptrs[0];
    object_ptrs[5] = station_ptrs[1];
 
    object_ptrs[6] = alien_ptrs[0];
    object_ptrs[7] = alien_ptrs[1];
    
    num_objects = 8;
    num_persons = 2;
    num_depots = 2;
    num_stations = 2;
    num_aliens = 2;
    */ 
    cout<< "Model default constructed."<< endl;
 
 
 
}
 
Model:: ~Model()
{
    list<Game_Object*>::iterator it;
    for (it = object_ptrs1.begin(); it != object_ptrs1.end(); ++it)
    {
        delete *it;
    }
   
    
    cout<< "Model destructed."<< endl;
}
 
 
Person* Model::get_Person_ptr(int id) //checking id of astronaut
{
    list<Person *>::iterator it;
    for (it = person_ptrs1.begin(); it != person_ptrs1.end(); ++it)
    {
        if ((*it)->get_id() == id)
        {
            return *it;
        }
    }
    return 0;
              /*
              if ((id > 0) && (id <= num_persons))
              {
                           int realid = id - 1;
                           return person_ptrs[realid];
              }
              else
              {
                           return 0;
              }
    */
   
}
 
Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id) //checking id of oxygen depot
{
   list<Oxygen_Depot *>::iterator it;
    for (it = depot_ptrs1.begin(); it != depot_ptrs1.end(); ++it)
     {
        if ((*it)->get_id() == id)
        {
            return *it;
        }
    }
    return 0;
   /* if ((id > 0) && (id<= num_depots))
    {
        int realid = id-1;
        return depot_ptrs[realid];
    }
    else
    {
        return 0;
    }
              */
}
Space_Station* Model::get_Space_Station_ptr(int id) //checking id of space station
{
    list<Space_Station *>::iterator it;
    for (it = station_ptrs1.begin(); it != station_ptrs1.end(); ++it)
    {
        if ((*it)->get_id() == id)
        {
            return *it;
        }
    }
    return 0;
              /*
    if ((id > 0) && (id<= num_stations))
    {
        int realid = id-1;
        return station_ptrs[realid];
    }
    else
    {
        return 0;
    }
              */
}
 
Alien* Model::get_Alien_ptr(int id) //checking id of alien
{
    list<Alien*>::iterator it;
    for (it = alien_ptrs1.begin(); it != alien_ptrs1.end(); ++it)
    {
       if ((*it)->get_id() == id)
        {
            return *it;
        }
    }
    return 0;
              /*
    if ((id > 0) && (id<= 2))
    {
        int realid = id-1;
        return alien_ptrs[realid];
    }
    else
    { 
        return 0;
    }*/
}
 
bool Model:: update()
{
    int count = 0;
    int upgradeChecker = 0;
    list<Space_Station *>::iterator it1;
    int totalAstronauts = 0;
    for (it1 = station_ptrs1.begin(); it1 != station_ptrs1.end(); ++it1)
    {
        totalAstronauts = totalAstronauts + (*it1)-> get_astronauts();
    }
    for (it1 = station_ptrs1.begin(); it1 != station_ptrs1.end(); ++it1)
    {
        if ((*it1)->get_state() == 'u')
        {
            upgradeChecker = upgradeChecker + 1;
            if (upgradeChecker == 2)
            {
                cout << "Ready for takeoff? " << count_down << "..." << endl;
                count_down = count_down - 1;
                int numberNotLocked = 0;
    
                if (totalAstronauts == person_ptrs1.size())//every astronaut at a station and each station has at least one astronaut
                {
                   cout << "Blast off! You Win!" << endl;
                    exit(0);
                }
                else if (totalAstronauts != person_ptrs1.size())
                {
                    //cout<< "Person pointers size: "<< person_ptrs1.size()<< endl;
                    list<Person *>::iterator it;
                    for (it = person_ptrs1.begin(); it != person_ptrs1.end(); ++it)
                    {
                        if (((*it)-> get_state() != 'l') && ((*it)-> get_state() != 'x'))
                        {
                            numberNotLocked = numberNotLocked +1;
                           // cout<< "NumberNotLocked: "<< numberNotLocked<< endl;
                        }
                    }
                    cout << "Missing "<< numberNotLocked<<" astronauts!" << endl;
                }
                if (count_down == 0)
                {
                    cout << "You lose!"<< endl;
                    exit(0);
                }
            }
            
        }
    }
    
    list<Game_Object*>::iterator it2;
    for (it2 = active_ptrs.begin(); it2 != active_ptrs.end(); ++it2)
    {
        bool val = (*it2)->update();
        if (val)
        {
           count = count + 1;
        }
        
        if (!(*it2)->is_alive())
        {
            //dead object removed from list
            it2 = active_ptrs.erase(it2);
            cout<< "Dead object removed. "<< endl;
        }
        
    }

    //cout<< "Count: "<< count<< endl;
    time = time + 1;
    if (count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

    
 /*
    if ((object_ptrs[4]->get_state() == 'u') && (object_ptrs[5]->get_state() =='u'))//if both space stations are updated
    {
 
        cout << "Ready for takeoff? " << count_down << "..." << endl;
        count_down = count_down - 1;
 
        int astronautsStation1 = station_ptrs[0]->get_astronauts();
        int astronautsStation2 = station_ptrs[1]->get_astronauts();
 
        int totalAstronauts = astronautsStation1 + astronautsStation2;
 
 
        if ((astronautsStation1>0)&&(astronautsStation2>0)&&(totalAstronauts == 2))//every astronaut at a station and each station has at least one astronaut
        {
           cout << "Blast off! You Win!" << endl;
            exit(0);
        }
        else if (((astronautsStation1>0) && (astronautsStation2==0)) || ((astronautsStation1==0) && (astronautsStation2 > 0)))
        {
           cout << "Missing 1 astronauts!" << endl;
                for (int j = 0; j<num_objects; j++)//update every object
                {
                    bool val2 = object_ptrs[j]->update();
                       if (val2)
                        {
                              count = count + 1;
                        }
                }
        }
        else if ((astronautsStation1==0) && (astronautsStation2 == 0))
        {
            cout << "Missing 2 astronauts!" << endl;
            for (int j = 0; j<num_objects; j++)//update every object
            {
                bool val2 = object_ptrs[j]->update();
                if (val2)
                    {
                       count = count + 1;
                    }
            }
        }

 
        if (count_down == 0)
        {
            exit(0);
        }
    }
    else // all cases when the space stations arent upgraded and the astronauts arent locked.
    {
        for (int i = 0; i < num_objects; i++)
        {
            bool val = object_ptrs[i]->update();
            if (val)
            {
               count = count + 1;
            }
        }
    }
    //counting the number of alive astornauts
    int liveAstronautCount = 0;
    for (int i = 0; i< 2; i++)
    {
        if (object_ptrs[i]->is_alive())
        {
            liveAstronautCount = liveAstronautCount + 1;
        }
    }
    //cout << "LiveAstronautCount is: "<< liveAstronautCount << endl;
   
 
    time = time + 1;
 */
}
void Model::display(View &view) //displays gameboard
{
   
    //generates view display for all objects
    view.clear();
    list<Game_Object*>::iterator it;
    for (it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
    {
        view.plot((*it));
    }
    /*
    for (int i = 0; i<num_objects; i++)
    {
        if ((i == 0 ) || (i == 1))
        {
            if (object_ptrs[i]->is_alive())
            {
                view.plot(object_ptrs[i]);
            }
           
        }
        else
        {
            view.plot(object_ptrs[i]);
        }
    }
    */

   
    view.draw();
   
}
 
void Model::show_status() //shows status of objects and time
{
    cout<< "Time: "<< time<< endl;
    /*
    for (int i = 0; i<num_objects; i++)
    {
        object_ptrs[i]->show_status();
    }
    */
    list<Game_Object*>::iterator it;
    for (it = object_ptrs1.begin(); it != object_ptrs1.end(); ++it)
    {
        (*it)->show_status();
    }
}

void Model:: handle_new_command(char TYPE, int id, double x, double y)
{
    bool checker5 = false;
    try
    {
        if (TYPE == 'd')
        {
            list<Oxygen_Depot *>::iterator it;
            for (it = depot_ptrs1.begin(); it != depot_ptrs1.end(); ++it)
            {
               if ((*it)->get_id() != id)
               {
                   checker5 = true;
               }
            }
            if (checker5 == true)
            {
                Oxygen_Depot* oxygenDepot1 = new Oxygen_Depot(Cart_Point(x,y), id);
                depot_ptrs1.push_back(oxygenDepot1);
                object_ptrs1.push_back(oxygenDepot1);
                active_ptrs.push_back(oxygenDepot1);
            }
        }
        else if (TYPE == 's')
        {
            list<Space_Station *>::iterator it;
            for (it = station_ptrs1.begin(); it != station_ptrs1.end(); ++it)
            {
               if ((*it)->get_id() != id)
               {
                   checker5 = true;
               }
            }
            if (checker5 == true)
            {
                Space_Station * spaceStation1 = new Space_Station(Cart_Point(x,y), id);
                station_ptrs1.push_back(spaceStation1);
                object_ptrs1.push_back(spaceStation1);
                active_ptrs.push_back(spaceStation1);
            }
        }
        else if (TYPE == 'a')
        {
            list<Person *>::iterator it;
            for (it = person_ptrs1.begin(); it != person_ptrs1.end(); ++it)
            {
               if ((*it)->get_id() != id)
               {
                   checker5 = true;
               }
            }
            if (checker5 == true)
            {
                Astronaut* astronaut1 = new Astronaut(id, Cart_Point(x, y));
                person_ptrs1.push_back(astronaut1);
                object_ptrs1.push_back(astronaut1);
                active_ptrs.push_back(astronaut1);
            }
        }
        else if (TYPE == 's')
        {
            list<Alien *>::iterator it;
            for (it = alien_ptrs1.begin(); it != alien_ptrs1.end(); ++it)
            {
               if ((*it)->get_id() != id)
               {
                   checker5 = true;
               }
            }
            if (checker5 == true)
            {
                Alien* alien1 = new Alien(id, Cart_Point(x, y));
                alien_ptrs1.push_back(alien1);
                object_ptrs1.push_back(alien1);
                active_ptrs.push_back(alien1);
            }
        }
        else
        {
            throw Invalid_Input((char*) "Was expecting a valid character.");
        }
    }
    catch (Invalid_Input& except) {
            cout << "Invalid input - " << except.msg_ptr << endl;
            return;
    }
    

}