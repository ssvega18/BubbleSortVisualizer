#include "Visualizer.h"

Visualizer::Visualizer()
{
	this->initVariables();
	this->initWindow();
	this->initEntities();
	this->initText();
}

Visualizer::~Visualizer()
{
	delete this->window;
}

const bool Visualizer::running() const
{
	return this->window->isOpen();
}

void Visualizer::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {

		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
			if (this->ev.key.code == sf::Keyboard::R) {
				this->reset();
			}
		}
	}
}

void Visualizer::update()
{
	this->pollEvents();

	if (this->currIndex != this->array.size())
		this->sortArray();
}

void Visualizer::render()
{
	this->window->clear(sf::Color(0, 0, 0, 255));

	this->window->draw(this->text);
	this->window->draw(this->text2);

	for (int i = 0; i < array.size(); i++) {
		sf::RectangleShape rec;
		rec.setPosition(sf::Vector2f(this->videoMode.width / 3 + (11.f * i), this->videoMode.height / 2));
		rec.setSize(sf::Vector2f(10.f, -array[i] * 2.f));

		if (i == currIndex) {
			rec.setFillColor(sf::Color::White);
		}
		else
		{
			rec.setFillColor(sf::Color::Cyan);
		}

		this->window->draw(rec);

	}

	
	this->window->display();
}

void Visualizer::initVariables()
{
	this->window = nullptr;
	this->array = { 90, 33, 171, 185, 11, 92, 173, 8, 184, 139, 131, 106, 113, 15, 27, 63, 199, 80, 150, 20, 129, 177, 86, 57, 166, 14, 79, 127, 45, 74, 153, 101, 82, 193, 72, 121, 136, 98, 102, 48, 182, 132, 25, 122, 115, 189, 95, 10, 174, 195, 112, 152, 187, 1, 154, 158, 96, 65, 142, 105, 50, 123, 172, 47, 88, 194, 143, 107, 58, 118, 99, 145, 5, 67, 51, 53, 186, 26, 196, 180, 141, 16, 109, 35, 78, 192, 30, 6, 55, 164, 100, 91, 85, 40, 175, 124, 52, 54, 76, 200 };
	this->copyArr = array;
}

void Visualizer::initWindow()
{
	this->videoMode.height = 1200;
	this->videoMode.width = 2000;

	this->window = new sf::RenderWindow(this->videoMode, "Algo-Visualizer", sf::Style::Default);
	this->window->setFramerateLimit(144);
}

void Visualizer::initEntities()
{

}

void Visualizer::sortArray()
{
	int tmp = array[currIndex];
	int tmp2;


	


	for (int k = currIndex; k < array.size(); k++) {

		sf::RectangleShape rec1;
		rec1.setPosition(sf::Vector2f(this->videoMode.width / 3 + (11.f * currIndex), this->videoMode.height / 2));
		rec1.setSize(sf::Vector2f(10.f, -array[currIndex] * 2.f));
		rec1.setFillColor(sf::Color::White);
		this->window->draw(rec1);

		sf::RectangleShape rec;
		rec.setPosition(sf::Vector2f(this->videoMode.width / 3 + (11.f * k), this->videoMode.height / 2));
		rec.setSize(sf::Vector2f(10.f, -array[k] * 2.f));
		rec.setFillColor(sf::Color::Red);
		this->window->draw(rec);
		this->window->display();

		if (array[k] < tmp) {

			comparisonCount++;
			currAccess = k;
			updateText(comparisonCount, &text);
			tmp2 = tmp;
			tmp = array[k];
			array[k] = tmp2;
			array[currIndex] = tmp;
		}


	}

	 currIndex++;

}

void Visualizer::initText()
{
	if (!this->font.loadFromFile("fonts/04B_09__.ttf")) {
		std::cout << "ERROR: Could not load font.";
		exit(1);
	}

	this->text.setFont(this->font);
	this->text.setPosition(sf::Vector2f(200.f, 400.f));
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(40);
	this->text.setString(std::to_string(this->comparisonCount));

	this->text2.setFont(this->font);
	this->text2.setPosition(sf::Vector2f(180.f, 350.f));
	this->text2.setFillColor(sf::Color::White);
	this->text2.setCharacterSize(30);
	this->text2.setString("Comparisons:");


}

void Visualizer::reset()
{
	this->array = copyArr;
	this->currIndex = 0;
	this->currAccess = 0;
	this->comparisonCount = 0;
}

void Visualizer::updateText(unsigned int number, sf::Text* text)
{
	text->setString(std::to_string(number));
}
