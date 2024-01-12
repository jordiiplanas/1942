#pragma once
#include "Wave.h"
#include <sstream>
#include <fstream>
#include <iostream>


#include "../dependencies/RapidXML/rapidxml.hpp"
#include "../dependencies/RapidXML/rapidxml_utils.hpp"
#include "../dependencies/RapidXML/rapidxml_iterators.hpp"
#include "../dependencies/RapidXML/rapidxml_print.hpp"

class IWaveManager
{
protected:
	std::vector<Wave> GetWavesFromFile(std::string filePath);
};