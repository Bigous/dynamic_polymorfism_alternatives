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

				using Shape = std::variant< Circle, Square >;

				struct Helper {
					unsigned long long drawed = 0ULL;
					std::string_view   name{ "Variant Visitor" };

					using Shapes = std::vector< Shape >;

					class Draw
					{
					public:
						void operator()( Circle const &c ) const { ++helper.drawed; }
						void operator()( Square const &c ) const { ++helper.drawed; }
					};

					void draw_all( Shapes const &shapes )
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
				} helper;
			} // namespace variant_visitor
		}   // namespace polymorfism
	}     // namespace bigous
}