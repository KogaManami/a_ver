#include "Scroll.h"
#include"dxlib.h"

Scroll::Scroll() {
	WIN_WIDTH = 1920;
}

int Scroll::getPosx() { return posx; }
int Scroll::getPosy() { return posy; }
int	Scroll::getPosr() { return posr; }

void Scroll::setPosx(int posx) { this->posx = posx; }
void Scroll::setPosy(int posy) { this->posy = posy; }

//プレイヤー移動
void Scroll::pmove(char keys[255]) {
	if (posx < WIN_WIDTH / 8) {
		if (keys[KEY_INPUT_RIGHT] == 1) {
			posx = posx + 16;
		}
	}

	if (posx > 0) {
		if (keys[KEY_INPUT_LEFT] == 1) {
			posx = posx - 16;
		}
	}

	if (posy > 0) {
		if (keys[KEY_INPUT_UP] == 1) {
			posy = posy - 16;
		}
	}

	if (posy < WIN_HEIGHT) {
		if (keys[KEY_INPUT_DOWN] == 1) {
			posy = posy + 16;
		}
	}
}

//プレイヤー描画
void Scroll::pdraw() {
	DrawBox(posx, posy, posx + posr, posy + posr, GetColor(109, 90, 12), TRUE);
}

//背景移動
void Scroll::hmove(char keys[255]) {
	if (keys[KEY_INPUT_RIGHT] == 1) {
		hx = hx - 6;
		hx2 = hx2 - 6;
		hx3 = hx3 - 6;
	}
	if (keys[KEY_INPUT_LEFT] == 1) {
		hx = hx + 6;
		hx2 = hx2 + 6;
		hx3 = hx3 + 6;
	}

	//背景ループ
	if (hx <= -3840) {
		hx = 1920;
	}
	if (hx2 <= -3840) {
		hx2 = 1920;
	}
	if (hx3 <= -3840) {
		hx3 = 1920;
	}

	//実際はいらない部分　デバッグ用
	if (hx2 >= 3840) {
		hx2 = -1920;
	}
	if (hx >= 3840) {
		hx = -1920;
	}
	if (hx3 >= 3840) {
		hx3 = -1920;
	}
}

//背景描画
void Scroll::hdraw() {
	DrawGraph(hx, hy, gh, TRUE);
	DrawGraph(hx2, hy2, gh2, TRUE);
	DrawGraph(hx3, hy3, gh3, TRUE);
	DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", hx2);
}
