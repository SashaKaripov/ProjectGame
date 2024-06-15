#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <ctime>
#include "menu.h"
#include "functions.h"

struct SpriteOfObj {
	sf::Image img;
	sf::Texture txtr;
	sf::Sprite mainsprt, copysprt;
};

int main(){
	SpriteOfObj *wall = new SpriteOfObj;
	(*wall).img.loadFromFile("texture/frstwall.png");
	(*wall).txtr.loadFromImage((*wall).img);
	(*wall).copysprt.setTexture((*wall).txtr);
	(*wall).mainsprt.setTexture((*wall).txtr);
	SpriteOfObj *hell = new SpriteOfObj;
	(*hell).img.loadFromFile("texture/mainheaven.png");
	(*hell).txtr.loadFromImage((*hell).img);
	(*hell).copysprt.setTexture((*hell).txtr);
	(*hell).mainsprt.setTexture((*hell).txtr);
	//спрайт оружи€
	SpriteOfObj *case1 = new SpriteOfObj, *case2 = new SpriteOfObj,
				*case3 = new SpriteOfObj, *case4 = new SpriteOfObj,
				*case5 = new SpriteOfObj, *case6 = new SpriteOfObj;
	SpriteOfObj gunCases[6]{ *case1, *case2, *case3, *case4, *case5, *case6 };
	for (short i = 0; i < 6; ++i){
		gunCases[i].img.loadFromFile("texture/gun/" + 
									 std::to_string(i + 1) + ".png");
		gunCases[i].txtr.loadFromImage(gunCases[i].img);
		gunCases[i].copysprt.setTexture(gunCases[i].txtr);
		gunCases[i].mainsprt.setTexture(gunCases[i].txtr);
	}
	SpriteOfObj *scope = new SpriteOfObj;
	(*scope).img.loadFromFile("texture/scope/scope.png");
	(*scope).txtr.loadFromImage((*scope).img);
	(*scope).copysprt.setTexture((*scope).txtr);
	(*scope).mainsprt.setTexture((*scope).txtr);
	SpriteOfObj *mnstranim1 = new SpriteOfObj, *mnstranim2 = new SpriteOfObj,
				*mnstranim3 = new SpriteOfObj, *mnstranim4 = new SpriteOfObj,
				*mnstranim5 = new SpriteOfObj, *mnstranim6 = new SpriteOfObj,
				*mnstranim7 = new SpriteOfObj, *mnstranim8 = new SpriteOfObj,
				*mnstranim9 = new SpriteOfObj, *mnstranim10 = new SpriteOfObj;
	SpriteOfObj mnstrAnimx[10]{ *mnstranim1, *mnstranim2, *mnstranim3,
								*mnstranim4, *mnstranim5, *mnstranim6,
								*mnstranim7, *mnstranim8, *mnstranim9,
								*mnstranim10 };
	for (short i = 0; i < 10; ++i){
		mnstrAnimx[i].img.loadFromFile("texture/mnstr/mnstr" + 
									   std::to_string(i + 1) + ".png");
		mnstrAnimx[i].txtr.loadFromImage(mnstrAnimx[i].img);
		mnstrAnimx[i].copysprt.setTexture(mnstrAnimx[i].txtr);
		mnstrAnimx[i].mainsprt.setTexture(mnstrAnimx[i].txtr);
	}
	SpriteOfObj *healthbar1 = new SpriteOfObj, *healthbar2 = new SpriteOfObj,
				*healthbar3 = new SpriteOfObj, *healthbar4 = new SpriteOfObj;
	SpriteOfObj healthBar[4]{ *healthbar1, *healthbar2,
							  *healthbar3, *healthbar4 };
	for (short i = 0; i < 4; ++i){
		healthBar[i].img.loadFromFile("texture/healthbar/health" + 
									  std::to_string(i + 1) + ".png");
		healthBar[i].txtr.loadFromImage(healthBar[i].img);
		healthBar[i].copysprt.setTexture(healthBar[i].txtr);
		healthBar[i].mainsprt.setTexture(healthBar[i].txtr);
	}
	SpriteOfObj *dead = new SpriteOfObj, *tryagain = new SpriteOfObj,
				*gotomenu = new SpriteOfObj;
	SpriteOfObj forDeadMenu[3]{ *dead, *tryagain, *gotomenu };
	for (short i = 0; i < 3; ++i){
		forDeadMenu[i].img.loadFromFile("texture/deadmenu/" + 
										std::to_string(i + 1) + ".png");
		forDeadMenu[i].txtr.loadFromImage(forDeadMenu[i].img);
		forDeadMenu[i].copysprt.setTexture(forDeadMenu[i].txtr);
		forDeadMenu[i].mainsprt.setTexture(forDeadMenu[i].txtr);
	}
	SpriteOfObj *winchik = new SpriteOfObj;
	(*winchik).img.loadFromFile("texture/win/win.png");
	(*winchik).txtr.loadFromImage((*winchik).img);
	(*winchik).copysprt.setTexture((*winchik).txtr);
	(*winchik).mainsprt.setTexture((*winchik).txtr);
	short ScreenWidth = 800;
	short ScreenHeight = 600;
	bool again = false;
	bool tomenu = true;
	bool statuswin = false;
	short caseInMenu{};
	std::wstring map{};
	sf::RenderWindow win(sf::VideoMode(ScreenWidth, ScreenHeight),
						 L"“естик’D", sf::Style::Fullscreen);
	while (true){
		std::wstring map_1{};
		map_1 += L"#$#$#$#$$$#$#$##";
		map_1 += L"#.......#.....##";
		map_1 += L"$.......$......$";
		map_1 += L"#..............#";
		map_1 += L"$..............$";
		map_1 += L"#.......#......#";
		map_1 += L"$$.....$$......$";
		map_1 += L"#$#$#$#$##.1...#";
		map_1 += L"#....4.$$#$..#$$";
		map_1 += L"$......#.......#";
		map_1 += L"#......3.......$";
		map_1 += L"$..............#";
		map_1 += L"#......$....2..$";
		map_1 += L"$......#.......#";
		map_1 += L"#......$.......$";
		map_1 += L"#$#$#$#$#$#$#$#$";

		std::wstring map_2{};
		map_2 += L"$$#$#$#$#$#$#$##";
		map_2 += L"#..............$";
		map_2 += L"$..............$";
		map_2 += L"$..............#";
		map_2 += L"#..............$";
		map_2 += L"$$#$#$#..$#$#$##";
		map_2 += L"#.1............$";
		map_2 += L"#.2............$";
		map_2 += L"#..............$";
		map_2 += L"$..............#";
		map_2 += L"##$#$#$.3#$#$#$$";
		map_2 += L"$...........4..#";
		map_2 += L"#..............$";
		map_2 += L"$..............#";
		map_2 += L"#..............$";
		map_2 += L"#$#$#$#$#$#$#$#$";

		std::wstring map_3{};
		map_3 += L"$$#$#$#$#$#$#$##";
		map_3 += L"#..$...........$";
		map_3 += L"$..#...........$";
		map_3 += L"$..$...........#";
		map_3 += L"#..#...........$";
		map_3 += L"$..$...........#";
		map_3 += L"#..#$#$#$$.....$";
		map_3 += L"$.....1..#..#$##";
		map_3 += L"#........$..#.5$";
		map_3 += L"$$#$#$#..#..$..#";
		map_3 += L"#.....$..$..#..$";
		map_3 += L"$.....#2.#..$..#";
		map_3 += L"#.....$..$#$#..$";
		map_3 += L"$.....#......4.#";
		map_3 += L"#.....$$.......$";
		map_3 += L"#$#$#$$$#$#$#$##";

		short MapWidth = 16;
		short MapHeight = 16;
		float PlayerX = 3.0f;
		float PlayerY = 3.0f;
		float PlayerA = 0.0f;
		float FOV = 3.14159f / 3.0f;
		float Depth = 24.0f;
		float Speed = 4.0f;
		short counterOfAnimOfGun = 0;
		bool startCounterOfTimeShoot = false;
		short previousValueOfTimeShoot = 0;
		short checkMnstrStrike = 0;
		short counterOfHealthBar = 0;

		if (tomenu){
			caseInMenu = menu(win);// ¬ызов меню. ¬ n записываем номер карты. 
								   // ≈сли выбрать play, то автоматически 
								   // выберитс€ 1 карта, а можно в select a map
								   //  выбрать одну из трЄх карт
			if (caseInMenu == 4){
				delete winchik, wall, hell, case1, case2, case3, case4,
					   case5, case6, scope, mnstranim1, mnstranim2,
					   mnstranim3, mnstranim4, mnstranim5, mnstranim6,
					   mnstranim7, mnstranim8, mnstranim9, mnstranim10,
					   healthbar1, healthbar2, healthbar3, healthbar4,
					   dead, tryagain, gotomenu;
				return 0;
			}
			tomenu = false;
		}
		if (caseInMenu == 1){
			map = map_1;
		}
		if (caseInMenu == 2){
			map = map_2;
		}
		if (caseInMenu == 3){
			map = map_3;
			PlayerX = 1.5;
			PlayerY = 1.5;
		}
		std::chrono::system_clock::time_point tp1 = std::chrono::system_clock::now();
		std::chrono::system_clock::time_point tp2 = std::chrono::system_clock::now();
		int counteranimnstr1 = 0, counteranimnstr2 = 0, counteranimnstr3 = 0,
			counteranimnstr4 = 0, counteranimnstr5 = 0, counteranimnstr6 = 0,
			counteranimnstr7 = 0, counteranimnstr8 = 0, counteranimnstr9 = 0;
		int CounterAniMnstrx[9]{ counteranimnstr1, counteranimnstr2,
								 counteranimnstr3, counteranimnstr4,
							     counteranimnstr5, counteranimnstr6,
			                     counteranimnstr7, counteranimnstr8,
			                     counteranimnstr9 };
		short counthitstomnstr1 = 0, counthitstomnstr2 = 0, counthitstomnstr3 = 0,
			  counthitstomnstr4 = 0, counthitstomnstr5 = 0, counthitstomnstr6 = 0,
			  counthitstomnstr7 = 0, counthitstomnstr8 = 0, counthitstomnstr9 = 0;
		short countHitsToMnstrx[9]{ counthitstomnstr1, counthitstomnstr2,
									counthitstomnstr3, counthitstomnstr4,
									counthitstomnstr5, counthitstomnstr6,
									counthitstomnstr7, counthitstomnstr8,
									counthitstomnstr9 };
		short ostatok1 = 5, ostatok2 = 5, ostatok3 = 5, ostatok4 = 5, ostatok5 = 5,
			  ostatok6 = 5, ostatok7 = 5, ostatok8 = 5, ostatok9 = 5;
		short maxIndexSpraitMnstr[9]{ ostatok1, ostatok2, ostatok3,
									  ostatok4, ostatok5, ostatok6,
									  ostatok7, ostatok8, ostatok9 };
		float XboundarysOfObj[2]{ 1000000000,1000000000 };
		float counterOfHeaven = 0.0f;
		win.setMouseCursorVisible(false);
		while (win.isOpen()){
			sf::Event event;
			while (win.pollEvent(event)){
				if (event.type == sf::Event::Closed ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
					delete winchik, wall, hell, case1, case2, case3, case4,
						   case5, case6, scope, mnstranim1, mnstranim2, mnstranim3,
						   mnstranim4, mnstranim5, mnstranim6, mnstranim7, mnstranim8,
						   mnstranim9, mnstranim10, healthbar1, healthbar2, healthbar3,
						   healthbar4, dead, tryagain, gotomenu;
					win.close();
					return 0;
				}
			}
			// Ќам понадобитс€ разница во времени дл€ каждого кадра,
			// чтобы рассчитать изменение
			// к скорост€м перемещени€, чтобы обеспечить равномерное
			// перемещение, как при трассировке лучей.
			// €вл€етс€ недетерминированным
			tp2 = std::chrono::system_clock::now();
			std::chrono::duration<float> elapsedTime = tp2 - tp1;
			tp1 = tp2;
			float fElapsedTime = elapsedTime.count(); // количество кадров
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
				counterOfAnimOfGun == 0 && !startCounterOfTimeShoot){
				startCounterOfTimeShoot = true;
			}
			int differenceXmouse = sf::Mouse::getPosition(win).x - (int)win.getSize().x / 2;
			sf::Mouse::setPosition({ (int)win.getSize().x / 2, (int)win.getSize().y / 2 }, win);
			PlayerA += (Speed) * (float)differenceXmouse * 0.001f;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
				PlayerX += sinf(PlayerA) * Speed * fElapsedTime;
				PlayerY += cosf(PlayerA) * Speed * fElapsedTime;
				if (map[(int)ceil(PlayerX) * MapWidth + (int)ceil(PlayerY)] != L'.'){
					PlayerX -= sinf(PlayerA) * Speed * fElapsedTime;
					PlayerY -= cosf(PlayerA) * Speed * fElapsedTime;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				PlayerX -= cosf(PlayerA) * Speed * fElapsedTime;
				PlayerY += sinf(PlayerA) * Speed * fElapsedTime;
				if (map[(int)ceil(PlayerX) * MapWidth + (int)ceil(PlayerY)] != L'.'){
					PlayerX += cosf(PlayerA) * Speed * fElapsedTime;
					PlayerY -= sinf(PlayerA) * Speed * fElapsedTime;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
				PlayerX -= sinf(PlayerA) * Speed * fElapsedTime;
				PlayerY -= cosf(PlayerA) * Speed * fElapsedTime;
				if (map[(int)ceil(PlayerX) * MapWidth + (int)ceil(PlayerY)] != L'.'){
					PlayerX += sinf(PlayerA) * Speed * fElapsedTime;
					PlayerY += cosf(PlayerA) * Speed * fElapsedTime;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				PlayerX += cosf(PlayerA) * Speed * fElapsedTime;
				PlayerY -= sinf(PlayerA) * Speed * fElapsedTime;
				if (map[(int)ceil(PlayerX) * MapWidth + (int)ceil(PlayerY)] != L'.'){
					PlayerX -= cosf(PlayerA) * Speed * fElapsedTime;
					PlayerY += sinf(PlayerA) * Speed * fElapsedTime;
				}
			}
			bool ConditionWriteBeginningObj = false;
			float xPositionCuttingFromSpriteWall = 0.0f;
			float xPositionColumnForDraw = 0.0f;
			win.clear(sf::Color(15, 15, 15));
			float lenOfBoundariesOfWall = 0;
			bool DrawingWall = false; // определена ли координаты ширины стены
			bool conditionForOnceWritePreviousSymbol = false;
			float distOfPreviousSymbol = 0.0f;
			std::wstring previousSymbol = L"";
			float distsAndColumnOfPixels[8]{ 1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 1.0f, 1.0f, 1.0f };
			short fourNearestWalls[4]{ 0, 1, 2, 3 };
			counterOfHeaven += 2.0f;
			for (short x = 0; x < ScreenWidth; x += 4){
				// Ќачало взаимствованного кода
				// ƒл€ каждого столбца рассчитайте угол проекции луча в мировое пространство
				float RayAngle = (PlayerA - FOV / 2.0f) + ((float)x / (float)ScreenWidth) * FOV;
				float StepSize = 0.05f;
				float DistanceToWall = 0.0f;
				bool HitWall = false;
				bool Boundary = false;
				float EyeX = sinf(RayAngle); // ≈диничный вектор дл€ луча в пространстве игрока
				float EyeY = cosf(RayAngle);
				int TestX = 0;
				int TestY = 0;
				int CornerX = 0;
				int CornerY = 0;
				Distance("Wall", HitWall, DistanceToWall, StepSize, TestX, TestY, PlayerX,
						 PlayerY, EyeX, EyeY, MapWidth, MapHeight, map);
				// –ассчитайте рассто€ние до потолка и пола
				float Ceiling = (float)ScreenHeight / 2.0f - (float)ScreenHeight / DistanceToWall;
				float Floor = ScreenHeight - Ceiling;
				//  онец взаимствованного кода
				f_3(x, counterOfHeaven);
				(*hell).copysprt = (*hell).mainsprt;
				(*hell).copysprt.setPosition(x, 0);
				(*hell).copysprt.setTextureRect(sf::IntRect(x + counterOfHeaven,
															0.0f, 4.0f, 300.0f));
				(*hell).copysprt.setScale(1, 1);
				win.draw((*hell).copysprt);
				if (map[TestX * MapWidth + TestY] == L'#' || map[TestX * MapWidth + TestY] == L'$'){
					if (!DrawingWall){
						if (DistanceToWall != distsAndColumnOfPixels[3]){
							distsAndColumnOfPixels[0] = distsAndColumnOfPixels[1];
							fourNearestWalls[0] = fourNearestWalls[1];
							distsAndColumnOfPixels[1] = distsAndColumnOfPixels[2];
							fourNearestWalls[1] = fourNearestWalls[2];
							distsAndColumnOfPixels[2] = distsAndColumnOfPixels[3];
							fourNearestWalls[2] = fourNearestWalls[3];
							distsAndColumnOfPixels[3] = DistanceToWall;
							fourNearestWalls[3] = TestX * MapWidth + TestY;
							distsAndColumnOfPixels[4] = distsAndColumnOfPixels[5];
							distsAndColumnOfPixels[5] = distsAndColumnOfPixels[6];
							distsAndColumnOfPixels[6] = distsAndColumnOfPixels[7];
							distsAndColumnOfPixels[7] = x;
						}
						if (!ConditionWriteBeginningObj){
							f_1(x, XboundarysOfObj, ConditionWriteBeginningObj);
						}
						else
						{
							if (XboundarysOfObj[1] == 1000000000 && XboundarysOfObj[0] != 1000000000){
								if (x > ScreenWidth - 9){ // этот if дл€ последней стены
									XboundarysOfObj[1] = x;
									reset(XboundarysOfObj, DrawingWall, xPositionColumnForDraw,
										  xPositionCuttingFromSpriteWall, ConditionWriteBeginningObj,
										  conditionForOnceWritePreviousSymbol, distOfPreviousSymbol,
										  lenOfBoundariesOfWall, x, ScreenWidth);
									continue;
								}
								else{
									if ((distsAndColumnOfPixels[1] - distsAndColumnOfPixels[0] > 0 && 
										 distsAndColumnOfPixels[1] - distsAndColumnOfPixels[2] > 0 &&
										 fourNearestWalls[0] == fourNearestWalls[1] &&
										 fourNearestWalls[1] != fourNearestWalls[3] &&
										 distsAndColumnOfPixels[0] != 1.0f)){
										XboundarysOfObj[1] = distsAndColumnOfPixels[7] - 
															(distsAndColumnOfPixels[7] - 
															 distsAndColumnOfPixels[6]) / 2.0f;
										reset(XboundarysOfObj, DrawingWall, xPositionColumnForDraw,
											  xPositionCuttingFromSpriteWall, ConditionWriteBeginningObj,
											  conditionForOnceWritePreviousSymbol, distOfPreviousSymbol,
											  lenOfBoundariesOfWall, x, ScreenWidth);
										continue;
									}
									if (distsAndColumnOfPixels[0] - distsAndColumnOfPixels[1] > 0 &&
										distsAndColumnOfPixels[2] - distsAndColumnOfPixels[1] > 0 && 
										distsAndColumnOfPixels[3] - distsAndColumnOfPixels[2] > 0 && 
										fourNearestWalls[0] == fourNearestWalls[1] && 
										fourNearestWalls[1] == fourNearestWalls[3] && 
										distsAndColumnOfPixels[0] != 1.0f){

										if ((distsAndColumnOfPixels[5] - distsAndColumnOfPixels[4]) / 
											(distsAndColumnOfPixels[7] - distsAndColumnOfPixels[6]) > 2.0f){
											XboundarysOfObj[1] = distsAndColumnOfPixels[6];
										}
										else{
											if ((distsAndColumnOfPixels[7] - distsAndColumnOfPixels[6]) / 
												(distsAndColumnOfPixels[5] - distsAndColumnOfPixels[4]) > 2.0f){
												XboundarysOfObj[1] = distsAndColumnOfPixels[5];
											}
											else{
												XboundarysOfObj[1] = distsAndColumnOfPixels[6] - 
																	(distsAndColumnOfPixels[6] - 
																	 distsAndColumnOfPixels[5]) / 2.0f;
											}
										}
										reset(XboundarysOfObj, DrawingWall, xPositionColumnForDraw,
											  xPositionCuttingFromSpriteWall, ConditionWriteBeginningObj,
											  conditionForOnceWritePreviousSymbol, distOfPreviousSymbol,
											  lenOfBoundariesOfWall, x, ScreenWidth);
										continue;
									}
									if (conditionForOnceWritePreviousSymbol == false){
										previousSymbol[0] = map[TestX * MapWidth + TestY];
										conditionForOnceWritePreviousSymbol = true;
										distOfPreviousSymbol = DistanceToWall;
										continue;
									}
									if (previousSymbol[0] != map[TestX * MapWidth + TestY] ||
										abs(DistanceToWall - distOfPreviousSymbol) > 2){
										XboundarysOfObj[1] = x - 4;
										reset(XboundarysOfObj, DrawingWall, xPositionColumnForDraw,
											  xPositionCuttingFromSpriteWall, ConditionWriteBeginningObj,
											  conditionForOnceWritePreviousSymbol, distOfPreviousSymbol,
											  lenOfBoundariesOfWall, x, ScreenWidth);
										continue;
									}
									distOfPreviousSymbol = DistanceToWall;
								}
							}
						}
					}
					if (DrawingWall){
						(*wall).copysprt = (*wall).mainsprt;
						(*wall).copysprt.setPosition(xPositionColumnForDraw, Ceiling);
						(*wall).copysprt.setTextureRect(sf::IntRect(xPositionCuttingFromSpriteWall,
														0.0f, 4.0f, 128.0f));
						short color{ 250 };
						for (float n{}; n < 14.5; n += 0.5){
							if ((n + 0.5) >= DistanceToWall && DistanceToWall > n){
								(*wall).copysprt.setColor(sf::Color(color, color, color));
							}
							color -= 7;
						}
						if (DistanceToWall > 14.5){
							(*wall).copysprt.setColor(sf::Color(color, color, color));
						}
						(*wall).copysprt.setScale(((float)(lenOfBoundariesOfWall)) / 128.0f,
												  (Floor - Ceiling) / 128.0f);
						win.draw((*wall).copysprt); //вывожу полоску
						xPositionColumnForDraw += 4 * ((float)(lenOfBoundariesOfWall)) / 128.0f;
						xPositionCuttingFromSpriteWall += 4;
						x = (int)ceil(xPositionColumnForDraw);
						if (xPositionCuttingFromSpriteWall == 128){
							x -= 4;
							XboundarysOfObj[0] = 1000000000;
							XboundarysOfObj[1] = 1000000000;
							DrawingWall = false;
							distsAndColumnOfPixels[0] = 1.0f;
							distsAndColumnOfPixels[1] = 2.0f;
							distsAndColumnOfPixels[2] = 3.0f;
							distsAndColumnOfPixels[3] = 4.0f;
							distsAndColumnOfPixels[4] = 1.0f;
							distsAndColumnOfPixels[5] = 1.0f;
							distsAndColumnOfPixels[6] = 1.0f;
							distsAndColumnOfPixels[7] = 1.0f;
							fourNearestWalls[0] = 0;
							fourNearestWalls[1] = 1;
							fourNearestWalls[2] = 2;
							fourNearestWalls[3] = 3;
							conditionForOnceWritePreviousSymbol = false;
							XboundarysOfObj[0] = x;
							xPositionCuttingFromSpriteWall = 0;
						}
					}
				}
			}
			bool DrawingMonster = false; // определенs ли координаты монстра
			float boundarys[2]{ 1000000000,1000000000 };
			float xPositionCuttingFromSpriteMonster = 0.0f;
			// Ќаходим рассто€ние до монстра
			for (short x = 0; x < ScreenWidth; x += 8){
				// Ќачало взаимствованного кода
				float RayAngle = (PlayerA - FOV / 2.0f) +
					             ((float)x / (float)ScreenWidth) * FOV;
				float StepSize = 0.05f;
				float DistanceToMonster = 0.0f;
				bool HitMonster = false;
				int TestX = 0;
				int TestY = 0;
				float EyeX = sinf(RayAngle); // ≈диничный вектор дл€
				float EyeY = cosf(RayAngle); // луча в пространстве игрока
				Distance("Monster", HitMonster, DistanceToMonster, StepSize,
					     TestX, TestY, PlayerX, PlayerY, EyeX, EyeY, MapWidth,
					     MapHeight, map);
				float Ceiling = (float)ScreenHeight / 2.0f -
					            (float)ScreenHeight / DistanceToMonster;
				float Floor = ScreenHeight - Ceiling;
				//  онец взаимствованного кода
				if (map[TestX * MapWidth + TestY] != L'.'){
					if (!DrawingMonster){
						if (!ConditionWriteBeginningObj){
							if (x > 0 && map[TestX * MapWidth + TestY] != L'#' &&
								map[TestX * MapWidth + TestY] != L'$'){
								boundarys[0] = x;
								ConditionWriteBeginningObj = true;
							}
						}
						else{
							if (conditionForOnceWritePreviousSymbol == false){
								previousSymbol[0] = map[TestX * MapWidth + TestY];
								conditionForOnceWritePreviousSymbol = true;
								continue;
							}
							if (previousSymbol[0] != L'$' && previousSymbol[0] != L'#' &&
								(previousSymbol[0] != map[TestX * MapWidth + TestY] || x > 790)){
								std::wstring str(previousSymbol);
								CounterAniMnstrx[std::stoi(str) - 1]++;
								boundarys[1] = x - 8;
								x = boundarys[0] - 8;
								DrawingMonster = true;
								ConditionWriteBeginningObj = false;
								xPositionCuttingFromSpriteMonster = 0;
								conditionForOnceWritePreviousSymbol = false;
								xPositionColumnForDraw = (float)boundarys[0];
								lenOfBoundariesOfWall = boundarys[1] - boundarys[0];
								continue;
							}
						}
					}
					if (DrawingMonster){
						std::wstring str_a(previousSymbol);
						short numberOfMonster = std::stoi(str_a) - 1;
						if (counterOfAnimOfGun == 2 && boundarys[0] < 400 && boundarys[1] > 400){
							countHitsToMnstrx[numberOfMonster]++;
						}
						if (countHitsToMnstrx[numberOfMonster] == 200){
							maxIndexSpraitMnstr[numberOfMonster] = 10;
						}
						if ((CounterAniMnstrx[numberOfMonster] / 5) % 
							maxIndexSpraitMnstr[numberOfMonster] == 9){
							if (map[TestX * MapWidth + TestY] == L'4'){
								statuswin = true;
							}
							map[TestX * MapWidth + TestY] = L'.';
							maxIndexSpraitMnstr[numberOfMonster] = 5;
							x = boundarys[1] - 8;
							gunCases[counterOfAnimOfGun].copysprt.setColor(sf::Color(255, 255, 255));
							CounterAniMnstrx[numberOfMonster] = 0;
							continue;
						}
						mnstrAnimx[(CounterAniMnstrx[numberOfMonster] / 5) %
							       maxIndexSpraitMnstr[numberOfMonster]].copysprt = 
						mnstrAnimx[(CounterAniMnstrx[numberOfMonster] / 5) %
							       maxIndexSpraitMnstr[numberOfMonster]].mainsprt;
						if ((CounterAniMnstrx[numberOfMonster] / 5) %
							maxIndexSpraitMnstr[numberOfMonster] == 4 &&
							maxIndexSpraitMnstr[numberOfMonster] != 10 &&
							sf::Keyboard::isKeyPressed(sf::Keyboard::A) ==
							sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
							if (checkMnstrStrike == 0){
								counterOfHealthBar++;
							}
							gunCases[counterOfAnimOfGun].copysprt.setColor(sf::Color(255, 100, 100));
							checkMnstrStrike++;
						}
						else{
							checkMnstrStrike = 0;
							gunCases[counterOfAnimOfGun].copysprt.setColor(sf::Color(255, 255, 255));
						}
						mnstrAnimx[(CounterAniMnstrx[numberOfMonster] / 5) %
								   maxIndexSpraitMnstr[numberOfMonster]].
						copysprt.setPosition(xPositionColumnForDraw, Ceiling);
						mnstrAnimx[(CounterAniMnstrx[numberOfMonster] / 5) % 
							       maxIndexSpraitMnstr[numberOfMonster]].
						copysprt.setTextureRect(sf::IntRect(xPositionCuttingFromSpriteMonster,
														    0.0f, 8.0f, 128.0f));
						mnstrAnimx[(CounterAniMnstrx[numberOfMonster] / 5) %
								   maxIndexSpraitMnstr[numberOfMonster]].
						copysprt.setScale(((float)(lenOfBoundariesOfWall)) / 128.0f,
										  (Floor - Ceiling) / 128.0f); // увеличиваем столбик
						win.draw(mnstrAnimx[(CounterAniMnstrx[numberOfMonster] / 5) %
							                maxIndexSpraitMnstr[numberOfMonster]].copysprt);
						xPositionColumnForDraw += 8 * ((float)(lenOfBoundariesOfWall)) / 128.0f;
						xPositionCuttingFromSpriteMonster += 8;
						x = (int)ceil(xPositionColumnForDraw);
						f_4(xPositionCuttingFromSpriteMonster, boundarys, DrawingMonster,
							conditionForOnceWritePreviousSymbol, ConditionWriteBeginningObj,
							previousSymbol);
					}
				}
			}
			if (startCounterOfTimeShoot && (int)(clock() / 50.0f) > previousValueOfTimeShoot){
				previousValueOfTimeShoot = (int)(clock() / 50.0f);
				counterOfAnimOfGun++;
			}
			f_2(counterOfAnimOfGun, startCounterOfTimeShoot);
			gunCases[counterOfAnimOfGun].copysprt.setScale(2, 2);
			gunCases[counterOfAnimOfGun].copysprt.setPosition(400, ScreenHeight - 220 + 
															       sin(PlayerX) * 3 + 
																   cos(PlayerY) * 3);
			win.draw(gunCases[counterOfAnimOfGun].copysprt);
			(*scope).copysprt.setPosition(392, 292);
			win.draw((*scope).copysprt);
			if (statuswin){
				win.setMouseCursorVisible(true);
				(*winchik).copysprt.setPosition(340, 195);
				forDeadMenu[1].copysprt.setPosition(300, 265);
				forDeadMenu[2].copysprt.setPosition(260, 500);
				while (true){	
					if (sf::IntRect(300, 275, 210, 80).contains(sf::Mouse::getPosition(win))){
						forDeadMenu[1].copysprt.setColor(sf::Color::Blue);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
							again = true;
							break;
						}
					}
					else{
						forDeadMenu[1].copysprt.setColor(sf::Color::White);
					}
					if (sf::IntRect(260, 510, 300, 80).contains(sf::Mouse::getPosition(win))){
						forDeadMenu[2].copysprt.setColor(sf::Color::Blue);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
							tomenu = true;
							break;
						}
					}
					else{
						forDeadMenu[2].copysprt.setColor(sf::Color::White);
					}
					win.draw((*winchik).copysprt);
					win.draw(forDeadMenu[1].copysprt);
					win.draw(forDeadMenu[2].copysprt);
					win.display();
					win.clear();
				}
				if (gamecase_reset(again, tomenu)){
					break;
				}
			}
			if (counterOfHealthBar == 4){
				win.setMouseCursorVisible(true);
				forDeadMenu[0].copysprt.setPosition(280, 195);
				forDeadMenu[1].copysprt.setPosition(300, 265);
				forDeadMenu[2].copysprt.setPosition(260, 500);
				while (true){
					if (sf::IntRect(300, 275, 210, 80).contains(sf::Mouse::getPosition(win))){
						forDeadMenu[1].copysprt.setColor(sf::Color::Blue);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
							again = true;
							break;
						}
					}
					else{
						forDeadMenu[1].copysprt.setColor(sf::Color::White);
					}
					if (sf::IntRect(260, 510, 300, 80).contains(sf::Mouse::getPosition(win))){
						forDeadMenu[2].copysprt.setColor(sf::Color::Blue);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
							tomenu = true;
							break;
						}
					}
					else
					{
						forDeadMenu[2].copysprt.setColor(sf::Color::White);
					}

					win.draw(forDeadMenu[0].copysprt);
					win.draw(forDeadMenu[1].copysprt);
					win.draw(forDeadMenu[2].copysprt);
					win.display();
					win.clear();
				}
				if (gamecase_reset(again, tomenu))
				{
					break;
				}
			}
			healthBar[counterOfHealthBar].copysprt.setScale(0.3, 0.3);
			healthBar[counterOfHealthBar].copysprt.setPosition(0, 550);
			win.draw(healthBar[counterOfHealthBar].copysprt);
			win.display();
			win.clear();
		}
	}
	return 0;
}