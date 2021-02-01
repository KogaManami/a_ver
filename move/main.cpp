#include "DxLib.h"
#include"Scroll.h"
#include"Enemy.h"
#include"Life.h"
#include"Bullet.h"
#include "Scene.h"

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
	SetBackgroundColor(0x33, 0x33, 0x33);		// ��ʂ̔w�i�F��ݒ肷��

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1) { return -1; }

	//�i�_�u���o�b�t�@�j�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int Pad = 0;
	int num = 0;
	const int BULLET_MAX = 20;
	int startTimer = 40;
	int timer = 40;
	Bullet* bullet[BULLET_MAX];

	Life* life = new Life();
	Enemy* enemy = new Enemy(1970, 400, 128, 4,1);
	Enemy* enemy2 = new Enemy(2300, 400, 128, 4,1);
	Enemy* enemy3 = new Enemy(1600, 400, 128, 10,1);
	Scroll* scroll = new Scroll();
	Scene* scene = new Scene();
	
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = new Bullet();
	}

	//�Q�[�����[�v�Ŏg���ϐ��̐錾
	char keys[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	XINPUT_STATE Inputfuuma = { 0 };

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
		Pad = GetJoypadInputState(DX_INPUT_PAD1);
		//one�t���[���O�̃R���g���[���[���
		XINPUT_STATE OldInput = Inputfuuma;
		//�R���g���[���[��XINPUT����擾�ł�����𓾂�Ӂ[��
		GetJoypadXInputState(DX_INPUT_PAD1, &Inputfuuma);

		//�Q�[���V�[��
		if (scene->getSceneNo() == 0) {
			//�^�C�g��
			if (Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
				if (scene->getSceneNo() == 0) {
					scene->setSceneNo(1);
				}
			}
			scene->titleDraw();
		}
		if (scene->getSceneNo() == 1) {
			//�`���[�g���A��
			
			if (scroll->getText() < 6 && Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
				scroll->setText(scroll->getText() + 1);
			}

			if(scroll->getText() == 6) {
				startTimer--;
				if (startTimer == 0) {
					scroll->setText(7);
				}
			}

			//�ŏ��̐F�ւ�
			if (scroll->getText() == 7) {
				if (scene->getColor() == 0) {
					if (Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
						scene->setColor(1);
						scene->setFillXS(1920);
						scene->setUnder(1);
					}
					if (Inputfuuma.Buttons[XINPUT_BUTTON_A] && !OldInput.Buttons[XINPUT_BUTTON_A]) {
						scene->setColor(2);
						scene->setFillXS(1920);
						scene->setUnder(2);
					}
					if (Inputfuuma.Buttons[XINPUT_BUTTON_X] && !OldInput.Buttons[XINPUT_BUTTON_X]) {
						scene->setColor(3);
						scene->setFillXS(1920);
						scene->setUnder(3);
					}
					if (Inputfuuma.Buttons[XINPUT_BUTTON_Y] && !OldInput.Buttons[XINPUT_BUTTON_Y]) {
						scene->setColor(4);
						scene->setFillXS(1920);
						scene->setUnder(4);
					}
				}

				//2��ڈȍ~,���R�ɐF�ւ�
				if (scene->getFillXS() == 0) {
					if (scene->getColor() != 1) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
							//����������
							scene->setColor(1);
							scene->setFillXS(1920);
							scene->setUnder(1);
						}
					}

					if (scene->getColor() != 2) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_A] && !OldInput.Buttons[XINPUT_BUTTON_A]) {
							//����������
							scene->setColor(2);
							scene->setFillXS(1920);
							scene->setUnder(2);
						}
					}

					if (scene->getColor() != 3) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_X] && !OldInput.Buttons[XINPUT_BUTTON_X]) {
							//����������
							scene->setColor(3);
							scene->setFillXS(1920);
							scene->setUnder(3);
						}
					}
				
					if (scene->getColor() != 4) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_Y] && !OldInput.Buttons[XINPUT_BUTTON_Y]) {
							//����������
							scene->setColor(4);
							scene->setFillXS(1920);
							scene->setUnder(4);
						}
					}
					
				}
			}

			scene->tyutaMove();
			scene->tyutaDraw();
			SetDrawArea(-3940, 0, 3940, 1080);
			DrawFormatString(0, 80, GetColor(255, 255, 255), "fillXS=%d", scene->getFillXS());
			DrawFormatString(0, 100, GetColor(255, 255, 255), "fillXE=%d", scene->getFillXE());
			DrawFormatString(0, 120, GetColor(255, 255, 255), "under=%d", scene->getUnder());
			DrawFormatString(0, 140, GetColor(255, 255, 255), "underMemory=%d", scene->getUnderMemory());
			DrawFormatString(0, 160, GetColor(255, 255, 255), "startTimer=%d", startTimer);
		}
		if (scene->getSceneNo() == 2) {
			//�X�e�[�W1
		}
		if (scene->getSceneNo() == 3) {
			//�X�e�[�W2
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
			enemy3->gun();
			for (int i = 0; i < BULLET_MAX; i++) {
				bullet[i]->move(scroll);
			}
			life->lif(scroll, enemy);
			life->lif(scroll, enemy2);

			//�`�揈��
			scroll->hdraw();
			enemy->yellowDraw(scroll);
			enemy2->yellowDraw(scroll);
			enemy3->yellowDraw(scroll);
			life->ldraw();
			scroll->pdraw();
			for (int i = 0; i < BULLET_MAX; i++) {
				bullet[i]->draw();
			}
		}
		if (scene->getSceneNo() == 4) {
			//�X�e�[�W3
		}
		if (scene->getSceneNo() == 5) {
			//�X�e�[�W4
			
		}
		if (scene->getSceneNo() == 6) {
			//GAMEOVER���(�����ŏ�����)
		}

		
		/*for (int i = 1; i < 4; i++) {
			DrawLine(480 * i, 0, 480 * i, 1080, GetColor(0, 0, 0), TRUE);
		}*/

		DrawFormatString(0, 0, GetColor(255, 255, 255), "SceneNo=%d", scene->getSceneNo());
		DrawFormatString(0, 20, GetColor(255, 255, 255), "text=%d", scroll->getText());
		DrawFormatString(0, 40, GetColor(255, 255, 255), "Input=%d", num);
		
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
	}
	//Dx���C�u�����I������
	DxLib_End();

	return 0;
}