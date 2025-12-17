#include <iostream>

#define BOARD_SIZE 3
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"

using namespace std;
class TicTacToe
{
private:
    char board[BOARD_SIZE][BOARD_SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char cur_mark;
    int cur_player;

public:
    TicTacToe(char a) : cur_mark(a), cur_player(1) {}
    ~TicTacToe() { cout << "\nGame over!" << endl; }

    friend void titleScreen();

    void drawBoard()
    {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "| ";
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 'X')
                {
                    cout << RED << board[i][j] << RESET;
                }
                else if (board[i][j] == 'O')
                {
                    cout << BLUE << board[i][j] << RESET;
                }
                else
                {
                    cout << board[i][j];
                }
                cout << " | ";
            }
            cout << endl
                 << "-------------" << endl;
        }
    }

    bool placeMarker(int place)
    {
        int row = (place - 1) / BOARD_SIZE;
        int col = (place - 1) % BOARD_SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = cur_mark;
            return true;
        }
        return false;
    }

    int winner()
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i][0] == board[i][1] && board[i][2] == board[i][1])
                return cur_player;
            if (board[0][i] == board[1][i] && board[2][i] == board[1][i])
                return cur_player;
        }

        if (board[0][0] == board[1][1] && board[2][2] == board[1][1])
            return cur_player;
        if (board[0][2] == board[1][1] && board[2][0] == board[1][1])
            return cur_player;

        return 0;
    }

    void changePlayer()
    {
        cur_player = (cur_player == 1) ? 2 : 1;
    }

    void changeMark()
    {
        cur_mark = (cur_mark == 'X') ? 'O' : 'X';
    }

    int getPlayer() { return cur_player; }
    char getMark() { return cur_mark; }
};

void titleScreen()
{
    cout << GREEN;
    cout << "  _______ _____ _____   _______       _____   _______ ____  ______ " << endl;
    cout << " |__   __|_   _/ ____| |__   __|/\\   / ____| |__   __/ __ \\|  ____|" << endl;
    cout << "    | |    | || |         | |  /  \\ | |         | | | |  | | |__   " << endl;
    cout << "    | |    | || |         | | / /\\ \\| |         | | | |  | |  __|  " << endl;
    cout << "    | |   _| || |____     | |/ ____ \\ |____     | | | |__| | |____ " << endl;
    cout << "    |_|  |_____\\_____|    |_/_/    \\_\\_____|    |_|  \\____/|______|" << endl;
    cout << RESET << endl;
    cout << "                Press ENTER to start the game..." << endl;
    cin.get();
}

int main()
{
    titleScreen();
    char mark;

    cout << YELLOW << "Player 1! Choose your marker (X or O): " << RESET;
    cin >> mark;
    cin.ignore(1000, '\n');
    TicTacToe game(mark);

    game.drawBoard();

    for (int i = 0; i < (BOARD_SIZE * BOARD_SIZE); i++)
    {
        int place;
        string color = (game.getPlayer() == 1) ? RED : BLUE;
        cout << color << "Player " << game.getPlayer() << YELLOW << "'s turn. Enter a place to put your marker: " << RESET;
        cin >> place;

        if (place < 1 || place > 9 || !game.placeMarker(place))
        {
            cout << RED << "Invalid move! Try again." << RESET << endl;
            i--;
            continue;
        }

        game.drawBoard();
        if (game.winner() != 0)
        {
            cout << GREEN << "============================" << endl;
            cout << "   PLAYER " << game.getPlayer() << " IS THE WINNER!  " << endl;
            cout << "============================" << RESET << endl;
            return 0;
        }

        game.changePlayer();
        game.changeMark();
    }

    cout << GREEN << "It's a tie!" << RESET << endl;

    return 0;
}
