#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#include "Button.h"

/// -- Ready --
// return distance from point
float distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}


/// -- Ready --
// draw button
void drawButton(int xPosition, int yPosition )
{
    circle(xPosition, yPosition, BUTTON_RADIUS);
}


/// -- In progress --
// check if button is clicked
bool buttonClicked(int xPosition, int yPosition)
{
    // detect when the left mouse button is clicked down
    bool mouseClicked = ismouseclick(2);

    int xPos = mousex();
    int yPos = mousey();

    float distancePoint = distance(xPosition, yPosition, xPos, yPos);

    if(mouseClicked && distancePoint < BUTTON_RADIUS)
    {
        return true;
    }

    return false;
}
