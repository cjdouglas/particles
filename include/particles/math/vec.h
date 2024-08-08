#pragma once

#include <concepts>

namespace particles {
struct vec {
  float x;
  float y;

  constexpr vec() : x{0}, y{0} {}
  constexpr vec(const float x_, const float y_) : x{x_}, y{y_} {}
  constexpr vec(const vec&) = default;
  constexpr ~vec() = default;
  constexpr vec& operator=(const vec&) = default;
  constexpr vec(vec&&) = default;
  constexpr vec& operator=(vec&&) = default;

  [[nodiscard]] constexpr vec operator-() const { return {-x, -y}; }
  [[nodiscard]] constexpr vec operator+(const vec& v) const { return {x + v.x, y + v.y}; }
  [[nodiscard]] constexpr vec operator-(const vec& v) const { return {x - v.x, y - v.y}; }
  [[nodiscard]] constexpr vec operator*(const vec& v) const { return {x * v.x, y * v.y}; }

  template <typename T>
    requires std::convertible_to<T, float>
  [[nodiscard]] constexpr vec operator+(const T& t) {
    return {x + t, y + t};
  }

  template <typename T>
    requires std::convertible_to<T, float>
  [[nodiscard]] constexpr vec operator-(const T& t) {
    return {x - t, y - t};
  }

  template <typename T>
    requires std::convertible_to<T, float>
  [[nodiscard]] constexpr vec operator*(const T& t) {
    return {x * t, y * t};
  }

  template <typename T>
    requires std::convertible_to<T, float>
  constexpr void operator+=(const T& t) {
    x += t;
    y += t;
  }

  template <typename T>
    requires std::convertible_to<T, float>
  constexpr void operator-=(const T& t) {
    x -= t;
    y -= t;
  }

  template <typename T>
    requires std::convertible_to<T, float>
  constexpr void operator*=(const T& t) {
    x *= t;
    y *= t;
  }
};
}  // namespace particles

inline std::ostream& operator<<(std::ostream& os, const particles::vec& v) {
  os << "{" << v.x << ", " << v.y << "}";
  return os;
}
