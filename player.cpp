#include<bits/stdc++.h>
using namespace std ;

#define ENTER_KEY int("\n")

class Player{
	int playerNumber ; 
	int position ; 
	
	public:
		Player(){
			this->position =0 ; 
		}

		Player(int number){
			this->position = 0 ; 
			this->playerNumber = number ; 
		}

		int getPlayerNumber(){
			return this->playerNumber ;
		}

		int getPlayerPosition(){
			return this->position ;
		}

		void setPlayerPosition(int position){
			this->position = position ;
		}

		void setPlayerNumber(int number){
			this->playerNumber = number ;
		}


		bool isWinner(int maxValue){
			if(this->position==maxValue){
				return true ;
			}

			return false ;
		}

		int getRandomNumber(){
			const int MIN_VALUE = 1 ; 
			const int MAX_VALUE = 6;

			unsigned seed = time(0) ;
			srand(seed) ; 

			int number =  (rand() %(MAX_VALUE - MIN_VALUE +1 )) + MIN_VALUE ; 
			return number ;
		}

		int  throwDice(){
			cout<< "[ Player"<<this->getPlayerNumber()<<" ] press enter to throw"<<endl;

			const int t = int('\n') ;
			const int T = int('T') ; 
			int userInput = cin.get();

			
			switch(userInput){
				case t:
					cout<<"throwing a Dice...."<<endl<<endl;
					break;

				// case T:
				// 	cout<<"throwing a Dice...."<<endl<<endl;
				// 	break;

				default:
					cout<<"wrong key pressed"<<endl<<endl;
					return throwDice();

			}
			

			
			int diceNo = getRandomNumber();

			cout<<diceNo<<endl<<endl;
			switch(diceNo){
				case 1:
					{
						cout<<"|     |"<<endl;
						cout<<"|  *  |"<<endl;
						cout<<"|     |"<<endl;
						break ;
					}
				case 2:
				{		cout<<"|   * |"<<endl;
						cout<<"|     |"<<endl;
						cout<<"| *   |"<<endl;
						break ;

				}
				case 3:
				{
						cout<<"|   * |"<<endl;
						cout<<"|  *  |"<<endl;
						cout<<"| *   |"<<endl;
						break;
				} 
				case 4:
				{
						cout<<"| * * |"<<endl;
						cout<<"|     |"<<endl;
						cout<<"| * * |"<<endl;
						break;
				} case 5:
				{
						cout<<"| * * |"<<endl;
						cout<<"|  *  |"<<endl;
						cout<<"| * * |"<<endl;
						break;
				} case 6:
				{
						cout<<"| * * |"<<endl;
						cout<<"| * * |"<<endl;
						cout<<"| * * |"<<endl;
						break;
				} 

				default:
					cout<<"TRY AGAIN DICE MUST BE IN RANGE [1-6]"<<endl<<endl;

			}


			return diceNo ;
		}
	
} ;





















