#include <stdio.h>
#include <math.h>

// Function prototype
void practice_1(void);

// Main function
int main()
{
    // Math functions
    // List of math functions in C

    // abs() - absolute value
    // fabs() - absolute value

    // sqrt() - square root
    // cbrt() - cube root

    // round() - round to nearest integer
    // floor() - round down to the nearest integer
    // ceil() - round up to the nearest integer

    // fmod() - remainder of division for floating point numbers

    // fmax() - maximum value
    // fmin() - minimum value

    // pow() - power
    // exp() - exponential
    // log() - natural logarithm
    // log10() - base 10 logarithm

    // sin() - sine
    // cos() - cosine
    // tan() - tangent
    // asin() - arcsine
    // acos() - arccosine
    // atan() - arctangent

    // hypot() - square root of the sum of squares (pythagorean theorem)

    // sqrt() - square root
    double num = 5;
    printf("The square root of %.2f is %.2f\n", num, sqrt(num));

    // pow() - power
    double base = 3.0;
    double exponent = 3.0;
    printf("The value of %.2f raised to the power of %.2f is %.2f\n", base, exponent, pow(base, exponent));

    // ceil() - round up to the nearest integer
    double num1 = 5.65;
    printf("The ceil of %.2f is %.2f\n", num1, ceil(num1)); // 6.00

    // floor() - round down to the nearest integer
    double num2 = 5.65;
    printf("The floor of %.2f is %.2f\n", num2, floor(num2)); // 5.00

    // fabs() - absolute value
    double num3 = -5.65;
    printf("The absolute value of %.2f is %.2f\n", num3, fabs(num3)); // 5.65

    // fmod() - remainder of division for floating point numbers
    double num4 = 5.65;
    double num5 = 2.0;
    printf("The remainder of %.2f divided by %.2f is %.2f\n", num4, num5, fmod(num4, num5)); // 1.65

    // log() - natural logarithm
    double num6 = 5.65;
    printf("The natural logarithm of %.2f is %.2f\n", num6, log(num6));

    // log10() - base 10 logarithm
    double num7 = 5.65;
    printf("The base 10 logarithm of %.2f is %.2f\n", num7, log10(num7));

    // exp() - exponential
    double num8 = 1;
    printf("The exponential of %.2f is %.2f\n", num8, exp(num8));

    // sin() - sine
    double num9 = 90;
    printf("The sine of %.2f is %.2f\n", num9, sin(num9 * M_PI / 180)); // sin() takes radians as input

    // cos() - cosine
    double num10 = 0;
    printf("The cosine of %.2f is %.2f\n", num10, cos(num10 * M_PI / 180)); // cos() takes radians as input

    // tan() - tangent
    double num11 = 45;
    printf("The tangent of %.2f is %.2f\n", num11, tan(num11 * M_PI / 180)); // tan() takes radians as input

    // hypot() - square root of the sum of squares (pythagorean theorem)
    double side1 = 3;
    double side2 = 4;
    printf("The hypotenuse of a right triangle with sides %.2f and %.2f is %.2f\n", side1, side2, hypot(side1, side2));

    // ==== Practice ====
    practice_1();

    return 0;
}

void practice_1(void)
{
    double x;
    printf("Enter a number: ");
    scanf("%lf", &x);

    double result;
    result = sin(x) + cos(pow(x, 2));

    printf("The result is: %.3f\n", result);
}