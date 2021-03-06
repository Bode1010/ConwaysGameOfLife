#include <iostream>
#include <SFML/Graphics.hpp>
#include "LifeBoard.h"
#include <thread>
#include <chrono>
using namespace std;

int main()
{
	cout << "Right Click to pause/resume, Left click to place organisms" << endl;
	LifeBoard board;
	int xQuads = board.getxQuads();
	int yQuads = board.getyQuads();
	int width = 8;
	int space = 2;
	sf::RenderWindow window(sf::VideoMode(xQuads * (width + space), yQuads * (width + space)), "Conways' Game of Life");
	sf::VertexArray grid(sf::Quads, xQuads * yQuads * 4);
	bool iShould = true;

	while (window.isOpen()) {
		board.update(iShould);

		sf::Event evnt;
		while (window.pollEvent(evnt)) {

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if (iShould) {
					iShould = false;
					cout << "Paused" << endl;
				}
				else {
					iShould = true;
					cout << "Resumed" << endl;
				}
			}
		}

		for (int i = 0; i < yQuads; i++) {
			for (int j = 0; j < xQuads; j++) {
				grid[4 * (i * xQuads + j)].position = sf::Vector2f(j * (width + space), i * (width + space));
				grid[4 * (i * xQuads + j) + 1].position = sf::Vector2f(j * (width + space) + width, i * (width + space));
				grid[4 * (i * xQuads + j) + 2].position = sf::Vector2f(j * (width + space) + width, i * (width + space) + width);
				grid[4 * (i * xQuads + j) + 3].position = sf::Vector2f(j * (width + space), i * (width + space) + width);


				/*if (sf::Mouse::getPosition(window).x >= j * (width + space) && sf::Mouse::getPosition(window).x <= j * (width + space) + width) {
					if (sf::Mouse::getPosition(window).y >= i * (width + space) && sf::Mouse::getPosition(window).y <= i * (width + space) + width) {
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
							board.setAlive(j, i);
						}
					}
				}*/
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					int x = sf::Mouse::getPosition(window).x / (width + space);
					int y = sf::Mouse::getPosition(window).y / (width + space);
					board.setAlive(x, y);
				}
				

				if (board.isAlive(j, i)) {
					sf::Color cellColor = sf::Color::Yellow;
					grid[4 * (i * xQuads + j)].color = cellColor;
					grid[4 * (i * xQuads + j) + 1].color = cellColor;
					grid[4 * (i * xQuads + j) + 2].color = cellColor;
					grid[4 * (i * xQuads + j) + 3].color = cellColor;
				}
				else {
					sf::Color cellColor = sf::Color::White;
					grid[4 * (i * xQuads + j)].color = cellColor;
					grid[4 * (i * xQuads + j) + 1].color = cellColor;
					grid[4 * (i * xQuads + j) + 2].color = cellColor;
					grid[4 * (i * xQuads + j) + 3].color = cellColor;
				}
			}
		}

		if(iShould)
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		window.clear();
		window.draw(grid);
		window.display();
	}
	cin.get();
	return 0;
}
