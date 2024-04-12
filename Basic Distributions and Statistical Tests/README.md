# Basic-Distributions-and-Statistical-Tests

Plotting common probability distributions and performing statistical tests using the Scipy and statsmodels.api module.

The distributions that will be plotted are as follows in order of appearance:
1. Continuous Uniform
2. Normal
3. Binomial
4. Exponential
5. Poisson
6. Lognormal
7. Power Law

<br>

The tests that were discussed are as follows in order of appearance:
| Test | Description |
|--------------|------|
|   Shapiro-Wilk test |normality checking|
|   Binomial test | tests probability of success|
|   Poisson exact test |tests difference between mean of two poisson distributions|
|   QQplot | normality checking|
|   Kolmogorov-Smirnov 1-sample test | compares a sample with a known distribution|
|   Kolmogorov-Smirnov 2-sample test | compares two samples of unknown distributions|
|   Goodness of fit test | tests whether data was drawn from a distribution in that family|
|   F-test | tests if the two normal distributions have the same mean |

<br>

### Appendix
| Index | Documentation  |
|--------------|------|
|   Pandas     | https://pandas.pydata.org/pandas-docs/stable/reference/|
|   Numpy      | https://numpy.org/doc/1.24/reference/index.html|
|   Scipy      | https://docs.scipy.org/doc/scipy/reference/stats.html|
|   Statsmodels| https://www.statsmodels.org/stable/api.html|
|   Plotly     | https://plotly.com/python/time-series/ |
|   Latex      | https://www.overleaf.com/learn/latex/Subscripts_and_superscripts |


Some ideas from using the tests:
-  distribution of stock prices and returns
-  distribution of option prices
-  show that they are conditional moments suitable for prices and returns

References:
<nav>
<a href=https://stats.stackexchange.com/questions/403237/kolmogorov-smirnov-test-vs-anderson-darling-test>Limitations of KS test</a> |
<a href=https://physics.stackexchange.com/questions/107682/kolmogorov-smirnov-test-vs-chi-squared-test>Comparison of KS and chi-squared test</a> |
<a href=https://discourse.datamethods.org/t/categorizing-continuous-variables/3402>Problems of categorising Continuous Variables</a> | 
<a href=https://userweb.ucs.louisiana.edu/~kxk4695/JSPI-04.pdf>Poisson Test</a> <br>
<a href=https://www.statology.org/central-limit-theorem>Central Limit Theorem</a> |
<a href=https://python-bloggers.com/2020/11/law-of-large-numbers-and-the-central-limit-theorem-with-python>Law of Large Numbers</a> |
</nav> 
