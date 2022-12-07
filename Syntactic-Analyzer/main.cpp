#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define ENTER_KEY 13
#define BACKSPACE_KEY 8
#define CLOSE_KEY_1 120
#define CLOSE_KEY_2 88

#define FIELD_HEIGHT 40
#define FIELD_LENGHT 100

#define BUTTON_RADIUS 20

using namespace std;


struct viewportPoint
{
    int x;
    int y;
};


// return distance from point
float distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}


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


/// -- In progress --
// draws the input field
// automatic resize
void drawInputField(int windowLenght, char fullSentence[300], int sentanceLenght = 0)
{
    //setlinestyle(0, 1, 3);

    int necesaryRows = sentanceLenght / 100 + 1;
    int heightSize = 50 + necesaryRows * 20;

    rectangle(
        windowLenght / 2 - 350, 50,
        windowLenght / 2 + 350, heightSize
    );

    for(int i = 0 ; i < necesaryRows; i++)
    {
         outtextxy(windowLenght/2 - 350 + 2, heightSize - 20 + 2, fullSentence);
    }
}


/// -- READY --
// draw the table with the analyzed sentance
void drawTableField(
        int startX,
        int startY,
        int endX,
        int endY,
        char word[50])
{
    rectangle(
        startX,
        startY,
        endX,
        endY
    );

    outtextxy(startX + 3, startY + 3, word);
}



/// -- READY --
// reading input text from keyboard
// and display it on the viewport
void readingInputText(
        int windowLenght,
        char fullSentence[300],
        char auxCharacter)
{
    int counterFullSentence = 0;

    while((int)auxCharacter != ENTER_KEY)
    {
        // if backspace delete characters
        // else add characters
        if((int)auxCharacter == BACKSPACE_KEY && counterFullSentence > 0)
        {
            counterFullSentence--;
            fullSentence[counterFullSentence] = NULL;
        }
        else
        {
            fullSentence[counterFullSentence] = auxCharacter;
            counterFullSentence++;
        }

        clearviewport();

        drawInputField(windowLenght, fullSentence, counterFullSentence);

        //drawButton(120, 60);
        //buttonClicked(120, 60);

        auxCharacter = (char)getch( );
    }
}


/// -- READY --
// draw the input field with all the elements
void drawWholeTableField(
       char** eachWord,
       int numberOfWords,
       viewportPoint centerPoint,
       int fieldHeight = 1 ,
       int fieldLenght = 1)
{
    char temp[50];

    viewportPoint startPoint;
    startPoint.x = centerPoint.x - ((numberOfWords + 1) * (FIELD_LENGHT * 0.5));
    startPoint.y = 100; // need to be dynamic

    for(int i = 0; i < numberOfWords + 1; i++)
    {
        for(int j = 0; j < numberOfWords + 1; j++)
        {
            if(i == 0 && i != j)
            {
                temp[0] = j + '0';
            }
            else if(j == 0 && i != j)
            {
                strcpy(temp, eachWord[i - 1]);
            }
            else if(i == j && i == 0 && j == 0)
            {
                strcpy(temp, "");
            }
            else
            {
                strcpy(temp, "..."); // the word analyzed
            }

            drawTableField(
                startPoint.x + (fieldLenght * i),
                startPoint.y + (fieldHeight * j),
                startPoint.x + fieldLenght * (i + 1),
                startPoint.y + fieldHeight * (j + 1),
                temp
            );
        }
    }
}


/// -- READY --
// obtain each word from text
int getEachWordFromText(
        char* sentence,
        char** eachWord)
{
    int index = 0;
    char* word = strtok(sentence, " ");

    while(word)
    {
        eachWord[index] = word;
        index++;

        word = strtok(NULL, " ");
    }

    return index;
}


/// -- READY --
// initiate the whole sentance with NULL
void resetSentence(char fullSentence[300])
{
    for(int i = 0; i < 300; i++)
    {
        fullSentence[i] = NULL;
    }
}


// main
int main()
{
    char inputCharacter;

    char fullSentence[300];
    resetSentence(fullSentence);

    // alocate memory for 2-dimensional array
    char** eachWord;
    eachWord = new char*[50];
    for(int i = 0; i < 50; i++)
    {
        eachWord[i] = new char[50];
    }

    int numberOfWords;

    int windowHeight = 600;
    int windowLenght = 1200;

    viewportPoint centerPoint;
    centerPoint.x = windowLenght / 2;
    centerPoint.y = windowHeight / 2;

    initwindow(windowLenght, windowHeight);

    //drawButton(120, 120);
    drawInputField(windowLenght, fullSentence);

    // code goes here
    //      ||
    //      ||
    //      \/

    inputCharacter = (char)getch();

    while(true)
    {
        readingInputText(windowLenght, fullSentence, inputCharacter);
        numberOfWords = getEachWordFromText(fullSentence, eachWord);

        drawInputField(windowLenght, fullSentence);
        drawWholeTableField(
                        eachWord,
                        numberOfWords,
                        centerPoint,
                        FIELD_HEIGHT,
                        FIELD_LENGHT);

        inputCharacter = (char)getch();

        if((int)inputCharacter == CLOSE_KEY_1 || (int)inputCharacter == CLOSE_KEY_2)
        {
            break;
        }
        else
        {
            resetSentence(fullSentence);
            clearviewport();
            drawInputField(windowLenght, fullSentence);
        }
    }

    //      /\
    //      ||
    //      ||
    // code goes here

    getch();
    closegraph();

    return 0;
}
