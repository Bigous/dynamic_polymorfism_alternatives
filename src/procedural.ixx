module;

#include <memory>
#include <string_view>
#include <vector>

export module Bigous.Polymorfism.Procedural;

export
{
	namespace bigous
	{
		namespace polymorfism
		{
			namespace procedural
			{
				enum ShapeType { circle, square };

				class Shape
				{
					ShapeType type;

				public:
					explicit Shape( ShapeType t ) : type{ t } {}
					virtual ~Shape() = default;
					ShapeType getType() const noexcept { return type; }
				};

				class Circle : public Shape
				{
					double radius;

				public:
					explicit Circle( double rad ) : Shape( circle ), radius( rad ) {}
					virtual ~Circle() = default;
					double getRadius() const noexcept { return radius; }
				};

				class Square : public Shape
				{
					double side;

				public:
					explicit Square( double s ) : Shape( square ), side( s ) {}
					virtual ~Square() = default;
					double getSide() const noexcept { return side; }
				};

				void draw( Circle const & );
				void draw( Square const & );

				struct Helper {
					unsigned long long drawed = 0ULL;
					std::string_view   name{ "Procedural" };

          using Shapes = std::vector< std::unique_ptr< Shape > >;

					void draw_all( Shapes const &shapes )
					{
						for( auto const &s: shapes ) {
							switch( s->getType() ) {
								case circle:
									draw( *static_cast< Circle const * >( s.get() ) );
									break;
								case square:
									draw( *static_cast< Square const * >( s.get() ) );
									break;
							}
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

			} // namespace procedural
		}   // namespace polymorfism
	}     // namespace bigous
}