//author: Mert Balkan
#include <iostream>
#include <math.h>
#include "BisectionHeader.h"

long double BisectionCalculator::CalculateFunctionValue(long double value)
{
    value = (10 * exp(-value / 2)) * (cos(6 * value) + sin(8 * value));
    return value;
}

void BisectionCalculator::StartProgram()
{ 
    //EXAMPLE FUNC => f(x) = 10*e^-x/2*(cos6x+sin8x)

    std::cout << "Min Range(a):";
    std::cin >> _minRange;
    std::cout << "Max Range(b):";
    std::cin >> _maxRange;
    std::cout << "Sensitivity(E):";
    std::cin >> _sensitivity;
    std::cout << "RepeatCount(Nmax):";
    std::cin >> _maxRepeatCount;

    long double calculateMinRange = CalculateFunctionValue(_minRange);
    long double calculateMaxRange = CalculateFunctionValue(_maxRange);

    if (calculateMaxRange * calculateMinRange > 0)
    {
        std::cout << "There is no root in that range!" << std::endl;
        EndProgram(_decisiveRoot, _currentRepeatCount);
    }
    else if (calculateMaxRange * calculateMinRange == 0)
    {
        if (calculateMinRange == 0)
        {
            _decisiveRoot = _minRange;
            EndProgram(_decisiveRoot, _currentRepeatCount);
        }
        else
        {
            _decisiveRoot = _maxRange;
            EndProgram(_decisiveRoot, _currentRepeatCount);
        }
    }
    //Foot 4:
    else
    {
        _currentRepeatCount = 1;
        while (_currentRepeatCount < _maxRepeatCount)
        {
            std::cout << "New Root:" << _currentRoot << std::endl;
            _currentRoot = (_minRange + _maxRange) / 2;
            long double calculateRootValue = CalculateFunctionValue(_currentRoot);
            //Foot 6:
            if (calculateMinRange * calculateRootValue == 0)
            {
                if (calculateMinRange == 0)
                {
                    _decisiveRoot = _minRange;
                    EndProgram(_decisiveRoot, _currentRepeatCount);
                }
                else if (calculateRootValue == 0)
                {
                    _decisiveRoot = _currentRoot;
                    EndProgram(_decisiveRoot, _currentRepeatCount);
                }
            }

            if (calculateMinRange * calculateRootValue < 0)
            {
                _maxRange = _currentRoot;
            }
            else
            {
                _minRange = _currentRoot;
            }

            if (abs((_maxRange - _minRange) / 2) < _sensitivity)
            {
                _decisiveRoot = _currentRoot;
                EndProgram(_decisiveRoot, _currentRepeatCount);
            }
            else
            {
                _currentRepeatCount++;
            }
            if (_currentRepeatCount > _maxRepeatCount)
            {
                std::cout << "Maximum repeat of the convergence could not be obtained" << std::endl;
                system("PAUSE");
                // return 0;
            }
        }
    }
    EndProgram(_decisiveRoot, _currentRepeatCount);
}

void BisectionCalculator::EndProgram(long double decisiveRoot, int currentRepeatCount)
{

    std::cout << "ROOT:" << decisiveRoot << std::endl;
    std::cout << "TOTAL REPEAT COUNT:" << currentRepeatCount << std::endl;
    system("PAUSE");
    exit(0);
}