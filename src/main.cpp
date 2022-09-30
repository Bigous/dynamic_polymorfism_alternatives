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

void procedural()
{
	using namespace bigous::polymorfism::procedural;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	std::cout << "Procedural creation duration: " << create_time << " seconds." << std::endl;
	std::cout << "Procedural draw duration: " << draw_time << " seconds." << std::endl;
}

void object_oriented()
{
	using namespace bigous::polymorfism::object_oriented;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	std::cout << "Object-Oriented creation duration: " << create_time << " seconds." << std::endl;
	std::cout << "Object-Oriented draw duration: " << draw_time << " seconds." << std::endl;
}

void visitor()
{
	using namespace bigous::polymorfism::visitor;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	std::cout << "Visitor creation duration: " << create_time << " seconds." << std::endl;
	std::cout << "Visitor draw duration: " << draw_time << " seconds." << std::endl;
}

void variant_visitor()
{
	using namespace bigous::polymorfism::variant_visitor;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	std::cout << "Variant Visitor creation duration: " << create_time << " seconds." << std::endl;
	std::cout << "Variant Visitor draw duration: " << draw_time << " seconds." << std::endl;
}

void strategy()
{
	using namespace bigous::polymorfism::strategy;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	std::cout << "Strategy creation duration: " << create_time << " seconds." << std::endl;
	std::cout << "Strategy draw duration: " << draw_time << " seconds." << std::endl;
}

void function()
{
	using namespace bigous::polymorfism::function;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	std::cout << "Function creation duration: " << create_time << " seconds." << std::endl;
	std::cout << "Function draw duration: " << draw_time << " seconds." << std::endl;
}

void type_erased()
{
	using namespace bigous::polymorfism::type_erased;
	using namespace bigous::benchmark;

	Shapes shapes;
	auto   create_time = measure_in_seconds( [&shapes]() { shapes = create_shapes( container_size ); } );
	auto   draw_time   = measure_in_seconds( [&shapes]() { draw( shapes ); } );

	std::cout << "Type Erased creation duration: " << create_time << " seconds." << std::endl;
	std::cout << "Type Erased draw duration: " << draw_time << " seconds." << std::endl;
}

int main( int argc, char *argv[] )
{
	[[maybe_unused]] std::vector< std::string > args( argv, argv + argc );

	// Procedural
	{
		assert( bigous::polymorfism::procedural::drawed == 0ULL );
		auto procedural_time = bigous::benchmark::measure_in_seconds( procedural );
		std::cout << "Procedural total time: " << procedural_time << " seconds for "
							<< bigous::polymorfism::procedural::drawed << " iterations.\n"
							<< std::endl;
		assert( bigous::polymorfism::procedural::drawed == container_size );
	}

	// Object Oriented
	{
		assert( bigous::polymorfism::object_oriented::drawed == 0ULL );
		auto oo_time = bigous::benchmark::measure_in_seconds( object_oriented );
		std::cout << "Object-Oriented total time: " << oo_time << " seconds for "
							<< bigous::polymorfism::object_oriented::drawed << " iterations.\n"
							<< std::endl;
		assert( bigous::polymorfism::object_oriented::drawed == container_size );
	}

	// Visitor
	{
		assert( bigous::polymorfism::visitor::drawed == 0ULL );
		auto visitor_time = bigous::benchmark::measure_in_seconds( visitor );
		std::cout << "Visitor total time: " << visitor_time << " seconds for " << bigous::polymorfism::visitor::drawed
							<< " iterations.\n"
							<< std::endl;
		assert( bigous::polymorfism::visitor::drawed == container_size );
	}

	// Variant Visitor
	{
		assert( bigous::polymorfism::variant_visitor::drawed == 0ULL );
		auto variant_visitor_time = bigous::benchmark::measure_in_seconds( variant_visitor );
		std::cout << "Variant Visitor total time: " << variant_visitor_time << " seconds for "
							<< bigous::polymorfism::variant_visitor::drawed << " iterations.\n"
							<< std::endl;
		assert( bigous::polymorfism::variant_visitor::drawed == container_size );
	}

	// Strategy
	{
		assert( bigous::polymorfism::strategy::drawed == 0ULL );
		auto strategy_time = bigous::benchmark::measure_in_seconds( strategy );
		std::cout << "Strategy total time: " << strategy_time << " seconds for "
							<< bigous::polymorfism::strategy::drawed << " iterations.\n"
							<< std::endl;
		assert( bigous::polymorfism::strategy::drawed == container_size );
	}

	// Function
	{
		assert( bigous::polymorfism::function::drawed == 0ULL );
		auto function_time = bigous::benchmark::measure_in_seconds( function );
		std::cout << "Function total time: " << function_time << " seconds for "
							<< bigous::polymorfism::function::drawed << " iterations.\n"
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
