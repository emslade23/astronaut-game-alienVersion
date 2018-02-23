#include <iostream>
#include "Game_Command.h"
#include <limits>
using namespace std;

void command_handling(Model& model, View& view, char input)
{
	int id1;
	int id2;
	double x;
	double y;
	char TYPE;
	try
	{
		switch(input) //switch statement 
		{
			case 'm':
				if ((cin >> id1) && (cin >> x) && (cin >> y))
				{
					do_move_command(model, view, id1, x, y);
				}
				else if (!(cin >> id1))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting an integer.");
				}
				else if ((! (cin >> x)) || (! (cin >> y)))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting a double.");
				}

				break;
			case 'w':
				if ((cin >> id1) && (cin >> id2))
				{
					do_depot_command(model, view, id1, id2);
				}
				else if ((!(cin >> id1)) || (!(cin >> id2)))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting an integer.");
				}
				break;
			case 'd':
				if ((cin >> id1) && (cin >> id2))
				{
					do_deposit_moonstones_command(model, view, id1, id2);
				}
				else if ((!(cin >> id1)) || (!(cin >> id2)))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting an integer.");
				}

				break;
			case 'a':
				if ((cin >> id1) && (cin >> id2))
				{
					attack_command(model, view, id1, id2);
				}
				else if ((!(cin >> id1)) || (!(cin >> id2)))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting an integer.");
				}
				break;
			case 's':
				if (cin >> id1)
				{
					do_stop_command(model, view, id1);
				}
				else if (!(cin >> id1))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting an integer.");
				}
				break;
			case 'l':
				if ((cin >> id1) && (cin >> id2))
				{
					do_lock_in_at_station_command(model, view, id1, id2);
				}
				else if ((!(cin >> id1)) || (!(cin >> id2)))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting an integer.");
				}
				break;
			case 'n':
				if ((cin >> TYPE) && (cin >> id1) && (cin >> x) && (cin >> y))
				{
					new_command(model, view, TYPE, id1, x, y);
				}
				else if (!cin >> id1)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting an integer.");
				}
				else if ((!(cin >> x)) || (! (cin >> y)))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw Invalid_Input((char*) "Was expecting a double.");
				}
				break;
			case 'g':
				do_go_command(model, view);
				break;
			case 'r':
				do_run_command(model, view);
				break;
			case 'q':
				do_quit_command(model);
				break;
			default:
				throw Invalid_Input((char*) "Invalid Command.");
		
		}
	
	}
	catch (Invalid_Input& except) {
		cout << "Invalid input - " << except.msg_ptr << endl;
		return;
	}
	
}


void do_move_command(Model& model, View& view, int id1, double x, double y) //declares astronaut pointer and calls start moving function
{
	char idChar;
	try
	{
		cout<< "Move Astronaut (enter 'a') or Alien (enter 'x'): ";
		cin >> idChar;
		if (idChar == 'a')
		{
			Person * astronaut_pointer1 = model.get_Person_ptr(id1);
			if (astronaut_pointer1 != 0) 
			{
				astronaut_pointer1->start_moving(Cart_Point(x, y));
				//model.display(view);
			}
			else 
			{
				throw Invalid_Input((char*) "Input ID does not exist!" );
			}
		}
		else if (idChar == 'x')
		{
			Alien * alien_pointer1 = model.get_Alien_ptr(id1);
			if (alien_pointer1 != 0) 
			{
				alien_pointer1->start_moving(Cart_Point(x, y));
				//model.display(view);
			}
			else 
			{
				throw Invalid_Input((char*) "Input ID does not exist!");
			}
		}
		else
		{
			throw Invalid_Input((char*) "You entered an incorrect character.");
		}

	}
	catch (Invalid_Input& except) {
		cout << "Invalid input - " << except.msg_ptr << endl;
		
	}

	
}
void do_depot_command(Model& model, View& view, int id1, int id2) //declares astronaut pointer and calls start supplying function
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	Oxygen_Depot* oxygen_depot_pointer = model.get_Oxygen_Depot_ptr(id2);
	try
	{
		if ((astronaut_pointer1 != 0) && (oxygen_depot_pointer != 0))
		{
			astronaut_pointer1->start_supplying(oxygen_depot_pointer);
			//model.display(view);
		}
		else 
		{
			throw Invalid_Input((char*) "Input ID does not exist!");
		}
	}
	catch (Invalid_Input& except) {
		cout << "Invalid input - " << except.msg_ptr << endl;
		
	}


}
void do_deposit_moonstones_command(Model& model, View& view, int id1, int id2) // declares astronaut pointer and calls start depositing function
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	Space_Station* space_station_pointer1 = model.get_Space_Station_ptr(id2);
	try
	{
		if ((astronaut_pointer1 != 0) && (space_station_pointer1 != 0))
		{
			astronaut_pointer1->start_depositing(space_station_pointer1);
			//model.display(view);
		}
		else 
		{
			throw Invalid_Input((char*) "Input ID does not exist!");
		}
	}

	catch (Invalid_Input& except) {
		cout << "Invalid input - " << except.msg_ptr << endl;
	
	}
	
}

void attack_command(Model& model, View& view, int id1, int id2)
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id2);
	Alien * alien_pointer1 = model.get_Alien_ptr(id1);
	try
	{
		if ((astronaut_pointer1 != 0) && (alien_pointer1 != 0))
		{
			alien_pointer1->start_attack(astronaut_pointer1);
		}
		else 
		{
			throw Invalid_Input((char*) "Input ID does not exist!");
		}
	}
	catch (Invalid_Input& except) {
		cout << "Invalid input - " << except.msg_ptr << endl;
	
	}
}


void  do_stop_command(Model& model, View& view, int id1) //stops astronaut
{
	char idChar;
	try
	{
		cout<< "Move Astronaut (enter 'a') or Alien (enter 'x'): ";
		cin >> idChar;
		if (idChar == 'a')
		{
			Person * astronaut_pointer1 = model.get_Person_ptr(id1);
			
				if (astronaut_pointer1 != 0) 
				{
					astronaut_pointer1->stop();
					model.display(view);
				}
				else 
				{
					throw Invalid_Input((char*) "Input ID does not exist!" );
				}
		}
		else if (idChar == 'x')
		{
			Alien * alien_pointer1 = model.get_Alien_ptr(id1);
			if (alien_pointer1 != 0) 
			{
				alien_pointer1->stop();
				model.display(view);
			}
			else 
			{
				throw Invalid_Input((char*) "Input ID does not exist!" );
			}
		}
		else
		{
			throw Invalid_Input((char*) "You entered an incorrect character.");
		}
		
	}
	catch(Invalid_Input& except) {
		cout << "Invalid input - " << except.msg_ptr << endl;
	}
	

}
void do_lock_in_at_station_command(Model& model, View& view, int id1, int id2) //locks astronaut into station
{
	Person * astronaut_pointer1 = model.get_Person_ptr(id1);
	Space_Station* space_station_pointer1 = model.get_Space_Station_ptr(id2);
	try
	{
		if ((astronaut_pointer1 != 0) && (space_station_pointer1 != 0))
		{
			astronaut_pointer1->go_to_station(space_station_pointer1);
			model.display(view);
		}
		else 
		{
			throw Invalid_Input((char*) "Input ID does not exist!" );
		}
	}
	catch(Invalid_Input& except) {
		cout << "Invalid input - " << except.msg_ptr << endl;
	}

}
void do_go_command(Model& model, View& view) //updates objects once
{
	cout << "Advancing one tick." << endl;
	model.update();
	model.show_status();
	model.display(view);
}
void do_run_command(Model& model, View& view) //updates objects up to 5 times
{
	cout << "Advancing to next event." << endl;
	int time = 0;
	while ((!model.update()) && (time < 4))
	{
		time = time + 1;
	}
	model.show_status();
	model.display(view);
}
void do_quit_command(Model& model) //quits program
{
	cout << "Terminating program. " << endl;

}
void new_command(Model& model, View& view, char TYPE, int id1, double x, double y)// new command
{
	model.handle_new_command(TYPE, id1, x, y);
}