# Maze Runner
Made for CYB 126, this is a cool little tool I made that will generate a maze and "solve" it using a basic algorithm. The "main" branch has an animation, you can guess what the "without-animation" branch does.

## Installation
1) Clone the repository to your machine using `git clone git@github.com:ckmontesano/Maze-Runner.git`
2) Navigate into the new directory and run `make`. This will build the program using the Makefile included.
Simple!

## Run it
There are two versions of this program, one with a cool animation and one without (I had to submit it to the class without animation but I couldn't resist adding one). The 'main' branch, or the default, does have the animation. If you'd like to switch to the non-animated version, run `git checkout without-animation`.

- Call the program using `./maze_runner x y`
  - the X dimension must be between 9 and 79, inclusive
  - the Y dimension must be between 9 and 25, inclusive
  - Both X and Y dimensions must be odd numbers
- See it in action!

## Credit
The algorithm is quite simple but I did not come up with it, I simply followed pseudocode to make the program come to life.
