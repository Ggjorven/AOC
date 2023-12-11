#include "2-Part-2.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace AOC
{

	void DayTwoPartTwo::OnAttach()
	{
	}

	void DayTwoPartTwo::OnDetach()
	{
	}

	void DayTwoPartTwo::Run()
	{
		std::cout << "Day - 2, Part One: " << GetTotalRibbon(GetDataFromFile("src/Day-2/input.txt")) << std::endl;
	}

	std::vector<DayTwoPartTwo::Dimensions> DayTwoPartTwo::GetDataFromFile(const std::filesystem::path& path)
	{
		std::ifstream file(path);
		std::vector<Dimensions> result;

		Dimension currentDimenion = Dimension::Length;
		if (file.good() && file.is_open())
		{
			std::string line;
			while (std::getline(file, line))
			{
				Dimensions dimension;

				std::string tempValue = "";
				for (auto& c : line)
				{
					if (c != 'x')
					{
						tempValue = tempValue + c;
					}
					else
					{
						uint32_t value = (uint32_t)std::atoi(tempValue.c_str());
						tempValue = "";

						switch (currentDimenion)
						{
						case Dimension::Length:
							dimension.Length = value;
							currentDimenion = Dimension::Width;
							break;

						case Dimension::Width:
							dimension.Width = value;
							currentDimenion = Dimension::Height;
							break;
						}
					}
				}
				dimension.Height = (uint32_t)std::atoi(tempValue.c_str());
				currentDimenion = Dimension::Length;

				result.push_back(dimension);
			}

			file.close();
		}

		return result;
	}

	uint32_t DayTwoPartTwo::GetTotalRibbon(const std::vector<Dimensions>& packages)
	{
		// 2*l*w + 2*w*h + 2*h*l

		uint32_t feet = 0;

		for (auto& package : packages)
		{
			uint32_t ribbon = 0;

			ribbon += package.Length * package.Width * package.Height;

			uint32_t smallest = package.Length * 2 + package.Width * 2;
			if (package.Width * 2 + package.Height * 2 < smallest) smallest = package.Width * 2 + package.Height * 2;
			if (package.Height * 2 + package.Length * 2 < smallest) smallest = package.Height * 2 + package.Length * 2;

			ribbon += smallest;

			feet += ribbon;
		}

		return feet;
	}

}
