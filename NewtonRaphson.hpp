//
//  NewtonRaphson.hpp
//  CPPinQF
//
//  Created by jameshuang on 2020/6/30.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#ifndef NewtonRaphson_hpp
#define NewtonRaphson_hpp

#include <stdio.h>
#include <cmath>

template<typename T,
         double (T::*g)(double) const,
         double (T::*g_prime)(double) const>  //first derivative of g
double Newton_Raphson (double y_target ,
                           double x_init, //left
                           T & root_finder){    // functor

    double epsilon = 0.001;
    double x = x_init;
    double y = (root_finder.*g)(x_init);

    
    while( abs(y-y_target ) > epsilon ){
        double dx = (root_finder.*g_prime)(x);
        x+= (y_target-y)/dx;
        y = (root_finder.*g)(x);
    }
    
    return x;
}




#endif /* NewtonRaphson_hpp */
