#ifndef PARSER_H
#define PARSER_H

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Component {

 protected:
  Component *parent_;
private:

 public:


  virtual ~Component() {}
  void SetParent(Component *parent) {
    this->parent_ = parent;
  }
  Component *GetParent() const {
    return this->parent_;
  }

  virtual void Add(Component *component) {}

  virtual void Remove(Component *component) {}

  virtual bool IsComposite() const {
    return false;
  }

  virtual std::string Operation() const = 0;
};

class Leaf : public Component {


 public:

  std::string Operation() const override {
    return "Argument";
  }
};
/// <summary>
/// The derived class of the Component class. It contains complex structures, which can have nested components.
/// </summary>
class Composite : public Component {

 protected:
  std::list<Component *> children_;

 public:

  void Add(Component *component) override {
    this->children_.push_back(component);
    component->SetParent(this);
  }

  void Remove(Component *component) override {
    children_.remove(component);
    component->SetParent(nullptr);
  }

  bool IsComposite() const override {
    return true;
  }

  std::string Operation() const override {
    std::string result;
    for (const Component *c : children_) {
      if (c == children_.back()) {
        result += c->Operation();
      } else {
        result += c->Operation() + "+";
      }
    }
    return "Loop(" + result + ")";
  }
};

string Simple_tree(Component *component) {
    string result;
 // std::cout << "RESULT: " << component->Operation();
return  result = component->Operation();
}


string Complex_tree(Component *component1, Component *component2) {
string result;
  if (component1->IsComposite()) {
    component1->Add(component2);
  }
  //std::cout << "RESULT: " << component1->Operation();
    return result = component1->Operation();
}

#endif // PARSER_H
