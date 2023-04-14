#include "ChessGame.h";

ChessGame::ChessGame(Man* man, AI* ai, Chess* chess)
{
	this->man = man;
	this->ai = ai;
	this->chess = chess;

	man->init(chess);
	ai->init(chess);
}
//�Ծ֣���ʼ��������Ϸ��
void ChessGame::paly()
{
	chess->init();
	while (1) {
		//������������
		man->go();
		if (chess->checkIsOver()) {
			chess->init();
			continue;
		}
	
		//��AI����
		ai->go();
		if (chess->checkIsOver()) {//����Ƿ����
			chess->init();
			continue;
		}
	}
}
