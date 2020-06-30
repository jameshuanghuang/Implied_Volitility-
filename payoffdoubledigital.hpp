//
//  payoffdoubledigital.hpp
//  design_pattern
//
//  Created by jameshuang on 2020/6/20.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#ifndef payoffdoubledigital_hpp
#define payoffdoubledigital_hpp

#include <stdio.h>
#include "payoff.hpp"

class PayOffDoubleDigital : public PayOff {
    private :
    
        double U; // Upper strike price
        double D; // Lower strike price
    
    
    public :
        PayOffDoubleDigital(const double U , const double D );
        virtual ~PayOffDoubleDigital () ;
        virtual double operator() (const double S) const;
    
};


#endif /* payoffdoubledigital_hpp */
