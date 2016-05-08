# Test Reduction
A Study of Greedy and ILP Techniques in Test Reduction

###Overview
In this project we studied the techniques used in test reduction,specifically greedy and linear programming(ILP) algorithm. We applied these algorithms in 20 opensource Java projects and the experiment showed that they were really efficient in detecting redundant test cases. 
 
###Greedy Algorithm

A greedy algorithm is an algorithm that follows the problem solving heuristic of making the locally optimal choice at each stage with the hope of finding a global optimum. In many problems, a greedy strategy does not in general produce an optimal solution, but nonetheless a greedy heuristic may yield locally optimal solutions that approximate a global optimal solution in a reasonable time. In test reduction,it iteratively selects test cases that maximizes the code coverage until all the statements are covered.  
  
  
###ILP Algorithm

Integer programming is NP-hard. A special case, 0-1 integer linear programming, in which unknowns are binary, and only the restrictions must be satisfied, is one of Karp's 21 NP-complete problems.So in this project we used an opensource ILP solver -- [lp_solve](http://lpsolve.sourceforge.net/5.5/). lp_solve is a free (LGPL license) linear (integer) programming solver based on the revised simplex method and the Branch-and-bound method for the integers.Three way to use lp_solve

  	Via the API
  	Via input files
  	Via an IDE
  	
In this project we used input files since it's easier to program comparing to the API method and could be automated while IDE could not.  
##Example

In this example,we use both greedy and ILP method to perform test cases reduction for a randomly chosen opensource [project](https://github.com/VerbalExpressions/JavaVerbalExpressions). Before test reduction,we need to know the test coverage data,which is done using maven and clover.A small piece of python code is then used to extract data from the html file generated by clover and convert to matrix for simpler post process.A more detailed decription about the usage of maven and clover will be covered when this project is done but for the time being this example mainly focus on the test reduction part.  
Type in the following command and run  

  ./TestReduction.exe JavaVerbalExpressions-masterMatrx

And we should see the following result:  

Opening "JavaVerbalExpressions-masterMatrx"
	Reducing test cases..

	Test cases number = 72
	Code Statement number = 143
	Covered Statement number = 143
	Coverage = 100%
	size=143
	Test Coverage Vector:
	1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	Reduction result:
	Cases reduced = 49
	1 1 1 1 0 1 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 1 0 1 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 1 1 0 1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

	Opening "JavaVerbalExpressions-masterMatrx-greedy"
	Result was saved to "JavaVerbalExpressions-masterMatrx-greedy"
	Opening "JavaVerbalExpressions-masterMatrx-ilp"
	ILP model was saved to "JavaVerbalExpressions-masterMatrx-ilp"
	
The above program use greedy to detect the duplicated test cases and we could see that 49 cases are reduced.Also it generate the test cases into a ILP model,which could be fed into the lp_solver to solve the problem:  

	min: t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10 + t11 + t12 + t13 + t14 + t15 + t16 + t17 + t18 + t19 + t20 + t21 + t22 + t23 + t24 + t25 + t26 + t27 + t28 + t29 + t30 + t31 + t32 + t33 + t34 + t35 + t36 + t37 + t38 + t39 + t40 + t41 + t42 + t43 + t44 + t45 + t46 + t47 + t48 + t49 + t50 + t51 + t52 + t53 + t54 + t55 + t56 + t57 + t58 + t59 + t60 + t61 + t62 + t63 + t64 + t65 + t66 + t67 + t68 + t69 + t70 + t71 + t72;

	1*t1 + 1*t2 + 1*t3 + 1*t4 + 1*t5 + 1*t6 + 1*t7 + 1*t8 + 1*t9 + 1*t10 + 1*t11 + 1*t12 + 1*t13 + 1*t14 + 1*t15 + 1*t16 + 1*t17 + 1*t18 + 1*t19 + 1*t20 + 1*t21 + 1*t22 + 1*t23 + 1*t24 + 1*t25 + 1*t26 + 1*t27 + 1*t28 + 1*t29 + 1*t30 + 1*t31 + 1*t32 + 1*t33 + 1*t34 + 1*t35 + 1*t36 + 1*t37 + 1*t38 + 1*t39 + 1*t40 + 1*t41 + 1*t42 + 1*t43 + 1*t44 + 1*t45 + 1*t46 + 1*t47 + 1*t48 + 1*t49 + 1*t50 + 1*t51 + 1*t52 + 1*t53 + 1*t54 + 1*t55 + 1*t56 + 1*t57 + 1*t58 + 1*t59 + 1*t60 + 1*t61 + 1*t62 + 1*t63 + 1*t64 + 0*t65 + 1*t66 + 1*t67 + 1*t68 + 1*t69 + 1*t70 + 1*t71 + 0*t72 >=1;

	...
	...
	
And then call the lp_solve on the console we could get a pretty similar result:  

  ../lp_solve/lp_solve.exe JavaVerbalExpressions-masterMatrx-ilp

