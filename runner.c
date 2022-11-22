#include <stdio.h>
#include <stdbool.h>
// Including a header file lets your file refer to the functions *declared* in
// that header file.  The functions are usually *defined* elsewhere though, in
// this case, mazelib.c
#include "mazelib.h"

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3


void runner_solve(void) {
  // Use a few variables to keep track of the current row and column position
  // of the "runner".  The runner should always start at the 'S' symbol in the
  // maze.  Luckily, the 'S' symbol is always in the same place

  // You should also keep track of which way the runner is facing.  You can use
  // the preprocessor defines at the top of this file to make your life easier
  // instead of just having to remember "0 is North, 1 is East, etc."
  // Basically, any time you use NORTH in your code, a zero will be substituted
  // in for it at compile time.

  // Ok, algorithm time:
  //
  // 1. As long as you are not standing on the 'E', do the following:
  // 2. Turn to your left
  // 3. Can you go that way?  I.E., is there not a wall in front of you?
  // 4. If your path is blocked, turn to your right and go back to (3)
  // 5. If your path is open, throw down the appropriate breadcrumb (see note)
  // 6. Move forward and go back to (1)
  // 7. You are standing on the 'E', STOP, you're done!

  // NOTE: By "appropriate breadcrumb" I mean this:
  //       If you are in an empty square, the breadcrumb should be '.'
  //       If you are in a square with '.', the breadcrumb should be 'o'
  //       If you are in a square with 'o', the breadcrumb should be 'O'
  //       If you are in a square with 'O', the breadcrumb should be '@'
  //
  // Here is an example of a solved maze:
  //
  // ###########################
  // #S....#.oo..#.oooOoooooo..#
  // #####.###.#.#####o#####.#.#
  // #   #.#...#.....#.#.....#.#
  // # # #.#.#######.###.#####.#
  // # # #...#     #.#...#.....#
  // # ####### # ###.#.###.#####
  // #         #    ...#  ....E#
  // ###########################
}
