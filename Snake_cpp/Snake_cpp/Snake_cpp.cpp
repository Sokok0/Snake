// Snake_cpp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;



bool isGameOver;

int width = 20;
int height = 20;

int x, y, fruit_X, fruit_Y, score;

int tail_X[100], tail_Y[100];
int tailLength;

enum Direction
{
    stop,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

Direction direction;

void Setup()
{
    isGameOver = false;
    direction = stop;
    x = width / 2; //glowa na srodku
    y = height / 2;
    fruit_X = rand() % width;
    fruit_Y = rand() % height;
    score = 0;


}

void Board()
{
    cout << system("cls");
    for (int i = 0; i <= width; i++)
    {
        cout << " @";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            
                cout << "@";
                
                
            
            if(i == y && j == x)
            
                cout << "O";
            
            else if (i == fruit_Y && j == fruit_X)
             
                cout << " F";
            else
            {
                bool print = false;
                for (int k = 0; k < tailLength; k++)
                {
                    
                    if (tail_X[k] == j && tail_Y[k] == i)
                    {
                        cout << "o";
                    }
                    
                }
                if (!print)
                    {
                        cout << "  ";
                    }
                
            }
            

            if (j == width - 1)
            {
                cout << " @";
                cout << endl;
            }
            
        }
    }
    for (int i = 0; i <= width; i++)
    {
        cout << " @";
    }
    cout << endl;
    cout << "Score: " << score <<endl;
}

void Movement()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'w':
            direction = UP;
            break;
        case 's':
            direction = DOWN;
            break;
        case 'x':
            isGameOver = true;
            
            cout << "End gry. You ended grę z score: " << score << endl;
            break;
        default:
            break;

        }
    }
}

void Logic()
{
    int previous_X = tail_X[0];
    int previous_Y = tail_Y[0];
    int previous2_X, previous2_Y;
    tail_X[0] = x;
    tail_Y[0] = y;
    for (int i = 1; i < tailLength; i++)
    {
        previous2_X = tail_X[i];
        previous2_Y = tail_Y[i];
        tail_X[i] = previous_X;
        tail_Y[i] = previous_Y;
        previous_X = previous2_X;
        previous_Y = previous2_Y;
    }
    switch (direction)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;

    }
    if (x > width || x < 0 || y > height || y < 0)
    {
        isGameOver = true;
    }
    if (x == fruit_X && y == fruit_Y)
    {
        score += 10;
        fruit_X = rand() % width;
        fruit_Y = rand() % height;
        tailLength++;
    }
    for (int i = 0; i < tailLength; i++)
    {
        if (tail_X[i] == x && tail_Y[i] == y)
        {
            isGameOver = true;
        }
    }
}
    
int main()
{
    Setup();
    while (!isGameOver)
        {
        Board();
        Movement();
        Logic();
        
        
        Sleep(100);
    }
    

}
