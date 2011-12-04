////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_CONVEXSHAPE_HPP
#define SFML_CONVEXSHAPE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Shape.hpp>
#include <vector>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Specialized shape representing a convex polygon
///
////////////////////////////////////////////////////////////
class SFML_API ConvexShape : public Shape
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    ConvexShape();

    ////////////////////////////////////////////////////////////
    /// \brief Set the number of points of the polygon
    ///
    /// \param count New number of points of the polygon
    ///
    /// \see GetPointsCount
    ///
    ////////////////////////////////////////////////////////////
    void SetPointsCount(unsigned int count);

    ////////////////////////////////////////////////////////////
    /// \brief Get the number of points of the polygon
    ///
    /// \return Number of points of the polygon
    ///
    /// \see SetPointsCount
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetPointsCount() const;

    ////////////////////////////////////////////////////////////
    /// \brief Set the position of a point
    ///
    /// Don't forget that the polygon must remain convex, and
    /// the points need to stay ordered!
    ///
    /// \param index Index of the point to change
    /// \param point New position of the point
    ///
    /// \see GetPoint
    ///
    ////////////////////////////////////////////////////////////
    void SetPoint(unsigned int index, const Vector2f& point);

    ////////////////////////////////////////////////////////////
    /// \brief Get the position of a point
    ///
    /// \param index Index of the point to get
    ///
    /// \return Position of the index-th point of the polygon
    ///
    /// \see SetPoint
    ///
    ////////////////////////////////////////////////////////////
    Vector2f GetPoint(unsigned int index) const;

private :

    ////////////////////////////////////////////////////////////
    /// \brief Get the number of points defining the shape
    ///
    /// \return Number of points of the shape
    ///
    ////////////////////////////////////////////////////////////
    virtual unsigned int GetOutlinePointsCount() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get a point of the shape
    ///
    /// \param index Index of the point to get
    ///
    /// \return Index-th point of the shape
    ///
    ////////////////////////////////////////////////////////////
    virtual Vector2f GetOutlinePoint(unsigned int index) const;

private :

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    std::vector<Vector2f> myPoints; ///< Points composing the convex polygon
};

} // namespace sf


#endif // SFML_CONVEXSHAPE_HPP


////////////////////////////////////////////////////////////
/// \class sf::ConvexShape
/// \ingroup graphics
///
/// This class inherits all the functions of sf::Transformable
/// (position, rotation, scale, bounds, ...) as well as the
/// functions of sf::Shape (outline, color, texture, ...).
///
/// It is important to keep in mind that a convex shape must
/// always be... convex, otherwise it may not be drawn correctly.
/// Moreover, the points must be defined in order; using a random
/// order would result in an incorrect shape.
///
/// Usage example:
/// \code
/// sf::ConvexShape polygon;
/// polygon.SetPointsCount(3);
/// polygon.SetPoint(0, sf::Vector2f(0, 0));
/// polygon.SetPoint(1, sf::Vector2f(0, 10));
/// polygon.SetPoint(2, sf::Vector2f(25, 5));
/// polygon.SetOutlineColor(sf::Color::Red);
/// polygon.SetOutlineThickness(5);
/// polygon.SetPosition(10, 20);
/// ...
/// window.Draw(polygon);
/// \endcode
///
/// \see sf::Shape, sf::StarShape, sf::RectangleShape, sf::CircleShape
///
////////////////////////////////////////////////////////////