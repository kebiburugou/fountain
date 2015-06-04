#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "FVector.h"
#include "Pool.h"

class FountainInitializer {
public:
    FountainInitializer(int levels, int raysPerStep, int dropsPerRay,
                        float dropSize, float angleMin, float angleMax,
                        float randomAngle, float acceleration) {
        this->levels = levels;
        this->raysPerStep = raysPerStep;
        this->dropsPerRay = dropsPerRay;
        this->dropSize = dropSize;
        this->angleMin = angleMin;
        this->angleMax = angleMax;
        this->randomAngle = randomAngle;
        this->acceleration = acceleration;
    }
    int levels;
    int raysPerStep;
    int dropsPerRay;
    float dropSize;
    float angleMin;
    float angleMax;
    float randomAngle;
    float acceleration;
};

class Fountain;

class Drop {
public:
    void setSpeed(FVector3 newSpeed);
    void setAcceleration(float newAcc);
    void setTime(float newTime);
    void updatePosition(FVector3 & position, float dtime,
                        Pool & pool, Fountain & fountain);
private:
    float time;  // time after the drop take off
    FVector3 speed;
    float acceleration;
};

class Fountain {
public:
    Fountain() : dropPositions(nullptr), drops(nullptr) {}

    Fountain(int levels, int raysPerStep, int dropsPerRay,
             float dropSize, float angleMin, float angleMax,
             float randomAngle, float acceleration)
             : dropPositions(nullptr), drops(nullptr) {
        initialize(levels, raysPerStep, dropsPerRay, dropSize, angleMin, angleMax,
                   randomAngle, acceleration);
    }

    void initialize(int levels, int raysPerStep, int dropsPerRay,
                    float dropSize, float angleMin, float angleMax,
                    float randomAngle, float acceleration);

    void initialize(FountainInitializer init) {
        initialize(init.levels, init.raysPerStep, init.dropsPerRay,
                   init.dropSize, init.angleMin, init.angleMax,
                   init.randomAngle, init.acceleration);
    }
    
    void render();
    void update(float dtime, Pool & pPool);
    ~Fountain() {
        delete [] drops;
        delete [] dropPositions;
    }

    FVector3 center;  // center of this fountain
private:
    int numDrops;  // number of drops
    float dropSize;  // size of drops
    FVector3 * dropPositions;  // positions of the drops this fountain emits
    Drop * drops;  // drop info(speed, accelerations, etc.)
};

#endif