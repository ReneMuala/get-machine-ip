source="main.cpp"
executable="main"

all:
	@ echo "\tBuilding \"./main\""
	@ g++ $(source) -o $(executable)
	@ echo "\tDone."
