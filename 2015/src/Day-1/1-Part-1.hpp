#pragma once

#include "Day.hpp"

#include <filesystem>

namespace AOC
{
	
	class DayOnePartOne : public Day
	{
	public:
		DayOnePartOne() = default;
		virtual ~DayOnePartOne() = default;

		void OnAttach() override;
		void OnDetach() override;

		void Run() override;

	private:
		std::string GetDataFromFile(const std::filesystem::path& path);
		void UpdateFloors(const std::string& input);

	private:
		int32_t m_Floor = 0;
	};

}