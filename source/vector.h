/*
	Copyright 2016-2017 sub1to

	This file is part of 2Take1 2 GTA:O Hack.

    2Take1 2 GTA:O Hack is free software: you can redistribute
	it and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation, either version 3 of the
	License, or (at your option) any later version.

    2Take1 2 GTA:O Hack is distributed in the hope that it
	will be useful, but WITHOUT ANY WARRANTY; without even the implied
	warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
	the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with 2Take1 2 GTA:O Hack.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef VECTOR_H
#define VECTOR_H

struct Vector3;

namespace vec
{
	typedef class v2
	{
		public:
			float	x	= 0,
					y	= 0;
	} v2;

	typedef class v3
	{
		public:
			float	x = 0,
					y = 0,
					z = 0;

					v3(){}
					v3(float fx, float fy, float fz);
					operator Vector3() const;
			v3&		v3::operator=(const v3& rhs);
			v3&		v3::operator*=(const v3& rhs);
			v3&		v3::operator*=(const float rhs);
			v3&		v3::operator+=(const v3& rhs);
			v3&		v3::operator-=(const v3& rhs);
			v3&		v3::transformRotToDir();
			float	v3::getDist(v3 to);
			bool	v3::empty();
			void	v3::clear();
	} v3;

	inline bool operator==(const v3& lhs, const v3& rhs)
	{
		if(lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z)
			return false;
		return true;
	}

	inline bool operator!=(const v3& lhs, const v3& rhs)
	{
		return !operator==(lhs, rhs);
	}

	inline v3 operator-(v3 lhs, const v3& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	inline v3 operator+(v3 lhs, const v3& rhs)
	{
		lhs	+= rhs;
		return lhs;
	}

	inline v3 operator*(v3 lhs, const v3& rhs)
	{
		lhs	*= rhs;
		return lhs;
	}

	inline v3 operator*(v3 lhs, const float& rhs)
	{
		lhs	*= rhs;
		return lhs;
	}
}

typedef vec::v3	v3;
typedef vec::v2 v2;

#pragma pack(push, 1)
typedef struct Vector3
{
	float x;
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
	float z;
	DWORD _paddingz;

	operator v3() const
	{
		return v3(x, y, z);
	}

	Vector3(float, float, float);
	Vector3(float, int, float, int, float, int);
	Vector3(float, int);
	Vector3(float);
	Vector3();
} Vector3;
#pragma pack(pop)

#endif