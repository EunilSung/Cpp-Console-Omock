#include <iostream>
#include <string>
using namespace std;
void initGame(string bord[][19],int BACKGROUND_WITH, int BACKGROUND_HIGHT, bool &isColor, int &result);
bool inputStone(string bord[][19],int &x, int &y, bool isColor);
void drawGame(string bord[][19], int with, int hight, bool isColor, int result);
bool gameResult(string bord[][19], int BACKGROUND_WITH, int BACKGROUND_HIGHT);
int main()
{
    const int BACKGROUND_WITH = 19;
    const int BACKGROUND_HIGHT = 19;
    bool isColor = true;
    bool isGameOver = false;
    int x, y;
    int result = 0;
    string bord[BACKGROUND_HIGHT][BACKGROUND_WITH];
    initGame(bord, BACKGROUND_WITH, BACKGROUND_HIGHT,isColor,result);

    while (true) {
       
        drawGame(bord, BACKGROUND_WITH, BACKGROUND_HIGHT,isColor, result);
        result = 0;
        if (inputStone(bord, x, y, isColor)) {
            result = 1;
            continue;
        }
        if (isColor)
            isColor = false;
        else
            isColor = true;
       
        if (gameResult(bord, BACKGROUND_WITH, BACKGROUND_HIGHT)) {
            result = 2;
            drawGame(bord, BACKGROUND_WITH, BACKGROUND_HIGHT, isColor, result);
            char restart;
            cout << "다시 시작하시겠습니까?(y/n)";
            cin >> restart;
            if (restart == 'y') {
                initGame(bord, BACKGROUND_WITH, BACKGROUND_HIGHT,isColor,result);
           
            }
            else if (restart == 'n')
                return 0;
        }
    }
}
void initGame(string bord[][19], int BACKGROUND_WITH, int BACKGROUND_HIGHT, bool &isColor, int &result) {
    isColor = true;
    result = 0;
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
}

void drawGame(string bord[][19], int BACKGROUND_WITH, int BACKGROUND_HIGHT, bool isColor, int result) {
    system("cls");
    cout << "      ====== Let's Play Omok ======" << endl;
    for (int i = 0; i <= BACKGROUND_HIGHT; i++) {
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
    if (result == 1) {
        cout << "돌을 놓을 수 없습니다. 다시 시도해 주세요"<<endl;
        isColor ? cout << "●'s X,Y: " : cout << "○'s X,Y: ";
    }
    else if(result==2)
        isColor ? cout << "○'s 승리: ": cout << "●'s 승리: ";
    else
    isColor ? cout << "●'s X,Y: " : cout << "○'s X,Y: ";
}

bool inputStone(string bord[][19], int& x, int& y, bool isColor) {
    cin >> x >> y;
    if (x > 19 || y > 19)
        return true;
    x--; y--;
    if (bord[y][x] == "●" || bord[y][x] == "○")
        return true;

    if (isColor) 
        bord[y][x] = "●";
    else 
        bord[y][x] = "○";
    return false;
}
bool gameResult(string bord[][19], int BACKGROUND_WITH, int BACKGROUND_HIGHT) {
    for (int i = 0; i < BACKGROUND_HIGHT; i++) {
        for (int j = 0; j < BACKGROUND_WITH; j++) {
            if (bord[i][j] == "●" || bord[i][j] == "○") {
                if (bord[i][j] == bord[i + 1][j] && bord[i][j] == bord[i + 2][j]
                    && bord[i][j] == bord[i + 3][j] && bord[i][j] == bord[i + 4][j]) {
                    return true;
                }
                if (bord[i][j] == bord[i][j + 1] && bord[i][j] == bord[i][j + 2]
                    && bord[i][j] == bord[i][j + 3] && bord[i][j] == bord[i][j + 4]) {
                    return true;
                }
                if (bord[i][j] == bord[i + 1][j + 1] && bord[i][j] == bord[i + 2][j + 2]
                    && bord[i][j] == bord[i + 3][j + 3] && bord[i][j] == bord[i + 4][j + 4]) {
                    return true;
                }
                if (bord[i][j] == bord[i + 1][j - 1] && bord[i][j] == bord[i + 2][j - 2]
                    && bord[i][j] == bord[i + 3][j - 3] && bord[i][j] == bord[i + 4][j - 4]) {
                    return true;
                }
            }
        }
    }
    return false;
}