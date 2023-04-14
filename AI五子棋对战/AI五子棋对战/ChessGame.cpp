#include "ChessGame.h";

ChessGame::ChessGame(Man* man, AI* ai, Chess* chess)
{
	this->man = man;
	this->ai = ai;
	this->chess = chess;

	man->init(chess);
	ai->init(chess);
}
//对局（开始五子棋游戏）
void ChessGame::paly()
{
	chess->init();
	while (1) {
		//先由棋手下棋
		man->go();
		if (chess->checkIsOver()) {
			chess->init();
			continue;
		}
	
		//由AI下棋
		ai->go();
		if (chess->checkIsOver()) {//检查是否结束
			chess->init();
			continue;
		}
	}
}
