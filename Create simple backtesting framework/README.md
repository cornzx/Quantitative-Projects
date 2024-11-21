# Create simple backtesting framework

This challenge is focused on creating a simple backtesting framework with pandas and numpy
without commonly used backtesting frameworks.


Strategy:
1. Check rsi dataframe if rsi < 25 or rsi > 75 for each date and 
2. If rsi < 25, buy indicator Else if rsi > 75, sell indicator. Otherwise, hold indicator.
3. Portfolio allocation is equal-weighted among all stocks that meet the criteria at any given time. This means allocating same number of shares for those stocks.
4. Account for commission and slippage per transaction
5. Check Capital before every trade AND weightage of each stock to ensure its not above 30%. Rebalance at next signal if the weightage increases at next check.
6. Prevent overbuying (total capital used > 1000,000) and overselling (total capital used < 0) by managing buy and sell positions of shares based on RSI indicators

Assumptions:
1. Strategy has constraints and variables as listed above
2. Commission and slippage per transaction is constant which increases buying costs and reduces selling profit
3. RSI indicator is based on past week rolling prices
4. Maximum weightage of any stock is 30% of total portfolio AUM, whichever is higher
5. Shares are bought until the criteria is reached and all shares are SOLD
6. When calculating AUM, we exclude the cost_factor (commission and slippage which will affect the total costs)
7. selling may increase weightage of other stocks to exceed 30% which will be rebalanced at the next opportunity

Metrics to record
- Total Return
- Annual Return
- Annual Volatility
- Maximum Drawdown
- Sharpe Ratio
- Sortino Ratio
- Total Number of Trades
- Average Return per Trade
- Win Rate
- Expectancy

<br>

### Appendix
| Index | Documentation  |
|--------------|------|
|   Pandas     | https://pandas.pydata.org/pandas-docs/stable/reference/|
|   Numpy      | https://numpy.org/doc/1.24/reference/index.html|


Some new ideas:
-  implement multi-threading to speed up calculations

References:
<nav>
</nav> 