#include "Enemy.h"
#include"dxlib.h"


Enemy::Enemy(int ex, int ey, int er, int espeed) {
	this->ex = ex;
	this->ey = ey;
	this->er = er;
	this->espeed = espeed;
}

//�������[
int Enemy::getEx() { return ex; }
int Enemy::getEy() { return ey; }
int Enemy::getEr() { return er; }
int Enemy::getIsalive() { return isalive; }

//�������[
void Enemy::setIsalive(int isalive) { this->isalive = isalive; }

//���˂݁[�`��
void Enemy::edraw() {
	if (isalive == 1) {
		SetDrawArea(-3840, 0, 3840, 1080);
		DrawBox(ex, ey, ex + er, ey + er, GetColor(50, 80, 20), TRUE);
	}
}

//���˂݁[�ړ�
void Enemy::emove() {
	if (isalive == 1) {
		ex = ex - espeed;//�����ړ�����
	}
}