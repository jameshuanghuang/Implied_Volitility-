//
//  BlackScholesCall.cpp
//  CPPinQF
//
//  Created by jameshuang on 2020/6/29.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#include "BlackScholes.hpp"
#include "bs.hpp"



BlackScholes:: BlackScholes(double _S , double _K, double _r , double _T){
    S=_S;
    K=_K;
    r=_r;
    T=_T;
};

double BlackScholes ::operator()(double sigma) const {
    VanillaOption v = VanillaOption(S, K, r, sigma, T);
    return v.cal_call() ;
}



double BlackScholes ::call_price(double sigma) const{ //rename operator() to call_price()
    VanillaOption v = VanillaOption(S, K, r, sigma, T);
    return v.cal_call() ;
}
double BlackScholes ::put_price(double sigma) const{
     VanillaOption v = VanillaOption(S, K, r, sigma, T);
     return v.cal_put() ;
}
double BlackScholes ::option_vega(double sigma) const{
    VanillaOption v = VanillaOption(S, K, r, sigma, T);
    return v.vega();
    //return v.gamma();
}
