#include<bits/stdc++.h>

#include "snake.cpp"
#include "ladder.cpp"
#include "player.cpp"

using namespace std ;



class Game{
	int *cardBoard;
	int noOfBlocks;
	int noOfPlayers ;
	Player *playersList ;
	Snake  *snakes;
	Ladder *ladders; 

	public:
		Game(int noOfPlayers=1 , int noOfBlocks=100){
			
			// declare a cardBoard
			this->noOfBlocks = noOfBlocks  ; 
			cardBoard = new int[noOfBlocks+1] ;

			// player count
			this->noOfPlayers = noOfPlayers ; 
			playersList = new Player[this->noOfPlayers+1] ;  
		
			// set position of all to 0.
			for(int player=1 ; player<= this->noOfPlayers ; player++){
				Player playerObject(player) ;
				// cout<<playerObject.getPlayerNumber()<<" "<<playerObject.getPlayerPosition()<<endl;
				playersList[player] =playerObject ; 
			}

			// ladder mapping
			ladders = new Ladder() ;

			// snake mapping
			snakes = new Snake() ;  

			
		}


		void displayRules(){
			cout<<"<-- Welcome to Snake and Ladder -->"<<endl<<endl<<endl;

			cout<<"***** RULES *****"<<endl<<endl;
			cout<<"1.	This is a commond line interface game "<<endl<<endl;
			cout<<"2.	Press T to throw dice"<<endl;
			cout<<"3.	If sanke is present on a block then you get demoted.. Sad hahhahah"<<endl;
			cout<<"4.	If ladder is present on a block then you will jump on ladder and ride"<<endl;

			cout<<"5	You have to to reach "<<this->noOfBlocks<<" to be a WINNER. Neither less nor more. @_@"<<endl<<endl;
			cout<<"--------------------------------------------"<<endl<<endl<<endl;
		}

		void displayCurrentState(){
			
			for(int player=1 ; player<=this->noOfPlayers ; player++ ){
				cout<<">>> player-" << playersList[player].getPlayerNumber()<<" ---> "<<playersList[player].getPlayerPosition()<<endl;
			}
			cout<<endl<<endl;
		}



		void startCustomGame(){
			cout<<"Not implemented"<<endl ;
		}



		int getBinaryInput(){
			int input ;
			cin >> input ;


			switch (input){
		        case 0 :
		            cout<<"You have selected [0]"<<endl;
		            break;
		        case 1 :
		            cout<<"You have selected [1]"<<endl;
		            break;
		        default:
		        	cout<<"Wrong input , select 1 or 0";
		            input = getBinaryInput() ;
		       }

		    return input ; 
		}



		bool isValidBlock(int blockNumber){
			return blockNumber>=1 && blockNumber<=this->noOfBlocks ;
		}




		bool turn(Player &player){

			int diceResult = player.throwDice() ; 
			int currentPositiion = player.getPlayerPosition();


			int nextPosition = currentPositiion + diceResult ; 

			if(!isValidBlock(nextPosition)){
				cout<<"Oops try again , "<<nextPosition<<" is not present in board"<<endl;
				return false;
			}

			if(snakes->isSnake(nextPosition)){
				cout<<"---Snake baby @_@---"<<endl<<endl;
				nextPosition = snakes->snakeBite(nextPosition) ; 

			}
			else if(ladders->isLadder(nextPosition)){
				cout<<"---Ladder is here @_@---"<<endl<<endl;
				nextPosition = ladders->rideLadder(nextPosition) ; 
			}

			player.setPlayerPosition(nextPosition);
			
			int anyWinner =false ;
			if(player.isWinner(this->noOfBlocks)){
				anyWinner = true ;
				cout<< endl<<endl<<"Player--"<<player.getPlayerNumber()<<" is the WINNER of game"<<endl ; 
			}

			return anyWinner; 

		}




		void startGame(){
			this->displayRules() ; 

			cout<<"Do you want play on Default snake and ladder setting"<<endl<<endl;
			cout<<"Press 0 to yes or press 1 to enter custom setting"<<endl<<endl;

			int customSetting = getBinaryInput() ; 


			if(customSetting){
				startCustomGame() ;
				return ;  
			}


			cout<<"Setting on Default setting ..."<<endl ; 
			cout<<endl;

			// this->diceResult();


			bool searchingForWinner = false ;

			while(!searchingForWinner){

				for(int player =1 ;player <= noOfPlayers ; player++){
					searchingForWinner= this->turn( playersList[player] ) ;
					this->displayCurrentState();

					if(searchingForWinner)
						break;
					// printf("\033[2J"); //clear full
  					// printf("\033[1;1H"); // point to first
				}
			
				cout<<endl;
			}

			cout<<" <---- Thanks ----> "<<endl;
			cout<<" Developer ---Deepak Kumar--- "<<endl;

		}


};
