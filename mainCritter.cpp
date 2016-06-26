/********************************************************************* 
** Author: Daniel Jackson
** Date: 5/13/2016
** Description: CS 161, Module C - simulate ants running around the grid
** and breeding every 3 moves 
*********************************************************************/ 

#include "Grid.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>

int main()
{

	int row, col, steps, numberOfCrit, numberOfDoodles;
	int invalid_input = 1;
	srand(time(NULL)); //geneerate a seed for random generator
	
	//get row and columns
	while (invalid_input) //input validation
	{
		std::cout << "Please specify the number of rows for the grid " << std::endl;
		std::cin >> row;
		std::cout << "Please specify the number of columns for the grid " << std::endl;
		std::cin >> col;
		if (row < 1 || col < 1)
		{
			std::cout << "The row and colums must be positive integers. Try again." << std::endl;	
		}
		else 
		{
			invalid_input = 0;
		}
	}
	
	//get number of ants
	invalid_input = 1;
	while (invalid_input) //input validation
	{
		std::cout << "How many Ants do you want to play around the grid " << std::endl;
		std::cin >> numberOfCrit;
		std::cout << "How many Doodlebugs do you want to play around the grid " << std::endl;
		std::cin >> numberOfDoodles;
		if (numberOfCrit < 0 || numberOfCrit > row*col)
		{
			std::cout << "Ants & Critters must be more than 0 and less than total elements in the grid." << std::endl;	
		}
		else 
		{
			invalid_input = 0;
		}
	}
	
	
	
	//create grid object
	Grid b1(row, col);
	
	//add 1st gen of amts
	for (int i = 0; i < numberOfCrit; i++)
	{
		Critter* critPtr = new Ant();
		b1.addCritter(critPtr);
		//b1.addCritter();
	}
	
	//add 1st gen of doodles
	for (int i = 0; i < numberOfDoodles; i++)
	{
		Critter* critPtr = new Doodlebug();
		b1.addCritter(critPtr);
	}
	
		
	b1.print(); //output critters that were created
	
	//get number of steps
	std::cout << "How many steps do you want to take?" << std::endl;
	std::cin >> steps ;
	
	//run number of steps
	for (int i=0;i<steps;i++)
	{

				if ((b1.getAntAmount()+numberOfCrit+numberOfDoodles) < row*col)
				{
					std::cout << "Step " << i+1 <<std::endl;
					b1.updateLocation() ;
					b1.print(); //display grid at each step
					usleep(1000000);
					system ("clear");
				}
	}
	std::cout << "Simulation over. Grid is full or number of steps has been reached. " << std::endl;
	return 0;

}
