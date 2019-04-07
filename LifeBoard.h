#pragma once
class LifeBoard
{
private:
	static const int xQuads = 64;
	static const int yQuads = 64;

	struct Cell {
		bool alive = false;
		int livingNeighbours = 0;
	};

	Cell cellGrid[xQuads][yQuads] = { 0 };

public:
	LifeBoard();
	int getxQuads();
	int getyQuads();
	bool isAlive(int x, int y);
	void setAlive(int x, int y);
	void update(bool shouldI);
	~LifeBoard();
};

