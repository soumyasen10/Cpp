#include <bits/stdc++.h>
#include <conio.h>
#include <graphics.h>

int main()
{

    int gdriver = DETECT, gmode, errorcode;

    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
 

    errorcode = graphresult();
    if (errorcode == grOk)

        cout << "Graphics enabled: \n"

             << grapherrormsg(errorcode);

    else

        cout << "Graphics error: \n"

             << grapherrormsg(errorcode);
 

    getch();
 

    closegraph();

    return 0;
}
