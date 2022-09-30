module;

#include <memory>
#include <string_view>
#include <variant>
#include <vector>

export module Bigous.Polymorfism.VariantVisitor;

export
{
	namespace bigous
	{
		namespace polymorfism
		{
			namespace variant_visitor
			{
				auto             drawed = 0ULL;
				std::string_view name{ "Variant Vector" };

				class Circle
				{
					double radius;

				public:
					explicit Circle( double rad ) : radius( rad ) {}
					double getRadius() const noexcept { return radius; }
				};

				class Square
				{
					double side;

				public:
					explicit Square( double s ) : side( s ) {}
					double getSide() const noexcept { return side; }
				};

				class Draw
				{
				public:
					void operator()( Circle const &c ) const { ++drawed; }
					void operator()( Square const &c ) const { ++drawed; }
				};

				using Shape = std::variant< Circle, Square >;

				using Shapes = std::vector< Shape >;

				void draw( Shapes const &shapes )
				{
					Draw d;
					for( auto const &s: shapes ) {
						std::visit( d, s );
					}
				}

				auto create_shapes( int size )
				{
					Shapes shapes;
					for( int i = 0; i < size / 2; ++i ) {
						shapes.push_back( Circle{ 2.0 + i } );
						shapes.push_back( Square{ 1.5 + i } );
					}
					return shapes;
				}
			} // namespace variant_visitor
		}   // namespace polymorfism
	}     // namespace bigous
}