#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define length 10
#define Format 3 //for printf 
#define risk_free_rate 0.01

// create put-call parity arbitrage checkers
// compounded interest rates
// pointers to menu function for different types

//structs for the financial derivatives
struct Options
{
    double stock_price;
    const double option_price;
    const double strike_price;
    bool call_put;
    bool long_short;
    bool American_European;
};

// struct Exotics
// {
//     bool asian;
//     bool lookback;
//     bool barrier;
//     bool basket;
//     bool binary;
//     bool bermuda;
//     bool chooser;
//     bool spread;
//     bool range;
//     bool quanto;
// }

struct Bonds
{
    const double price;
    const double face_value;
    const double coupon_rate;
    double coupon_frequency; //per year
    const double maturity; //years
};

struct Forwards
{
    const double spot_price;
    const double maturity; //years
    double interest;    
    double dividends;
};

struct Futures
{
    const double present_value;
    const double maturity; //years
    double interest; 
};

struct Swaps
{
    const double notional_amount;
    const double fixed_interest;
    double floating_interest; //LIBOR
};

//options {stock_price, option_price, strike_price, call_put, long_short, American_European}
typedef struct Options options;
// bonds {price, face_value, coupon_rate, coupon_frequency, yield_to_maturity, maturity}
typedef struct Bonds bonds;
// forwards {spot_price, maturity, interest, dividends}
typedef struct Forwards forwards;
// futures {present_value, maturity, interest}
typedef struct Futures futures;
// swaps {notional_amount, fixed_interest, floating_interest}
typedef struct Swaps swaps;


/**********************************************************************************************************************************************************************/
//function prototypes for derivative calculations

double option_payoffs(struct Options option);
double option_combinations(struct Options option,struct Options option2,struct Options option3);

double forward_present_value(struct Forwards forwards);
double forward_arbitrage(struct Forwards forwards);

double bonds_future_value(struct Bonds bonds);
double bonds_present_value(struct Bonds bonds);
double bonds_arbitrage(struct Bonds bonds);
double bonds_yield_to_maturity(struct Bonds bonds);


//option_payoffs (option)
double option_payoffs(struct Options option)
{
    double payoff = (2*option.long_short - 1)*fmax((2*option.call_put - 1)*option.stock_price - (2*option.call_put - 1)*option.strike_price,0);
    double profit = (2*option.long_short - 1)*fmax((2*option.call_put - 1)*option.stock_price - (2*option.call_put - 1)*option.strike_price,0) - (2*option.long_short - 1)*option.option_price;
    return profit;
};

//option_combinations (option, option2, option3)
double option_combinations(struct Options option,struct Options option2,struct Options option3)
{
    printf("The option combination gives $%.*f profit.\n",Format,(option_payoffs(option) + option_payoffs(option2) + option_payoffs(option3)));
    return (option_payoffs(option) + option_payoffs(option2) + option_payoffs(option3));
}

//forward_price (spot_price, maturity,interest,dividends)
double forward_present_value(struct Forwards forwards)
{
    return (forwards.spot_price - forwards.dividends) * exp(forwards.interest*forwards.maturity);
}

//forward_arbitrage (forwards)
double forward_arbitrage(struct Forwards forwards)
{
   return forward_present_value(forwards) - forwards.spot_price*(risk_free_rate*forwards.maturity);
}

// bonds_future_value (bonds)
double bonds_future_value(struct Bonds bonds)
{
    int i;
    double bonds_coupons_fv = 0;    
    // discounted by risk_free_rate
    for (i=1;i<bonds.coupon_frequency*bonds.maturity;i++){
        bonds_coupons_fv += bonds.coupon_rate * bonds.face_value * exp(risk_free_rate*i/bonds.coupon_frequency);
    }
    return bonds_coupons_fv + bonds.face_value;
}

// bonds_present_value (bonds)
double bonds_present_value(struct Bonds bonds)
{
    return bonds_future_value(bonds) * (-risk_free_rate*bonds.maturity);
}
    
// bonds_yield_to_maturity (bonds)
double bonds_yield_to_maturity(struct Bonds bonds)
{
    return log(bonds_future_value(bonds)/bonds_present_value(bonds));
}

// bonds_arbitrage (bonds)
double bonds_arbitrage(struct Bonds bonds)
{   
    printf("There is arbitrage profit of $%.*f when you borrowed money to buy the bond\n",Format, bonds.price - bonds_present_value(bonds) );
    return bonds.price - bonds_present_value(bonds);
}

double swaps_present_value(struct Swaps swaps)
{
    return 0;
}

/***************************************************************************************************************************************/

int main()
{   
    clock_t begin = clock();
    
    options call50 = {65,10,50,1,1,0};
    options put50 = {45,5,50,0,1,0};
    options nulloption = {0};
    option_combinations(call50,put50,nulloption);
    
    forwards forward100 = {100,1,0.02,5};
    forward_arbitrage(forward100);

    Bonds bonds100 = {100,110,0.05,4,2};
    bonds_arbitrage(bonds100);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %f seconds to execute the program",time_spent);

    //end program
    return 0;
}


