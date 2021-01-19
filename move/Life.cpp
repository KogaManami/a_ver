#include "Life.h"
#include"Scroll.h"
#include"Enemy.h"
#include"dxlib.h"

Life::Life() {
	
}

//げったー
int Life::getHtx() { return htx; }
int Life::getHty() { return hty; }


//ライフ描画
void Life::ldraw() {

	//ライフが３の時
	if (lifepoint == 3) {
		DrawCircle(htx, hty, 30, GetColor(0, 0, 0), TRUE);
		DrawCircle(htx2, hty2, 30, GetColor(0, 0, 0), TRUE);
		DrawCircle(htx3, hty3, 30, GetColor(0, 0, 0), TRUE);
	}

	//ライフが２の時
	if (lifepoint == 2) {
		DrawCircle(htx, hty, 30, GetColor(0, 0, 0), TRUE);
		DrawCircle(htx2, hty2, 30, GetColor(0, 0, 0), TRUE);
	}

	//ライフが１の時
	if (lifepoint == 1) {
		DrawCircle(htx, hty, 30, GetColor(0, 0, 0), TRUE);
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