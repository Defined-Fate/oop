#include <cmath>
#include <iostream>
struct ComplexNumbers {
  float real, imag;
  ComplexNumbers(float real = 0, float imag = 0):real(real), imag(imag) {}
  
  ComplexNumbers(const ComplexNumbers &z): real(z.real), imag(z.imag) {}

  ComplexNumbers &operator=(const ComplexNumbers &z){
    real = z.real;
    imag = z.imag;

    return *this;
  }

  float formodul() const {
    return real * real + imag * imag;
  }

  float operator~() const {
    return sqrt(formodul());
  }

  ComplexNumbers operator+(const ComplexNumbers &z) const {
    return {real + z.real, imag + z.imag};
  }

  ComplexNumbers operator-(const ComplexNumbers &z) const {
    return {real - z.real, imag - z.imag};
  }

  ComplexNumbers operator*(const ComplexNumbers &z) const {
    return {real * z.real - imag * z.imag, imag * z.real + real * z.imag};
  }

  ComplexNumbers operator/(const ComplexNumbers &z) const {
    return {(real * z.real + imag * z.imag) / (z.real * z.real + z.imag * z.imag), (imag * z.real - z.imag * real) / (z.real * z.real + z.imag * z.imag)};
  }

  ComplexNumbers operator*(float n) const {
    return {real * n, imag * n};
  }

  ComplexNumbers operator/(float n) const {
    return {real / n, imag / n};
  }

  friend std::ostream &operator<<(std::ostream &os, const ComplexNumbers &z) {
  	return os << z.real << " + " << z.imag << 'i';
  }
};

int main (int argc, char *argv[]) {
  ComplexNumbers z(2, 5);
  ComplexNumbers z1(6, 3);

  std::cout << z << " " << z1 << '\n';
  std::cout << z+z1 << '\n';
  std::cout << z1-z << '\n';
  std::cout << ~z << '\n';
  std::cout << z*z1 << '\n';
  std::cout << z/z1 << '\n';
  std::cout << z*2 << '\n';
  std::cout << z1/3 << '\n';

  return 0;
}
