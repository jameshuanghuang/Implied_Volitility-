//
//  payoffPut.cpp
//  CPPinQF
//
//  Created by jameshuang on 2020/6/30.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#include "payoffPut.hpp"

PayOffPut:: PayOffPut(const double _K) {
    K = _K ;
    
}
// Destructor (no need to use virtual keyword in source file)
PayOffPut::~PayOffPut(){};

double PayOffPut::operator() (const double S) const {
    if (    S-K>0  ) {
        return S-K ;
        
    }
    else {
        return 0.0;
        
    }
    
}

