#include <iostream>

class vec2 {
protected:
  double x;
  double y;
  
public:
  vec2();
  vec2(double c);
  vec2(double x, double y);
  vec2(const vec2& o); // Copy constructor
  ~vec2(); // Destructor
  
public:
  double length2() const; // A member const function
                          // to compute the squared length
                          // of this function.  By declaring
                          // this function const, we
                          // promise that this function
                          // will not modify "this" instance, i.e.,
                          // members x and y will remain unchanged.
                          // this allows the following to work
                          //
                          //   vec2 v(1,2);
                          //   const vec2& const_v_ref = v;
                          //   cout << "Squred length = " << const_v_ref.length2() << endl;
                          //
                          // Note that if this function was not
                          // declared const, the following statement
                          // will give a compile-time error:
                          //
                          //   const_v_ref.length2()
  
  friend double length2(const vec2& v); // A friend function, which is not
                                        // not a member of vec2, to compute
                                        // the squred length of this vector.
                                        // Since this function is not a member,
                                        // we need to pass a vec2 as argument.
                                        // Here we pass a const references to
                                        // a vec2.  This is the recommended
                                        // approach to pass objects due to the following
                                        // advantages:
                                        //    1. We are only passing a reference to
                                        //       the object, avoiding a copy.
                                        //    2. Since we don't expect a vec2 to
                                        //       change because its squared length
                                        //       is computed, we pass a const reference.
                                        // Note that we also decrare this function
                                        // a friend.  That allows that vec2 instance
                                        // within this function can access the protected
                                        // members of vec2.
                                        
  const vec2& operator=(const vec2& o) { // Assignment operator
    x = o.x;
    y = o.y;
    return *this;
  }

  // vec2 a, b;
  // cout << a << ' ' << b << endl;
  friend std::ostream& operator<<(std::ostream& stream, const vec2& o) { // Insertor operator
                                                                         // Use to insert data to
                                                                         // ostream objects
    stream << o.x << ' ' << o.y;
    return stream;
  }

  // vec2 a
  // cin >> a;
  friend std::istream& operator>>(std::istream& stream, vec2& o) { // extractor operator
                                                                   // Use to extract data from
                                                                   // istream objects
    stream >> o.x;
    stream >> o.y;
    return stream;
  }
};
