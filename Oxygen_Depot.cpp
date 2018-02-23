
#include <iostream>
#include "Cart_Point.h"//inherits from game_object
#include "Oxygen_Depot.h"
using namespace std;


 
    Oxygen_Depot::Oxygen_Depot()
    :Game_Object('O')
    {
        amount_oxygen = 50;
        state = 'f';
        cout<< "Oxygen_Depot default constructed."<<endl;
    }
    
    
    Oxygen_Depot:: Oxygen_Depot(Cart_Point inputLoc, int inputId)
    :Game_Object(inputLoc, inputId, 'O') //sets up id_num, location, and display_code
    {   
        state = 'f';
        amount_oxygen = 50;
        cout<< "Oxygen_Depot constructed."<< endl;
    }
    bool Oxygen_Depot::is_empty()
    {
        if (amount_oxygen == 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    double Oxygen_Depot:: extract_oxygen(double amount_to_extract)
    {
        if (amount_oxygen >= amount_to_extract)
        {
            amount_oxygen = amount_oxygen - amount_to_extract;
            return amount_to_extract;
        }
        else
        {
            double current_amount_oxygen = amount_oxygen;
            amount_oxygen = 0;
            return current_amount_oxygen;
        }
    }
    bool Oxygen_Depot:: update()//confused about the fact that the function should only return true at the time when o2depot becomes empty
    {
        if ((amount_oxygen == 0) && (state != 'e'))
        {
            state = 'e';
            display_code = 'o';
            cout<< "Oxygen Depot " << id_num<< " has been depleted. "<< endl;
            return true; 
        }
        else 
        {
            return false;
        }
    }
    void Oxygen_Depot:: show_status()
    {
        cout<< "Oxygen Depot status: "<<display_code<<id_num<<" at location "<<location<< " contains "<<amount_oxygen << "."<< endl;
    }
    Oxygen_Depot:: ~Oxygen_Depot()
    {
        cout<< "Oxygen_Depot destructed."<< endl;
        
    }
    bool Oxygen_Depot:: is_alive()
    {
        return true;
    }
