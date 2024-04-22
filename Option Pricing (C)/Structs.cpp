#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define length 10
#define Format 3 //for printf 

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
    double coupon_payment;
    double yield_to_maturity; //years
    const double maturity;
};

struct Forwards
{
    const double forward_price;
    const double maturity; //years
    double spot_price;
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

typedef struct Options options;
typedef struct Bonds bonds;
typedef struct Forwards forwards;
typedef struct Futures futures;
typedef struct Swaps swaps;


/**********************************************************************************************************************************************************************/
//function prototypes for derivative calculations
double option_payoffs(struct Options option);
double option_combinations(struct Options option,struct Options option2,struct Options option3);
double futures(struct Futures futures);
double bonds(struct Bonds bonds);


// vary the final stock price to get the range of positive profits
double option_payoffs(struct Options option)
{
    double payoff = (2*option.long_short - 1)*fmax((2*option.call_put - 1)*option.stock_price - (2*option.call_put - 1)*option.strike_price,0);
    double profit = (2*option.long_short - 1)*fmax((2*option.call_put - 1)*option.stock_price - (2*option.call_put - 1)*option.strike_price,0) - (2*option.long_short - 1)*option.option_price;
    return profit;
};

double option_combinations(struct Options option,struct Options option2,struct Options option3)
{
    printf("The option combination gives $ %.*f profit.\n",Format,(option_payoffs(option) + option_payoffs(option2) + option_payoffs(option3)));
    return (option_payoffs(option) + option_payoffs(option2) + option_payoffs(option3));
}

double futures(struct Futures futures)
{
    double future_value = exp(futures.interest*futures.maturity);
    return future_value;
}

double bonds(struct Bonds bonds)
{
    bonds.price;
    bonds.coupon_payment;
    bonds.coupon_rate;
    bonds.face_value;
    bonds.maturity;
    bonds.yield_to_maturity;

    //calculate present value to see if there is arbitrage opportunities
    // double yield_to_maturity = formula;
    // double present_value = formula;
    // double forward_rate = formula;

    // bonds(0,0,100,0.5,0)

}

int main()
{   
    clock_t begin = clock();
    //option (stock_price;option_price;strike_price;call_put;long_short;American_European)
    options call50 = {65,10,50,1,1,0};
    options put50 = {45,5,50,0,1,0};
    options nulloption = {0};
    option_combinations(call50,put50,nulloption);


    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("It took %f seconds to execute the program",time_spent);

    //end program
    return 0;
}


