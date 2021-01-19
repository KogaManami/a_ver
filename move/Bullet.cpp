#include "Bullet.h"

Bullet::Bullet() {}

Bullet::~Bullet() {}

void Bullet::init(Scroll* scroll) {
	//posX = scroll->getPosx();
	//posY = scroll->getPosy();
}

void Bullet::alive(Scroll* scroll) {
	timer--;
	if (timer == 0) {
		isAlive = 1;
		timer = 10;
		
	}

	if(isAlive==1) {
		posX = scroll->getPosx();
		posY = scroll->getPosy();
	}
}

void Bullet::move() {
	if (isAlive == 1) {
		posX = posX + speed;
	}
}

void Bullet::draw() {
	if (isAlive == 1) {
		DrawCircle(posX+128, posY+64, radius, GetColor(150, 150, 150), TRUE);
		DrawFormatString(0, 128, GetColor(0, 0, 0), "bullPosX=%f", posX);
	}
}