/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, constructor)
{
	//lets create a board
	TicTacToeBoard board;
	//now lets check that the board is empty
	for(int i=0; i<BOARDSIZE; i++)
		for(int j=0; j<BOARDSIZE; j++)
			ASSERT_EQ(board.getPiece(i,j), Blank);
}


TEST(TicTacToeBoardTest, toggleTurn)
{
	//lets create a board
	TicTacToeBoard board;
	for(int i=0; i<BOARDSIZE*BOARDSIZE; i++)
	{
		if(i%2 == 0)
			ASSERT_EQ(board.toggleTurn(), O);
		else
			ASSERT_EQ(board.toggleTurn(), X);
	}
}
TEST(TicTacToeBoardTest, out_of_bounds){
	TicTacToeBoard board;
	for(int i=-1; i<BOARDSIZE+1; i++){
		for(int j=-1; j<BOARDSIZE+1; j++){
			if(i<0 || i>=BOARDSIZE || j<0 || j>=BOARDSIZE){
				ASSERT_EQ(board.getPiece(i,j), Invalid);
			}else{
				ASSERT_EQ(board.getPiece(i,j), Blank);
			}
		}
	}
}

TEST(TicTacToeBoardTest, insert_piece){
	TicTacToeBoard board;
	for(int i=0; i<BOARDSIZE; i++){
		for(int j=0; j<BOARDSIZE; j++){
			if((i+j)%2 == 0){
				ASSERT_EQ(board.placePiece(i,j), X);
			}else{
				ASSERT_EQ(board.placePiece(i,j), O);
			}
		}
	}
}

TEST(TicTacToeBoardTest, insert_and_validate){
	TicTacToeBoard board;
	for(int i=0; i<BOARDSIZE; i++){
		for(int j=0; j<BOARDSIZE; j++){
			if((i+j)%2 == 0){
				ASSERT_EQ(board.placePiece(i,j), X);
			}else{
				ASSERT_EQ(board.placePiece(i,j), O);
			}
		}
	}
	for(int i=0; i<BOARDSIZE; i++){
		for(int j=0; j<BOARDSIZE; j++){
			if((i+j)%2 == 0){
				ASSERT_EQ(board.placePiece(i,j), X);
			}else{
				ASSERT_EQ(board.placePiece(i,j), O);
			}
		}
	}
}
TEST(TicTacToeBoardTest, insert_out_of_place){
	TicTacToeBoard board;
	//lets go from -1 to BoardSize+1
	for(int i=-1; i<BOARDSIZE+1; i++){
		for(int j=-1; j<BOARDSIZE+1; j++){
			if(i<0 || i>=BOARDSIZE || j<0 || j>=BOARDSIZE){
				ASSERT_EQ(board.placePiece(i,j), Invalid);
			}else{
				if((i+j)%2 == 0){
					ASSERT_EQ(board.placePiece(i,j), X);
				}else{
					ASSERT_EQ(board.placePiece(i,j), O);
				}
			}
		}
	}
}

TEST(TicTacToeBoardTest, testWinnerHorizontal){
	TicTacToeBoard board;
	for(int i=0; i<BOARDSIZE; i++){
		ASSERT_EQ(board.placePiece(0,i), X);
		ASSERT_EQ(board.placePiece(1,i), O);
	}
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, testWinnerVertical){
	TicTacToeBoard board;
	//lets make a vertical line
	for(int i=0; i<BOARDSIZE; i++){
		ASSERT_EQ(board.placePiece(i,0), X);
		ASSERT_EQ(board.placePiece(i,1), O);
	}
	//lets make sure the winner is X
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, testWinnerDiagonal){
	TicTacToeBoard board;
	//lets make a diagonal line
	for(int i=0; i<BOARDSIZE; i++){
		ASSERT_EQ(board.placePiece(i,i), X);
		if(i+1<BOARDSIZE)
			ASSERT_EQ(board.placePiece(i,i+1), O);
		else
			ASSERT_EQ(board.placePiece(i,i-1), O);
	}
	//lets make sure the winner is X
	ASSERT_EQ(board.getWinner(), X);
}


TEST(TicTacToeBoardTest, winnerCircle){
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,0), X);
	for(int i=0; i<BOARDSIZE; i++){
		ASSERT_EQ(board.placePiece(1,i), O);
		ASSERT_EQ(board.placePiece(2,i), X);
	}
	ASSERT_EQ(board.getWinner(), O);
}