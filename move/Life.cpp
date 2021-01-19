#include "Life.h"
#include"Scroll.h"
#include"Enemy.h"
#include"dxlib.h"

Life::Life() {
	
}

//�������[
int Life::getHtx() { return htx; }
int Life::getHty() { return hty; }


//���C�t�`��
void Life::ldraw() {

	//���C�t���R�̎�
	if (lifepoint == 3) {
		DrawCircle(htx, hty, 30, GetColor(0, 0, 0), TRUE);
		DrawCircle(htx2, hty2, 30, GetColor(0, 0, 0), TRUE);
		DrawCircle(htx3, hty3, 30, GetColor(0, 0, 0), TRUE);
	}

	//���C�t���Q�̎�
	if (lifepoint == 2) {
		DrawCircle(htx, hty, 30, GetColor(0, 0, 0), TRUE);
		DrawCircle(htx2, hty2, 30, GetColor(0, 0, 0), TRUE);
	}

	//���C�t���P�̎�
	if (lifepoint == 1) {
		DrawCircle(htx, hty, 30, GetColor(0, 0, 0), TRUE);
	}
	DrawFormatString(0, 30, GetColor(0, 0, 0), "%d", lifepoint);
}

//�����蔻��@���������烉�C�t1����
void Life::lif(Scroll* scroll, Enemy* enemy) {

	if (enemy->getIsalive() == 1) {

		//�ꉞ�Z�`�̓����蔻��g���Ă܂�
		if (enemy->getEx() < scroll->getPosx() + scroll->getPosr() && scroll->getPosx() < enemy->getEx() + enemy->getEr() && enemy->getEy() < scroll->getPosy() + scroll->getPosr() && scroll->getPosy() < enemy->getEy() + enemy->getEr()) {
			enemy->setIsalive(0);//�G������

			flag = 1;//������t���O

			if (flag == 1) {
				if (lifepoint >= 0) {//���C�t���O�ȉ��ɂȂ�Ȃ��悤�ɂ���
					lifepoint -= 1;
				}
			}
		}
	}
}