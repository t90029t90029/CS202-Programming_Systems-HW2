//Shang-Chun, Lin CS202 assignment#2
#include "list.h"

using namespace std;
//The purpose of this file is to implement each function in the list.h file

g_node::g_node()
{
	data = NULL;
	next = NULL;
}

g_node::g_node(const g_node & source)
{
	matching * m_ptr = dynamic_cast<matching*>(source.data);
	find_ball * f_ptr = dynamic_cast<find_ball*>(source.data);
	black_jack * b_ptr = dynamic_cast<black_jack*>(source.data);
	if(m_ptr)
	{
		data = new matching(*m_ptr);
	}
	else if(f_ptr)
	{
		data = new find_ball(*f_ptr);
	}
	else if(b_ptr)
	{
		data = new black_jack(*b_ptr);
	}

	next = NULL;
}

void g_node::remove()
{
	if(data)
	{
		data->remove_all();
	}
	data = NULL;

	if(next)
	{
		next = NULL;
	}
}

g_node::~g_node()
{
	remove();
}

g_node *& g_node::go_next()
{
	return next;
}

g_node * g_node::get_next()const
{
	return next;
}

void g_node::connect_next(g_node * connection)
{
	if(!connection)
	{
		return;
	}
	next = connection;
	return;
}

game *& g_node::get_data()
{
	return data;
}

game * g_node::use_data()const
{
	return data;
}

games_played::games_played()
{
	rear = NULL;
}

void games_played::copy(g_node * & rear,const g_node * source_first,const g_node * source_rear)
{
	g_node * last = NULL;
	if(source_first == source_rear)
	{
		rear = new g_node(*source_first);
		last = rear;
		rear->go_next() = this->rear;
		return;
	}

	rear = new g_node(*source_first);
	last = rear;

	copy(rear->go_next(),source_first->get_next(),source_rear);

	if(source_first == source_rear->get_next())
	{
		rear = last;
	}
	return;
}

games_played::games_played(const games_played & source)
{
	if(source.rear)
	{
		g_node * s_first = source.rear->get_next();
		copy(rear,s_first,source.rear);
	}	
}

void games_played::remove_all(g_node * & rear)
{
	g_node * hold = NULL;
	if(!rear)
	{
		return;
	}

	if(rear == this->rear)
	{
		hold = NULL;
	}
	else
	{
		hold = rear->go_next();
	}
	rear->remove();
	delete rear;
	rear = hold;

	return remove_all(rear);
}

void games_played::remove_all()
{
	if(rear)
	{
		remove_all(rear->go_next());
	}
}

games_played::~games_played()
{
	remove_all();
}

int games_played::insert()
{
	cout<<"Which game do you want to play?"<<endl
		<<"(M) matching"<<endl
		<<"(F) finding the ball"<<endl
		<<"(B) black jack"<<endl;

	char answer = '\0';
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);

	switch (answer)
	{
		case 'M':if(!rear)
			 {
				 rear = new g_node;
				 rear->get_data() = new matching;
				 rear->go_next() = rear;
			 }
			 else
			 {
				 g_node * first = rear->go_next();
				 rear->go_next() = new g_node;
				 rear = rear->go_next();
				 rear->get_data() = new matching;
				 rear->go_next() = first;
			 }
			 break;

		case 'F':if(!rear)
			 {
				 rear = new g_node;
				 rear->get_data() = new find_ball;
				 rear->go_next() = rear;
			 }
			 else
			 {
				 g_node * first = rear->go_next();
				 rear->go_next() = new g_node;
				 rear = rear->go_next();
				 rear->get_data() = new find_ball;
				 rear->go_next() = first;
			 }
			 break;

		case 'B':if(!rear)
			 {
				 rear = new g_node;
				 rear->get_data() = new black_jack;
				 rear->go_next() = rear;
			 }
			 else
			 {
				 g_node * first = rear->go_next();
				 rear->go_next() = new g_node;
				 rear = rear->go_next();
				 rear->get_data() = new black_jack;
				 rear->go_next() = first;
			 }
			 break;

		default:cout<<"The default is Black Jack."<<endl;
			if(!rear)
			{
				rear = new g_node;
				rear->get_data() = new black_jack;
				rear->go_next() = rear;
			}
			else
			{
				g_node * first = rear->go_next();
				rear->go_next() = new g_node;
				rear = rear->go_next();
				rear->get_data() = new black_jack;
				rear->go_next() = first;
			}
	}

	return 1;
}

int games_played::remove(g_node * & rear)
{
	char answer = '\0';

	cout<<"This game is : "<<endl;

	if(rear->get_data())
	{
		rear->get_data()->display_name();
	}

	cout<<"Do you want to remove it from the list?"<<endl
		<<"Y for yes, N for no. (If you choose no, then we will examine the next game.)"<<endl;

	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);

	if(rear == this->rear)
	{
		cout<<"This is the last game in the game list."<<endl;

		if(answer == 'Y')
		{
			if(rear->go_next() == rear)
			{
				rear->remove();
				delete rear;
				rear = NULL;
			}
			else
			{
				g_node * hold = rear->go_next();
				rear->remove();
				delete rear;
				rear = hold;
			}
			return 1;
		}
		else
		{
			cout<<"You did not remove any game."<<endl;
			return 0;
		}
	}
	else if(answer == 'Y')
	{
		if(rear->go_next() == rear)
		{
			rear->remove();
			delete rear;
			rear = NULL;
		}
		else
		{
			g_node * hold = rear->go_next();
			rear->remove();
			delete rear;
			rear = hold;
		}
		return 1;
	}

	return remove(rear->go_next());
}

int games_played::remove()
{
	if(!rear)
	{
		cout<<"The game list is empty, you can not remove anything!"<<endl;
		return 0;
	}
	return remove(rear->go_next());	
}

int games_played::display(const g_node * rear)
{
	if(rear == this->rear)
	{
		rear->use_data()->display_name();
		return 1;
	}

	rear->use_data()->display_name();

	return display(rear->get_next());
}

int games_played::display()
{
	if(!rear)
	{
		cout<<"The game list is empty. We can not display anything for you."<<endl;
		return 0;
	}
	return display(rear->get_next());
}

int games_played::count_score(const g_node * rear,int sum)
{
	if(rear == this->rear)
	{
		sum += rear->use_data()->return_score();
		return sum;
	}
	sum += rear->use_data()->return_score();

	return count_score(rear->get_next(),sum);	
}

int games_played::count_score(int sum)
{
	if(!rear)
	{
		return 0;
	}
	return count_score(rear->get_next(),sum);
}

int games_played::play(const g_node * rear)
{
	int count = 0;
	if(rear == this->rear)
	{
		count += rear->use_data()->play();
		return count;
	}

	count += rear->use_data()->play();

	return play(rear->get_next());
}

int games_played::play()
{
	if(!rear)
	{
		return 0;
	}
	return play(rear->get_next());
}

player::player()
{
	name = NULL;
	score = NULL;
}

player::player(const player & source):games_played(source)
{
	if(source.name)
	{
		name = new char[strlen(source.name) +1];
		strcpy(name,source.name);
	}

	if(source.score)
	{
		score = new int;
		*score = *source.score;
	}
}

void player::remove_all()
{
	if(name)
	{
		delete [] name;
	}
	name = NULL;

	if(score)
	{
		delete score;
	}
	score = NULL;

	return;
}

player::~player()
{
	remove_all();
}

void player::set_name()
{
	cout<<"Please set a gamer's name."<<endl;
	char * hold = new char[51];
	cin.get(hold,50,'\n');
	cin.ignore(100,'\n');

	if(name)
	{
		delete [] name;
		name = NULL;
	}

	name = new char[strlen(hold)+1];
	strcpy(name,hold);

	delete [] hold;
	hold = NULL;

	return;
}

int player::display()
{
	if(!name || !score)
	{
		cout<<"The gamer's name or the score has not been set up. We can not display it for you."<<endl;
		return 0;
	}

	cout<<"Gamer's name : "<<name<<endl;
	cout<<"Total score : "<<*score<<endl;
	cout<<"Game list : "<<endl;

	if(games_played::display())
	{
		cout<<"The details of each game is shown above."<<endl;
	}
	return 1;
}

int player::add_score()
{
	if(!score)
	{
		score = new int;
	}

	*score = count_score(0);

	return 1;
}

int player::play()
{
	cout<<"Hi, "<<name<<endl;
	if(games_played::play())
	{
		return 1;
	}
	return 0;
}

int player::compare(const char * to_compare)	//compare the name
{
	if(!to_compare)
	{
		return 0;
	}
	if(strcmp(name,to_compare) == 0)
	{
		return 1;
	}
	return 0;
}

int player::compare(const player & to_compare)	//compare the score
{
	if(!score || !to_compare.score)
	{
		return 0;
	}
	if(*score < *to_compare.score)		//we need to swap the ranking
	{
		return 1;
	}
	return 0;
}

l_node::l_node()
{
	data = NULL;
	next = NULL;
}

l_node::l_node(const l_node & source)
{
	if(source.data)
	{
		data = new player(*source.data);
	}

	next = NULL;
}

void l_node::remove()
{
	if(data)
	{
		data->games_played::remove_all();	//delete the CLL for the player
		data->remove_all();			//delete the player's info
	}
	data = NULL;

	if(next)
	{
		next = NULL;
	}
}

l_node::~l_node()
{
	remove();
}

l_node *& l_node::go_next()
{
	return next;
}

l_node * l_node::get_next()const
{
	return next;
}

void l_node::connect_next(l_node * connection)
{
	if(!connection)
	{
		return;
	}
	next = connection;
	return;
}

int l_node::compare()
{
	if(!data || !next ||!next->data)
	{
		return 0;
	}
	if(data->compare(*next->data))
	{
		return 1;
	}
	return 0;
}

player *& l_node::get_data()
{
	return data;
}

player * l_node::use_data()const
{
	return data;
}

games_system::games_system()
{
	head = NULL;
}

void games_system::copy(l_node * & head,const l_node * source_head)
{
	if(!source_head)
	{
		head = NULL;
		return;
	}

	head = new l_node(*source_head);

	return copy(head->go_next(),source_head->get_next());
}

games_system::games_system(const games_system & source)
{
	if(source.head)
	{
		copy(head,source.head);
	}
}

void games_system::remove_all(l_node * & head)
{
	if(!head)
	{
		return;
	}

	l_node * hold = head->go_next();
	head->remove();
	delete head;
	head = hold;
	if(!head)
	{
		return;
	}

	return remove_all(head->go_next());
}

void games_system::remove_all()
{
	if(!head)
	{
		return;
	}
	return remove_all(head);
}

games_system::~games_system()
{
	remove_all();
}

int games_system::insert(l_node * head,const char * to_add)	//for inserting a game
{
	char * source = new char[strlen(to_add) + 1];
	strcpy(source,to_add);

	if(!head)
	{
		return 0;
	}

	if(head->get_data()->compare(source))
	{
		if(head->get_data()->games_played::insert())
		{
			delete []source;
			source = NULL;
			return 1;
		}
	}
	delete []source;
	source = NULL;

	return insert(head->go_next(),to_add);
}

int games_system::insert(l_node * & head)	//for inserting a player
{
	if(!head)
	{
		head = new l_node;
		head->go_next() = NULL;
		head->get_data() = new player;
		head->get_data()->set_name();

		cout<<"We have inserted a player for you."<<endl;	
		return 1;
	}
	return insert(head->go_next());
}

int games_system::insert()
{
	cout<<"Do you want to insert a player into the player list or a game into the game list for a specific player?"<<endl
		<<"P for player, G for game."<<endl;
	int success = 0;
	char answer = '\0';
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);

	if(answer == 'P')
	{
		return insert(head);
	}
	if(answer == 'G')
	{
		cout<<"Please enter the name of the player that you are looking for."<<endl;
		char * to_add = new char[101];
		cin.get(to_add,100,'\n');
		cin.ignore(100,'\n');

		success = insert(head,to_add);

		delete []to_add;
		to_add = NULL;
		return success;
	}

	cout<<"Your answer is out of range."<<endl;
	return 0;
}

int games_system::remove(l_node * & head,const char * to_remove,char answer)
{
	if(!head)
	{
		return 0;
	}
	char * source = new char[strlen(to_remove) + 1];
	strcpy(source,to_remove);

	if(head->get_data()->compare(source) && answer == 'P')
	{
		l_node * hold = head->go_next();

		head->remove();					//delete the node
		delete head;
		head = hold;

		delete []source;
		source = NULL;
		return 1;
	}
	else if(head->get_data()->compare(source) && answer == 'G')
	{
		if(head->get_data()->games_played::remove())		//delete a game in the CLL
		{
			cout<<"We have removed the game for you."<<endl;

			return 1;
		}
		cout<<"You have gone through the whole game list. You did not do anything."<<endl;
		return 0;
	}

	delete []source;
	source = NULL;

	return remove(head->go_next(),to_remove,answer);
}

int games_system::remove()
{
	if(!head)
	{
		cout<<"The gamer list is empty. We can not remove anything for you."<<endl;
		return 0;
	}
	cout<<"Do you want to remove a player from the player list or a game from the game list of a specific player?"<<endl
		<<"P for player, G for game."<<endl;
	char answer = '\0';
	cin>>answer;
	cin.ignore(100,'\n');
	answer = toupper(answer);

	cout<<"Please enter the name of the player that you are looking for."<<endl;
	char * to_remove = new char[101];
	cin.get(to_remove,100,'\n');
	cin.ignore(100,'\n');

	if(answer == 'P' || answer == 'G')
	{
		if(remove(head,to_remove,answer))
		{
			delete []to_remove;
			to_remove = NULL;
			return 1;
		}

		delete []to_remove;
		to_remove = NULL;
		return 0;
	}

	cout<<"The answer is out of range."<<endl;

	delete []to_remove;
	to_remove = NULL;

	return 0;
}

int games_system::display(const l_node * head)
{
	int count = 0;
	int success = 0;
	if(!head)
	{
		return 0;
	}
	if(head->use_data()->display())
	{
		++count;
	}
	success += display(head->get_next());

	return count;
}

int games_system::display()
{
	if(!head)
	{
		cout<<"The player list is empty now."<<endl;
		return 0;
	}
	return display(head);
}

int games_system::swap(l_node * & head)
{
	int count = 0;
	int success = 0;

	if(!head)
	{
		return 0;
	}
	if(head->compare())
	{
		l_node * hold = head->go_next();
		head->go_next() = hold->go_next();
		hold->go_next() = head;
		head = hold;

		++count;
	}

	success += swap(head->go_next());
	return count;
}

int games_system::change_rank(l_node * & head,int success)
{
	int count = 0;		//check if the swapping happened or not
	count = swap(head);
	if(count != 0)
	{
		++success;
	}
	if(count == 0 && success == 0)
	{
		cout<<"The rank does not change."<<endl;
		return 0;
	}
	else if(count == 0)	//this is the true base case
	{
		cout<<"The updating has been done."<<endl;
		return 1;
	}
	return change_rank(head,success);
}

int games_system::change_rank()
{
	if(!head)
	{
		cout<<"The player list is empty now. We can not change the rank for the list."<<endl;
		return 0;
	}
	int success = 0;	//check does the swapping ever happen
	return change_rank(head,success);
}

int games_system::start(l_node * & head)
{
	int success = 0;
	if(!head)
	{
		return 0;
	}
	success = head->get_data()->play();
	if(head->get_data()->add_score())
	{
		cout<<"We have updated the score for the player."<<endl;
	}

	success += start(head->go_next());

	return success;
}

int games_system::start()
{
	if(!head)
	{
		cout<<"The player list is empty now. There is no player can play the games."<<endl;
		return 0;
	}
	return start(head);
}

