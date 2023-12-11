#pragma once

#include "Day.hpp"

#include <filesystem>

namespace AOC
{

	class DayOnePartTwo : public Day
	{
	public:
		DayOnePartTwo() = default;
		virtual ~DayOnePartTwo() = default;

		void OnAttach() override;
		void OnDetach() override;

		void Run() override;

	private:
		std::string GetDataFromFile(const std::filesystem::path& path);
		void UpdateFloors(const std::string& input);

	private:
		int32_t m_Floor = 0;

		bool m_NotFound = true;
		int32_t m_BasementIndex = 0;
	};

}