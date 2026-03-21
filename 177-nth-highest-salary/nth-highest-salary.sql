CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE offset_val INT;
  SET offset_val = N - 1;

  RETURN (
    select distinct salary
    from employee
    order by salary desc
    limit offset_val, 1
  );
END