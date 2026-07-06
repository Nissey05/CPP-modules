#pragma once

#include <map>
#include <string>

std::map <std::string, float> import_csv(std::fstream &fs);
bool printOccurances(const std::string file, const std::map<std::string, float> data);
float getRate(const std::string &date, const std::map<std::string, float> data);