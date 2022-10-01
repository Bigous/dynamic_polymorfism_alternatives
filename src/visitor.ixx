module;

#include <memory>
#include <string_view>
#include <vector>

export module Bigous.Polymorfism.Visitor;

export
{
	namespace bigous
	{
		namespace polymorfism
		{
			namespace visitor
			{
				class Circle;
				class Square;

				class Visitor
				{
				public:
					virtual ~Visitor()                         = default;
					virtual void visit( Circle const & ) const = 0;
					virtual void visit( Square const & ) const = 0;
				};

				class Shape
				{
				public:
					Shape()                                = default;
					virtual ~Shape()                       = default;
					virtual void accept( Visitor const & ) = 0;
				};

				class Circle : public Shape
				{
					double radius;

				public:
					explicit Circle( double rad ) : radius( rad ) {}
					virtual ~Circle() = default;
					double getRadius() const noexcept { return radius; }
					void   accept( Visitor const &v ) override { v.visit( *this ); }
				};

				class Square : public Shape
				{
					double side;

				public:
					explicit Square( double s ) : side( s ) {}
					virtual ~Square() = default;
					double getSide() const noexcept { return side; }
					void   accept( Visitor const &v ) override { v.visit( *this ); }
				};

				struct Helper {
					unsigned long long drawed = 0ULL;
					std::string_view   name{ "Visitor" };

					class Draw : public Visitor
					{
					public:
						void visit( Circle const &c ) const override { ++helper.drawed; }
						void visit( Square const &c ) const override { ++helper.drawed; }
					};

          using Shapes = std::vector< std::unique_ptr< Shape > >;

					void draw_all( Shapes const &shapes )
					{
						Draw d;
						for( auto const &s: shapes ) {
							s->accept( d );
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

			} // namespace visitor
		}   // namespace polymorfism
	}     // namespace bigous
}