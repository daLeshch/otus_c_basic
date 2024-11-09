#include "Ball.hpp"
#include <cmath>

// Конструктор по умолчанию
Ball::Ball() : ball_velocity(Velocity()), ball_center(Point()), ball_radius(0.0), ball_mass(0.0), ball_colour(Color()){
}

// Конструктор уже с параметрами
Ball::Ball(double x, double y, const Velocity& velocity, double radius, const Color& color) 
    : ball_velocity(Velocity(velocity)), ball_center(Point(x, y)), ball_radius(radius), ball_colour(color){
        ball_mass = (4/3) * M_PI * std::pow(radius, 3);
}


/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    ball_velocity = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    return ball_velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    painter.draw(ball_center, ball_radius, ball_colour);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    ball_center = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    return ball_center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    return ball_radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    return  ball_mass;
}
