//Shang-Chun, Lin CS202 assignment#2
#include "game.h"

using namespace std;
//The purpose of this file is to implement each function in the game.h file

game::game()
{
}

game::~game()
{
}

matching::matching()
{
	tag_name = NULL;
	num = NULL;
	score = NULL;
}

matching::matching(const matching & source):game(source)
{
	if(source.tag_name)
	{
		tag_name = new char[strlen(source.tag_name)+1];
		strcpy(tag_name,source.tag_name);
	}
	if(source.num)
	{
		num = new int;
		*num = *source.num;
	}
	if(source.score)
	{
		score = new int;
		*score = *source.score;
	}
}

void matching::remove_all()
{
	if(tag_name)
	{
		delete []tag_name;
	}
	tag_name = NULL;

	if(num)
	{
		delete num;
	}
	num = NULL;

	if(score)
	{
		delete score;
	}
	score = NULL;
	return;
}

matching::~matching()
{
	remove_all();
}

int matching::random_generator()
{
	if(!num)
	{
		num = new int;
	}
	*num = rand() % 10 + 1;
	return 1;
}

int matching::your_turn()
{
	cout<<"It's your turn, "<<tag_name<<". Please guess an number."<<endl;
	int guess = 0;
	cin>>guess;
	cin.ignore(100,'\n');

	return guess;
}

void matching::set_tag_name()
{
	cout<<"Please set your matching game tag name."<<endl;
	char * hold = new char[101];
	cin.get(hold,100,'\n');
	cin.ignore(100,'\n');

	if(tag_name)
	{
		delete []tag_name;
		tag_name = NULL;
	}

	tag_name = new char[strlen(hold)+1];
	strcpy(tag_name,hold);

	delete []hold;
	hold = NULL;

	return;
}

int matching::quit()
{
	cout<<"Do you want to quit the matching game? Y for yes, N for no."<<endl;
	char answer = '\0';
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);
	
	if(answer == 'Y')
	{
		return 1;
	}

	return 0;
}

int matching::play()
{
	cout<<"This game is to guess a number from 1 to 10. If your answer matches the answer, then you will get 1 point."<<endl;

	if(quit())
	{
		cout<<"Okay, let's begin playing the next game."<<endl;
		return 0;
	}

	set_tag_name();

	if(random_generator())
	{
		cout<<"The answer has been set."<<endl;
	}

	if(your_turn() == *num)
	{
		cout<<"The answer is : "<<*num<<endl;
		cout<<"You get it! Your point + 1 !!!"<<endl;

		if(!score)
		{
			score = new int;
			*score = 1;
		}
		
		*score = 1;

		return 1;
	}
	
	cout<<"The answer is : "<<*num<<endl;
	cout<<"oops, wrong answer. Let's play the next game."<<endl;
	return 0;
}

int matching::return_score()
{
	if(!score)
	{
		return 0;
	}
	return *score;
}

void matching::display_name()
{
	cout<<"Game : Matching game"<<endl;
	if(!score)
	{
		cout<<"Score : 0"<<endl;
	}
	else
	{
		cout<<"Score : "<<*score<<endl;
	}
}

find_ball::find_ball()
{
	tag_name = NULL;
	cup = NULL;
	score = NULL;
}

find_ball::find_ball(const find_ball & source):game(source)
{
	if(source.tag_name)
	{
		tag_name = new char[strlen(source.tag_name)+1];
		strcpy(tag_name,source.tag_name);
	}
	if(source.cup)
	{
		cup = new int;
		*cup = *source.cup;
	}
	if(source.score)
	{
		score = new int;
		*score = *source.score;
	}
}

void find_ball::remove_all()
{
	if(tag_name)
	{
		delete []tag_name;
	}
	tag_name = NULL;

	if(cup)
	{
		delete cup;
	}
	cup = NULL;

	if(score)
	{
		delete score;
	}
	score = NULL;
	return;
}

find_ball::~find_ball()
{
	remove_all();
}

int find_ball::put_ball()
{
	if(!cup)
	{
		cup = new int;
	}
	*cup = rand() % 3 + 1;
	return 1;
}

int find_ball::your_turn()
{
	cout<<"It's your turn, "<<tag_name<<". Please guess an number of a cup."<<endl;
	int guess = 0;
	cin>>guess;
	cin.ignore(100,'\n');

	return guess;
}

void find_ball::set_tag_name()
{
	cout<<"Please set your find_ball tag name."<<endl;
	char * hold = new char[101];
	cin.get(hold,100,'\n');
	cin.ignore(100,'\n');

	if(tag_name)
	{
		delete []tag_name;
		tag_name = NULL;
	}

	tag_name = new char[strlen(hold)+1];
	strcpy(tag_name,hold);

	delete []hold;
	hold = NULL;

	return;
}

int find_ball::quit()
{
	cout<<"Do you want to quit find a ball game? Y for yes, N for no."<<endl;
	char answer = '\0';
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);

	if(answer == 'Y')
	{
		return 1;
	}

	return 0;
}

int find_ball::play()
{
	cout<<"This game is to guess which cup has a ball inside (from #1 to #3). "<<endl
	<<"If your answer matches the right cup, then you will get 1 point."<<endl;

	if(quit())
	{
		cout<<"Okay, let's begin playing the next game."<<endl;
		return 0;
	}

	set_tag_name();

	if(put_ball())
	{
		cout<<"The ball has been set."<<endl;
	}

	if(your_turn() == *cup)
	{
		cout<<"The answer is : "<<*cup<<endl;
		cout<<"You get it! Your point + 1 !!!"<<endl;

		if(!score)
		{
			score = new int;
			*score = 1;
		}

		*score = 1;

		return 1;
	}
	
	cout<<"The answer is : "<<*cup<<endl;
	cout<<"oops, wrong answer. Let's play the next game."<<endl;
	return 0;
}

int find_ball::return_score()
{
	if(!score)
	{
		return 0;
	}
	return *score;
}

void find_ball::display_name()
{
	cout<<"Game : Find the ball game"<<endl;
	if(!score)
	{
		cout<<"Score : 0"<<endl;
	}
	else
	{
		cout<<"Score : "<<*score<<endl;
	}
}

black_jack::black_jack()
{
	tag_name = NULL;
	bank = NULL;
	score = NULL;
}

black_jack::black_jack(const black_jack & source):game(source)
{
	if(source.tag_name)
	{
		tag_name = new char[strlen(source.tag_name)+1];
		strcpy(tag_name,source.tag_name);
	}
	if(source.bank)
	{
		bank = new int;
		*bank = *source.bank;
	}
	if(source.score)
	{
		score = new int;
		*score = *source.score;
	}
}

void black_jack::remove_all()
{
	if(tag_name)
	{
		delete []tag_name;
	}
	tag_name = NULL;

	if(bank)
	{
		delete bank;
	}
	bank = NULL;

	if(score)
	{
		delete score;
	}
	score = NULL;
	return;
}

black_jack::~black_jack()
{
	remove_all();
}

int black_jack::set_new(int * source,int count)
{
	if(!source)
	{
		return 0;
	}


	*source = 4;
	++count;

	if(count == 13)
	{
		return 1;
	}

	return set_new(source+1,count);
}

int black_jack::draw_until(int * source,int card)
{
	int count = 0;
	if(source[card-1] != 0)
	{
		return card;
	}
	card = rand() % 13 + 1;
	count = draw_until(source,card);
	
	return count;
}

int black_jack::draw(int * source)
{
	if(!source)
	{
		return 0;
	}
	int card = 0;
	card = rand() % 13 + 1;
	if(source[card-1] == 0)
	{
		card = draw_until(source,card);
	}
	--source[card-1];
	if(card == 13 || card == 12 || card == 11)
	{
		return 10;
	}
	else
	{
		return card;
	}
}

int black_jack::bank_turn(int * source)
{
	if(!bank)
	{
		bank = new int;
	}
	
	*bank = draw(source);
	if(*bank < 10)
	{
		*bank += draw(source);
	}
	return 1;
}

void black_jack::your_turn(int * source,int & sum,int & count,char & answer)
{
	if(answer != 'Y' || count >5)
	{
		return;
	}
	
	sum += draw(source);
	++count;

	cout<<"The sum of your cards is "<<sum<<". Do you want to draw one more card?"<<endl
	<<"Y for yes, N for no."<<endl;
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);

	return your_turn(source,sum,count,answer);
}

int black_jack::your_turn(int * source)
{
	cout<<"It's your turn, "<<tag_name<<"."<<endl;
	int card_sum = 0;
	char answer = '\0';
	int count = 1;

	card_sum = draw(source);

	cout<<"The sum of your cards is "<<card_sum<<". Do you want to draw one more card?"<<endl
	<<"Y for yes, N for no."<<endl;
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);

	your_turn(source,card_sum,count,answer);

	return card_sum;
}

void black_jack::set_tag_name()
{
	cout<<"Please set your black_jack tag name."<<endl;
	char * hold = new char[101];
	cin.get(hold,100,'\n');
	cin.ignore(100,'\n');

	if(tag_name)
	{
		delete []tag_name;
		tag_name = NULL;
	}

	tag_name = new char[strlen(hold)+1];
	strcpy(tag_name,hold);

	delete []hold;
	hold = NULL;

	return;
}

int black_jack::quit()
{
	cout<<"Do you want to quit Black Jack this time? Y for yes, N for no."<<endl;
	char answer = '\0';
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);
	
	if(answer == 'Y')
	{
		return 1;
	}

	return 0;
}

int black_jack::play()
{
	int * database = new int[13];
	cout<<"This black jack game is to compare your card with the bank's. "<<endl
	<<"If the sum of your cards is bigger than the bank's, then you will get 1 point."<<endl;

	if(quit())
	{
		cout<<"Okay, let's begin playing the next game."<<endl;
		return 0;
	}
	int your_sum = 0;

	set_tag_name();

	srand(time(NULL));

	if(set_new(database,0))
	{
		if(bank_turn(database))
		{
			cout<<"The bank has set."<<endl;
		}
	}
	
	your_sum = your_turn(database);	

	cout<<"The sum of the bank is : "<<*bank<<endl;

	if(your_sum > *bank && your_sum <= 21)
	{
		cout<<"You get it! Your point + 1 !!!"<<endl;
		if(!score)
		{
			score = new int;
			*score = 1;
		}

		*score = 1;

		delete [] database;
		database = NULL;
		return 1;
	}
	else if(your_sum <= 21 && *bank > 21)
	{
		cout<<"You get it! Your point + 1 !!!"<<endl;
		if(!score)
		{
			score = new int;
			*score = 1;
		}
		
		*score = 1;

		delete [] database;
		database = NULL;
		return 1;
	}
	
	delete [] database;
	database = NULL;

	cout<<"oops, you lose. Let's play the next game."<<endl;
	return 0;
}

int black_jack::return_score()
{
	if(!score)
	{
		return 0;
	}
	return *score;
}

void black_jack::display_name()
{
	cout<<"Game : Black Jack"<<endl;
	if(!score)
	{
		cout<<"Score : 0"<<endl;
	}
	else
	{
		cout<<"Score : "<<*score<<endl;
	}
}

