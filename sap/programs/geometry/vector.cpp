/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 16:00:50 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/04 20:48:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class Vec3
{
	public:
	Vec3() : x(T(0)), y(T(0)), z(T(0))
	{}
	Vec3(const T &xx) : x(xx), y(xx), z(xx)
	{}
	Vec3(const T &xx, const T &yy, const T &zz) : x(xx), y(yy), z(zz)
	{}
	void display()
	{
		cout << x << " " << y << " " << z << endl;
	}
	T	x, y, z;
};

typedef Vec3<float> Vec3f;

int	main(void)
{
	Vec3<int> V1(10);
	Vec3<int> V2(10, 15, 20);
	Vec3<int> V3;

	V1.display();
	V2.display();
	V3.display();
	return (0);
}
