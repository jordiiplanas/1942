#include "IWaveManager.h"

Stage* IWaveManager::GetStageFromFile(std::string filePath, Transform* transform)
{

	rapidxml::xml_document<> doc;

	std::string path = "config/" + filePath;

	std::ifstream file;
	file.open(path);

	if (!file.is_open())
	{
		std::cout << "Failed to open file: " << filePath << std::endl;
		return nullptr;
	}

	Stage* stage;

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();

	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<>* root = doc.first_node();
	int totalTime = 0;
	if (root->first_node()->name() == std::string("totalTime"))
	{
		totalTime = std::stoi(root->first_node()->value());
	}
	rapidxml::xml_node<>* waveNode = root->first_node()->next_sibling();
	std::vector<Wave*> waves;
	while (waveNode != nullptr)
	{
		float spawnTime = 0;
		WaveType type;
		int amount = 0;

		rapidxml::xml_node<>* value = waveNode->first_node();
		if (value->name() == std::string("spawnTime"))
		{
			spawnTime = std::stof(value->value());
		}
		value = value->next_sibling();
		rapidxml::xml_attribute<>* attr = value->first_attribute();
		std::string pattern = "";
		if (value->name() == std::string("type"))
		{
			type = GetWaveTypeFromString(value->value());
			if (type == WaveType::NORMAL)
			{
				pattern = attr->value();
				if (pattern == "V")
				{
					type = WaveType::NORMAL_V;
				}
				else if (pattern == "STRAIGHT")
				{
					type = WaveType::NORMAL;
				}
				else if (pattern == "CURVE")
				{
					type = WaveType::NORMAL_CURVE;
				}
			}
		}
		value = value->next_sibling();
		if (value->name() == std::string("amount"))
		{
			amount = std::stoi(value->value());
		}
		waves.push_back(new Wave(type, spawnTime, amount, transform));
		waveNode = waveNode->next_sibling();
	}
	stage = new Stage(totalTime);
	stage->SetWaves(waves);
	return stage;
}

std::vector<Stage*> IWaveManager::GetStagesFromFile(std::string filePathPart1, std::string filePathPart2, Transform* transform)
{
	std::vector<Stage*> stages2 = std::vector<Stage*>();
	Stage* stage;
	int i = 1;
	do
	{
		stage = GetStageFromFile(filePathPart1 + std::to_string(i++) + filePathPart2, transform);
		if (stage != nullptr)
			stages2.push_back(stage);
	} while (stage != nullptr);
	return stages2;
}

WaveType IWaveManager::GetWaveTypeFromString(std::string waveTypeString)
{
	if (waveTypeString == "normal")
	{
		return WaveType::NORMAL;
	}
	else if (waveTypeString == "smallred")
	{
		return WaveType::SMALLRED;
	}
	else if (waveTypeString == "mediumyellow")
	{
		return WaveType::MEDIUMYELLOW;
	}
	else if (waveTypeString == "biggreen")
	{
		return WaveType::BIGGREEN;
	}
	else
	{
		return WaveType::NORMAL;
	}

}
