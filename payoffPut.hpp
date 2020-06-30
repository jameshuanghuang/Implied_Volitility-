//
//  payoffPut.hpp
//  CPPinQF
//
//  Created by jameshuang on 2020/6/30.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#ifndef payoffPut_hpp
#define payoffPut_hpp

#include <stdio.h>
#include "payoff.hpp"

class PayOffPut : public PayOff {
    private :
        double K; // Strike price
    
    public :
        PayOffPut(const double K ) ;
        virtual ~PayOffPut() ;
        virtual double operator() (const double S) const;
};
#endif /* payoffPut_hpp */
