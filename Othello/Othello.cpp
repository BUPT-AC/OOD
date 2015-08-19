/*
Description: Design the game of Othello (https://en.wikipedia.org/wiki/Reversi). 
*/

enum class Color{WHITE, BLACK};
enum class Direction {LEFT,RIGHT,UP,DOWN};
// singleton class for Game
class Game
{
private:
	Game(){
		// init all members
	}
	Player player1;
	Player player2;
	Board board;
	const int NUM_ROW = 0;
	const int NUM_COL = 0;
public:
	static Game & getInstance(){

		static Game instance = Game();
		return instance;
	}
	Board getBoard();
};

class Board
{
	vector<vector<Piece>> borad;
	int black_score = 0;
	int white_score = 0;
public:
	Board(int col, int row);

	void display();
	bool placeColor(int row, int col, Color c);
	bool flip(int row, int col, Color c, Direction d);

	void updateScore();
};

class Piece
{
private:
	Color c;
public:
	Piece(Color c);
	~Piece();
	void flip();
	Color getColor();
};

class Player
{
private:

	Color c;
public:
	Player(Color);
	~Player();

	int getScore();
	bool playPiece(int row, int col){
		return Game::getInstance().getBoard.placeColor(row,col,c);
	}
};