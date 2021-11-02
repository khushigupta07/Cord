#include "cord.hpp"

Cord::Cord(std::string dat) {
  data_ = dat;
  length_ = dat.length();
}

Cord::Cord(Cord* left_cord, Cord* right_cord) {
  // TODO
}

size_t Cord::Length() const { return length_; }

Cord* Cord::GetLeft() const { return left_; }

Cord* Cord::GetRight() const { return right_; }

const std::string& Cord::GetData() const { return data_; }

std::string Cord::ToString() const {
  // TODO
  return "";
}

Cord* Cord::SubString(size_t lower_idx, size_t upper_idx) {
  // TODO
  return nullptr;
}

bool Cord::IsValidCord() const {
  // TODO
  return false;
}

char Cord::At(size_t idx) const {
  // TODO
  return '\0';
}
