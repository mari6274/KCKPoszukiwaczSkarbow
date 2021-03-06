#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Helper.h"
#include <iostream>

class Game;

class TaskManager {
    public:
        TaskManager(Game * game);

        void quit();
        bool move(int x, int y);
        void rotate(int angle);
        bool goCoordinates(int x, int y, bool automatic = false);
        void kop(sf::Vector2f v);

        sf::Vector2f getCoordinates();
        int getRotation();
        std::vector<Object*> getLocalObjects(int distance = 2, bool print = true);
        std::vector<Object*> getNeighbors(bool print = true);
        sf::String getError();

        sf::String readCommand(bool ogonki = false);
        void setInfo(std::string info);
    private:
        Game * game;
        sf::String error;

        bool goTo(sf::Vector2f v);
        bool goToAuto(sf::Vector2f v);
        float calcF(AStarVector2f * a, sf::Vector2f target);
        std::vector<AStarVector2f*> generatePath(AStarVector2f * a);
        bool checkCollisions(sf::Vector2f v);
        std::vector<AStarVector2f*> AStar(sf::Vector2f target);
        sf::Vector2f getRoverPosition();
        void setRoverPosition(float x, float y);
        void setRoverPosition(sf::Vector2f v);

};

#endif // TASKMANAGER_H
