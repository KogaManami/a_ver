#include "Bullet.h"
#include"dxlib.h"

//�R���X�g���N�g
Bullet::Bullet() {
	isActive = 0;
}

//�f�X�g���N�g
Bullet::~Bullet() {}

//�Q�b�^�[
int Bullet::getIsActive() { return isActive; }

void Bullet::activate(Scroll* scroll) {
	isActive = 1;
	timer = 0;
	posX = scroll->getPosx();
	posY = scroll->getPosy();
}

void Bullet::move(Scroll* scroll) {
	if (isActive == 1) {
		posX = posX + speed;
	}

	if (posX >= 1920) {
		isActive = 0;
		posX = scroll->getPosx();
		posY = scroll->getPosy();
	}

}

void Bullet::draw() {
	if (isActive == 1) {
		DrawCircle(posX + 128, posY + 64, radius, GetColor(150, 150, 150), TRUE);
	}
}