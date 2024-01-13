#pragma once
#include "Stage.h"
#include <sstream>
#include <fstream>
#include <iostream>


#include "../dependencies/RapidXML/rapidxml.hpp"
#include "../dependencies/RapidXML/rapidxml_utils.hpp"
#include "../dependencies/RapidXML/rapidxml_iterators.hpp"
#include "../dependencies/RapidXML/rapidxml_print.hpp"

class IWaveManager
{
private:
	std::vector<Wave> GetWavesFromFile(std::string filePath);
	WaveType GetWaveTypeFromString(std::string waveTypeString);
protected:
	Stage* GetStageFromFile(std::string filePath, Transform* transform);
	std::vector<Stage*> GetStagesFromFile(std::string filePathPart1, std::string filePathPart2, Transform* transform);
};