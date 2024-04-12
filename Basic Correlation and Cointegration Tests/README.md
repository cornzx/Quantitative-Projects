# Basic-Correlation-and-Cointegration-Test

**Background Information:**
- *Mean reversion states that stock prices will eventually return to their historical means, because the prices are fluctuating around the mean*

- *Stationarity is important in mean reversion because a stationary time series has constant variance and mean. <br>
Non-stationary time-series data is hard to model when there mean and variance (and co-variance) are constantly changing. <br> 
The properties of the time-series are also **unaffected by time**.  Thats why stationarity is important. <br> 
IF the time-series data is not stationary, we can use techniques such as*:
1. differencing 
2. log-transformation
3. de-trending/de-seasonalising

**There are many reasons why we use logarithmic returns for correlation:**
1. log-normality: to standardise the returns for calculation as outliers can skew the data.

2. Suppose returns are increasing at a constant rate e.g. 5% YoY, the plot for the returns/price becomes exponential over time. <br>
It can be difficult to analyse exponential curves while linear graphs are easier to analyse. <br>
Thus, we rely on the characteristic of logarithmic scales in that two equal percent changes are plotted as the same vertical distance on the scale.<br>

3. A number of stocks whose market capitalizations are massive can influence regression analyses or other ranking analysis

4. When returns are very small for short-periods, $ln(1+x)\approx ln(x)$ , is sufficiently accurate 

*More of the reasons can be found here:*
https://quant.stackexchange.com/questions/64028/why-and-when-we-should-use-the-log-variable


**Strategy**
- Cointegration is a statistical property of a pair of time series, where two or more time series move together over time and are correlated.<br>
In finance, this property is often used to develop mean-reverting algorithmic strategies.<br>
- The two stocks should have similar risk exposure or in similar industries so that their prices move together.<br>
We will long the undervalued stock and short the overvalued stock. When the two stock prices revert to the mean, then we will sell both. This is an example of Pairs Trading.

Functions created used in order of appearance:
| Function| Description  |
|--------------|------|
|   correlation_matrix | plots a correlation matrix for log returns datasets|
|   adfpair_test | Augmented Dickey-Fuller pair test which checks for cointegration between a pair of stocks |
|   EG_test | Engel Granger Test which checks for cointegration between a pair of stocks |
|   autocorr| tests for hypothesis of autocorrelation using durbin watson statistic |
|   addcolumn | adds column |
|   beta | Ordinary Linear Regression where we find the rsquared coefficient of the regression |
|   Smooth | Creates the price spread and smooths the spread using moving averages |
|   adfsingle_test | checks only one series for stationarity |
|   strategy | runs the trading strategy for longing and shorting the stocks based on the smoothed spread, returns the PnL graph and stats |

<br>

### Appendix

| Index | Documentation  |
|--------------|------|
|   Pandas     | https://pandas.pydata.org/pandas-docs/stable/reference/|
|   Numpy      | https://numpy.org/doc/1.24/reference/index.html|
|   Statsmodels| https://www.statsmodels.org/stable/api.html|
|   Plotly     | https://plotly.com/python/time-series/ |
|   Latex      | https://www.overleaf.com/learn/latex/Subscripts_and_superscripts |

Some ideas to further expand the strategy:
- Employ group_backfill to replace nan-values 
- Add a technical indicator as an additional condition for entry
- Additional rules for selecting stock pair. 
- Using the johansen cointegration test for multiple time-series (allows up to 12)
- Using cointegration on a basket of stocks (sectors or industries)

References:
<nav>
<a href=https://stats.stackexchange.com/questions/29121/intuitive-explanation-of-unit-root>Time Series Stationarity and unit roots</a> |
<a href=https://hudsonthames.org/an-introduction-to-cointegration>Cointegration examples</a> |
<a href=https://quant.stackexchange.com/questions/1027/how-are-correlation-and-cointegration-related>Correlation vs Cointegration </a> |
<a href=https://www.quantstart.com/articles/Basics-of-Statistical-Mean-Reversion-Testing-Part-II>Mean Reversion </a> |
<a href=https://blog.quantinsti.com/johansen-test-cointegration-building-stationary-portfolio>Johansen Test </a> |
<a href=https://machinelearningmastery.com/moving-average-smoothing-for-time-series-forecasting-python>Moving Averages </a> |<br>
<a href=https://medium.com/analytics-vidhya/the-ultimate-markdown-guide-for-jupyter-notebook-d5e5abf728fd>Jupyter Markdown guide </a> | 
<a href=https://betterdatascience.com/style-pandas-dataframes>Pandas Styling </a> | <br>
<a href=https://epchan.blogspot.com/2007/04/anonymous-reader-l-posted-some.html>epchan quant blog</a> |
<a href=https://letianzj.github.io/archives>Letian quant blog </a> |
</nav> 
