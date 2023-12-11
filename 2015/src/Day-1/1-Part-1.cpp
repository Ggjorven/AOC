#include "1-Part-1.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace AOC
{

	void DayOnePartOne::OnAttach()
	{
	}

	void DayOnePartOne::OnDetach()
	{
	}

	void DayOnePartOne::Run()
	{
		UpdateFloors(GetDataFromFile("src/Day-1/input.txt"));

		std::cout << "Day - 1, Part One: " << m_Floor << std::endl;
	}

	std::string DayOnePartOne::GetDataFromFile(const std::filesystem::path& path)
	{
		std::ifstream file(path);
		std::stringstream ss;
		
		if (file.good() && file.is_open())
		{
			ss << file.rdbuf();
			file.close();
		}

		return ss.str();
	}

	void DayOnePartOne::UpdateFloors(const std::string& input)
	{
		for (auto& c : input)
		{
			switch (c)
			{
			case '(':
				++m_Floor;
				break;
			case ')':
				--m_Floor;
				break;
			}
		}
	}

}
