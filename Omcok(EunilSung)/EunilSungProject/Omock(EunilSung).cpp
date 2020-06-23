#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int BACKGROUND_WITH = 19;
    const int BACKGROUND_HIGHT = 19;
    bool isColor = true;
    int x, y;
    string bord[BACKGROUND_HIGHT][BACKGROUND_WITH];
    for (int i = 0; i < BACKGROUND_HIGHT; i++) {
        for (int j = 0; j < BACKGROUND_WITH; j++) {
            if (i == 0) {
                if (j == 0)
                    bord[i][j] = "┌─";
                else if (j == BACKGROUND_WITH - 1)
                    bord[i][j] = "┐";
                else
                    bord[i][j] = "┬─";
            }
            else if (i == BACKGROUND_HIGHT - 1) {
                if (j == 0)
                    bord[i][j] = "└─";
                else if (j == BACKGROUND_WITH - 1)
                    bord[i][j] = "┘";
                else
                    bord[i][j] = "┴─";
            }
            else {
                if (j == 0)
                    bord[i][j] = "├─";
                else if (j == BACKGROUND_WITH - 1)
                    bord[i][j] = "┤";
                else
                    bord[i][j] = "┼─";
            }
        }
    }
    cout << "      ====== Let's Play Omok ======" << endl;

    while (true) {
        system("cls");
        for (int i = 0; i <= BACKGROUND_WITH; i++) {
            if (i == 0)
                cout << "  ";
            else if (i < 10)
                cout << i << " ";
            else
                cout << i;
        }
        cout << endl;

        for (int i = 0; i < BACKGROUND_HIGHT; i++) {
            i < 9 ? cout << " " << i + 1 : cout << i + 1;
            for (int j = 0; j < BACKGROUND_WITH; j++) {
                cout << bord[i][j];
            }
            cout << endl;
        }
      
        isColor ? cout << "●'s X,Y: " : cout << "○'s X,Y: ";
        cin >> x >> y;
        if (x == 99 && y == 99)
            return 0;
        else if (x > 19 || y > 19)
            continue;

        x--; y--;
        if (bord[y][x] == "●" || bord[y][x] == "○")
            continue;

        if (isColor) {
            bord[y][x] = "●";
            isColor = false;
        }
        else {
            bord[y][x] = "○";
            isColor = true;
        }
    }
}