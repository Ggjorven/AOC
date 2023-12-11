#include "Day-1/1-Part-1.hpp"
#include "Day-1/1-Part-2.hpp"

#include "Day-2/2-Part-1.hpp"
#include "Day-2/2-Part-2.hpp"

template<typename TDay>
void RunDay()
{
	static_assert(std::is_base_of<AOC::Day, TDay>::value, "Not a valid day class type");

	AOC::Day* obj = new TDay();

	obj->OnAttach();
	obj->Run();
	obj->OnDetach();

	delete obj;
}

int main(int argc, char* argv[])
{
	RunDay<AOC::DayOnePartOne>();
	RunDay<AOC::DayOnePartTwo>();

	RunDay<AOC::DayTwoPartOne>();
	RunDay<AOC::DayTwoPartTwo>();

	return 0;
}