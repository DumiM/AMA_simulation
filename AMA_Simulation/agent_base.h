#pragma once
#include "agent_model.h"
#include <boost/geometry/geometries/point_xy.hpp>


using namespace boost::geometry;
using namespace std;

typedef model::d2::point_xy<double> point_2d;

class agent_base abstract
{
public:
	agent_base();
	virtual ~agent_base();
	point_2d position;
	agent_model * model = new agent_model();
};

inline agent_base::agent_base()
{
}

inline agent_base::~agent_base()
{
}
