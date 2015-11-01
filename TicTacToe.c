#include<stdio.h>
#include<time.h>
#include"conio.h"
#include<stdlib.h>

int count=0;
bool result(char res);
bool test_game(char board[3][3]){
  if( (board[0][0]==board[0][1])&&(board[0][0]==board[0][2])&&(board[0][0]!='.') )       
    return result(board[0][0]);
  if( ((board[1][0]==board[1][1])&&(board[1][0]==board[1][2]))&&(board[1][0]!='.') )   
    return result(board[1][0]);
  if( ((board[2][0]==board[2][1])&&(board[2][0]==board[2][2]))&&(board[2][0]!='.') )
    return result(board[2][0]);
  if( ((board[0][0]==board[1][0])&&(board[0][0]==board[2][0]))&&(board[0][0]!='.') )       
    return result(board[0][0]);
  if( ((board[0][1]==board[1][1])&&(board[0][1]==board[2][1]))&&(board[0][1]!='.') )
    return result(board[0][1]);
  if( ((board[0][2]==board[1][2])&&(board[0][2]==board[2][2]))&&(board[0][2]!='.') )
    return result(board[0][2]);
  if( ((board[0][0]==board[1][1])&&(board[0][0]==board[2][2]))&&(board[0][0]!='.') )
    return result(board[0][0]);
  if( ((board[0][2]==board[1][1])&&(board[0][2]==board[2][0]))&&(board[0][2]!='.') )
    return result(board[0][2]);
  return false;
}

bool result(char res){
  printf("%s",(res=='X')?"computer wins\n":"you win\n");
  return true;
}

void set_board( char (&board)[3][3], int val ) {
  int i=9;
  while( i-- ) *(*(board)+i)=val;
}

void render_game( char board[3][3] ) {//Displays the matrix each time
  int i=3,j=3;
  //  system("clear");
  for(i=0;i<3;i++) {
    for(j=0;j<3;j++)
      printf("%c\t",board[i][j]);
    printf("\n");
  }
  printf("\n");
}

void user_choice(char (&board)[3][3], char symbol ) {
  int row, column, move;
  while(1){
    printf("enter position of y::  ");
    scanf("%d",&move);
    row=(move-1)/3; //converts position(0-9) to array index(00-22)
    column=(move-1)%3; //---
    if( board[row][column]=='.' ) {//checks if position is not used previously
      *(*(board+row)+column)=symbol;
      break;
    }
    printf("enter proper input\n");
  }
}

void comp_choice(char (&board)[3][3], char symbol ) {
  int i,j;
  long t;
  char user_symbol=(symbol == 'X')? 'O':'X'; 
  if( (board[0][0]==board[0][1])&&(board[0][0]!='.')&&(board[0][2]=='.') ){i=0;j=2;}
  else if( (board[0][1]==board[0][2])&&(board[0][1]==symbol)&&(board[0][0]=='.') ){i=0;j=0;}
  else if( (board[1][0]==board[1][1])&&(board[1][0]==symbol)&&(board[1][2]=='.') ){i=1;j=2;}
  else if( (board[1][1]==board[1][2])&&(board[1][1]==symbol)&&(board[1][0]=='.') ){i=1;j=0;}
  else if( (board[2][0]==board[2][1])&&(board[2][0]==symbol)&&(board[2][2]=='.') ){i=2;j=2;}
  else if( (board[2][1]==board[2][2])&&(board[2][1]==symbol)&&(board[2][0]=='.') ){i=2;j=0;}
  else if( (board[0][0]==board[1][0])&&(board[0][0]==symbol)&&(board[2][0]=='.') ){i=2;j=0;}
  else if( (board[0][1]==board[1][1])&&(board[0][1]==symbol)&&(board[2][1]=='.') ){i=2;j=1;}
  else if( (board[0][2]==board[1][2])&&(board[0][2]==symbol)&&(board[2][2]=='.') ){i=2;j=2;}
  else if( (board[1][0]==board[2][0])&&(board[1][0]==symbol)&&(board[0][0]=='.') ){i=0;j=0;}
  else if( (board[1][1]==board[2][1])&&(board[1][1]==symbol)&&(board[0][1]=='.') ){i=0;j=1;}
  else if( (board[1][2]==board[2][2])&&(board[1][2]==symbol)&&(board[0][2]=='.') ){i=0;j=2;}
  else if( (board[0][0]==board[1][1])&&(board[0][0]==symbol)&&(board[2][2]=='.') ){i=2;j=2;}
  else if( (board[0][2]==board[1][1])&&(board[0][2]==symbol)&&(board[2][0]=='.') ){i=2;j=0;}
  else if( (board[2][0]==board[1][1])&&(board[2][0]==symbol)&&(board[0][2]=='.') ){i=0;j=2;}
  else if( (board[2][2]==board[1][1])&&(board[2][2]==symbol)&&(board[0][0]=='.') ){i=0;j=0;}

  else if( (board[0][0]==board[0][2])&&(board[0][0]==symbol)&&(board[0][1]=='.') ){i=0;j=1;}
  else if( (board[1][0]==board[1][2])&&(board[1][0]==symbol)&&(board[1][1]=='.') ){i=1;j=1;}
  else if( (board[2][0]==board[2][2])&&(board[2][0]==symbol)&&(board[2][1]=='.') ){i=2;j=1;}
  else if( (board[0][0]==board[2][0])&&(board[0][0]==symbol)&&(board[1][0]=='.') ){i=1;j=0;}
  else if( (board[0][1]==board[2][1])&&(board[0][1]==symbol)&&(board[1][1]=='.') ){i=1;j=1;}
  else if( (board[0][2]==board[2][2])&&(board[0][2]==symbol)&&(board[1][2]=='.') ){i=1;j=2;}
  else if( (board[0][0]==board[2][2])&&(board[0][0]==symbol)&&(board[1][1]=='.') ){i=1;j=1;}
  else if( (board[0][2]==board[2][0])&&(board[0][2]==symbol)&&(board[1][1]=='.') ){i=1;j=1;}
	

  else if( (board[0][0]==board[0][1])&&(board[0][0]==user_symbol)&&(board[0][2]=='.') ){i=0;j=2;}
  else if( (board[0][1]==board[0][2])&&(board[0][1]==user_symbol)&&(board[0][0]=='.') ){i=0;j=0;}
  else if( (board[1][0]==board[1][1])&&(board[1][0]==user_symbol)&&(board[1][2]=='.') ){i=1;j=2;}
  else if( (board[1][1]==board[1][2])&&(board[1][1]==user_symbol)&&(board[1][0]=='.') ){i=1;j=0;}
  else if( (board[2][0]==board[2][1])&&(board[2][0]==user_symbol)&&(board[2][2]=='.') ){i=2;j=2;}
  else if( (board[2][1]==board[2][2])&&(board[2][1]==user_symbol)&&(board[2][0]=='.') ){i=2;j=0;}
  else if( (board[0][0]==board[1][0])&&(board[0][0]==user_symbol)&&(board[2][0]=='.') ){i=2;j=0;}
  else if( (board[0][1]==board[1][1])&&(board[0][1]==user_symbol)&&(board[2][1]=='.') ){i=2;j=1;}
  else if( (board[0][2]==board[1][2])&&(board[0][2]==user_symbol)&&(board[2][2]=='.') ){i=2;j=2;}
  else if( (board[1][0]==board[2][0])&&(board[1][0]==user_symbol)&&(board[0][0]=='.') ){i=0;j=0;}
  else if( (board[1][1]==board[2][1])&&(board[1][1]==user_symbol)&&(board[0][1]=='.') ){i=0;j=1;}
  else if( (board[1][2]==board[2][2])&&(board[1][2]==user_symbol)&&(board[0][2]=='.') ){i=0;j=2;}
  else if( (board[0][0]==board[1][1])&&(board[0][0]==user_symbol)&&(board[2][2]=='.') ){i=2;j=2;}
  else if( (board[0][2]==board[1][1])&&(board[0][2]==user_symbol)&&(board[2][0]=='.') ){i=2;j=0;}
  else if( (board[2][0]==board[1][1])&&(board[2][0]==user_symbol)&&(board[0][2]=='.') ){i=0;j=2;}
  else if( (board[2][2]==board[1][1])&&(board[2][2]==user_symbol)&&(board[0][0]=='.') ){i=0;j=0;}

  else if( (board[0][0]==board[0][2])&&(board[0][0]==user_symbol)&&(board[0][1]=='.') ){i=0;j=1;}
  else if( (board[1][0]==board[1][2])&&(board[1][0]==user_symbol)&&(board[1][1]=='.') ){i=1;j=1;}
  else if( (board[2][0]==board[2][2])&&(board[2][0]==user_symbol)&&(board[2][1]=='.') ){i=2;j=1;}
  else if( (board[0][0]==board[2][0])&&(board[0][0]==user_symbol)&&(board[1][0]=='.') ){i=1;j=0;}
  else if( (board[0][1]==board[2][1])&&(board[0][1]==user_symbol)&&(board[1][1]=='.') ){i=1;j=1;}
  else if( (board[0][2]==board[2][2])&&(board[0][2]==user_symbol)&&(board[1][2]=='.') ){i=1;j=2;}
  else if( (board[0][0]==board[2][2])&&(board[0][0]==user_symbol)&&(board[1][1]=='.') ){i=1;j=1;}
  else if( (board[0][2]==board[2][0])&&(board[0][2]==user_symbol)&&(board[1][1]=='.') ){i=1;j=1;}
	
  else  {   
    while(1) {
      srand(time(NULL));
      t=(rand()%9+1);
      j=(t-1)%3;
      i=(t-1)/3;
      if(board[i][j]=='.')
	break;
    }
  }
  board[i][j]=symbol;
  count++;
}

int main() {
  char board[3][3];
  int fstPlr;
  void (*player_1)( char (&board)[3][3], char ) = &comp_choice;
  void (*player_2)( char (&board)[3][3], char ) = &comp_choice;

  set_board( board, '.' );
  render_game( board );

  printf("\nEnter 0 to play 1st,1 to play 2nd: ");
  scanf("%d",&fstPlr);
  if( fstPlr==1 )  player_2= user_choice;
  else             player_1= user_choice;

  while( 1 ) {
    player_1( board, 'X' );
    render_game( board );
    if( test_game( board ) ) break;
    player_2( board, 'O' );
    render_game( board );
    if( test_game( board ) ) break;
  }
  
  printf("thanks for playing the game\n\n");
  return 0;
}
