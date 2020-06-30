//
//  cheesecake.cpp
//  design_pattern
//
//  Created by jameshuang on 2020/5/19.
//  Copyright © 2020 jameshuang. All rights reserved.
//


#include <cmath>
#include "bs.hpp"


//-------helper function-----------

double norm_pdf(const double& x) {
    return (1.0/(pow(2*M_PI,0.5) ))*exp(-(0.5)*x*x) ;
}

double norm_cdf(const double& x) {
    double k = 1.0/(1.0 + 0.2316419*x) ;
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k)))) ;
    
    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x)*k_sum);
    }
    else {
    return 1.0 - norm_cdf(-x) ;
    }
}



double d_j(const int& j, const double& S, const double& K, const double& r,const double& v , const double& T) {
    return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5)));
}

//-------helper function-----------

void VanillaOption::init(){
    //a helper method
    S = 100.0;
    K = 100.0;
    r = 0.05;
    sigma = 0.2;
    T = 1.0;
    
}

void VanillaOption::copy(const VanillaOption& rhs){
    //a helper method to aviod DRY used by copy constructor and op=.
    K = rhs.getK();
    r = rhs.getr();
    T = rhs.getT();
    S = rhs.getS();
    sigma = rhs.getsigma();
    
}

VanillaOption:: VanillaOption() { init();}
VanillaOption:: VanillaOption(const double& S_,const double& K_,const double& r_,const double& sigma_,const double& T_){
    S=S_;
    K=K_;
    r=r_;
    sigma = sigma_;
    T=T_;
}

VanillaOption:: VanillaOption( const VanillaOption& rhs){
    copy(rhs);
}
VanillaOption& VanillaOption:: operator=(const VanillaOption& rhs)
{
    if (this == &rhs) return *this; //to aviod copy yourself and waste of resource
    copy(rhs);
    return *this;
}

VanillaOption :: ~VanillaOption(){}

double VanillaOption:: getK() const { return K;}
double VanillaOption:: getr() const { return r;}
double VanillaOption:: getT() const { return T;}
double VanillaOption:: getS() const { return S;}
double VanillaOption:: getsigma() const { return sigma;}

double VanillaOption::cal_put() const {
    
    return -S*norm_cdf(-d_j(1,S,K,r,sigma,T))+K*exp(-r*T)*norm_cdf(-d_j(2, S, K, r, sigma, T));
}

double VanillaOption::cal_call() const {
    return S*norm_cdf(d_j(1,S,K,r,sigma,T))-K*exp(-r*T)*norm_cdf(d_j(2, S, K, r, sigma, T));
}

double VanillaOption::delta(const int type) const {
    if (type==0){
        //call 0
        return norm_cdf(d_j(1,S,K,r,sigma,T));
    }
    else {
        //put 1
        return norm_cdf(d_j(1,S,K,r,sigma,T))-1;
    }
}

double VanillaOption::gamma() const {
    return norm_pdf(d_j(1,S,K,r,sigma,T))/(S*sigma*sqrt(T));
}


double VanillaOption::vega() const{
    return S*sqrt(T)*norm_pdf(d_j(1, S, K, r, sigma, T));
    
}



