//
//  payoff.hpp
//  design_pattern
//
//  Created by jameshuang on 2020/6/20.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#ifndef payoff_hpp
#define payoff_hpp

#include <stdio.h>
#include <algorithm>

class PayOff {
    public :
        PayOff() {}; // Default (no parameter) constructor
        virtual ~PayOff() {}; // Virtual destructor
// Overloaded operator () , turns the PayOff into an abstract function object
        virtual double operator() (const double S) const = 0; // Pure virtual method
};



#endif /* payoff_hpp */
