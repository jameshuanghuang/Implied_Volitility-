//
//  BlackScholesCall.hpp
//  CPPinQF
//
//  Created by jameshuang on 2020/6/29.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#ifndef BlackScholesCall_hpp
#define BlackScholesCall_hpp

#include <stdio.h>
#include "bs.hpp"

class BlackScholes{
private:
     double K;
     double r;
     double T;
     double S;
public:
    BlackScholes(double S_,double K_,double r_,double T_);
    double operator()( double sigma ) const ;
    double call_price(double sigma) const;
    double put_price(double sigma) const;
    double option_vega(double sigma) const;
    
    
};

#endif /* BlackScholesCall_hpp */
