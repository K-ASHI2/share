#pragma once
class CKeyPad
{
private:
	int button[8];		//�ݒ肳�ꂽ�{�^���̓��̓t���[���J�E���g e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
	int button1P[8];	//�ΐ탂�[�h����1P�̓��̓t���[���J�E���g
	int button2P[8];	//�ΐ탂�[�h����2P�̓��̓t���[���J�E���g
	int key_p[8];		//�L�[�R���t�B�O�Őݒ肳�ꂽ�Q�[���p�b�h�̃{�^����z��ɃQ�[���p�b�h�̓Y�����ŕۑ����� e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
	int Key[256];		//�L�[���͂̓��̓t���[���J�E���g
	int Pad[28];		//�Q�[���p�b�h�̓��̓t���[���J�E���g
	int Pad2[28];		//2�ڂ̃Q�[���p�b�h�̓��̓t���[���J�E���g
	char *cPad[8];		//�Q�[���p�b�h�̑��삷��{�^���̕�����ő�������ɗp����
	int Pad2P[28];		//2P�̃Q�[���p�b�h�̓��̓t���[���J�E���g

public:
	CKeyPad();
	~CKeyPad();
	int getButton(int key);
	int getButton1P(int key);
	int getButton2P(int key);
	int getKey(int keyInput);
	int getPad(int padInput);
	char* getCPad(int padInput);
	//�J�[�\���̈ʒu�̃{�^���̃L�[�R���t�B�O��ύX����
	void setKeyConfig(int cursor);
	void init_key();
	void init();
	//�L�[�ƃp�b�h�����t���[��������Ă������X�V����
	void updateKey();
	void drawEx();
};
