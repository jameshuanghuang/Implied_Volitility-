//
//  payoffdoubledigital.cpp
//  design_pattern
//
//  Created by jameshuang on 2020/6/20.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#include "payoffdoubledigital.hpp"



PayOffDoubleDigital :: PayOffDoubleDigital(const double _U, const double _D) {
    U=_U;
    D=_D;
}


double PayOffDoubleDigital::operator() (const double S) const {
    if (    S>=D    &&  S<=U    ) { return 1.0;}
    else {return 0.0;}
    
}
