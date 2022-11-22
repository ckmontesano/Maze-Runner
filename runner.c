#include <stdio.h>
#include <stdbool.h>
// Including a header file lets your file refer to the functions *declared* in
// that header file.  The functions are usually *defined* elsewhere though, in
// this case, mazelib.c
#include "mazelib.h"
#include "runner.h" // header file
#include <unistd.h> // !for sleep
#include <stdlib.h> // !for clearing screen

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// own custom vars for orientation and wall pieces
#define LEFT 4
#define RIGHT 5
#define WALL '#'

/* main solving function */
void runner_solve(void)
{
   // create and intialize necessary variables

   // initialize character direction to NORTH
   int currOrientation = NORTH;

   // character starts where "S" is, which is hardcoded at (1,1)
   int currRow = 1;
   int currCol = 1;

   // keep track of last move
   bool movedForward = true;

   // As long as you are not standing on the 'E', do the following:
   while (maze_get_char(currRow, currCol) != 'E')
   {
      // turn to your left if char was moved forward last turn
      if (movedForward)
      {
         currOrientation = turn(LEFT, currOrientation);
      }

      // Check wall not in front of character
      if (getCharInFront(currOrientation, currRow, currCol) != WALL)
      {
         // drop appropriate breadcrum
         dropBreadcrumb(currRow, currCol);

         // move forward
         moveForward(currOrientation, &currRow, &currCol);
         movedForward = true;
      }
      else
      {
         // turn to right
         currOrientation = turn(RIGHT, currOrientation);

         movedForward = false;
      }

      system("clear");
      maze_display();
      usleep(5000);
   }

   system("clear");
}

/* support functions */

// drops a breadcrumb accordingly:
//  - if the square is empty, place '.'
//  - if the square has '.', place 'o'
//  - if the square has 'o', place 'O'
//  - if the square has 'O', place '@'
void dropBreadcrumb(int currRow, int currCol)
{
   if (maze_get_char(currRow, currCol) == ' ')
   {
      maze_set_char(currRow, currCol, '.');
   }
   else if (maze_get_char(currRow, currCol) == '.')
   {
      maze_set_char(currRow, currCol, 'o');
   }
   else if (maze_get_char(currRow, currCol) == 'o')
   {
      maze_set_char(currRow, currCol, 'O');
   }
   else if (maze_get_char(currRow, currCol) == 'O')
   {
      maze_set_char(currRow, currCol, '@');
   }
}

// gets char in front of character
char getCharInFront(int currOrientation, int currRow, int currCol)
{
   if (currOrientation == NORTH)
   {
      return maze_get_char(currRow - 1, currCol);
   }
   else if (currOrientation == EAST)
   {
      return maze_get_char(currRow, currCol + 1);
   }
   else if (currOrientation == WEST)
   {
      return maze_get_char(currRow, currCol - 1);
   }
   // otherwise assume south
   else
   {
      return maze_get_char(currRow + 1, currCol);
   }
}

// moves the character forward
void moveForward(int currOrientation, int *currRow, int *currCol)
{
   if (currOrientation == NORTH)
   {
      *currRow -= 1;
   }
   else if (currOrientation == EAST)
   {
      *currCol += 1;
   }
   else if (currOrientation == WEST)
   {
      *currCol -= 1;
   }
   // otherwise assume south
   else
   {
      *currRow += 1;
   }
}

// Turns character in desired direction
int turn(int direction, int currOrientation)
{
   int newOrientation = NORTH; // temporary initialization

   if (direction == LEFT)
   {
      switch (currOrientation)
      {
      case NORTH:
         newOrientation = WEST;
         break;
      case EAST:
         newOrientation = NORTH;
         break;
      case SOUTH:
         newOrientation = EAST;
         break;
      case WEST:
         newOrientation = SOUTH;
         break;
      }
   }
   else if (direction == RIGHT)
   {
      switch (currOrientation)
      {
      case NORTH:
         newOrientation = EAST;
         break;
      case EAST:
         newOrientation = SOUTH;
         break;
      case SOUTH:
         newOrientation = WEST;
         break;
      case WEST:
         newOrientation = NORTH;
         break;
      }
   }

   return newOrientation;
}