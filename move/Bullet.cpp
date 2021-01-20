#include "Bullet.h"
#include"dxlib.h"
Bullet::Bullet() {}

Bullet::~Bullet() {}

void Bullet::init(Scroll* scroll) {
	//posX = scroll->getPosx();
	//posY = scroll->getPosy();
}

void Bullet::alive(Scroll* scroll, char oldkey[255], char keys[255]) {
	timer--;
	//if (timer == 0) {
		//isAlive = 1;
		//timer = 10;

	//}

	if (/*keys[KEY_INPUT_V] == 1*/bflag == 0) {
		bflag = 1;
		isAlive = 1;
		posX = scroll->getPosx();
		posY = scroll->getPosy();
	}
	if (posX >= 1920) {
		isAlive = 0;
		bflag = 0;
	}

}

void Bullet::move() {
	if (bflag == 1) {
		posX = posX + speed;
	}
}

void Bullet::draw() {
	if (isAlive == 1) {
		DrawCircle(posX + 128, posY + 64, radius, GetColor(150, 150, 150), TRUE);
		DrawFormatString(0, 128, GetColor(0, 0, 0), "bullPosX=%f", posX);
	}
}