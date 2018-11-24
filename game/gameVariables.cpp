bool gameMapDragging,
	 pause;
float gameMapDraggingMouseX1,
	  gameMapDraggingMouseY1,
	  gameScaleDelta,
	  gameScale;
sf::Vector2f	gameMapDraggingMapInitialCoordinates,
				gameDragOffset,
				gameScaleCenter;

unsigned int gameBaseHealth,
			 money;

#include "../map/MapForPlaying.cpp"
MapForPlaying *gameMap;

#include "GraphicalEntity.cpp"
#include "effects/Splinter.cpp"
#include "effects/collapse.cpp"

#include "monsters/Monster.cpp"
#include "monsters/ModelA.cpp"
#include "monsters/ModelB.cpp"
std::list<Monster*> monsters;

#include "gameFunctions.cpp"
#include "gameInfo.cpp"

#include "towers/towersPanel.cpp"
std::list<Tower*> towers;
unsigned int towerToAddNumber;

#include "shooting.cpp"

void updateGameVariables()
{
	updateGameInfoVariables();
	updateTowersPanelPositionAndSize();
}

void dragGameObjects()
{
	for (std::list<Monster*>::iterator i = monsters.begin(); i != monsters.end(); i++)
		(*i)->updatePosition();
	for (std::list<Tower*>::iterator i = towers.begin(); i != towers.end(); i++)
		(*i)->drag();
	for (std::list<Shot*>::iterator i = shots.begin(); i != shots.end(); i++)
		(*i)->updatePosition();
	dragSplinters();
}

void makeMapCentered()
{
	gameDragOffset = gameMap->fitInRectangle(sf::Vector2f(0, 0),
											sf::Vector2f(towersPanelRelativeX, 1));
}

void setGameVariables(const char *gameMapFileName)
{
	gameMap = new MapForPlaying(gameMapFileName, sf::Color(150, 150, 64, 196),
								sf::Color(0, 0, 196, 128), sf::Color(128, 0, 196));
	gameMap->setTextures(0.9);
	makeMapCentered();
	gameScale = 1;
	gameMapDragging = false;
	pause = true;

	loadMonstersParameters();
	setTowersPanel();
	towerToAddNumber = 0;
	addingTower = NULL;

	windowSize = window.getSize();
	setGameInfoVariables();

	gameBaseHealth = 100;
	updateBaseHealthText();
	money = 350;
	updateMoneyText();

	startWaving();
}
