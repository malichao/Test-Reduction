# A Study of Greedy and ILP Techniques in Test Reduction #

## Overview ##
In this project we studied the techniques used in test reduction,specifically greedy and linear programming(ILP) algorithm. We applied these algorithms in 20 opensource Java projects and the experiment showed that they were really efficient in detecting redundant test cases. 

### Greedy Algorithm ###

A greedy algorithm is an algorithm that follows the problem solving heuristic of making the locally optimal choice at each stage with the hope of finding a global optimum. In many problems, a greedy strategy does not in general produce an optimal solution, but nonetheless a greedy heuristic may yield locally optimal solutions that approximate a global optimal solution in a reasonable time. In test reduction,it iteratively selects test cases that maximizes the code coverage until all the statements are covered.  
  
  
### ILP Algorithm ###

Integer programming is NP-hard. A special case, 0-1 integer linear programming, in which unknowns are binary, and only the restrictions must be satisfied, is one of Karp's 21 NP-complete problems.So in this project we used an opensource ILP solver -- [lp_solve](http://lpsolve.sourceforge.net/5.5/). lp_solve is a free (LGPL license) linear (integer) programming solver based on the revised simplex method and the Branch-and-bound method for the integers.Three way to use lp_solve

  	Via the API
  	Via input files
  	Via an IDE
  	
In this project we used input files since it's easier to program comparing to the API method and could be automated while IDE could not.  
## Quick Start ##

### Dependency ###

Before you use our tools please make sure you installed the following tools/frameworks properly. Since lp_solve only works on Windows platform so our tools are designed for windows as well.But they should work on other platforms with minor modification as most of the codes are really portable.
  * Apache Maven 3.3.9 
  * Clover-for-Maven
  * Python2.7 (for running the tool that extracts test information)
  * Gcc and Eclipse CDT,or Visual Studio (only needed if you want to re-compile our code)
  * Java(TM) SE Runtime Environment (build 1.8.0_77-b03)
  * Eclipse (for verifying the result)

After installing all the dependencies,you could start using our tools to perform test reduction.All the tools and test projects are provided in the 'Example' folder.Here's a short description of each folders/files:

  	test projects.rar --------- :Contains all the test projects we used.
	coverage.py --------------- :Tool for extracting test coverage information
	projects_test_coverage ---- :Extracted test coverage information
  	TestReduction.exe --------- :Greedy algorithm,ILP models generation,and calling lp_solve to solve the models
	lp_solve ------------------ :Contains all the files needed to solve ILP model
  	result.rar ---------------- :The reduced test cases we've got using our tools
  	ASM ----------------------- :Contains Java codes to remove test cases
  
### Step 1 Build and Run the Test Cases ###

All the test projects we used could be found in Example/test projects.rar ,after unzipping the file we could use the following command to build these projects and generate test coverage information. Take 'aalto-xml' project as example:

	cd aalto-xml-master
	mvn clean clover:setup test 
	mvn clover:aggregate clover:clover

### Step 2 Extract Test Coverage data ###

Extracting test coverage data could be done by simply running the program 'Coverage.py'. Here' the format of the command:

	python Coverage.py PATH
	
For example,if the projects is under the folder '/user/CourseProject/ProjectA',then the above command becomes:

	python Coverage.py /user/CourseProject/

### Step 3 Perform Test Reduction ###
Test reduction is done by using only one line of command.The command format is like:

	TestReduction.exe [inputFolderName] [outputFolderName]
	
For example,'projects_test_coverage' folder contains all the extracted test coverage information and we want to store the reduced test cases in 'result' folder,then we can use the following command:

	TestReduction.exe projects_test_coverage\ result\

After type the above command,we could see the programming processing all the test cases.Take "JavaVerbalExpressions-masterMatrx" for example,we could see the following result on the console.

	============================================
	Processing JavaVerbalExpressions-masterMatrx
	Opening "test_cases\JavaVerbalExpressions-masterMatrx"
	Reducing test cases..

	Test cases number = 72
	Code Statement number = 143
	Coverage = 100%
	size=143
	Test Coverage Vector:
	1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
	1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

	Reduction result:
	Cases reduced = 49
	1 1 1 1 0 1 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 1 0 1 1 0 0 0 0 0 1 0 0 0 0 0 1 
	0 0 0 1 1 1 0 1 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 1
	Greedy result was saved to "result\JavaVerbalExpressions-masterMatrx-greedy"
	Opening "result\ilp\JavaVerbalExpressions-masterMatrx-ilp"
	ILP model was saved to "result\ilp\JavaVerbalExpressions-masterMatrx-ilp"

	============================================
	Solving ILP model JavaVerbalExpressions-masterMatrx
	Start solving ILP models
	lp_solve\lp_solve.exe result\ilp\JavaVerbalExpressions-masterMatrx-ilp > 
	result\ilp\ilp_result\JavaVerbalExpressions-masterMa
	trx-ilp_result
	
The above program use greedy to detect the duplicated test cases and we could see that 49 cases are reduced.Also it generate the test cases into a ILP model,which could be fed into the lp_solver to solve the problem:  

	min: t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10 + t11 + t12 + t13 + 
	t14 + t15 + t16 + t17 + t18 + t19 + t20 + t21 + t22 + t23 + t24 + t25 + 
	t26 + t27 + t28 + t29 + t30 + t31 + t32 + t33 + t34 + t35 + t36 + t37 + 
	t38 + t39 + t40 + t41 + t42 + t43 + t44 + t45 + t46 + t47 + t48 + t49 + 
	t50 + t51 + t52 + t53 + t54 + t55 + t56 + t57 + t58 + t59 + t60 + t61 + 
	t62 + t63 + t64 + t65 + t66 + t67 + t68 + t69 + t70 + t71 + t72;

	1*t1 + 1*t2 + 1*t3 + 1*t4 + 1*t5 + 1*t6 + 1*t7 + 1*t8 + 1*t9 + 1*t10 + 
	1*t11 + 1*t12 + 1*t13 + 1*t14 + 1*t15 + 1*t16 + 1*t17 + 1*t18 + 1*t19 + 
	1*t20 + 1*t21 + 1*t22 + 1*t23 + 1*t24 + 1*t25 + 1*t26 + 1*t27 + 1*t28 + 
	1*t29 + 1*t30 + 1*t31 + 1*t32 + 1*t33 + 1*t34 + 1*t35 + 1*t36 + 1*t37 + 
	1*t38 + 1*t39 + 1*t40 + 1*t41 + 1*t42 + 1*t43 + 1*t44 + 1*t45 + 1*t46 + 
	1*t47 + 1*t48 + 1*t49 + 1*t50 + 1*t51 + 1*t52 + 1*t53 + 1*t54 + 1*t55 + 
	1*t56 + 1*t57 + 1*t58 + 1*t59 + 1*t60 + 1*t61 + 1*t62 + 1*t63 + 1*t64 + 
	0*t65 + 1*t66 + 1*t67 + 1*t68 + 1*t69 + 1*t70 + 1*t71 + 0*t72 >=1;

	...
	...
	
Lastly we can see all the reduced test cases in the 'result' folder.

### Step 4 Apply Reduced Test Cases Back to the Projects ###

After generating the reduced test cases,we need to apply the result back to the original projects.This process could be done by calling the following command:

	java -cp PATHTO\ASM\bin\;PATHTO\ASM\lib\asm-all-5.0.3.jar Myown.RemoveMethod OriginalClassfile NewClassfileafterreduction NameOfTestcase

### Step 5 Compare Result with Mutation Test ###

In this step, we run PITest on original projects, projects after reduction by ILP, projects after reduction by Greedy. 
The configuration of PIT is like following:

	<plugin>
	    <groupId>org.pitest</groupId>
	    <artifactId>pitest-maven</artifactId>
	    <version>1.1.7-SNAPSHOT</version>
	    <configuration>
	        <targetClasses>
	            <param>com.mashape.*</param>  
	        </targetClasses>
	<mutators>
	                <mutator>ALL</mutator>
	      </mutators>
	         <outputFormats>
	                        <param>XML</param>
	                        <param>html</param>
	         </outputFormats>
	    </configuration>
	</plugin>

Then we calculating the ratio of “Killed” with all mutants to evaluate ILP and Greedy according to the PITest report) .For example

	<mutation detected='false' status='SURVIVED'><sourceFile>
	ChannelManager.java</sourceFile><mutatedClass>org.asteriskjava.live.internal.ChannelManager
	</mutatedClass><mutatedMethod>&#60;init&#62;</mutatedMethod><methodDescription>
	(Lorg/asteriskjava/live/internal/AsteriskServerImpl;)V
	</methodDescription><lineNumber>87</lineNumber><mutator>
	org.pitest.mutationtest.engine.gregor.mutators.ConstructorCallMutator
	</mutator><index>17</index><killingTest/></mutation>

	<mutation detected='true' status='KILLED'><sourceFile>ChannelManager.java
	</sourceFile><mutatedClass>org.asteriskjava.live.internal.ChannelManager
	</mutatedClass><mutatedMethod>&#60;init&#62;</mutatedMethod><methodDescription>
	(Lorg/asteriskjava/live/internal/AsteriskServerImpl;)V</methodDescription><lineNumber>73</lineNumber>
	<mutator>org.pitest.mutationtest.engine.gregor.mutators.NonVoidMethodCallMutator</mutator>
	<index>9</index><killingTest>org.asteriskjava.live.internal.AsteriskChannelImplTest.testStateChange
	(org.asteriskjava.live.internal.AsteriskChannelImplTest),
	org.asteriskjava.live.internal.AsteriskAgentImplTest.testUpdateStatus
	(org.asteriskjava.live.internal.AsteriskAgentImplTest)</killingTest></mutation>
	
In the example aboce there are two mutants,one of which is killed and the other is not killed(Survived).
