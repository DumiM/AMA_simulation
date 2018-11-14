#pragma once
#include  <boost/numeric/ublas/matrix.hpp>


using namespace boost::numeric::ublas;


class agent_model
{
private:
	virtual ~agent_model();
public:
	agent_model();
	matrix<double> shape_matrix;
};


inline agent_model::~agent_model()
{
}

inline agent_model::agent_model()
{
	//set the shape using matrix
	shape_matrix.resize(3, 2);
	shape_matrix(0, 0) = -5;
	shape_matrix(0, 1) = 3;
	shape_matrix(1, 0) = 5;
	shape_matrix(1, 1) = 0.0;
	shape_matrix(2, 0) = -5;
	shape_matrix(2, 1) = -3;
}
