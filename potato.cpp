#include <bangtal>
#include <Windows.h>
using namespace bangtal;

#include <cstdlib>
#include <ctime>

ScenePtr sceneGame;
ScenePtr sceneEnd;
ScenePtr sceneRule;
ScenePtr scenePlay;
ObjectPtr ears;
ObjectPtr arms;
ObjectPtr shoes;
ObjectPtr hat;
ObjectPtr eyes;
ObjectPtr mouth;
ObjectPtr start2;
ObjectPtr man;
TimerPtr timer;
TimerPtr timerr;
float animationtime = 0.1f;
int count = 0;
int manX;
int manY;
int s1, s2, s3, s4, s5;


// 미니게임1 - 토이스토리
void picture() {
	auto ears = Object::create("image/귀.png", sceneGame, 100, 200);
	ears->setScale(0.2f);
	auto arms = Object::create("image/팔.png", sceneGame, 410, 120);
	arms->setScale(1.0f);
	auto shoes = Object::create("image/신발.png", sceneGame, 700, 100);
	shoes->setScale(0.2f);
	auto hat = Object::create("image/모자.png", sceneGame, 240, 530);
	hat->setScale(0.2f);
	auto eyes = Object::create("image/눈.png", sceneGame, 330, 520);
	eyes->setScale(0.2f);
	auto mouth = Object::create("image/입.png", sceneGame, 600, 400);
	mouth->setScale(0.2f);

	
	ears->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		auto ears1 = Object::create("image/감자몸_03.jpg", sceneGame, 1050, 400);
		auto ears2 = Object::create("image/감자몸_05.jpg", sceneGame, 888, 317);
		auto ears3 = Object::create("image/감자몸_07.jpg", sceneGame, 1050, 317);
		count = count + 1;
		if (count == 6) {
			showMessage("!성공!");
			sceneEnd->enter();
		}
		return true;
		});
	arms->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		auto arms1 = Object::create("image/감자몸_04.jpg", sceneGame, 1131, 400);
		auto arms2 = Object::create("image/감자몸_08.jpg", sceneGame, 1131, 317);
		auto arms3 = Object::create("image/감자몸_09.jpg", sceneGame, 888, 234);
		count = count + 1;
		if (count == 6) {
			showMessage("!성공!");
			sceneEnd->enter();
		}
		return true;
		});
	shoes->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		auto shoes1 = Object::create("image/감자몸_13.jpg", sceneGame, 888, 151);
		auto shoes2 = Object::create("image/감자몸_14.jpg", sceneGame, 969, 151);
		auto shoes3 = Object::create("image/감자몸_15.jpg", sceneGame, 1050, 151);
		count = count + 1;
		if (count == 6) {
			showMessage("!성공!");
			sceneEnd->enter();
		}
		return true;
		});
	hat->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		auto hat1 = Object::create("image/감자몸_01.jpg", sceneGame, 888, 400);
		auto hat2 = Object::create("image/감자몸_02.jpg", sceneGame, 969, 400);
		count = count + 1;
		if (count == 6) {
			showMessage("!성공!");
			sceneEnd->enter();
		}
		return true;
		});
	eyes->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		auto eyes1 = Object::create("image/감자몸_06.jpg", sceneGame, 969, 317);
		count = count + 1;
		if (count == 6) {
			showMessage("!성공!");
			sceneEnd->enter();
		}
		return true;
		});
	mouth->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		auto mouth1 = Object::create("image/감자몸_10.jpg", sceneGame, 969, 234);
		auto mouth2 = Object::create("image/감자몸_11.jpg", sceneGame, 1050, 234);
		count = count + 1;
		if (count == 6) {
			showMessage("!성공!");
			sceneEnd->enter();
		}
		return true;
		});
}



int main() {
	auto GameStart = Scene::create("시작", "image/시작.png");
	auto sceneStart = Scene::create("시작", "image/토이스토리 처음.png");
	auto startB = Object::create("image/스타트.png", GameStart, 400, 80);
	startB -> setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		sceneStart->enter();
		return true;
		});
	sceneEnd = Scene::create("끝", "image/토이마지막배경.jpg");
	sceneGame = Scene::create("게임", "image/토이스토리게임.jpg");
	auto sceneStart2 = Scene::create("시작", "image/하늘에서시작.png");
	auto sceneEnd2 = Scene::create("끝", "image/음식끝배경.png");
	sceneRule = Scene::create("설명", "image/하늘설명.png");
	scenePlay = Scene::create("하늘게임", "image/땅배경.png");
	auto start2 = Object::create("image/startbutton.png", sceneRule, 400, 100);
	start2->setScale(0.6f);
	start2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scenePlay->enter();
		timer->start();
		return true;
	});
	auto start = Object::create("image/startbutton.png", sceneStart, 500, 600);
	start->setScale(0.7f);
	start->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		sceneGame->enter();
		return true;
		});




	// 미니게임2 - 하늘에서 음식이 내려온다면
	auto next = Object::create("image/NEXT.png", sceneEnd, 600, 300);
	next->setScale(0.6f);
	next->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		sceneStart2->enter();
		showMessage("스페이스바를 누르세요.");
		sceneStart2->setOnKeyboardCallback([&](ScenePtr scene, KeyCode key, bool pressed)->bool {
			if (key == KeyCode::KEY_SPACE) {
				sceneRule->enter();
				return true;
			}});
		return true;
	});


	auto man = Object::create("image/주인공.png", scenePlay, 550, 60);
	man->setScale(0.5f);
	auto manX = 550;
	scenePlay->setOnKeyboardCallback([&](ScenePtr scene, KeyCode key, bool pressed)->bool {
		if (key == KeyCode::KEY_RIGHT_ARROW) {
			manX = manX + 20;
			man->locate(scenePlay, manX, 60);
		}
		else if (key == KeyCode::KEY_LEFT_ARROW) {
			manX = manX - 20;
			man->locate(scenePlay, manX, 60);
		}
		return true;
	});
	


	auto bread = Object::create("image/빵.png", scenePlay, 200, 700);
	bread->setScale(0.5f);
	int breadX = 200;
	int breadY = 700;
	auto toma = Object::create("image/토마토.png", scenePlay, 400, 900);
	toma->setScale(0.5f);
	int tomaX = 400;
	int tomaY = 900;
	auto pa = Object::create("image/패티.png", scenePlay, 100, 800);
	pa->setScale(0.5f);
	int paX = 100;
	int paY = 800;
	auto cab = Object::create("image/양상추.png", scenePlay, 700, 700);
	cab->setScale(0.5f);
	int cabX = 700;
	int cabY = 700;
	auto che = Object::create("image/치즈.png", scenePlay, 900, 800);
	che->setScale(0.5f);
	int cheX = 900;
	int cheY = 800;


	timer = Timer::create(animationtime);
	timer->setOnTimerCallback([&](auto)->bool {
		bread->locate(scenePlay, breadX, breadY);
		breadY -= 10;
		toma->locate(scenePlay, tomaX, tomaY);
		tomaY -= 11;
		pa->locate(scenePlay, paX, paY);
		paY -= 8;
		cab->locate(scenePlay, cabX, cabY);
		cabY -= 13;
		che->locate(scenePlay, cheX, cheY);
		cheY -= 16;

		//int s1, s2, s3, s4, s5;

		timer->set(animationtime);
		timer->start();
		if ((breadX - 70 < manX) && (manX < breadX + 50) && (50 < breadY) && (breadY < 80)) {
			auto cbread = Object::create("image/c빵.png", scenePlay, 1200, 400);
			cbread->setScale(0.7f);
			s1 = 1;
		}
		if ((tomaX - 70 < manX) && (manX < tomaX + 50) && (50 < tomaY) && (tomaY < 80)) {
			auto ctoma = Object::create("image/c토마토.png", scenePlay, 1200, 350);
			ctoma->setScale(0.7f);
			s2 = 1;
		}
		if ((paX - 70 < manX) && (manX < paX + 50) && (50 < paY) && (paY < 80)) {
			auto cpa = Object::create("image/c패티.png", scenePlay, 1200, 300);
			cpa->setScale(0.7f);
			s3 = 1;
		}
		if ((cabX - 70 < manX) && (manX < cabX + 50) && (50 < cabY) && (cabY < 80)) {
			auto ccab = Object::create("image/c양상추.png", scenePlay, 1200, 250);
			ccab->setScale(0.7f);
			s4 = 1;
		}
		if ((cheX - 70 < manX) && (manX < cheX + 50) && (50 < cheY) && (cheY < 70)) {
			auto cche = Object::create("image/c치즈.png", scenePlay, 900, 200);
			cche->setScale(0.3f);
			s5 = 1;
		}

		if (breadY == 20) {
			breadX += 100;
			breadY = 700;
		}
		if (tomaY == 20) {
			tomaX += 100;
			tomaY = 900;
		}
		if (paY <= 20) {
			paX += 100;
			paY = 700;
		}
		if (cabY <= 20) {
			cabX -= 100;
			cabY = 700;
		}
		if (cheY <= 20) {
			cheX -= 100;
			cheY = 800;
		}

		if (s1 + s2 + s3 + s4 + s5 == 5) {
			sceneEnd2->enter();
		}

		return true;
	});



	picture();

	startGame(GameStart);
	return 0;
}