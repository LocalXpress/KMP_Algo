#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

char matrix[3][3]; //The matrix for the initialization of the grid.
char check()
{
int i;
for(i=0;i<3;i++)//Check the rows
{
if((matrix[i][0]==matrix[i][1])&&(matrix[i][0]==matrix[i][2]))
return matrix[i][0];
}
for(i=0;i<3;i++)//Check the columns
{
if((matrix[0][i]==matrix[1][i])&&(matrix[0][i]==matrix[2][i]))
return matrix[0][i];
}
//checking the left to right diagonal
if((matrix[0][0]==matrix[1][1])&&(matrix[1][1]==matrix[2][2]))
return matrix[0][0];
//checking the right to left diagonal
if((matrix[0][2]==matrix[1][1])&&(matrix[2][0]==matrix[1][1]))

return matrix[0][2];
//checking if every cell is full
if(matrix[0][0]!=' '&& matrix[0][1]!=' '&& matrix[0][2]!=' '&& matrix[1][0]!=' '&&matrix[1][1]!=' '&& matrix[1][2]!=' '&& matrix[2][0]!=' '&& matrix[2][1]!=' '&& matrix[2][2])
	return 'd';
return ' ';
}

void init_matrix()//Intializes the matrix with empty values
{
int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
matrix[i][j]=' ';
}
}
void get_player_move()//to get the move from the player
{
int x,y;

cout<<"ENTER THE COORDINATES OF THE MOVE: ";
cout<<endl;
cout<<"ENTER THE ROW: ";
cin>>x;
cout<<"ENTER THE COLOUMN: ";
cin>>y;

x--; y--;
cout<<endl<<"INDEX NUMBERS ARE: "<<x<<" "<<y;

cout<<endl<<"Press enter to continue! ";


if(matrix[x][y]!=' ')
{cout<<"INVALID MOVE, TRY AGAIN!!"; get_player_move();}
else
matrix[x][y]='X';
}

void get_comp_move()//to get the move from the computer
{
int i, j;
for(i=0; i<3; i++){
for(j=0; j<3; j++)
if(matrix[i][j]==' ') break;
if(matrix[i][j]==' ') break;
}
if(i*j==9) {
cout<<"draw\n";
exit(0);
}
else
matrix[i][j] = 'O';
}

void get_player_move_1()//to get the move from the second player
{
int x,y;

cout<<"ENTER THE COORDINATES OF THE MOVE: ";
cout<<endl;
cout<<"ENTER THE ROW: ";
cin>>x;
cout<<"ENTER THE COLOUMN: ";

cin>>y;

x--; y--;
cout<<endl<<"Press enter to continue! ";


if(matrix[x][y]!=' ')
{cout<<"INVALID MOVE, TRY AGAIN!!"; get_player_move();}
else
matrix[x][y]='O';
}

void dis_matrix()// to display the tic-tac-toe board
{
cout << "\n\n\tTic Tac Toe\n\n";
cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
cout << endl;
cout << " | | " << endl;
cout << " " << matrix[0][0] << " | " << matrix[0][1] << " | " <<matrix[0][2] << endl;
cout << "_____|_____|_____" << endl;
cout << " | | " << endl;
cout << " " << matrix[1][0] << " | " << matrix[1][1]<< " | " <<matrix[1][2] << endl;
cout << "_____|_____|_____" << endl;
cout << " | | " << endl;

cout << " " << matrix[2][0] << " | " << matrix[2][1] << " | " <<
matrix[2][2] << endl;
cout << " | | " << endl << endl;
}
int main()
{
char done=' ';
char player_1[10],player_2[10];//to store the names of the players
int choice=0;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<" WELCOME TO TIC-TAC-TOE GAME";
cout<<endl;
cout<<endl;
cout<<endl<<" RULES OF THE GAME: "<<endl;
cout<<"X always goes first."<<endl;
cout<<"Players alternate placing Xs and Os on the board until either";
cout<<endl<<"(a) one player has three in a row, horizontally, vertically or diagonally";
cout<<endl<<"(b) all nine squares are filled."<<endl;
cout<<"If a player is able to draw three Xs or three Os in a row, that player wins."<<endl;
cout<<"If all nine squares are filled and neither player has three in a row, the game is a draw."<<endl;
cout<<endl<<"Press enter to continue!!";

a:

cout<<endl<<endl<<endl<<"********************************************************************************";
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<" Press 1 to play single player";
cout<<endl<<" Press 2 to play multi player";
cout<<endl<<" Enter your choice: ";cin>>choice;

if(choice==2)

{

cout<<endl<<endl<<endl<<" Enter Player 1 name: "; gets(player_1);
cout<<" Enter Player 2 name: "; gets(player_2);
cout<<endl<<endl<<endl<<endl<<endl<<" "<<player_1<<" & "<<player_2<<" LET THE GAME BEGIN"; cout<<endl;
cout<<" (Press enter to continue!!)";



init_matrix();
do
{

cout<<player_1<<" Enter your move!"<<endl;
dis_matrix();
get_player_move();
done=check();
if(done!=' ')
break;

cout<<player_2<<" Enter your move!"<<endl;
dis_matrix();
get_player_move_1();
done=check();
if(done!=' ')
break;
cout<<endl;
}while(done==' ');
if(done=='X')
cout<<player_1<<" WON!!";
else if(done=='O')

cout<<player_2<<" WON!!";
else
cout<<"MATCH DRAWN!!";
cout<<endl;
dis_matrix();

goto a;
}
else
{

cout<<endl<<endl<<endl<<" Enter Player 1 name: "; gets(player_1);
strcpy(player_2,"COMPUTER");
cout<<endl<<endl<<endl<<endl<<endl<<" "<<player_1<<" & "<<player_2<<" LET THE GAME BEGIN"; cout<<endl;
cout<<" (Press enter to continue!!)";



init_matrix();
do
{

cout<<player_1<<" Enter your move!"<<endl;
dis_matrix();
get_player_move();
done=check();
if(done!=' ')
break;
get_comp_move();
done=check();
if(done!=' ')
break;

cout<<endl;
}while(done==' ');
if(done=='X')
cout<<player_1<<" WON!!";
else if(done=='O')
cout<<player_2<<" WON!!";
else
cout<<"MATCH DRAWN!!";
cout<<endl;
dis_matrix();

goto a;
}

}