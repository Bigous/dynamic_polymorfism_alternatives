#include <cassert>
#include <chrono>
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

void display_duration(const std::string_view &name, const double &create_time, const double &draw_time) {
	std::cout << name << " creation duration: " << create_time << " seconds." << std::endl;
	std::cout << name << " draw duration: " << draw_time << " seconds." << std::endl;

}

void procedural()
{
	using namespace bigous::polymorfism::procedural;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	display_duration(name, create_time, draw_time);
}

void object_oriented()
{
	using namespace bigous::polymorfism::object_oriented;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	display_duration(name, create_time, draw_time);
}

void visitor()
{
	using namespace bigous::polymorfism::visitor;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	display_duration(name, create_time, draw_time);
}

void variant_visitor()
{
	using namespace bigous::polymorfism::variant_visitor;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	display_duration(name, create_time, draw_time);
}

void strategy()
{
	using namespace bigous::polymorfism::strategy;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	display_duration(name, create_time, draw_time);
}

void function()
{
	using namespace bigous::polymorfism::function;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	display_duration(name, create_time, draw_time);
}

void type_erased()
{
	using namespace bigous::polymorfism::type_erased;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	display_duration(name, create_time, draw_time);
}

int main( int argc, char *argv[] )
{
	[[maybe_unused]] std::vector< std::string > args( argv, argv + argc );

	// Procedural
	{
		using namespace bigous::polymorfism::procedural;
		assert( drawed == 0ULL );
		auto procedural_time = bigous::benchmark::measure_in_seconds( procedural );
		std::cout << name << " total time: " << procedural_time << " seconds for " << drawed << " iterations.\n"
							<< std::endl;
		assert( drawed == container_size );
	}

	// Object Oriented
	{
		using namespace bigous::polymorfism::object_oriented;
		assert( drawed == 0ULL );
		auto oo_time = bigous::benchmark::measure_in_seconds( object_oriented );
		std::cout << name << " total time: " << oo_time << " seconds for " << drawed << " iterations.\n" << std::endl;
		assert( drawed == container_size );
	}

	// Visitor
	{
		using namespace bigous::polymorfism::visitor;
		assert( drawed == 0ULL );
		auto visitor_time = bigous::benchmark::measure_in_seconds( visitor );
		std::cout << name << " total time: " << visitor_time << " seconds for " << drawed << " iterations.\n" << std::endl;
		assert( drawed == container_size );
	}

	// Variant Visitor
	{
		using namespace bigous::polymorfism::variant_visitor;
		assert( drawed == 0ULL );
		auto variant_visitor_time = bigous::benchmark::measure_in_seconds( variant_visitor );
		std::cout << name << " total time: " << variant_visitor_time << " seconds for " << drawed << " iterations.\n"
							<< std::endl;
		assert( drawed == container_size );
	}

	// Strategy
	{
		using namespace bigous::polymorfism::strategy;
		assert( drawed == 0ULL );
		auto strategy_time = bigous::benchmark::measure_in_seconds( strategy );
		std::cout << name << " total time: " << strategy_time << " seconds for " << drawed << " iterations.\n" << std::endl;
		assert( drawed == container_size );
	}

	// Function
	{
		assert( bigous::polymorfism::function::drawed == 0ULL );
		auto function_time = bigous::benchmark::measure_in_seconds( function );
		std::cout << "Function total time: " << function_time << " seconds for " << bigous::polymorfism::function::drawed
							<< " iterations.\n"
							<< std::endl;
		assert( bigous::polymorfism::function::drawed == container_size );
	}

	// Type Erased
	{
		assert( bigous::polymorfism::type_erased::drawed == 0ULL );
		auto type_erased_time = bigous::benchmark::measure_in_seconds( type_erased );
		std::cout << "Type Erased total time: " << type_erased_time << " seconds for "
							<< bigous::polymorfism::type_erased::drawed << " iterations.\n"
							<< std::endl;
		assert( bigous::polymorfism::type_erased::drawed == container_size );
	}

	return 0;
}
