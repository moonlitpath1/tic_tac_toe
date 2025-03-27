#include<iostream>
#include<map>
using namespace std;

class TicTacToe
{
    char board[3][3] = {};
    map<char, string> player; 
    map<int, pair<int, int>> board_num;
    char curr;
    int boxes_filled;

    //func
    public:
        TicTacToe();
        void print_board();
        void play();
        bool win(int pos);
        void reset();
};

TicTacToe::TicTacToe()
{
    cout<<"\nEnter name of Player 1: ";
    cin>>player['X'];
    cout<<"Enter name of Player 2: ";
    cin>>player['O'];

    boxes_filled = 0;

    //init board_num map
    board_num = {
        {1, {0, 0}},
        {2, {0, 1}},
        {3, {0, 2}},
        {4, {1, 0}},
        {5, {1, 1}},
        {6, {1, 2}},
        {7, {2, 0}},
        {8, {2, 1}},
        {9, {2, 2}}
    };
    curr = 'X';
}

void TicTacToe::print_board()
{
    int count = 1;
    for(int i=0; i<3; i++)
    {

        for(int j=0; j<3; j++)
        {
            cout<<" | ";

            //number or X/O
            if(board[i][j])
                cout<<board[i][j];
            else
                cout<<count;

            count++;
        }
        cout<<" |\n";
        
    }
    cout<<"\n";
}

void TicTacToe::play()
{
    int pos = -1;
    // char curr = 'X';

    while(true)
    {
        cout<<"\nPlayer "<<player[curr]<<endl;
        print_board();
        
        //input
        cout<<"Enter number where you want to put "<<curr<<": ";
        cin>>pos;

        //add X/0 to board
        if(!board[board_num[pos].first][board_num[pos].second])
        {
            board[board_num[pos].first][board_num[pos].second] = curr;
            boxes_filled += 1;
        }
        else
        {
            cout<<"You cannot place "<<curr<<" over here.";
            continue;
        }
        

      //result displaying
        if(boxes_filled >= 9 || win(pos))
        {
            if(boxes_filled >= 9)
                cout<<"It was a draw.\n\n";
            else cout<<"Congratulations!!!!\n"<<"Player "<<player[curr]<<" has won!!!\n\n";

            return;            
        }
        
        //swap current player
        if (curr == 'X') 
        {
            curr = 'O';
        } else 
        {
            curr = 'X';
        }
    }

}

bool TicTacToe::win(int pos)
{
    int row = board_num[pos].first;
    int col = board_num[pos].second;

    //horiozontal   
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
        return true;
    }

    //vertical
    if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
        return true;
    }

    //diag1
    if (row == col && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
  //diag 2
    if (row + col == 2 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;

}

void TicTacToe::reset()
{
    boxes_filled = 0;
    for(int i=0; i<3; i++)
    {
        board[i][0] = board[i][1] = board[i][2] = '\0';
    }

    curr = 'X';

    //swap players
    string temp = player['X'];
    player['X'] = player['O'];
    player['O'] = temp;
}


int main()
{
    TicTacToe t;
    t.play();   
    char flag;
    
    cout<<"Play Again?(Y/N): ";
    cin>>flag;
    if(flag == 'Y' || flag == 'y')
    {    
        t.reset();
        t.play();
    }
    else
    {
        cout<<"Thank you for playing!\n";
    }
}
