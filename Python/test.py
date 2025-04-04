import pulp as pl
# LPVariable, LPProblem, LPMaximize, LPMinize, 

# define the problem using function LPProblem 
#z = pl.LPProblem("abc", pl.LPMaximize)
# define varible
#X = pl.LPVariable(X, pl.lowbound = 0)
# objective function
#abc += 2x+3y
# contraints 
# solve the problem
#pl.solve
# print result if z.status = 1 => optimal print(x.varvalue, y, objectivefunction), else print(not optimal solution)

problem = pl.LpProblem("lpp", pl.LpMaximize)
x = pl.LpVariable("x",0)
y = pl.LpVariable("y",0)
problem += 3*x + 2*y
problem += x + 2*y >= 8
problem += 2*x + y <= 6
problem.solve()
status = problem.solve();
print(pl.LpStatus[status])
#print(problem.status)
#print("Optimal values")
if problem.status == 1:
    print("Solution is optimal");
    print("X : ",x.varValue)
    print("Y : ",y.varValue)
    print("Objective Function : ",problem.objective.value())
else:
    print("Solution is not optimal");