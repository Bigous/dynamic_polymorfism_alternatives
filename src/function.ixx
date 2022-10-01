module;

#include <functional>
#include <memory>
#include <string_view>
#include <vector>

export module Bigous.Polymorfism.Function;

export
{
	namespace bigous
	{
		namespace polymorfism
		{
			namespace function
			{
				class Circle;
				class Square;

				using DrawCircleStrategy = std::function< void( Circle const & ) >;
				using DrawSquareStrategy = std::function< void( Square const & ) >;

				struct Draw {
					template < typename T > void operator()( T const &drawable ) const { draw( drawable ); }
				};

				class Shape
				{
				public:
					Shape()                   = default;
					virtual ~Shape()          = default;
					virtual void draw() const = 0;
				};

				class Circle : public Shape
				{
					double             radius;
					DrawCircleStrategy drawing;

				public:
					explicit Circle( double rad, DrawCircleStrategy ds = Draw{} ) : radius( rad ), drawing( std::move( ds ) ) {}
					virtual ~Circle() = default;
					double getRadius() const noexcept { return radius; }
					void   draw() const override { drawing( *this ); }
				};

				class Square : public Shape
				{
					double             side;
					DrawSquareStrategy drawing;

				public:
					explicit Square( double s, DrawSquareStrategy ds = Draw{} ) : side( s ), drawing( std::move( ds ) ) {}
					virtual ~Square() = default;
					double getSide() const noexcept { return side; }
					void   draw() const override { drawing( *this ); }
				};

				struct Helper {
					unsigned long long drawed = 0ULL;
					std::string_view   name{ "Function" };
					using Shapes = std::vector< std::unique_ptr< Shape > >;
					void draw_all( Shapes const &shapes )
					{
						for( auto const &s: shapes ) {
							s->draw();
						}
					}

					auto create_shapes( int size )
					{
						Shapes shapes;
						for( int i = 0; i < size / 2; ++i ) {
							shapes.push_back( std::make_unique< Circle >( 2.0 + i ) );
							shapes.push_back( std::make_unique< Square >( 1.5 + i ) );
						}
						return shapes;
					}
				} helper;

				void draw( Circle const & ) { ++helper.drawed; }
				void draw( Square const & ) { ++helper.drawed; }
			} // namespace function
		}   // namespace polymorfism
	}     // namespace bigous
}