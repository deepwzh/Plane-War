#pragma once
class CDataModel
{
public:
	struct Data {
		int score;
		int HP;
		int MP;
		int mode;
		int level;
		int arms;
		int sleep_time;
		CPoint myPoint;
	};
protected:

	Data data;
public:
	Data GetData() {
		return data;
	}
	void setData(Data data) {
		memcpy(&this->data, &data, sizeof(data));
	}
	CPoint getMyPoint() { return data.myPoint; }
	void setMyPoint(CPoint point) { this->data.myPoint = point; }
	int getScore() { return data.score; }
	void setScore(int score) { this->data.score +=  score; }
	int getHP() { return data.HP; }
	void setHP(int hp) { this->data.HP += hp; }
	int getMP() { return data.MP; }
	void setMP(int mp) { this->data.MP += mp; }
	int getMode() { return data.mode; }
	void setMode(int mode) { this->data.mode = mode; }
	int getArms() { return data.arms; }
	void setArms(int arms) { this->data.arms = arms; }
	int getLevel() { return data.level; }
	void setLevel(int level) { this->data.level = level; }
	int getSleepTime() { return data.sleep_time; }
	void setSleepTime(int sleep_time) { this->data.sleep_time = sleep_time; }
	//virtual void push() {
	//	board->update(2, getHP(), getScore());
	//}
	CDataModel();
	//void SetBoard(CGameBoard * board);
	virtual ~CDataModel();
};

