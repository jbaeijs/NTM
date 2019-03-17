#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u nbImages, float tpsSwitch)
{
	this->nbImages = nbImages;
	this->tpsSwitch = tpsSwitch;
	tpsTotal = 0.0f;
	imageCourante.x = 0;

	rect.width  = texture->getSize().x / float(nbImages.x);
	rect.height = texture->getSize().y / float(nbImages.y);
}

Animation::~Animation()
{
}

void Animation::Update(int colonne, float deltaTime)
{
	imageCourante.y = colonne;
	tpsTotal += deltaTime;

	if (tpsTotal >= tpsSwitch) {
		tpsTotal -= tpsSwitch;
		imageCourante.x++;
		if (imageCourante.x >= nbImages.x) {
			imageCourante.x = 0;
		}
	}

	rect.top = imageCourante.y * rect.height;
	rect.left = imageCourante.x * rect.width;
}
