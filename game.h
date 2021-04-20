//Shang-Chun, Lin CS202 assignment#2
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <time.h>

//This class interface includes an abtract base class Game and three derived classes for different games.

class game
{
	public:
		game();
		virtual ~game();

		virtual int play() = 0;
		virtual void set_tag_name() = 0;
		virtual int quit() = 0;
		virtual void display_name() = 0;
		virtual void remove_all() = 0;
		virtual int return_score() = 0;
};

class matching : public game
{
	public:
		matching();
		matching(const matching & source);
		~matching();

		int play();
		int random_generator();
		int your_turn();
		void set_tag_name();
		int quit();
		void display_name();
		void remove_all();
		int return_score();

	protected:
		char * tag_name;
		int * num;
		int * score;
};


class find_ball : public game
{
	public:
		find_ball();
		find_ball(const find_ball & source);
		~find_ball();

		int play();
		int put_ball();
		int your_turn();
		void set_tag_name();
		int quit();
		void display_name();
		void remove_all();
		int return_score();

	protected:
		char * tag_name;
		int * cup;
		int * score;
};

class black_jack : public game
{
	public:
		black_jack();
		black_jack(const black_jack & source);
		~black_jack();

		int play();
		int bank_turn(int * source);
		int your_turn(int * source);
		void set_tag_name();
		int quit();
		void display_name();
		void remove_all();
		int return_score();

	protected:
		char * tag_name;
		int * bank;
		int * score;

		int set_new(int * source,int count);
		int draw(int * source);
		int draw_until(int * source,int card);
		void your_turn(int * source,int & sum,int & count,char & answer);

};
