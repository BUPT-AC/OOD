
public class TicTacToe {
	GAME_STATE state;
	Board gameBoard;
	User player;
	User AI;
	
	public TicTacToe(){}
	public void initGame(){}
	public void nextPlayerMove(){}
	public void updateGame(){}
}

enum CELL_STATE {
	CIR, CRO, EMP
}

enum USER_STATE {
	CROSS, CIRCLE;
}

enum GAME_STATE {
	PLAYING, CROSS_WIN, CIRCLE_WIN;
}

class Cell {
	CELL_STATE state;
	int row;
	int col;
	
	public CELL_STATE getState(){}
	public void setState(CELL_STATE state){this.state = state}
	public void clear(){}
}

class Board {
	Cell[][] table;
	static final int rowNum = 3;
	static final int colNum = 3;
	public Board(){}
	public void clear(){}
	public boolean isWin(User u){}
}

abstract class User {
	USER_STATE state;
	String userName;	
	Board table;
	
	public User(String name, USER_STATE state, Board table) {}
	public void setUserName(String name){}
	//place circle or cross
	public boolean setNextMove(int x, int y){}
	public USER_STATE getState(){}
}

class Player extends User {
	public Player(String name, USER_STATE state, Board table){
		super(name, state, table);
	}
	
}

class AI extends User {
	public AI(String name, USER_STATE state, Board table){
		super(name, state, table);
	}
	//Use algorithm to find the next best move
	public int[] nextBestMove() {}
	public boolean setNextMove() {}
}



