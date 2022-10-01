#include <cassert>
#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

import Bigous.Benchmark;
import Bigous.Polymorfism.Procedural;
import Bigous.Polymorfism.ObjectOriented;
import Bigous.Polymorfism.Visitor;
import Bigous.Polymorfism.VariantVisitor;
import Bigous.Polymorfism.Strategy;
import Bigous.Polymorfism.Function;
import Bigous.Polymorfism.TypeErased;

constexpr int container_size = 5'000'000;

template < typename Helper > void run_bench_for( Helper &h )
{
	using namespace bigous::benchmark;

	auto total_run = [&h]() {
		Helper::template Shapes shapes;
		auto create_time = measure_in_seconds( [&shapes, &h]() { shapes = h.create_shapes( container_size ); } );
		auto draw_time   = measure_in_seconds( [&shapes, &h]() { h.draw_all( shapes ); } );

		std::cout << h.name << " creation duration: " << create_time << " seconds." << std::endl;
		std::cout << h.name << " draw duration: " << draw_time << " seconds." << std::endl;
	};

	assert( h.drawed == 0ULL );
	auto total_time = bigous::benchmark::measure_in_seconds( total_run );
	std::cout << h.name << " total time: " << total_time << " seconds for " << h.drawed << " iterations.\n"
						<< std::endl;
	assert( h.drawed == container_size );
}

int main( int argc, char *argv[] )
{
	[[maybe_unused]] std::vector< std::string > args( argv, argv + argc );

	// Procedural
	run_bench_for(bigous::polymorfism::procedural::helper);

	// Object Oriented
	run_bench_for(bigous::polymorfism::object_oriented::helper);

	// Visitor
	run_bench_for(bigous::polymorfism::visitor::helper);

	// Variant Visitor
	run_bench_for(bigous::polymorfism::variant_visitor::helper);

	// Strategy
	run_bench_for(bigous::polymorfism::strategy::helper);

	// Function
	run_bench_for(bigous::polymorfism::function::helper);

	// Type Erased
	run_bench_for(bigous::polymorfism::type_erased::helper);

	return 0;
}
