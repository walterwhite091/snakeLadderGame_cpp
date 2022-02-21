#include<bits/stdc++.h>
using namespace std ;

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

		
		int  throwDice(){
			int maxValue = 6 ;
			int diceNo = 1 + ( rand()% maxValue ) ;
			return diceNo ;
		}
	
} ;

