#include<bits/stdc++.h>
using namespace std ;

class Ladder{
	unordered_map<int,int> ladderMapping;
	

	protected:
		bool isValidBlock(int blockNumber){
			return blockNumber>=1 && blockNumber<=100 ; 
		}
	public:
		Ladder(){
			int defaultLadder[9][2] ={
				{4,14},
				{9,31},
				{21,42},
				{28,84},
				{36,44},
				{51,67},
				{71,91},
				{80,100},
			};
			 
			 for(int i=0 ;i<9 ;i++){
			 	int from = defaultLadder[i][0] ;
			 	int to = defaultLadder[i][1] ;

			 	ladderMapping[from] = to ; 
			 }

		}

		Ladder(int customLadder[][2] , int  noOfLadders){
			for(int  i =0 ;i<noOfLadders ; i++){
				int from = customLadder[i][0] ; 
				int to = customLadder[i][1] ; 

				ladderMapping[from] = to ; 
			}
		}


	// functions:

		bool isLadder(int blockNumber){
			
			return  isValidBlock(blockNumber) &&
				 ladderMapping[blockNumber] ; 
		}

		int rideLadder(int blockNumber){

			if( isValidBlock(blockNumber) && isLadder(blockNumber)){
				return ladderMapping[blockNumber];
			}

			return 0 ; 
		}

		void addLadder(int from , int to){
			
			// check if they are in same line
			if( isValidBlock(from) && isValidBlock(to) && from/10 == to/10){
				return ; 
			}

			ladderMapping[from] = to ;
			return ;
		}



		void removeLadder(int blockNumber){
			// if ladder is not present then ignore
			if( isValidBlock(blockNumber) && isLadder(blockNumber) ){
				ladderMapping[blockNumber] = 0 ; 
				return ;
			}

		}
} ;