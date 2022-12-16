#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
    initwindow(450, 300);
    readimagefile("image.jpg", 0, 0, 100, 100);

    getch();
    closegraph();
    return 0;
}
