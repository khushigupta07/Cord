#include "cord.hpp"

#include <stdexcept>

Cord::Cord(std::string dat) {
  data_ = dat;
  length_ = dat.length();
}

Cord::Cord(Cord* left_cord, Cord* right_cord) {
  left_ = left_cord;
  right_ = right_cord;
  length_ = left_cord->Length() + right_cord->Length();
};

size_t Cord::Length() const { return length_; }

Cord* Cord::GetLeft() const { return left_; }

Cord* Cord::GetRight() const { return right_; }

const std::string& Cord::GetData() const { return data_; }

std::string Cord::ToString() const {
  if (left_ == nullptr && right_ == nullptr) {
    return data_;
  }
  return left_->ToString() + right_->ToString();
}

Cord* Cord::SubString(size_t lower_idx, size_t upper_idx) {
  size_t sub_length = upper_idx - lower_idx;
  if (sub_length == 0) return nullptr;
  if (length_ == sub_length) {
    return this;
  }
  if (left_ == nullptr and right_ == nullptr) {  // checking for leaf node
    Cord* new_cord = new Cord(data_.substr(lower_idx, upper_idx - lower_idx));
    return new_cord;
  }
  if (lower_idx < left_->Length() and
      upper_idx <= left_->Length()) {  // completely in left
    return left_->SubString(lower_idx, upper_idx);
  }
  if (lower_idx >= left_->Length()) {  // completely in right
    return right_->SubString(lower_idx - left_->Length(),
                             upper_idx - left_->Length());
  }
  Cord* left_cord = left_->SubString(lower_idx, left_->Length());
  Cord* right_cord = right_->SubString(0, upper_idx - left_->Length());
  Cord* conc_cord = ConcatCords(left_cord, right_cord);
  return conc_cord;
}

bool Cord::IsValidCord() const {
  if (!data_.empty() and left_ == nullptr and right_ == nullptr and
      length_ == data_.length()) {
    return true;
  }
  if (data_.empty() and left_ != nullptr and right_ != nullptr and
      right_->Length() < length_ and left_->Length() < length_ and
      length_ == (right_->Length() + left_->Length())) {
    return left_->IsValidCord() and right_->IsValidCord();
  }
  return false;
}

char Cord::At(size_t idx) const {
  if (idx > (length_ - 1) || idx < 0)
    throw std::runtime_error("Index out of bound");
  if (left_ == nullptr && right_ == nullptr) {
    return data_.at(idx);
  }
  if (idx < left_->Length()) {
    return left_->At(idx);
  }
  return right_->At(idx - (left_->Length()));
}
