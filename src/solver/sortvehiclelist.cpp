//
// Created by Mark van der Broek on 03/03/2017.
//

#include "solver.ih"

vector<int> Solver::sortVehicleList(int depotNumber)
{
    // Get vehicle list
    vector<Vehicle> &vehicles = d_env->d_depots[depotNumber].getVehicles();

    // Create vector with elements 0, 1,..., N (N: Number of vehicles in depot)
    vector<int> orderedVehicles(vehicles.size());
    iota(std::begin(orderedVehicles), std::end(orderedVehicles), 0);

    sort(begin(orderedVehicles), end(orderedVehicles),
         [&](int lhs, int rhs)
         {
             return vehicles[lhs].getDrivingCost() < vehicles[rhs].getDrivingCost();
         });

    return orderedVehicles;
}