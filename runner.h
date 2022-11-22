#pragma once

void runner_solve(void);
void dropBreadcrumb(int currRow, int currCol);
char getCharInFront(int currOrientation, int currRow, int currCol);
void moveForward(int currOrientation, int *currRow, int *currCol);
int turn(int direction, int currOrientation);