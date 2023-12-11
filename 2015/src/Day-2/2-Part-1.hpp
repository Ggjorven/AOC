#pragma once

#include "Day.hpp"

#include <vector>
#include <filesystem>

namespace AOC
{

	class DayTwoPartOne : public Day
	{
	public:
		DayTwoPartOne() = default;
		virtual ~DayTwoPartOne() = default;

		void OnAttach() override;
		void OnDetach() override;

		void Run() override;

	private:
		enum class Dimension
		{
			None = -1, Length, Width, Height
		};

		struct Dimensions
		{
		public:
			uint32_t Length = 0;
			uint32_t Width = 0;
			uint32_t Height = 0;

		public:
			Dimensions() = default;
			Dimensions(uint32_t length, uint32_t width, uint32_t height)
				: Length(length), Width(width), Height(height) {}
		};

	private:
		std::vector<Dimensions> GetDataFromFile(const std::filesystem::path& path);
		uint32_t GetSquareFeetOfPaper(const std::vector<Dimensions>& packages);
	};

}