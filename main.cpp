//Shang-Chun, Lin CS202 assignment#2
#include "list.h"
using namespace std;

//This file is to test out the hierarchy of the classes created
int main()
{
	games_system list;

	int * choose = NULL;
	// ---------------------------------------------------------//
	cout<<"Hi, this is a gaming program to record the score and the order of ranking for each player."<<endl;	

	cout<<"Now, please choose a kind of services you would like to use. You have to enter a number."<<endl
	<<"1 for inserting a player into the list or a game into the game list for a specific player, "<<endl
	<<"2 for removing a player from the list or a game from the game list for a specific player, "<<endl
	<<"3 for starting playing the game that in the game list of each player, "<<endl
	<<"4 for displaying the whole record of a player in the order of the ranking, "<<endl
	<<"5 for cleaning up every data in the player list and the game list for each player, "<<endl
	<<"6 for quiting the program."<<endl;

	choose = new int;
	cin>>*choose;
	cin.ignore(100,'\n');
		
	while(*choose < 1 || *choose > 6)
	{
		cout<<"out of range! try again."<<endl;
		cin>>*choose;
		cin.ignore(100,'\n');
	}
	
	//-----------------starting running the main part---------------------//
	while(*choose != 6)
	{	

		if(*choose == 1)
		{
			if(list.insert())
			{
				cout<<"The instruction of inserting is done."<<endl;
			}
		}
		else if(*choose == 2)
		{
			if(list.remove())
			{
				cout<<"The instruction of removing is done."<<endl;
			}
		}
		else if(*choose == 3)
		{
			if(list.start())
			{
				if(list.change_rank())
				{
					cout<<"The instruction of starting the game is done."<<endl;
				}
			}
		}
		else if(*choose == 4)
		{
			if(list.display())
			{
				cout<<"The instruction of displaying is done."<<endl;
			}
		}
		else if(*choose == 5)
		{
			list.remove_all();
		}

		// ---------------------------------------------------------//
		cout<<"Now, please choose a kind of services you would like to use at the next step. "<<endl
		<<"1 for inserting a player into the list or a game into the game list for a specific player, "<<endl
		<<"2 for removing a player from the list or a game from the game list for a specific player, "<<endl
		<<"3 for starting playing the game that in the game list of each player, "<<endl
		<<"4 for displaying the whole record of a player in the order of the ranking, "<<endl
		<<"5 for cleaning up every data in the player list and the game list for each player, "<<endl
		<<"6 for quiting the program."<<endl;

		cin>>*choose;
		cin.ignore(100,'\n');

		while(*choose < 1 || *choose > 6)
		{
			cout<<"out of range! try again."<<endl;
			cin>>*choose;
			cin.ignore(100,'\n');
		}

	}

	if(choose)
	{
		delete choose;
	}
	choose = NULL;

	return 0;
}
