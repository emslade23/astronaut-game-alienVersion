#include "Alien.h"
#include <iostream>
#include <math.h> 

using namespace std;

Alien:: Alien()
:Game_Object('X')
{
    attack_strength = 2;
    range = 2.0;
    target = NULL;
    speed = 5;
    cout << "Default Alien constructed. " << endl;
}
Alien:: Alien(int in_id, Cart_Point in_loc)
:Game_Object(in_loc, in_id, 'X')
{
    attack_strength = 2;
    range = 2.0;
    target = NULL;
    speed = 5;
    cout << "Alien constructed. "<< endl;
}
void Alien:: start_attack(Person * in_target) //save the target pointer??
{
    target = in_target;
    Cart_Point personLocation = in_target->Game_Object::get_location();
    if (cart_distance(personLocation, this->location)<= range)
    {
        cout <<display_code<< id_num <<": Smash!." << endl;
        state = 'a';
    }
    else
    {
        cout << "Target is out of range. "<< endl;
    }
}
void Alien:: start_moving(Cart_Point dest)
{

        if ((location.x == dest.x) && (location.y == dest.y))
        {
            cout<< display_code<< id_num<< ": I'm already there. see u?"<< endl;
        }
        else
        {
             //tells person to start moving
         setup_destination(dest);
         state = 'm';
         cout<< "Moving "<< id_num<< " to "<< dest<< endl;
         cout<< display_code<< id_num<< ": On my way."<< endl;
        }
}
bool Alien:: update_location()
{
    Cart_Point location1 = Game_Object:: get_location();
    //if astronaut arrives,
    if ((fabs(destination.x - location1.x) <= fabs(delta.x)) && (fabs(destination.y - location1.y) <= fabs(delta.y)))
    {
        location = destination;
        cout<< display_code<< id_num<< ": I'm there!"<< endl;

        return true;
    }
    else
    {
        location = location + delta;
        cout<< display_code<< id_num<< ": step ..."<< endl;
        return false;
    }
}
void Alien:: setup_destination(Cart_Point newdestination)
{
    if ((newdestination.x == location.x) && (newdestination.y == location.y))
    {
        delta = Cart_Vector(0,0);

    }
    else
    {
        destination = newdestination;
        delta = (destination - location) * (speed/cart_distance(destination, location));//what does each variable mean?
    
    }
}
void Alien:: stop()
{
    state = 's'; //stopped
    cout<< display_code<< id_num<< ": Stopped. "<< endl;

}
bool Alien:: update()
{
    switch(state)
    {
        case 's':
        return false;
        break;
        
        case 'm':
        if (update_location())
        {

            //object has arrived
            state = 's';
            
            return true; //update must return true if there is a state change
        }
        else 
        {
            return false; //any additional parameter?
        }
        break;

        case 'a':
        if (cart_distance(target->get_location(), this->location)<= range)
        {
            if (target-> is_alive())
            {
                cout<< display_code<< id_num<<": Take that!"<< endl;
                target->take_hit(attack_strength);
                if(target->update())
                {
                    return true;
                }
                return false;
            }
            else
            {
                cout<< display_code<< id_num<<": I win."<< endl;
                state = 's';
                return true;
            }
        }
        else
        {
            cout<< display_code<< id_num<<": Target is out of range. "<< endl;
            cout<< display_code<< id_num<<": Chaaaaarge. "<< endl;
            state = 's';
            return true;
        }

    }
}
void Alien:: show_status()
{
    cout<< "Alien status: ";
    Game_Object::show_status();
    if (state == 's')
    {
        cout << " is stopped. "<< endl;
    }
    else if (state == 'm') 
    {
        cout<< " moving at speed of "<<speed<< " towards "<< destination<< " at each step of "<< delta << endl;
    }
    else if (state == 'a')
    {
        cout<< " attacking astronaut A"<< target->get_id() << endl;
    }
    
}
