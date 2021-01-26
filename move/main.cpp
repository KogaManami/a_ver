#include "DxLib.h"
#include"Scroll.h"
#include"Enemy.h"
#include"Life.h"
#include"Bullet.h"

const char TITLE[] = "Fill_Color";

const int WIN_WIDTH = 1970; //�E�B���h�E����
const int WIN_HEIGHT = 1080;//�E�B���h�E�c��

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);						//�E�B���h�E���[�h�ɐݒ�
	//�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// �^�C�g����ύX
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�i���j�^�[�̉𑜓x�ɍ��킹��j
	SetWindowSizeExtendRate(1.0);				//��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
	SetBackgroundColor(0x00, 0x00, 0xFF);		// ��ʂ̔w�i�F��ݒ肷��

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1) { return -1; }

	//�i�_�u���o�b�t�@�j�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	const int BULLET_MAX = 20;
	int timer = 40;
	Bullet* bullet[BULLET_MAX];
	
	Life* life = new Life();
	Enemy* enemy = new Enemy(400, 400, 30, 3);
	Enemy* enemy2 = new Enemy(800, 400, 30, 3);
	Scroll* scroll = new Scroll();

	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = new Bullet();
	}
	
	//�Q�[�����[�v�Ŏg���ϐ��̐錾
	char keys[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	// �Q�[�����[�v
	while (1)
	{
		//�ŐV�̃L�[�{�[�h��񂾂������̂͂P�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		//�ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		//��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//
		//�X�V����
		//�e�̃Z�b�gtimer
		timer--;
		
		//scroll�̂Ƃ���Ƀv���C���[����Ă܂�
		scroll->hmove(keys);
		scroll->pmove(keys);
		for (int i = 0; i < BULLET_MAX; i++) {
			if (timer == 0) {
				if (bullet[i]->getIsActive() == 0) {
					bullet[i]->activate(scroll);
					timer = 40;
					break;
				}
			}
		}
		
		enemy->emove();
		enemy2->emove();
		for (int i = 0; i < BULLET_MAX; i++) {
			bullet[i]->move(scroll);
		}
		life->lif(scroll, enemy);
		life->lif(scroll, enemy2);

		//�`�揈��
		scroll->hdraw();
		enemy->edraw();
		enemy2->edraw();
		life->ldraw();
		scroll->pdraw();
		for (int i = 0; i < BULLET_MAX; i++) {
			bullet[i]->draw();
		}
		for(int i=1;i<4;i++) {
			DrawLine(480 * i, 0, 480 * i, 1080, GetColor(0, 0, 0), TRUE);
		}
		//---------  �����܂łɃv���O�������L�q  ---------//
		ScreenFlip();//�i�_�u���o�b�t�@�j����
		// 20�~���b�ҋ@�i�^��60FPS�j
		WaitTimer(20);
		// Windows �V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}
		// �d�r�b�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
		//delete life;
	}
	//Dx���C�u�����I������
	DxLib_End();

	return 0;
}