#pragma once
class CDataModel
{
protected:
	int score;
	int HP;
	int MP;
	int mode;
	int level;
	int arms;
	int sleep_time;
public:
	int getScore() { return score; }
	void setScore(int score) { this->score +=  score; }
	int getHP() { return HP; }
	void setHP(int hp) { this->HP += hp; }
	int getMP() { return MP; }
	void setMP(int mp) { this->MP += mp; }
	int getMode() { return mode; }
	void setMode(int mode) { this->mode = mode; }
	int getArms() { return arms; }
	void setArms(int arms) { this->arms = arms; }
	int getLevel() { return level; }
	void setLevel(int level) { this->level = level; }
	int getSleepTime() { return sleep_time; }
	void setSleepTime(int sleep_time) { this->sleep_time = sleep_time; }
	//virtual void push() {
	//	board->update(2, getHP(), getScore());
	//}
	CDataModel();
	//void SetBoard(CGameBoard * board);
	virtual ~CDataModel();
};

