#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Object.h"
#include <vector>

class TaskManager;

class Game
{
    friend class TaskManager;
    public:
        Game();
        void start();
        TaskManager * getTaskManager();
    protected:
    private:
        TaskManager * taskManager;

        const int WINDOWX = 800;
        const int WINDOWY = 600;

        //textures
        sf::Texture tMap;
        sf::Texture crater;
        sf::Texture tCookie;

        sf::RenderWindow window;
        sf::Sprite sMap;
        sf::RectangleShape miniMapRect;
        sf::View view;
        sf::View miniMap;

        sf::Sprite cookie;
        std::vector<Object*> craters;

        sf::Event event;
        int speed = 50;

        void loadTextures();
        void generateRandPosObjects(sf::Texture &, int, std::vector<Object*> &);
};

class TaskManager {
    public:
        TaskManager(Game * game);
        void goLeft();
        void goRight();
        void goUp();
        void goDown();
        bool goCoordinates(int x, int y);
        sf::Vector2f getCoordinates();
    private:
        Game * game;
};

#endif // GAME_H
