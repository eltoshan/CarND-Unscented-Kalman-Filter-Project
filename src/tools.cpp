#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
	rmse << 0,0,0,0;

  if ((estimations.size() == 0) || (estimations.size() != ground_truth.size())) {
	    return rmse;
	}

	for(int i=0; i < estimations.size(); ++i){
		VectorXd err = estimations[i] - ground_truth[i];
    err = err.array() * err.array();
		rmse += err;
	}

	rmse = rmse / estimations.size();
  rmse = rmse.array().sqrt();

  return rmse;
}
