//
//  cheesecake.hpp
//  design_pattern
//
//  Created by jameshuang on 2020/5/19.
//  Copyright © 2020 jameshuang. All rights reserved.
//

#ifndef bs_hpp
#define bs_hpp

#include <stdio.h>
class VanillaOption{
public:
    VanillaOption();
    VanillaOption(const VanillaOption& rhs);
    VanillaOption(const double& S_,const double& K_,const double& r_,const double& sigma_,const double& T_);
    VanillaOption& operator= (const VanillaOption& rhs);
    virtual ~VanillaOption();
    double getK() const;
    double getr() const;
    double getT() const;
    double getS() const;
    double getsigma() const;
    
    double cal_call() const;
    double cal_put() const;
    double delta(const int type) const; //call0 put1
    double gamma() const;
    double vega() const;

    
private:
    double K;
    double r;
    double T;
    double S;
    double sigma;
    void init();
    void copy (const VanillaOption& rhs );
    
    
};
#endif /* cheesecake_hpp */
