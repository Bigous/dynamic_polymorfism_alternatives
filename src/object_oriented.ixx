module;

#include <memory>
#include <string_view>
#include <vector>

export module Bigous.Polymorfism.ObjectOriented;

export
{
	namespace bigous
	{
		namespace polymorfism
		{
			namespace object_oriented
			{
				class Shape
				{
				public:
					Shape()                   = default;
					virtual ~Shape()          = default;
					virtual void draw() const = 0;
				};

				void inc_draw();

				class Circle : public Shape
				{
					double radius;

				public:
					explicit Circle( double rad ) : radius( rad ) {}
					virtual ~Circle() = default;
					double getRadius() const noexcept { return radius; }
					void   draw() const override { inc_draw(); }
				};

				class Square : public Shape
				{
					double side;

				public:
					explicit Square( double s ) : side( s ) {}
					virtual ~Square() = default;
					double getSide() const noexcept { return side; }
					void   draw() const override { inc_draw(); }
				};

				struct Helper {
					unsigned long long drawed = 0ULL;
					std::string_view   name{ "Object Oriented" };

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

				void inc_draw() { ++helper.drawed; }

			} // namespace object_oriented
		}   // namespace polymorfism
	}     // namespace bigous
}