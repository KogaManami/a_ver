#include "Bullet.h"
#include"dxlib.h"

//コンストラクト
Bullet::Bullet() {
	isActive = 0;
	LoadDivGraph("Resources/bullet_RGB.png", 9, 9, 1, 64, 64, bullGh);
}

//デストラクト
Bullet::~Bullet() {}

//ゲッター
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
	ATCount--;
	if(ATCount==0) {
		ATCount = 4;
		AT++;
	}

	if (AT == 8) {
		AT = 0;
	}
	if (isActive == 1) {
		DrawExtendGraph(posX + 128, posY + 32, posX + 192, posY + 96, bullGh[AT],TRUE);
		
	}
}

