#include "tasks.h"
#include "circle.h"

double taskEarth(double earthRadiusKm, double extraLengthM) {
  Circle earth(earthRadiusKm * 1000);
  double initialFerence = earth.getFerence();
  earth.setFerence(initialFerence + extraLengthM);
  
  return earth.getRadius() - (earthRadiusKm * 1000);
}

double taskPool(double poolRadius, double pathWidth, double priceConcrete, double priceFence) {
  Circle pool(poolRadius);
  Circle outer(poolRadius + pathWidth);

  double areaPath = outer.getArea() - pool.getArea();
  double costConcrete = areaPath * priceConcrete;
  double costFence = outer.getFerence() * priceFence;

  return costConcrete + costFence;
}
