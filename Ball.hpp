#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball();
    Ball(double x, double y, const Velocity& velocity, double radius, const Color& color);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;

private:
    Velocity ball_velocity;
    Point ball_center;
    double ball_radius;
    double ball_mass;
    Color ball_colour;
};
