#include "2-Part-1.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

namespace AOC
{

	void DayTwoPartOne::OnAttach()
	{
	}

	void DayTwoPartOne::OnDetach()
	{
	}

	void DayTwoPartOne::Run()
	{
		std::cout << "Day - 2, Part One: " << GetSquareFeetOfPaper(GetDataFromFile("src/Day-2/input.txt")) << std::endl;
	}

	std::vector<DayTwoPartOne::Dimensions> DayTwoPartOne::GetDataFromFile(const std::filesystem::path& path)
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

	uint32_t DayTwoPartOne::GetSquareFeetOfPaper(const std::vector<Dimensions>& packages)
	{
		// 2*l*w + 2*w*h + 2*h*l

		uint32_t sqFeet = 0;

		for (auto& package : packages)
		{
			uint32_t pckSqFeet = 0;

			pckSqFeet += 2 * package.Length * package.Width;
			pckSqFeet += 2 * package.Width * package.Height;
			pckSqFeet += 2 * package.Height * package.Length;

			uint32_t smallest = package.Length * package.Width;
			if (package.Width * package.Height < smallest) smallest = package.Width * package.Height;
			if (package.Height* package.Length < smallest) smallest = package.Height * package.Length;

			pckSqFeet += smallest;

			sqFeet += pckSqFeet;
		}

		return sqFeet;
	}

}
