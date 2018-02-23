#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Cart_Vector.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"

using namespace std;

int main()
{
	/*Model model;
	model.show_status();
	do_move_command(model, 1, 10, 10);
	//cout << model.update() << endl;
	do_run_command(model);
	model.show_status();
	//do_go_command(model);
	//do_go_command(model);
	do_depot_command(model, 1, 2);
	do_depot_command(model, 2, 1);
    do_deposit_moonstones_command(model, 2, 1);
	do_deposit_moonstones_command(model, 1, 2);
	
	do_lock_in_at_station_command(model, 1, 2);
	do_stop_command(model, 1);
	do_stop_command(model, 2);
	*/
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2017" << endl;
	cout << "Programming Assignment 3" << endl;
    Model model;
    View view;
	char command;
	model.update();
    model.show_status();
    model.display(view);
	cout << "Enter command: ";
	cin >> command;
	command_handling(model, view, command);
	while (command != 'q')
	{
		cout << "Enter command: ";
		cin >> command;
		command_handling(model, view, command);
	}
	

	
		return 0;
}