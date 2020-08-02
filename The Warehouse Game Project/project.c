/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* Krithik Lekinwala
   Username: Klek990
   ID: 950114150
*/

#include "project.h"

/*
 This function computes the time difference between two points in time; A and B respectively.
 This time difference (timeDiff) is known as the length of a workers shift and by converting 
 all minutes into seconds, the function can simply subtract the two totals to calculate the length
 of a workers shift.
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{

	// Declaring variables for the time difference, total of A and B in seconds (multiply minutes by 60)
	int totalA = (minuteA * 60) + secondA;
	int totalB = (minuteB * 60) + secondB;
	int timeDiff = 0;


	// Conditional statements to check which total is bigger, then subtract the latter total
	if (totalA > totalB)
		timeDiff = totalA - totalB;

	else
		timeDiff = totalB - totalA;


	return timeDiff;
}

/*
This function calculates the largest prime number in the given maximum value.
This is done by re-writing the value of 'i' (prime number) to isPrime IF the
condition for a prime number is met. The conditional is inside a for loop in
order to return the largest possible prime number before the maximum value input.
i.e The largest prime number IS the first prime number before the maximum.
*/
int WarehouseAddress(int maximum)
{
	// Variable declaration
	int i, j;
	int isPrime = 0;

	// i = number which is modded by j. Range = 2 to (maximum - 1)
	for (i = 2; i < maximum; i++)
	{
		// j = mod number
		for (j = 2; j <= i; j++)
		{
			/* 
			If remainder of this condition is 0, i is a factor of j. If successful,
			break inner for loop
			*/
			if (i % j == 0)
				break;
		}

		/*
		Checks whether i is a prime number. Inside outer for loop so the largest prime
		number in the range is taken.
		*/
		if (i == j)
			isPrime = i;
	}

	return isPrime;
}

/*
This function's purpose is to move each character in the input string to the left by 1
index position. The first character in the string should 'wrap' around become the right-most
index position. i.e words[0] == words[length - 1]. This creates the effect of scrolling text.
*/
void Advertise(char *words)
{
	// Finding length of words input and declaring variables
	int length = strlen(words);
	char x = words[0];
	int i = 0;
	
	// Loop with these conditions moves all array elements to the left by one
	for (i = 0; i < length - 1; i++) {
		words[i] = words[i + 1];
	}

	// Sets first character in the string to the last character in the string
	words[length - 1] = x;
}

/*
This function calculates the lowest UNIQUE value of a given array. This is done
by checking if any numbers are repeated and if they are, do not write these values 
to a new 'unique' array. If the values are unique and not repeated, these values
are filtered into another array and then the minimum value of these integers is
returned.
*/
int WinningBid(int *values, int length)
{

	int i, j;
	int uniqueVals[100];
	int uniqueLength = 0;

	// Loops all positions in array to check if values are the same
	for (i = 0; i < length; i++)
	{

		for (j = 0; j < length; j++)
		{
			/*
			If values are the same, break the loop and check the if condition to write to a new array
			for unique values.
			*/ 
			if (values[i] == values[j] && i != j)
				break;
		}

		if (j == length) {
			uniqueVals[uniqueLength] = values[i];
			uniqueLength++;
		}
	}

	/*
	Filtering out the smallest value of the array of unique integers. This
	part of the code will only run IF there are unique integers in the array.
	Otherwise, the program will simply return '-1' due to no unique values.
	*/
	int smallNum = uniqueVals[0];
	
	// If the length of the unique array (i.e all repeated values), return -1
	if (uniqueLength == 0) 
		smallNum = -1;

	for (i = 1; i < uniqueLength; i++)
	{
		if (uniqueVals[i] < smallNum)
		{
			smallNum = uniqueVals[i];

		}
	}

	return smallNum;

}

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void BoxDesign(char *design, int width, int height)
{
	width = height;
	design[0] = '-';
	design[1] = '9';
	design[2] = '9';
	design[3] = '9';
	design[4] = '9';
	design[5] = '\0';
}

/*
The positions of the worker and boxes are first recorded and stored in declared variables.
Given the right conditions (i.e. move left then up, move right then down etc) the rows of the
box and worker are made equal using for loops and same goes for the columns. This will work for
every scenario possible (which is why there are 12 possible cases in which the worker could move)
*/
void WorkerRoute(int warehouse[10][10])
{
	int i = 0;
	int j = 0;
	int workerRow = 0;
	int workerCol = 0;
	int boxRow = 0;
	int boxCol = 0;

	// Records positions of worker and box
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 1) {
				workerRow = i;
				workerCol = j;
			}
			if (warehouse[i][j] == 2) {
				boxRow = i;
				boxCol = j;
			}
		}
	}

	// This conditional creates a path when worker needs to move RIGHT then UP or DOWN

	// Move RIGHT
	if (workerCol < boxCol && workerRow != boxRow) {
		for (j = workerCol + 1; j <= boxCol; j++) {
			warehouse[workerRow][j] = 3;

			// Move UP
			if (workerRow > boxRow) {
				for (i = boxRow + 1; i < workerRow; i++) {
					warehouse[i][boxCol] = 3;
				}
			}

			// Move DOWN
			else if (workerRow < boxRow) {
				for (i = boxRow - 1; i > workerRow; i--) {
					warehouse[i][boxCol] = 3;
				}
			}
		}
	}


	// This conditional creates a path when worker needs to move LEFT then UP or DOWN

	// Move LEFT
	else if (workerCol > boxCol && workerRow != boxRow) {
		for (j = workerCol - 1; j >= boxCol; j--) {
			warehouse[workerRow][j] = 3;

			// Move UP
			if (workerRow > boxRow) {
				for (i = boxRow + 1; i < workerRow; i++) {
					warehouse[i][boxCol] = 3;
				}
			}

			// Move DOWN
			else if (workerRow < boxRow) {
				for (i = boxRow - 1; i > workerRow; i--) {
					warehouse[i][boxCol] = 3;
				}
			}
		}
	}


	//This conditional creates a path when worker only needs to move UP or DOWN
	else if (workerCol == boxCol) {

		// Move UP
		if (workerRow > boxRow) {
			for (i = boxRow + 1; i < workerRow; i++) {
				warehouse[i][boxCol] = 3;
			}
		}

		// Move DOWN
		else if (workerRow < boxRow) {
			for (i = boxRow - 1; i > workerRow; i--) {
				warehouse[i][boxCol] = 3;
			}
		}
	}
	//This conditional creates a path when worker only needs to move RIGHT or LEFT
	else if (workerRow == boxRow) {

		// Move RIGHT
		if (workerCol < boxCol) {
			for (j = workerCol + 1; j < boxCol; j++) {
				warehouse[workerRow][j] = 3;
			}
		}

		// Move LEFT
		else if (workerCol > boxCol) {
			for (j = workerCol - 1; j > boxCol; j--) {
				warehouse[workerRow][j] = 3;
			}
		}
	}
	
}



/*
Firstly, this function will enable the user to input 'w', 'a', 's', or 'd' depending on what direction
they wish to move the worker. Upon hitting a wall, the worker will not be able to move any further which also applies to the box boundaries.
This is done by checking the adjacent spaces of the worker to see if there is a wall. If there is, restrict movement, otherwise, movement is
allowed.


*/
int MakeMove(int warehouse[10][10], char move)
{
	// Declaration of variables used
	int i = 0;
	int j = 0;
	int workerRow = 0;
	int workerCol = 0;


	// Finding the positions of the worker and worker on target

	for (i = 1; i < 9; i++) {
		for (j = 1; j < 9; j++) {
			if (warehouse[i][j] == WORKER) {
				workerRow = i;
				workerCol = j;

			}
		}
	}

	/* 
	MOVEMENT INTERACTIONS below. If the input is w, a, s, d respectively, 
	the worker can only move if there is no adjacent wall present.
	*/


	// Move UP until only when there is no wall
	if (move == 'w' && warehouse[workerRow - 1][workerCol] != WALL) {
		
		// If a box is present when moving UP, box will be 'pushed' unless there are 2 or more boxes
		if (warehouse[workerRow - 1][workerCol] == BOX && warehouse[workerRow - 2][workerCol] != WALL && warehouse[workerRow - 2][workerCol] != BOX) {
			warehouse[workerRow - 2][workerCol] = BOX;
			warehouse[workerRow - 1][workerCol] = WORKER;
			warehouse[workerRow][workerCol] = SPACE;
			warehouse[workerRow - 1][workerCol] = WORKER;
		}

		// If no box is present, continue movement as normal
		else if (warehouse[workerRow - 1][workerCol] != BOX) {
			warehouse[workerRow - 1][workerCol] = WORKER;
			warehouse[workerRow][workerCol] = SPACE;

		}

	}


	// Move LEFT until only when there is no wall
	else if (move == 'a' && warehouse[workerRow][workerCol - 1] != WALL) {

		// If a box is present when moving LEFT, box will be 'pushed' unless there are 2 or more boxes
		if (warehouse[workerRow][workerCol - 1] == BOX && warehouse[workerRow][workerCol - 2] != WALL && warehouse[workerRow][workerCol - 2] != BOX) {
			warehouse[workerRow][workerCol - 2] = BOX;
			warehouse[workerRow][workerCol - 1] = WORKER;
			warehouse[workerRow][workerCol] = SPACE;
			warehouse[workerRow][workerCol - 1] = WORKER;
		}

		// If no box is present, continue movement as normal
		else if (warehouse[workerRow][workerCol - 1] != BOX) {
			warehouse[workerRow][workerCol] = SPACE;
			warehouse[workerRow][workerCol - 1] = WORKER;
		}
	}

	// Move DOWN until only when there is no wall
	else if (move == 's' && warehouse[workerRow + 1][workerCol] != WALL) {

		// If a box is present when moving DOWN, box will be 'pushed' unless there are 2 or more boxes
		if (warehouse[workerRow + 1][workerCol] == BOX && warehouse[workerRow + 2][workerCol] != WALL && warehouse[workerRow + 2][workerCol] != BOX) {
			warehouse[workerRow + 2][workerCol] = BOX;
			warehouse[workerRow + 1][workerCol] = WORKER;
			warehouse[workerRow][workerCol] = SPACE;
			warehouse[workerRow + 1][workerCol] = WORKER;
		}

		// If no box is present, continue movement as normal
		else if (warehouse[workerRow + 1][workerCol] != BOX){
			warehouse[workerRow][workerCol] = SPACE;
			warehouse[workerRow + 1][workerCol] = WORKER;
		}
	}
	// Move RIGHT until only when there is no wall
	else if (move == 'd' && warehouse[workerRow][workerCol + 1] != WALL) {

		// If a box is present when moving RIGHT, box will be 'pushed' unless there are 2 or more boxes
		if (warehouse[workerRow][workerCol + 1] == BOX && warehouse[workerRow][workerCol + 2] != WALL && warehouse[workerRow][workerCol + 2] != BOX) {
			warehouse[workerRow][workerCol + 2] = BOX;
			warehouse[workerRow][workerCol + 1] = WORKER;
			warehouse[workerRow][workerCol] = SPACE;
			warehouse[workerRow][workerCol + 1] = WORKER;

		}

		// If no box is present, continue movement as normal
		else if (warehouse[workerRow][workerCol + 1] != BOX){
			warehouse[workerRow][workerCol] = SPACE;
			warehouse[workerRow][workerCol + 1] = WORKER;
		}
		
	}

	return 0;
}

