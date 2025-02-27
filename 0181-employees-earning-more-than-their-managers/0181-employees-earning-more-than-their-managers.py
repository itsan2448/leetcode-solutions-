import pandas as pd

def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(right = employee, how = 'inner', left_on="managerId", right_on="id")
    emp = df[df['salary_x']>df['salary_y']]['name_x']
    return pd.DataFrame({'employee':emp})