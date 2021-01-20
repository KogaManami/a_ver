#include "Life.h"
#include"Scroll.h"
#include"Enemy.h"
#include"dxlib.h"

Life::Life() {
}
Life::~Life() {};
//�������[
int Life::getHtx() { return htx; }
int Life::getHty() { return hty; }


//���C�t�`��
void Life::ldraw() {
	SetDrawArea(-3840, 0, 3840, 1080);
	//���C�t���R�̎�
	if (lifepoint == 3) {
		DrawExtendGraph(htx - htr, hty - htr, htx + htr, hty + htr, gh, TRUE);
		DrawExtendGraph(htx2 - htr, hty2 - htr, htx2 + htr, hty2 + htr, gh, TRUE);
		DrawExtendGraph(htx3 - htr, hty3 - htr, htx3 + htr, hty3 + htr, gh, TRUE);
	}

	//���C�t���Q�̎�
	if (lifepoint == 2) {
		DrawExtendGraph(htx - htr, hty - htr, htx + htr, hty + htr, gh, TRUE);
		DrawExtendGraph(htx2 - htr, hty2 - htr, htx2 + htr, hty2 + htr, gh, TRUE);

	}

	//���C�t���P�̎�
	if (lifepoint == 1) {
		DrawExtendGraph(htx - htr, hty - htr, htx + htr, hty + htr, gh, TRUE);
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