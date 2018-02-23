GCC = g++
# a target to compile the Checkpoint1 which depends on all object-files
# and which links all object-files into an executable
PA4.o: main.o Cart_Point.o Cart_Vector.o Game_Object.o Oxygen_Depot.o Space_Station.o Astronaut.o Person.o Model.o Game_Command.o View.o Alien.o
	$(GCC) main.o Cart_Point.o Cart_Vector.o Game_Object.o Oxygen_Depot.o Space_Station.o Astronaut.o Person.o Model.o Game_Command.o View.o Alien.o -o PA4
# a target to compile the TestCheckpoint3.cpp into an object-file
main.o: main.cpp
	$(GCC) -c main.cpp
# a target to compile the CartPoint.cpp into an object-file
Cart_Point.o: Cart_Point.cpp
	$(GCC) -c Cart_Point.cpp
# a target to compile the Cart_Vector.cpp into an object-file
Cart_Vector.o: Cart_Vector.cpp
	$(GCC) -c Cart_Vector.cpp
	
Game_Object.o: Game_Object.cpp
	$(GCC) -c Game_Object.cpp
	
Oxygen_Depot.o: Oxygen_Depot.cpp
	$(GCC) -c Oxygen_Depot.cpp
	
Space_Station.o: Space_Station.cpp
	$(GCC) -c Space_Station.cpp
	
Astronaut.o: Astronaut.cpp
	$(GCC) -c Astronaut.cpp
	
Person.o: Person.cpp
	$(GCC) -c Person.cpp
	
Model.o: Model.cpp
	$(GCC) -c Model.cpp

Game_Command.o: Game_Command.cpp
	$(GCC) -c Game_Command.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

Alien.o: Alien.cpp
	$(GCC) -c Alien.cpp
	
# a target to delete all object-files and executables
clean:
	rm main.o Cart_Point.o Cart_Vector.o Game_Object.o Space_Station.o Oxygen_Depot.o Astronaut.o Person.o Model.o View.o Game_Command.o Alien.o
