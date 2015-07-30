#include<stdio.h>
#include<time.h>
#include"conio.h"
#include<stdlib.h>
void test(char a[3][3])
{
	if( (a[0][0]==a[0][1])&&(a[0][0]==a[0][2])&&(a[0][0]!='.') )
	{
			printf("%c wins\n",a[0][0]);
			getch();
			exit(0);
	}
	if( ((a[1][0]==a[1][1])&&(a[1][0]==a[1][2]))&&(a[1][0]!='.') )
	{
			printf("%c wins\n",a[1][0]);
			getch();
			exit(0);
	}
	if( ((a[2][0]==a[2][1])&&(a[2][0]==a[2][2]))&&(a[2][0]!='.') )
	{
			printf("%c wins\n",a[2][0]);
			getch();
			exit(0);
	}
	if( ((a[0][0]==a[1][0])&&(a[0][0]==a[2][0]))&&(a[0][0]!='.') )
	{
			printf("%c wins\n",a[0][0]);
			getch();
			exit(0);
	}
	if( ((a[0][1]==a[1][1])&&(a[0][1]==a[2][1]))&&(a[0][1]!='.') )
	{
			printf("%c wins\n",a[0][1]);
			getch();
			exit(0);
	}
	if( ((a[0][2]==a[1][2])&&(a[0][2]==a[2][2]))&&(a[0][2]!='.') )
	{
			printf("%c wins\n",a[0][2]);
			getch();
			exit(0);
	}
	if( ((a[0][0]==a[1][1])&&(a[0][0]==a[2][2]))&&(a[0][0]!='.') )
	{
			printf("%c wins\n",a[0][0]);
			getch();
			exit(0);
	}
	if( ((a[0][2]==a[1][1])&&(a[0][2]==a[2][0]))&&(a[0][2]!='.') )
	{
			printf("%c wins\n",a[0][2]);
			getch();
			exit(0);
	}
}









void output(char a[3][3]) //used to display the matrix each time
{
	int i,j;
	//clrscr();
	system("clear");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%c\t",a[i][j]);
		printf("\n");
	}
	printf("\n");
	test(a);    //tests if there are 3 consicutive x or y

}
void user_choice(char a[3][3])
{
	int i,j;
	printf("enter position of y");
	scanf("%d",&i);
	switch(i)
	{
		case 1: i=0;j=0;break;
		case 2: i=0;j=1;break;
		case 3: i=0;j=2;break;
		case 4: i=1;j=0;break;
		case 5: i=1;j=1;break;
		case 6: i=1;j=2;break;
		case 7: i=2;j=0;break;
		case 8: i=2;j=1;break;
		case 9: i=2;j=2;break;
	}
	if(a[i][j]=='.')
	{
		a[i][j]='y';
		output(a);
	}
	else
	{
		printf("enter proper output\n");
		user_choice(a);
	}
}
void comp_choice(char a[3][3])
{
	int i,j;
	
	if( (a[0][0]==a[0][1])&&(a[0][0]!='.')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[0][1]==a[0][2])&&(a[0][1]!='.')&&(a[0][0]=='.') ){i=0;j=0;}
	else if( (a[1][0]==a[1][1])&&(a[1][0]!='.')&&(a[1][2]=='.') ){i=1;j=2;}
	else if( (a[1][1]==a[1][2])&&(a[1][1]!='.')&&(a[1][0]=='.') ){i=1;j=0;}
	else if( (a[2][0]==a[2][1])&&(a[2][0]!='.')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[2][1]==a[2][2])&&(a[2][1]!='.')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[0][0]==a[1][0])&&(a[0][0]!='.')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[0][1]==a[1][1])&&(a[0][1]!='.')&&(a[2][1]=='.') ){i=2;j=1;}
	else if( (a[0][2]==a[1][2])&&(a[0][2]!='.')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[1][0]==a[2][0])&&(a[1][0]!='.')&&(a[0][0]=='.') ){i=0;j=0;}
	else if( (a[1][1]==a[2][1])&&(a[1][1]!='.')&&(a[0][1]=='.') ){i=0;j=1;}
	else if( (a[1][2]==a[2][2])&&(a[1][2]!='.')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[0][0]==a[1][1])&&(a[0][0]!='.')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[0][2]==a[1][1])&&(a[0][2]!='.')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[2][0]==a[1][1])&&(a[2][0]!='.')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[2][2]==a[1][1])&&(a[2][2]!='.')&&(a[0][0]=='.') ){i=0;j=0;}

	else if( (a[0][0]==a[0][2])&&(a[0][0]!='.')&&(a[0][1]=='.') ){i=0;j=1;}
	else if( (a[1][0]==a[1][2])&&(a[1][0]!='.')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[2][0]==a[2][2])&&(a[2][0]!='.')&&(a[2][1]=='.') ){i=2;j=1;}
	else if( (a[0][0]==a[2][0])&&(a[0][0]!='.')&&(a[1][0]=='.') ){i=1;j=0;}
	else if( (a[0][1]==a[2][1])&&(a[0][1]!='.')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[0][2]==a[2][2])&&(a[0][2]!='.')&&(a[1][2]=='.') ){i=1;j=2;}
	else if( (a[0][0]==a[2][2])&&(a[0][0]!='.')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[0][2]==a[2][0])&&(a[0][2]!='.')&&(a[1][1]=='.') ){i=1;j=1;}
	else
	{
		  srand(time(NULL));
		i=(rand()%9+1);

		switch(i)
		{
			case 1: i=0;j=0;break;
			case 2: i=0;j=1;break;
			case 3: i=0;j=2;break;
			case 4: i=1;j=0;break;
			case 5: i=1;j=1;break;
			case 6: i=1;j=2;break;
			case 7: i=2;j=0;break;
			case 8: i=2;j=1;break;
			case 9: i=2;j=2;break;
		}
	}
	if(a[i][j]=='.')
	{
		a[i][j]='x';
		output(a);
	}
	else
	{
		comp_choice(a);
	}
}
int main()
{
	char a[3][3];
	int i,j;
	//clrscr();
	system("clear");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j]='.';
	output(a);

	for(i=0;i<4;i++)
	{
		comp_choice(a);
		user_choice(a);
	}
	comp_choice(a);
	//getch();
}
