#include "snake.cpp"
#include "ladder.cpp"

#include<bits/stdc++.h>
using namespace std ;

#define ENTER_KEY int("\n")

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
			for(int player=1 ; player< this->noOfPlayers ; player++){
				Player playerObject(player) ;

				playersList[player] =playerObject ; 
			}

			// ladder mapping
			ladders = new Ladder() ;

			// snake mapping
			snakes = new Snake() ;  

			
		}


		void displayCurrentState(){
			for(int player=1 ; player<this->noOfPlayers ; player++ ){
				cout<<">>> player-" << playersList[player].getPlayerNumber()<<" ---> "<<playersList[player].getPlayerPosition()<<endl;
			}
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




		bool turn(Player player){

			cout<<"Press enter to throw a dice"<<endl ; 

			// if(cin.get() == KB_ENTER){
				
			// 	cout<<"enter is pressed"<<endl;
			// }
			// 	else{
			// 	cout<<"enter not pressed"<<endl;
			// 	}

			int diceResult = player.throwDice() ; 
			int currentPositiion = player.getPlayerPosition();


			int nextPosition = currentPositiion + diceResult ; 

			if(!isValidBlock(nextPosition)){
				cout<<"Oops try again , "<<nextPosition<<" is not present in board"<<endl;
				return false;
			}

			if(snakes->isSnake(nextPosition)){
				nextPosition = snakes->snakeBite(nextPosition) ; 

			}
			else if(ladders->isLadder(nextPosition)){
				nextPosition = ladders->rideLadder(nextPosition) ; 
			}


			player.setPlayerPosition(nextPosition);

			int anyWinner =false ;
			if(player.isWinner(this->noOfBlocks)){
				anyWinner = true ;
				cout<<player.getPlayerPosition()<<" is the WINNER of game"<<endl ; 
			}

			return anyWinner; 

		}




		void startGame(){
			cout<<"<-- Welcome to Snake and Ladder -->"<<endl<<endl<<endl;

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

			while(searchingForWinner){
			
				for(int player =1 ;player <= noOfPlayers ; player++){
					searchingForWinner= turn(playersList[player]) ;
				}
			
				cout<<endl;
			}

			cout<<" <---- Thanks ----> "<<endl;
			cout<<" Developer ---Deepak Kumar--- "<<endl;

		}


};

 


int main(){
	Game game1;

	game1.startGame();
}


