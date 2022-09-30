module;

#include <chrono>
#include <functional>

export module Bigous.Benchmark;

export
{
	namespace bigous
	{
		namespace benchmark
		{
			auto measure( std::function< void() > func )
			{
				using hrc = std::chrono::high_resolution_clock;
				auto t1   = hrc::now();
				func();
				auto t2 = hrc::now();
				return t2 - t1;
			}

			double measure_in_seconds( std::function< void() > func )
			{
				return std::chrono::duration< double, std::milli >( measure( func ) ).count() / 1000.0;
			}
		} // namespace benchmark
	}   // namespace bigous
}