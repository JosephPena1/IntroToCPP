#include <iostream>

void printArray(char arr[][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++) 
        {
            std::cout << arr[row][col];
        }
    }
}

int main()
{
    bool gameOver = false;
    char grid[3][3] = { {'0', '0', '0'}, {'0', '0', '0'}, {'0', '0', '0'} };

    char player1Icon = 'X';
    int player1Row = 0;
    int player1Col = 0;

    char player2Icon = 'O';
    int player2Row = 0;
    int player2Col = 0;

    char player1[10];
    std::cout << "Enter player 1's name" << std::endl;
    std::cin >> player1;

    char player2[10];
    std::cout << "Enter player 2's name" << std::endl;
    std::cin >> player2;
    system("cls");

    while (!gameOver)
    {
        bool player1Choice = false;
        while (!player1Choice)
        {
            for (int row = 0; row < 3; ++row)
            {
                for (int col = 0; col < 3; ++col)
                {
                    std::cout << " " << grid[row][col];
                }

                std::cout << std::endl;
            }

            //player 1's turn
            int player1KeyPress = 0;
            std::cout << player1 << " [" << player1Icon << "] " << std::endl;
            std::cout << "Select a position using the Keypad 1-9" << std::endl;
            std::cout << "> ";
            std::cin >> player1KeyPress;
            switch (player1KeyPress)
            {
            case 1:
                player1Row = 2;
                player1Col = 0;
                break;
            case 2:
                player1Row = 2;
                player1Col = 1;
                break;
            case 3:
                player1Row = 2;
                player1Col = 2;
                break;
            case 4:
                player1Row = 1;
                player1Col = 0;
                break;
            case 5:
                player1Row = 1;
                player1Col = 1;
                break;
            case 6:
                player1Row = 1;
                player1Col = 2;
                break;
            case 7:
                player1Row = 0;
                player1Col = 0;
                break;
            case 8:
                player1Row = 0;
                player1Col = 1;
                break;
            case 9:
                player1Row = 0;
                player1Col = 2;
                break;
            }
            if (grid[player1Row][player1Col] == player2Icon || grid[player1Row][player1Col] == player1Icon)
            {
                std::cout << "invalid move, try again" << std::endl;
                system("pause");
                system("cls");
            }
            else
                player1Choice = true;
        }
        grid[player1Row][player1Col] = player1Icon;
        system("cls");

        //checks if player 1 has won.
        if ((grid[0][0] == player1Icon && grid[0][1] == player1Icon && grid[0][2] == player1Icon) ||
            (grid[1][0] == player1Icon && grid[1][1] == player1Icon && grid[1][2] == player1Icon) ||
            (grid[2][0] == player1Icon && grid[2][1] == player1Icon && grid[2][2] == player1Icon) ||
            (grid[0][0] == player1Icon && grid[1][0] == player1Icon && grid[2][0] == player1Icon) ||
            (grid[0][1] == player1Icon && grid[1][1] == player1Icon && grid[2][1] == player1Icon) ||
            (grid[0][2] == player1Icon && grid[1][2] == player1Icon && grid[2][2] == player1Icon) ||
            (grid[0][0] == player1Icon && grid[1][1] == player1Icon && grid[2][2] == player1Icon) ||
            (grid[0][2] == player1Icon && grid[1][1] == player1Icon && grid[2][0] == player1Icon))
        {
            std::cout << player1 << " wins!" << std::endl;
            system("pause");
            gameOver = true;
            break;
        }

        bool player2Choice = false;
        while (!player2Choice)
        {
            for (int row = 0; row < 3; ++row)
            {
                for (int col = 0; col < 3; ++col)
                {
                    std::cout << " " << grid[row][col];
                }

                std::cout << std::endl;
            }

            //player 2's turn
            int player2KeyPress = 0;
            std::cout << player2 << " [" << player2Icon << "] " << std::endl;
            std::cout << "Select a position using the Keypad 1-9" << std::endl;
            std::cout << "> ";
            std::cin >> player2KeyPress;
            switch (player2KeyPress)
            {
            case 1:
                player2Row = 2;
                player2Col = 0;
                break;
            case 2:
                player2Row = 2;
                player2Col = 1;
                break;
            case 3:
                player2Row = 2;
                player2Col = 2;
                break;
            case 4:
                player2Row = 1;
                player2Col = 0;
                break;
            case 5:
                player2Row = 1;
                player2Col = 1;
                break;
            case 6:
                player2Row = 1;
                player2Col = 2;
                break;
            case 7:
                player2Row = 0;
                player2Col = 0;
                break;
            case 8:
                player2Row = 0;
                player2Col = 1;
                break;
            case 9:
                player2Row = 0;
                player2Col = 2;
                break;
            }
            if (grid[player2Row][player2Col] == player1Icon || grid[player2Row][player2Col] == player2Icon)
            {
                std::cout << "invalid move, try again" << std::endl;
                system("pause");
                system("cls");
            }
            else
                player2Choice = true;
        }
        
        system("cls");
        grid[player2Row][player2Col] = player2Icon;

        //checks if player 2 has won.
        if ((grid[0][0] == player2Icon && grid[0][1] == player2Icon && grid[0][2] == player2Icon) ||
            (grid[1][0] == player2Icon && grid[1][1] == player2Icon && grid[1][2] == player2Icon) ||
            (grid[2][0] == player2Icon && grid[2][1] == player2Icon && grid[2][2] == player2Icon) ||
            (grid[0][0] == player2Icon && grid[1][0] == player2Icon && grid[2][0] == player2Icon) ||
            (grid[0][1] == player2Icon && grid[1][1] == player2Icon && grid[2][1] == player2Icon) ||
            (grid[0][2] == player2Icon && grid[1][2] == player2Icon && grid[2][2] == player2Icon) ||
            (grid[0][0] == player2Icon && grid[1][1] == player2Icon && grid[2][2] == player2Icon) ||
            (grid[0][2] == player2Icon && grid[1][1] == player2Icon && grid[2][0] == player2Icon))
        {
            std::cout << player2 << " wins!" << std::endl;
            system("pause");
            gameOver = true;
            break;
        }
        player1Choice = false;
        player2Choice = false;
    }
}