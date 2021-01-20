#include "Enemy.h"
#include"dxlib.h"


Enemy::Enemy(int ex, int ey, int er, int espeed) {
	this->ex = ex;
	this->ey = ey;
	this->er = er;
	this->espeed = espeed;
}

//げったー
int Enemy::getEx() { return ex; }
int Enemy::getEy() { return ey; }
int Enemy::getEr() { return er; }
int Enemy::getIsalive() { return isalive; }

//せったー
void Enemy::setIsalive(int isalive) { this->isalive = isalive; }

//えねみー描画
void Enemy::edraw() {
	if (isalive == 1) {
		SetDrawArea(-3840, 0, 3840, 1080);
		DrawBox(ex, ey, ex + er, ey + er, GetColor(50, 80, 20), TRUE);
	}
}

//えねみー移動
void Enemy::emove() {
	if (isalive == 1) {
		ex = ex - espeed;//直線移動だけ
	}
}