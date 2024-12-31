CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    IF N < 1 THEN
            RETURN NULL;
        END IF;
    -- Adjust N for zero-based indexing in OFFSET
    SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
    select distinct salary
    from employee
    order by salary desc
    limit 1 offset n 
    -- Skips the first N salaries and retrieves the next one.
  );
END