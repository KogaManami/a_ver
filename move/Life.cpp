#include "Life.h"
#include"Scroll.h"
#include"Enemy.h"
#include"dxlib.h"

Life::Life() {
}
Life::~Life() {};
//げったー
int Life::getHtx() { return htx; }
int Life::getHty() { return hty; }


//ライフ描画
void Life::ldraw() {
	SetDrawArea(-3840, 0, 3840, 1080);
	//ライフが３の時
	if (lifepoint == 3) {
		DrawExtendGraph(htx - htr, hty - htr, htx + htr, hty + htr, gh, TRUE);
		DrawExtendGraph(htx2 - htr, hty2 - htr, htx2 + htr, hty2 + htr, gh, TRUE);
		DrawExtendGraph(htx3 - htr, hty3 - htr, htx3 + htr, hty3 + htr, gh, TRUE);
	}

	//ライフが２の時
	if (lifepoint == 2) {
		DrawExtendGraph(htx - htr, hty - htr, htx + htr, hty + htr, gh, TRUE);
		DrawExtendGraph(htx2 - htr, hty2 - htr, htx2 + htr, hty2 + htr, gh, TRUE);

	}

	//ライフが１の時
	if (lifepoint == 1) {
		DrawExtendGraph(htx - htr, hty - htr, htx + htr, hty + htr, gh, TRUE);
	}
	DrawFormatString(0, 30, GetColor(0, 0, 0), "%d", lifepoint);
}

//当たり判定　当たったらライフ1減る
void Life::lif(Scroll* scroll, Enemy* enemy) {

	if (enemy->getIsalive() == 1) {

		//一応短形の当たり判定使ってます
		if (enemy->getEx() < scroll->getPosx() + scroll->getPosr() && scroll->getPosx() < enemy->getEx() + enemy->getEr() && enemy->getEy() < scroll->getPosy() + scroll->getPosr() && scroll->getPosy() < enemy->getEy() + enemy->getEr()) {
			enemy->setIsalive(0);//敵を消す

			flag = 1;//当たりフラグ

			if (flag == 1) {
				if (lifepoint >= 0) {//ライフが０以下にならないようにする
					lifepoint -= 1;
				}
			}
		}
	}
}