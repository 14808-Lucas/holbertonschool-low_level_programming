Green efficiency analysis - measurements and conclusions.

Measurment Methodology:
I tested 3 programs running on my Dell computer laptop
-baseline_loop.c counts a loop 100,000,000 times for each run, which I ran 3 times with recordings.
-comparison_algorithms.c runs a program in a 50,000-element array using two methods (naive and single-pass). I ran it 3 times recording both results and times each run, and calculating the average time after.
-instrumentation_lab.c is a program that BUILDS, PROCESSES, and REDUCES a 50,000-number list. I  ran it 3 times, recording TOTAL, BUILD_DATA, PROCESS, and REDUCE each run.

Observed perforance differences:
- Baseline_loop.c the times were 0.228093 seconds,0.248821 seconds and 0.234033 seconds. all the times were different but close but still the same amount of iterations.
- Algorithm comparison  Naive times (2.830193 seconds,2.876140 seconds and 2.861016 seconds) with an average time of 2.855783 seconds.
  single-pass times (0.000106 seconds,0.000105 seconds & 0.000106 seconds) with an average time of 0.000105 seconds.
  Naive result = 625025000  single-pass result =25000.  Single pass is running 99.96% faster, essentially eliminating the run time. The Naive version produced a different result because it is double counting the same numbers hence its massive difference. while single pass is focused on the arrary size.
- Instrumentation lab :
First run
TOTAL seconds: 0.000732
BUILD_DATA seconds: 0.000283
PROCESS seconds: 0.000309
REDUCE seconds: 0.000135

Second run
TOTAL seconds: 0.000739
BUILD_DATA seconds: 0.000285
PROCESS seconds: 0.000315
REDUCE seconds: 0.000134

third run
TOTAL seconds: 0.000748
BUILD_DATA seconds: 0.000285
PROCESS seconds: 0.000323
REDUCE seconds: 0.000136
  
Relation between runtime and energy consumption
None of these programs measure energy consumption directly, and no power-measuring tool was used in this analysis. Execution time can only serve as an indirect proxy for energy use: a program that keeps the CPU active for longer (such as the naive approach at 2.85s compared to 0.000105s for the single-pass approach) is likely to consume more energy simply because the processor remains busy for a longer period. This conclusion is inferred from runtime data alone, not from an actual energy measurement.

Limitations of the experiment:
One limitation is I didn't have a proper tool to measure actual energy use, so any energy/efficiency claims here are inferred, not measured. Timing also wasn't perfectly consistent between runs even though the code never changed — probably because I ran this on a laptop, where background processes and the OS can act as confounding variables. I also only ran each program 3 times, which is a small sample size so more would be need for more clearer takeaways.

Practical engineering takeaway:
The clearest takeaway is that the choice of algorithm matters far more than small tweaks. The single-pass algorithm cut the runtime by over 99.99%. Since less runtime likely means less CPU activity, choosing a better algorithm is probably the easiest way to improve efficiency and energy consumption.
