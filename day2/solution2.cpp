#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <climits>
#include <regex>
#include <unordered_map>
#include <filesystem>
#include "utils.h"

using namespace std;

int getPower(const std::string& gameString)
{
            //Game 1: 4 green, 3 blue, 11 red; 7 red, 5 green, 10 blue; 3 green, 8 blue, 8 red; 4 red, 12 blue; 15 red, 3 green, 10 blue
        int max_red = 1;
        int max_blue = 1;
        int max_green = 1;

        std::vector<std::string> tokens = Utils::split(gameString, ":");

        if(tokens.size() < 2)
        {
            return 0;
        }

        std::vector<std::string> gameDraws = Utils::split(tokens[1], ";");

        for(const auto& draw : gameDraws)
        {
            std::vector<std::string> colours = Utils::split(draw, ",");

            for(const auto& colour : colours)
            {
                std::pair<std::string, int>colourEntry = parseGameEntry(colour);

                std::string myColour = colourEntry.first;
                int count = colourEntry.second;

                if(myColour == "blue")
                {
                    max_blue = std::max(max_blue, count);
                }
                else if(myColour == "green")
                {
                    max_green = std::max(max_green, count);
                }
                else if(myColour == "red")
                {
                    max_red = std::max(max_red, count);
                }
            }
        }
        return max_red * max_green * max_blue;
}

    std::pair<std::string, int> parseGameEntry(const std::string& entry)
    {
        // " 4 green" first character after is a space;
        std::vector<std::string> elements = Utils::split(entry, " ");
        return std::make_pair(elements[2], std::stoi(elements[1]));
    }

int main()
{
    std::ifstream infile("input.txt");
    std::vector<int> values;
    std::string str;

   while(getline(infile, str))
   {
        values.push_back(game.getPower(str));
   }

   total = std::accumulate(values.begin(), values.end(),0);
   std::cout << "Number of values: " << values.size() << " total: " << total << std::endl;

    return 0;

}
