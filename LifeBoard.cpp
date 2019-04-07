#include "LifeBoard.h"


LifeBoard::LifeBoard()
{
}

int LifeBoard::getxQuads() {
	return xQuads;
}

int LifeBoard::getyQuads() {
	return yQuads;
}

bool LifeBoard::isAlive(int x, int y) {
	return cellGrid[x][y].alive;
}

void LifeBoard::setAlive(int x, int y) {
	cellGrid[x][y].alive = true;
}

void LifeBoard::update(bool shouldI) {
	if (shouldI) {
		//checks every cell, if its' alive check if it must die, if its dead, check if it can be born
		for (int i = 0; i < yQuads; i++) {
			for (int j = 0; j < xQuads; j++) {
				int liveCells = 0;
				//top left
				if (j - 1 >= 0 && i - 1 >= 0 && cellGrid[j - 1][i - 1].alive) {
					liveCells++;
				}

				//top
				if (i - 1 >= 0 && cellGrid[j][i - 1].alive) {
					liveCells++;
				}

				//top right
				if (j + 1 <= xQuads - 1 && i - 1 >= 0 && cellGrid[j + 1][i - 1].alive) {
					liveCells++;
				}

				//right
				if (j + 1 <= xQuads - 1 && cellGrid[j + 1][i].alive) {
					liveCells++;
				}

				//bottom right
				if (j + 1 <= xQuads - 1 && i + 1 <= yQuads - 1 && cellGrid[j + 1][i + 1].alive) {
					liveCells++;
				}

				//bottom
				if (i + 1 <= yQuads - 1 && cellGrid[j][i + 1].alive) {
					liveCells++;
				}

				//bottom left
				if (j - 1 >= 0 && i + 1 <= yQuads - 1 && cellGrid[j - 1][i + 1].alive) {
					liveCells++;
				}

				//left
				if (j - 1 >= 0 && cellGrid[j - 1][i].alive) {
					liveCells++;
				}

				cellGrid[j][i].livingNeighbours = liveCells;
			}
		}

		for (int i = 0; i < yQuads; i++) {
			for (int j = 0; j < xQuads; j++) {
				if (cellGrid[j][i].alive) {
					if (cellGrid[j][i].livingNeighbours < 2 || cellGrid[j][i].livingNeighbours > 3) {
						cellGrid[j][i].alive = false;
					}
				}
				else {
					if (cellGrid[j][i].livingNeighbours == 3) {
						cellGrid[j][i].alive = true;
					}
				}
			}
		}
	}
}

LifeBoard::~LifeBoard()
{
}
