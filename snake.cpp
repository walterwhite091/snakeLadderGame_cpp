#include<bits/stdc++.h>
using namespace std ;

class Snake {
	unordered_map<int,int> snakeMapping ; 

	protected:

		bool isValidBlock(int blockNumber){
			return blockNumber>=1 && blockNumber<=100 ; 
		}

	public:
		Snake(){
			int defaultSnakes[10][2]={
				{16,6},
				{49,11},
				{47,26},
				{56,53},
				{64,60},
				{87,24},
				{93,73},
				{95,75},
				{98,78},
				} ; 

				for(int i=0 ; i<10 ; i++){
					int from = defaultSnakes[i][0];
					int to = defaultSnakes[i][1] ;

					snakeMapping[from] = to ; 
				}

			} 

		Snake(int customSnakes[][2] , int noOfSnakes){

			for(int i=0 ;i<noOfSnakes ; i++){
				int from = customSnakes[i][0] ; 
				int to = customSnakes[i][1] ; 

				snakeMapping[from] = to ; 
			}

		}

		bool isSnake(int blockNumber){
		
			if(!isValidBlock(blockNumber))
				return false ; 

			return snakeMapping[blockNumber] ; 
		}

		int snakeBite(int blockNumber){
		
			if(isValidBlock(blockNumber)  && isSnake(blockNumber))
				return snakeMapping[blockNumber] ; 	

			return 0 ;
		}

		void addSnake(int from , int to){
		
			if(isValidBlock(from) && isValidBlock(to))
				snakeMapping[from] = to ; 
		 }

		void removeSnake(int blockNumber){
		
			if(isValidBlock(blockNumber)  && isSnake(blockNumber))
				snakeMapping[blockNumber] =0 ;
		}
} ; 