#include "Enemy.h"
#include"dxlib.h"

Enemy::Enemy(int ex, int ey, int er, int espeed, int color) {
	this->ex = ex;
	this->ey = ey;
	this->er = er;
	this->espeed = espeed;
	this->color = color;
}

//�������[
int Enemy::getEx() { return ex; }
int Enemy::getEy() { return ey; }
int Enemy::getEr() { return er; }
int Enemy::getIsalive() { return isalive; }
int Enemy::getColor() { return color; }

//�������[
void Enemy::setIsalive(int isalive) { this->isalive = isalive; }
void Enemy::setColor(int color) { this->color = color; }

//���˂݁[�ړ�
void Enemy::emove() {
	if (isalive == 1) {
		ex = ex - espeed;//�����ړ�����
	}
}

void Enemy::gun() {
	if (isalive == 1) {
		ey = ey + espeed;
		if (ey <= 1080) {
			espeed = -espeed;
		}

		if (ey >= 0) {
			espeed = -espeed;
		}
	}
}

void Enemy::homing() {}

void Enemy::sin() {}

//���˂݁[�`��
void Enemy::grayDraw() {
	SetDrawArea(-3940, 0, 3940, 1080);
	if (isalive == 1) {
		DrawBox(ex, ey, ex + er, ey + er, GetColor(100, 100, 100), TRUE);
	}
}
void Enemy::yellowDraw(Scroll* scroll) {
	SetDrawArea(-3940, 0, 3940, 1080);
	if (isalive == 1) {
		if (scroll->getFlag() == 1) {
			if (scroll->getSx() < ex) {
			DrawBox(ex, ey, ex + er, ey + er, GetColor(200, 180, 70), TRUE);
			}
		}
		if (scroll->getFlag() == 3 && scroll->getSx2() > ex) {
				DrawBox(ex, ey, ex + er, ey + er, GetColor(200, 180, 70), TRUE);
		}
		
	}
}


void Enemy::redDraw() {}
void Enemy::buleDraw() {}
void Enemy::greenDraw() {}