#include&lt;stdio.h&gt;

int main() {
int time, burst_time[10], at[10], sum_burst_time = 0, smallest, n, i;
int sumt = 0, sumw = 0;
printf(&quot;enter the no of processes : &quot;);
scanf(&quot;%d&quot;, &amp; n);
for (i = 0; i &lt; n; i++) {
printf(&quot;the arrival time for process P%d : &quot;, i + 1);
scanf(&quot;%d&quot;, &amp; at[i]);
printf(&quot;the burst time for process P%d : &quot;, i + 1);
scanf(&quot;%d&quot;, &amp; burst_time[i]);
sum_burst_time += burst_time[i];
}
burst_time[9] = 9999;
for (time = 0; time &lt; sum_burst_time;) {
smallest = 9;
for (i = 0; i &lt; n; i++) {

if (at[i] &lt;= time &amp;&amp; burst_time[i] &gt; 0 &amp;&amp; burst_time[i] &lt; burst_time[smallest])
smallest = i;
}
printf(&quot;P[%d]\t|\t%d\t|\t%d\n&quot;, smallest + 1, time + burst_time[smallest] - at[smallest], time -
at[smallest]);
sumt += time + burst_time[smallest] - at[smallest];
sumw += time - at[smallest];
time += burst_time[smallest];
burst_time[smallest] = 0;
}
printf(&quot;\n\n average waiting time = %f&quot;, sumw * 1.0 / n);
printf(&quot;\n\n average turnaround time = %f&quot;, sumt * 1.0 / n);
return 0;
}
