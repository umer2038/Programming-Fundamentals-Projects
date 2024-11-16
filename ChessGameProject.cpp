/// Muhammad Umer Siddiqui
                                                        /// 22I-2038
                                                        /// Abdullah Bin Irshad
                                                        /// 22I-1912
                                                        /// PF-A
                                                        /// Save The King ( Two Player Game )
                                                        /// Instructor : Miss Maryam Shahbaz

#include <iostream>

#include <cstdlib>

#include <Windows.h>

#include <iomanip>

#include <ctime>

using namespace std;

const char KING = 'K';
const char KNIGHT = 'N';
const char BISHOP = 'B';

bool KingValidation(const char board[][8], int r, int c);
void start();
void RandomPosition(int& r, int& c);
bool attack(char type1, int r1, int c1, char type2, int r2, int c2);
void ChessBoard(const char board[][8]);
void BBoard(char board[][8]);
void ChessPiece(char board[][8], int r, int c, char symbol);
void UpdateRC(char board[][8], int r, int c);
bool Validation(int r, int c);
void TURN(char board[][8], int& kingR, int& kingC, char playerPiece, const string& Name);

/// Int Main ///
int main()
{

    start();
    return 0;
}

/// \\\ 
                    /// For Kings Move Validation
bool KingValidation(const char board[][8], int r, int c) {
    int moves[8][2] = {
            {
                    -1, 0
            },
            {
                    1,
                    0
            },
            {
                    0,
                    -1
            },
            {
                    0,
                    1
            },
            {
                    -1,
                    -1
            },
            {
                    -1,
                    1
            },
            {
                    1,
                    -1
            },
            {
                    1,
                    1
            }
    };


    // Calculates new row and column and Updates empty cells with '-'
    int i = 0;
    while (i < 8)
    {

        int newC = c + moves[i][1];

        int newR = r + moves[i][0];

        switch (board[newR][newC])
        {

        case '-':
            if (Validation(newR, newC))
            {

                return true;

            }

            break;

        default:

            break;
        }

        i++;
    }

    return false;
}

void start() {
    // Handle is a Data Type
    // For heading

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    int consoleWidth = consoleInfo.dwSize.X;
    cout << "                       ";
    string text = "                                (-: Chess is a Game of Skill, Luck & Practice <> GoodLuck to Both the Players :-)";

    int leftMargin;
    leftMargin = (consoleWidth - text.length()) / 2;
    cout << string(leftMargin, ' ') << text << endl;

    /// For Background Colour
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout << setw(15) << endl << "                                                           *** WELCOME TO SAVE THE KING GAME MADE BY UMER AND ABDULLAH *** " << endl << endl << endl;

    // For telling Rulles
    string rules;
    cout << "Enter 'yes' if you know the rules of chess and 'no' if you do not know the rules : ";
    cin >> rules;

    if (rules == "no")
    {

        cout << "Here are the basic rules for chess:" << endl;

        cout << "1. The game is played on an 8x8 board with alternating black and white squares." << endl;

        cout << "2. Each player starts with 16 pieces: one king, one queen, two rooks, two knights, two bishops, and eight pawns." << endl;

        cout << "3. The pieces move in specific ways: " << endl;
        cout << "- The king can move one square in any direction." << endl;
        cout << "- The queen can move any number of squares in any direction." << endl;
        cout << "- The rook can move any number of squares vertically or horizontally." << endl;
        cout << "- The bishop can move any number of squares diagonally." << endl;
        cout << "- The knight moves in an L-shape: two squares in one direction and then one square perpendicular to that." << endl;
        cout << "- The pawn can move one square forward, but on its first move it can choose to move two squares forward. Pawns capture diagonally." << endl;

        cout << "4. The goal of the game is to checkmate the opponent's king, which means putting it under attack (in check) with no legal move to escape." << endl;

        cout << "5. The game can also end in a draw:" << endl;
        cout << "- Stalemate: when a player is not in check, but has no legal move to make." << endl;
        cout << "- Threefold repetition: when the same position is repeated three times." << endl;
        cout << "- Fifty-move rule: when no pawn has been moved and no capture has been made in the last fifty moves." << endl;
        cout << "- Insufficient material: when neither player has enough pieces to checkmate the other." << endl;

        cout << "6. The game starts with white making the first move, and players take turns making one move at a time." << endl;
    }

    srand(time(0));

    char board[8][8];
    BBoard(board);

    int kingR;
    int kingC;

    RandomPosition(kingR, kingC);
    ChessPiece(board, kingR, kingC, KING);

    int oppR1, oppC1, oppR2, oppC2;
    do
    {
        RandomPosition(oppR1, oppC1);
        RandomPosition(oppR2, oppC2);
    } while (attack(KING, kingR, kingC, KNIGHT, oppR1, oppC1) || attack(KING, kingR, kingC, KNIGHT, oppR2, oppC2) || attack(KING, kingR, kingC, BISHOP, oppR2, oppC2) || attack(KING, kingR, kingC, BISHOP, oppR1, oppC1));


    ChessPiece(board, oppR2, oppC2, BISHOP);
    ChessPiece(board, oppR1, oppC1, BISHOP);

    string player1;
    cout << endl;
    string player2;

    cout << endl;
    cout << "=> Enter the name for Player #1: ";
    cin >> player1;
    cout << endl;
    cout << "=> Enter the name for Player #2: ";
    cin >> player2;

    bool game = false;
    int player = 1;

    time_t time1;
    time1 = time(nullptr);

    while (!game)
    {
        ChessBoard(board);

        /// For Time
        time_t time2;
        int seconds;
        int minutes;
        int currentR;
        int currentC;
        char playerPiece = ' ';


        time2 = time(nullptr);
        int totaltime = time2 - time1;

        minutes = totaltime / 60;

        seconds = totaltime % 60;
        cout << endl;
        cout << endl;
        cout << "The Time is : " << minutes << "m " << seconds << "s " << endl;
        cout << endl << endl;


        switch (player) {
        case 1:
            currentC = kingC;
            currentR = kingR;
            playerPiece = 'P';

            TURN(board, kingR, kingC, playerPiece, player1);
            break;
        default:
            currentR = oppR1;
            currentC = oppC1;
            playerPiece = 'O';

            TURN(board, oppR1, oppC1, playerPiece, player2);
            break;
        }

        if (attack(playerPiece, currentR, currentC, KING, kingR, kingC))
        {
            game = true;
            cout << "The Player : " << player << " has won!" << endl;

        }
        else
        {
            if (!KingValidation(board, kingR, kingC))
            {
                game = true;
                cout << "The game has resulted in a draw." << endl;

            }
        }

        switch (player)
        {
        case 1:
            player = 2;
            break;
        case 2:
            player = 1;
            break;
        }
    }
}

void RandomPosition(int& r, int& c)
{
    c = rand() % 8;
    r = rand() % 8;
}

// To check If it has Attacked Each Other 
bool attack(char type1, int r1, int c1, char type2, int r2, int c2)
{
    // abs gives posiitve value
    if (abs(r1 - r2) == abs(c1 - c2))
    {
        return true;
    }

    if (r1 == r2 && c1 == c2)
    {
        return true;
    }

    return false;
}

// Starting Chess Board
void ChessBoard(const char board[][8])
{
    cout << endl;
    cout << "  ";
    cout << "The Following is Your ChessBoard, Goodluck!!!" << endl << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int i = 0;
    while (i < 8) {
        cout << i << " ";

        int j = 0;
        while (j < 8) {
            cout << board[i][j] << " ";
            j++;
        }

        cout << endl;
        i++;
    }

}


void BBoard(char board[][8])
{
    int i = 0;
    while (i < 8) {
        int j = 0;
        while (j < 8) {
            board[i][j] = '-';
            j++;
        }
        i++;
    }

}
void ChessPiece(char board[][8], int r, int c, char symbol)
{
    board[r][c] = symbol;
}

/// To update board
void UpdateRC(char board[][8], int r, int c) {
    board[r][c] = '-';
}

bool Validation(int r, int c) {
    return (r >= 0 && r < 8 && c >= 0 && c < 8);
}

// For turn
void TURN(char board[][8], int& kingR, int& kingC, char playerPiece, const string& Name) {
    cout << "It is " << Name << "'s turn:" << endl;
    int newR;
    int newC;
    bool isValidMove = false;
    while (!isValidMove) {
        cout << "Enter the row: ";
        cin >> newR;
        cout << "Enter the column: ";
        cin >> newC;

        if (Validation(newR, newC))
        {
            /// Abs for +ve answer
            switch (abs(newR - kingR) <= 1 && abs(newC - kingC) <= 1)
            {
            case true:
                isValidMove = true;
                break;
            default:
                cout << "Invalid Step! Enter Again:" << endl;
                break;
            }

        }
        else {
            cout << "Invalid Step! Enter Again:" << endl;
        }
    }

    UpdateRC(board, kingR, kingC);
    kingR = newR;
    kingC = newC;
    ChessPiece(board, kingR, kingC, KING);
    ChessBoard(board);
}

/* int arr[8][8] ;
    for (int i = 0; i < 8; i++)
    {
        cout << endl;
        for (int j = 0; j < 8; j++)
        {
            cout << arr[i][j] <<" ";
        }
    }	cout << endl;cout << endl;cout << endl;
    for (int i = 0; i < 8; i++)
    {if (i == 0)
        {
            for (int j = 0; j < 3; j){	cout << arr[i][j] << "-";
            }}
        for (int j = 0; j < 8; j++)
        { if (j == 3)
            {cout << arr[i][j] << "-";}
        }

        for (int j = 2; j > 8; j--)
        {
            if (i == 1)

            {cout << arr[i][j] << "-";	}
        }
    }for (int i = 3; i > 0; i--)
    {for (int j = 0; j < 4; j++)
        {
            if (j == 0){cout << arr[i][j] << "-";}
        }
        if (i == 1)
        {
            for (int j = 1; j < 3; j++)
            {
                cout << arr[i][j] << "-";
            }
        }

    }
    for (int i = 3; i > 0; i--)
    {

        if (i == 2)
        {
            for (int j = 2; j >= 0; j--)
            {
                cout << arr[i][j] << "-";
            }
        }
    }
    for (int i = 3; i >=0; i--)
    {if (i == 0)
        {
            for (int j = 0; j < 3; j++)
            {cout << arr[i][j] << "-";}
        }
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                cout << arr[i][j] << "-";
            }
        }

        for (int j = 2; j > 0; j--)
        {
            if (i == 3)

            {
                cout << arr[i][j] << "-";
            }
        }


    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                cout << arr[i][j] << "-";
            }
        }
        if (i == 1)
        {
            for (int j = 1; j < 3; j++)
            {
                cout << arr[i][j] << "-";
            }
        }

    }
    for (int i = 0; i >4; i++)
    {

        if (i == 2)
        {
            for (int j = 2; j >= 0; j--)
            {
                cout << arr[i][j] << "-";
            }
        }}*/

        /*
        int arr[8][8];


                for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {


                        }
                }

                for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                                if (i % 2 != 0 && j % 2 != 0)

                        }
                }*/
