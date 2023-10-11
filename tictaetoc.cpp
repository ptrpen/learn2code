#include<iostream>

#define _STARTING_PLAYER_ 'X'
#define _PLAYER2_ 'O'
int board[3][3] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
char drawBoard[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

class Game
{
private:
    char player;
    int userInput;
    int turn;
    int data[9];
public:
    Game(): player(_STARTING_PLAYER_), userInput(0),turn(0) {}
    bool Running() {
        if(turn < 9)
            return 1;
        return 0;
    }
    void Draw() {

        for(int i = 0; i < 3; i++) {
            std::cout<<"\n----------------------------------"<<std::endl;
            std::cout<<"|          |          |          |\n";
            for(int j = 0; j <3; j++) {
                std::cout<<"| ";
                std::cout<<"   "<<drawBoard[i][j]<<"     ";
            }
              std::cout<<"|\n|          |          |          |";
        }
        std::cout<<"\n----------------------------------"<<std::endl;
;
    }
    void Input() {
        std::cout<<player<<" input: ";
        std::cin>>userInput;

        if(userInput < 1 || userInput > 9) {
            std::cout<<"Wrong Input"<<std::endl;
            return;
        }
        for(int i = 0; i < 9; i++) {
            if(data[i] == userInput) {
                std::cout<<"Taken"<<std::endl;
                return;
            }
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j <3; j++) {
                if(board[i][j] == userInput)
                    drawBoard[i][j] = player;
            }
        }
        player = (player == _STARTING_PLAYER_) ? _PLAYER2_ : _STARTING_PLAYER_;
        data[turn++] = userInput;
    }
    int Check() {
        for(int i = 0; i < 3; i++) {
            if(((drawBoard[i][0] == drawBoard[i][1]) && (drawBoard[i][0] == drawBoard[i][2])) ||
                ((drawBoard[0][i] == drawBoard[1][i]) && (drawBoard[0][i] == drawBoard[2][i])))
                    return 2;
        }
        if(((drawBoard[0][0] == drawBoard[1][1]) && (drawBoard[0][0] == drawBoard[2][2])) || 
            ((drawBoard[2][0] == drawBoard[1][1]) && (drawBoard[2][0] == drawBoard[0][2])))
                return 2;
        if(turn == 9)
            return 1;
        
        return 0;
    }
    inline void Ending() {
        Draw();
        if(Check() == 2) {
            player = (player == _STARTING_PLAYER_) ? _PLAYER2_ : _STARTING_PLAYER_;
            std::cout<<"Winner: "<<player<<std::endl;
            return;
        } //Winner
        else if(Check() == 1) {
            std::cout<<"Draw!"<<std::endl;
            return;
        } //Draw;
    }
    ~Game() {}
};

int main() {
    Game game;
    while(game.Running()) {
        if(game.Check() > 0) {
            game.Ending();
            break;
        }
        game.Draw();
        game.Input();
    }
    return 0;
}