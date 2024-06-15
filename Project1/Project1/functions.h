#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#pragma once
#include <iostream>
#include <typeinfo>

/**
 * \functions.h
 *
 * This file contains functions that are used in the main file
 *
 */

 /**
  * This function calculates the distance to an object
  *
  * \param[in] subject is input subject in the format of a stringstring.
  * 		   Monster or Wall
  * \param[in] it is a variable that shows whether the ray reached the object
  *            or not in the format of a bool
  * \param[in] DistanceTo is a variable that counts the distance to an object
  *            in the format of a float
  * \param[in] StepSize is the step with which the beam increases in the
  *            format of a float
  * \param[in] TestX is a variable that shows the position of the ray
  *            relative to the X axis on the map in the format of a int
  * \param[in] TestY is a variable that shows the position of the ray 
  *            relative to the Y axis on the map in the format of a int
  * \param[in] PlayerX is a variable that shows the player's position on
  *            the map along the X axis in the format of a float
  * \param[in] PlayerY is a variable that shows the player's position
  *            on the map along the Y axis in the format of a float
  * \param[in] EyeX  in the format of a float
  * \param[in] EyeY  in the format of a float
  * \param[in] MapWidth is input map width in the format of a short
  * \param[in] MapHeight is input map height in the format of a short
  * \param[in] map is input map in the format of a wstring
  * \param[in] Depth is the visibility distance. Default 24.0
  *
  * \throw "Invalid type of subject" if (subject != "Wall" and
  *                                      subject != "Monster")
  */
void Distance(std::string subject, bool& Hit, float& DistanceTo,
			  float StepSize, int& TestX, int& TestY, float& PlayerX,
			  float& PlayerY, float& EyeX, float& EyeY, short MapWidth,
			  short MapHeight, std::wstring map, float Depth = 24.0f){
	if (subject != "Wall" && subject != "Monster"){
		throw "Invalid type of subject";
	}
	while (!Hit && DistanceTo < Depth){
		DistanceTo += StepSize;
		TestX = (int)ceil(PlayerX + EyeX * DistanceTo);
		TestY = (int)ceil(PlayerY + EyeY * DistanceTo);
		// ѕроверьте, находитс€ ли луч за пределами пол€ зрени€
		if (TestX < 0 || TestX >= MapWidth || TestY < 0 || TestY >= MapHeight){
			Hit = true;
			if (subject == "Wall"){
				DistanceTo = Depth;
			}
		}
		else{
			if (subject == "Wall"){
				// Ћуч находитс€ в пределах дос€гаемости, поэтому проверьте,
				//  €вл€етс€ ли €чейка луча блоком стены
				if (map[TestX * MapWidth + TestY] == '#' ||
					map[TestX * MapWidth + TestY] == '$'){
					// Ray has hit wall
					Hit = true;
				}
			}
			if (subject == "Monster"){
				if (map[TestX * MapWidth + TestY] != L'.'){
					// Ray has hit wall
					Hit = true;
				}
			}
		}
	}
}

/**
 * This function resets values
 *
 * \param[in] XboundarysOfOb this is an array of two numbers that show
 *            the coordinates of the object's frames in the format of a float
 * \param[in] DrawingWall shows whether the coordinates of the wall width
 *            are defined in the format of a bool
 * \param[in] xPositionColumnForDraw shows the column position we are
 *            outputting in the format of a float
 * \param[in] xPositionCuttingFromSpriteWall shows the position from
 *            which we start cropping the image in the format of a float
 * \param[in] ConditionWriteBeginningObj shows whether we have found the 
 *            coordinate of the beginning of the wall in the format of a bool
 * \param[in] conditionForOnceWritePreviousSymbol is a condition for one-time
 *            recording of a map symbol in the format of a bool
 * \param[in] distOfPreviousSymbol distance to previous symbol
 *            in the format of a float
 * \param[in] lenOfBoundariesOfWall is the width of the object
 *            in the format of a float
 * \param[in] x is the x coordinate in the format of a short
 * \param[in] ScreenWidth is the window width in the format of a int
 *
 */
void reset(float(&XBoundariesOfOb)[2], bool& DrawingWall,
		   float& xPositionColumnForDraw, float& xPositionCuttingFromSpriteWall,
		   bool& ConditionWriteBeginningObj,
		   bool& conditionForOnceWritePreviousSymbol, float& distOfPreviousSymbol,
		   float& lenOfBoundariesOfWall, short& x, int ScreenWidth){
	x = XBoundariesOfOb[0] - 4;
	DrawingWall = true;
	xPositionColumnForDraw = (float)XBoundariesOfOb[0];
	xPositionCuttingFromSpriteWall = 0;
	ConditionWriteBeginningObj = false;
	conditionForOnceWritePreviousSymbol = false;
	distOfPreviousSymbol = 0.0f;
	lenOfBoundariesOfWall = XBoundariesOfOb[1] - XBoundariesOfOb[0];
	XBoundariesOfOb[0] = 1000000000;
	XBoundariesOfOb[1] = 1000000000;
}

/**
 * This function checks where we clicked after the game
 *
 * \param[in] again is checking that we pressed play again
 *            in the format of a bool
 * \param[in] tomenu is checking that we pressed exit
 *            to the menu in the format of a bool
 *
 * \throw "you cannot press two buttons at once" if we
 *        pressed two buttons at the same time
 * \return true if we pressed one of the two buttons after the game
 */
bool gamecase_reset(bool &again, bool &tomenu){
	if (again && tomenu){
		throw "You cannot press two buttons at once";
	}
	if (again){
		again = false;
		return true;
	}
	if (tomenu){
		return true;
	}
	return false;
}

/**
 * This function to determine the coordinate of the beginning of the wall
 *
 * \param[in] x is the x coordinate in the format of a short
 * \param[in] XboundarysOfOb this is an array of two numbers that show
 *            the coordinates of the object's frames in the format of a float
 * \param[in] ConditionWriteBeginningObj shows whether we have found the 
 *            coordinate of the beginning of the wall in the format of a bool
 *
 * \throw "Value is negative" if 0>x
 */
void f_1(short x, float(&XboundariesOfObj)[2],
		 bool& ConditionWriteBeginningObj){
	if (x >= 0){
		XboundariesOfObj[0] = x - 4;
		ConditionWriteBeginningObj = true;
	}
	else{
		throw "Value is negative";
	}
}

/**
 * This function to reset animation for shooting
 *
 * \param[in] counterOfAnimOfGun is the weapon animation counter
 *            in the format of a short
 * \param[in] startCounterOfTimeShoot is the shooting test int
 *            the format of a bool
 *
 * \throw "Value of counter shoudent be bigger than six"
 *        if counterOfAnimOfGun >= 7
 */
void f_2(short& counterOfAnimOfGun, bool& startCounterOfTimeShoot){
	if (counterOfAnimOfGun >= 7){
		throw "Value of counter shoudent be bigger than six";
	}
	if (counterOfAnimOfGun > 5){
		startCounterOfTimeShoot = false;
		counterOfAnimOfGun = 0;
	}
}

/**
 * This function resets the sky animation counter
 *
 * \param[in] x is the x coordinate in the format of a short
 * \param[in] counterOfHeaven is the sky animation
 *            counter in the format of a float
 *
 * \throw "Out of the picture" if we went beyond the picture
 */
void f_3(short x, float& counterOfHeaven){
	if (x + counterOfHeaven > 6500){
		throw "Out of the picture";
	}
	if (x + counterOfHeaven > 6400){
		counterOfHeaven = 0;
	}
}

/**
 * This function resets variables if we have removed the entire monster
 *
 * \param[in] xPositionCuttingFromSpriteMonster shows the position
 *            from which we start cropping the image in the format of a float
 * \param[in] boundarys this is an array of two numbers that show 
 *            the coordinates of the object's frames in the format of a float
 * \param[in] DrawingMonster shows whether the coordinates of the monster
 *            width are defined in the format of a bool
 * \param[in] conditionForOnceWritePreviousSymbol is a condition for one-time
 *            recording of a map symbol in the format of a bool
 * \param[in] ConditionWriteBeginningObj shows whether we have found
 *            the coordinate of the beginning of the wall in the format of a bool
 * \param[in] previousSymbol shows what the previous card symbol was
 *            in the format of a wstring
 *
 * \throw "Beyond the picture" if we try to crop a picture outside our limits
 */
void f_4(float& xPositionCuttingFromSpriteMonster, float(&Boundaries)[2],
		 bool& DrawingMonster, bool& conditionForOnceWritePreviousSymbol,
		 bool& ConditionWriteBeginningObj, std::wstring& previousSymbol){
	if (xPositionCuttingFromSpriteMonster == 128){
		Boundaries[0] = 1000000000;
		Boundaries[1] = 1000000000;
		DrawingMonster = false;
		conditionForOnceWritePreviousSymbol = false;
		ConditionWriteBeginningObj = false;
		xPositionCuttingFromSpriteMonster = 0;
		previousSymbol = L"";
	}
	if (xPositionCuttingFromSpriteMonster < 0 ||
		xPositionCuttingFromSpriteMonster > 128){
		throw "Beyond the picture";
	}
}

#endif GAME_FUNCTIONS_H