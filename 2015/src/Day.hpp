#pragma once

#include <string>

namespace AOC
{

	class Day
	{
	public:
		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;

		virtual void Run() = 0;

	protected:
		std::string m_DebugName = "";
	};

}