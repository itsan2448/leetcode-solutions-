import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    un = employee['salary'].drop_duplicates()
    s=un.sort_values(ascending=False)
    if N>len(un) or N<=0:
        return pd.DataFrame({f'getNthHighestSalary({N})':[None]})
    nth = s.iloc[N-1]
    return pd.DataFrame({f'getNthHighestSalary({N})':[nth]})
