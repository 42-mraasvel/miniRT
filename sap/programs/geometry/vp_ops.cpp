/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vp_ops.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 11:04:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/07 17:47:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

/*
** Operations:
** 1. Get vector length
** 2. Normalize a vector (optimized)
** 3. Dot product of 2 vectors
*/

// basic vector with 3 coordinate values.
template <typename T>
class vec3
{
public:
	// 3 different constructors.
	vec3() : x(T(0)), y(T(0)), z(T(0))
	{}
	vec3(const T &val) : x(val), y(val), z(val)
	{}
	vec3(const T &xx, const T &yy, const T &zz) : x(xx), y(yy), z(zz)
	{}
	T	get_length()
	{
		return (sqrt(x * x + y * y + z * z));
	}
	vec3<T>	normalize()
	{
		T	len;
		T	optLen;

		len = get_length();
		if (len > 0)
		{
			optLen = 1 / len;
			x *= optLen;
			y *= optLen;
			z *= optLen;
		}
		return *this;
	}
		T x, y, z;
};

// calculate the length of a vector. (distance from origin to point)
// ||V|| = vector length notation, sqrt of vector^2
template <typename T>
T	vec_length(vec3<T> &v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

// returns the normalized version of a vector.
// V^ = V / ||V||
// V^ = V * (1 / ||V||) : (optimization).
template <typename T>
vec3<T>	ft_normalize(vec3<T> &v)
{
	vec3<T>	normalized;
	T		length;
	T		optLen;

	length = v.get_length();
	optLen = 1 / length;
	normalized.x = v.x * optLen;
	normalized.y = v.y * optLen;
	normalized.z = v.z * optLen;
	return (normalized);
}

// Multiplying 2 vectors by eachother
template <typename T>
T	ft_dotproduct(vec3<T> &a, vec3<T> &b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// Cross Product
template <typename T>
vec3<T>	cross_product(vec3<T> &a, vec3<T> &b)
{
	// wtf this works, typecasting vector initialization?
	return (vec3<T>(
		a.y * b.z - a.z * b.y,
		a.x * b.z - a.z * b.x,
		a.x * b.y - a.y * b.x));
}

int	main(void)
{
	vec3<double>	v(1, 1, 0);
	vec3<double>	v2(1, 0, 0);
	vec3<double>	c;
	vec3<double>	nv;

	// nv = v2.normalize();
	// printf("nv: %f %f %f\n", nv.x, nv.y, nv.z);
	v.normalize();
	v2.normalize();
	printf("nv: %f %f %f\n", v.x, v.y, v.z);
	printf("nv: %f %f %f\n", v2.x, v2.y, v2.z);
	
	cout << "product: " << ft_dotproduct(v, v2) << endl;
	cout << "angle: " << acos(ft_dotproduct(v, v2)) * 180 / 3.14 << endl;
	c = cross_product(v, v2);
	return (0);
}
