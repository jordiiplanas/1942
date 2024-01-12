#include "IWaveManager.h"

std::vector<Wave> IWaveManager::GetWavesFromFile(std::string filePath)
{
	rapidxml::xml_document<> doc;
	std::ifstream file("../../config/" + filePath);
	if (!file.is_open())
	{
		std::cout << "Failed to open file: " << filePath << std::endl;
		return std::vector<Wave>();
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	//rapidxml::xml_node<>* root = doc.first_node("Waves"); 
}
