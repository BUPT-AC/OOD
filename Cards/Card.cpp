enum class Suit	 { Club, Diamond, Heart, Spade  };

class Card
{
protected:

	// whether this card is available to give player
	bool available = true;
	// Ace to King
	int faceValue;
	Suit suit;
public:
	Card(int c, Suit s):faceValue(c),suit(s){}
	~Card();
	int getValue();
	Suit getSuit();
	bool isAvailable();
	void makeAvailable();
	void makeUnavailable();
};


class Deck
{
private:
	vector<Card> cards;
	// the idx of undealt card
	int idx = 0;

public:
	Deck(std::vector<Card> v){};
	~Deck();

	void shuffle();
	int remainingCards();
	Card dealCard();
};

class Hand
{
protected:
	// a hand of cards
	std::vector<Card> cards;
public:
	Hand();
	~Hand();

	virtual int score();
	void addCard(Card c);
};

class Gamer
{
protected:
	Strategy strategy;
	vector<Hand> hands;
	string name;
	double money;
public:
	Gamer(arguments);
	~Gamer();
	int GetScore();
	void MakeDecision()''
	/* data */
};

class Player: public Gamer
{
private:
	// costom data
	vector<Action> actions;
public:
	Player(arguments);
	~Player();

	/* data */
};

class Dealer: public Gamer
{
private:
	Deck deck;
	// game information
public:
	Dealer(arguments);
	~Dealer();

	/* data */
};

struct Action
{
	string info;
	date time;
};