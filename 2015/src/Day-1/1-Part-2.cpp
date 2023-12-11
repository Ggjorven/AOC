#include "1-Part-2.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace AOC
{

	void DayOnePartTwo::OnAttach()
	{
	}

	void DayOnePartTwo::OnDetach()
	{
	}

	void DayOnePartTwo::Run()
	{
		UpdateFloors(GetDataFromFile("src/Day-1/input.txt"));

		std::cout << "Day - 1, Part Two: " << m_BasementIndex << std::endl;
	}

	std::string DayOnePartTwo::GetDataFromFile(const std::filesystem::path& path)
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

	void DayOnePartTwo::UpdateFloors(const std::string& input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			switch (input[i])
			{
			case '(':
				++m_Floor;
				break;
			case ')':
				--m_Floor;
				break;
			}

			// Entered basement
			if (m_NotFound && m_Floor == -1)
			{
				m_BasementIndex = i+1;
				m_NotFound = false;
			}
		}
	}

}
