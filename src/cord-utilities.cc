#include "cord-utilities.hpp"

#include <map>
#include <stdexcept>
#include <string>

Cord* ConcatCords(Cord* left_cord, Cord* right_cord) {
  if (!left_cord->IsValidCord() || !right_cord->IsValidCord()) {
    throw std::runtime_error("Invalid cord input");
  }
  Cord* new_cord = new Cord(left_cord, right_cord);
  return new_cord;
}

void ReduceCords(cs128::ReferenceList<Cord*> cords) {
  std::map<std::string, Cord*> nodes;
  for (Cord*& cord : cords) {
    cord = Reduce(cord, nodes);
  }
}

Cord* Reduce(Cord* red_cord, std::map<std::string, Cord*>& node_map) {
  auto it = node_map.find(red_cord->ToString());
  if (it == node_map.end()) {  // not in map
    if (red_cord->left_ != nullptr)
      red_cord->left_ = Reduce(red_cord->left_, node_map);
    if (red_cord->right_ != nullptr)
      red_cord->right_ = Reduce(red_cord->right_, node_map);
    node_map[red_cord->ToString()] = red_cord;
  } else {  // in map, setting new node address
    red_cord = it->second;
  }
  return red_cord;
}