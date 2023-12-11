#pragma once

#include "Day.hpp"

#include <vector>
#include <filesystem>

namespace AOC
{

	class DayThreePartOne : public Day
	{
	public:
		DayThreePartOne() = default;
		virtual ~DayThreePartOne() = default;

		void OnAttach() override;
		void OnDetach() override;

		void Run() override;

	private:

	};

}