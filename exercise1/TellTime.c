#include <stdio.h>
#include <time.h>
#include <math.h>

void tellTime(){
    time_t current_time;
    time(&current_time);

    long seconds_a_day = 60 * 60 * 24;

    long full_days_since_epoch = current_time/ seconds_a_day;

    long seconds_today = current_time - (seconds_a_day * full_days_since_epoch);

    long full_hours_today = (long)(seconds_today / (60*60));

    long full_min_this_hour = (long)(seconds_today % (60*60) / 60);

    long seconds_this_hour = (long)seconds_today - (full_hours_today * pow(60.0,2.0) + full_min_this_hour * 60);

    printf("The Greenwich standard time (in h/min/sec) is currently at: ");
    printf("%ld:%ld:%ld\n", full_hours_today, full_min_this_hour, seconds_this_hour);
}

int main(){
    tellTime();
    return 0;
}