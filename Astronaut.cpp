#include <iostream>
#include "Cart_Vector.h"
#include "Astronaut.h"
using namespace std;

//constructors
Astronaut:: Astronaut()
:Person('A')
{
    amount_moonstones = 0;
    amount_oxygen = 20;
    depot = NULL;
    home = NULL;
    cout<< "Astronaut default constructed."<< endl;
    checker = false;
    checker2 = false;
}
Astronaut:: Astronaut(int in_id, Cart_Point in_loc)
:Person(in_loc, in_id, 'A')
{
    amount_moonstones = 0;
    amount_oxygen = 20;
    depot = NULL;
    home = NULL;
    cout<< "Astronaut constructed."<< endl;   
    checker = false;
    checker2 = false;
}

bool Astronaut:: update()
{
    //cout<< "Health: "<< health<< endl;
    if (health < 3)
    {
        display_code = 'a';
    }
    //switch statement
    switch (state)
    {
        case 's':
        if (amount_oxygen == 0)
        {
            cout << "I can't move. I'm out of oxygen." << endl;
            state = 'x';
            return true; //update must return true if there is a state change
        }
        else
        {
            return false;
        }
        break;
        case 'm':
        if (amount_oxygen == 0)
        {
            cout << "I can't move. I'm out of oxygen." << endl;
            state = 'x';
            return true; //update must return true if there is a state change
        }
        else
        {
            if (update_location())
            {
    
                //object has arrived
                state = 's';
                
                return true; //update must return true if there is a state change
            }
            else 
            {
                amount_moonstones = amount_moonstones+1; //incrementing moonstones and decrementing oxygen
                amount_oxygen = amount_oxygen -1;
                return false;
                
            }
        }
        break;
        case 'o':
        if (amount_oxygen == 0)
        {
            cout << "I can't move. I'm out of oxygen." << endl;
            state = 'x';
            return true; //update must return true if there is a state change
        }
        else
        {
            if (update_location())
            {
                
                //show_status();
                state = 'g';
                return true;//update must return true if there is a state change
    
            }
            else
            {
                //show_status();
                amount_moonstones = amount_moonstones+1;
                amount_oxygen = amount_oxygen -1;
                return false;
            }
        }
        break;
        case 'g':
        amount_oxygen = depot->extract_oxygen() + amount_oxygen; //extracting oxygen from the astronaut object's current depot
        cout<< display_code<< id_num<<": Got 20 more oxygen."<< endl;
        state = 's';
        return true; //update must return true if there is a state change
        break;

        case 'i':
        if (amount_oxygen == 0)
        {
            cout << "I can't move. I'm out of oxygen." << endl;
            state = 'x';
            return true; //update must return true if there is a state change
        }
        else
        {
            if (update_location())
            {
             
                state = 'd';
                return true; //update must return true if there is a state change
            }
            else 
            {
            //show_status();
                amount_moonstones = amount_moonstones+1;
                amount_oxygen = amount_oxygen -1;
                return false;
            }
        }
        break;
        case 'd':
        cout<< display_code<< id_num<< ": Deposit "<< amount_moonstones<< " moonstones. "<< endl;
        home->deposit_moonstones(amount_moonstones); //depositing moonstones from astronaut object's home
        amount_moonstones = 0;
        
        state = 's';
        if (amount_oxygen == 0)
        {
            cout << "I'm out of oxygen. I'm dying!" << endl;
            state = 'x';
        }
        return true; //update must return true if there is a state change
        break;
        case 'l':
        if (amount_oxygen == 0)
        {
            return false;
        }
        else
        {
            if (checker == false)
            {
                if(update_location())
                {
                    home->add_astronaut();
                    checker = true; //flag to avoid repetitive measures of astronaut arrival
                    return true; //update must return true if there is a state change
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        case 'x':
        if (checker2 == false)
        {
            checker2 = true;
            return true;
        }
        else
        {
            return false;
        }
        break;


    }

}
void Astronaut:: start_supplying(Oxygen_Depot* inputDepot)
{
    
    //remove oxygen from depot
    if ((state != 'l') && (state != 'x'))
    {
        depot = inputDepot; //updating depot
        setup_destination(inputDepot -> get_location()); //recieving inputDepot's location and setting up route
        state = 'o';
        cout<< "Astronaut "<< id_num <<" supplying at Oxygen Depot "<< inputDepot->get_id()<< "."<< endl;
        cout<< display_code<< id_num<<": Yes, my lord."<< endl;
    }
    else if (state == 'x')
    {
        cout<< "Sorry Astronaut " << id_num<< " is dead and a zombie."<< endl;
    }
    else
    {
        cout<< "Sorry Astronaut " << id_num<< " is locked and a zombie."<< endl; //prevents locked astronaut from getting oxygen
    }
}
void Astronaut:: start_depositing(Space_Station* inputStation)
{
	
    if ((state != 'l') && (state != 'x'))
    {
        home = inputStation;
    	//start moving to station to deposit moonstones 
    	setup_destination(inputStation->get_location()); //input station **get location **
    	state = 'i';
    	cout<< "Astronaut "<< id_num<< " depositing at Space Station "<< inputStation->get_id()<< "."<< endl;
   	 	cout<< display_code<< id_num<< ": Yes, my lord."<< endl;
    }
    else if (state == 'x')
    {
        cout<< "Sorry Astronaut " << id_num<< " is dead and a zombie."<< endl;
    }
    else
    {
        cout<< "Sorry Astronaut " << id_num<< " is locked."<< endl; //prevents locked astronaut from getting oxygen
    }
		
}
void Astronaut:: go_to_station(Space_Station* inputStation)
{
  
    if ((inputStation->get_state()) != 'u') //if stations arent upgraded, the astronaut cant go to them
    {
        cout<< "Astronaut "<< id_num<< " cannot lock in at Space_Station "<< inputStation->get_id()<< " because it is not upgraded. "<< endl;
    }
    else if (state == 'x')
    {
        cout<< "Sorry Astronaut " << id_num<< " is dead and a zombie."<< endl;
    }
    else
    {
        home = inputStation;
    	cout<< "Astronaut "<< id_num<< " locking in at Space_Station "<< inputStation->get_id()<< ". "<< endl;
        setup_destination(inputStation -> get_location()); //setting astronaut up to go to station
        state = 'l';
    }
}
void Astronaut:: show_status() //prints out the current status of the astronaut
{
    cout<< "Astronaut status: ";
    Person:: show_status();
    if (state == 's')
    {
        cout<< "with "<< amount_oxygen << " oxygen and "<< amount_moonstones<< " moon stones."<< endl;
    }
    else if (state == 'm')
    {
        //Person:: show_status();
    }
    else if (state == 'o')
    {
        cout<<" is outbound to a Depot with "<< amount_oxygen<< " oxygen and "<< amount_moonstones<< " moon stones. "<< endl;
    }
    else if(state == 'g')
    {
        cout<< " is getting oxygen from Depot."<<endl;

    }
    else if(state == 'i')
    {
        cout << " is inbound to home with load: "<< amount_moonstones << " moon stones and "<< amount_oxygen<< " oxygen. "<< endl;
    }
    else if (state == 'd')
    {
        cout<< " is depositing "<< amount_moonstones<< " moon stones."<< endl;
    }
    else if (state == 'l')
    {
        if (amount_oxygen == 0)
        {
            cout<< ". Out of oxygen." << endl;
        }
        else 
        {
            cout<< "at Space Station. "<< endl; //error
        }
    }

}

Astronaut:: ~Astronaut()
{
    cout<< "Astronaut destructed."<< endl;
}
