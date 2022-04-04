//Peseudocode
/*
Create an empty Tic-Tac-Toe board
Display the game instructions
Determine who goes first
Display the board
While nobody's won and it's not a tie
    If it's the human's turn
        Get the human's move
        Update the board with the human's move
    Otherwise
        Calculate the computer's move
        Update the board with the computer's move
    Display the board
    Switch turns
Congratulate the winner or declare a tie
*/

//Tic-Tac-Toe
//Plays the game of tic-tac-toe against a human opponent

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


//global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//function prototpyes
void instruction();
char askYesNo(std::string question);
int askNumber(std::string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const std::vector<char>* const board);
char winner(const std::vector<char>* const board);
bool isLegal(const std::vector<char>* const board, int move);
int humanMove(const std::vector<char>* const board, char human);
int computerMove(std::vector<char>* const board, char computer);
void announceWinner(char winner, char computer, char human);

//main function
int main(){
    int move;
    const int NUM_SQUARE = 9;
    std::vector<char> board(NUM_SQUARE, EMPTY);
    //for(int i = 0; i < NUM_SQUARE; i++) std::cout << i;

    instruction();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(&board); //bug

    while(winner(&board) == NO_ONE){
        if(turn == human){
            move = humanMove(&board, human);
            board[move] = human;
        } else {
            move = computerMove(&board, computer);
            board[move] = computer;
        }
        displayBoard(&board);
        turn = opponent(turn);
    }

    announceWinner(winner(&board), computer, human);
    return 0;
}

void instruction(){
    std::cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    std::cout << "--where human brain is pit against silicon processor\n\n";

    std::cout << "Make your move know by entering a number, 0 - 8. The number\n";
    std::cout << "correspond to the desired board position, as illustrated:\n\n";

    std::cout << "      0 | 1 | 2\n";
    std::cout << "      3 | 4 | 5\n";
    std::cout << "      6 | 7 | 8\n\n";

    std::cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char askYesNo(std::string question){
    char response;
    do {
        /* code */
        std::cout << question << " (y/n): ";
        std::cin >> response;
    } while (response != 'y' && response != 'n');
    
    return response;
}

int askNumber(std::string question, int high, int low)
{
    int number;
    do {
        std::cout << question << " (" << low << " - " << high << "): ";
        std::cin >> number;
    } while(number > high || number < low);

    return number;
}

char humanPiece(){
    char go_first = askYesNo("Do you require the first move?");
    if(go_first == 'y'){
        std::cout << "\nThen take the first move. You will need it.\n";
        return X;
    } else {
        std::cout << "\nYour bravery will be your undoing... I will go first.\n";
        return O;
    }
}

char opponent(char piece)
{
    if (piece == X){
        return O;
    } else {
        return X;
    }
}

void displayBoard(const std::vector<char>* const board){
    std::cout << "\n\t"  << (*board)[0] << " | " << (*board)[1] << " | " << (*board)[2];
    std::cout << "\n\t" << "---------";
    std::cout << "\n\t"  << (*board)[3] << " | " << (*board)[4] << " | " << (*board)[5];
    std::cout << "\n\t" << "---------";
    std::cout << "\n\t"  << (*board)[6] << " | " << (*board)[7] << " | " << (*board)[8];
    std::cout << "\n\n";
}

char winner(const std::vector<char>* const board){
    //all possible winning rows
    const int WINNING_ROW[8][3] = { {0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6} };
    const int TOTAL_ROWS = 8;

    //if any winning row has three values that are the same (and not EMPTY),
    //then we have a winner
    for(int row = 0; row < TOTAL_ROWS; row++){
        if( ((*board)[WINNING_ROW[row][0]] != EMPTY) &&
            ((*board)[WINNING_ROW[row][0]] == (*board)[WINNING_ROW[row][1]]) &&
            ((*board)[WINNING_ROW[row][0]] == (*board)[WINNING_ROW[row][2]]) ){
            return (*board)[WINNING_ROW[row][0]];
        }
    }

    //since nobody has won, check for a tie (no empty squares left)
    if(std::count(board->begin(), board->end(), EMPTY) == 0)
        return TIE;
    
    //since nobody has won and it isn't a tie, the game ain't over
    return NO_ONE;
}

inline bool isLegal(const std::vector<char>* const board, int move){
    return ((*board)[move] == EMPTY);
}

int humanMove(const std::vector<char>* const board, char human){
    int move = askNumber("Where will you move?", (board->size() - 1));
    while(!isLegal(board, move)){
        std::cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", (board->size() - 1));
    }
    std::cout << "Fine...\n";
    return move;
}

int computerMove(std::vector<char>* const board, char computer){
    unsigned int move = 0;
    bool found = false;

    //if computer can win on next move, that's the move to make
    while(!found && move < board->size()){
        if(isLegal(board, move)){
            (*board)[move] = computer;
            found = winner(board) == computer;
            (*board)[move] = EMPTY;
        }

        if(!found){
            move++;
        }
    }

    //otherwise, if human can win on the next one, that's the move to make
    if(!found){
        move = 0;
        char human = opponent(computer);

        while(!found && move < board->size()){
            if(isLegal(board, move)){
                (*board)[move] = human;
                found = winner(board) == human;
                (*board)[move] = EMPTY;
            }

            if(!found){
                move++;
            }
        }
    }

    if(!found){
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVE[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        //pick best open square
        while (!found && i < board->size()){
            move = BEST_MOVE[i];
            if(isLegal(board, move)){
                found = true;
            }
            i++;
        }
    }

    std::cout << "I shall take the square number " << move << std::endl;
    return move;
}

void announceWinner(char winner, char computer, char human){
    if(winner == computer){
        std::cout << winner << "'s won!\n";
        std::cout << "As I predicted, human, I am triumphant once more -- proof\n";
        std::cout << "that computers are superior to humans in all regard.\n";
    } else if(winner == human){
        std::cout << winner << "'s won!\n";
        std::cout << "No, no! It cannot be! Somehow you tricked me, human.\n";
        std::cout << "But never again! I, the computer, so swear it!\n";
    } else{
        std::cout << "It's a tie.\n";
        std::cout << "You were most lucky, human, and somehow managed to tie me.\n";
        std::cout << "Celebrate... for this is the best you will ever achieve.\n";
    }
}