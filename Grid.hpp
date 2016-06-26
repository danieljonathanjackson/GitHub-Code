/********************************************************************* 
** Author: Daniel Jackson
** Date: 4/19/2016
** Description: Grid class header file
*********************************************************************/ 
#include "Ant.hpp"
#include "Doodlebug.hpp"

#ifndef GRID_HPP
#define GRID_HPP

class Grid
{
private:
	Critter*** GridArry; //dynamic 2d array
	int rowMax, columnMax, xCoord, yCoord, antAmount;
public:
    Grid(int, int); //constructor
	void addCritter(Critter* critPtr);
	void updateLocation();
	void print();
	int getRowMax();
	int getColumnMax();
	int getAntAmount();
	void reset();
	~Grid(); //destructor
};

#endif
