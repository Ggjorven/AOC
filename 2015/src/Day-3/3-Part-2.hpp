#pragma once

#include "Day.hpp"

#include <vector>
#include <filesystem>

namespace AOC
{

	class DayThreePartTwo : public Day
	{
	public:
		DayThreePartTwo() = default;
		virtual ~DayThreePartTwo() = default;

		void OnAttach() override;
		void OnDetach() override;

		void Run() override;

	private:

	};

}