//author: Mert Balkan
#pragma once
#ifndef BISECTIONHEADER_H_
#define BISECTIONHEADER_H_

class BisectionCalculator
{
private:
    long double _minRange, _maxRange, _sensitivity, _maxRepeatCount;
    int _currentRepeatCount;
    double _currentRoot, _decisiveRoot;

public:
    void StartProgram();
    void EndProgram(long double, int);

    long double CalculateFunctionValue(long double value);

    long double& GetMinRange() { return this->_minRange; }
    long double& GetMaxRange() { return this->_maxRange; }
    long double& GetSensitivity() { return this->_sensitivity; }
    long double& GetMaxRepeatCount() { return this->_maxRepeatCount; }

    int& GetCurrentRepeatCount() { return this->_currentRepeatCount; }

    double& GetCurrentRoot() { return this->_currentRoot; }
    double& GetDecisiveRoot() { return this->_decisiveRoot; }

};

#endif