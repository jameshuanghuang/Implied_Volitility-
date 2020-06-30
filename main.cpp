//
//  main.cpp
//  CPPinQF
//
//  Created by jameshuang on 2020/6/23.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#include <iostream>
#include "bs.hpp"

#include "BlackScholes.hpp"
#include "BISECTION.hpp"
#include "NewtonRaphson.hpp"



int main(int argc, const char * argv[]) {
    double S = 100.0; double K = 100.0; double r = 0.05; double sigma = 0.2; double T = 1.0;
    
    VanillaOption vanilla = VanillaOption(S, K, r, sigma,T);
    std::cout << "Call_Price "<< vanilla.cal_call() << std::endl;
    std::cout << "Put_Price "<< vanilla.cal_put() << std::endl;
    std::cout << "delta_call "<< vanilla.delta(0) << std::endl;
    
    double marketC = 10.5;
    double marketP = 5.5;
    double low = 0.05;
    double high= 0.35;
    
    BlackScholes v(S,K,r,T) ;
    //actually sees as call(x)
    double implied_vol_c = interval_bisection<BlackScholes ,
                                              &BlackScholes :: call_price>(marketC,low, high, v);
    
    double implied_vol_p = interval_bisection<BlackScholes ,
                                              &BlackScholes :: put_price>(marketP,low, high, v);
    
    std::cout << "Implied Vol_c: "<< implied_vol_c << std::endl;
    std::cout << "Implied Vol_p: "<< implied_vol_p << std::endl;
    
    
    double init=0.3;
    double iv  = Newton_Raphson    <BlackScholes ,
                                   &BlackScholes :: call_price ,
                                   &BlackScholes :: option_vega>(marketC,init,v);
    
    std::cout << "Newton Implied Vol_c: " << iv << std::endl;
   
    return 0;
    
    
}
