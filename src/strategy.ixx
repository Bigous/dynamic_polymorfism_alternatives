module;

#include <memory>
#include <string_view>
#include <vector>

export module Bigous.Polymorfism.Strategy;

export
{
	namespace bigous
	{
		namespace polymorfism
		{
			namespace strategy
			{
				auto             drawed = 0ULL;
				std::string_view name{ "Strategy" };

				class Circle;
				class Square;

				class DrawCircleStrategy
				{
				public:
					virtual ~DrawCircleStrategy(){};
					virtual void draw( const Circle & ) const = 0;
				};

				class DrawSquareStrategy
				{
				public:
					virtual ~DrawSquareStrategy(){};
					virtual void draw( const Square & ) const = 0;
				};

				class Shape
				{
				public:
					Shape()                   = default;
					virtual ~Shape()          = default;
					virtual void draw() const = 0;
				};

				using Shapes = std::vector< std::unique_ptr< Shape > >;

				class Circle : public Shape
				{
					double                                radius;
					std::unique_ptr< DrawCircleStrategy > drawing;

				public:
					explicit Circle( double rad, std::unique_ptr< DrawCircleStrategy > ds )
							: radius( rad ), drawing( std::move( ds ) )
					{
					}
					virtual ~Circle() = default;
					double getRadius() const noexcept { return radius; }
					void   draw() const override { drawing->draw( *this ); }
				};

				class Square : public Shape
				{
					double                                side;
					std::unique_ptr< DrawSquareStrategy > drawing;

				public:
					explicit Square( double s, std::unique_ptr< DrawSquareStrategy > ds ) : side( s ), drawing( std::move( ds ) )
					{
					}
					virtual ~Square() = default;
					double getSide() const noexcept { return side; }
					void   draw() const override { drawing->draw( *this ); }
				};

				void draw( Shapes const &shapes )
				{
					for( auto const &s: shapes ) {
						s->draw();
					}
				}

				class OpenGLCircleStrategy : public DrawCircleStrategy
				{
				public:
					virtual ~OpenGLCircleStrategy() {}

					void draw( Circle const & ) const override { ++drawed; }
				};

				class OpenGLSquareStrategy : public DrawSquareStrategy
				{
				public:
					virtual ~OpenGLSquareStrategy() {}

					void draw( Square const & ) const override { ++drawed; }
				};

				auto create_shapes( int size )
				{
					Shapes shapes;
					for( int i = 0; i < size / 2; ++i ) {
						shapes.push_back( std::make_unique< Circle >( 2.0 + i, std::make_unique< OpenGLCircleStrategy >() ) );
						shapes.push_back( std::make_unique< Square >( 1.5 + i, std::make_unique< OpenGLSquareStrategy >() ) );
					}
					return shapes;
				}
			} // namespace strategy
		}   // namespace polymorfism
	}     // namespace bigous
}