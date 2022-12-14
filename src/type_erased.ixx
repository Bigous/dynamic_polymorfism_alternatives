module;

#include <memory>
#include <string_view>
#include <variant>
#include <vector>

export module Bigous.Polymorfism.TypeErased;

export
{
	namespace bigous
	{
		namespace polymorfism
		{
			namespace type_erased
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

				class Shape
				{
				private:
					struct Concept {
						virtual ~Concept() {}
						virtual void     do_draw() const = 0;
						virtual Concept *clone() const   = 0;
					};

					template < typename T > struct Model : Concept {
						explicit Model( T const &value ) : object{ value } {}
						void     do_draw() const override { draw( object ); }
						Concept *clone() const override { return new Model( object ); }
						T        object;
					};
					Concept    *pimpl;
					friend void draw( Shape const &shape ) { shape.pimpl->do_draw(); }

				public:
					template < typename T > Shape( T const &x ) : pimpl{ new Model< T >( x ) } {}
					~Shape() { delete pimpl; }
					Shape( Shape const &s ) : pimpl{ s.pimpl->clone() } {}
					Shape &operator=( Shape s )
					{
						std::swap( pimpl, s.pimpl );
						return *this;
					}
				};

				struct Helper {

					using Shapes = std::vector< Shape >;

					unsigned long long drawed = 0ULL;
					std::string_view   name{ "Type Erased" };

					void draw_all( Shapes const &shapes )
					{
						for( auto const &s: shapes ) {
							draw( s );
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

				void draw( Circle const & ) { ++helper.drawed; }
				void draw( Square const & ) { ++helper.drawed; }
			} // namespace type_erased
		}   // namespace polymorfism
	}     // namespace bigous
}