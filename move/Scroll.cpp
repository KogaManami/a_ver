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

//�v���C���[�ړ�
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

//�v���C���[�`��
void Scroll::pdraw() {
	DrawBox(posx, posy, posx + posr, posy + posr, GetColor(109, 90, 12), TRUE);
}

//�w�i�ړ�
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

	//�w�i���[�v
	if (hx <= -3840) {
		hx = 1920;
	}
	if (hx2 <= -3840) {
		hx2 = 1920;
	}
	if (hx3 <= -3840) {
		hx3 = 1920;
	}

	//���ۂ͂���Ȃ������@�f�o�b�O�p
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

//�w�i�`��
void Scroll::hdraw() {
	DrawGraph(hx, hy, gh, TRUE);
	DrawGraph(hx2, hy2, gh2, TRUE);
	DrawGraph(hx3, hy3, gh3, TRUE);
	DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", hx2);
}
