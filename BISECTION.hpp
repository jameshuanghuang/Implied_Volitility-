//
//  BISECTION.hpp
//  CPPinQF
//
//  Created by jameshuang on 2020/6/29.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#ifndef BISECTION_hpp
#define BISECTION_hpp
#include <stdio.h>
#include <cmath>

//add the template<typename T> syntax to the signature of the function in order to tell the compiler it should be expecting a generic type as one of its parameters. The function body implicitly calls operator() of the
//function object g, so any object passed to it must define operator() for a sole parameter.


template<typename T,
         double (T::*g)(double) const>
double interval_bisection (double y_target ,
                           double m, //left
                           double n, //right
                           T& root_finder){    /// function object of type T name g 

    double epsilon = 0.0001;
    double x = 0.5 *(m+n);
    double y = (root_finder.*g)(x);
    
    do {
        if(y<y_target){
            m=x;
        }
        if(y>y_target){
            n=x;
        }
        x = 0.5*(m+n);
        y = (root_finder.*g)(x);
    }
    
    while( abs(y-y_target ) > epsilon );
    
    return x;
}





#endif /* BISECTION_hpp */
