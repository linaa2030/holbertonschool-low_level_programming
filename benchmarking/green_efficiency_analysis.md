# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with the same command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. All measurements were taken on the same laptop, one after another, without changing the code logic.

Time was measured with `clock()` from `<time.h>`. The idea is simple: read the clock before the work starts, read it again after the work ends, then divide the difference by `CLOCKS_PER_SEC` to get seconds. Each program was run three times, and the average was calculated for every measurement.

In the instrumentation program, each phase (BUILD_DATA, PROCESS, REDUCE) has its own start and end clock reading, placed directly around the function call. The TOTAL measurement starts before the first phase and ends after the last one, so TOTAL is always greater than or equal to each phase.

## Observed Performance Differences

**Baseline loop (100,000,000 iterations):** 0.153920, 0.154438 and 0.177121 seconds. The average is about 0.161826 seconds. The program did exactly the same work each time, but the third run was about 15% slower than the fastest run.

**Algorithm comparison (50,000 elements):** the biggest difference in the whole experiment. The naive algorithm took 3.540055, 3.536361 and 3.523766 seconds (average 3.533394 seconds). The single-pass algorithm took 0.000142, 0.000141 and 0.000141 seconds (average about 0.000141 seconds). This means the naive implementation is about 25,000 times slower. The reason is its nested loop: for every element, it goes back to the start of the array, so it performs about 1.25 billion checks instead of 50,000.

The two algorithms also returned different results: 625025000 for the naive version and 25000 for the single-pass version. The naive version counts the same elements many times, so it is both slower and not equivalent.

**Instrumentation lab:** the averages were TOTAL 0.000528, BUILD_DATA 0.000274, PROCESS 0.000147 and REDUCE 0.000103 seconds. BUILD_DATA used about half of the total time, so it is the first phase to look at if the program needs to be faster. The sum of the three phases (about 0.000524) is slightly lower than TOTAL, because reading the clock also takes a small amount of time.

## Relation Between Runtime and Energy Consumption

This experiment did not measure energy directly. Runtime was used as a proxy: when a program runs longer, the CPU stays active longer, and this usually means more energy is used. Based on this, the naive algorithm, which kept the CPU busy for about 3.5 seconds instead of a fraction of a millisecond, would most likely consume much more energy for the same task. If this code ran many times on many machines, the difference would become significant.

## Limitations of the Experiment

- Runtime is only an indirect indicator. No power or energy values in watts were measured.
- Results change between runs. The baseline third run (0.177121 seconds) was clearly slower than the first two, probably because other applications on the laptop were using the CPU at the same time.
- Only three runs were recorded for each program, which is a small sample.
- The instrumentation phases are very short (less than one millisecond), so small background activity can change them by a large percentage.
- All results come from one machine and may be different on another computer.

## Practical Engineering Takeaway

Nested loops can become very expensive when the data grows, so it is worth checking whether the same problem can be solved in a single pass. Performance should never be judged from one run: repeat the measurement, use averages and look at the variation. Before comparing the speed of two implementations, confirm that they produce the same correct result. Finally, measuring each phase separately shows where time is really spent, so improvement effort goes to the right place.
