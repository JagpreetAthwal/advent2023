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

class Game
{
public:

    void addColourMax(const std::string& colour, int count)
    {
        max_counts[colour] = count;
    }

    std::pair<bool,int> isPossible(const std::string& gameString)
    {
        std::vector<std::string> tokens = Utils::split(gameString, ":");

        if(tokens.size() < 2)
        {
            return std::make_pair(false,0);
        }

        std::vector<std::string> gameSets = Utils::split(tokens[1], ";");

        for(const auto& gameEntry : gameSets)
        {
            std::vector<std::string> colours = Utils::split(gameEntry, ",");

            for(const auto& colour : colours)
            {
                std::pair<std::string, int>gameEntry = parseGameEntry(colour);
                if(!isValid(gameEntry))
                {
                    return std::make_pair(false,0);
                }
            }
        }

        return std::make_pair(true,std::stoi(Utils::split(tokens[0], " ")[1]));
    }
private:

    std::unordered_map<std::string, int> max_counts;
    int blue;
    int green;
    int red;

    bool isValid(const std::pair<std::string, int>& entry)
    {
        std::string colour = entry.first;
        int count = entry.second;

        return count <= max_counts[colour];
    }

    std::pair<std::string, int> parseGameEntry(const std::string& entry)
    {
        // " 4 green" first character after is a space;
        std::vector<std::string> elements = Utils::split(entry, " ");
        return std::make_pair(elements[2], std::stoi(elements[1]));
    }
};

int main()
{
    Game game;
    game.addColourMax("red", 12);
    game.addColourMax("green", 13);
    game.addColourMax("blue",14);

    std::ifstream infile("input.txt");
    std::vector<int> values;
    std::string str;

   while(getline(infile, str))
   {
      auto result = game.isPossible(str);
      if(result.first)
      {
          values.push_back(result.second);
      }
   }

   auto total = std::accumulate(values.begin(), values.end(),0);
   std::cout << "Number of values: " << values.size() << " total: " << total << std::endl;

    return 0;
}
