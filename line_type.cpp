//The lines in this program are represented in standard form Ax + By = C.
//Created: 2/16/2024
//Author: Mabo Giqwa
//Purpose: Solves linear systems with 2 equations and 2 variables.
#include <iostream>
#include <cmath>

class lineType
{
public:
	double get_slope() const;
	//Postcondition: Returns the slope of a line of the form a_1x + b_1y = c_1
	bool check_equality(const lineType&) const;
	//Postcondition: Returns boolean value which indicates whether two equations
	//are equal or not.
	bool check_if_parallel(const lineType&) const;
	//Postcondition: Returns a boolean value which indicates whether two equations 
	//are parallel or not.
	bool check_if_perpendicular(const lineType&) const;
	//Postcondition: Returns a boolean value which indicates whether two equations are 
	//perpendicular or not.
    double get_a_in_explicit_form() const;
    //Postcondition: Returns the value of A in an explicit form y = C - Ax where A = a/b
    double get_c_in_explicit_form() const;
    //Postcondition: Returns the value of C in an explicit form y = C - Ax where C = c/b
    double get_x_intersection(const lineType&);
    //Precondition: The lines must not be parallel.
    //Postcondition: Returns the x intersection of two lines of the form y = mx + c
    double get_y_intersection(double);
    //Postcondition: Returns the y value of the intersection of two lines that are not
    //parallel.
    void print_intersection_of_lines(const lineType& line2);
    //Postcondition: Prints the intersection of two lines that are not parallel.
	lineType();
    lineType(double, double, double);
    //The values for the formal parameters are represented as Ax + By = C, in the standard
    //form.
private:
	double a;
	double b;
	double c;
};

lineType::lineType() : a(1), b(1)
{

}

lineType::lineType(double a_value, double b_value, double c_value)
{
    a = a_value;
    b = b_value;
    c = c_value;
}

//Get slope is functional, no bugs.
double lineType::get_slope() const
{
	return (-1)*(a/b);
    //The -1 is to elucidate that the Ax is moved to the right hand side
    //so that the equation is represented as y = (A/B)x + C where A/B is the
    //slope.
}

//check_equality is functional, no bugs.
bool lineType::check_equality(const lineType& line2) const
{
	return (a == line2.a && b == line2.b && c == line2.c);
}

bool lineType::check_if_parallel(const lineType& line2) const
{
    return (get_slope() == line2.get_slope());
}

bool lineType::check_if_perpendicular(const lineType& line2) const
{
	double m_1 = (a/b); //Calculates the slope for the first line
	double m_2 = (line2.a/line2.b); //Calculates the slope for the second line
	
	return ((m_1 * m_2) == -1); //Checks if the product of the two slopes is -1.
}

double lineType::get_a_in_explicit_form() const
{
    return (-1)*(a/b);
}

double lineType::get_c_in_explicit_form() const
{
    return c/b;
}

double lineType::get_x_intersection(const lineType& line2)
{
    double a_2, c_2;

    double a_0 = get_a_in_explicit_form();
    double a_1 = line2.get_a_in_explicit_form();
    double c_0 = get_c_in_explicit_form();
    double c_1 = line2.get_c_in_explicit_form();
    //The values of line1 and line2 are now representative of
    //their respective explicit forms, y = mx + c.
    //Before the values represented the standard form Ax + Bx = C.

    //To get the intersection of both lines if they are not parallel,
    //we equate them to c_0 + a_0x = c_1 + a_1x.
    

    //This if block encompasses moving the constant c_0 from the left side
    //to the right side of the equation.
    if (c_0 > 0) {
        c_2 = c_1 - c_0;
    }
    else {
        c_2 = c_1 + fabs(c_0);
    }

    //This if block encompasses moving the x and its coefficient a_1x to
    //the right hand side of the equation from the left.
    if (a_1 > 0) {
        a_2 = a_0 + a_1;
    }
    else {
        a_2 = a_0 + fabs(a_1);
    }

    return (c_2/a_2);
    //The value returned is the x value of where the two line intersect.
}

void lineType::print_intersection_of_lines(const lineType& line2)
{
    if (check_if_parallel(line2))
    {
        std::cout << "There is no intersection since they are parallel." << std::endl;
    } else {
        double x_value, y_value;

        x_value = get_x_intersection(line2);
        y_value = get_y_intersection(x_value);

        std::cout << "The intersection of the lines is: (" << x_value << ", " << y_value << ")." << std::endl;
    }

}

double lineType::get_y_intersection(double x_value)
{
    double a_0 = get_a_in_explicit_form();
    double c_0 = get_c_in_explicit_form();

    double y_value = a_0*x_value + c_0;

    return y_value;
}

int main()
{
    lineType line1(9,3,5);
    lineType line2(9,7,12);
    double x;

    line1.print_intersection_of_lines(line2);

	return 0;
}
