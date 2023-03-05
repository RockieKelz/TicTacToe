#pragma once

#include<iostream>
#include <string>

class Player
{
    private:
        std::string name;
        int score;
    public:
        Player() :Player{ "" } {}
        Player(std::string n) :score{ 0 }, name{ n }{}

        void won();
        int getScore();
        std::string getName();
};

