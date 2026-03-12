#include <iostream>
#include <ctime>
using namespace std;

void drawboard(char *spaces){
    cout<< '\n';
    cout << spaces[0] << " | " << spaces [1] << " | " << spaces[2] << " \n";
    cout << "---------\n";
    cout << spaces[3] << " | " << spaces [4] << " | " << spaces[5] << " \n";
    cout << "---------\n";
    cout << spaces[6] << " | " << spaces [7] << " | " << spaces[8] << " \n";
    cout<< '\n';


}

void playermove(char *spaces, char player){
    int num;
    do{
        cout<< "enter spot to place marker (1-9): ";
        cin >> num;
        num--;
        if(spaces[num] = ' '){
            spaces[num] = player;
            break;
        }

    } while(!num > 0 || !num < 8);
}

void computermove(char *spaces, char computer){
    int num;
    srand(time(0));

    while(true){
        num = rand() % 9;
        if(spaces[num] == ' '){
        spaces[num] = computer;
        break;
        }
    } 
}

bool checkwinner(char *spaces, char player, char computer){

    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";
    } else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";
    } else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";
    } else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";
    } else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
         spaces[1] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";       
    } else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
         spaces[2] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";       
    } else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
         spaces[0] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";       
    } else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
         spaces[2] == player ? cout << "MAX WIN!!\n" : cout << "YOU LOSE! \n";       
    } else {
            return false;
    }
    return true;
}

bool checktie(char *spaces){

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        } 
    }
    cout << "It's a tie! \n";

    return true;
}

int main(){
    char spaces[9] = {' ', ' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawboard(spaces);
    
    while(running){
        playermove(spaces, player);
        drawboard(spaces);

        if(checkwinner(spaces,player,computer)){
            running = false;
            break;
        } else if(checktie(spaces)){
            running  = false;
            break;
        }

        computermove(spaces, computer);
        drawboard(spaces);

        if(checkwinner(spaces,player,computer)){
            running = false;
            break;
        }else if(checktie(spaces)){
            running  = false;
            break;
        }

    }
    
    return 0;
}