//Shang-Chun, Lin CS202 assignment#2
#include "game.h"

//This file has the classes for managing a game board of the list of games and players, implemented using a CLL and a LLL.

//A game node "has a" game class (ABC), and a list node "has a" player class.

class g_node
{
	public:
		g_node();
		g_node(const g_node & source);
		~g_node();

		g_node *& go_next();
		g_node * get_next()const;
		void connect_next(g_node * connection);
		void remove();
		game *& get_data();
		game * use_data()const;

	protected:
		game * data;
		g_node * next;
};

class games_played
{
	public:
		games_played();
		games_played(const games_played & source);
		~games_played();

		int insert();	// the only place I have used break because I extremely want to use switch command that I saw in lab!! It's so cool!
		int remove();
		int play();
		int display();
		void remove_all();

	protected:
		g_node * rear;

		int remove(g_node * & rear);
		void copy(g_node * & rear,const g_node * source_first,const g_node * source_rear);
		void remove_all(g_node * & rear);
		int count_score(const g_node * rear,int sum);
		int count_score(int sum);
		int play(const g_node * rear);
		int display(const g_node * rear);
};

class player : public games_played
{
	public:
		player();
		player(const player & source);
		~player();

		void set_name();
		int play();
		int display();
		int add_score();	//called after the play function
		void remove_all();
		int compare(const char * to_compare);	//compare the name
		int compare(const player & to_compare);	//compare the score

	protected:
		char * name;
		int * score;
};

class l_node
{
	public:
		l_node();
		l_node(const l_node & source);
		~l_node();

		l_node *& go_next();
		l_node * get_next()const;
		void connect_next(l_node * connection);
		void remove();
		int compare();		//compare the score with the next score
		player *& get_data();
		player * use_data()const;

	protected:
		player * data;
		l_node * next;
};

class games_system
{
	public:
		games_system();
		games_system(const games_system & source);
		~games_system();
		
		int start();	
		int insert();
		int remove();
		int display();
		void remove_all();
		int change_rank();

	protected:
		l_node * head;

		void copy(l_node * & head,const l_node * source_head);
		int insert(l_node * head,const char * to_add);		//for inserting a game
		int insert(l_node * & head);				//for inserting a player
		void remove_all(l_node * & head);
		int remove(l_node * & head,const char * to_remove,char answer);
		int display(const l_node * head);
		int swap(l_node * & head);			//serving for change_rank(head)
		int change_rank(l_node * & head,int success);	//serving for change_rank()
		int start(l_node * & head);
};
















