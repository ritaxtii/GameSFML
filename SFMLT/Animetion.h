#pragma once
#include <SFML/Graphics.hpp>
class Animetion
{

public:
	Animetion(sf::Texture* texture, sf::Vector2u imageCount,float switchTime);
	~Animetion();
	void Update(int row, float deltaTime,bool faceRight);
public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

